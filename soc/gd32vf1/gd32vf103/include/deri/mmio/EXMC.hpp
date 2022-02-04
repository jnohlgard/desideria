/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct EXMC_regs {
  enum class SNCTL0_bits : uint32_t;
  enum class SNTCFG0_bits : uint32_t;
  enum class SNCTL1_bits : uint32_t;
  enum class SNCTL0_shift : unsigned;
  enum class SNTCFG0_shift : unsigned;
  enum class SNCTL1_shift : unsigned;

  Register<SNCTL0_bits> SNCTL0;
  Register<SNTCFG0_bits> SNTCFG0;
  Register<SNCTL1_bits> SNCTL1;
};
}  // namespace deri::mmio
