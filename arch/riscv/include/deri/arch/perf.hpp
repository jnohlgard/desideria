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
    asm volatile("csrr %0, mcycle" : "=r"(lo)::);
    asm volatile("csrr %0, mcycleh" : "=r"(hi)::);
    return (static_cast<uint64_t>(hi) << 32 | lo);
  }
  [[nodiscard, gnu::always_inline]] static uint64_t instructionsRetired() {
    uint32_t lo;
    uint32_t hi;
    asm volatile("csrr %0, minstret" : "=r"(lo)::);
    asm volatile("csrr %0, minstreth" : "=r"(hi)::);
    return (static_cast<uint64_t>(hi) << 32 | lo);
  }
};
}  // namespace deri::arch
