/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/callback.h"
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

  using PullConfig = GpioInConfig::PullConfig;

  using OutputMode = GpioOutConfig::OutputMode;
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

struct GpioOutGd32 {
  using Polarity = GpioOutConfig::Polarity;
  using Pin = GpioPortGd32::Pin;

  GpioOutGd32(GpioPortGd32 &port,
              Pin pin,
              Polarity polarity = Polarity::POSITIVE)
      : port(&port), pin(pin), polarity(polarity) {}

  GpioOutGd32() = default;
  GpioOutGd32(const GpioOutGd32 &) = default;
  GpioOutGd32 &operator=(const GpioOutGd32 &) = default;

  void set() {
    switch (polarity) {
      case Polarity::POSITIVE:
        port->set(pin);
        break;
      case Polarity::INVERTED:
        port->clear(pin);
        break;
    }
  }

  void clear() {
    switch (polarity) {
      case Polarity::POSITIVE:
        port->clear(pin);
        break;
      case Polarity::INVERTED:
        port->set(pin);
        break;
    }
  }

  void write(bool value) {
    if (value) {
      set();
    } else {
      clear();
    }
  }

  void toggle() {
    bool value = read();
    write(!value);
  }

  [[nodiscard]] bool read() const { return port->read(pin); }

  GpioPortGd32 *port{nullptr};
  Pin pin{};
  Polarity polarity{};
};

struct GpioInGd32 {
  using Pin = GpioPortGd32::Pin;

  [[nodiscard]] bool read() const { return port.read(pin); }

  GpioPortGd32 &port;
  Pin pin;
};

class GpioManagerGd32 {
 public:
  using PullConfig = GpioInConfig::PullConfig;
  using OutputMode = GpioOutConfig::OutputMode;
  using DigitalOutSpeed = GpioPortGd32::DigitalOutSpeed;
  enum class Edge {
    RISING = 1 << 0,
    FALLING = 1 << 1,
  };

  using Callback = deri::Callback<void(uintptr_t)>;
  void initAnalog(Gpio gpio);

  GpioInGd32 initInput(Gpio gpio, PullConfig pull = PullConfig::FLOATING);

  GpioInGd32 initInput(GpioInConfig config) {
    return initInput(config.gpio, config.pull);
  }

  GpioOutGd32 initOutGpio(Gpio gpio,
                          OutputMode mode = OutputMode::PUSH_PULL,
                          DigitalOutSpeed speed = DigitalOutSpeed::D2MHZ);

  GpioOutGd32 initOutGpio(GpioOutConfig config);

  void initOutAfio(Gpio gpio,
                   OutputMode mode = OutputMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);
  void setInterruptHandler(Gpio gpio, Edge edge, Callback callback);
  void clearInterruptHandler(Gpio gpio);
  static void enableInterrupt(Gpio gpio);
  static void disableInterrupt(Gpio gpio);

  void interruptCallback(unsigned line) const {
    const auto &callback = callbacks[line];
    if (callback.func != nullptr) {
      callback.func(callback.arg);
    }
  }

 private:
  std::array<Callback, 19> callbacks{};
};
void HasBitwiseOperators(GpioManagerGd32::Edge);

}  // namespace deri::dev::gpio
