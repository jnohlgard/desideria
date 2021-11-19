/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio_gd32.h"
#include "deri/soc/gpio_dev.h"

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

}  // namespace deri::bsp::config
