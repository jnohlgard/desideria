/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/timer_dev.hpp"

namespace deri::soc {

void timerInterrupt(TimerDriver &driver, const TimerPeriph &timer_dev) {
  using INTF_bits = deri::mmio::TIMER_regs::INTF_bits;
  auto intf = timer_dev.interruptFlag();
  if (!!(intf & INTF_bits::UPIF)) {
    driver.periodCallback();
  }
  if (!!(intf & INTF_bits::CH0IF)) {
    driver.interruptCallback(static_cast<TimerDriver::Channel>(0));
  }
  if (!!(intf & INTF_bits::CH1IF)) {
    driver.interruptCallback(static_cast<TimerDriver::Channel>(1));
  }
  if (!!(intf & INTF_bits::CH2IF)) {
    driver.interruptCallback(static_cast<TimerDriver::Channel>(2));
  }
  if (!!(intf & INTF_bits::CH3IF)) {
    driver.interruptCallback(static_cast<TimerDriver::Channel>(3));
  }
}
}  // namespace deri::soc

using deri::soc::timerInterrupt;
extern "C" {
[[gnu::interrupt]] void isr_TIMER0_Channel();
void isr_TIMER0_Channel() {
  timerInterrupt(deri::soc::timers[0], deri::soc::timer0);
}
[[gnu::interrupt]] void isr_TIMER0_UP();
void isr_TIMER0_UP() {
  timerInterrupt(deri::soc::timers[0], deri::soc::timer0);
}
[[gnu::interrupt]] void isr_TIMER1();
void isr_TIMER1() { timerInterrupt(deri::soc::timers[1], deri::soc::timer1); }
[[gnu::interrupt]] void isr_TIMER2();
void isr_TIMER2() { timerInterrupt(deri::soc::timers[2], deri::soc::timer2); }
[[gnu::interrupt]] void isr_TIMER3();
void isr_TIMER3() { timerInterrupt(deri::soc::timers[3], deri::soc::timer3); }
[[gnu::interrupt]] void isr_TIMER4();
void isr_TIMER4() { timerInterrupt(deri::soc::timers[4], deri::soc::timer4); }
[[gnu::interrupt]] void isr_TIMER5();
void isr_TIMER5() { timerInterrupt(deri::soc::timers[5], deri::soc::timer5); }
[[gnu::interrupt]] void isr_TIMER6();
void isr_TIMER6() { timerInterrupt(deri::soc::timers[6], deri::soc::timer6); }
}
