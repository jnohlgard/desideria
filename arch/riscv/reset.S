.section .reset_trampoline,"ax",@progbits
.globl _reset_trampoline
_reset_trampoline:
j _start
