/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/PRCI.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for PRCI hfrosccfg
 *
 * Clock Configuration Register
 */
enum class PRCI_regs::hfrosccfg_bits : uint32_t {
  ready = (1u << 31),
  enable = (1u << 30),
  trim_mask = (0x1fu << 16),
  div_mask = (0x3fu << 0),
  Reserved_mask = 0x3fe0ffc0  ///< All reserved bits
};
void HasBitwiseOperators(PRCI_regs::hfrosccfg_bits);

/**
 * Bit shifts for PRCI hfrosccfg
 */
enum class PRCI_regs::hfrosccfg_shift : unsigned {
  ready = 31,
  enable = 30,
  trim = 16,
  div = 0,
};
void IsBitShift(PRCI_regs::hfrosccfg_shift);

/**
 * Bitmasks for PRCI hfxosccfg
 *
 * Clock Configuration Register
 */
enum class PRCI_regs::hfxosccfg_bits : uint32_t {
  ready = (1u << 31),
  enable = (1u << 30),
  Reserved_mask = 0x3fffffff  ///< All reserved bits
};
void HasBitwiseOperators(PRCI_regs::hfxosccfg_bits);

/**
 * Bit shifts for PRCI hfxosccfg
 */
enum class PRCI_regs::hfxosccfg_shift : unsigned {
  ready = 31,
  enable = 30,
};
void IsBitShift(PRCI_regs::hfxosccfg_shift);

/**
 * Bitmasks for PRCI pllcfg
 *
 * PLL Configuration Register
 */
enum class PRCI_regs::pllcfg_bits : uint32_t {
  lock = (1u << 31),
  bypass = (1u << 18),
  refsel = (1u << 17),
  sel = (1u << 16),
  pllq_mask = (0x3u << 10),
  pllf_mask = (0x3fu << 4),
  pllr_mask = (0x7u << 0),
  Reserved_mask = 0x7ff8f008  ///< All reserved bits
};
void HasBitwiseOperators(PRCI_regs::pllcfg_bits);

/**
 * Bit shifts for PRCI pllcfg
 */
enum class PRCI_regs::pllcfg_shift : unsigned {
  lock = 31,
  bypass = 18,
  refsel = 17,
  sel = 16,
  pllq = 10,
  pllf = 4,
  pllr = 0,
};
void IsBitShift(PRCI_regs::pllcfg_shift);

/**
 * Bitmasks for PRCI plloutdiv
 *
 * PLL Divider Register
 */
enum class PRCI_regs::plloutdiv_bits : uint32_t {
  divby1 = (1u << 8),
  div_mask = (0x3fu << 0),
  Reserved_mask = 0xfffffec0  ///< All reserved bits
};
void HasBitwiseOperators(PRCI_regs::plloutdiv_bits);

/**
 * Bit shifts for PRCI plloutdiv
 */
enum class PRCI_regs::plloutdiv_shift : unsigned {
  divby1 = 8,
  div = 0,
};
void IsBitShift(PRCI_regs::plloutdiv_shift);

/**
 * Bitmasks for PRCI coreclkcfg
 *
 * Clock Configuration Register
 */
enum class PRCI_regs::coreclkcfg_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(PRCI_regs::coreclkcfg_bits);

/**
 * Bit shifts for PRCI coreclkcfg
 */
enum class PRCI_regs::coreclkcfg_shift : unsigned {};
void IsBitShift(PRCI_regs::coreclkcfg_shift);

static_assert(offsetof(PRCI_regs, hfrosccfg) == 0x0);
static_assert(offsetof(PRCI_regs, hfxosccfg) == 0x4);
static_assert(offsetof(PRCI_regs, pllcfg) == 0x8);
static_assert(offsetof(PRCI_regs, plloutdiv) == 0xc);
static_assert(offsetof(PRCI_regs, coreclkcfg) == 0x10);
}  // namespace deri::mmio
