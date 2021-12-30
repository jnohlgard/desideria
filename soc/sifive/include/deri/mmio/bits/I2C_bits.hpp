/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/I2C.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for I2C prer_lo
 *
 * Clock Prescale register lo-byte
 */
enum class I2C_regs::prer_lo_bits : uint32_t {
  value_mask = (0xffu << 0),
  Reserved_mask = 0xffffff00  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::prer_lo_bits);

/**
 * Bit shifts for I2C prer_lo
 */
enum class I2C_regs::prer_lo_shift : unsigned {
  value = 0,
};

/**
 * Bitmasks for I2C prer_hi
 *
 * Clock Prescale register hi-byte
 */
enum class I2C_regs::prer_hi_bits : uint32_t {
  value_mask = (0xffu << 0),
  Reserved_mask = 0xffffff00  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::prer_hi_bits);

/**
 * Bit shifts for I2C prer_hi
 */
enum class I2C_regs::prer_hi_shift : unsigned {
  value = 0,
};

/**
 * Bitmasks for I2C ctr
 *
 * Control register
 */
enum class I2C_regs::ctr_bits : uint32_t {
  en = (1u << 7),             ///< I2C core enable bit
  ien = (1u << 6),            ///< I2C core interrupt enable bit
  Reserved_mask = 0xffffff3f  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::ctr_bits);

/**
 * Bit shifts for I2C ctr
 */
enum class I2C_regs::ctr_shift : unsigned {
  en = 7,
  ien = 6,
};

/**
 * Bitmasks for I2C txr_rxr
 *
 * Transmit register / Receive register
 */
enum class I2C_regs::txr_rxr_bits : uint32_t {
  data_mask = (0xffu << 0),
  Reserved_mask = 0xffffff00  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::txr_rxr_bits);

/**
 * Bit shifts for I2C txr_rxr
 */
enum class I2C_regs::txr_rxr_shift : unsigned {
  data = 0,
};

/**
 * Bitmasks for I2C cr_sr
 *
 * Command register / Status register
 */
enum class I2C_regs::cr_sr_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::cr_sr_bits);

/**
 * Bit shifts for I2C cr_sr
 */
enum class I2C_regs::cr_sr_shift : unsigned {};

/**
 * Bitmasks for I2C cr
 *
 * Command register
 */
enum class I2C_regs::cr_bits : uint32_t {
  sta = (1u << 7),  ///< Generate (repeated) start condition
  sto = (1u << 6),  ///< Generate stop condition
  rd = (1u << 5),   ///< Read from slave
  wr = (1u << 4),   ///< Write to slave
  ack = (1u << 3),  ///< When a receiver, sent ACK (0) or NACK (1)
  iack =
      (1u
       << 0),  ///< Interrupt acknowledge. When set, clears a pending interrupt
  Reserved_mask = 0xffffff06  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::cr_bits);

/**
 * Bit shifts for I2C cr
 */
enum class I2C_regs::cr_shift : unsigned {
  sta = 7,
  sto = 6,
  rd = 5,
  wr = 4,
  ack = 3,
  iack = 0,
};

/**
 * Bitmasks for I2C sr
 *
 * Status register
 */
enum class I2C_regs::sr_bits : uint32_t {
  rx_ack = (1u << 7),  ///< Received acknowledge from slave. This flag
                       ///< represents acknowledge from the addressed slave. '1'
                       ///< = No acknowledge received '0' = Acknowledge received
  busy = (1u << 6),    ///< I2C bus busy
  al = (1u << 5),      ///< Arbitration lost
  tip = (1u << 1),     ///< Transfer in progress
  if = (1u << 0),      ///< Interrupt Flag. This bit is set when an interrupt is
                   ///< pending, which will cause a processor interrupt request
                   ///< if the IEN bit is set.
  Reserved_mask = 0xffffff1c  ///< All reserved bits
};
void HasBitwiseOperators(I2C_regs::sr_bits);

/**
 * Bit shifts for I2C sr
 */
enum class I2C_regs::sr_shift : unsigned {
  rx_ack = 7,
  busy = 6,
  al = 5,
  tip = 1,
  if = 0,
};

static_assert(offsetof(I2C_regs, prer_lo) == 0x0);
static_assert(offsetof(I2C_regs, prer_hi) == 0x4);
static_assert(offsetof(I2C_regs, ctr) == 0x8);
static_assert(offsetof(I2C_regs, txr_rxr) == 0xc);
static_assert(offsetof(I2C_regs, cr_sr) == 0x10);
static_assert(offsetof(I2C_regs, cr) == 0x10);
static_assert(offsetof(I2C_regs, sr) == 0x10);
}  // namespace deri::mmio
