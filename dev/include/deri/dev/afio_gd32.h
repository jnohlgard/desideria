/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.h"
#include "deri/mmio/AFIO.hpp"

namespace deri::dev::gpio {
class AfioGd32 {
 public:
  using ExtiSource = Gpio::Port;
  void init();

  void setExtiSource(Gpio::Pin pin, ExtiSource source);

 private:
  mmio::AFIO_regs AFIO;
};

static_assert(sizeof(AfioGd32) == sizeof(mmio::AFIO_regs));
}  // namespace deri::dev::gpio
