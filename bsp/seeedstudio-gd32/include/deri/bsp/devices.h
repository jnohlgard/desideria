/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio_gd32.h"
#include "deri/dev/uart_gd32.h"
#include "deri/soc/gpio_dev.h"

namespace deri::bsp {
extern deri::dev::uart::UsartGd32 uart0;

inline constexpr dev::gpio::Gpio led0{dev::gpio::Gpio::Port::B, 5};
inline constexpr dev::gpio::Gpio led1{dev::gpio::Gpio::Port::B, 0};
inline constexpr dev::gpio::Gpio led2{dev::gpio::Gpio::Port::B, 1};

inline constexpr dev::gpio::Gpio button0{dev::gpio::Gpio::Port::A, 0};
inline constexpr dev::gpio::Gpio button1{dev::gpio::Gpio::Port::C, 13};
}  // namespace deri::bsp
