/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
#include "riscv/asm.h"
#include "riscv/csr/encoding.h"

__attribute__((naked, noreturn )) void _start() {
  /* Disable interrupts globally */
  asm volatile("csrc mstatus, %0" :: "I"(MSTATUS_MIE) : );

  /* Clear the return address register to be able to detect the end of 
   * a backtrace. */
  asm volatile(".cfi_undefined ra");

  /* Set up the global pointer register, the linker assumes that the gp
   * register always contains the address of the __global_pointer$
   * symbol, so be careful if refactoring this. */
  asm volatile(".option push;"
                   ".option norelax;"
                   "la gp, __global_pointer$;"
                   ".option pop;");

  /* Set the default stack pointer */
  asm volatile("la sp, _stack_end");

  /* Jump to kernel start */
  asm volatile("tail hang");

  /* we should never end up here, but spin if we do */
  asm volatile("1:\nj 1b\n");
}
