/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct CRC_regs {
  enum class DATA_bits : uint32_t;
  enum class FDATA_bits : uint32_t;
  enum class CTL_bits : uint32_t;
  enum class DATA_shift : unsigned;
  enum class FDATA_shift : unsigned;
  enum class CTL_shift : unsigned;

  Register<DATA_bits> DATA;
  Register<FDATA_bits> FDATA;
  Register<CTL_bits> CTL;
};
}  // namespace deri::mmio
