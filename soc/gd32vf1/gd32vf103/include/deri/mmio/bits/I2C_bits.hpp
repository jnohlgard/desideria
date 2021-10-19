/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/I2C.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for I2C CTL0
 *
 * Control register 0
 */
enum class I2C_regs::CTL0_bits : uint16_t {
  SRESET = (1 << 15),    ///< Software reset
  SALT = (1 << 13),      ///< SMBus alert
  PECTRANS = (1 << 12),  ///< PEC Transfer
  POAP = (1 << 11),      ///< Position of ACK and PEC when receiving
  ACKEN = (1 << 10),     ///< Whether or not to send an ACK
  STOP = (1 << 9),       ///< Generate a STOP condition on I2C bus
  START = (1 << 8),      ///< Generate a START condition on I2C bus
  SS = (1 << 7),      ///< Whether to stretch SCL low when data is not ready in
                      ///< slave mode
  GCEN = (1 << 6),    ///< Whether or not to response to a General Call (0x00)
  PECEN = (1 << 5),   ///< PEC Calculation Switch
  ARPEN = (1 << 4),   ///< ARP protocol in SMBus switch
  SMBSEL = (1 << 3),  ///< SMBusType Selection
  SMBEN = (1 << 1),   ///< SMBus/I2C mode switch
  I2CEN = (1 << 0),   ///< I2C peripheral enable
  Reserved_mask = 0x4004  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::CTL0_bits);

/**
 * Bit shifts for I2C CTL0
 */
enum class I2C_regs::CTL0_shift : unsigned {
  SRESET = 15,
  SALT = 13,
  PECTRANS = 12,
  POAP = 11,
  ACKEN = 10,
  STOP = 9,
  START = 8,
  SS = 7,
  GCEN = 6,
  PECEN = 5,
  ARPEN = 4,
  SMBSEL = 3,
  SMBEN = 1,
  I2CEN = 0,
};

/**
 * Bitmasks for I2C CTL1
 *
 * Control register 1
 */
enum class I2C_regs::CTL1_bits : uint16_t {
  DMALST = (1 << 12),         ///< Flag indicating DMA last transfer
  DMAON = (1 << 11),          ///< DMA mode switch
  BUFIE = (1 << 10),          ///< Buffer interrupt enable
  EVIE = (1 << 9),            ///< Event interrupt enable
  ERRIE = (1 << 8),           ///< Error interrupt enable
  I2CCLK_mask = (0x3f << 0),  ///< I2C Peripheral clock frequency
  Reserved_mask = 0xe0c0      ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::CTL1_bits);

/**
 * Bit shifts for I2C CTL1
 */
enum class I2C_regs::CTL1_shift : unsigned {
  DMALST = 12,
  DMAON = 11,
  BUFIE = 10,
  EVIE = 9,
  ERRIE = 8,
  I2CCLK = 0,
};

/**
 * Bitmasks for I2C SADDR0
 *
 * Slave address register 0
 */
enum class I2C_regs::SADDR0_bits : uint16_t {
  ADDFORMAT = (1 << 15),         ///< Address mode for the I2C slave
  ADDRESS9_8_mask = (0x3 << 8),  ///< Highest two bits of a 10-bit address
  ADDRESS7_1_mask =
      (0x7f << 1),        ///< 7-bit address or bits 7:1 of a 10-bit address
  ADDRESS0 = (1 << 0),    ///< Bit 0 of a 10-bit address
  Reserved_mask = 0x7c00  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::SADDR0_bits);

/**
 * Bit shifts for I2C SADDR0
 */
enum class I2C_regs::SADDR0_shift : unsigned {
  ADDFORMAT = 15,
  ADDRESS9_8 = 8,
  ADDRESS7_1 = 1,
  ADDRESS0 = 0,
};

/**
 * Bitmasks for I2C SADDR1
 *
 * Slave address register 1
 */
enum class I2C_regs::SADDR1_bits : uint16_t {
  ADDRESS2_mask =
      (0x7f << 1),    ///< Second I2C address for the slave in Dual-Address mode
  DUADEN = (1 << 0),  ///< Dual-Address mode switch
  Reserved_mask = 0xff00  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::SADDR1_bits);

/**
 * Bit shifts for I2C SADDR1
 */
enum class I2C_regs::SADDR1_shift : unsigned {
  ADDRESS2 = 1,
  DUADEN = 0,
};

/**
 * Bitmasks for I2C DATA
 *
 * Transfer buffer register
 */
enum class I2C_regs::DATA_bits : uint16_t {
  TRB_mask = (0xff << 0),  ///< Transmission or reception data buffer register
  Reserved_mask = 0xff00   ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::DATA_bits);

/**
 * Bit shifts for I2C DATA
 */
enum class I2C_regs::DATA_shift : unsigned {
  TRB = 0,
};

/**
 * Bitmasks for I2C STAT0
 *
 * Transfer status register 0
 */
enum class I2C_regs::STAT0_bits : uint16_t {
  SMBALT = (1 << 15),  ///< SMBus Alert status
  SMBTO = (1 << 14),   ///< Timeout signal in SMBus mode
  PECERR = (1 << 12),  ///< PEC error when receiving data
  OUERR = (1 << 11),   ///< Over-run or under-run situation occurs in slave mode
  AERR = (1 << 10),    ///< Acknowledge error
  LOSTARB = (1 << 9),  ///< Arbitration Lost in master mode
  BERR = (1 << 8),     ///< A bus error occurs indication a unexpected START or
                       ///< STOP condition on I2C bus
  TBE = (1 << 7),      ///< I2C_DATA is Empty during transmitting
  RBNE = (1 << 6),     ///< I2C_DATA is not Empty during receiving
  STPDET = (1 << 4),   ///< STOP condition detected in slave mode
  ADD10SEND = (1 << 3),   ///< Header of 10-bit address is sent in master mode
  BTC = (1 << 2),         ///< Byte transmission completed
  ADDSEND = (1 << 1),     ///< Address is sent in master mode or received and
                          ///< matches in slave mode
  SBSEND = (1 << 0),      ///< START condition sent out in master mode
  Reserved_mask = 0x2020  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::STAT0_bits);

/**
 * Bit shifts for I2C STAT0
 */
enum class I2C_regs::STAT0_shift : unsigned {
  SMBALT = 15,
  SMBTO = 14,
  PECERR = 12,
  OUERR = 11,
  AERR = 10,
  LOSTARB = 9,
  BERR = 8,
  TBE = 7,
  RBNE = 6,
  STPDET = 4,
  ADD10SEND = 3,
  BTC = 2,
  ADDSEND = 1,
  SBSEND = 0,
};

/**
 * Bitmasks for I2C STAT1
 *
 * Transfer status register 1
 */
enum class I2C_regs::STAT1_bits : uint16_t {
  PECV_mask = (0xff << 8),  ///< Packet Error Checking Value that calculated by
                            ///< hardware when PEC is enabled
  DUMODF = (1 << 7),        ///< Dual Flag in slave mode
  HSTSMB = (1 << 6),        ///< SMBus Host Header detected in slave mode
  DEFSMB = (1 << 5),        ///< Default address of SMBusDevice
  RXGC = (1 << 4),          ///< General call address (00h) received
  TR = (1 << 2),            ///< Whether the I2C is a transmitter or a receiver
  I2CBSY = (1 << 1),        ///< Busy flag
  MASTER = (1 << 0),  ///< A flag indicating whether I2C block is in master or
                      ///< slave mode
  Reserved_mask = 0x0008  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::STAT1_bits);

/**
 * Bit shifts for I2C STAT1
 */
enum class I2C_regs::STAT1_shift : unsigned {
  PECV = 8,
  DUMODF = 7,
  HSTSMB = 6,
  DEFSMB = 5,
  RXGC = 4,
  TR = 2,
  I2CBSY = 1,
  MASTER = 0,
};

/**
 * Bitmasks for I2C CKCFG
 *
 * Clock configure register
 */
enum class I2C_regs::CKCFG_bits : uint16_t {
  FAST = (1 << 15),          ///< I2C speed selection in master mode
  DTCY = (1 << 14),          ///< Duty cycle in fast mode
  CLKC_mask = (0xfff << 0),  ///< I2C Clock control in master mode
  Reserved_mask = 0x3000     ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::CKCFG_bits);

/**
 * Bit shifts for I2C CKCFG
 */
enum class I2C_regs::CKCFG_shift : unsigned {
  FAST = 15,
  DTCY = 14,
  CLKC = 0,
};

/**
 * Bitmasks for I2C RT
 *
 * Rise time register
 */
enum class I2C_regs::RT_bits : uint16_t {
  RISETIME_mask = (0x3f << 0),  ///< Maximum rise time in master mode
  Reserved_mask = 0xffc0        ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::RT_bits);

/**
 * Bit shifts for I2C RT
 */
enum class I2C_regs::RT_shift : unsigned {
  RISETIME = 0,
};

static_assert(offsetof(I2C_regs, CTL0) == 0x0);
static_assert(offsetof(I2C_regs, CTL1) == 0x4);
static_assert(offsetof(I2C_regs, SADDR0) == 0x8);
static_assert(offsetof(I2C_regs, SADDR1) == 0xc);
static_assert(offsetof(I2C_regs, DATA) == 0x10);
static_assert(offsetof(I2C_regs, STAT0) == 0x14);
static_assert(offsetof(I2C_regs, STAT1) == 0x18);
static_assert(offsetof(I2C_regs, CKCFG) == 0x1c);
static_assert(offsetof(I2C_regs, RT) == 0x20);
}  // namespace deri::mmio
