/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/allocator.h"
#include "deri/assert.h"
#include "deri/testing/finish.h"
extern "C" {
#include <stdio.h>
}
#include <cstring>

#define TEST_ALLOCATOR_SIZE 11111

static uint8_t scratch[TEST_ALLOCATOR_SIZE];

using deri::Allocator;
using deri::testing::finish;

void wipe_scratch() {
  std::memset(scratch, 0xa5, sizeof(scratch));
}

bool overlap(const void *b1, size_t s1, const void *b2, size_t s2) {
  return !(static_cast<const void *>(static_cast<const uint8_t *>(b1) + s1) <= b2 ||
           static_cast<const void *>(static_cast<const uint8_t *>(b2) + s2) <= b1);
}
bool check_allocated_block_inside_test_bounds(const void *base, size_t size) {
  const uint8_t *ptr = static_cast<const uint8_t *>(base);
  return (&scratch[0] <= ptr && (ptr + size) <= &scratch[TEST_ALLOCATOR_SIZE]);
}

void testAllocator_allocate_single_block_should_give_valid_pointer() {
  wipe_scratch();
  static const unsigned int block_size = 128u;
  Allocator sut(scratch, TEST_ALLOCATOR_SIZE, block_size);
  void *ptr = sut.allocate(block_size);
  printf("allocated %5u bytes at %p\n", block_size, ptr);
  if (!check_allocated_block_inside_test_bounds(ptr, block_size)) {
    finish->fail(1);
  }
}

void testAllocator_self_allocate() {
  wipe_scratch();
  static const unsigned int block_size = 128u;
  Allocator *allocator =
      deri::create_allocator(scratch, TEST_ALLOCATOR_SIZE, block_size);
  printf("self-allocated Allocator at %p\n",
         static_cast<void *>(allocator));
  Allocator &sut = *allocator;
  void *ptr = sut.allocate(block_size);
  printf("allocated %5u bytes at %p\n", block_size, ptr);
  if (overlap(ptr, block_size, static_cast<void *>(allocator),
              sizeof(Allocator))) {
    finish->fail(2);
  }
  if (!check_allocated_block_inside_test_bounds(ptr, block_size)) {
    finish->fail(1);
  }
}

int main() {
  printf("Allocator test, using [%p, %p] as scratch area\n",
         static_cast<void *>(&scratch[0]),
         static_cast<void *>(&scratch[TEST_ALLOCATOR_SIZE - 1]));
  testAllocator_self_allocate();
  testAllocator_allocate_single_block_should_give_valid_pointer();
  finish->pass();

  return 0;
}
