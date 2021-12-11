/*
 * Copyright (C) 2021 Joakim Nohlgård <joakim@nohlgard.se>
 */

.equ MSTATUS_MIE, 8
.equ MCAUSE_ECALL_U, 8
.equ MCAUSE_ECALL_M, 11
.equ SIZEOF_REG, (__SIZEOF_POINTER__)

.globl deri_exception_handler
.align 6
deri_exception_handler:
.cfi_startproc
  // Disable interrupts globally
  //csrc mstatus, MSTATUS_MIE
  addi sp, sp, -(2 * SIZEOF_REG)
  sw t0, 0*SIZEOF_REG(sp)
  csrr t0, mcause
  // if the sign bit in mcause is set, then we are handling an interrupt
  bltz t0, interrupt
  // pick out the bottom 11 bits of mcause to check for the exception number
  andi t0, t0, 0x7ff
  sw t1, 1*SIZEOF_REG(sp)
  li t1, MCAUSE_ECALL_M
  // ecall from M-mode is used to trigger context switches from interrupts
  beq t0, t1, do_sched_update
  li t1, MCAUSE_ECALL_U
  // ecall from U-mode is used for syscalls from applications (not yet implemented)
  beq t0, t1, ecall_handler
  j other_exception
do_sched_update:
  // Advance PC past the ecall instruction which caused the trap
  csrr t0, mepc
  addi t0, t0, 4
  csrw mepc, t0
  // restore all register state
  lw t0, SIZEOF_REG*0(sp)
  lw t1, SIZEOF_REG*1(sp)
  addi sp, sp, SIZEOF_REG*2
  j deri_arch_sched_update
.globl ecall_handler
ecall_handler:
  // Advance PC past the ecall instruction which caused the trap
  csrr t0, mepc
  addi t0, t0, 4
  csrw mepc, t0
  // restore all register state
  lw t0, SIZEOF_REG*0(sp)
  lw t1, SIZEOF_REG*1(sp)
  addi sp, sp, SIZEOF_REG*2
  // Same register numbers that Linux uses for syscalls.
  // a7 contains the syscall number
  bnez a7, other_ecall
  // 0 is thread scheduler update, possible context switch
  tail deri_arch_sched_update
other_ecall:
  // ecall that is not one of the recognized numbers above
other_exception:
  // Exception that is not handled above
  lw t1, SIZEOF_REG*1(sp)
interrupt:
  // Interrupt that was not vectorized
  lw t0, SIZEOF_REG*0(sp)
  addi sp, sp, SIZEOF_REG*2
  tail deri_arch_unhandled_interrupt
.cfi_endproc

.equ STACKED_REGS_SIZE, (32*SIZEOF_REG)

#define REG_OFFSET(num) SIZEOF_REG * (num)
#define SAVED_REG(num) x##num, REG_OFFSET(num)(sp)

.globl deri_arch_sched_update
deri_arch_sched_update:
.cfi_startproc
  // a0 new context pointer, a1 old context pointer

  // load the old context pointer from mscratch, stash user a1
  csrrw a1, mscratch, a1
  // Get a pointer to the new context
  addi sp, sp, -(1*SIZEOF_REG)
  sw a0, (0*SIZEOF_REG)(sp)
  // This is dependent on the layout of ForwardListNode and OrderedForwardList
  lui a0, %hi(_ZN4deri9Scheduler9run_queueE) // &deri::Scheduler::run_queue.head
  lw  a0, %lo(_ZN4deri9Scheduler9run_queueE)(a0) // deri::Scheduler::run_queue.head
  addi a0, a0, 4 # &deri::Scheduler::run_queue.head->saved_context
  bne a0, a1, switch_context
no_context_change:
  // restore user a1 and a0
  csrrw a1, mscratch, a1
  lw a0, (0*SIZEOF_REG)(sp)
  addi sp, sp, (1*SIZEOF_REG)
  mret
switch_context:
  // context pointer stored in mscratch is 0 when initializing the scheduler, avoid saving the init context
  bnez a1, save_context
  // no need to restore anything because we are discarding the current state
  j load_context
save_context:
  // Save everything to *a1
  // temporarily store new context pointer in pc position
  sw a0, REG_OFFSET( 0)(a1)
  // restore user a0
  lw a0, (0*SIZEOF_REG)(sp)
  addi sp, sp, (1*SIZEOF_REG)
  // save user sp
  sw sp, REG_OFFSET( 2)(a1)
  // put old context pointer in sp
  mv sp, a1
  // restore user a1
  csrrw a1, mscratch, a1
  // store all general purpose registers
  sw SAVED_REG( 1)
  // x2 is sp, saved above
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
  // load new context pointer from temporary position in old context
  lw a0, REG_OFFSET(0)(sp)
  // Store the program counter in old context
  csrr t0, mepc
  sw t0, REG_OFFSET(0)(sp)
load_context:
  // save new context pointer in mscratch
  csrw mscratch, a0
  // put context pointer in sp for better instruction compression for the block below
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
  // finally load the stack pointer
  lw SAVED_REG( 2)
  mret
.cfi_endproc

.globl deri_arch_unhandled_interrupt
deri_arch_unhandled_interrupt:
.cfi_startproc
  ebreak
  j deri_arch_unhandled_interrupt
.cfi_endproc
