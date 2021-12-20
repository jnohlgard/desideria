/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/registers.hpp"

#include <array>
#include <cstdint>

namespace deri::mmio {
struct MTIME_regs {
  enum class MTIME_bits : int64_t;

  Register<MTIME_bits> mtime;
  Register<MTIME_bits> mtimecmp;
};
}  // namespace deri::mmio
