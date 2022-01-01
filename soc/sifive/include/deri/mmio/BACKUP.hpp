/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct BACKUP_regs {
  enum class backup_bits : uint32_t;
  enum class backup_shift : unsigned;

  Register<backup_bits> backup[16];
};
}  // namespace deri::mmio
