/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct SPI_regs {
  enum class CTL0_bits : uint16_t;
  enum class CTL1_bits : uint16_t;
  enum class STAT_bits : uint16_t;
  enum class DATA_bits : uint16_t;
  enum class CRCPOLY_bits : uint16_t;
  enum class RCRC_bits : uint16_t;
  enum class TCRC_bits : uint16_t;
  enum class I2SCTL_bits : uint16_t;
  enum class I2SPSC_bits : uint16_t;
  enum class CTL0_shift : unsigned;
  enum class CTL1_shift : unsigned;
  enum class STAT_shift : unsigned;
  enum class DATA_shift : unsigned;
  enum class CRCPOLY_shift : unsigned;
  enum class RCRC_shift : unsigned;
  enum class TCRC_shift : unsigned;
  enum class I2SCTL_shift : unsigned;
  enum class I2SPSC_shift : unsigned;

  Register<CTL0_bits> CTL0;
  const Reserved<uint16_t> reserved_0;
  // Base + 0x4
  Register<CTL1_bits> CTL1;
  const Reserved<uint16_t> reserved_1;
  // Base + 0x8
  Register<STAT_bits> STAT;
  const Reserved<uint16_t> reserved_2;
  // Base + 0xc
  Register<DATA_bits> DATA;
  const Reserved<uint16_t> reserved_3;
  // Base + 0x10
  Register<CRCPOLY_bits> CRCPOLY;
  const Reserved<uint16_t> reserved_4;
  // Base + 0x14
  const Register<RCRC_bits> RCRC;
  const Reserved<uint16_t> reserved_5;
  // Base + 0x18
  const Register<TCRC_bits> TCRC;
  const Reserved<uint16_t> reserved_6;
  // Base + 0x1c
  Register<I2SCTL_bits> I2SCTL;
  const Reserved<uint16_t> reserved_7;
  // Base + 0x20
  Register<I2SPSC_bits> I2SPSC;
};
}  // namespace deri::mmio
