/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/soc/soc.hpp"
#include "deri/dev/uart.hpp"
#include "deri/dev/uart_gd32.hpp"
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"

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
// avoiding C++ static initialization order fiasco by wrapping each device in a
// function
inline dev::uart::UartIrqDriver<dev::uart::UsartGd32> &uart0() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UartIrqDriver{mmio::USART0};
    moduleEnable(instance, Clock::APB2::USART0EN, Irq::IRQ::USART0);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UartIrqDriver<dev::uart::UsartGd32> &uart1() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UartIrqDriver{mmio::USART1};
    moduleEnable(instance, Clock::APB1::USART1EN, Irq::IRQ::USART1);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UartIrqDriver<dev::uart::UsartGd32> &uart2() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UartIrqDriver{mmio::USART2};
    moduleEnable(instance, Clock::APB1::USART2EN, Irq::IRQ::USART2);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UartIrqDriver<dev::uart::UsartGd32> &uart3() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UartIrqDriver{mmio::UART3};
    moduleEnable(instance, Clock::APB1::UART3EN, Irq::IRQ::UART3);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UartIrqDriver<dev::uart::UsartGd32> &uart4() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UartIrqDriver{mmio::UART4};
    moduleEnable(instance, Clock::APB1::UART4EN, Irq::IRQ::UART4);
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::soc
