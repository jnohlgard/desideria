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
  BKPWEN = (1 << 8),          ///< Backup Domain Write Enable
  LVDT_mask = (0x7 << 5),     ///< Low Voltage Detector Threshold
  LVDEN = (1 << 4),           ///< Low Voltage Detector Enable
  STBRST = (1 << 3),          ///< Standby Flag Reset
  WURST = (1 << 2),           ///< Wakeup Flag Reset
  STBMOD = (1 << 1),          ///< Standby Mode
  LDOLP = (1 << 0),           ///< LDO Low Power Mode
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
  WUPEN = (1 << 8),           ///< Enable WKUP pin
  LVDF = (1 << 2),            ///< Low Voltage Detector Status Flag
  STBF = (1 << 1),            ///< Standby flag
  WUF = (1 << 0),             ///< Wakeup flag
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
