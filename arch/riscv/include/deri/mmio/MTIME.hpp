/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/registers.hpp"

#include <array>
#include <cstdint>

namespace deri::mmio {
enum class MTIME_bits : uint32_t;
enum class MTIME64_bits : uint64_t;

using MTIME_reg = SplitRegister<MTIME_bits, MTIME64_bits>;
extern MTIME_reg mtime;
extern MTIME_reg mtimecmp;
}  // namespace deri::mmio
