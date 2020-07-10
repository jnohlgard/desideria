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
  static const unsigned int MAX_ORDER = 5;
  using bitmap_type = uint32_t; // (1 << MAX_ORDER)
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
  void reserve_oob_blocks();
  unsigned int calc_order(uint8_t *ptr);
  void init_free_blocks_list();

  struct FreeBlock;
  size_t block_size;
  uint8_t *aligned_base;
  size_t block_count;
  /// Bitmap of free blocks
  bitmap_type *free_map;
  /// Bitmap of split blocks
  bitmap_type *split_map;
  FreeBlock *free_blocks[MAX_ORDER + 1];
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
