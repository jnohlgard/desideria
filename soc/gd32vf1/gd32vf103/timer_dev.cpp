/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/timer_dev.hpp"

namespace deri::soc {

void timerInterrupt(TimerDriver &driver) {
  auto &dev = driver.underlyingTimer();
  using INTF_bits = deri::mmio::TIMER_regs::INTF_bits;
  auto intf = dev.interruptFlag();
  dev.clearInterruptFlag(intf);
  if (!!(intf & INTF_bits::UPIF)) {
    driver.periodCallback();
  }
  if (!!(intf & INTF_bits::CH0IF)) {
    driver.interruptCallback(TimerDriver::Channel::CH0);
  }
  if (!!(intf & INTF_bits::CH1IF)) {
    driver.interruptCallback(TimerDriver::Channel::CH1);
  }
  if (!!(intf & INTF_bits::CH2IF)) {
    driver.interruptCallback(TimerDriver::Channel::CH2);
  }
  if (!!(intf & INTF_bits::CH3IF)) {
    driver.interruptCallback(TimerDriver::Channel::CH3);
  }
}
}  // namespace deri::soc

using deri::soc::timerInterrupt;
// This extra level of indirection for TIMER0 is a workaround for a bug in GCC
// when compiling with -Os and two interrupt functions have the same body.
// https://godbolt.org/z/Pe6s9bMj4
void TIMER0_interrupt() {
  timerInterrupt(deri::soc::timers[0]);
}

extern "C" {
[[gnu::interrupt]] void isr_TIMER0_Channel();
void isr_TIMER0_Channel() {
  TIMER0_interrupt();
}
[[gnu::interrupt]] void isr_TIMER0_UP();
void isr_TIMER0_UP() {
  TIMER0_interrupt();
}
[[gnu::interrupt]] void isr_TIMER1();
void isr_TIMER1() {
  timerInterrupt(deri::soc::timers[1]);
}
[[gnu::interrupt]] void isr_TIMER2();
void isr_TIMER2() {
  timerInterrupt(deri::soc::timers[2]);
}
[[gnu::interrupt]] void isr_TIMER3();
void isr_TIMER3() {
  timerInterrupt(deri::soc::timers[3]);
}
[[gnu::interrupt]] void isr_TIMER4();
void isr_TIMER4() {
  timerInterrupt(deri::soc::timers[4]);
}
[[gnu::interrupt]] void isr_TIMER5();
void isr_TIMER5() {
  timerInterrupt(deri::soc::timers[5]);
}
[[gnu::interrupt]] void isr_TIMER6();
void isr_TIMER6() {
  timerInterrupt(deri::soc::timers[6]);
}
}
