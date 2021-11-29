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

  void interruptCallback(Channel channel) const {
    const auto &callback = callbacks[static_cast<unsigned>(channel)];
    if (callback.func != nullptr) {
      callback.func(channel, callback.arg);
    }
  }

  void periodCallback() const {
    if (period_callback.func != nullptr) {
      period_callback.func(period_callback.arg);
    }
  }

  const TimerDevice &underlyingTimer() const { return *timer; }
  TimerDevice &underlyingTimer() { return *timer; }

 private:
  TimerDevice *timer{nullptr};
  std::array<Callback, TimerDevice::num_channels> callbacks{};
  PeriodCallback period_callback{};
};

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::setCompareHandler(Channel channel,
                                                     Callback callback) {
  arch::CriticalSection cs;
  callbacks[static_cast<unsigned>(channel)] = callback;
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::clearCompareHandler(Channel channel) {
  timer->disableInterrupt(channel);
  timer->clearInterruptFlag(channel);
  callbacks[static_cast<unsigned>(channel)] = {};
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::setPeriodHandler(PeriodCallback callback) {
  timer->disablePeriodInterrupt();
  timer->clearPeriodFlag();
  period_callback = callback;
  timer->enablePeriodInterrupt();
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::clearPeriodHandler() {
  timer->disablePeriodInterrupt();
  timer->clearPeriodFlag();
  period_callback = {};
}
}  // namespace deri::dev::timer
