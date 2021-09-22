/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

.section .reset_trampoline,"ax",@progbits
.globl _reset_trampoline
_reset_trampoline:
.cfi_startproc
.cfi_undefined ra
.option push
.option norelax
lui a0, %hi(_start)
addi a0, a0, %lo(_start)
jr a0
.option pop
.cfi_endproc
