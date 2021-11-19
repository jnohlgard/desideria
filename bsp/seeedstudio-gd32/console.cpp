/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.h"

#include "deri/bsp/devices.h"
#include "deri/soc/clock_dev.h"
#include "deri/soc/gpio_dev.h"

namespace deri {
using namespace dev;
namespace bsp {
void console_init() {
  gpio::Gpio uart_pin{dev::gpio::Gpio::Port::A, 9};
  soc::gpio.initOutAfio(uart_pin);

  soc::rcu.enableModules(clock::RcuGd32::APB2EN_bits::USART0EN);
  uart0.init();
  uart0.setBaud(soc::rcu.apb2Freq(), 115200);
  uart0.transmitterOn();
}
}  // namespace bsp
bsp::Console console{bsp::uart0};
}  // namespace deri
