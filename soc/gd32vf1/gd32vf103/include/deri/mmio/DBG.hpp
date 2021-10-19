/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct DBG_regs {
  enum class ID_bits : uint32_t;
  enum class CTL_bits : uint32_t;
  enum class ID_shift : unsigned;
  enum class CTL_shift : unsigned;

  const Register<ID_bits> ID;
  Register<CTL_bits> CTL;
};
}  // namespace deri::mmio
