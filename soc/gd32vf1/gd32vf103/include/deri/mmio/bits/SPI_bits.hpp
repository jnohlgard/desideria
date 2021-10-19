/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/SPI.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for SPI CTL0
 *
 * control register 0
 */
enum class SPI_regs::CTL0_bits : uint16_t {
  BDEN = (1 << 15),       ///< Bidirectional enable
  BDOEN = (1 << 14),      ///< Bidirectional Transmit output enable
  CRCEN = (1 << 13),      ///< CRC Calculation Enable
  CRCNT = (1 << 12),      ///< CRC Next Transfer
  FF16 = (1 << 11),       ///< Data frame format
  RO = (1 << 10),         ///< Receive only
  SWNSSEN = (1 << 9),     ///< NSS Software Mode Selection
  SWNSS = (1 << 8),       ///< NSS Pin Selection In NSS Software Mode
  LF = (1 << 7),          ///< LSB First Mode
  SPIEN = (1 << 6),       ///< SPI enable
  PSC_mask = (0x7 << 3),  ///< Master Clock Prescaler Selection
  MSTMOD = (1 << 2),      ///< Master Mode Enable
  CKPL = (1 << 1),        ///< Clock polarity Selection
  CKPH = (1 << 0),        ///< Clock Phase Selection
};
void HasBitwiseOperators(SPI_regs::CTL0_bits);

/**
 * Bit shifts for SPI CTL0
 */
enum class SPI_regs::CTL0_shift : unsigned {
  BDEN = 15,
  BDOEN = 14,
  CRCEN = 13,
  CRCNT = 12,
  FF16 = 11,
  RO = 10,
  SWNSSEN = 9,
  SWNSS = 8,
  LF = 7,
  SPIEN = 6,
  PSC = 3,
  MSTMOD = 2,
  CKPL = 1,
  CKPH = 0,
};

/**
 * Bitmasks for SPI CTL1
 *
 * control register 1
 */
enum class SPI_regs::CTL1_bits : uint16_t {
  TBEIE = (1 << 7),       ///< Tx buffer empty interrupt enable
  RBNEIE = (1 << 6),      ///< RX buffer not empty interrupt enable
  ERRIE = (1 << 5),       ///< Error interrupt enable
  TMOD = (1 << 4),        ///< SPI TI mode enable
  NSSP = (1 << 3),        ///< SPI NSS pulse mode enable
  NSSDRV = (1 << 2),      ///< Drive NSS Output
  DMATEN = (1 << 1),      ///< Transmit Buffer DMA Enable
  DMAREN = (1 << 0),      ///< Rx buffer DMA enable
  Reserved_mask = 0xff00  ///< All reserved bits
};
void HasBitwiseOperators(SPI_regs::CTL1_bits);

/**
 * Bit shifts for SPI CTL1
 */
enum class SPI_regs::CTL1_shift : unsigned {
  TBEIE = 7,
  RBNEIE = 6,
  ERRIE = 5,
  TMOD = 4,
  NSSP = 3,
  NSSDRV = 2,
  DMATEN = 1,
  DMAREN = 0,
};

/**
 * Bitmasks for SPI STAT
 *
 * status register
 */
enum class SPI_regs::STAT_bits : uint16_t {
  FERR = (1 << 8),        ///< Format error
  TRANS = (1 << 7),       ///< Transmitting On-going Bit
  RXORERR = (1 << 6),     ///< Reception Overrun Error Bit
  CONFERR = (1 << 5),     ///< SPI Configuration error
  CRCERR = (1 << 4),      ///< SPI CRC Error Bit
  TXURERR = (1 << 3),     ///< Transmission underrun error bit
  I2SCH = (1 << 2),       ///< I2S channel side
  TBE = (1 << 1),         ///< Transmit Buffer Empty
  RBNE = (1 << 0),        ///< Receive Buffer Not Empty
  Reserved_mask = 0xfe00  ///< All reserved bits
};
void HasBitwiseOperators(SPI_regs::STAT_bits);

/**
 * Bit shifts for SPI STAT
 */
enum class SPI_regs::STAT_shift : unsigned {
  FERR = 8,
  TRANS = 7,
  RXORERR = 6,
  CONFERR = 5,
  CRCERR = 4,
  TXURERR = 3,
  I2SCH = 2,
  TBE = 1,
  RBNE = 0,
};

/**
 * Bitmasks for SPI DATA
 *
 * data register
 */
enum class SPI_regs::DATA_bits : uint16_t {
  SPI_DATA_mask = (0xffff << 0),  ///< Data transfer register
};
void HasBitwiseOperators(SPI_regs::DATA_bits);

/**
 * Bit shifts for SPI DATA
 */
enum class SPI_regs::DATA_shift : unsigned {
  SPI_DATA = 0,
};

/**
 * Bitmasks for SPI CRCPOLY
 *
 * CRC polynomial register
 */
enum class SPI_regs::CRCPOLY_bits : uint16_t {
  CRCPOLY_mask = (0xffff << 0),  ///< CRC polynomial value
};
void HasBitwiseOperators(SPI_regs::CRCPOLY_bits);

/**
 * Bit shifts for SPI CRCPOLY
 */
enum class SPI_regs::CRCPOLY_shift : unsigned {
  CRCPOLY = 0,
};

/**
 * Bitmasks for SPI RCRC
 *
 * RX CRC register
 */
enum class SPI_regs::RCRC_bits : uint16_t {
  RCRC_mask = (0xffff << 0),  ///< RX CRC value
};
void HasBitwiseOperators(SPI_regs::RCRC_bits);

/**
 * Bit shifts for SPI RCRC
 */
enum class SPI_regs::RCRC_shift : unsigned {
  RCRC = 0,
};

/**
 * Bitmasks for SPI TCRC
 *
 * TX CRC register
 */
enum class SPI_regs::TCRC_bits : uint16_t {
  TCRC_mask = (0xffff << 0),  ///< Tx CRC value
};
void HasBitwiseOperators(SPI_regs::TCRC_bits);

/**
 * Bit shifts for SPI TCRC
 */
enum class SPI_regs::TCRC_shift : unsigned {
  TCRC = 0,
};

/**
 * Bitmasks for SPI I2SCTL
 *
 * I2S control register
 */
enum class SPI_regs::I2SCTL_bits : uint16_t {
  I2SSEL = (1 << 11),          ///< I2S mode selection
  I2SEN = (1 << 10),           ///< I2S Enable
  I2SOPMOD_mask = (0x3 << 8),  ///< I2S operation mode
  PCMSMOD = (1 << 7),          ///< PCM frame synchronization mode
  I2SSTD_mask = (0x3 << 4),    ///< I2S standard selection
  CKPL = (1 << 3),             ///< Idle state clock polarity
  DTLEN_mask = (0x3 << 1),     ///< Data length
  CHLEN = (1 << 0),       ///< Channel length (number of bits per audio channel)
  Reserved_mask = 0xf040  ///< All reserved bits
};
void HasBitwiseOperators(SPI_regs::I2SCTL_bits);

/**
 * Bit shifts for SPI I2SCTL
 */
enum class SPI_regs::I2SCTL_shift : unsigned {
  I2SSEL = 11,
  I2SEN = 10,
  I2SOPMOD = 8,
  PCMSMOD = 7,
  I2SSTD = 4,
  CKPL = 3,
  DTLEN = 1,
  CHLEN = 0,
};

/**
 * Bitmasks for SPI I2SPSC
 *
 * I2S prescaler register
 */
enum class SPI_regs::I2SPSC_bits : uint16_t {
  MCKOEN = (1 << 9),       ///< I2S_MCK output enable
  OF = (1 << 8),           ///< Odd factor for the prescaler
  DIV_mask = (0xff << 0),  ///< Dividing factor for the prescaler
  Reserved_mask = 0xfc00   ///< All reserved bits
};
void HasBitwiseOperators(SPI_regs::I2SPSC_bits);

/**
 * Bit shifts for SPI I2SPSC
 */
enum class SPI_regs::I2SPSC_shift : unsigned {
  MCKOEN = 9,
  OF = 8,
  DIV = 0,
};

static_assert(offsetof(SPI_regs, CTL0) == 0x0);
static_assert(offsetof(SPI_regs, CTL1) == 0x4);
static_assert(offsetof(SPI_regs, STAT) == 0x8);
static_assert(offsetof(SPI_regs, DATA) == 0xc);
static_assert(offsetof(SPI_regs, CRCPOLY) == 0x10);
static_assert(offsetof(SPI_regs, RCRC) == 0x14);
static_assert(offsetof(SPI_regs, TCRC) == 0x18);
static_assert(offsetof(SPI_regs, I2SCTL) == 0x1c);
static_assert(offsetof(SPI_regs, I2SPSC) == 0x20);
}  // namespace deri::mmio
