/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <deri/console.h>
#include <stdio.h>

using deri::console;

int main() {
  const char msg[] = "Hello world\n";
  console->write(msg, sizeof(msg));
  puts("Hello world from puts\n");
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
  return 0;
}
