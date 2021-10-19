/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct EXTI_regs {
  enum class INTEN_bits : uint32_t;
  enum class EVEN_bits : uint32_t;
  enum class RTEN_bits : uint32_t;
  enum class FTEN_bits : uint32_t;
  enum class SWIEV_bits : uint32_t;
  enum class PD_bits : uint32_t;
  enum class INTEN_shift : unsigned;
  enum class EVEN_shift : unsigned;
  enum class RTEN_shift : unsigned;
  enum class FTEN_shift : unsigned;
  enum class SWIEV_shift : unsigned;
  enum class PD_shift : unsigned;

  Register<INTEN_bits> INTEN;
  Register<EVEN_bits> EVEN;
  Register<RTEN_bits> RTEN;
  Register<FTEN_bits> FTEN;
  Register<SWIEV_bits> SWIEV;
  Register<PD_bits> PD;
};
}  // namespace deri::mmio
