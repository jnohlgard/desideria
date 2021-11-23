/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

template <class TimerDriverType>
class TimerManager {
 public:
  using TimerDriver = TimerDriverType;
  enum class Frequency : unsigned long;
  static constexpr auto num_channels = TimerDriver::num_channels;

  explicit TimerManager(TimerDriver &timer) : timer(timer) {}

 private:
  TimerDriver timer;
  Frequency tick_rate_hz;
};
