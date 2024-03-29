/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once
#include "deri/bsp/config.hpp"
#include "deri/dev/gpio.hpp"
#include "deri/dev/uart.hpp"
#include "deri/dev/uart_gd32.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/soc/uart_dev.hpp"

namespace deri::bsp {
using ConsoleDriver = dev::uart::UartIrqDriver<dev::uart::UsartGd32>;
inline ConsoleDriver &console() {
  static auto &instance = []() -> auto & {
    auto &instance = soc::uart<0>();
    instance.setBaud(115200);
    soc::gpio.initOutAfio(config::console_tx_pin);
    if (config::console_rx_pin) {
      soc::gpio.initInput(*config::console_rx_pin);
    }
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::bsp
