/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/log.hpp"
#include "deri/mmio/MTIME.hpp"

#include <cstdint>
#include <limits>
#include <type_traits>

namespace deri::log {
struct TimerRiscv;
}  // namespace deri::log

namespace deri::dev::timer {

class TimerRiscv {
  using Logger = log::Logger<log::TimerRiscv>;

 public:
  enum class Count : int64_t {};
  static constexpr int64_t max_value =
      std::numeric_limits<std::underlying_type_t<Count>>::max();
  static constexpr unsigned num_channels = 1;

  enum class Channel {};
  enum class Prescaler {};

  using Period = mmio::MTIME64_bits;

  void init() {
    // Always running
    Logger::debug("TimerRiscv::init\n");
  }
  void start() {
    // Always running
    Logger::debug("TimerRiscv::start\n");
  }
  void stop() {
    // Always running
    Logger::debug("TimerRiscv::stop\n");
  }

  void setPeriod(Count) {
    // Not possible
    Logger::warning("TimerRiscv::setPeriod not possible\n");
  }

  void setPrescaler(Prescaler) {
    // Not possible
    Logger::warning("TimerRiscv::setPrescaler not possible\n");
  }

  Prescaler computePrescaler(unsigned module_clock, unsigned tick_rate_hz) {
    return {};
  }

  /**
   * Read the current hardware counter value
   * @return Current count
   */
  [[nodiscard]] Count read() const;

  /**
   * Set the compare value for the given channel
   *
   * @param channel channel to configure
   * @param target value to compare
   */
  void setCompare(Channel, Count target);

  void disableInterrupt(Channel);

  void enableInterrupt(Channel);

  void clearInterruptFlag(Channel) {
    // Cleared by writing a new compare target
  }
};
void HasArithmeticOperators(TimerRiscv::Count);

}  // namespace deri::dev::timer
