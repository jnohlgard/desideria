/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.hpp"
#include "deri/dev/gpio_gd32.hpp"
#include "deri/dev/exti_gd32.hpp"
#include "deri/dev/afio_gd32.hpp"
#include "deri/mmio/RCU.hpp"

namespace deri::dev::gpio {

enum class Gpio::Port : unsigned {
  A = 0,
  B,
  C,
  D,
  E,
};

}  // namespace deri::dev::gpio

namespace deri::mmio {
extern dev::gpio::AfioGd32 AFIO;
extern dev::gpio::ExtiGd32 EXTI;
extern dev::gpio::GpioPortGd32 GPIOA;
extern dev::gpio::GpioPortGd32 GPIOB;
extern dev::gpio::GpioPortGd32 GPIOC;
extern dev::gpio::GpioPortGd32 GPIOD;
extern dev::gpio::GpioPortGd32 GPIOE;
}  // namespace deri::mmio

namespace deri::soc {

using GpioManager = dev::gpio::GpioManagerGd32;
using GpioOut = dev::gpio::GpioOutGd32;
using GpioIn = dev::gpio::GpioInGd32;
extern GpioManager gpio;

dev::gpio::GpioPortGd32 &gpioPortDev(dev::gpio::Gpio::Port port);

inline dev::gpio::GpioPortGd32 &gpioPortDev(dev::gpio::Gpio gpio) {
  return gpioPortDev(gpio.port);
}

mmio::RCU_regs::APB2EN_bits gpioPortClockEnableBits(dev::gpio::Gpio::Port port);

}  // namespace deri::soc
