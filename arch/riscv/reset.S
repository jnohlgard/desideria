/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

.section .reset_trampoline,"ax",@progbits
.globl _reset_trampoline
_reset_trampoline:
.globl _jump_to__start_in_flash_region
_jump_to__start_in_flash_region:
.cfi_startproc
.cfi_undefined ra
.option push
.option norelax
lui a0, %hi(_start)
addi a0, a0, %lo(_start)
jr a0
.option pop
.cfi_endproc
