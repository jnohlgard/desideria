/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include "deri/allocator.h"
#include "deri/assert.h"
#include <cstdint>
#include <cstring>
extern "C" {
#include <stdio.h>
}

namespace deri {

namespace {

static const Allocator::bitmap_type bitmap_order_lsb[Allocator::MAX_ORDER + 1] =
    {
        0x00000001u, 0x00010000u, 0x01000000u, 0x10000000u, 0x40000000u, 0u,
};

/**
 * Align an unaligned pointer up to nearest alignof(T) bytes
 *
 * @tparam T requested pointer type
 * @tparam U input pointer type
 * @param possibly_unaligned_ptr unaligned pointer
 * @return aligned pointer to @p T
 */
template <typename T, typename U> T *aligned_ptr(U *possibly_unaligned_ptr) {
  return reinterpret_cast<T *>(
      static_cast<uint8_t *>(nullptr) +
      ((static_cast<uint8_t *>(possibly_unaligned_ptr) + alignof(T) - 1 -
        static_cast<uint8_t *>(nullptr)) &
       ~(alignof(T) - 1)));
}

Allocator::offset_type map_index_from_block(Allocator::offset_type block) {
  Allocator::offset_type map_idx = block >> Allocator::MAX_ORDER;
  return map_idx;
}

/**
 * Compute the bit mask for the split/free bits of the given block
 * @param block (order 0) block offset from the aligned base
 * @param order
 * @return
 */
Allocator::bitmap_type block_mask_from_block(Allocator::offset_type block,
                                             unsigned int order) {
  // each buddy pair has one bit in the bitmap
  size_t block_sub_pair =
      ((block >> order) & ((1u << (Allocator::MAX_ORDER - order)) - 1u)) >> 1;
  return bitmap_order_lsb[order] << block_sub_pair;
}

} // namespace

struct Allocator::FreeBlock {
  FreeBlock *next;
  FreeBlock *prev;
};

Allocator::Allocator(void *area_base, size_t area_size, size_t block_size)
    : aligned_base{nullptr}, free_map{nullptr}, split_map{nullptr},
      free_blocks{0}, first_usable_block{0}, block_size{block_size},
      block_size_log2{0}, map_count{0}, map_stride_log2{0} {
  deri::assert((block_size > 0) && (block_size & (block_size - 1u)) == 0,
               "block_size must be a power of 2");
  size_t max_block_size = (block_size << MAX_ORDER);
  printf("block_size     = %5lu (0x%04lx)\n",
         static_cast<unsigned long>(block_size),
         static_cast<unsigned long>(block_size));
  printf("max_block_size = %5lu (0x%04lx)\n",
         static_cast<unsigned long>(max_block_size),
         static_cast<unsigned long>(max_block_size));
  deri::assert(max_block_size >= block_size, "max_block_size overflow");
  for (size_t k = block_size >> 1; k > 0; k >>= 1) {
    ++block_size_log2;
  }
  map_stride_log2 = block_size_log2 + MAX_ORDER;
  printf("block_size_log2 = %zu\n", block_size_log2);
  printf("map_stride_log2 = %zu\n", map_stride_log2);
  // aligned_base, aligned_size may point outside of the designated area, but we
  // will mark as used all blocks which are out of bounds.
  aligned_base =
      static_cast<uint8_t *>(nullptr) +
      ((static_cast<uint8_t *>(area_base) - static_cast<uint8_t *>(nullptr)) &
       ~(max_block_size - 1u));
  offset_type aligned_size = (static_cast<uint8_t *>(area_base) + area_size -
                              aligned_base + max_block_size - 1u) &
                             ~(max_block_size - 1u);
  printf("area_base: %p\n", static_cast<void *>(area_base));
  printf("area_size: %lu\n", static_cast<unsigned long>(area_size));
  printf("aligned_base: %p\n", static_cast<void *>(aligned_base));
  printf("aligned_size: %6lu (0x%04lx)\n",
         static_cast<unsigned long>(aligned_size),
         static_cast<unsigned long>(aligned_size));
  map_count = aligned_size >> map_stride_log2;

  // NB: ensure alignment before casting byte pointer into wider type pointer!
  free_map = reinterpret_cast<bitmap_type *>(
      static_cast<uint8_t *>(nullptr) +
      ((static_cast<uint8_t *>(area_base) + alignof(bitmap_type) - 1 -
        static_cast<uint8_t *>(nullptr)) &
       ~(alignof(bitmap_type) - 1)));
  split_map = free_map + map_count;
  memset(free_map, 0, map_count * sizeof(*free_map));
  memset(split_map, 0, map_count * sizeof(*split_map));
  printf("free_map:  %p (%zu elements)\n", static_cast<void *>(free_map),
         map_count);
  printf("split_map: %p (%zu elements)\n", static_cast<void *>(split_map),
         map_count);
  printf("map_stride = %u (2**%u)\n",
         static_cast<unsigned int>(1u << map_stride_log2),
         static_cast<unsigned int>(map_stride_log2));
  // Round up to find the first completely free block
  offset_type first_free_block =
      ((reinterpret_cast<uint8_t *>(split_map + map_count) - aligned_base) +
       block_size - 1) >>
      block_size_log2;
  // Truncate for the past-the-end block
  offset_type end_block =
      (static_cast<uint8_t *>(area_base) + area_size - aligned_base) >>
      block_size_log2;

  init_free_blocks_list(first_free_block, end_block);
}

void *Allocator::allocate(size_t requested_size) {
  size_t requested_blocks =
      (requested_size + block_size - 1) >> block_size_log2;
  printf("requested %lu bytes (%zu blocks)\n",
         static_cast<unsigned long>(requested_size), requested_blocks);
  unsigned int order = 0;
  while (requested_blocks > 1u) {
    ++order;
    requested_blocks = (requested_blocks >> 1u) + (requested_blocks & 1);
  }
  void *free_block = allocate_block(order);
  if (free_block) {
    printf("found free block %p\n", free_block);
  }
  return free_block;
}

Allocator::offset_type Allocator::block_from_ptr(void *ptr) const {
  ptrdiff_t diff = static_cast<uint8_t *>(ptr) - aligned_base;
  //  if (diff < 0) {
  //    // ptr does not point inside this Allocator's region
  //    return ~(offset_type{0});
  //  }
  offset_type block = static_cast<offset_type>(diff) >> block_size_log2;
  return block;
}

void Allocator::init_free_blocks_list(offset_type free_begin,
                                      offset_type free_end) {
  printf("map_count = %zu\n", map_count);
  for (unsigned int k = 0; k <= MAX_ORDER; ++k) {
    free_blocks[k] = nullptr;
  }

  // Scan the free space and add as large blocks as possible to the free blocks
  // lists
  offset_type block = free_begin;
  unsigned int order = 0;
  while (block < free_end) {
    for (offset_type k = block >> order; order < MAX_ORDER && (k & 1u) == 0;
         k >>= 1u) {
      ++order;
    }
    size_t map_idx = map_index_from_block(block);
    while (order > 0 && (block + (1u << order)) > free_end) {
      split_map[map_idx] |= block_mask_from_block(block, order);
      --order;
    }
    printf("next free block order: %u (0x%04zx)\n", order,
           (block_size << order));
    bitmap_type block_mask = block_mask_from_block(block, order);
    printf("map_idx = %u\n", static_cast<unsigned>(map_idx));
    printf("block_mask = 0x%08lx\n", static_cast<unsigned long>(block_mask));
    free_map[map_idx] ^= block_mask;
    split_map[map_idx] |= block_mask;
    push_free_block(ptr_from_block(block), order);
    block += 1u << order;
  }

  print_block_map();
}

void Allocator::print_block_map() const {
  fflush(stdout);
  printf("free blocks table:\n");
  for (unsigned int k = 0; k <= MAX_ORDER; ++k) {
    printf("  [%u] (%5lu)", k, static_cast<unsigned long>(block_size << k));
    FreeBlock *it = free_blocks[k];
    while (it) {
      printf(" <-> %p", static_cast<void *>(it));
      it = it->next;
    }
    puts("");
  }
  printf("free blocks map:\n");
  for (unsigned int k = 0; k < map_count; ++k) {
    printf("  [%u] 0x%08lx\n", k, static_cast<unsigned long>(free_map[k]));
  }
  printf("split blocks map:\n");
  for (unsigned int k = 0; k < map_count; ++k) {
    printf("  [%u] 0x%08lx\n", k, static_cast<unsigned long>(split_map[k]));
  }
  fflush(stdout);
}

void *Allocator::allocate_block(unsigned int order) {
  if (order > MAX_ORDER) {
    return nullptr;
  }
  void *free_block = pop_free_block(order);
  if (!free_block) {
    // Split a higher level block
    void *higher_block = allocate_block(order + 1);
    if (!higher_block) {
      // No blocks available
      return nullptr;
    }
    offset_type block = block_from_ptr(static_cast<void *>(higher_block));
    offset_type map_idx = map_index_from_block(block);
    bitmap_type block_mask = block_mask_from_block(block, order);
    // Leave the first half of the higher-order block as a free block, keep the
    // second half to use for this allocation.
    split_map[map_idx] |= block_mask;
    free_map[map_idx] |= block_mask;
    push_free_block(higher_block, order);
    block += 1 << order;
    return ptr_from_block(block);
  }
  offset_type block = block_from_ptr(static_cast<void *>(free_block));
  offset_type map_idx = map_index_from_block(block);
  bitmap_type block_mask = block_mask_from_block(block, order);
  free_map[map_idx] ^= block_mask;
  return free_block;
}

void Allocator::push_free_block(void *ptr, unsigned int order) {
  FreeBlock *free_block = ::new (ptr) FreeBlock();
  printf("push free block^%u @ %p\n", order, static_cast<void *>(free_block));
  FreeBlock *free_head = free_blocks[order];
  free_block->next = free_head;
  if (free_head) {
    free_head->prev = free_block;
  }
  free_blocks[order] = free_block;
}

void *Allocator::pop_free_block(unsigned int order) {
  FreeBlock *head = free_blocks[order];
  if (!head) {
    return nullptr;
  }
  FreeBlock *next = head->next;
  if (next) {
    next->prev = nullptr;
  }
  free_blocks[order] = next;
  return static_cast<void *>(head);
}

void *Allocator::ptr_from_block(Allocator::offset_type block) const {
  return static_cast<void *>(aligned_base + (block << block_size_log2));
}

void Allocator::visualize_split_block(Allocator::offset_type block) const {
  offset_type map_idx = map_index_from_block(block);
  offset_type base_block = (map_idx << MAX_ORDER);
  if (map_idx >= map_count) {
    // Out of bounds
    return;
  }
//  bitmap_type free_bits = free_map[map_idx];
  bitmap_type split_bits = split_map[map_idx];
  fflush(stdout);
  printf("      |%-18p%46p|\n", ptr_from_block(base_block),
         ptr_from_block(base_block + (1 << MAX_ORDER)));
  printf("order ");
  unsigned int width = 2 << MAX_ORDER;
  putchar('+');
  for (size_t k = 2; k < (2 << MAX_ORDER); ++k) {
    putchar('-');
  }
  putchar('+');
  putchar('\n');
  for (int k = MAX_ORDER; k >= 0; --k) {
    unsigned int order = k;
    printf("%5u |", order);
    // bitmap_type free_mask = block_mask_from_block(0, order - 1);
    for (offset_type offset = 0; offset < (1 << MAX_ORDER);
         offset += (1 << order)) {
      int filler = ' ';
      if (order > 0) {
        bitmap_type block_mask =
            block_mask_from_block(base_block + offset, order - 1);
        if (split_bits & block_mask) {
          // This block is split
          filler = 'v';
        }
      }
      if (filler == ' ') {
        bitmap_type block_mask =
            block_mask_from_block(base_block + offset, order);
        if (split_bits & block_mask) {
          // The higher order block above this one is split, visualize here
          FreeBlock *free_block = free_blocks[order];
          void *this_block = ptr_from_block(base_block + offset);
          filler = 'A';
          while (free_block) {
            if (static_cast<void *>(free_block) == this_block) {
              filler = 'F';
              break;
            }
            free_block = free_block->next;
          }
        }
      }
      for (unsigned int k = 1; k < width; ++k) {
        putchar(filler);
      }
      putchar('|');
    }
    putchar('\n');
    width >>= 1;
  }
  printf("      ");
  putchar('+');
  for (size_t k = 2; k < (2 << MAX_ORDER); ++k) {
    putchar('-');
  }
  putchar('+');
  putchar('\n');
}

void Allocator::visualize_split_block(void *ptr) const {
  if (ptr < aligned_base) {
    return;
  }
  visualize_split_block(block_from_ptr(ptr));
}

Allocator *create_allocator(void *area_base, size_t area_size,
                            size_t block_size) {
  uint8_t *area_end = static_cast<uint8_t *>(area_base) + area_size;
  // Align object placement pointer first, rounding up
  Allocator *object_ptr = aligned_ptr<Allocator>(area_base);
  // trim leading area to allow space for storing the Allocator instance
  area_base = static_cast<void *>(object_ptr + 1);
  deri::assert(area_base < area_end, "area too small");
  // recalculate size after trimming
  area_size = area_end - static_cast<uint8_t *>(area_base);
  return ::new (object_ptr) Allocator(area_base, area_size, block_size);
}
} // namespace deri
