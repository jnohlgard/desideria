/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/timer.hpp"
#include "deri/dev/timer_gd32.hpp"
#include "deri/dev/timer_riscv.hpp"
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"
#include "deri/soc/soc.hpp"

#include <array>

namespace deri::soc {
using TimerPeriph = dev::timer::TimerGd32;
}
namespace deri::mmio {
extern soc::TimerPeriph TIMER0;
extern soc::TimerPeriph TIMER1;
extern soc::TimerPeriph TIMER2;
extern soc::TimerPeriph TIMER3;
extern soc::TimerPeriph TIMER4;
extern soc::TimerPeriph TIMER5;
extern soc::TimerPeriph TIMER6;
extern dev::timer::TimerRiscv MTIME;
}  // namespace deri::mmio

namespace deri::soc {
using TimerDriver = dev::timer::TimerDriver<TimerPeriph>;

inline std::array<TimerDriver *, 7> timers;

inline auto &timer0() {
  static auto &instance = []() -> auto & {
    static auto instance = TimerDriver{mmio::TIMER0};
    moduleEnable(instance,
                 soc::Clock::APB2::TIMER0EN,
                 mmio::IRQ::TIMER0_Channel,
                 mmio::IRQ::TIMER0_UP);
    timers[0] = &instance;
    return instance;
  }
  ();
  return instance;
}
inline auto &timer1() {
  static auto &instance = []() -> auto & {
    static auto instance = TimerDriver{mmio::TIMER1};
    moduleEnable(instance, soc::Clock::APB1::TIMER1EN, mmio::IRQ::TIMER1);
    return instance;
    timers[1] = &instance;
  }
  ();
  return instance;
}
inline auto &timer2() {
  static auto &instance = []() -> auto & {
    static auto instance = TimerDriver{mmio::TIMER2};
    moduleEnable(instance, soc::Clock::APB1::TIMER2EN, mmio::IRQ::TIMER2);
    timers[2] = &instance;
    return instance;
  }
  ();
  return instance;
}
inline auto &timer3() {
  static auto &instance = []() -> auto & {
    static auto instance = TimerDriver{mmio::TIMER3};
    moduleEnable(instance, soc::Clock::APB1::TIMER3EN, mmio::IRQ::TIMER3);
    timers[3] = &instance;
    return instance;
  }
  ();
  return instance;
}
inline auto &timer4() {
  static auto &instance = []() -> auto & {
    static auto instance = TimerDriver{mmio::TIMER4};
    moduleEnable(instance, soc::Clock::APB1::TIMER4EN, mmio::IRQ::TIMER4);
    timers[4] = &instance;
    return instance;
  }
  ();
  return instance;
}
inline auto &timer5() {
  static auto &instance = []() -> auto & {
    static auto instance = TimerDriver{mmio::TIMER5};
    moduleEnable(instance, soc::Clock::APB1::TIMER5EN, mmio::IRQ::TIMER5);
    timers[5] = &instance;
    return instance;
  }
  ();
  return instance;
}
inline auto &timer6() {
  static auto &instance = []() -> auto & {
    static auto instance = TimerDriver{mmio::TIMER6};
    moduleEnable(instance, soc::Clock::APB1::TIMER6EN, mmio::IRQ::TIMER6);
    timers[6] = &instance;
    return instance;
  }
  ();
  return instance;
}
inline auto &mtime() {
  static auto &instance = []() -> auto & {
    static auto driver =
        dev::timer::TimerDriver<dev::timer::TimerRiscv>{mmio::MTIME};
    return driver;
  }
  ();
  return instance;
}

}  // namespace deri::soc
