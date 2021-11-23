/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct USART_regs {
  enum class STAT_bits : uint32_t;
  enum class DATA_bits : uint32_t;
  enum class BAUD_bits : uint32_t;
  enum class CTL0_bits : uint32_t;
  enum class CTL1_bits : uint32_t;
  enum class CTL2_bits : uint32_t;
  enum class GP_bits : uint32_t;
  enum class STAT_shift : unsigned;
  enum class DATA_shift : unsigned;
  enum class BAUD_shift : unsigned;
  enum class CTL0_shift : unsigned;
  enum class CTL1_shift : unsigned;
  enum class CTL2_shift : unsigned;
  enum class GP_shift : unsigned;

  Register<STAT_bits> STAT;
  Register<DATA_bits> DATA;
  Register<BAUD_bits> BAUD;
  Register<CTL0_bits> CTL0;
  Register<CTL1_bits> CTL1;
  Register<CTL2_bits> CTL2;
  Register<GP_bits> GP;
};
}  // namespace deri::mmio
