/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/AONCLK.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for AONCLK lfrosccfg
 *
 * AON Clock Configuration Register
 */
enum class AONCLK_regs::lfrosccfg_bits : uint32_t {
  ready = (1u << 31),
  enable = (1u << 30),
  trim_mask = (0x1fu << 16),
  div_mask = (0x3fu << 0),
  Reserved_mask = 0x3fe0ffc0  ///< All reserved bits
};
void HasBitwiseOperators(AONCLK_regs::lfrosccfg_bits);

/**
 * Bit shifts for AONCLK lfrosccfg
 */
enum class AONCLK_regs::lfrosccfg_shift : unsigned {
  ready = 31,
  enable = 30,
  trim = 16,
  div = 0,
};

static_assert(offsetof(AONCLK_regs, lfrosccfg) == 0x0);
}  // namespace deri::mmio
