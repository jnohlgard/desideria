/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once
#include <array>
#include <cstdint>

namespace deri::dev::timer {

template <class TimerDeviceType>
class TimerDriver {
 public:
  using TimerDevice = TimerDeviceType;
  using Count = typename TimerDevice::Count;
  using Channel = typename TimerDevice::Channel;
  static constexpr auto max_value = TimerDevice::max_value;
  static constexpr auto num_channels = TimerDevice::num_channels;

  struct Callback {
    void (*func)(Channel, uintptr_t);
    uintptr_t arg;
  };
  struct PeriodCallback {
    void (*func)(uintptr_t);
    uintptr_t arg;
  };

  explicit TimerDriver(TimerDevice &timer) : timer(timer) {}

  void init() { timer.init(); }

  [[nodiscard]] Count read() const { return timer.read(); }
  void start() { timer.start(); }
  void stop() { timer.stop(); }

  void setPeriod(Count period) { timer.setPeriod(period); }
  void setCompare(Channel channel, Count target) { timer.setCompare(channel, target); }

  void setInterruptHandler(Channel channel, Callback callback);
  void clearInterruptHandler(Channel channel);
  void setPeriodHandler(PeriodCallback callback);
  void clearPeriodHandler();

  void interruptCallback(Channel channel) {
    timer.clearInterruptFlag(channel);
    const auto &callback = callbacks[static_cast<unsigned>(channel)];
    if (callback.func != nullptr) {
      callback.func(channel, callback.arg);
    }
  }

  void periodCallback() {
    timer.clearPeriodFlag();
    if (period_callback.func != nullptr) {
      period_callback.func(period_callback.arg);
    }
  }

  const TimerDevice &underlyingTimer() const { return timer; }
  TimerDevice &underlyingTimer() { return timer; }

 private:
  TimerDevice &timer;
  std::array<Callback, TimerDevice::num_channels> callbacks{};
  PeriodCallback period_callback{};
};
template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::setInterruptHandler(Channel channel,
                                                       Callback callback) {
  timer.disableInterrupt(channel);
  timer.clearInterruptFlag(channel);
  callbacks[static_cast<unsigned>(channel)] = callback;
  timer.enableInterrupt(channel);
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::clearInterruptHandler(Channel channel) {
  timer.disableInterrupt(channel);
  timer.clearInterruptFlag(channel);
  callbacks[static_cast<unsigned>(channel)] = {};
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::setPeriodHandler(PeriodCallback callback) {
  timer.disablePeriodInterrupt();
  timer.clearPeriodFlag();
  period_callback = callback;
  timer.enablePeriodInterrupt();
}

template <class TimerDeviceType>
void TimerDriver<TimerDeviceType>::clearPeriodHandler() {
  timer.disablePeriodInterrupt();
  timer.clearPeriodFlag();
  period_callback = {};
}
}  // namespace deri::dev::timer
