/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <deri/console.h>

using deri::console;

int main() {
  const char msg[] = "Hello world\n";
  console->write(msg, sizeof(msg));
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
  return 0;
}
