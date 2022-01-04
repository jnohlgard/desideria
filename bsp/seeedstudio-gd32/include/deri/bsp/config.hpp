/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.hpp"
#include "deri/dev/gpio_gd32.hpp"
#include "deri/dev/timer.hpp"
#include "deri/dev/timer_gd32.hpp"
#include "deri/dev/timer_manager.hpp"
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/soc/timer_dev.hpp"

#include <array>
#include <cstdint>
#include <optional>

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

inline constexpr dev::gpio::Gpio console_tx_pin{dev::gpio::Gpio::Port::A, 9};
inline constexpr std::optional<dev::gpio::Gpio> console_rx_pin{
    {dev::gpio::Gpio::Port::A, 10}};

inline constexpr auto clock = soc::Clock::HxtalConfig{};

namespace time {

struct UsecTimerConfig {
  using TimerManager = dev::TimerManager<dev::timer::TimerGd32>;
  static constexpr uint32_t tick_rate_hz = 1'000'000;
  static auto &driver() { return soc::timer<4>(); };
};
struct MtimeTimerConfig {
  using TimerManager = dev::TimerManager<dev::timer::TimerRiscv>;
  static constexpr uint32_t tick_rate_hz = 2'000'000;
  static auto &driver() { return soc::mtime(); };
};

using SystemTimerConfig = UsecTimerConfig;
using HighResolutionTimerConfig = UsecTimerConfig;
using LowPowerTimerConfig = MtimeTimerConfig;
}  // namespace time
}  // namespace deri::bsp::config
