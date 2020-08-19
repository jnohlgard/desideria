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
  using bitmap_type = uint32_t; // (1 << MAX_ORDER) bits
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
  [[nodiscard]] void *allocate(size_t size);

private:
  /**
   * Class representing a free block ready to be allocated
   */
  struct FreeBlock;

  /**
   * Marks all blocks that are outside of the given range as allocated
   *
   * @param free_begin first block inside the valid region
   * @param free_end past-the-end block number
   */
  void init_free_blocks_list(offset_type free_begin, offset_type free_end);

  /**
   * Take one block of @p order from the free list, or split a higher order block if no free block is available
   *
   * If no higher order blocks are available @c nullptr is returned to indicate
   * failure.
   * The returned block will be marked as allocated in @c free_map.
   *
   * @param order the order of the block to allocate
   * @return pointer allocated block
   * @return nullptr on failure
   */
  void *allocate_block(unsigned int order);

  /**
   * Get the block offset given a regular pointer
   * @param ptr pointer to a block
   * @return offset to the block containing the pointed to memory location
   */
  offset_type block_from_ptr(void *ptr) const;

  /**
   * Convert a block index into a pointer value
   *
   * @param block the block index
   * @return pointer to the beginning of the block
   */
  void *ptr_from_block(offset_type block) const;

  // Free list handling
  // TODO use std::optional<offset_type> or something related instead of void *
  void *pop_free_block(unsigned int order);
  void push_free_block(void *ptr, unsigned int order);

  /**
   * Debug helper, print the free_map and split_map to stdout
   */
  void print_block_map() const;

  /**
   * Draw an ascii art diagram of the highest order block containing the given
   * block
   *
   * @param block which block to visualize
   */
  void visualize_split_block(offset_type block) const;

public:
  /**
   * Draw an ascii art diagram of the highest order block containing the given
   * pointer address
   *
   * @param ptr  which block to visualize
   */
  void visualize_split_block(void *ptr) const;

private:
  /// Base of allocatable area, aligned to fit block size boundaries
  uint8_t *aligned_base;
  /// Bitmap of free blocks
  bitmap_type *free_map;
  /// Bitmap of split blocks
  bitmap_type *split_map;
  /// Lists of unallocated blocks, one list per level
  FreeBlock *free_blocks[MAX_ORDER + 1];
  /// offset of the first block that is entirely inside the assigned area
  /// (distance from aligned_base to actual base)
  offset_type first_usable_block;
  /// size of a block, in bytes
  size_t block_size;
  /// block_size as a power of two (block_size = 1 << block_size_log2)
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
