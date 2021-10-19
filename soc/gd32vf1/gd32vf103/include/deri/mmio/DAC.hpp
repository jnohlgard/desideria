/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct DAC_regs {
  enum class CTL_bits : uint32_t;
  enum class SWT_bits : uint32_t;
  enum class DAC0_R12DH_bits : uint32_t;
  enum class DAC0_L12DH_bits : uint32_t;
  enum class DAC0_R8DH_bits : uint32_t;
  enum class DAC1_R12DH_bits : uint32_t;
  enum class DAC1_L12DH_bits : uint32_t;
  enum class DAC1_R8DH_bits : uint32_t;
  enum class DACC_R12DH_bits : uint32_t;
  enum class DACC_L12DH_bits : uint32_t;
  enum class DACC_R8DH_bits : uint32_t;
  enum class DAC0_DO_bits : uint32_t;
  enum class DAC1_DO_bits : uint32_t;
  enum class CTL_shift : unsigned;
  enum class SWT_shift : unsigned;
  enum class DAC0_R12DH_shift : unsigned;
  enum class DAC0_L12DH_shift : unsigned;
  enum class DAC0_R8DH_shift : unsigned;
  enum class DAC1_R12DH_shift : unsigned;
  enum class DAC1_L12DH_shift : unsigned;
  enum class DAC1_R8DH_shift : unsigned;
  enum class DACC_R12DH_shift : unsigned;
  enum class DACC_L12DH_shift : unsigned;
  enum class DACC_R8DH_shift : unsigned;
  enum class DAC0_DO_shift : unsigned;
  enum class DAC1_DO_shift : unsigned;

  Register<CTL_bits> CTL;
  Register<SWT_bits> SWT;
  Register<DAC0_R12DH_bits> DAC0_R12DH;
  Register<DAC0_L12DH_bits> DAC0_L12DH;
  Register<DAC0_R8DH_bits> DAC0_R8DH;
  Register<DAC1_R12DH_bits> DAC1_R12DH;
  Register<DAC1_L12DH_bits> DAC1_L12DH;
  Register<DAC1_R8DH_bits> DAC1_R8DH;
  Register<DACC_R12DH_bits> DACC_R12DH;
  Register<DACC_L12DH_bits> DACC_L12DH;
  Register<DACC_R8DH_bits> DACC_R8DH;
  const Register<DAC0_DO_bits> DAC0_DO;
  const Register<DAC1_DO_bits> DAC1_DO;
};
}  // namespace deri::mmio
