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
tail _jump_to__start_in_flash_region
.option pop
.cfi_endproc
