/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/EXMC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for EXMC SNCTL0
 *
 * SRAM/NOR flash control register 0
 */
enum class EXMC_regs::SNCTL0_bits : uint32_t {
  ASYNCWAIT = (1 << 15),      ///< Asynchronous wait
  NRWTEN = (1 << 13),         ///< NWAIT signal enable
  WREN = (1 << 12),           ///< Write enable
  NRWTPOL = (1 << 9),         ///< NWAIT signal polarity
  NREN = (1 << 6),            ///< NOR Flash access enable
  NRW_mask = (0x3 << 4),      ///< NOR bank memory data bus width
  NRTP_mask = (0x3 << 2),     ///< NOR bank memory type
  NRMUX = (1 << 1),           ///< NOR bank memory address/data multiplexing
  NRBKEN = (1 << 0),          ///< NOR bank enable
  Reserved_mask = 0xffff4d80  ///< All reserved bits
};
void HasBitwiseOperators(EXMC_regs::SNCTL0_bits);

/**
 * Bit shifts for EXMC SNCTL0
 */
enum class EXMC_regs::SNCTL0_shift : unsigned {
  ASYNCWAIT = 15,
  NRWTEN = 13,
  WREN = 12,
  NRWTPOL = 9,
  NREN = 6,
  NRW = 4,
  NRTP = 2,
  NRMUX = 1,
  NRBKEN = 0,
};

/**
 * Bitmasks for EXMC SNTCFG0
 *
 * SRAM/NOR flash timing configuration register 0
 */
enum class EXMC_regs::SNTCFG0_bits : uint32_t {
  BUSLAT_mask = (0xf << 16),  ///< Bus latency
  DSET_mask = (0xff << 8),    ///< Data setup time
  AHLD_mask = (0xf << 4),     ///< Address hold time
  ASET_mask = (0xf << 0),     ///< Address setup time
  Reserved_mask = 0xfff00000  ///< All reserved bits
};
void HasBitwiseOperators(EXMC_regs::SNTCFG0_bits);

/**
 * Bit shifts for EXMC SNTCFG0
 */
enum class EXMC_regs::SNTCFG0_shift : unsigned {
  BUSLAT = 16,
  DSET = 8,
  AHLD = 4,
  ASET = 0,
};

/**
 * Bitmasks for EXMC SNCTL1
 *
 * SRAM/NOR flash control register 1
 */
enum class EXMC_regs::SNCTL1_bits : uint32_t {
  ASYNCWAIT = (1 << 15),      ///< Asynchronous wait
  NRWTEN = (1 << 13),         ///< NWAIT signal enable
  WREN = (1 << 12),           ///< Write enable
  NRWTPOL = (1 << 9),         ///< NWAIT signal polarity
  NREN = (1 << 6),            ///< NOR Flash access enable
  NRW_mask = (0x3 << 4),      ///< NOR bank memory data bus width
  NRTP_mask = (0x3 << 2),     ///< NOR bank memory type
  NRMUX = (1 << 1),           ///< NOR bank memory address/data multiplexing
  NRBKEN = (1 << 0),          ///< NOR bank enable
  Reserved_mask = 0xffff4d80  ///< All reserved bits
};
void HasBitwiseOperators(EXMC_regs::SNCTL1_bits);

/**
 * Bit shifts for EXMC SNCTL1
 */
enum class EXMC_regs::SNCTL1_shift : unsigned {
  ASYNCWAIT = 15,
  NRWTEN = 13,
  WREN = 12,
  NRWTPOL = 9,
  NREN = 6,
  NRW = 4,
  NRTP = 2,
  NRMUX = 1,
  NRBKEN = 0,
};

static_assert(offsetof(EXMC_regs, SNCTL0) == 0x0);
static_assert(offsetof(EXMC_regs, SNTCFG0) == 0x4);
static_assert(offsetof(EXMC_regs, SNCTL1) == 0x8);
}  // namespace deri::mmio
