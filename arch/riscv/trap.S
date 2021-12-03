/*
 * Copyright (C) 2021 Joakim Nohlgård <joakim@nohlgard.se>
 */

.equ MSTATUS_MIE, 8

.equ SIZEOF_REG, (__SIZEOF_POINTER__)
.equ STACKED_REGS_SIZE, (32*SIZEOF_REG)

#define REG_OFFSET(num) SIZEOF_REG * (num)
#define SAVED_REG(num) x##num, REG_OFFSET(num)(sp)

.globl trap
.align 2
trap:
.globl deri_save_context
deri_save_context:
.cfi_startproc
  // Disable interrupts globally
  csrc mstatus, MSTATUS_MIE
  // Stack everything
  sw sp, REG_OFFSET( 2)(tp)
  mv sp, tp
  sw SAVED_REG( 1)
  sw SAVED_REG( 3)
  sw SAVED_REG( 4)
  sw SAVED_REG( 5)
  sw SAVED_REG( 6)
  sw SAVED_REG( 7)
  sw SAVED_REG( 8)
  sw SAVED_REG( 9)
  sw SAVED_REG(10)
  sw SAVED_REG(11)
  sw SAVED_REG(12)
  sw SAVED_REG(13)
  sw SAVED_REG(14)
  sw SAVED_REG(15)
  sw SAVED_REG(16)
  sw SAVED_REG(17)
  sw SAVED_REG(18)
  sw SAVED_REG(19)
  sw SAVED_REG(20)
  sw SAVED_REG(21)
  sw SAVED_REG(22)
  sw SAVED_REG(23)
  sw SAVED_REG(24)
  sw SAVED_REG(25)
  sw SAVED_REG(26)
  sw SAVED_REG(27)
  sw SAVED_REG(28)
  sw SAVED_REG(29)
  sw SAVED_REG(30)
  sw SAVED_REG(31)
  // Store the program counter
  csrr t0, mepc
  sw t0,   REG_OFFSET(0)(tp)

  // Update $tp to the new thread
  call _ZN4deri9Scheduler3runEv

.globl deri_restore_context
deri_restore_context:
  mv sp, a0
  // Reload program counter
  lw t0,   REG_OFFSET(0)(sp)
  csrw mepc, t0
  // Reload all registers
  lw SAVED_REG( 1)
  lw SAVED_REG( 3)
  lw SAVED_REG( 4)
  lw SAVED_REG( 5)
  lw SAVED_REG( 6)
  lw SAVED_REG( 7)
  lw SAVED_REG( 8)
  lw SAVED_REG( 9)
  lw SAVED_REG(10)
  lw SAVED_REG(11)
  lw SAVED_REG(12)
  lw SAVED_REG(13)
  lw SAVED_REG(14)
  lw SAVED_REG(15)
  lw SAVED_REG(16)
  lw SAVED_REG(17)
  lw SAVED_REG(18)
  lw SAVED_REG(19)
  lw SAVED_REG(20)
  lw SAVED_REG(21)
  lw SAVED_REG(22)
  lw SAVED_REG(23)
  lw SAVED_REG(24)
  lw SAVED_REG(25)
  lw SAVED_REG(26)
  lw SAVED_REG(27)
  lw SAVED_REG(28)
  lw SAVED_REG(29)
  lw SAVED_REG(30)
  lw SAVED_REG(31)
  mv tp, sp
  lw SAVED_REG( 2)
  csrr ra, mepc
  ret

.cfi_endproc
