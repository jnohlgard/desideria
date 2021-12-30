/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/PWM.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for PWM cfg
 *
 * PWM Configuration Register
 */
enum class PWM_regs::cfg_bits : uint32_t {
  cmp3ip = (1u << 31),
  cmp2ip = (1u << 30),
  cmp1ip = (1u << 29),
  cmp0ip = (1u << 28),
  cmp3gang = (1u << 27),
  cmp2gang_mask = (0x7ffu << 26),
  cmp1gang = (1u << 25),
  cmp0gang = (1u << 24),
  cmp3center = (1u << 19),
  cmp2center = (1u << 18),
  cmp1center = (1u << 17),
  cmp0center = (1u << 16),
  enoneshot = (1u << 13),
  enalways = (1u << 12),
  deglitch = (1u << 10),
  zerocmp = (1u << 9),
  sticky = (1u << 8),
  scale_mask = (0xfu << 0),
  Reserved_mask = 0x00f0c8f0  ///< All reserved bits
};
void HasBitwiseOperators(PWM_regs::cfg_bits);

/**
 * Bit shifts for PWM cfg
 */
enum class PWM_regs::cfg_shift : unsigned {
  cmp3ip = 31,
  cmp2ip = 30,
  cmp1ip = 29,
  cmp0ip = 28,
  cmp3gang = 27,
  cmp2gang = 26,
  cmp1gang = 25,
  cmp0gang = 24,
  cmp3center = 19,
  cmp2center = 18,
  cmp1center = 17,
  cmp0center = 16,
  enoneshot = 13,
  enalways = 12,
  deglitch = 10,
  zerocmp = 9,
  sticky = 8,
  scale = 0,
};

/**
 * Bitmasks for PWM count
 *
 * Counter Register
 */
enum class PWM_regs::count_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(PWM_regs::count_bits);

/**
 * Bit shifts for PWM count
 */
enum class PWM_regs::count_shift : unsigned {};

/**
 * Bitmasks for PWM pwms
 *
 * Scaled Halfword Counter Register
 */
enum class PWM_regs::pwms_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(PWM_regs::pwms_bits);

/**
 * Bit shifts for PWM pwms
 */
enum class PWM_regs::pwms_shift : unsigned {};

/**
 * Bitmasks for PWM cmp0
 *
 * Compare Register
 */
enum class PWM_regs::cmp0_bits : uint32_t {
  value_mask = (0xffffu << 0),
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(PWM_regs::cmp0_bits);

/**
 * Bit shifts for PWM cmp0
 */
enum class PWM_regs::cmp0_shift : unsigned {
  value = 0,
};

/**
 * Bitmasks for PWM cmp1
 *
 * Compare Register
 */
enum class PWM_regs::cmp1_bits : uint32_t {
  value_mask = (0xffffu << 0),
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(PWM_regs::cmp1_bits);

/**
 * Bit shifts for PWM cmp1
 */
enum class PWM_regs::cmp1_shift : unsigned {
  value = 0,
};

/**
 * Bitmasks for PWM cmp2
 *
 * Compare Register
 */
enum class PWM_regs::cmp2_bits : uint32_t {
  value_mask = (0xffffu << 0),
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(PWM_regs::cmp2_bits);

/**
 * Bit shifts for PWM cmp2
 */
enum class PWM_regs::cmp2_shift : unsigned {
  value = 0,
};

/**
 * Bitmasks for PWM cmp3
 *
 * Compare Register
 */
enum class PWM_regs::cmp3_bits : uint32_t {
  value_mask = (0xffffu << 0),
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(PWM_regs::cmp3_bits);

/**
 * Bit shifts for PWM cmp3
 */
enum class PWM_regs::cmp3_shift : unsigned {
  value = 0,
};

static_assert(offsetof(PWM_regs, cfg) == 0x0);
static_assert(offsetof(PWM_regs, count) == 0x8);
static_assert(offsetof(PWM_regs, pwms) == 0x10);
static_assert(offsetof(PWM_regs, cmp0) == 0x20);
static_assert(offsetof(PWM_regs, cmp1) == 0x24);
static_assert(offsetof(PWM_regs, cmp2) == 0x28);
static_assert(offsetof(PWM_regs, cmp3) == 0x2c);
}  // namespace deri::mmio
