/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/arch/asm.h"
#include "riscv/csr/encoding.h"

void early_trap();
extern long _stack_end[];

__attribute__((naked)) void _start() {
  /* Clear the return address register to be able to detect the end of
   * a backtrace. */
  asm volatile(".cfi_undefined ra");

  /* Disable interrupts globally */
  asm volatile("csrc mstatus, %0" ::"rI"(MSTATUS_MIE) :);

  /* Set up an exception vector for any machine exceptions in early boot */
  asm volatile("csrw mtvec, %0" ::"rA"(early_trap));

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
  asm volatile("tail deri_init");

  /* we should never end up here, but spin if we do */
  asm volatile("1:\nj 1b\n");
}
