/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/QSPI.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for QSPI sckdiv
 *
 * Serial Clock Divisor Register
 */
enum class QSPI_regs::sckdiv_bits : uint32_t {
  div_mask = (0xfffu << 0),   ///< Divisor for serial clock
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::sckdiv_bits);

/**
 * Bit shifts for QSPI sckdiv
 */
enum class QSPI_regs::sckdiv_shift : unsigned {
  div = 0,
};

/**
 * Bitmasks for QSPI sckmode
 *
 * Serial Clock Mode Register
 */
enum class QSPI_regs::sckmode_bits : uint32_t {
  pol = (1u << 1),            ///< Serial clock polarity
  pha = (1u << 0),            ///< Serial clock phase
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::sckmode_bits);

/**
 * Bit shifts for QSPI sckmode
 */
enum class QSPI_regs::sckmode_shift : unsigned {
  pol = 1,
  pha = 0,
};

/**
 * Bitmasks for QSPI csid
 *
 * Chip Select ID Register
 */
enum class QSPI_regs::csid_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::csid_bits);

/**
 * Bit shifts for QSPI csid
 */
enum class QSPI_regs::csid_shift : unsigned {};

/**
 * Bitmasks for QSPI csdef
 *
 * Chip Select Default Register
 */
enum class QSPI_regs::csdef_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::csdef_bits);

/**
 * Bit shifts for QSPI csdef
 */
enum class QSPI_regs::csdef_shift : unsigned {};

/**
 * Bitmasks for QSPI csmode
 *
 * Chip Select Mode Register
 */
enum class QSPI_regs::csmode_bits : uint32_t {
  mode_mask = (0x3u << 0),    ///< Chip select mode
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::csmode_bits);

/**
 * Bit shifts for QSPI csmode
 */
enum class QSPI_regs::csmode_shift : unsigned {
  mode = 0,
};

/**
 * Bitmasks for QSPI delay0
 *
 * Delay Control 0 Register
 */
enum class QSPI_regs::delay0_bits : uint32_t {
  sckcs_mask = (0xffu << 16),  ///< SCK to CS Delay
  cssck_mask = (0xffu << 0),   ///< CS to SCK Delay
  Reserved_mask = 0xff00ff00   ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::delay0_bits);

/**
 * Bit shifts for QSPI delay0
 */
enum class QSPI_regs::delay0_shift : unsigned {
  sckcs = 16,
  cssck = 0,
};

/**
 * Bitmasks for QSPI delay1
 *
 * Delay Control 1 Register
 */
enum class QSPI_regs::delay1_bits : uint32_t {
  interxfr_mask = (0xffu << 16),  ///< Maximum interframe delay
  intercs_mask = (0xffu << 0),    ///< Minimum CS inactive time
  Reserved_mask = 0xff00ff00      ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::delay1_bits);

/**
 * Bit shifts for QSPI delay1
 */
enum class QSPI_regs::delay1_shift : unsigned {
  interxfr = 16,
  intercs = 0,
};

/**
 * Bitmasks for QSPI fmt
 *
 * Frame Format Register
 */
enum class QSPI_regs::fmt_bits : uint32_t {
  len_mask = (0xfu << 16),    ///< Number of bits per frame
  dir = (1u << 3),            ///< SPI I/O direction
  endian = (1u << 2),         ///< SPI endianness
  proto_mask = (0x3u << 0),   ///< SPI protocol
  Reserved_mask = 0xfff0fff0  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::fmt_bits);

/**
 * Bit shifts for QSPI fmt
 */
enum class QSPI_regs::fmt_shift : unsigned {
  len = 16,
  dir = 3,
  endian = 2,
  proto = 0,
};

/**
 * Bitmasks for QSPI txdata
 *
 * Transmit Data Register
 */
enum class QSPI_regs::txdata_bits : uint32_t {
  full = (1u << 31),          ///< FIFO full flag
  data_mask = (0xffu << 0),   ///< Transmit data
  Reserved_mask = 0x7fffff00  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::txdata_bits);

/**
 * Bit shifts for QSPI txdata
 */
enum class QSPI_regs::txdata_shift : unsigned {
  full = 31,
  data = 0,
};

/**
 * Bitmasks for QSPI rxdata
 *
 * Receive Data Register
 */
enum class QSPI_regs::rxdata_bits : uint32_t {
  empty = (1u << 31),         ///< FIFO empty flag
  data_mask = (0xffu << 0),   ///< Received data
  Reserved_mask = 0x7fffff00  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::rxdata_bits);

/**
 * Bit shifts for QSPI rxdata
 */
enum class QSPI_regs::rxdata_shift : unsigned {
  empty = 31,
  data = 0,
};

/**
 * Bitmasks for QSPI txmark
 *
 * Transmit Watermark Register
 */
enum class QSPI_regs::txmark_bits : uint32_t {
  txmark_mask = (0x7u << 0),  ///< Transmit watermark
  Reserved_mask = 0xfffffff8  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::txmark_bits);

/**
 * Bit shifts for QSPI txmark
 */
enum class QSPI_regs::txmark_shift : unsigned {
  txmark = 0,
};

/**
 * Bitmasks for QSPI rxmark
 *
 * Receive Watermark Register
 */
enum class QSPI_regs::rxmark_bits : uint32_t {
  rxmark_mask = (0x7u << 0),  ///< Receive watermark
  Reserved_mask = 0xfffffff8  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::rxmark_bits);

/**
 * Bit shifts for QSPI rxmark
 */
enum class QSPI_regs::rxmark_shift : unsigned {
  rxmark = 0,
};

/**
 * Bitmasks for QSPI fctrl
 *
 * SPI Flash Interface Control Register
 */
enum class QSPI_regs::fctrl_bits : uint32_t {
  en = (1u << 0),             ///< SPI Flash Mode Select
  Reserved_mask = 0xfffffffe  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::fctrl_bits);

/**
 * Bit shifts for QSPI fctrl
 */
enum class QSPI_regs::fctrl_shift : unsigned {
  en = 0,
};

/**
 * Bitmasks for QSPI ffmt
 *
 * SPI Flash Instruction Format Register
 */
enum class QSPI_regs::ffmt_bits : uint32_t {
  pad_code_mask =
      (0xffu << 24),  ///< First 8 bits to transmit during dummy cycles
  cmd_code_mask = (0xffu << 16),   ///< Value of command byte
  data_proto_mask = (0x3u << 12),  ///< Protocol for receiving data bytes
  addr_proto_mask =
      (0x3u << 10),  ///< Protocol for transmitting address and padding
  cmd_proto_mask = (0x3u << 8),  ///< Protocol for transmitting command
  pad_cnt_mask = (0xfu << 4),    ///< Number of dummy cycles
  addr_len_mask = (0x7u << 1),   ///< Number of address bytes (0 to 4)
  cmd_en = (1u << 0),            ///< Enable sending of command
  Reserved_mask = 0x0000c000     ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::ffmt_bits);

/**
 * Bit shifts for QSPI ffmt
 */
enum class QSPI_regs::ffmt_shift : unsigned {
  pad_code = 24,
  cmd_code = 16,
  data_proto = 12,
  addr_proto = 10,
  cmd_proto = 8,
  pad_cnt = 4,
  addr_len = 1,
  cmd_en = 0,
};

/**
 * Bitmasks for QSPI ie
 *
 * SPI Interrupt Enable Register
 */
enum class QSPI_regs::ie_bits : uint32_t {
  rxwm = (1u << 1),           ///< Receive watermark enable
  txwm = (1u << 0),           ///< Transmit watermark enable
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::ie_bits);

/**
 * Bit shifts for QSPI ie
 */
enum class QSPI_regs::ie_shift : unsigned {
  rxwm = 1,
  txwm = 0,
};

/**
 * Bitmasks for QSPI ip
 *
 * SPI Interrupt Pending Register
 */
enum class QSPI_regs::ip_bits : uint32_t {
  rxwm = (1u << 1),           ///< Receive watermark enable
  txwm = (1u << 0),           ///< Transmit watermark enable
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(QSPI_regs::ip_bits);

/**
 * Bit shifts for QSPI ip
 */
enum class QSPI_regs::ip_shift : unsigned {
  rxwm = 1,
  txwm = 0,
};

static_assert(offsetof(QSPI_regs, sckdiv) == 0x0);
static_assert(offsetof(QSPI_regs, sckmode) == 0x4);
static_assert(offsetof(QSPI_regs, csid) == 0x10);
static_assert(offsetof(QSPI_regs, csdef) == 0x14);
static_assert(offsetof(QSPI_regs, csmode) == 0x18);
static_assert(offsetof(QSPI_regs, delay0) == 0x28);
static_assert(offsetof(QSPI_regs, delay1) == 0x2c);
static_assert(offsetof(QSPI_regs, fmt) == 0x40);
static_assert(offsetof(QSPI_regs, txdata) == 0x48);
static_assert(offsetof(QSPI_regs, rxdata) == 0x4c);
static_assert(offsetof(QSPI_regs, txmark) == 0x50);
static_assert(offsetof(QSPI_regs, rxmark) == 0x54);
static_assert(offsetof(QSPI_regs, fctrl) == 0x60);
static_assert(offsetof(QSPI_regs, ffmt) == 0x64);
static_assert(offsetof(QSPI_regs, ie) == 0x70);
static_assert(offsetof(QSPI_regs, ip) == 0x74);
}  // namespace deri::mmio
