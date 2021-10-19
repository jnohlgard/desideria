/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct ECLIC_regs {
  enum class CLICCFG_bits : uint8_t;
  enum class CLICINFO_bits : uint32_t;
  enum class MTH_bits : uint8_t;
  enum class CLICCFG_shift : unsigned;
  enum class CLICINFO_shift : unsigned;
  enum class MTH_shift : unsigned;

  Register<CLICCFG_bits> CLICCFG;
  const Reserved<uint8_t> reserved_0;
  const Reserved<uint16_t> reserved_1;
  // Base + 0x4
  const Register<CLICINFO_bits> CLICINFO;
  const Reserved<uint8_t> reserved_2;
  const Reserved<uint8_t> reserved_3;
  const Reserved<uint8_t> reserved_4;
  Register<MTH_bits> MTH;
  const Reserved<uint32_t> reserved_5[1021];
  // Base + 0x1000
  struct CLICINT_regs {
    enum class CLICINTIP_bits : uint8_t;
    enum class CLICINTIE_bits : uint8_t;
    enum class CLICINTATTR_bits : uint8_t;
    enum class CLICINTCTL_bits : uint8_t;
    enum class CLICINTIP_shift : unsigned;
    enum class CLICINTIE_shift : unsigned;
    enum class CLICINTATTR_shift : unsigned;
    enum class CLICINTCTL_shift : unsigned;

    Register<CLICINTIP_bits> CLICINTIP;
    Register<CLICINTIE_bits> CLICINTIE;
    Register<CLICINTATTR_bits> CLICINTATTR;
    Register<CLICINTCTL_bits> CLICINTCTL;
  };
  CLICINT_regs CLICINT[87];
};
}  // namespace deri::mmio
