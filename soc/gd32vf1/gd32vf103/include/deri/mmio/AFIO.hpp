/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct AFIO_regs {
  enum class EC_bits : uint32_t;
  enum class PCF0_bits : uint32_t;
  enum class EXTISS0_bits : uint32_t;
  enum class EXTISS1_bits : uint32_t;
  enum class EXTISS2_bits : uint32_t;
  enum class EXTISS3_bits : uint32_t;
  enum class PCF1_bits : uint32_t;
  enum class EC_shift : unsigned;
  enum class PCF0_shift : unsigned;
  enum class EXTISS0_shift : unsigned;
  enum class EXTISS1_shift : unsigned;
  enum class EXTISS2_shift : unsigned;
  enum class EXTISS3_shift : unsigned;
  enum class PCF1_shift : unsigned;

  Register<EC_bits> EC;
  Register<PCF0_bits> PCF0;
  Register<EXTISS0_bits> EXTISS0;
  Register<EXTISS1_bits> EXTISS1;
  Register<EXTISS2_bits> EXTISS2;
  Register<EXTISS3_bits> EXTISS3;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x1c
  Register<PCF1_bits> PCF1;
};
}  // namespace deri::mmio
