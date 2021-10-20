/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/USBFS_PWRCLK.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for USBFS_PWRCLK PWRCLKCTL
 *
 * power and clock gating control register (PWRCLKCTL)
 */
enum class USBFS_PWRCLK_regs::PWRCLKCTL_bits : uint32_t {
  SUCLK = (1u << 0),          ///< Stop the USB clock
  SHCLK = (1u << 1),          ///< Stop HCLK
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_PWRCLK_regs::PWRCLKCTL_bits);

/**
 * Bit shifts for USBFS_PWRCLK PWRCLKCTL
 */
enum class USBFS_PWRCLK_regs::PWRCLKCTL_shift : unsigned {
  SUCLK = 0,
  SHCLK = 1,
};

static_assert(offsetof(USBFS_PWRCLK_regs, PWRCLKCTL) == 0x0);
}  // namespace deri::mmio
