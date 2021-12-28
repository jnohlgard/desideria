/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/MTIME.hpp"

#include <cstdint>
#include <limits>
#include <type_traits>

namespace deri::dev::timer {

class TimerRiscv {
 public:
  enum class Count : int64_t {};
  static constexpr int64_t max_value =
      std::numeric_limits<std::underlying_type_t<Count>>::max();
  static constexpr unsigned num_channels = 1;

  enum class Channel {};
  enum class Prescaler {};

  using Period = mmio::MTIME_bits;
  using Target = mmio::MTIME_bits;

  void init() {
    // Always running
  }
  void start() {
    // Always running
  }
  void stop() {
    // Always running
  }

  void setPeriod(Count) {
    // Not possible
  }

  void setPrescaler(Prescaler) {
    // Not possible
  }

  Prescaler computePrescaler(unsigned module_clock, unsigned tick_rate_hz) {
    return {};
  }

  /**
   * Read the current hardware counter value
   * @return Current count
   */
  [[nodiscard]] Count read() const {
    return static_cast<Count>(mmio::mtime.load());
  }

  /**
   * Set the compare value for the given channel
   *
   * @param channel channel to configure
   * @param target value to compare
   */
  void setCompare(Channel, Count target) {
    mmio::mtimecmp.store(Target{target});
  }

  void disableInterrupt(Channel);

  void enableInterrupt(Channel);

  void clearInterruptFlag(Channel) {
    // Cleared by writing a new compare target
  }
};
void HasArithmeticOperators(TimerRiscv::Count);

}  // namespace deri::dev::timer
