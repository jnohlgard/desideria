/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/RTC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for RTC rtccfg
 *
 * RTC Configuration Register
 */
enum class RTC_regs::rtccfg_bits : uint32_t {
  cmpip = (1u << 28),
  enalways = (1u << 12),
  scale_mask = (0xfu << 0),
  Reserved_mask = 0xefffeff0  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::rtccfg_bits);

/**
 * Bit shifts for RTC rtccfg
 */
enum class RTC_regs::rtccfg_shift : unsigned {
  cmpip = 28,
  enalways = 12,
  scale = 0,
};

/**
 * Bitmasks for RTC rtclo
 *
 * RTC Counter Low Register
 */
enum class RTC_regs::rtclo_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::rtclo_bits);

/**
 * Bit shifts for RTC rtclo
 */
enum class RTC_regs::rtclo_shift : unsigned {};

/**
 * Bitmasks for RTC rtchi
 *
 * RTC Counter High Register
 */
enum class RTC_regs::rtchi_bits : uint32_t {
  value_mask = (0xffffu << 0),
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::rtchi_bits);

/**
 * Bit shifts for RTC rtchi
 */
enum class RTC_regs::rtchi_shift : unsigned {
  value = 0,
};

/**
 * Bitmasks for RTC rtcs
 *
 * RTC Scaled Counter Register
 */
enum class RTC_regs::rtcs_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::rtcs_bits);

/**
 * Bit shifts for RTC rtcs
 */
enum class RTC_regs::rtcs_shift : unsigned {};

/**
 * Bitmasks for RTC rtccmp
 *
 * RTC Compare Register
 */
enum class RTC_regs::rtccmp_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(RTC_regs::rtccmp_bits);

/**
 * Bit shifts for RTC rtccmp
 */
enum class RTC_regs::rtccmp_shift : unsigned {};

static_assert(offsetof(RTC_regs, rtccfg) == 0x0);
static_assert(offsetof(RTC_regs, rtclo) == 0x8);
static_assert(offsetof(RTC_regs, rtchi) == 0xc);
static_assert(offsetof(RTC_regs, rtcs) == 0x10);
static_assert(offsetof(RTC_regs, rtccmp) == 0x20);
}  // namespace deri::mmio
