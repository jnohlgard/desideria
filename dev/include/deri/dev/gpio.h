/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <optional>

namespace deri::dev::gpio {

/**
 * GPIO pin specifier
 */
struct Gpio {
  enum class Pin : unsigned;
  enum class Port : unsigned;

  constexpr Gpio(Port port, Pin pin) : pin(pin), port(port) {}

  /// Convenience wrapper for int pin number
  constexpr Gpio(Port port, std::underlying_type_t<Pin> pin)
      : Gpio(port, static_cast<Pin>(pin)) {}

  Pin pin;
  Port port;
};

struct GpioIn {
  enum class PullConfig {
    FLOATING,
    PULL_UP,
    PULL_DOWN,
  };
  Gpio gpio;
  PullConfig pull{PullConfig::FLOATING};
};

struct GpioOut {
  enum class OutputMode {
    PUSH_PULL,
    OPEN_DRAIN,
  };
  enum class Polarity {
    POSITIVE,
    INVERTED,
  };
  Gpio gpio;
  OutputMode mode{OutputMode::PUSH_PULL};
  Polarity polarity{Polarity::POSITIVE};
};

}  // namespace deri::dev::gpio
