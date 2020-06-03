/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <cstddef>
#include <cstdint>
#include <deri/dev/char.h>
#include <deri/dev/sifive_uart.h>

struct SiFiveUartRegs {
  volatile uint32_t txdata;
  volatile uint32_t rxdata;
  volatile uint32_t txctrl;
  volatile uint32_t rxctrl;
  volatile uint32_t ie;
  volatile uint32_t ip;
  volatile uint32_t div;
};

namespace deri::dev {

SiFiveUart::SiFiveUart(SiFiveUartRegs *dev) : dev(dev) {}

void SiFiveUart::init() {
  // disable interrupts
  dev->ie = 0;
  // set divisor
  dev->div = 0;
}

long SiFiveUart::write(const char *buf, long len) {
  long count = 0;
  for (long k = 0; k < len; ++k) {
    dev->txdata = buf[k];
    while (dev->txdata) {
      // waiting for transmission buffer space to become available
      asm volatile("" ::: "memory");
    }
    ++count;
  }
  return count;
}

} // namespace deri::dev