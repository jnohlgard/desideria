/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/arch/asm.h"
#include "riscv/csr/encoding.h"

void early_trap(void);
extern long _stack_end[];

/**
 * Trap for machine exceptions early in the boot process
 */
__attribute__((naked, optimize("align-functions=16"))) void early_trap(void) {
#if 0
// check stack pointer for corruption first
  asm volatile("la t0, _stack_end;"
               "blt t0, sp, 1f;"
               "la t0, _memory_begin;"
               "blt sp, t0, 1f;"
               "j 2f;"
               "1:;"
  // Restore initial stack pointer if it has been corrupted
#if __LP64__
               "ld sp, _initial_sp;"
#else
               "lw sp, _initial_sp;"
#endif
               "2:;");
#endif
  // Read exception cause registers
  asm volatile("csrr t0, mcause;"
               "csrr t1, mepc;"
               "csrr t2, mtval;"
               "1: j 1b;");
}

__attribute__((naked)) void _start(void) {
  // Disable interrupts globally
  asm volatile("csrc mstatus, %0" ::"rI"(MSTATUS_MIE) :);

  // Set up an exception vector for any machine exceptions in early boot
  asm volatile("csrw mtvec, %0" ::"rA"(early_trap));

  // Set up the global pointer register, the linker assumes that the gp
  // register always contains the address of the __global_pointer$
  // symbol, so be careful if refactoring this.
  asm volatile(".option push;"
               ".option norelax;"
               "la gp, __global_pointer$;"
               ".option pop;");

  // Set the initial stack pointer, using the proper width depending on the ABI
#ifdef __LP64__
  asm volatile("ld sp, _initial_sp");
#else
  asm volatile("lw sp, _initial_sp");
#endif

  // TODO Add multi core support
  // Check hart id, only allow one hart to proceed
  asm volatile("csrr t0, mhartid;"
               "1: bne t0, zero, 1b;");

  // Jump to kernel start
  asm volatile("tail deri_init");

  // we should never end up here, but spin if we do
  asm volatile("1: j 1b");

  // initial stack pointer value
#ifdef __LP64__
  asm volatile("_initial_sp:\n.8byte %0" ::"i"(&_stack_end));
#else
  asm volatile("_initial_sp:\n.4byte %0" ::"i"(&_stack_end));
#endif
}
