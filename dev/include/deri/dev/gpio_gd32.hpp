/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/gpio.hpp"
#include "deri/function.hpp"
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

  [[nodiscard]] bool read() const {
    auto value = port->read(pin);
    if (polarity == Polarity::INVERTED) {
      return !value;
    }
    return value;
  }

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
  using Trigger = GpioInConfig::Trigger;

  using Callback = deri::Function<void()>;
  void initAnalog(Gpio gpio);

  GpioInGd32 initInput(Gpio gpio, PullConfig pull = PullConfig::FLOATING);

  GpioInGd32 initInput(const GpioInConfig &config) {
    return initInput(config.gpio, config.pull);
  }

  GpioOutGd32 initOutGpio(Gpio gpio,
                          OutputMode mode = OutputMode::PUSH_PULL,
                          DigitalOutSpeed speed = DigitalOutSpeed::D2MHZ);

  GpioOutGd32 initOutGpio(const GpioOutConfig &config) {
    auto gpio_out = initOutGpio(config.gpio, config.mode);
    gpio_out.polarity = config.polarity;
    return gpio_out;
  }

  void initOutAfio(Gpio gpio,
                   OutputMode mode = OutputMode::PUSH_PULL,
                   DigitalOutSpeed speed = DigitalOutSpeed::D10MHZ);
  void setInterruptHandler(Gpio gpio, Trigger edge, Callback callback);
  void clearInterruptHandler(Gpio gpio);
  static void enableInterrupt(Gpio gpio);
  static void disableInterrupt(Gpio gpio);

  void interrupt(unsigned line) const {
    const auto &callback = callbacks[line];
    if (callback) {
      callback();
    }
  }

 private:
  std::array<Callback, 19> callbacks{};
};
void HasBitwiseOperators(GpioManagerGd32::Trigger);

}  // namespace deri::dev::gpio
