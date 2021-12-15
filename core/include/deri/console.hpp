/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

#include "deri/bsp/console.hpp"

namespace deri {
/**
 * Kernel console device
 */
class Console {
 public:
  static void write(std::span<const std::byte> buffer) {
    bsp::console().write(buffer);
  }
};
}  // namespace deri
