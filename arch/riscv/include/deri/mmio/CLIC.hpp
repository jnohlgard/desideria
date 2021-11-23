/*
* Copyright (C) 2021 Joakim Nohlgård <joakim@nohlgard.se>
*/
#pragma once

#include "deri/registers.hpp"

#include <array>
#include <cstdint>

namespace deri::mmio {
struct CLIC_regs {
  enum class CLICCFG_bits : uint8_t;
  enum class CLICINFO_bits : uint32_t;
  enum class CLICINTTRIG_bits : uint32_t;
  enum class CLICCFG_shift : unsigned;
  enum class CLICINFO_shift : unsigned;
  enum class CLICINTTRIG_shift : unsigned;

  Register<CLICCFG_bits> cliccfg;
  const Reserved<uint8_t> reserved_0;
  const Reserved<uint16_t> reserved_1;
  // Base + 0x4
  const Register<CLICINFO_bits> clicinfo;
  const std::array<const Reserved<uint32_t>, (0x40 - 0x8) / 4> reserved_2;
  // Base + 0x40
  std::array<Register<CLICINTTRIG_bits>, 32> clicinttrig;
  const std::array<const Reserved<uint32_t>, (0x1000 - 0xC0) / 4> reserved_3;
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

    Register<CLICINTIP_bits> clicintip;
    Register<CLICINTIE_bits> clicintie;
    Register<CLICINTATTR_bits> clicintattr;
    Register<CLICINTCTL_bits> clicintctl;
  };
  std::array<CLICINT_regs, 4096> clicint;
};
}  // namespace deri::mmio
