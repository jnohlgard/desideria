/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/DBG.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for DBG ID
 *
 * ID code register
 */
enum class DBG_regs::ID_bits : uint32_t {
  ID_CODE_mask = (0xffffffffu << 0),  ///< DBG ID code register
};
void HasBitwiseOperators(DBG_regs::ID_bits);

/**
 * Bit shifts for DBG ID
 */
enum class DBG_regs::ID_shift : unsigned {
  ID_CODE = 0,
};

/**
 * Bitmasks for DBG CTL
 *
 * Control register 0
 */
enum class DBG_regs::CTL_bits : uint32_t {
  SLP_HOLD = (1u << 0),       ///< Sleep mode hold register
  DSLP_HOLD = (1u << 1),      ///< Deep-sleep mode hold register
  STB_HOLD = (1u << 2),       ///< Standby mode hold register
  FWDGT_HOLD = (1u << 8),     ///< FWDGT hold bit
  WWDGT_HOLD = (1u << 9),     ///< WWDGT hold bit
  TIMER0_HOLD = (1u << 10),   ///< TIMER 0 hold bit
  TIMER1_HOLD = (1u << 11),   ///< TIMER 1 hold bit
  TIMER2_HOLD = (1u << 12),   ///< TIMER 2 hold bit
  TIMER3_HOLD = (1u << 13),   ///< TIMER 23 hold bit
  CAN0_HOLD = (1u << 14),     ///< CAN0 hold bit
  I2C0_HOLD = (1u << 15),     ///< I2C0 hold bit
  I2C1_HOLD = (1u << 16),     ///< I2C1 hold bit
  TIMER4_HOLD = (1u << 18),   ///< TIMER4_HOLD
  TIMER5_HOLD = (1u << 19),   ///< TIMER 5 hold bit
  TIMER6_HOLD = (1u << 20),   ///< TIMER 6 hold bit
  CAN1_HOLD = (1u << 21),     ///< CAN1 hold bit
  Reserved_mask = 0xffc200f8  ///< All reserved bits
};
void HasBitwiseOperators(DBG_regs::CTL_bits);

/**
 * Bit shifts for DBG CTL
 */
enum class DBG_regs::CTL_shift : unsigned {
  SLP_HOLD = 0,
  DSLP_HOLD = 1,
  STB_HOLD = 2,
  FWDGT_HOLD = 8,
  WWDGT_HOLD = 9,
  TIMER0_HOLD = 10,
  TIMER1_HOLD = 11,
  TIMER2_HOLD = 12,
  TIMER3_HOLD = 13,
  CAN0_HOLD = 14,
  I2C0_HOLD = 15,
  I2C1_HOLD = 16,
  TIMER4_HOLD = 18,
  TIMER5_HOLD = 19,
  TIMER6_HOLD = 20,
  CAN1_HOLD = 21,
};

static_assert(offsetof(DBG_regs, ID) == 0x0);
static_assert(offsetof(DBG_regs, CTL) == 0x4);
}  // namespace deri::mmio
