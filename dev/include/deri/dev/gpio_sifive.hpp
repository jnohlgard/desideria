/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/callback.hpp"
#include "deri/dev/gpio.hpp"
#include "deri/mmio/GPIO.hpp"
#include "deri/mmio/bits/GPIO_bits.hpp"

#include <functional>

namespace deri::dev::gpio {

class GpioPortSifive {
 public:
  using Pin = Gpio::Pin;

  using PullConfig = GpioInConfig::PullConfig;

  using Polarity = GpioOutConfig::Polarity;
  enum class DriveStrength {
    LOW,
    HIGH,
  };
  enum class Iof {
    IOF0,
    IOF1,
  };

  using output_val_bits = mmio::GPIO_regs::output_val_bits;

  void initInGpio(Pin pin, PullConfig pull = PullConfig::FLOATING);
  void initInIof(Pin pin,
                 PullConfig pull = PullConfig::FLOATING,
                 Iof = Iof::IOF0);
  void initOutGpio(Pin pin,
                   Polarity polarity = Polarity::POSITIVE,
                   DriveStrength strength = DriveStrength::LOW);
  void initOutIof(Pin pin,
                  Polarity polarity = Polarity::POSITIVE,
                  DriveStrength strength = DriveStrength::LOW,
                  Iof = Iof::IOF0);

  void set(Pin pin) { set(output_val_bits{1u << static_cast<unsigned>(pin)}); }
  void clear(Pin pin) {
    clear(output_val_bits{1u << static_cast<unsigned>(pin)});
  }
  void set(output_val_bits pins) { GPIO.output_val |= pins; }
  void clear(output_val_bits pins) { GPIO.output_val &= ~pins; }

  [[nodiscard]] bool read(Pin pin) const {
    using input_val_bits = mmio::GPIO_regs::input_val_bits;
    return !!(GPIO.input_val.load() &
              input_val_bits{1u << static_cast<unsigned>(pin)});
  }

 private:
  void initIof(Pin, Iof);
  mmio::GPIO_regs GPIO;
};

struct GpioOutSifive {
  using Polarity = GpioPortSifive::Polarity;
  using Pin = GpioPortSifive::Pin;

  GpioOutSifive(GpioPortSifive &port, Pin pin, Polarity polarity)
      : port(&port), pin(pin), polarity(polarity) {}

  GpioOutSifive() = default;
  GpioOutSifive(const GpioOutSifive &) = default;
  GpioOutSifive &operator=(const GpioOutSifive &) = default;

  void set() { port->set(pin); }

  void clear() { port->clear(pin); }

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

  GpioPortSifive *port{nullptr};
  Pin pin{};
  Polarity polarity{};
};

struct GpioInSifive {
  using Pin = GpioPortSifive::Pin;

  [[nodiscard]] bool read() const { return port.read(pin); }

  GpioPortSifive &port;
  Pin pin;
};

class GpioManagerSifive {
 public:
  using PullConfig = GpioInConfig::PullConfig;
  using Polarity = GpioOutConfig::Polarity;
  using DriveStrength = GpioPortSifive::DriveStrength;
  using Iof = GpioPortSifive::Iof;
  enum class Trigger {
    RISING = (1 << 0),
    FALLING = (1 << 1),
    HIGH = (1 << 2),
    LOW = (1 << 3),
  };

  using Callback = deri::Callback<void(uintptr_t)>;

  static constexpr unsigned num_gpios = 24;

  GpioInSifive initInGpio(Gpio gpio, PullConfig pull = PullConfig::FLOATING);

  GpioInSifive initInGpio(const GpioInConfig &config) {
    return initInGpio(config.gpio, config.pull);
  }
  GpioOutSifive initOutGpio(Gpio gpio,
                            Polarity polarity = Polarity::POSITIVE,
                            DriveStrength strength = DriveStrength::LOW);

  GpioOutSifive initOutGpio(const GpioOutConfig &config) {
    auto gpio_out = initOutGpio(config.gpio, config.polarity);
    gpio_out.polarity = config.polarity;
    return gpio_out;
  }

  void initInIof(Gpio gpio,
                 PullConfig pull = PullConfig::FLOATING,
                 Iof = Iof::IOF0);

  void initInIof(const GpioInConfig &config) {
    initInIof(config.gpio, config.pull);
  }

  void initOutIof(Gpio gpio,
                  Polarity polarity = Polarity::POSITIVE,
                  DriveStrength strength = DriveStrength::LOW,
                  Iof = Iof::IOF0);

  void setInterruptHandler(Gpio gpio, Trigger triggers, Callback callback);
  void clearInterruptHandler(Gpio gpio);
  static void enableInterrupt(Gpio gpio);
  static void disableInterrupt(Gpio gpio);

  void interrupt(unsigned line) const {
    const auto &callback = callbacks[line];
    if (callback.func != nullptr) {
      callback.func(callback.arg);
    }
  }

 private:
  std::array<Callback, num_gpios> callbacks{};
};
void HasBitwiseOperators(GpioManagerSifive::Trigger);

}  // namespace deri::dev::gpio
