/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct WWDGT_regs {
  enum class CTL_bits : uint32_t;
  enum class CFG_bits : uint32_t;
  enum class STAT_bits : uint32_t;
  enum class CTL_shift : unsigned;
  enum class CFG_shift : unsigned;
  enum class STAT_shift : unsigned;

  Register<CTL_bits> CTL;
  Register<CFG_bits> CFG;
  Register<STAT_bits> STAT;
};
}  // namespace deri::mmio
