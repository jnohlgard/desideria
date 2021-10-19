/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/CRC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for CRC DATA
 *
 * Data register
 */
enum class CRC_regs::DATA_bits : uint32_t {
  DATA_mask = (0xffffffff << 0),  ///< CRC calculation result bits
};
void HasBitwiseOperators(CRC_regs::DATA_bits);

/**
 * Bit shifts for CRC DATA
 */
enum class CRC_regs::DATA_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for CRC FDATA
 *
 * Free data register
 */
enum class CRC_regs::FDATA_bits : uint32_t {
  FDATA_mask = (0xff << 0),   ///< Free Data Register bits
  Reserved_mask = 0xffffff00  ///< All reserved bits
};
void HasBitwiseOperators(CRC_regs::FDATA_bits);

/**
 * Bit shifts for CRC FDATA
 */
enum class CRC_regs::FDATA_shift : unsigned {
  FDATA = 0,
};

/**
 * Bitmasks for CRC CTL
 *
 * Control register
 */
enum class CRC_regs::CTL_bits : uint32_t {
  RST = (1 << 0),             ///< reset bit
  Reserved_mask = 0xfffffffe  ///< All reserved bits
};
void HasBitwiseOperators(CRC_regs::CTL_bits);

/**
 * Bit shifts for CRC CTL
 */
enum class CRC_regs::CTL_shift : unsigned {
  RST = 0,
};

static_assert(offsetof(CRC_regs, DATA) == 0x0);
static_assert(offsetof(CRC_regs, FDATA) == 0x4);
static_assert(offsetof(CRC_regs, CTL) == 0x8);
}  // namespace deri::mmio
