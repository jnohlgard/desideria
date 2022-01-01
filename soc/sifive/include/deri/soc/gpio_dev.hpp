/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.hpp"
#include "deri/dev/gpio_sifive.hpp"

namespace deri::dev::gpio {

// There is only one single GPIO instance in FE310
enum class Gpio::Port : unsigned {};
}  // namespace deri::dev::gpio

namespace deri::soc {
using GpioManager = dev::gpio::GpioManagerSifive;
using GpioOut = dev::gpio::GpioOutSifive;
using GpioIn = dev::gpio::GpioInSifive;
extern GpioManager gpio;
}  // namespace deri::soc
