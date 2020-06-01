/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <deri/arch/asm.h>

extern "C" __attribute__((interrupt)) void early_trap();

/**
 * Trap for machine exceptions early in the boot process
 */
void early_trap() {
  asm volatile("csrr t0, mcause;"
               "csrr t1, mepc;"
               "csrr t2, mtval;" ::
                   : "memory");
  while (1) {
    asm volatile("" ::: "memory");
  }
}
