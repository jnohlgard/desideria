/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/WDOG.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for WDOG wdogcfg
 *
 * Watchdog Configuration Register
 */
enum class WDOG_regs::wdogcfg_bits : uint32_t {
  cmpip = (1u << 28),
  encoreawake = (1u << 13),
  enalways = (1u << 12),
  zerocmp = (1u << 9),
  rsten = (1u << 8),
  scale_mask = (0xfu << 0),
  Reserved_mask = 0xefffccf0  ///< All reserved bits
};
void HasBitwiseOperators(WDOG_regs::wdogcfg_bits);

/**
 * Bit shifts for WDOG wdogcfg
 */
enum class WDOG_regs::wdogcfg_shift : unsigned {
  cmpip = 28,
  encoreawake = 13,
  enalways = 12,
  zerocmp = 9,
  rsten = 8,
  scale = 0,
};

/**
 * Bitmasks for WDOG wdogcount
 *
 * Watchdog Counter Register
 */
enum class WDOG_regs::wdogcount_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(WDOG_regs::wdogcount_bits);

/**
 * Bit shifts for WDOG wdogcount
 */
enum class WDOG_regs::wdogcount_shift : unsigned {};

/**
 * Bitmasks for WDOG wdogs
 *
 * Watchdog Scaled Counter Register
 */
enum class WDOG_regs::wdogs_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(WDOG_regs::wdogs_bits);

/**
 * Bit shifts for WDOG wdogs
 */
enum class WDOG_regs::wdogs_shift : unsigned {};

/**
 * Bitmasks for WDOG wdogfeed
 *
 * Watchdog Feed Register
 */
enum class WDOG_regs::wdogfeed_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(WDOG_regs::wdogfeed_bits);

/**
 * Bit shifts for WDOG wdogfeed
 */
enum class WDOG_regs::wdogfeed_shift : unsigned {};

/**
 * Bitmasks for WDOG wdogkey
 *
 * Watchdog Key Register
 */
enum class WDOG_regs::wdogkey_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(WDOG_regs::wdogkey_bits);

/**
 * Bit shifts for WDOG wdogkey
 */
enum class WDOG_regs::wdogkey_shift : unsigned {};

/**
 * Bitmasks for WDOG wdogcmp
 *
 * Watchdog Compare Register
 */
enum class WDOG_regs::wdogcmp_bits : uint32_t {
  value_mask = (0xffffu << 0),
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(WDOG_regs::wdogcmp_bits);

/**
 * Bit shifts for WDOG wdogcmp
 */
enum class WDOG_regs::wdogcmp_shift : unsigned {
  value = 0,
};

static_assert(offsetof(WDOG_regs, wdogcfg) == 0x0);
static_assert(offsetof(WDOG_regs, wdogcount) == 0x8);
static_assert(offsetof(WDOG_regs, wdogs) == 0x10);
static_assert(offsetof(WDOG_regs, wdogfeed) == 0x18);
static_assert(offsetof(WDOG_regs, wdogkey) == 0x1c);
static_assert(offsetof(WDOG_regs, wdogcmp) == 0x20);
}  // namespace deri::mmio
