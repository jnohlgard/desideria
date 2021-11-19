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

class GpioPortGd32 {
 public:
  using Pin = Gpio::Pin;
  using BOP_bits = mmio::GPIO_regs::BOP_bits;
  using BC_bits = mmio::GPIO_regs::BC_bits;

  using PullConfig = GpioIn::PullConfig;

  using OutputMode = GpioOut::OutputMode;
  enum class DigitalOutSpeed {
    D10MHZ,
    D2MHZ,
    D50MHZ,
  };

  void initAnalog(Pin pin);
  void initInput(Pin pin, PullConfig pull = PullConfig::FLOATING);
  void initOutGpio(Pin pin,
                   OutputMode mode = OutputMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);
  void initOutAfio(Pin pin,
                   OutputMode mode = OutputMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);

  void set(Pin pin) {
    GPIO.BOP.store(static_cast<BOP_bits>(1u << static_cast<unsigned>(pin)));
  }
  void clear(Pin pin) {
    GPIO.BC.store(static_cast<BC_bits>(1u << static_cast<unsigned>(pin)));
  }
  void set(BOP_bits pins) { GPIO.BOP.store(pins); }
  void clear(BC_bits pins) { GPIO.BC.store(pins); }

  [[nodiscard]] bool read(Pin pin) const {
    return !!(GPIO.ISTAT.load() & static_cast<mmio::GPIO_regs::ISTAT_bits>(
                                      1u << static_cast<unsigned>(pin)));
  }

 private:
  using CTL_bits = mmio::GPIO_regs::CTL_bits;
  void writeCTLReg(Pin pin, CTL_bits bits);

  mmio::GPIO_regs GPIO;
};

class GpioManagerGd32 {
 public:
  using PullConfig = GpioIn::PullConfig;
  using OutputMode = GpioOut::OutputMode;
  using DigitalOutSpeed = GpioPortGd32::DigitalOutSpeed;
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

  void initInput(Gpio gpio, PullConfig pull = PullConfig::FLOATING);

  void initInput(GpioIn config) { initInput(config.gpio, config.pull); }

  void initOutGpio(Gpio gpio,
                   OutputMode mode = OutputMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D2MHZ);

  void initOutGpio(GpioOut config) { initOutGpio(config.gpio, config.mode); }

  void initOutAfio(Gpio gpio,
                   OutputMode mode = OutputMode::PUSH_PULL,
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
