/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/OTP.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for OTP lock
 *
 * Programmed-I/O lock register
 */
enum class OTP_regs::lock_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::lock_bits);

/**
 * Bit shifts for OTP lock
 */
enum class OTP_regs::lock_shift : unsigned {};

/**
 * Bitmasks for OTP clock
 *
 * OTP device clock signal
 */
enum class OTP_regs::clock_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::clock_bits);

/**
 * Bit shifts for OTP clock
 */
enum class OTP_regs::clock_shift : unsigned {};

/**
 * Bitmasks for OTP output_en
 *
 * OTP device output-enable signal
 */
enum class OTP_regs::output_en_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::output_en_bits);

/**
 * Bit shifts for OTP output_en
 */
enum class OTP_regs::output_en_shift : unsigned {};

/**
 * Bitmasks for OTP select
 *
 * OTP device chip-select signal
 */
enum class OTP_regs::select_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::select_bits);

/**
 * Bit shifts for OTP select
 */
enum class OTP_regs::select_shift : unsigned {};

/**
 * Bitmasks for OTP write_en
 *
 * OTP device write-enable signal
 */
enum class OTP_regs::write_en_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::write_en_bits);

/**
 * Bit shifts for OTP write_en
 */
enum class OTP_regs::write_en_shift : unsigned {};

/**
 * Bitmasks for OTP mode
 *
 * OTP device mode register
 */
enum class OTP_regs::mode_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::mode_bits);

/**
 * Bit shifts for OTP mode
 */
enum class OTP_regs::mode_shift : unsigned {};

/**
 * Bitmasks for OTP mrr
 *
 * OTP read-voltage regulator control
 */
enum class OTP_regs::mrr_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::mrr_bits);

/**
 * Bit shifts for OTP mrr
 */
enum class OTP_regs::mrr_shift : unsigned {};

/**
 * Bitmasks for OTP mpp
 *
 * OTP write-voltage charge pump control
 */
enum class OTP_regs::mpp_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::mpp_bits);

/**
 * Bit shifts for OTP mpp
 */
enum class OTP_regs::mpp_shift : unsigned {};

/**
 * Bitmasks for OTP vrren
 *
 * OTP read-voltage enable
 */
enum class OTP_regs::vrren_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::vrren_bits);

/**
 * Bit shifts for OTP vrren
 */
enum class OTP_regs::vrren_shift : unsigned {};

/**
 * Bitmasks for OTP vppen
 *
 * OTP write-voltage enable
 */
enum class OTP_regs::vppen_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::vppen_bits);

/**
 * Bit shifts for OTP vppen
 */
enum class OTP_regs::vppen_shift : unsigned {};

/**
 * Bitmasks for OTP addr
 *
 * OTP device address
 */
enum class OTP_regs::addr_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::addr_bits);

/**
 * Bit shifts for OTP addr
 */
enum class OTP_regs::addr_shift : unsigned {};

/**
 * Bitmasks for OTP data_in
 *
 * OTP device data input
 */
enum class OTP_regs::data_in_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::data_in_bits);

/**
 * Bit shifts for OTP data_in
 */
enum class OTP_regs::data_in_shift : unsigned {};

/**
 * Bitmasks for OTP data_out
 *
 * OTP device data output
 */
enum class OTP_regs::data_out_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::data_out_bits);

/**
 * Bit shifts for OTP data_out
 */
enum class OTP_regs::data_out_shift : unsigned {};

/**
 * Bitmasks for OTP rsctrl
 *
 * OTP read sequencer control
 */
enum class OTP_regs::rsctrl_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(OTP_regs::rsctrl_bits);

/**
 * Bit shifts for OTP rsctrl
 */
enum class OTP_regs::rsctrl_shift : unsigned {};

static_assert(offsetof(OTP_regs, lock) == 0x0);
static_assert(offsetof(OTP_regs, clock) == 0x4);
static_assert(offsetof(OTP_regs, output_en) == 0x8);
static_assert(offsetof(OTP_regs, select) == 0xc);
static_assert(offsetof(OTP_regs, write_en) == 0x10);
static_assert(offsetof(OTP_regs, mode) == 0x14);
static_assert(offsetof(OTP_regs, mrr) == 0x18);
static_assert(offsetof(OTP_regs, mpp) == 0x1c);
static_assert(offsetof(OTP_regs, vrren) == 0x20);
static_assert(offsetof(OTP_regs, vppen) == 0x24);
static_assert(offsetof(OTP_regs, addr) == 0x28);
static_assert(offsetof(OTP_regs, data_in) == 0x2c);
static_assert(offsetof(OTP_regs, data_out) == 0x30);
static_assert(offsetof(OTP_regs, rsctrl) == 0x34);
}  // namespace deri::mmio
