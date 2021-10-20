/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/WWDGT.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for WWDGT CTL
 *
 * Control register
 */
enum class WWDGT_regs::CTL_bits : uint32_t {
  WDGTEN = (1u << 7),         ///< Activation bit
  CNT_mask = (0x7fu << 0),    ///< 7-bit counter
  Reserved_mask = 0xffffff00  ///< All reserved bits
};
void HasBitwiseOperators(WWDGT_regs::CTL_bits);

/**
 * Bit shifts for WWDGT CTL
 */
enum class WWDGT_regs::CTL_shift : unsigned {
  WDGTEN = 7,
  CNT = 0,
};

/**
 * Bitmasks for WWDGT CFG
 *
 * Configuration register
 */
enum class WWDGT_regs::CFG_bits : uint32_t {
  EWIE = (1u << 9),           ///< Early wakeup interrupt
  PSC_mask = (0x3u << 7),     ///< Prescaler
  WIN_mask = (0x7fu << 0),    ///< 7-bit window value
  Reserved_mask = 0xfffffc00  ///< All reserved bits
};
void HasBitwiseOperators(WWDGT_regs::CFG_bits);

/**
 * Bit shifts for WWDGT CFG
 */
enum class WWDGT_regs::CFG_shift : unsigned {
  EWIE = 9,
  PSC = 7,
  WIN = 0,
};

/**
 * Bitmasks for WWDGT STAT
 *
 * Status register
 */
enum class WWDGT_regs::STAT_bits : uint32_t {
  EWIF = (1u << 0),           ///< Early wakeup interrupt flag
  Reserved_mask = 0xfffffffe  ///< All reserved bits
};
void HasBitwiseOperators(WWDGT_regs::STAT_bits);

/**
 * Bit shifts for WWDGT STAT
 */
enum class WWDGT_regs::STAT_shift : unsigned {
  EWIF = 0,
};

static_assert(offsetof(WWDGT_regs, CTL) == 0x0);
static_assert(offsetof(WWDGT_regs, CFG) == 0x4);
static_assert(offsetof(WWDGT_regs, STAT) == 0x8);
}  // namespace deri::mmio
