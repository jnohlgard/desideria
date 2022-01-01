/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <type_traits>

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

  Gpio() = default;
  Gpio(const Gpio &) = default;
  Gpio(Gpio &&) noexcept = default;
  Gpio &operator=(const Gpio &) = default;
  Gpio &operator=(Gpio &&) noexcept = default;

  Pin pin;
  Port port;
};

struct GpioInConfig {
  enum class Trigger {
    RISING = (1 << 0),
    FALLING = (1 << 1),
    HIGH = (1 << 2),
    LOW = (1 << 3),
  };
  enum class PullConfig {
    FLOATING,
    PULL_UP,
    PULL_DOWN,
  };
  Gpio gpio;
  PullConfig pull{PullConfig::FLOATING};
};

struct GpioOutConfig {
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
