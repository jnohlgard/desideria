/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/arch/thread.hpp"

namespace deri {
[[noreturn]] void panic();

arch::SavedContext panic_context;

[[gnu::naked]] void panic() {
  asm volatile(
      // Disable interrupts
      "csrc mstatus, 8\n\t"
      // stack a0
      "addi sp, sp, -4\n\t"
      "sw a0, 0(sp)\n\t"
      // get pointer to deri::panic_context for use with deri::arch::saveContext
      "la a0, _ZN4deri13panic_contextE\n\t"
      // save ra
      "sw ra, 4(a0)\n\t"
      // save all general purpose registers
      "call _ZN4deri4arch11saveContextERNS0_12SavedContextE\n\t"
      // save the stacked a0
      "lw t0, 0(sp)\n\t"
      "addi sp, sp, 4\n\t"
      "sw t0, 40(a0)\n\t"
      // print out the saved context
      "call _ZN4deri4arch11dumpContextERKNS0_12SavedContextE\n\t"
      // hang
      "1:\n\t"
      "j 1b");
}
}  // namespace deri
