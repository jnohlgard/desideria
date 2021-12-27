/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/callback.hpp"
#include "deri/dev/clock.hpp"
#include "deri/dev/clock_gd32.hpp"
#include "deri/log.hpp"

namespace deri::mmio {
extern dev::clock::RcuGd32 RCU;
}  // namespace deri::mmio

namespace deri::log {
struct Clock;
}  // namespace deri::log

namespace deri::soc {
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

  template <typename Bits>
  static void enable(Bits bits) {
    mmio::RCU.enableModules(bits);
  }

  [[nodiscard]] static unsigned current(Core) { return mmio::RCU.sysFreq(); }
  [[nodiscard]] static unsigned current(AHB) { return mmio::RCU.ahbFreq(); }
  [[nodiscard]] static unsigned current(APB1) { return mmio::RCU.apb1Freq(); }
  [[nodiscard]] static unsigned current(APB2) { return mmio::RCU.apb2Freq(); }

  static void onClockChange(OnClockChange &on_clock_change, AHB) {
    arch::CriticalSection cs{};
    ahb_users.remove(on_clock_change);
    ahb_users.push_front(on_clock_change);
  }

  static void onClockChange(OnClockChange &on_clock_change,
                            APB1 clock_enable_bits) {
    arch::CriticalSection cs{};
    switch (clock_enable_bits) {
      case APB1::TIMER1EN:
      case APB1::TIMER2EN:
      case APB1::TIMER3EN:
      case APB1::TIMER4EN:
      case APB1::TIMER5EN:
      case APB1::TIMER6EN:
        apb1timer_users.remove(on_clock_change);
        apb1timer_users.push_front(on_clock_change);
        break;
      default:
        apb1_users.remove(on_clock_change);
        apb1_users.push_front(on_clock_change);
        break;
    }
  }

  static void onClockChange(OnClockChange &on_clock_change,
                            APB2 clock_enable_bits) {
    arch::CriticalSection cs{};
    if (clock_enable_bits == APB2::TIMER0EN) {
      apb2timer_users.remove(on_clock_change);
      apb2timer_users.push_front(on_clock_change);
    } else {
      apb2_users.remove(on_clock_change);
      apb2_users.push_front(on_clock_change);
    }
  }

  template <class Config>
  static void apply(const Config &config) {
    Logger::info("Applying new clock config\n");
    mmio::RCU.setConfig(config);
    auto ahb_freq = current(AHB{});
    for (const auto &on_clock_change : ahb_users) {
      Logger::debug(
          "onClockChange(AHB %p: %lu)\n",
          reinterpret_cast<const void *>(on_clock_change.callback.arg),
          static_cast<unsigned long>(ahb_freq));
      on_clock_change.callback.func(ahb_freq, on_clock_change.callback.arg);
    }
    auto apb1_freq = current(APB1{});
    for (const auto &on_clock_change : apb1_users) {
      Logger::debug(
          "onClockChange(APB1 %p: %lu)\n",
          reinterpret_cast<const void *>(on_clock_change.callback.arg),
          static_cast<unsigned long>(apb1_freq));
      on_clock_change.callback.func(apb1_freq, on_clock_change.callback.arg);
    }
    auto apb2_freq = current(APB2{});
    for (const auto &on_clock_change : apb2_users) {
      Logger::debug(
          "onClockChange(APB2 %p: %lu)\n",
          reinterpret_cast<const void *>(on_clock_change.callback.arg),
          static_cast<unsigned long>(apb2_freq));
      on_clock_change.callback.func(apb2_freq, on_clock_change.callback.arg);
    }
    auto apb1timer_freq = mmio::RCU.timerFreq(APB1{});
    for (const auto &on_clock_change : apb1timer_users) {
      Logger::debug(
          "onClockChange(APB1 Timer %p: %lu)\n",
          reinterpret_cast<const void *>(on_clock_change.callback.arg),
          static_cast<unsigned long>(apb1timer_freq));
      on_clock_change.callback.func(apb1timer_freq,
                                    on_clock_change.callback.arg);
    }
    auto apb2timer_freq = mmio::RCU.timerFreq(APB2{});
    for (const auto &on_clock_change : apb2timer_users) {
      Logger::debug(
          "onClockChange(APB2 Timer %p: %lu)\n",
          reinterpret_cast<const void *>(on_clock_change.callback.arg),
          static_cast<unsigned long>(apb2timer_freq));
      on_clock_change.callback.func(apb2timer_freq,
                                    on_clock_change.callback.arg);
    }
    Logger::info("New clocks:\n");
    Logger::info("Core = %u, AHB = %u, APB1 = %u, APB2 = %u\n",
                 current(Core{}),
                 ahb_freq,
                 apb1_freq,
                 apb2_freq);
  }

 private:
  static inline ForwardList<OnClockChange> ahb_users{};
  static inline ForwardList<OnClockChange> apb1_users{};
  static inline ForwardList<OnClockChange> apb2_users{};
  static inline ForwardList<OnClockChange> apb1timer_users{};
  static inline ForwardList<OnClockChange> apb2timer_users{};
};
}  // namespace deri::soc
