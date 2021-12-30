/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct PRCI_regs {
  enum class hfrosccfg_bits : uint32_t;
  enum class hfxosccfg_bits : uint32_t;
  enum class pllcfg_bits : uint32_t;
  enum class plloutdiv_bits : uint32_t;
  enum class coreclkcfg_bits : uint32_t;
  enum class hfrosccfg_shift : unsigned;
  enum class hfxosccfg_shift : unsigned;
  enum class pllcfg_shift : unsigned;
  enum class plloutdiv_shift : unsigned;
  enum class coreclkcfg_shift : unsigned;

  Register<hfrosccfg_bits> hfrosccfg;
  Register<hfxosccfg_bits> hfxosccfg;
  Register<pllcfg_bits> pllcfg;
  Register<plloutdiv_bits> plloutdiv;
  Register<coreclkcfg_bits> coreclkcfg;
};
}  // namespace deri::mmio
