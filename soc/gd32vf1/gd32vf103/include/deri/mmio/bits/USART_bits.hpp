/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/USART.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for USART STAT
 *
 * Status register
 */
enum class USART_regs::STAT_bits : uint32_t {
  CTSF = (1 << 9),            ///< CTS change flag
  LBDF = (1 << 8),            ///< LIN break detection flag
  TBE = (1 << 7),             ///< Transmit data buffer empty
  TC = (1 << 6),              ///< Transmission complete
  RBNE = (1 << 5),            ///< Read data buffer not empty
  IDLEF = (1 << 4),           ///< IDLE frame detected flag
  ORERR = (1 << 3),           ///< Overrun error
  NERR = (1 << 2),            ///< Noise error flag
  FERR = (1 << 1),            ///< Frame error flag
  PERR = (1 << 0),            ///< Parity error flag
  Reserved_mask = 0xfffffc00  ///< All reserved bits
};
void HasBitwiseOperators(USART_regs::STAT_bits);

/**
 * Bit shifts for USART STAT
 */
enum class USART_regs::STAT_shift : unsigned {
  CTSF = 9,
  LBDF = 8,
  TBE = 7,
  TC = 6,
  RBNE = 5,
  IDLEF = 4,
  ORERR = 3,
  NERR = 2,
  FERR = 1,
  PERR = 0,
};

/**
 * Bitmasks for USART DATA
 *
 * Data register
 */
enum class USART_regs::DATA_bits : uint32_t {
  DATA_mask = (0x1ff << 0),   ///< Transmit or read data value
  Reserved_mask = 0xfffffe00  ///< All reserved bits
};
void HasBitwiseOperators(USART_regs::DATA_bits);

/**
 * Bit shifts for USART DATA
 */
enum class USART_regs::DATA_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for USART BAUD
 *
 * Baud rate register
 */
enum class USART_regs::BAUD_bits : uint32_t {
  INTDIV_mask = (0xfff << 4),  ///< Integer part of baud-rate divider
  FRADIV_mask = (0xf << 0),    ///< Fraction part of baud-rate divider
  Reserved_mask = 0xffff0000   ///< All reserved bits
};
void HasBitwiseOperators(USART_regs::BAUD_bits);

/**
 * Bit shifts for USART BAUD
 */
enum class USART_regs::BAUD_shift : unsigned {
  INTDIV = 4,
  FRADIV = 0,
};

/**
 * Bitmasks for USART CTL0
 *
 * Control register 0
 */
enum class USART_regs::CTL0_bits : uint32_t {
  UEN = (1 << 13),    ///< USART enable
  WL = (1 << 12),     ///< Word length
  WM = (1 << 11),     ///< Wakeup method in mute mode
  PCEN = (1 << 10),   ///< Parity check function enable
  PM = (1 << 9),      ///< Parity mode
  PERRIE = (1 << 8),  ///< Parity error interrupt enable
  TBEIE = (1 << 7),   ///< Transmitter buffer empty interrupt enable
  TCIE = (1 << 6),    ///< Transmission complete interrupt enable
  RBNEIE = (1 << 5),  ///< Read data buffer not empty interrupt and overrun
                      ///< error interrupt enable
  IDLEIE = (1 << 4),  ///< IDLE line detected interrupt enable
  TEN = (1 << 3),     ///< Transmitter enable
  REN = (1 << 2),     ///< Receiver enable
  RWU = (1 << 1),     ///< Receiver wakeup from mute mode
  SBKCMD = (1 << 0),  ///< Send break command
  Reserved_mask = 0xffffc000  ///< All reserved bits
};
void HasBitwiseOperators(USART_regs::CTL0_bits);

/**
 * Bit shifts for USART CTL0
 */
enum class USART_regs::CTL0_shift : unsigned {
  UEN = 13,
  WL = 12,
  WM = 11,
  PCEN = 10,
  PM = 9,
  PERRIE = 8,
  TBEIE = 7,
  TCIE = 6,
  RBNEIE = 5,
  IDLEIE = 4,
  TEN = 3,
  REN = 2,
  RWU = 1,
  SBKCMD = 0,
};

/**
 * Bitmasks for USART CTL1
 *
 * Control register 1
 */
enum class USART_regs::CTL1_bits : uint32_t {
  LMEN = (1 << 14),           ///< LIN mode enable
  STB_mask = (0x3 << 12),     ///< STOP bits length
  CKEN = (1 << 11),           ///< CK pin enable
  CPL = (1 << 10),            ///< Clock polarity
  CPH = (1 << 9),             ///< Clock phase
  CLEN = (1 << 8),            ///< CK Length
  LBDIE = (1 << 6),           ///< LIN break detection interrupt enable
  LBLEN = (1 << 5),           ///< LIN break frame length
  ADDR_mask = (0xf << 0),     ///< Address of the USART
  Reserved_mask = 0xffff8090  ///< All reserved bits
};
void HasBitwiseOperators(USART_regs::CTL1_bits);

/**
 * Bit shifts for USART CTL1
 */
enum class USART_regs::CTL1_shift : unsigned {
  LMEN = 14,
  STB = 12,
  CKEN = 11,
  CPL = 10,
  CPH = 9,
  CLEN = 8,
  LBDIE = 6,
  LBLEN = 5,
  ADDR = 0,
};

/**
 * Bitmasks for USART CTL2
 *
 * Control register 2
 */
enum class USART_regs::CTL2_bits : uint32_t {
  CTSIE = (1 << 10),          ///< CTS interrupt enable
  CTSEN = (1 << 9),           ///< CTS enable
  RTSEN = (1 << 8),           ///< RTS enable
  DENT = (1 << 7),            ///< DMA request enable for transmission
  DENR = (1 << 6),            ///< DMA request enable for reception
  SCEN = (1 << 5),            ///< Smartcard mode enable
  NKEN = (1 << 4),            ///< Smartcard NACK enable
  HDEN = (1 << 3),            ///< Half-duplex selection
  IRLP = (1 << 2),            ///< IrDA low-power
  IREN = (1 << 1),            ///< IrDA mode enable
  ERRIE = (1 << 0),           ///< Error interrupt enable
  Reserved_mask = 0xfffff800  ///< All reserved bits
};
void HasBitwiseOperators(USART_regs::CTL2_bits);

/**
 * Bit shifts for USART CTL2
 */
enum class USART_regs::CTL2_shift : unsigned {
  CTSIE = 10,
  CTSEN = 9,
  RTSEN = 8,
  DENT = 7,
  DENR = 6,
  SCEN = 5,
  NKEN = 4,
  HDEN = 3,
  IRLP = 2,
  IREN = 1,
  ERRIE = 0,
};

/**
 * Bitmasks for USART GP
 *
 * Guard time and prescaler register
 */
enum class USART_regs::GP_bits : uint32_t {
  GUAT_mask = (0xff << 8),    ///< Guard time value in Smartcard mode
  PSC_mask = (0xff << 0),     ///< Prescaler value
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(USART_regs::GP_bits);

/**
 * Bit shifts for USART GP
 */
enum class USART_regs::GP_shift : unsigned {
  GUAT = 8,
  PSC = 0,
};

static_assert(offsetof(USART_regs, STAT) == 0x0);
static_assert(offsetof(USART_regs, DATA) == 0x4);
static_assert(offsetof(USART_regs, BAUD) == 0x8);
static_assert(offsetof(USART_regs, CTL0) == 0xc);
static_assert(offsetof(USART_regs, CTL1) == 0x10);
static_assert(offsetof(USART_regs, CTL2) == 0x14);
static_assert(offsetof(USART_regs, GP) == 0x18);
}  // namespace deri::mmio
