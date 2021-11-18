/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.h"
#include "deri/mmio/AFIO.hpp"

namespace deri::dev::gpio {
class AfioGd32 : private mmio::AFIO_regs {
 public:
  using ExtiSource = Gpio::Port;
  void init();

  void setExtiSource(Gpio::Pin pin, ExtiSource source);
};
}  // namespace deri::dev::gpio
