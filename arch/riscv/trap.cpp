/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

extern "C" {
__attribute__((__interrupt__)) void isr_unhandled() {
  while (1) {
  }
}
}
