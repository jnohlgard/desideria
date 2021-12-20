/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once
#include "deri/callback.hpp"
#include "deri/irq.hpp"

#include <array>
#include <cstdint>

namespace deri::dev::timer {

template <class TimerDeviceType>
class TimerDriver {
 public:
  using TimerDevice = TimerDeviceType;
  using Count = typename TimerDevice::Count;
  using Channel = typename TimerDevice::Channel;
  using Prescaler = typename TimerDevice::Prescaler;
  static constexpr auto max_value = TimerDevice::max_value;
  static constexpr auto num_channels = TimerDevice::num_channels;

  using Callback = deri::Callback<void(Channel, uintptr_t)>;
  using PeriodCallback = deri::Callback<void(uintptr_t)>;

  explicit TimerDriver(TimerDevice &timer) : timer(&timer) {}
  TimerDriver() = default;
  TimerDriver(const TimerDriver &) = default;
  TimerDriver(TimerDriver &&) noexcept = default;
  TimerDriver &operator=(const TimerDriver &) = default;
  TimerDriver &operator=(TimerDriver &&) noexcept = default;

  void init() { timer->init(); }

  [[nodiscard]] Count read() const { return timer->read(); }
  void start() { timer->start(); }
  void stop() { timer->stop(); }

  void setPrescaler(Prescaler prescaler) { timer->setPrescaler(prescaler); }

  void setPeriod(Count period) { timer->setPeriod(period); }
  void setCompare(Channel channel, Count target) {
    timer->disableInterrupt(channel);
    timer->clearInterruptFlag(channel);
    timer->setCompare(channel, target);
    timer->enableInterrupt(channel);
  }

  void setCompareHandler(Channel channel, Callback callback);
  void clearCompareHandler(Channel channel);
  void setPeriodHandler(PeriodCallback callback);
  void clearPeriodHandler();

  void channelInterrupt(Channel channel) const {
    const auto &callback = channel_callbacks[static_cast<unsigned>(channel)];
    if (callback.func != nullptr) {
      callback.func(channel, callback.arg);
    }
  }

  void periodInterrupt() const {
    if (period_callback.func != nullptr) {
      period_callback.func(period_callback.arg);
    }
  }

  const TimerDevice &underlyingTimer() const { return *timer; }
  TimerDevice &underlyingTimer() { return *timer; }

  void setTickRateHz(unsigned new_tick_rate_hz) {
    tick_rate_hz = new_tick_rate_hz;
    updatePrescaler();
  }

  void updateModuleClock(unsigned new_clock) {
    module_clock = new_clock;
    updatePrescaler();
  }

 private:
  void updatePrescaler() {
    if (tick_rate_hz == 0) {
      return;
    }
    timer->setPrescaler(timer->computePrescaler(module_clock, tick_rate_hz));
  }
  TimerDevice *timer{nullptr};
  std::array<Callback, TimerDevice::num_channels> channel_callbacks{};
  PeriodCallback period_callback{};
  unsigned module_clock{};
  unsigned tick_rate_hz{};
};

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::setCompareHandler(Channel channel,
                                                     Callback callback) {
  arch::CriticalSection cs{};
  channel_callbacks[static_cast<unsigned>(channel)] = callback;
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::clearCompareHandler(Channel channel) {
  arch::CriticalSection cs{};
  timer->disableInterrupt(channel);
  timer->clearInterruptFlag(channel);
  channel_callbacks[static_cast<unsigned>(channel)] = {};
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::setPeriodHandler(PeriodCallback callback) {
  arch::CriticalSection cs{};
  timer->disablePeriodInterrupt();
  timer->clearPeriodFlag();
  period_callback = callback;
  timer->enablePeriodInterrupt();
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::clearPeriodHandler() {
  arch::CriticalSection cs{};
  timer->disablePeriodInterrupt();
  timer->clearPeriodFlag();
  period_callback = {};
}
}  // namespace deri::dev::timer
