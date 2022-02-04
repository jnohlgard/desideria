/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct I2C_regs {
  enum class CTL0_bits : uint16_t;
  enum class CTL1_bits : uint16_t;
  enum class SADDR0_bits : uint16_t;
  enum class SADDR1_bits : uint16_t;
  enum class DATA_bits : uint16_t;
  enum class STAT0_bits : uint16_t;
  enum class STAT1_bits : uint16_t;
  enum class CKCFG_bits : uint16_t;
  enum class RT_bits : uint16_t;
  enum class CTL0_shift : unsigned;
  enum class CTL1_shift : unsigned;
  enum class SADDR0_shift : unsigned;
  enum class SADDR1_shift : unsigned;
  enum class DATA_shift : unsigned;
  enum class STAT0_shift : unsigned;
  enum class STAT1_shift : unsigned;
  enum class CKCFG_shift : unsigned;
  enum class RT_shift : unsigned;

  Register<CTL0_bits> CTL0;
  const Reserved<uint16_t> reserved_0;
  // Base + 0x4
  Register<CTL1_bits> CTL1;
  const Reserved<uint16_t> reserved_1;
  // Base + 0x8
  Register<SADDR0_bits> SADDR0;
  const Reserved<uint16_t> reserved_2;
  // Base + 0xc
  Register<SADDR1_bits> SADDR1;
  const Reserved<uint16_t> reserved_3;
  // Base + 0x10
  Register<DATA_bits> DATA;
  const Reserved<uint16_t> reserved_4;
  // Base + 0x14
  Register<STAT0_bits> STAT0;
  const Reserved<uint16_t> reserved_5;
  // Base + 0x18
  const Register<STAT1_bits> STAT1;
  const Reserved<uint16_t> reserved_6;
  // Base + 0x1c
  Register<CKCFG_bits> CKCFG;
  const Reserved<uint16_t> reserved_7;
  // Base + 0x20
  Register<RT_bits> RT;
};
}  // namespace deri::mmio
