/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct PWM_regs {
  enum class cfg_bits : uint32_t;
  enum class count_bits : uint32_t;
  enum class pwms_bits : uint32_t;
  enum class cmp0_bits : uint32_t;
  enum class cmp1_bits : uint32_t;
  enum class cmp2_bits : uint32_t;
  enum class cmp3_bits : uint32_t;
  enum class cfg_shift : unsigned;
  enum class count_shift : unsigned;
  enum class pwms_shift : unsigned;
  enum class cmp0_shift : unsigned;
  enum class cmp1_shift : unsigned;
  enum class cmp2_shift : unsigned;
  enum class cmp3_shift : unsigned;

  Register<cfg_bits> cfg;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x8
  Register<count_bits> count;
  const Reserved<uint32_t> reserved_1;
  // Base + 0x10
  Register<pwms_bits> pwms;
  const Reserved<uint32_t> reserved_2[3];
  // Base + 0x20
  Register<cmp0_bits> cmp0;
  Register<cmp1_bits> cmp1;
  Register<cmp2_bits> cmp2;
  Register<cmp3_bits> cmp3;
};
}  // namespace deri::mmio
