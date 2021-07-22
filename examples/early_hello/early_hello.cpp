/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/console.h"

#include <span>

using deri::console;

int main() {
  const char msg[] = "Hello world\n";
  std::span<const char> buffer_view{msg, sizeof msg};
  console.write(std::as_bytes(buffer_view));
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
  return 0;
}
