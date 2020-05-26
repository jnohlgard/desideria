/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
__attribute__((__naked__, __noreturn__)) void _start() {
  /* Clear the return address register to be able to detect the end of 
   * a backtrace. */
  __asm__ volatile(".cfi_undefined ra");

  /* Set up the global pointer register, the linker assumes that the gp
   * register always contains the address of the __global_pointer$
   * symbol, so be careful if refactoring this. */
  __asm__ volatile(".option push\n"
                   ".option norelax\n"
                   "la gp, __global_pointer$\n"
                   ".option pop\n");

  /* Set the default stack pointer */
  __asm__ volatile("la sp, _stack_end");

  /* Jump to kernel start */
  __asm__ volatile("j hang");

  /* we should never end up here, but spin if we do */
  __asm__ volatile("1:\nj 1b\n");
}
