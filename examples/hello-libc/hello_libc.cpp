/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/console.h"

#include <span>

#include <stdio.h>

using deri::console;

int main() {
  static constexpr char msg[] = "Hello world\n";
  std::span<const char> buffer_view{msg, sizeof msg};
  console.write(std::as_bytes(buffer_view));
  puts("Hello world from puts\n");
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
  return 0;
}
