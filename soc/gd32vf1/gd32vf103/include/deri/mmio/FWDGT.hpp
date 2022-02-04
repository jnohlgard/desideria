/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct FWDGT_regs {
  enum class CTL_bits : uint32_t;
  enum class PSC_bits : uint32_t;
  enum class RLD_bits : uint32_t;
  enum class STAT_bits : uint32_t;
  enum class CTL_shift : unsigned;
  enum class PSC_shift : unsigned;
  enum class RLD_shift : unsigned;
  enum class STAT_shift : unsigned;

  Register<CTL_bits> CTL;
  Register<PSC_bits> PSC;
  Register<RLD_bits> RLD;
  const Register<STAT_bits> STAT;
};
}  // namespace deri::mmio
