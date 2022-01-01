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
    uint32_t hi1;
    uint32_t hi2;
    asm volatile(
        "1:\n\t"
        "rdcycleh %1\n\t"
        "rdcycle %0\n\t"
        "rdcycleh %2\n\t"
        "bne %1, %2, 1b\n\t"
        : "=r"(lo), "=r"(hi1), "=r"(hi2)::);
    return (static_cast<uint64_t>(hi1) << 32 | lo);
  }
  [[nodiscard, gnu::always_inline]] static uint64_t instructionsRetired() {
    uint32_t lo;
    uint32_t hi1;
    uint32_t hi2;
    asm volatile(
        "1:\n\t"
        "rdinstreth %1\n\t"
        "rdinstret %0\n\t"
        "rdinstreth %2\n\t"
        "bne %1, %2, 1b\n\t"
        : "=r"(lo), "=r"(hi1), "=r"(hi2)::);
    return (static_cast<uint64_t>(hi1) << 32 | lo);
  }
};
}  // namespace deri::arch
