/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/timer_dev.hpp"

namespace deri::soc {

void timerInterrupt(TimerDriver &driver) {
  auto &dev = driver.underlyingTimer();
  auto intf = dev.interruptFlag();
  dev.clearInterruptFlag(intf);
  using INTF = decltype(intf);
  if (!!(intf & INTF::UPIF)) {
    driver.periodInterrupt();
  }
  if (!!(intf & INTF::CH0IF)) {
    driver.channelInterrupt(TimerDriver::Channel::CH0);
  }
  if (!!(intf & INTF::CH1IF)) {
    driver.channelInterrupt(TimerDriver::Channel::CH1);
  }
  if (!!(intf & INTF::CH2IF)) {
    driver.channelInterrupt(TimerDriver::Channel::CH2);
  }
  if (!!(intf & INTF::CH3IF)) {
    driver.channelInterrupt(TimerDriver::Channel::CH3);
  }
}
}  // namespace deri::soc

using deri::soc::timerInterrupt;

extern "C" {
// This aliased function for TIMER0 is a workaround for a bug in GCC
// when compiling with -Os and two interrupt functions have the same body.
// https://godbolt.org/z/Pe6s9bMj4

[[gnu::interrupt]] void isr_TIMER0();
void isr_TIMER0() { timerInterrupt(*deri::soc::timers[0]); }
[[gnu::alias("isr_TIMER0")]] void isr_TIMER0_Channel();
[[gnu::alias("isr_TIMER0")]] void isr_TIMER0_UP();
[[gnu::interrupt]] void isr_TIMER1();
void isr_TIMER1() { timerInterrupt(*deri::soc::timers[1]); }
[[gnu::interrupt]] void isr_TIMER2();
void isr_TIMER2() { timerInterrupt(*deri::soc::timers[2]); }
[[gnu::interrupt]] void isr_TIMER3();
void isr_TIMER3() { timerInterrupt(*deri::soc::timers[3]); }
[[gnu::interrupt]] void isr_TIMER4();
void isr_TIMER4() { timerInterrupt(*deri::soc::timers[4]); }
[[gnu::interrupt]] void isr_TIMER5();
void isr_TIMER5() { timerInterrupt(*deri::soc::timers[5]); }
[[gnu::interrupt]] void isr_TIMER6();
void isr_TIMER6() { timerInterrupt(*deri::soc::timers[6]); }
}
