/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/timer_dev.hpp"

#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"

namespace deri::soc {

template <class Driver>
void timerInterrupt(Driver &driver) {
  auto &dev = driver.underlyingTimer();
  auto intf = dev.interruptFlag();
  dev.clearInterruptFlag(intf);
  using INTF = decltype(intf);
  if (!!(intf & INTF::UPIF)) {
    driver.periodInterrupt();
  }
  if (!!(intf & INTF::CH0IF)) {
    driver.channelInterrupt(Driver::Channel::CH0);
  }
  if (!!(intf & INTF::CH1IF)) {
    driver.channelInterrupt(Driver::Channel::CH1);
  }
  if (!!(intf & INTF::CH2IF)) {
    driver.channelInterrupt(Driver::Channel::CH2);
  }
  if (!!(intf & INTF::CH3IF)) {
    driver.channelInterrupt(Driver::Channel::CH3);
  }
}
}  // namespace deri::soc

using deri::soc::timerInterrupt;

extern "C" {
// This aliased function for TIMER0 is a workaround for a bug in GCC
// when compiling with -Os and two interrupt functions have the same body.
// https://godbolt.org/z/Pe6s9bMj4

[[gnu::interrupt]] void isr_TIMER0();
void isr_TIMER0() { timerInterrupt(*deri::soc::Timer<0>::static_instance); }
[[gnu::alias("isr_TIMER0")]] void isr_TIMER0_Channel();
[[gnu::alias("isr_TIMER0")]] void isr_TIMER0_UP();
[[gnu::interrupt]] void isr_TIMER1();
void isr_TIMER1() { timerInterrupt(*deri::soc::Timer<1>::static_instance); }
[[gnu::interrupt]] void isr_TIMER2();
void isr_TIMER2() { timerInterrupt(*deri::soc::Timer<2>::static_instance); }
[[gnu::interrupt]] void isr_TIMER3();
void isr_TIMER3() { timerInterrupt(*deri::soc::Timer<3>::static_instance); }
[[gnu::interrupt]] void isr_TIMER4();
void isr_TIMER4() { timerInterrupt(*deri::soc::Timer<4>::static_instance); }
[[gnu::interrupt]] void isr_TIMER5();
void isr_TIMER5() { timerInterrupt(*deri::soc::Timer<5>::static_instance); }
[[gnu::interrupt]] void isr_TIMER6();
void isr_TIMER6() { timerInterrupt(*deri::soc::Timer<6>::static_instance); }

[[gnu::interrupt]] void isr_CLIC_INT_TMR();
void isr_CLIC_INT_TMR() {
  deri::soc::mtime().channelInterrupt(deri::dev::timer::TimerRiscv::Channel{});
}
}
