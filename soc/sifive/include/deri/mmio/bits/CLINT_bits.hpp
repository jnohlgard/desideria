/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/CLINT.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for CLINT msip
 *
 * Hart 0 software interrupt register
 */
enum class CLINT_regs::msip_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(CLINT_regs::msip_bits);

/**
 * Bit shifts for CLINT msip
 */
enum class CLINT_regs::msip_shift : unsigned {};

/**
 * Bitmasks for CLINT mtimecmp
 *
 * Hart 0 time comparator register
 */
enum class CLINT_regs::mtimecmp_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(CLINT_regs::mtimecmp_bits);

/**
 * Bit shifts for CLINT mtimecmp
 */
enum class CLINT_regs::mtimecmp_shift : unsigned {};

/**
 * Bitmasks for CLINT mtimecmph
 *
 * Hart 0 time comparator register
 */
enum class CLINT_regs::mtimecmph_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(CLINT_regs::mtimecmph_bits);

/**
 * Bit shifts for CLINT mtimecmph
 */
enum class CLINT_regs::mtimecmph_shift : unsigned {};

/**
 * Bitmasks for CLINT mtime
 *
 * Timer register
 */
enum class CLINT_regs::mtime_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(CLINT_regs::mtime_bits);

/**
 * Bit shifts for CLINT mtime
 */
enum class CLINT_regs::mtime_shift : unsigned {};

/**
 * Bitmasks for CLINT mtimeh
 *
 * Timer register
 */
enum class CLINT_regs::mtimeh_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(CLINT_regs::mtimeh_bits);

/**
 * Bit shifts for CLINT mtimeh
 */
enum class CLINT_regs::mtimeh_shift : unsigned {};

static_assert(offsetof(CLINT_regs, msip) == 0x0);
static_assert(offsetof(CLINT_regs, mtimecmp) == 0x4000);
static_assert(offsetof(CLINT_regs, mtimecmph) == 0x4004);
static_assert(offsetof(CLINT_regs, mtime) == 0xbff8);
static_assert(offsetof(CLINT_regs, mtimeh) == 0xbffc);
}  // namespace deri::mmio
