/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <deri/dev/char.h>
#include <deri/dev/sifive_uart.h>

namespace deri::dev {

// TODO refactor register definitions
#define _IO volatile
#define _I volatile
#define _O volatile

struct SifiveUartRegs {
  _IO uint32_t txdata;
  _IO uint32_t rxdata;
  _IO uint32_t txctrl;
  _IO uint32_t rxctrl;
  _IO uint32_t ie;
  _IO uint32_t ip;
  _IO uint32_t div;
};

SifiveUart::SifiveUart(SifiveUartRegs *dev) : dev(dev) {}
void SifiveUart::init() {
  // disable interrupts
  dev->ie = 0;
  // set divisor
  dev->div = 0;
}
long SifiveUart::write(const char *buf, long len, long off) {
  long count = 0;
  for (long k = off; k < len; ++k) {
    dev->txdata = buf[k];
    while (dev->txdata) {
      // waiting for transmission buffer to free
    }
    ++count;
  }
  return count;
}

} // namespace deri::dev
