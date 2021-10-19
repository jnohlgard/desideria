/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/FMC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for FMC WS
 *
 * wait state counter register
 */
enum class FMC_regs::WS_bits : uint32_t {
  WSCNT_mask = (0x7 << 0),    ///< wait state counter register
  Reserved_mask = 0xfffffff8  ///< All reserved bits
};
void HasBitwiseOperators(FMC_regs::WS_bits);

/**
 * Bit shifts for FMC WS
 */
enum class FMC_regs::WS_shift : unsigned {
  WSCNT = 0,
};

/**
 * Bitmasks for FMC KEY0
 *
 * Unlock key register 0
 */
enum class FMC_regs::KEY0_bits : uint32_t {
  KEY_mask = (0xffffffff << 0),  ///< FMC_CTL0 unlock key
};
void HasBitwiseOperators(FMC_regs::KEY0_bits);

/**
 * Bit shifts for FMC KEY0
 */
enum class FMC_regs::KEY0_shift : unsigned {
  KEY = 0,
};

/**
 * Bitmasks for FMC OBKEY
 *
 * Option byte unlock key register
 */
enum class FMC_regs::OBKEY_bits : uint32_t {
  OBKEY_mask =
      (0xffffffff << 0),  ///< FMC_ CTL0 option byte operation unlock register
};
void HasBitwiseOperators(FMC_regs::OBKEY_bits);

/**
 * Bit shifts for FMC OBKEY
 */
enum class FMC_regs::OBKEY_shift : unsigned {
  OBKEY = 0,
};

/**
 * Bitmasks for FMC STAT0
 *
 * Status register 0
 */
enum class FMC_regs::STAT0_bits : uint32_t {
  ENDF = (1 << 5),            ///< End of operation flag bit
  WPERR = (1 << 4),           ///< Erase/Program protection error flag bit
  PGERR = (1 << 2),           ///< Program error flag bit
  BUSY = (1 << 0),            ///< The flash is busy bit
  Reserved_mask = 0xffffffca  ///< All reserved bits
};
void HasBitwiseOperators(FMC_regs::STAT0_bits);

/**
 * Bit shifts for FMC STAT0
 */
enum class FMC_regs::STAT0_shift : unsigned {
  ENDF = 5,
  WPERR = 4,
  PGERR = 2,
  BUSY = 0,
};

/**
 * Bitmasks for FMC CTL0
 *
 * Control register 0
 */
enum class FMC_regs::CTL0_bits : uint32_t {
  ENDIE = (1 << 12),          ///< End of operation interrupt enable bit
  ERRIE = (1 << 10),          ///< Error interrupt enable bit
  OBWEN = (1 << 9),           ///< Option byte erase/program enable bit
  LK = (1 << 7),              ///< FMC_CTL0 lock bit
  START = (1 << 6),           ///< Send erase command to FMC bit
  OBER = (1 << 5),            ///< Option bytes erase command bit
  OBPG = (1 << 4),            ///< Option bytes program command bit
  MER = (1 << 2),             ///< Main flash mass erase for bank0 command bit
  PER = (1 << 1),             ///< Main flash page erase for bank0 command bit
  PG = (1 << 0),              ///< Main flash program for bank0 command bit
  Reserved_mask = 0xffffe908  ///< All reserved bits
};
void HasBitwiseOperators(FMC_regs::CTL0_bits);

/**
 * Bit shifts for FMC CTL0
 */
enum class FMC_regs::CTL0_shift : unsigned {
  ENDIE = 12,
  ERRIE = 10,
  OBWEN = 9,
  LK = 7,
  START = 6,
  OBER = 5,
  OBPG = 4,
  MER = 2,
  PER = 1,
  PG = 0,
};

/**
 * Bitmasks for FMC ADDR0
 *
 * Address register 0
 */
enum class FMC_regs::ADDR0_bits : uint32_t {
  ADDR_mask = (0xffffffff << 0),  ///< Flash erase/program command address bits
};
void HasBitwiseOperators(FMC_regs::ADDR0_bits);

/**
 * Bit shifts for FMC ADDR0
 */
enum class FMC_regs::ADDR0_shift : unsigned {
  ADDR = 0,
};

/**
 * Bitmasks for FMC OBSTAT
 *
 * Option byte status register
 */
enum class FMC_regs::OBSTAT_bits : uint32_t {
  OBERR = (1 << 0),  ///< Option bytes read error bit
  SPC = (1 << 1),    ///< Option bytes security protection code
  USER_mask =
      (0xff << 2),  ///< Store USER of option bytes block after system reset
  DATA_mask =
      (0xffff
       << 10),  ///< Store DATA[15:0] of option bytes block after system reset
  Reserved_mask = 0xfc000000  ///< All reserved bits
};
void HasBitwiseOperators(FMC_regs::OBSTAT_bits);

/**
 * Bit shifts for FMC OBSTAT
 */
enum class FMC_regs::OBSTAT_shift : unsigned {
  OBERR = 0,
  SPC = 1,
  USER = 2,
  DATA = 10,
};

/**
 * Bitmasks for FMC WP
 *
 * Erase/Program Protection register
 */
enum class FMC_regs::WP_bits : uint32_t {
  WP_mask =
      (0xffffffff
       << 0),  ///< Store WP[31:0] of option bytes block after system reset
};
void HasBitwiseOperators(FMC_regs::WP_bits);

/**
 * Bit shifts for FMC WP
 */
enum class FMC_regs::WP_shift : unsigned {
  WP = 0,
};

/**
 * Bitmasks for FMC PID
 *
 * Product ID register
 */
enum class FMC_regs::PID_bits : uint32_t {
  PID_mask = (0xffffffff << 0),  ///< Product reserved ID code register
};
void HasBitwiseOperators(FMC_regs::PID_bits);

/**
 * Bit shifts for FMC PID
 */
enum class FMC_regs::PID_shift : unsigned {
  PID = 0,
};

static_assert(offsetof(FMC_regs, WS) == 0x0);
static_assert(offsetof(FMC_regs, KEY0) == 0x4);
static_assert(offsetof(FMC_regs, OBKEY) == 0x8);
static_assert(offsetof(FMC_regs, STAT0) == 0xc);
static_assert(offsetof(FMC_regs, CTL0) == 0x10);
static_assert(offsetof(FMC_regs, ADDR0) == 0x14);
static_assert(offsetof(FMC_regs, OBSTAT) == 0x1c);
static_assert(offsetof(FMC_regs, WP) == 0x20);
static_assert(offsetof(FMC_regs, PID) == 0x100);
}  // namespace deri::mmio
