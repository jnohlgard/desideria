/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#ifndef DERI_ALLOCATOR_H_
#define DERI_ALLOCATOR_H_

#include <cstddef>
#include <cstdint>
#include <new>

namespace deri {
class Allocator {
public:
  /**
   * Maximum contiguous allocation request allowed
   */
  static const unsigned int MAX_ORDER = 4;
  using bitmap_type = uint32_t; // (2 << MAX_ORDER) bits
  /**
   * Type used internally for offset from base pointer
   */
  using offset_type = uintptr_t;
  /**
   * Initialize an allocator for the designated memory area.
   *
   * @param area_base Beginning of designated area
   * @param area_size Size of the designated area
   * @param block_size Block size of the allocations
   */
  Allocator(void *area_base, size_t area_size, size_t block_size);

  /**
   * Allocate @p size bytes from the designated memory area.
   *
   * The requested @p size will be rounded up to nearest @c block_size bytes
   *
   * @param size
   * @return pointer to allocated memory on success
   * @return nullptr on failure
   */
  void *allocate(size_t size);

private:
  void init_free_blocks_list(uintptr_t free_begin, uintptr_t free_end);

  struct FreeBlock;
  uint8_t *aligned_base;
  /// Bitmap of free blocks
  bitmap_type *free_map;
  /// Bitmap of split blocks
  bitmap_type *split_map;
  /// Lists of unallocated blocks, one list per level
  FreeBlock *free_blocks[MAX_ORDER + 1];
  size_t block_size;
  size_t block_size_log2;
  /// Number of bitmap array elements
  size_t map_count;
  /// Log2 of bytes per highest level block (corresponding to one bitmap array element)
  size_t map_stride_log2;
};

/**
 * Self-allocate an Allocator object
 *
 * Reserve memory from the designated area so that the Allocator object can
 * reside within the memory region that it manages.
 *
 * The returned pointer will point to somewhere inside the @p area_base region.
 *
 * @param area_base Beginning of designated area
 * @param area_size Size of the designated area
 * @param block_size Block size of the allocations
 * @return Pointer to an initialized Allocator object
 */
Allocator *create_allocator(void *area_base, size_t area_size,
                            size_t block_size);
} // namespace deri

#endif // DERI_ALLOCATOR_H_
