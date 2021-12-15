/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio_gd32.hpp"
#include "deri/dev/timer.hpp"
#include "deri/dev/timer_gd32.hpp"
#include "deri/dev/timer_manager.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/soc/timer_dev.hpp"

#include <array>
#include <cstdint>

namespace deri::bsp::config {
using Port = dev::gpio::Gpio::Port;
using Polarity = dev::gpio::GpioOutConfig::Polarity;
using Pull = dev::gpio::GpioInConfig::PullConfig;
inline constexpr std::array leds{
    dev::gpio::GpioOutConfig{.gpio = {config::Port::A, 1},
                             .polarity = config::Polarity::INVERTED},
    dev::gpio::GpioOutConfig{.gpio = {config::Port::A, 2},
                             .polarity = config::Polarity::INVERTED},
    dev::gpio::GpioOutConfig{.gpio = {config::Port::C, 13},
                             .polarity = config::Polarity::INVERTED},
};

inline constexpr std::array buttons{
    dev::gpio::GpioInConfig{{config::Port::A, 0}, config::Pull::FLOATING},
};

inline constexpr dev::gpio::Gpio console_pin{dev::gpio::Gpio::Port::A, 9};

namespace time {

struct UsecTimerConfig {
  using TimerManager = dev::TimerManager<dev::timer::TimerGd32>;
  static constexpr uint32_t tick_rate_hz = 1'000'000;
  static constexpr soc::TimerConfig driver_config = soc::timer_config[4];
};

using SystemTimerConfig = UsecTimerConfig;
using HighResolutionTimerConfig = UsecTimerConfig;
using LowPowerTimerConfig = UsecTimerConfig;
}  // namespace time
}  // namespace deri::bsp::config
