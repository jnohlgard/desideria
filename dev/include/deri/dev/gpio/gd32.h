/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/GPIO.hpp"

namespace deri::dev::gpio {

class GpioGd32 : protected mmio::GPIO_regs {
 public:
  enum class DigitalIn {
    FLOATING,
    PULL_UP,
    PULL_DOWN,
  };

  enum class DigitalOutMode {
    PUSH_PULL,
    OPEN_DRAIN,
  };
  enum class DigitalOutSpeed {
    D10MHZ,
    D2MHZ,
    D50MHZ,
  };

  /// Pin number within the port, i.e. y in Pxy
  enum class PinNum : int;

  void initAnalog(PinNum pin);
  void initInput(PinNum pin, DigitalIn mode = DigitalIn::FLOATING);
  void initOutGpio(PinNum pin,
                   DigitalOutMode mode = DigitalOutMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);
  void initOutAfio(PinNum pin,
                   DigitalOutMode mode = DigitalOutMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);

 private:
  void writeCTLReg(PinNum pin, CTL_bits bits);
};
}  // namespace deri::dev::gpio
