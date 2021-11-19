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

GpioGd32 &gpioPortDev(Gpio::Port port) {
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
extern "C" {
void isr_EXTI_Line0() __attribute__((__interrupt__));
void isr_EXTI_Line0() {
  exti.clearPending(static_cast<ExtiGd32::Line>(0));
  gpio.interruptCallback(0);
}
void isr_EXTI_Line1() __attribute__((__interrupt__));
void isr_EXTI_Line1() {
  exti.clearPending(static_cast<ExtiGd32::Line>(1));
  gpio.interruptCallback(1);
}
void isr_EXTI_Line2() __attribute__((__interrupt__));
void isr_EXTI_Line2() {
  exti.clearPending(static_cast<ExtiGd32::Line>(2));
  gpio.interruptCallback(2);
}
void isr_EXTI_Line3() __attribute__((__interrupt__));
void isr_EXTI_Line3() {
  exti.clearPending(static_cast<ExtiGd32::Line>(3));
  gpio.interruptCallback(3);
}
void isr_EXTI_Line4() __attribute__((__interrupt__));
void isr_EXTI_Line4() {
  exti.clearPending(static_cast<ExtiGd32::Line>(4));
  gpio.interruptCallback(4);
}
void isr_EXTI_line9_5() __attribute__((__interrupt__));
void isr_EXTI_line9_5() {
  using PD_bits = deri::mmio::EXTI_regs::PD_bits;
  auto pending = exti.pending();
  pending &= static_cast<PD_bits>(0b11111 << 5);
  exti.clearPending(pending);
  for (unsigned line_number = 5; line_number <= 9; ++line_number) {
    if (!!(pending & static_cast<PD_bits>(1u << line_number))) {
      gpio.interruptCallback(line_number);
    }
  }
}
void isr_EXTI_line15_10() __attribute__((__interrupt__));
void isr_EXTI_line15_10() {
  using PD_bits = deri::mmio::EXTI_regs::PD_bits;
  auto pending = exti.pending();
  pending &= static_cast<PD_bits>(0b11111u << 10);
  exti.clearPending(pending);
  for (unsigned line_number = 10; line_number <= 15; ++line_number) {
    if (!!(pending & static_cast<PD_bits>(1u << line_number))) {
      gpio.interruptCallback(line_number);
    }
  }
}
}
