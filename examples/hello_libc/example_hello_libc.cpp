/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/console.hpp"
#include "deri/span_literals.hpp"

#include <span>

#include <stdio.h>

using deri::Console;
using namespace deri::literals;

int main() {
  auto buffer_view = "Hello world!\n"_span;
  Console::write(std::as_bytes(buffer_view));
  puts("Hello world from puts\n");
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
  return 0;
}
