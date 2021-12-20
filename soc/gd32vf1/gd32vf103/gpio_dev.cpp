/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/gpio_dev.hpp"

#include "deri/dev/afio_gd32.hpp"
#include "deri/dev/exti_gd32.hpp"
#include "deri/dev/gpio_gd32.hpp"
#include "deri/mmio/bits/RCU_bits.hpp"
#include "deri/mmio/interrupts.hpp"
#include "deri/soc/irq_dev.hpp"

#include <array>
#include <functional>

using namespace deri::dev::gpio;

namespace deri::soc {

using APB2EN_bits = mmio::RCU_regs::APB2EN_bits;

namespace {
constexpr std::array gpio_ports{
    std::ref(gpioa),
    std::ref(gpiob),
    std::ref(gpioc),
    std::ref(gpiod),
    std::ref(gpioe),
};
constexpr std::array gpio_port_clock_enable_bit_masks{
    APB2EN_bits::PAEN,
    APB2EN_bits::PBEN,
    APB2EN_bits::PCEN,
    APB2EN_bits::PDEN,
    APB2EN_bits::PEEN,
};
}  // namespace

GpioManagerGd32 gpio;

GpioPortGd32 &gpioPortDev(Gpio::Port port) {
  return gpio_ports[static_cast<std::underlying_type_t<Gpio::Port>>(port)];
}

APB2EN_bits gpioPortClockEnableBits(Gpio::Port port) {
  return gpio_port_clock_enable_bit_masks
      [static_cast<std::underlying_type_t<Gpio::Port>>(port)];
}
}  // namespace deri::soc

namespace deri::dev::gpio {
void ExtiGd32::clicInterruptEnable(ExtiGd32::Line line) {
  auto line_number = static_cast<unsigned>(line);
  using IRQ = deri::mmio::IRQ;
  switch (line_number) {
    case 0:
      soc::Irq::enable(IRQ::EXTI_Line0);
      break;
    case 1:
      soc::Irq::enable(IRQ::EXTI_Line1);
      break;
    case 2:
      soc::Irq::enable(IRQ::EXTI_Line2);
      break;
    case 3:
      soc::Irq::enable(IRQ::EXTI_Line3);
      break;
    case 4:
      soc::Irq::enable(IRQ::EXTI_Line4);
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      soc::Irq::enable(IRQ::EXTI_line9_5);
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      soc::Irq::enable(IRQ::EXTI_line15_10);
      break;
  }
}
void ExtiGd32::clicInterruptDisable(ExtiGd32::Line line) {
  auto line_number = static_cast<unsigned>(line);
  using IRQ = deri::mmio::IRQ;
  switch (line_number) {
    case 0:
      soc::Irq::disable(IRQ::EXTI_Line0);
      break;
    case 1:
      soc::Irq::disable(IRQ::EXTI_Line1);
      break;
    case 2:
      soc::Irq::disable(IRQ::EXTI_Line2);
      break;
    case 3:
      soc::Irq::disable(IRQ::EXTI_Line3);
      break;
    case 4:
      soc::Irq::disable(IRQ::EXTI_Line4);
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      soc::Irq::disable(IRQ::EXTI_line9_5);
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      soc::Irq::disable(IRQ::EXTI_line15_10);
      break;
  }
}

}  // namespace deri::dev::gpio

using namespace deri;

namespace {
using PD_bits = deri::mmio::EXTI_regs::PD_bits;

void gpioInterrupt(unsigned line) {
  mmio::EXTI.clearPending(static_cast<ExtiGd32::Line>(line));
  soc::gpio.interrupt(line);
}

void gpioInterruptsGrouped(PD_bits pending, unsigned line) {
  mmio::EXTI.clearPending(pending);
  unsigned pending_lines = static_cast<unsigned>(pending) >> line;
  while (pending_lines != 0) {
    if ((pending_lines & 1) != 0) {
      soc::gpio.interrupt(line);
    }
    pending_lines >>= 1;
    ++line;
  }
}

constexpr PD_bits pendingMask(unsigned group_first, unsigned group_last) {
  auto group_width = group_last - group_first + 1;
  return static_cast<PD_bits>(((1u << group_width) - 1) << group_first);
}
}  // namespace

extern "C" {
[[gnu::interrupt]] void isr_EXTI_Line0();
void isr_EXTI_Line0() { gpioInterrupt(0); }
[[gnu::interrupt]] void isr_EXTI_Line1();
void isr_EXTI_Line1() { gpioInterrupt(1); }
[[gnu::interrupt]] void isr_EXTI_Line2();
void isr_EXTI_Line2() { gpioInterrupt(2); }
[[gnu::interrupt]] void isr_EXTI_Line3();
void isr_EXTI_Line3() { gpioInterrupt(3); }
[[gnu::interrupt]] void isr_EXTI_Line4();
void isr_EXTI_Line4() { gpioInterrupt(4); }
[[gnu::interrupt]] void isr_EXTI_line9_5();
void isr_EXTI_line9_5() {
  auto pending = mmio::EXTI.pending();
  constexpr auto group_first = 5u;
  constexpr auto group_last = 9u;
  pending &= pendingMask(group_first, group_last);
  gpioInterruptsGrouped(pending, group_first);
}
[[gnu::interrupt]] void isr_EXTI_line15_10();
void isr_EXTI_line15_10() {
  auto pending = mmio::EXTI.pending();
  constexpr auto group_first = 10u;
  constexpr auto group_last = 15u;
  pending &= pendingMask(group_first, group_last);
  gpioInterruptsGrouped(pending, group_first);
}
}
