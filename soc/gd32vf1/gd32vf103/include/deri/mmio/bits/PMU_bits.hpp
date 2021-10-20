/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/PMU.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for PMU CTL
 *
 * power control register
 */
enum class PMU_regs::CTL_bits : uint32_t {
  BKPWEN = (1u << 8),         ///< Backup Domain Write Enable
  LVDT_mask = (0x7u << 5),    ///< Low Voltage Detector Threshold
  LVDEN = (1u << 4),          ///< Low Voltage Detector Enable
  STBRST = (1u << 3),         ///< Standby Flag Reset
  WURST = (1u << 2),          ///< Wakeup Flag Reset
  STBMOD = (1u << 1),         ///< Standby Mode
  LDOLP = (1u << 0),          ///< LDO Low Power Mode
  Reserved_mask = 0xfffffe00  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::CTL_bits);

/**
 * Bit shifts for PMU CTL
 */
enum class PMU_regs::CTL_shift : unsigned {
  BKPWEN = 8,
  LVDT = 5,
  LVDEN = 4,
  STBRST = 3,
  WURST = 2,
  STBMOD = 1,
  LDOLP = 0,
};

/**
 * Bitmasks for PMU CS
 *
 * power control/status register
 */
enum class PMU_regs::CS_bits : uint32_t {
  WUPEN = (1u << 8),          ///< Enable WKUP pin
  LVDF = (1u << 2),           ///< Low Voltage Detector Status Flag
  STBF = (1u << 1),           ///< Standby flag
  WUF = (1u << 0),            ///< Wakeup flag
  Reserved_mask = 0xfffffef8  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::CS_bits);

/**
 * Bit shifts for PMU CS
 */
enum class PMU_regs::CS_shift : unsigned {
  WUPEN = 8,
  LVDF = 2,
  STBF = 1,
  WUF = 0,
};

static_assert(offsetof(PMU_regs, CTL) == 0x0);
static_assert(offsetof(PMU_regs, CS) == 0x4);
}  // namespace deri::mmio
