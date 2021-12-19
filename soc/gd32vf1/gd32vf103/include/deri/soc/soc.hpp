/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"

namespace deri::soc {
inline unsigned moduleClock(Clock::APB2 clock_bits) {
  // assert clock_bits == ~(clock_bits - 1) + 1
  if (clock_bits == Clock::APB2::TIMER0EN) {
    return mmio::RCU.timerFreq(clock_bits);
  }
  return mmio::RCU.apb2Freq();
}
inline unsigned moduleClock(Clock::APB1 clock_bits) {
  switch (clock_bits) {
    case Clock::APB1::TIMER1EN:
    case Clock::APB1::TIMER2EN:
    case Clock::APB1::TIMER3EN:
    case Clock::APB1::TIMER4EN:
    case Clock::APB1::TIMER5EN:
    case Clock::APB1::TIMER6EN:
      return mmio::RCU.timerFreq(clock_bits);
    default:
      return mmio::RCU.apb1Freq();
  }
}
inline unsigned moduleClock(Clock::AHB) { return mmio::RCU.ahbFreq(); }

template <class Driver, typename ClockEnable, typename... Irqs>
inline void moduleEnable(Driver &driver, ClockEnable clock_bits, Irqs... irqs) {
  Clock::enable(clock_bits);
  driver.init();
  driver.updateModuleClock(moduleClock(clock_bits));
  (Irq::enable(irqs), ...);
}
}  // namespace deri::soc
