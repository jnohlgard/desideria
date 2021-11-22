/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/TIMER.hpp"
#include "deri/mmio/bits/TIMER_bits.hpp"

#include <chrono>

namespace deri::dev::timer {

class TimerGd32 {
 public:
  static constexpr unsigned max_value = 0xffffu;
  static constexpr unsigned num_channels = 4;

  enum class ClockSource {
    CK_TIMER,
    ITI0,
    ITI1,
    ITI2,
    ITI3,
    EXTERNAL_TRIGGER,
  };

  enum class Channel {
    CH0 = 0,
    CH1,
    CH2,
    CH3,
  };

  enum class Count : uint16_t {};
  using Period = mmio::TIMER_regs::CAR_bits;
  using Target = mmio::TIMER_regs::CHxCV_bits;
  using Prescaler = mmio::TIMER_regs::PSC_bits;

  void init();

  void setSource(ClockSource source);

  /**
   * Set clock prescaler division factor
   *
   * The module clock is divided by (prescaler+1) to generate the counter clock.
   *
   * @param prescaler Prescaler value of the counter clock
   */
  void setPrescaler(Prescaler prescaler) { TIMER.PSC.store(prescaler); }

  /**
   * Start the timer
   */
  void start() { TIMER.CTL0 |= mmio::TIMER_regs::CTL0_bits::CEN; }
  /**
   * Stop the timer
   */
  void stop() { TIMER.CTL0 &= ~(mmio::TIMER_regs::CTL0_bits::CEN); }

  /**
   * Read the current hardware counter value
   * @return Current count
   */
  [[nodiscard]] Count read() const {
    return static_cast<Count>(TIMER.CNT.load());
  }

  /**
   * Set the period of the timer.
   *
   * When the counter increments when count = period, the count will reset back
   * to 0 The length of a whole period is (max_count+1) ticks
   *
   * @param period
   */
  void setPeriod(Count max_count) {
    TIMER.CAR.store(Period{max_count});
    // When writing the CAR register all INTF flags may become set.
    TIMER.INTF.store(mmio::TIMER_regs::INTF_bits{0});
  }

  /**
   * Set the compare value for the given channel
   *
   * @param channel channel to configure
   * @param target value to compare
   */
  void setCompare(Channel channel, Count target) {
    TIMER.CHxCV[static_cast<unsigned>(channel)].store(Target{target});
  }

  void disableInterrupt(Channel channel) {
    TIMER.DMAINTEN &= ~channelInterruptEnableBit(channel);
  }

  void enableInterrupt(Channel channel) {
    TIMER.DMAINTEN |= channelInterruptEnableBit(channel);
  }

  void clearInterruptFlag(Channel channel) {
    // INTF is write 0 to clear
    TIMER.INTF.store(~channelInterruptFlagBit(channel));
  }
  [[nodiscard]] auto interruptFlag() const { return TIMER.INTF.load(); }

  void disablePeriodInterrupt() {
    TIMER.DMAINTEN &= ~mmio::TIMER_regs::DMAINTEN_bits::UPIE;
  }

  void enablePeriodInterrupt() {
    TIMER.DMAINTEN |= mmio::TIMER_regs::DMAINTEN_bits::UPIE;
  }

  void clearPeriodFlag() {
    // INTF is write 0 to clear
    TIMER.INTF.store(~mmio::TIMER_regs::INTF_bits::UPIF);
  }

 private:
  static constexpr mmio::TIMER_regs::DMAINTEN_bits channelInterruptEnableBit(
      Channel channel) {
    using DMAINTEN_bits = mmio::TIMER_regs::DMAINTEN_bits;
    return static_cast<DMAINTEN_bits>(
        static_cast<std::underlying_type_t<DMAINTEN_bits>>(DMAINTEN_bits::CH0IE)
        << static_cast<unsigned>(channel));
  }
  static constexpr mmio::TIMER_regs::INTF_bits channelInterruptFlagBit(
      Channel channel) {
    using INTF_bits = mmio::TIMER_regs::INTF_bits;
    return static_cast<INTF_bits>(
        static_cast<std::underlying_type_t<INTF_bits>>(INTF_bits::CH0IF)
        << static_cast<unsigned>(channel));
  }

  mmio::TIMER_regs TIMER;
};
void HasArithmeticOperators(TimerGd32::Count);

static_assert(sizeof(TimerGd32) == sizeof(mmio::TIMER_regs));

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
  void setCompare(Channel channel, Count target) { timer.setCompare(target); }

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
