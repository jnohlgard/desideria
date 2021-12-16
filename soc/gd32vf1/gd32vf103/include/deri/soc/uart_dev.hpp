/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/uart_gd32.hpp"
#include "deri/mmio/USART.hpp"
#include "deri/mmio/bits/USART_bits.hpp"
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"

namespace deri::mmio {
extern USART_regs USART0;
extern USART_regs USART1;
extern USART_regs USART2;
extern USART_regs UART3;
extern USART_regs UART4;
}  // namespace deri::mmio

namespace deri::soc {

// avoiding C++ static initialization order fiasco by wrapping each device in a
// function
inline dev::uart::UsartGd32 &uart0() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UsartGd32{mmio::USART0};
    soc::rcu.enableModules(dev::clock::RcuGd32::APB2EN_bits::USART0EN);
    instance.updateModuleClock(rcu.apb2Freq());
    clic.enableIrq(mmio::IRQ::USART0);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UsartGd32 &uart1() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UsartGd32{mmio::USART1};
    soc::rcu.enableModules(dev::clock::RcuGd32::APB1EN_bits::USART1EN);
    instance.updateModuleClock(rcu.apb1Freq());
    clic.enableIrq(mmio::IRQ::USART1);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UsartGd32 &uart2() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UsartGd32{mmio::USART2};
    soc::rcu.enableModules(dev::clock::RcuGd32::APB1EN_bits::USART2EN);
    instance.updateModuleClock(rcu.apb1Freq());
    clic.enableIrq(mmio::IRQ::USART2);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UsartGd32 &uart3() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UsartGd32{mmio::UART3};
    soc::rcu.enableModules(dev::clock::RcuGd32::APB1EN_bits::UART3EN);
    instance.updateModuleClock(rcu.apb1Freq());
    clic.enableIrq(mmio::IRQ::UART3);
    return instance;
  }
  ();
  return instance;
}
inline dev::uart::UsartGd32 &uart4() {
  static auto &instance = []() -> auto & {
    static auto instance = dev::uart::UsartGd32{mmio::UART4};
    soc::rcu.enableModules(dev::clock::RcuGd32::APB1EN_bits::UART4EN);
    instance.updateModuleClock(rcu.apb1Freq());
    clic.enableIrq(mmio::IRQ::UART4);
    return instance;
  }
  ();
  return instance;
}
}  // namespace deri::soc