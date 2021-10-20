/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/RTC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for RTC INTEN
 *
 * RTC interrupt enable register
 */
enum class RTC_regs::INTEN_bits : uint32_t {
  OVIE = (1u << 2),           ///< Overflow interrupt enable
  ALRMIE = (1u << 1),         ///< Alarm interrupt enable
  SCIE = (1u << 0),           ///< Second interrupt
  Reserved_mask = 0xfffffff8  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::INTEN_bits);

/**
 * Bit shifts for RTC INTEN
 */
enum class RTC_regs::INTEN_shift : unsigned {
  OVIE = 2,
  ALRMIE = 1,
  SCIE = 0,
};

/**
 * Bitmasks for RTC CTL
 *
 * control register
 */
enum class RTC_regs::CTL_bits : uint32_t {
  LWOFF = (1u << 5),          ///< Last write operation finished flag
  CMF = (1u << 4),            ///< Configuration mode flag
  RSYNF = (1u << 3),          ///< Registers synchronized flag
  OVIF = (1u << 2),           ///< Overflow interrupt flag
  ALRMIF = (1u << 1),         ///< Alarm interrupt flag
  SCIF = (1u << 0),           ///< Sencond interrupt flag
  Reserved_mask = 0xffffffc0  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::CTL_bits);

/**
 * Bit shifts for RTC CTL
 */
enum class RTC_regs::CTL_shift : unsigned {
  LWOFF = 5,
  CMF = 4,
  RSYNF = 3,
  OVIF = 2,
  ALRMIF = 1,
  SCIF = 0,
};

/**
 * Bitmasks for RTC PSCH
 *
 * RTC prescaler high register
 */
enum class RTC_regs::PSCH_bits : uint32_t {
  PSC_mask = (0xfu << 0),     ///< RTC prescaler value high
  Reserved_mask = 0xfffffff0  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::PSCH_bits);

/**
 * Bit shifts for RTC PSCH
 */
enum class RTC_regs::PSCH_shift : unsigned {
  PSC = 0,
};

/**
 * Bitmasks for RTC PSCL
 *
 * RTC prescaler low register
 */
enum class RTC_regs::PSCL_bits : uint32_t {
  PSC_mask = (0xffffu << 0),  ///< RTC prescaler value low
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::PSCL_bits);

/**
 * Bit shifts for RTC PSCL
 */
enum class RTC_regs::PSCL_shift : unsigned {
  PSC = 0,
};

/**
 * Bitmasks for RTC DIVH
 *
 * RTC divider high register
 */
enum class RTC_regs::DIVH_bits : uint32_t {
  DIV_mask = (0xfu << 0),     ///< RTC divider value high
  Reserved_mask = 0xfffffff0  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::DIVH_bits);

/**
 * Bit shifts for RTC DIVH
 */
enum class RTC_regs::DIVH_shift : unsigned {
  DIV = 0,
};

/**
 * Bitmasks for RTC DIVL
 *
 * RTC divider low register
 */
enum class RTC_regs::DIVL_bits : uint32_t {
  DIV_mask = (0xffffu << 0),  ///< RTC divider value low
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::DIVL_bits);

/**
 * Bit shifts for RTC DIVL
 */
enum class RTC_regs::DIVL_shift : unsigned {
  DIV = 0,
};

/**
 * Bitmasks for RTC CNTH
 *
 * RTC counter high register
 */
enum class RTC_regs::CNTH_bits : uint32_t {
  CNT_mask = (0xffffu << 0),  ///< RTC counter value high
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::CNTH_bits);

/**
 * Bit shifts for RTC CNTH
 */
enum class RTC_regs::CNTH_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for RTC CNTL
 *
 * RTC counter low register
 */
enum class RTC_regs::CNTL_bits : uint32_t {
  CNT_mask = (0xffffu << 0),  ///< RTC counter value low
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::CNTL_bits);

/**
 * Bit shifts for RTC CNTL
 */
enum class RTC_regs::CNTL_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for RTC ALRMH
 *
 * Alarm high register
 */
enum class RTC_regs::ALRMH_bits : uint32_t {
  ALRM_mask = (0xffffu << 0),  ///< Alarm value high
  Reserved_mask = 0xffff0000   ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::ALRMH_bits);

/**
 * Bit shifts for RTC ALRMH
 */
enum class RTC_regs::ALRMH_shift : unsigned {
  ALRM = 0,
};

/**
 * Bitmasks for RTC ALRML
 *
 * RTC alarm low register
 */
enum class RTC_regs::ALRML_bits : uint32_t {
  ALRM_mask = (0xffffu << 0),  ///< alarm value low
  Reserved_mask = 0xffff0000   ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::ALRML_bits);

/**
 * Bit shifts for RTC ALRML
 */
enum class RTC_regs::ALRML_shift : unsigned {
  ALRM = 0,
};

static_assert(offsetof(RTC_regs, INTEN) == 0x0);
static_assert(offsetof(RTC_regs, CTL) == 0x4);
static_assert(offsetof(RTC_regs, PSCH) == 0x8);
static_assert(offsetof(RTC_regs, PSCL) == 0xc);
static_assert(offsetof(RTC_regs, DIVH) == 0x10);
static_assert(offsetof(RTC_regs, DIVL) == 0x14);
static_assert(offsetof(RTC_regs, CNTH) == 0x18);
static_assert(offsetof(RTC_regs, CNTL) == 0x1c);
static_assert(offsetof(RTC_regs, ALRMH) == 0x20);
static_assert(offsetof(RTC_regs, ALRML) == 0x24);
}  // namespace deri::mmio
