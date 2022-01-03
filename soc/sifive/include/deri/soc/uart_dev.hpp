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

extern std::array<dev::uart::UartIrqDriver<soc::UartPeriph> *, 2> uart;
// avoiding C++ static initialization order fiasco by wrapping each device in a
// function
inline auto &uart0() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UartIrqDriver{mmio::UART0};
    instance.init();
    instance.setBaud(115200);
    soc::Irq::enable(mmio::IRQ::UART0);
    uart[0] = &instance;
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::soc
