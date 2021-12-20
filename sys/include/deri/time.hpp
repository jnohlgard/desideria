/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/bsp/config.hpp"

#include <chrono>
#include <ratio>

namespace deri::sys::time {
template <class Config>
class Timer {
 public:
  using TimerManager = typename Config::TimerManager;
  using Schedulable = typename TimerManager::Schedulable;
  using Callback = typename TimerManager::TimerCallback;

  // Clock required types (https://en.cppreference.com/w/cpp/named_req/Clock)
  using rep = typename TimerManager::Count;
  using period = std::ratio<1, Config::tick_rate_hz>;
  using duration = std::chrono::duration<rep, period>;
  using time_point = std::chrono::time_point<Timer>;
  static const bool is_steady = false;

  static void init();

  static time_point now() { return time_point{duration{timer.read()}}; }
  static void schedule(Schedulable &schedulable) {
    timer.schedule(schedulable);
  }

 private:
  inline static TimerManager timer{};
};
template <class Config>
void Timer<Config>::init() {
  using Frequency = typename TimerManager::Frequency;
  static auto &once = []() -> auto & {
    auto &driver = Config::driver();
    timer = TimerManager{driver, Frequency{Config::tick_rate_hz}};
    driver.setTickRateHz(Config::tick_rate_hz);
    timer.init();
    return driver;
  }
  ();
}

void init();
}  // namespace deri::sys::time

namespace deri {
using SystemTimer = sys::time::Timer<bsp::config::time::SystemTimerConfig>;
using HighResolutionTimer =
    sys::time::Timer<bsp::config::time::HighResolutionTimerConfig>;
using LowPowerTimer = sys::time::Timer<bsp::config::time::LowPowerTimerConfig>;

static_assert(std::chrono::is_clock_v<SystemTimer>);
static_assert(std::chrono::is_clock_v<HighResolutionTimer>);
static_assert(std::chrono::is_clock_v<LowPowerTimer>);
}  // namespace deri
