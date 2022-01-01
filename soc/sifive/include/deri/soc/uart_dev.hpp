/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/uart.hpp"
#include "deri/dev/uart_sifive.hpp"

namespace deri::soc {
// USART low level operations
using UartPeriph = dev::uart::UartSiFive;
}  // namespace deri::soc

namespace deri::mmio {
// Defined by fe310_mmio.ld
extern soc::UartPeriph UART0;
extern soc::UartPeriph UART1;
}  // namespace deri::mmio

namespace deri::soc {
// avoiding C++ static initialization order fiasco by wrapping each device in a
// function
inline dev::uart::UartBlockingDriver<dev::uart::UartSiFive> &uart0() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UartBlockingDriver{mmio::UART0};
    instance.init();
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::soc
