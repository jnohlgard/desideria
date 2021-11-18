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

struct InputPinConfig {
Gpio gpio;

};

}  // namespace deri::dev::gpio
