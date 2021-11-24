/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/irq.hpp"

#include <cstdint>
#include <cstring>
#include <functional>

// Implementations for GCC atomic helpers
//
namespace deri {
template <typename Int>
Int atomic_load(const volatile void *ptr, int /*memorder*/) {
  arch::CriticalSection cs;
  auto &stored = *reinterpret_cast<const volatile Int *>(ptr);
  return stored;
}
template <typename Int>
void atomic_store(volatile void *ptr, Int val, int /*memorder*/) {
  arch::CriticalSection cs;
  auto &stored = *reinterpret_cast<volatile Int *>(ptr);
  stored = val;
}
template <typename Int, class BinaryOp>
Int atomic_fetch_op(volatile void *ptr,
                    Int val,
                    int /*memorder*/,
                    BinaryOp op) {
  arch::CriticalSection cs;
  auto &stored = *reinterpret_cast<volatile Int *>(ptr);
  auto old = stored;
  stored = op(old, val);
  return old;
}
template <typename Int>
bool atomic_compare_exchange(volatile void *ptr,
                             void *expected_ptr,
                             Int desired,
                             bool /*weak*/,
                             int /*success_memorder*/,
                             int /*failure_memorder*/) {
  arch::CriticalSection cs;

  auto &stored = *reinterpret_cast<volatile Int *>(ptr);
  auto &expected = *reinterpret_cast<Int *>(expected_ptr);
  auto old = stored;
  if (old == expected) {
    stored = desired;
    return true;
  } else {
    expected = old;
    return false;
  }
}
}  // namespace deri
extern "C" {

uint64_t __atomic_load_8(volatile const void *ptr, int memorder) {
  return deri::atomic_load<uint64_t>(ptr, memorder);
}
void __atomic_store_8(volatile void *ptr, uint64_t val, int memorder) {
  deri::atomic_store(ptr, val, memorder);
}
uint64_t __atomic_exchange_8(volatile void *ptr, uint64_t val, int memorder) {
  return deri::atomic_fetch_op(
      ptr, val, memorder, [](auto lhs, auto rhs) { return rhs; });
}
bool __atomic_compare_exchange_8(volatile void *ptr,
                                 void *expected,
                                 uint64_t desired,
                                 bool weak,
                                 int success_memorder,
                                 int failure_memorder) {
  return deri::atomic_compare_exchange(
      ptr, expected, desired, weak, success_memorder, failure_memorder);
}
uint64_t __atomic_fetch_add_8(volatile void *ptr, uint64_t val, int memorder) {
  return deri::atomic_fetch_op(ptr, val, memorder, std::plus());
}
uint64_t __atomic_fetch_sub_8(volatile void *ptr, uint64_t val, int memorder) {
  return deri::atomic_fetch_op(ptr, val, memorder, std::minus());
}
uint64_t __atomic_fetch_and_8(volatile void *ptr, uint64_t val, int memorder) {
  return deri::atomic_fetch_op(ptr, val, memorder, std::bit_and());
}
uint64_t __atomic_fetch_xor_8(volatile void *ptr, uint64_t val, int memorder) {
  return deri::atomic_fetch_op(ptr, val, memorder, std::bit_xor());
}
uint64_t __atomic_fetch_or_8(volatile void *ptr, uint64_t val, int memorder) {
  return deri::atomic_fetch_op(ptr, val, memorder, std::bit_or());
}
uint64_t __atomic_fetch_nand_8(volatile void *ptr, uint64_t val, int memorder) {
  return deri::atomic_fetch_op(
      ptr, val, memorder, [](auto lhs, auto rhs) { return ~(lhs & rhs); });
}

// Clang generic versions
// Clang objects if you redefine a builtin.  This little hack allows us to
// define a function with the same name as an intrinsic.
// source:
// https://github.com/llvm-mirror/compiler-rt/blob/69445f095c22aac2388f939bedebf224a6efcdaf/lib/builtins/atomic.c
#pragma redefine_extname __atomic_load_c __atomic_load
#pragma redefine_extname __atomic_store_c __atomic_store
#pragma redefine_extname __atomic_exchange_c __atomic_exchange
#pragma redefine_extname __atomic_compare_exchange_c __atomic_compare_exchange

void __atomic_load_c(size_t size,
                     const void *src,
                     void *dest,
                     int /*memorder*/) {
  deri::arch::CriticalSection cs;
  memcpy(dest, src, size);
}

void __atomic_store_c(size_t size,
                      void *dest,
                      const void *src,
                      int /*memorder*/) {
  deri::arch::CriticalSection cs;
  memcpy(dest, src, size);
}
void __atomic_exchange_c(
    size_t size, void *ptr, void *val, void *ret, int /*memorder*/) {
  deri::arch::CriticalSection cs;
  memcpy(ret, ptr, size);
  memcpy(ptr, val, size);
}

bool __atomic_compare_exchange_c(size_t size, void *ptr, void *expected,
                                 void *desired, bool /*weak*/, int /*success_memorder*/,
                                 int /*failure_memorder*/) {
  deri::arch::CriticalSection cs;
  if (memcmp(ptr, expected, size) == 0) {
    memcpy(ptr, desired, size);
    return true;
  } else {
    memcpy(expected, ptr, size);
    return false;
  }
}
}
