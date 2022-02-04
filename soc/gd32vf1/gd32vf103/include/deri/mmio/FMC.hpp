/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct FMC_regs {
  enum class WS_bits : uint32_t;
  enum class KEY0_bits : uint32_t;
  enum class OBKEY_bits : uint32_t;
  enum class STAT0_bits : uint32_t;
  enum class CTL0_bits : uint32_t;
  enum class ADDR0_bits : uint32_t;
  enum class OBSTAT_bits : uint32_t;
  enum class WP_bits : uint32_t;
  enum class PID_bits : uint32_t;
  enum class WS_shift : unsigned;
  enum class KEY0_shift : unsigned;
  enum class OBKEY_shift : unsigned;
  enum class STAT0_shift : unsigned;
  enum class CTL0_shift : unsigned;
  enum class ADDR0_shift : unsigned;
  enum class OBSTAT_shift : unsigned;
  enum class WP_shift : unsigned;
  enum class PID_shift : unsigned;

  Register<WS_bits> WS;
  Register<KEY0_bits> KEY0;
  Register<OBKEY_bits> OBKEY;
  Register<STAT0_bits> STAT0;
  Register<CTL0_bits> CTL0;
  Register<ADDR0_bits> ADDR0;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x1c
  const Register<OBSTAT_bits> OBSTAT;
  const Register<WP_bits> WP;
  const Reserved<uint32_t> reserved_1[55];
  // Base + 0x100
  const Register<PID_bits> PID;
};
}  // namespace deri::mmio
