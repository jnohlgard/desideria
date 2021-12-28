/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/timer_dev.hpp"

#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"

namespace deri::soc {

std::array<TimerPeriphDriver *, 7> timers;

// By instantiating this template for each hardware instance we get a unique
// static variable for each driver instance
template <int index,
          class Driver,
          auto *device,
          auto clock_enable_bits,
          auto... irqs>
Driver &driverInstance() {
  static auto driver = Driver{*device};
  Clock::enable(clock_enable_bits);
  driver.init();
  driver.updateModuleClock(moduleClock(clock_enable_bits));
  (Irq::enable(irqs), ...);
  Clock::onClockChange(driver.clockChangeCallback(), clock_enable_bits);
  timers[index] = &driver;
  return driver;
}

TimerPeriphDriver &timer0() {
  return driverInstance<0,
                        TimerPeriphDriver,
                        &mmio::TIMER0,
                        soc::Clock::APB2::TIMER0EN,
                        mmio::IRQ::TIMER0_Channel,
                        mmio::IRQ::TIMER0_UP>();
}
TimerPeriphDriver &timer1() {
  return driverInstance<1,
                        TimerPeriphDriver,
                        &mmio::TIMER1,
                        soc::Clock::APB1::TIMER1EN,
                        mmio::IRQ::TIMER1>();
}
TimerPeriphDriver &timer2() {
  return driverInstance<2,
                        TimerPeriphDriver,
                        &mmio::TIMER2,
                        soc::Clock::APB1::TIMER2EN,
                        mmio::IRQ::TIMER2>();
}
TimerPeriphDriver &timer3() {
  return driverInstance<3,
                        TimerPeriphDriver,
                        &mmio::TIMER3,
                        soc::Clock::APB1::TIMER3EN,
                        mmio::IRQ::TIMER3>();
}
TimerPeriphDriver &timer4() {
  return driverInstance<4,
                        TimerPeriphDriver,
                        &mmio::TIMER4,
                        soc::Clock::APB1::TIMER4EN,
                        mmio::IRQ::TIMER4>();
}
TimerPeriphDriver &timer5() {
  return driverInstance<5,
                        TimerPeriphDriver,
                        &mmio::TIMER5,
                        soc::Clock::APB1::TIMER5EN,
                        mmio::IRQ::TIMER5>();
}
TimerPeriphDriver &timer6() {
  return driverInstance<6,
                        TimerPeriphDriver,
                        &mmio::TIMER6,
                        soc::Clock::APB1::TIMER6EN,
                        mmio::IRQ::TIMER6>();
}

dev::timer::TimerDriver<dev::timer::TimerRiscv> &mtime() {
  static auto &instance = []() -> auto & {
    static auto device = dev::timer::TimerRiscv{};
    static auto driver = dev::timer::TimerDriver{device};
    return driver;
  }
  ();
  return instance;
}

void timerInterrupt(TimerPeriphDriver &driver) {
  auto &dev = driver.underlyingTimer();
  auto intf = dev.interruptFlag();
  dev.clearInterruptFlag(intf);
  using INTF = decltype(intf);
  if (!!(intf & INTF::UPIF)) {
    driver.periodInterrupt();
  }
  if (!!(intf & INTF::CH0IF)) {
    driver.channelInterrupt(TimerPeriphDriver::Channel::CH0);
  }
  if (!!(intf & INTF::CH1IF)) {
    driver.channelInterrupt(TimerPeriphDriver::Channel::CH1);
  }
  if (!!(intf & INTF::CH2IF)) {
    driver.channelInterrupt(TimerPeriphDriver::Channel::CH2);
  }
  if (!!(intf & INTF::CH3IF)) {
    driver.channelInterrupt(TimerPeriphDriver::Channel::CH3);
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

[[gnu::interrupt]] void isr_CLIC_INT_TMR();
void isr_CLIC_INT_TMR() {
  deri::soc::mtime().channelInterrupt(deri::dev::timer::TimerRiscv::Channel{});
}
}
