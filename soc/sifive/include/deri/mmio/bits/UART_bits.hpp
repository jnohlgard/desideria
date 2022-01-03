/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/UART.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for UART txdata
 *
 * Transmit Data Register
 */
enum class UART_regs::txdata_bits : uint32_t {
  full = (1u << 31),
  data_mask = (0xffu << 0),
  Reserved_mask = 0x7fffff00  ///< All reserved bits
};
void HasBitwiseOperators(UART_regs::txdata_bits);

/**
 * Bit shifts for UART txdata
 */
enum class UART_regs::txdata_shift : unsigned {
  full = 31,
  data = 0,
};

/**
 * Bitmasks for UART rxdata
 *
 * Receive Data Register
 */
enum class UART_regs::rxdata_bits : uint32_t {
  empty = (1u << 31),
  data_mask = (0xffu << 0),
  Reserved_mask = 0x7fffff00  ///< All reserved bits
};
void HasBitwiseOperators(UART_regs::rxdata_bits);

/**
 * Bit shifts for UART rxdata
 */
enum class UART_regs::rxdata_shift : unsigned {
  empty = 31,
  data = 0,
};

/**
 * Bitmasks for UART txctrl
 *
 * Transmit Control Register
 */
enum class UART_regs::txctrl_bits : uint32_t {
  counter_mask = (0x7u << 16),
  nstop = (1u << 1),
  enable = (1u << 0),
  Reserved_mask = 0xfff8fffc  ///< All reserved bits
};
void HasBitwiseOperators(UART_regs::txctrl_bits);

/**
 * Bit shifts for UART txctrl
 */
enum class UART_regs::txctrl_shift : unsigned {
  counter = 16,
  nstop = 1,
  enable = 0,
};
void IsBitShift(UART_regs::txctrl_shift);

/**
 * Bitmasks for UART rxctrl
 *
 * Receive Control Register
 */
enum class UART_regs::rxctrl_bits : uint32_t {
  counter_mask = (0x7u << 16),
  enable = (1u << 0),
  Reserved_mask = 0xfff8fffe  ///< All reserved bits
};
void HasBitwiseOperators(UART_regs::rxctrl_bits);

/**
 * Bit shifts for UART rxctrl
 */
enum class UART_regs::rxctrl_shift : unsigned {
  counter = 16,
  enable = 0,
};

/**
 * Bitmasks for UART ie
 *
 * Interrupt Enable Register
 */
enum class UART_regs::ie_bits : uint32_t {
  rxwm = (1u << 1),
  txwm = (1u << 0),
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(UART_regs::ie_bits);

/**
 * Bit shifts for UART ie
 */
enum class UART_regs::ie_shift : unsigned {
  rxwm = 1,
  txwm = 0,
};

/**
 * Bitmasks for UART ip
 *
 * Interrupt Pending Register
 */
enum class UART_regs::ip_bits : uint32_t {
  rxwm = (1u << 1),
  txwm = (1u << 0),
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(UART_regs::ip_bits);

/**
 * Bit shifts for UART ip
 */
enum class UART_regs::ip_shift : unsigned {
  rxwm = 1,
  txwm = 0,
};

/**
 * Bitmasks for UART div
 *
 * Baud Rate Divisor Register
 */
enum class UART_regs::div_bits : uint32_t {
  value_mask = (0xffffu << 0),
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(UART_regs::div_bits);

/**
 * Bit shifts for UART div
 */
enum class UART_regs::div_shift : unsigned {
  value = 0,
};

static_assert(offsetof(UART_regs, txdata) == 0x0);
static_assert(offsetof(UART_regs, rxdata) == 0x4);
static_assert(offsetof(UART_regs, txctrl) == 0x8);
static_assert(offsetof(UART_regs, rxctrl) == 0xc);
static_assert(offsetof(UART_regs, ie) == 0x10);
static_assert(offsetof(UART_regs, ip) == 0x14);
static_assert(offsetof(UART_regs, div) == 0x18);
}  // namespace deri::mmio
