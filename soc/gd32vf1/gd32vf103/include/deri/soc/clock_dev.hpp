/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/callback.hpp"
#include "deri/dev/clock.hpp"
#include "deri/dev/clock_gd32.hpp"
#include "deri/irq.hpp"
#include "deri/log.hpp"

namespace deri::mmio {
extern dev::clock::RcuGd32 RCU;
}  // namespace deri::mmio

namespace deri::log {
struct Clock;
}  // namespace deri::log

namespace deri::soc {

template <typename ClockBits>
class OnClockChangeHelperDispatch;
template <auto clock_bits>
class OnClockChangeHelper;

// Timers on APB1 and APB2 have special logic for the prescaler setting,
class APB1Timer {};
class APB2Timer {};

class Clock {
 private:
  using Logger = log::Logger<log::Clock>;

 public:
  using OnClockChange = dev::clock::OnClockChange;
  enum class Core {};
  using AHB = mmio::RCU_regs::AHBEN_bits;
  using APB1 = mmio::RCU_regs::APB1EN_bits;
  using APB2 = mmio::RCU_regs::APB2EN_bits;

  using HxtalConfig = dev::clock::RcuGd32::HxtalConfig;
  using Irc8MConfig = dev::clock::RcuGd32::Irc8MConfig;
  using PllConfig = dev::clock::RcuGd32::PllConfig;

  template <typename Bits>
  static void enable(Bits bits) {
    mmio::RCU.enableModules(bits);
  }

  [[nodiscard]] static unsigned current(Core) { return mmio::RCU.sysFreq(); }
  [[nodiscard]] static unsigned current(AHB) { return mmio::RCU.ahbFreq(); }
  [[nodiscard]] static unsigned current(APB1) { return mmio::RCU.apb1Freq(); }
  [[nodiscard]] static unsigned current(APB2) { return mmio::RCU.apb2Freq(); }

  template <auto clock_bits>
  static void onClockChange(OnClockChange &on_clock_change) {
    OnClockChangeHelper<clock_bits>::push(on_clock_change);
  };

  template <class Config>
  static void apply(const Config &config) {
    Logger::info("Applying new clock config\n");
    mmio::RCU.setConfig(config);
    runEvents<AHB>();
    runEvents<APB1>();
    runEvents<APB2>();
    auto apb1timer_freq = mmio::RCU.timerFreq(APB1{});
    runEvents<APB1Timer>(apb1timer_freq);
    auto apb2timer_freq = mmio::RCU.timerFreq(APB2{});
    runEvents<APB2Timer>(apb2timer_freq);
    Logger::info("New clocks:\n");
    Logger::info("Core = %u, AHB = %u, APB1 = %u, APB2 = %u\n",
                 current(Core{}),
                 current(AHB{}),
                 current(APB1{}),
                 current(APB2{}));
  }

 private:
  template <typename ClockBits>
  static void runEvents() {
    auto freq = current(ClockBits{});
    runEvents<ClockBits>(freq);
  }

  template <typename ClockBits>
  static void runEvents(unsigned new_clock_frequency) {
    for (const auto &on_clock_change : bus_users<ClockBits>) {
      Logger::debug(
          "onClockChange(%lu, %p)\n",
          static_cast<unsigned long>(new_clock_frequency),
          reinterpret_cast<const void *>(on_clock_change.callback.arg));
      on_clock_change.callback.func(new_clock_frequency,
                                    on_clock_change.callback.arg);
    }
  }

  template <typename ClockBits>
  static inline ForwardList<OnClockChange> bus_users{};

  template <auto clock_bits>
  friend class OnClockChangeHelper;
};

template <auto clock_bits>
class OnClockChangeHelper {
  friend Clock;
  static inline void push(Clock::OnClockChange &on_clock_change);
};

template <auto clock_bits>
inline void OnClockChangeHelper<clock_bits>::push(
    Clock::OnClockChange &on_clock_change) {
  arch::CriticalSection cs{};
  Clock::bus_users<decltype(clock_bits)>.remove(on_clock_change);
  Clock::bus_users<decltype(clock_bits)>.push_front(on_clock_change);
}

// this set of template specializations will put the Timer OnClockChange
// callbacks in a separate list
template <>
class OnClockChangeHelper<Clock::APB2::TIMER0EN>
    : public OnClockChangeHelper<APB2Timer{}> {};
template <>
class OnClockChangeHelper<Clock::APB1::TIMER1EN>
    : public OnClockChangeHelper<APB1Timer{}> {};
template <>
class OnClockChangeHelper<Clock::APB1::TIMER2EN>
    : public OnClockChangeHelper<APB1Timer{}> {};
template <>
class OnClockChangeHelper<Clock::APB1::TIMER3EN>
    : public OnClockChangeHelper<APB1Timer{}> {};
template <>
class OnClockChangeHelper<Clock::APB1::TIMER4EN>
    : public OnClockChangeHelper<APB1Timer{}> {};
template <>
class OnClockChangeHelper<Clock::APB1::TIMER5EN>
    : public OnClockChangeHelper<APB1Timer{}> {};
template <>
class OnClockChangeHelper<Clock::APB1::TIMER6EN>
    : public OnClockChangeHelper<APB1Timer{}> {};

}  // namespace deri::soc
