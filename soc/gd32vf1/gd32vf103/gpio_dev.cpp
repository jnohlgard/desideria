/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/gpio_dev.h"

#include "deri/dev/exti_gd32.h"
#include "deri/dev/gpio_gd32.h"
#include "deri/mmio/bits/RCU_bits.hpp"
#include "deri/mmio/interrupts.hpp"
#include "deri/soc/irq_dev.h"

#include <array>
#include <functional>

using namespace deri::dev::gpio;

namespace deri::soc {

using APB2EN_bits = mmio::RCU_regs::APB2EN_bits;

namespace {
constexpr std::array gpioPorts{
    std::ref(gpioa),
    std::ref(gpiob),
    std::ref(gpioc),
    std::ref(gpiod),
    std::ref(gpioe),
};
constexpr std::array gpioPortClockEnableBitMasks{
    APB2EN_bits::PAEN,
    APB2EN_bits::PBEN,
    APB2EN_bits::PCEN,
    APB2EN_bits::PDEN,
    APB2EN_bits::PEEN,
};
}  // namespace

GpioManagerGd32 gpio;

GpioPortGd32 &gpioPortDev(Gpio::Port port) {
  return gpioPorts[static_cast<std::underlying_type_t<Gpio::Port>>(port)];
}

APB2EN_bits gpioPortClockEnableBits(Gpio::Port port) {
  return gpioPortClockEnableBitMasks
      [static_cast<std::underlying_type_t<Gpio::Port>>(port)];
}
}  // namespace deri::soc

namespace deri::dev::gpio {
void ExtiGd32::clicInterruptEnable(ExtiGd32::Line line) {
  auto line_number = static_cast<unsigned>(line);
  using IRQ = deri::mmio::IRQ;
  switch (line_number) {
    case 0:
      soc::clic.enable_irq(IRQ::EXTI_Line0);
      break;
    case 1:
      soc::clic.enable_irq(IRQ::EXTI_Line1);
      break;
    case 2:
      soc::clic.enable_irq(IRQ::EXTI_Line2);
      break;
    case 3:
      soc::clic.enable_irq(IRQ::EXTI_Line3);
      break;
    case 4:
      soc::clic.enable_irq(IRQ::EXTI_Line4);
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      soc::clic.enable_irq(IRQ::EXTI_line9_5);
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      soc::clic.enable_irq(IRQ::EXTI_line15_10);
      break;
  }
}
void ExtiGd32::clicInterruptDisable(ExtiGd32::Line line) {
  auto line_number = static_cast<unsigned>(line);
  using IRQ = deri::mmio::IRQ;
  switch (line_number) {
    case 0:
      soc::clic.disable_irq(IRQ::EXTI_Line0);
      break;
    case 1:
      soc::clic.disable_irq(IRQ::EXTI_Line1);
      break;
    case 2:
      soc::clic.disable_irq(IRQ::EXTI_Line2);
      break;
    case 3:
      soc::clic.disable_irq(IRQ::EXTI_Line3);
      break;
    case 4:
      soc::clic.disable_irq(IRQ::EXTI_Line4);
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      soc::clic.disable_irq(IRQ::EXTI_line9_5);
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      soc::clic.disable_irq(IRQ::EXTI_line15_10);
      break;
  }
}

}  // namespace deri::dev::gpio

using namespace deri::soc;

namespace {
void gpio_interrupt(unsigned line) {
  exti.clearPending(static_cast<ExtiGd32::Line>(line));
  gpio.interruptCallback(line);
}
using PD_bits = deri::mmio::EXTI_regs::PD_bits;
void gpio_interrupts_grouped(PD_bits pending, unsigned line) {
  exti.clearPending(pending);
  unsigned pending_lines = static_cast<unsigned>(pending) >> line;
  while (pending_lines != 0) {
    if ((pending_lines & 1) != 0) {
      gpio.interruptCallback(line);
    }
    pending_lines >>= 1;
    ++line;
  }
}
}  // namespace

extern "C" {
[[gnu::interrupt]] void isr_EXTI_Line0();
void isr_EXTI_Line0() { gpio_interrupt(0); }
[[gnu::interrupt]] void isr_EXTI_Line1();
void isr_EXTI_Line1() { gpio_interrupt(1); }
[[gnu::interrupt]] void isr_EXTI_Line2();
void isr_EXTI_Line2() { gpio_interrupt(2); }
[[gnu::interrupt]] void isr_EXTI_Line3();
void isr_EXTI_Line3() { gpio_interrupt(3); }
[[gnu::interrupt]] void isr_EXTI_Line4();
void isr_EXTI_Line4() { gpio_interrupt(4); }
[[gnu::interrupt]] void isr_EXTI_line9_5();
void isr_EXTI_line9_5() {
  auto pending = exti.pending();
  unsigned line_number = 5;
  pending &= static_cast<PD_bits>(0b11111u << line_number);
  gpio_interrupts_grouped(pending, line_number);
}
[[gnu::interrupt]] void isr_EXTI_line15_10();
void isr_EXTI_line15_10() {
  auto pending = exti.pending();
  unsigned line_number = 10;
  pending &= static_cast<PD_bits>(0b111111u << line_number);
  gpio_interrupts_grouped(pending, line_number);
}
}
