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

  // Clock required types (https://en.cppreference.com/w/cpp/named_req/Clock)
  using rep = typename TimerManager::Count;
  using period = std::ratio<1, Config::tick_rate_hz>;
  using duration = std::chrono::duration<rep, period>;
  using time_point = std::chrono::time_point<Timer<Config>>;
  static const bool is_steady = false;

  static void init();

  static time_point now() { return time_point{duration{timer.read()}}; }

 private:
  inline static TimerManager timer{};
};
template <class Config>
void Timer<Config>::init() {
  using Frequency = typename TimerManager::Frequency;
  auto &&driver_config = Config::driver_config;
  timer = TimerManager{driver_config.init(), Frequency{Config::tick_rate_hz}};
  auto prescaler = Config::TimerManager::TimerDevice::computePrescaler(
      driver_config.module_clock(), Config::tick_rate_hz);
  driver_config.dev.setPrescaler(prescaler);
  timer.init();
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
