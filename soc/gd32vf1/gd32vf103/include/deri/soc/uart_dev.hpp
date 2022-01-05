/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/mmio_driver.hpp"
#include "deri/dev/uart.hpp"
#include "deri/dev/uart_gd32.hpp"
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"
#include "deri/soc/soc.hpp"

namespace deri::soc {
// USART low level operations
using UartPeriph = dev::uart::UsartGd32;
}  // namespace deri::soc

namespace deri::mmio {
// Defined by gd32vf103_mmio.ld
extern soc::UartPeriph USART0;
extern soc::UartPeriph USART1;
extern soc::UartPeriph USART2;
extern soc::UartPeriph UART3;
extern soc::UartPeriph UART4;
}  // namespace deri::mmio

namespace deri::soc {

template <>
struct DefaultConfig<UartPeriph> {
  using Driver = dev::uart::UartIrqDriver<UartPeriph>;
};

template <>
struct HardwareMap<mmio::USART0>
    : public detail::HardwareMapDefinition<mmio::USART0,
                                           Clock::APB2::USART0EN,
                                           Irq::IRQ::USART0> {};
template <>
struct HardwareMap<mmio::USART1>
    : public detail::HardwareMapDefinition<mmio::USART1,
                                           Clock::APB1::USART1EN,
                                           Irq::IRQ::USART0> {};
template <>
struct HardwareMap<mmio::USART2>
    : public detail::HardwareMapDefinition<mmio::USART2,
                                           Clock::APB1::USART2EN,
                                           Irq::IRQ::USART2> {};
template <>
struct HardwareMap<mmio::UART3>
    : public detail::HardwareMapDefinition<mmio::UART3,
                                           Clock::APB1::UART3EN,
                                           Irq::IRQ::UART3> {};
template <>
struct HardwareMap<mmio::UART4>
    : public detail::HardwareMapDefinition<mmio::UART4,
                                           Clock::APB1::UART4EN,
                                           Irq::IRQ::UART4> {};

template <>
struct UartDevice<0> {
  static inline auto &device{mmio::USART0};
};
template <>
struct UartDevice<1> {
  static inline auto &device{mmio::USART1};
};
template <>
struct UartDevice<2> {
  static inline auto &device{mmio::USART2};
};
template <>
struct UartDevice<3> {
  static inline auto &device{mmio::UART3};
};
template <>
struct UartDevice<4> {
  static inline auto &device{mmio::UART4};
};
}  // namespace deri::soc
