/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct RCU_regs {
  enum class CTL_bits : uint32_t;
  enum class CFG0_bits : uint32_t;
  enum class INT_bits : uint32_t;
  enum class APB2RST_bits : uint32_t;
  enum class APB1RST_bits : uint32_t;
  enum class AHBEN_bits : uint32_t;
  enum class APB2EN_bits : uint32_t;
  enum class APB1EN_bits : uint32_t;
  enum class BDCTL_bits : uint32_t;
  enum class RSTSCK_bits : uint32_t;
  enum class AHBRST_bits : uint32_t;
  enum class CFG1_bits : uint32_t;
  enum class DSV_bits : uint32_t;
  enum class CTL_shift : unsigned;
  enum class CFG0_shift : unsigned;
  enum class INT_shift : unsigned;
  enum class APB2RST_shift : unsigned;
  enum class APB1RST_shift : unsigned;
  enum class AHBEN_shift : unsigned;
  enum class APB2EN_shift : unsigned;
  enum class APB1EN_shift : unsigned;
  enum class BDCTL_shift : unsigned;
  enum class RSTSCK_shift : unsigned;
  enum class AHBRST_shift : unsigned;
  enum class CFG1_shift : unsigned;
  enum class DSV_shift : unsigned;

  Register<CTL_bits> CTL;
  Register<CFG0_bits> CFG0;
  Register<INT_bits> INT;
  Register<APB2RST_bits> APB2RST;
  Register<APB1RST_bits> APB1RST;
  Register<AHBEN_bits> AHBEN;
  Register<APB2EN_bits> APB2EN;
  Register<APB1EN_bits> APB1EN;
  Register<BDCTL_bits> BDCTL;
  Register<RSTSCK_bits> RSTSCK;
  Register<AHBRST_bits> AHBRST;
  Register<CFG1_bits> CFG1;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x34
  Register<DSV_bits> DSV;
};
}  // namespace deri::mmio
