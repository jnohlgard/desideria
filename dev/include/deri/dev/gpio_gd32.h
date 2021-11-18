/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.h"
#include "deri/mmio/AFIO.hpp"
#include "deri/mmio/GPIO.hpp"
#include "deri/mmio/bits/GPIO_bits.hpp"

#include <functional>

namespace deri::dev::gpio {

class GpioGd32 : private mmio::GPIO_regs {
 public:
  using Pin = Gpio::Pin;

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

  void initAnalog(Pin pin);
  void initInput(Pin pin, DigitalIn mode = DigitalIn::FLOATING);
  void initOutGpio(Pin pin,
                   DigitalOutMode mode = DigitalOutMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);
  void initOutAfio(Pin pin,
                   DigitalOutMode mode = DigitalOutMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);

  void set(Pin pin) {
    BOP.store(static_cast<BOP_bits>(1u << static_cast<unsigned>(pin)));
  }
  void clear(Pin pin) {
    BC.store(static_cast<BC_bits>(1u << static_cast<unsigned>(pin)));
  }
  void set(BOP_bits pins) { BOP.store(pins); }
  void clear(BC_bits pins) { BC.store(pins); }

  bool read(Pin pin) {
    return !!(ISTAT.load() &
              static_cast<ISTAT_bits>(1u << static_cast<unsigned>(pin)));
  }

 private:
  void writeCTLReg(Pin pin, CTL_bits bits);
};

class GpioManagerGd32 {
 public:
  using DigitalIn = GpioGd32::DigitalIn;
  using DigitalOutMode = GpioGd32::DigitalOutMode;
  using DigitalOutSpeed = GpioGd32::DigitalOutSpeed;
  struct Callback {
    void (*func)(uintptr_t);
    uintptr_t arg;
  };

  enum class Edge {
    RISING = 1 << 0,
    FALLING = 1 << 1,
  };

  void enableModule(Gpio::Port port);
  void initAnalog(Gpio gpio);
  void initInput(Gpio gpio, DigitalIn mode = DigitalIn::FLOATING);
  void initOutGpio(Gpio gpio,
                   DigitalOutMode mode = DigitalOutMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);
  void initOutAfio(Gpio gpio,
                   DigitalOutMode mode = DigitalOutMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);
  void setInterruptHandler(Gpio gpio, Edge edge, Callback callback);
  void clearInterruptHandler(Gpio gpio);
  void enableInterrupt(Gpio gpio);
  void disableInterrupt(Gpio gpio);

  void interruptCallback(unsigned line) {
    const auto &callback = callbacks[line];
    callback.func(callback.arg);
  }

 private:
  std::array<Callback, 18> callbacks{};
};
void HasBitwiseOperators(GpioManagerGd32::Edge);

}  // namespace deri::dev::gpio
