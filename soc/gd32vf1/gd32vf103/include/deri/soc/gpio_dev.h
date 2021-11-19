/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.h"
#include "deri/dev/gpio_gd32.h"
#include "deri/dev/exti_gd32.h"
#include "deri/mmio/RCU.hpp"

namespace deri::dev::gpio {

class AfioGd32;
class ExtiGd32;
class GpioPortGd32;
class GpioManagerGd32;

enum class Gpio::Port : unsigned {
  A = 0,
  B,
  C,
  D,
  E,
};

}  // namespace deri::dev::gpio

namespace deri::soc {

extern dev::gpio::GpioPortGd32 gpioa;
extern dev::gpio::GpioPortGd32 gpiob;
extern dev::gpio::GpioPortGd32 gpioc;
extern dev::gpio::GpioPortGd32 gpiod;
extern dev::gpio::GpioPortGd32 gpioe;
extern dev::gpio::AfioGd32 afio;
extern dev::gpio::ExtiGd32 exti;
extern dev::gpio::GpioManagerGd32 gpio;

dev::gpio::GpioPortGd32 &gpioPortDev(dev::gpio::Gpio::Port port);

inline dev::gpio::GpioPortGd32 &gpioPortDev(dev::gpio::Gpio gpio) {
  return gpioPortDev(gpio.port);
}

mmio::RCU_regs::APB2EN_bits gpioPortClockEnableBits(dev::gpio::Gpio::Port port);

}  // namespace deri::soc
