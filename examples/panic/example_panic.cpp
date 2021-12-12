/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <stdio.h>

int main() {
  puts("Kernel panic tester");
  puts(
      "This example will crash on purpose in order to test the crash dump "
      "features");

  volatile auto invalid_ptr = reinterpret_cast<void (*)()>(0xdeadfeed);
  invalid_ptr();
  while (true) {
    asm volatile("ebreak" ::: "memory");
  }
  return 0;
}
