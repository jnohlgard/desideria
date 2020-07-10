/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include "deri/allocator.h"
#include "deri/assert.h"
#include <cstdint>
extern "C" {
#include <stdio.h>
}

namespace deri {

namespace {

// Internal helper functions

inline uint8_t *align_down(uint8_t *ptr, size_t alignment) {
  return ptr - ((ptr - static_cast<uint8_t *>(nullptr)) & (alignment - 1u));
}

inline uint8_t *align_up(uint8_t *ptr, size_t alignment) {
  ptr += (alignment - 1u);
  return align_down(ptr, alignment);
}

} // namespace

struct Allocator::FreeBlock {
  FreeBlock *next;
};

Allocator::Allocator(void *area_base, size_t area_size, size_t block_size)
    : block_size{block_size}, aligned_base{nullptr},
      block_count{0}, free_map{nullptr}, split_map{nullptr}, free_blocks{0} {
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
  // aligned_base, aligned_end may point outside of the designated area, but we
  // will mark as used all blocks which are out of bounds.
  uint8_t *area_end = static_cast<uint8_t *>(area_base) + area_size;
  uint8_t *aligned_end = align_up(area_end, max_block_size);
  aligned_base = align_down(static_cast<uint8_t *>(area_base), max_block_size);
  printf("area_base: %p\n", static_cast<void *>(area_base));
  printf("area_end:  %p\n", static_cast<void *>(area_end));
  printf("aligned_base: %p\n", static_cast<void *>(aligned_base));
  printf("aligned_end:  %p\n", static_cast<void *>(aligned_end));
  block_count = (aligned_end - aligned_base) / block_size;
  size_t map_count = (aligned_end - aligned_base) / max_block_size;

  // NB: ensure alignment before casting byte pointer into wider type pointer!
  free_map = reinterpret_cast<bitmap_type *>(
      align_up(static_cast<uint8_t *>(area_base), alignof(bitmap_type)));
  split_map = free_map + map_count;
  printf("free_map:  %p (%u elements)\n", static_cast<void *>(free_map),
         map_count);
  printf("split_map: %p (%u elements)\n", static_cast<void *>(split_map),
         map_count);
  init_free_blocks_list(reinterpret_cast<uint8_t *>(split_map + map_count)
      , area_end);
}

void *Allocator::allocate(size_t) { return aligned_base; }

void Allocator::reserve_oob_blocks() {
  //  uint8_t *end_reserved = aligned_base;
}

unsigned int Allocator::calc_order(uint8_t *ptr) {
  unsigned int order = 1;
  while (order <= MAX_ORDER) {
    if (align_down(ptr, (block_size << order)) != ptr) {
      break;
    }
    ++order;
  }
  --order;
  return order;
}

void Allocator::init_free_blocks_list(uint8_t *free_begin, uint8_t *free_end) {
  size_t map_count = (block_count + (1 << MAX_ORDER) - 1) >> MAX_ORDER;
  printf("map_count = %u\n", map_count);
  for (unsigned int k = 0; k <= MAX_ORDER; ++k) {
    free_blocks[k] = nullptr;
  }
  uint8_t *block = align_up(free_begin, block_size);

  // Scan the free space and add as large blocks as possible to the free blocks
  // lists
  while (block < free_end) {
    FreeBlock *free_block = new (static_cast<void *>(block)) FreeBlock();
    printf("next free: %p\n", static_cast<void *>(free_block));
    unsigned int order = calc_order(reinterpret_cast<uint8_t *>(free_block));
    while (order > 0 && block + (block_size << order) >= free_end) {
      --order;
    }
    if (order == 0 && block + block_size >= free_end) {
      break;
    }
    printf("next free block order: %u\n", order);
    free_block->next = free_blocks[order];
    free_blocks[order] = free_block;
    block += block_size << order;
  }

  printf("free blocks table:\n");
  for (unsigned int k = 0; k <= MAX_ORDER; ++k) {
    printf("  [%u] (%5lu)", k, static_cast<unsigned long>(block_size << k));
    FreeBlock *it = free_blocks[k];
    while (it) {
      printf(" -> %p", static_cast<void *>(it));
      it = it->next;
    }
    puts("");
  }
}

Allocator *create_allocator(void *area_base, size_t area_size,
                            size_t block_size) {
  uint8_t *area_end = static_cast<uint8_t *>(area_base) + area_size;
  // Align object placement pointer first, rounding up
  Allocator *object_ptr = reinterpret_cast<Allocator *>(
      align_up(static_cast<uint8_t *>(area_base), alignof(Allocator)));
  // trim leading area to allow space for storing the Allocator instance
  area_base = static_cast<void *>(object_ptr + 1);
  deri::assert(area_base < area_end, "area too small");
  // recalculate size after trimming
  area_size = area_end - static_cast<uint8_t *>(area_base);
  return ::new (object_ptr) Allocator(area_base, area_size, block_size);
}
} // namespace deri
