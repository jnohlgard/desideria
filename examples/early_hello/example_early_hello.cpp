/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/console.hpp"

#include <span>

using deri::Console;

int main() {
  const char msg[] = "Hello world\n";
  std::span<const char> buffer_view{msg, sizeof msg};
  Console::write(std::as_bytes(buffer_view));
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
  return 0;
}
