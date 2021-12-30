/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct I2C_regs {
  enum class prer_lo_bits : uint32_t;
  enum class prer_hi_bits : uint32_t;
  enum class ctr_bits : uint32_t;
  enum class txr_rxr_bits : uint32_t;
  enum class cr_sr_bits : uint32_t;
  enum class cr_bits : uint32_t;
  enum class sr_bits : uint32_t;
  enum class prer_lo_shift : unsigned;
  enum class prer_hi_shift : unsigned;
  enum class ctr_shift : unsigned;
  enum class txr_rxr_shift : unsigned;
  enum class cr_sr_shift : unsigned;
  enum class cr_shift : unsigned;
  enum class sr_shift : unsigned;

  Register<prer_lo_bits> prer_lo;
  Register<prer_hi_bits> prer_hi;
  Register<ctr_bits> ctr;
  Register<txr_rxr_bits> txr_rxr;
  Register<cr_sr_bits> cr_sr;
  Register<cr_bits> cr;
  const Register<sr_bits> sr;
};
}  // namespace deri::mmio
