/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct RTC_regs {
  enum class rtccfg_bits : uint32_t;
  enum class rtclo_bits : uint32_t;
  enum class rtchi_bits : uint32_t;
  enum class rtcs_bits : uint32_t;
  enum class rtccmp_bits : uint32_t;
  enum class rtccfg_shift : unsigned;
  enum class rtclo_shift : unsigned;
  enum class rtchi_shift : unsigned;
  enum class rtcs_shift : unsigned;
  enum class rtccmp_shift : unsigned;

  Register<rtccfg_bits> rtccfg;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x8
  Register<rtclo_bits> rtclo;
  Register<rtchi_bits> rtchi;
  Register<rtcs_bits> rtcs;
  const Reserved<uint32_t> reserved_1[3];
  // Base + 0x20
  Register<rtccmp_bits> rtccmp;
};
}  // namespace deri::mmio
