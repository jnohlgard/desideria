/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

extern "C" {
[[gnu::interrupt, gnu::aligned(0b1000000)]] void isr_unhandled();
void isr_unhandled() {
  asm volatile("ebreak");
  while (1) {
  }
}
}
