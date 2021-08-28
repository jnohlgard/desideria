/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/bitwise_enums.h"

#include <cstdint>

namespace deri::dev::gd32::usart {

enum class STAT_bits : uint32_t {
  CTSF = (1 << 9),   ///< CTS change flag
  LBDF = (1 << 8),   ///< LIN break detected flag
  TBE = (1 << 7),    ///< Transmit data buffer empty
  TC = (1 << 6),     ///< Transmission complete
  RBNE = (1 << 5),   ///< Read data buffer not empty
  IDLEF = (1 << 4),  ///< IDLE frame detected flag
  ORERR = (1 << 3),  ///< Overrun error flag
  NERR = (1 << 2),   ///< Noise error flag
  FERR = (1 << 1),   ///< Frame error flag
  PERR = (1 << 0),   ///< Parity error flag
};
void HasBitwiseOperators(STAT_bits);

enum class DATA_bits : uint32_t {
  DATA_mask = (0b1'1111'1111 << 0),  ///< Transmitted or received data value
  Reserved_mask = (~0u << 8),        ///< All reserved bits selected
};
void HasBitwiseOperators(DATA_bits);

enum class BAUD_bits : uint32_t {
  INTDIV_mask = (0xfff0),
  FRADIV_mask = (0x000f),
  Reserved_mask = (~0u << 16),  ///< All reserved bits selected
};
void HasBitwiseOperators(BAUD_bits);

enum class CTL0_bits : uint32_t {
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
  IDLEIE = (1 << 4),            ///< IDLE line detected interrupt enable
  TEN = (1 << 3),               ///< Transmitter enable
  REN = (1 << 2),               ///< Receiver enable
  RWU = (1 << 1),               ///< Receiver wakes up from mute mode
  SBC = (1 << 0),               ///< Send break command
  Reserved_mask = (~0u << 13),  ///< All reserved bits selected
};
void HasBitwiseOperators(CTL0_bits);

enum class CTL1_bits : uint32_t {
  LMEN = (1 << 14),           ///< LIN mode enable
  STB_mask = (0b11 << 12),    ///< Stop bits length
  CKEN = (1 << 11),           ///< CK pin enable
  CPL = (1 << 10),            ///< CK polarity
  CPH = (1 << 9),             ///< CK phase
  CLEN = (1 << 8),            ///< CK length
  Reserved7 = (1 << 7),       ///< Reserved, must be kept at reset value
  LBDIE = (1 << 6),           ///< LIN break detection interrupt enable
  LBLEN = (1 << 5),           ///< LIN break length
  Reserved4 = (1 << 4),       ///< Reserved, must be kept at reset value
  ADDR_mask = (0b1111 << 0),  ///< Address of the USART
  Reserved_mask =
      (~0u << 14) | Reserved7 | Reserved4,  ///< All reserved bits selected
};
void HasBitwiseOperators(CTL1_bits);

enum class CTL2_bits : uint32_t {
  CTSIE = (1 << 10),            ///< CTS interrupt enable
  CTSEN = (1 << 9),             ///< CTS enable
  RTSEN = (1 << 8),             ///< RTS enable
  DENT = (1 << 7),              ///< DMA request enable for transmission
  DENR = (1 << 6),              ///< DMA request enable for reception
  SCEN = (1 << 5),              ///< Smartcard mode enable
  NKEN = (1 << 4),              ///< NACK enable in Smartcard mode
  HDEN = (1 << 3),              ///< Half-duplex enable
  IRLP = (1 << 2),              ///< IrDA low power
  IREN = (1 << 1),              ///< IrDA mode enable
  ERRIE = (1 << 0),             ///< Error interrupt enable
  Reserved_mask = (~0u << 10),  ///< All reserved bits selected
};
void HasBitwiseOperators(CTL2_bits);

enum class GP_bits : uint32_t {
  GUAT_mask = (0xff00),         ///< Guard time value in Smartcard mode
  PSC_mask = (0x00ff),          ///< Division factor in IrDA low-power mode
  Reserved_mask = (~0u << 16),  ///< All reserved bits selected
};
void HasBitwiseOperators(GP_bits);

}  // namespace deri::dev::gd32::usart
