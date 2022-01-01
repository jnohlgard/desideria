/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct WDOG_regs {
  enum class wdogcfg_bits : uint32_t;
  enum class wdogcount_bits : uint32_t;
  enum class wdogs_bits : uint32_t;
  enum class wdogfeed_bits : uint32_t;
  enum class wdogkey_bits : uint32_t;
  enum class wdogcmp_bits : uint32_t;
  enum class wdogcfg_shift : unsigned;
  enum class wdogcount_shift : unsigned;
  enum class wdogs_shift : unsigned;
  enum class wdogfeed_shift : unsigned;
  enum class wdogkey_shift : unsigned;
  enum class wdogcmp_shift : unsigned;

  Register<wdogcfg_bits> wdogcfg;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x8
  Register<wdogcount_bits> wdogcount;
  const Reserved<uint32_t> reserved_1;
  // Base + 0x10
  Register<wdogs_bits> wdogs;
  const Reserved<uint32_t> reserved_2;
  // Base + 0x18
  Register<wdogfeed_bits> wdogfeed;
  Register<wdogkey_bits> wdogkey;
  Register<wdogcmp_bits> wdogcmp;
};
}  // namespace deri::mmio
