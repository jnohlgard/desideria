/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/FWDGT.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for FWDGT CTL
 *
 * Control register
 */
enum class FWDGT_regs::CTL_bits : uint32_t {
  CMD_mask = (0xffff << 0),   ///< Key value
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(FWDGT_regs::CTL_bits);

/**
 * Bit shifts for FWDGT CTL
 */
enum class FWDGT_regs::CTL_shift : unsigned {
  CMD = 0,
};

/**
 * Bitmasks for FWDGT PSC
 *
 * Prescaler register
 */
enum class FWDGT_regs::PSC_bits : uint32_t {
  PSC_mask = (0x7 << 0),      ///< Free watchdog timer prescaler selection
  Reserved_mask = 0xfffffff8  ///< All reserved bits
};
void HasBitwiseOperators(FWDGT_regs::PSC_bits);

/**
 * Bit shifts for FWDGT PSC
 */
enum class FWDGT_regs::PSC_shift : unsigned {
  PSC = 0,
};

/**
 * Bitmasks for FWDGT RLD
 *
 * Reload register
 */
enum class FWDGT_regs::RLD_bits : uint32_t {
  RLD_mask = (0xfff << 0),    ///< Free watchdog timer counter reload value
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(FWDGT_regs::RLD_bits);

/**
 * Bit shifts for FWDGT RLD
 */
enum class FWDGT_regs::RLD_shift : unsigned {
  RLD = 0,
};

/**
 * Bitmasks for FWDGT STAT
 *
 * Status register
 */
enum class FWDGT_regs::STAT_bits : uint32_t {
  PUD = (1 << 0),  ///< Free watchdog timer prescaler value update
  RUD = (1 << 1),  ///< Free watchdog timer counter reload value update
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(FWDGT_regs::STAT_bits);

/**
 * Bit shifts for FWDGT STAT
 */
enum class FWDGT_regs::STAT_shift : unsigned {
  PUD = 0,
  RUD = 1,
};

static_assert(offsetof(FWDGT_regs, CTL) == 0x0);
static_assert(offsetof(FWDGT_regs, PSC) == 0x4);
static_assert(offsetof(FWDGT_regs, RLD) == 0x8);
static_assert(offsetof(FWDGT_regs, STAT) == 0xc);
}  // namespace deri::mmio
