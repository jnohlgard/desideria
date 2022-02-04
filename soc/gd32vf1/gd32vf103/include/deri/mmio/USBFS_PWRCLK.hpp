/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct USBFS_PWRCLK_regs {
  enum class PWRCLKCTL_bits : uint32_t;
  enum class PWRCLKCTL_shift : unsigned;

  Register<PWRCLKCTL_bits> PWRCLKCTL;
};
}  // namespace deri::mmio
