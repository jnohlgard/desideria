/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

extern "C" {
[[gnu::interrupt]] void isr_unhandled();
void isr_unhandled() {
  while (1) {
  }
}
}
