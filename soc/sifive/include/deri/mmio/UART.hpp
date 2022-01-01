/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct UART_regs {
  enum class txdata_bits : uint32_t;
  enum class rxdata_bits : uint32_t;
  enum class txctrl_bits : uint32_t;
  enum class rxctrl_bits : uint32_t;
  enum class ie_bits : uint32_t;
  enum class ip_bits : uint32_t;
  enum class div_bits : uint32_t;
  enum class txdata_shift : unsigned;
  enum class rxdata_shift : unsigned;
  enum class txctrl_shift : unsigned;
  enum class rxctrl_shift : unsigned;
  enum class ie_shift : unsigned;
  enum class ip_shift : unsigned;
  enum class div_shift : unsigned;

  AtomicRegister<txdata_bits> txdata;
  Register<rxdata_bits> rxdata;
  Register<txctrl_bits> txctrl;
  Register<rxctrl_bits> rxctrl;
  Register<ie_bits> ie;
  Register<ip_bits> ip;
  Register<div_bits> div;
};
}  // namespace deri::mmio
