/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct AONCLK_regs {
  enum class lfrosccfg_bits : uint32_t;
  enum class lfrosccfg_shift : unsigned;

  Register<lfrosccfg_bits> lfrosccfg;
};
}  // namespace deri::mmio
