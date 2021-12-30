/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct CLINT_regs {
  enum class msip_bits : uint32_t;
  enum class mtimecmp_bits : uint32_t;
  enum class mtimecmph_bits : uint32_t;
  enum class mtime_bits : uint32_t;
  enum class mtimeh_bits : uint32_t;
  enum class msip_shift : unsigned;
  enum class mtimecmp_shift : unsigned;
  enum class mtimecmph_shift : unsigned;
  enum class mtime_shift : unsigned;
  enum class mtimeh_shift : unsigned;

  Register<msip_bits> msip;
  const Reserved<uint32_t> reserved_0[4095];
  // Base + 0x4000
  Register<mtimecmp_bits> mtimecmp;
  Register<mtimecmph_bits> mtimecmph;
  const Reserved<uint32_t> reserved_1[8188];
  // Base + 0xbff8
  Register<mtime_bits> mtime;
  Register<mtimeh_bits> mtimeh;
};
}  // namespace deri::mmio
