/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

// Machine mode interrupt enable flag
.equ MSTATUS_MIE, 8

/**
 * Trap for machine exceptions early in the boot process
 */
.globl early_trap
// mtvec lower 2 bits have special meaning, all handlers must be aligned to at least 4 bytes
.align 2
early_trap:
.cfi_startproc
  // Read exception cause registers
  csrr t0, mcause
  csrr t1, mepc
  csrr t2, mtval
  1: j 1b
.cfi_endproc

.globl _start
_start:
.cfi_startproc
  // Avoid GP relative addressing until we have gp set up correctly
  .option push
  .option norelax

  // Disable interrupts globally
  csrc mstatus, MSTATUS_MIE

  // Set up an exception vector for any machine exceptions in early boot
  la t0, early_trap
  csrw mtvec, t0

  // Set up the global pointer register, the linker assumes that the gp
  // register always contains the address of the __global_pointer$
  // symbol, so be careful if refactoring this.
  la gp, __global_pointer$
  // gp has been set up, drop norelax
  .option pop

  // Set the initial stack pointer, using the proper width depending on the ABI
  la sp, _stack_end

  // TODO Add multi core support
  // Check hart id, only allow one hart to proceed
  csrr t0, mhartid
  bne t0, zero, 1f

  // Jump to kernel start
  tail deri_init

  // Park all except HART#0 here.
  1: j 1b
.cfi_endproc
