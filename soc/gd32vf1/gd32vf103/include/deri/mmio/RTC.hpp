/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct RTC_regs {
  enum class INTEN_bits : uint32_t;
  enum class CTL_bits : uint32_t;
  enum class PSCH_bits : uint32_t;
  enum class PSCL_bits : uint32_t;
  enum class DIVH_bits : uint32_t;
  enum class DIVL_bits : uint32_t;
  enum class CNTH_bits : uint32_t;
  enum class CNTL_bits : uint32_t;
  enum class ALRMH_bits : uint32_t;
  enum class ALRML_bits : uint32_t;
  enum class INTEN_shift : unsigned;
  enum class CTL_shift : unsigned;
  enum class PSCH_shift : unsigned;
  enum class PSCL_shift : unsigned;
  enum class DIVH_shift : unsigned;
  enum class DIVL_shift : unsigned;
  enum class CNTH_shift : unsigned;
  enum class CNTL_shift : unsigned;
  enum class ALRMH_shift : unsigned;
  enum class ALRML_shift : unsigned;

  Register<INTEN_bits> INTEN;
  Register<CTL_bits> CTL;
  Register<PSCH_bits> PSCH;
  Register<PSCL_bits> PSCL;
  const Register<DIVH_bits> DIVH;
  const Register<DIVL_bits> DIVL;
  Register<CNTH_bits> CNTH;
  Register<CNTL_bits> CNTL;
  Register<ALRMH_bits> ALRMH;
  Register<ALRML_bits> ALRML;
};
}  // namespace deri::mmio
