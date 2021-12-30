/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/PLIC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for PLIC priority[53]
 *
 * Interrupt Priority Register
 */
enum class PLIC_regs::priority_bits : uint32_t {
  priority_mask = (0x7u << 0),
  Reserved_mask = 0xfffffff8  ///< All reserved bits
};
void HasBitwiseOperators(PLIC_regs::priority_bits);

/**
 * Bit shifts for PLIC priority[53]
 */
enum class PLIC_regs::priority_shift : unsigned {
  priority = 0,
};

/**
 * Bitmasks for PLIC pending[2]
 *
 * Interrupt Pending Register
 */
enum class PLIC_regs::pending_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(PLIC_regs::pending_bits);

/**
 * Bit shifts for PLIC pending[2]
 */
enum class PLIC_regs::pending_shift : unsigned {};

/**
 * Bitmasks for PLIC enable[2]
 *
 * Interrupt Enable Register
 */
enum class PLIC_regs::enable_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(PLIC_regs::enable_bits);

/**
 * Bit shifts for PLIC enable[2]
 */
enum class PLIC_regs::enable_shift : unsigned {};

/**
 * Bitmasks for PLIC threshold
 *
 * Priority Threshold Register
 */
enum class PLIC_regs::threshold_bits : uint32_t {
  priority_mask = (0x7u << 0),
  Reserved_mask = 0xfffffff8  ///< All reserved bits
};
void HasBitwiseOperators(PLIC_regs::threshold_bits);

/**
 * Bit shifts for PLIC threshold
 */
enum class PLIC_regs::threshold_shift : unsigned {
  priority = 0,
};

/**
 * Bitmasks for PLIC claim
 *
 * Claim/Complete Register
 */
enum class PLIC_regs::claim_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(PLIC_regs::claim_bits);

/**
 * Bit shifts for PLIC claim
 */
enum class PLIC_regs::claim_shift : unsigned {};

static_assert(offsetof(PLIC_regs, priority) == 0x0);
static_assert(offsetof(PLIC_regs, pending) == 0x1000);
static_assert(offsetof(PLIC_regs, enable) == 0x2000);
static_assert(offsetof(PLIC_regs, threshold) == 0x200000);
static_assert(offsetof(PLIC_regs, claim) == 0x200004);
}  // namespace deri::mmio
