/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <cstdint>
namespace deri::arch {

class Perf {
 public:
  [[nodiscard, gnu::always_inline]] static uint64_t cycles() {
    uint32_t lo;
    uint32_t hi;
    asm volatile("rdcycle %0" : "=r"(lo)::);
    asm volatile("rdcycleh %0" : "=r"(hi)::);
    return (static_cast<uint64_t>(hi) << 32 | lo);
  }
  [[nodiscard, gnu::always_inline]] static uint64_t instructionsRetired() {
    uint32_t lo;
    uint32_t hi;
    asm volatile("rdinstret %0" : "=r"(lo)::);
    asm volatile("rdinstreth %0" : "=r"(hi)::);
    return (static_cast<uint64_t>(hi) << 32 | lo);
  }
};
}  // namespace deri::arch
