/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/mmio_driver.hpp"
#include "deri/dev/timer.hpp"
#include "deri/dev/timer_gd32.hpp"
#include "deri/dev/timer_riscv.hpp"
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
}  // namespace deri::mmio

namespace deri::soc {

template <>
struct DefaultConfig<TimerPeriph> {
  using Driver = dev::timer::TimerDriver<TimerPeriph>;
};

template <>
struct HardwareMap<mmio::TIMER0>
    : public detail::HardwareMapDefinition<mmio::TIMER0,
                                           Clock::APB2::TIMER0EN,
                                           Irq::IRQ::TIMER0_UP,
                                           Irq::IRQ::TIMER0_Channel> {};
template <>
struct HardwareMap<mmio::TIMER1>
    : public detail::HardwareMapDefinition<mmio::TIMER1,
                                           Clock::APB1::TIMER1EN,
                                           Irq::IRQ::TIMER1> {};
template <>
struct HardwareMap<mmio::TIMER2>
    : public detail::HardwareMapDefinition<mmio::TIMER2,
                                           Clock::APB1::TIMER2EN,
                                           Irq::IRQ::TIMER2> {};
template <>
struct HardwareMap<mmio::TIMER3>
    : public detail::HardwareMapDefinition<mmio::TIMER3,
                                           Clock::APB1::TIMER3EN,
                                           Irq::IRQ::TIMER3> {};
template <>
struct HardwareMap<mmio::TIMER4>
    : public detail::HardwareMapDefinition<mmio::TIMER4,
                                           Clock::APB1::TIMER4EN,
                                           Irq::IRQ::TIMER4> {};
template <>
struct HardwareMap<mmio::TIMER5>
    : public detail::HardwareMapDefinition<mmio::TIMER5,
                                           Clock::APB1::TIMER5EN,
                                           Irq::IRQ::TIMER5> {};
template <>
struct HardwareMap<mmio::TIMER6>
    : public detail::HardwareMapDefinition<mmio::TIMER6,
                                           Clock::APB1::TIMER6EN,
                                           Irq::IRQ::TIMER6> {};
}  // namespace deri::soc

namespace deri::soc {

template <>
struct TimerDevice<0> {
  static inline auto &device{mmio::TIMER0};
};
template <>
struct TimerDevice<1> {
  static inline auto &device{mmio::TIMER1};
};
template <>
struct TimerDevice<2> {
  static inline auto &device{mmio::TIMER2};
};
template <>
struct TimerDevice<3> {
  static inline auto &device{mmio::TIMER3};
};
template <>
struct TimerDevice<4> {
  static inline auto &device{mmio::TIMER4};
};
template <>
struct TimerDevice<5> {
  static inline auto &device{mmio::TIMER5};
};
template <>
struct TimerDevice<6> {
  static inline auto &device{mmio::TIMER6};
};

dev::timer::TimerDriver<dev::timer::TimerRiscv> &mtime();

}  // namespace deri::soc
