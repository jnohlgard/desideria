/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once
#include "deri/bsp/config.hpp"
#include "deri/dev/gpio.hpp"
#include "deri/dev/uart.hpp"
#include "deri/dev/uart_sifive.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/soc/uart_dev.hpp"

namespace deri::bsp {
using ConsoleDriver = dev::uart::UartBlockingDriver<dev::uart::UartSiFive>;
inline ConsoleDriver &console() {
  static auto &instance = []() -> auto & {
    auto &instance = soc::uart0();
    instance.setBaud(115200);
    soc::gpio.initOutIof(config::console_tx_pin);
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::bsp
