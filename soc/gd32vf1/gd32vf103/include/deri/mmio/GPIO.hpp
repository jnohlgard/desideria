/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct GPIO_regs {
  enum class CTL_bits : uint32_t;
  enum class ISTAT_bits : uint32_t;
  enum class OCTL_bits : uint32_t;
  enum class BOP_bits : uint32_t;
  enum class BC_bits : uint32_t;
  enum class LOCK_bits : uint32_t;
  enum class CTL_shift : unsigned;
  enum class ISTAT_shift : unsigned;
  enum class OCTL_shift : unsigned;
  enum class BOP_shift : unsigned;
  enum class BC_shift : unsigned;
  enum class LOCK_shift : unsigned;

  Register<CTL_bits> CTL[2];
  const Register<ISTAT_bits> ISTAT;
  Register<OCTL_bits> OCTL;
  Register<BOP_bits> BOP;
  Register<BC_bits> BC;
  Register<LOCK_bits> LOCK;
};
}  // namespace deri::mmio
