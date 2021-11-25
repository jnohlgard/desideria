/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio_gd32.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/soc/timer_dev.hpp"
#include "deri/dev/timer_manager.hpp"
#include "deri/dev/timer.hpp"
#include "deri/dev/timer_gd32.hpp"

#include <array>
#include <cstdint>

namespace deri::bsp::config {
using Port = dev::gpio::Gpio::Port;
using Polarity = dev::gpio::GpioOutConfig::Polarity;
using Pull = dev::gpio::GpioInConfig::PullConfig;
inline constexpr std::array leds{
    dev::gpio::GpioOutConfig{.gpio = {config::Port::B, 5},
                             .polarity = config::Polarity::INVERTED},
    dev::gpio::GpioOutConfig{.gpio = {config::Port::B, 0},
                             .polarity = config::Polarity::INVERTED},
    dev::gpio::GpioOutConfig{.gpio = {config::Port::B, 1},
                             .polarity = config::Polarity::INVERTED},
};

inline constexpr std::array buttons{
    dev::gpio::GpioInConfig{{config::Port::A, 0}, config::Pull::FLOATING},
    dev::gpio::GpioInConfig{{config::Port::C, 13}, config::Pull::FLOATING},
};

struct TimerManagerConfig {
  using TimerManager = dev::TimerManager<dev::timer::TimerDriver<dev::timer::TimerGd32>>;
  const soc::TimerConfig& config;
  uint32_t tick_rate_hz;
};
inline constexpr TimerManagerConfig utime {
    .config = soc::timer_config[4],
    .tick_rate_hz = 1'000'000,
};

}  // namespace deri::bsp::config
