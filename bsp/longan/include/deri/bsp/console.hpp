/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once
#include "deri/bsp/config.hpp"
#include "deri/dev/gpio.hpp"
#include "deri/dev/uart_gd32.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/soc/uart_dev.hpp"

namespace deri::bsp {
using Console = dev::uart::UsartGd32;
inline Console &console() {
  static auto &instance = []() -> auto & {
    auto &instance = soc::uart0();
    instance.init();
    instance.setBaud(115200);
    soc::gpio.initOutAfio(config::console_pin);
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::bsp
