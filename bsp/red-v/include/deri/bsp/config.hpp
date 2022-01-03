/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.hpp"
#include "deri/dev/timer.hpp"
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
    // This LED shares pin with SPI1 SCK
    dev::gpio::GpioOutConfig{.gpio = {{}, 5},
                             .polarity = config::Polarity::POSITIVE},
};

inline constexpr std::array<dev::gpio::GpioInConfig, 0> buttons{};

inline constexpr dev::gpio::Gpio console_tx_pin{{}, 17};
inline constexpr std::optional<dev::gpio::Gpio> console_rx_pin{{{}, 16}};

inline constexpr auto clock = soc::Clock::HfxoscConfig{};
//    soc::Clock::PllConfig{soc::Clock::PllConfig::PllFactors{
//        .div_R = 2, .mult_F = 80, .div_Q = 2, .div_final = 1}};

namespace time {

struct MtimeTimerConfig {
  using TimerManager = dev::TimerManager<dev::timer::TimerRiscv>;
  static constexpr uint32_t tick_rate_hz = 32768;
  static auto &driver() { return soc::mtime(); };
};

using SystemTimerConfig = MtimeTimerConfig;
using HighResolutionTimerConfig = MtimeTimerConfig;
using LowPowerTimerConfig = MtimeTimerConfig;
}  // namespace time
}  // namespace deri::bsp::config
