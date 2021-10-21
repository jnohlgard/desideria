/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio_gd32.h"
#include "deri/dev/uart_gd32.h"

namespace deri::bsp {
extern deri::dev::uart::UsartGd32 uart0;
extern deri::dev::gpio::GpioGd32 gpioa;
extern deri::dev::gpio::GpioGd32 gpiob;
extern deri::dev::gpio::GpioGd32 gpioc;
extern deri::dev::gpio::GpioGd32 gpiod;
extern deri::dev::gpio::GpioGd32 gpioe;
}  // namespace deri::bsp
