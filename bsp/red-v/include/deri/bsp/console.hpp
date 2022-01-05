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
inline auto &console() {
  static auto &instance = []() -> auto & {
    auto &instance = soc::uart<0>();
    soc::gpio.initOutIof(config::console_tx_pin);
    if (config::console_rx_pin.has_value()) {
      soc::gpio.initInIof(*config::console_rx_pin);
    }
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::bsp
