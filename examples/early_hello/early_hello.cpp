/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <deri/dev/sifive_uart.h>
#include <deri/bsp/memory_map.h>

int main() {
  deri::dev::SifiveUart uart(UART0);
  uart.init();
  const char msg[] = "Hello world\n";
  uart.write(msg, sizeof(msg), 0);
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
  return 0;
}
