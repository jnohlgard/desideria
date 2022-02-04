/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct PMU_regs {
  enum class CTL_bits : uint32_t;
  enum class CS_bits : uint32_t;
  enum class CTL_shift : unsigned;
  enum class CS_shift : unsigned;

  Register<CTL_bits> CTL;
  Register<CS_bits> CS;
};
}  // namespace deri::mmio
