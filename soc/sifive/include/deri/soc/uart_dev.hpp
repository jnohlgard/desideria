/*
 * Copyright (c) 2021-2022 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/mmio_driver.hpp"
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

template <>
struct DefaultConfig<UartPeriph> {
  using Driver = dev::uart::UartIrqDriver<UartPeriph>;
};

template <>
struct HardwareMap<mmio::UART0>
    : public detail::HardwareMapDefinition<mmio::UART0,
                                           Clock::TileLink{},
                                           Irq::IRQ::UART0> {};
template <>
struct HardwareMap<mmio::UART1>
    : public detail::HardwareMapDefinition<mmio::UART1,
                                           Clock::TileLink{},
                                           Irq::IRQ::UART1> {};

template <>
struct UartDevice<0> {
  static inline auto &device{mmio::UART0};
};
template <>
struct UartDevice<1> {
  static inline auto &device{mmio::UART1};
};
}  // namespace deri::soc
