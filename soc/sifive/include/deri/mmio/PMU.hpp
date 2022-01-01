/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct PMU_regs {
  enum class pmuwakepm_bits : uint32_t;
  enum class pmusleeppm_bits : uint32_t;
  enum class pmuie_bits : uint32_t;
  enum class pmucause_bits : uint32_t;
  enum class pmusleep_bits : uint32_t;
  enum class pmukey_bits : uint32_t;
  enum class pmuwakepm_shift : unsigned;
  enum class pmusleeppm_shift : unsigned;
  enum class pmuie_shift : unsigned;
  enum class pmucause_shift : unsigned;
  enum class pmusleep_shift : unsigned;
  enum class pmukey_shift : unsigned;

  Register<pmuwakepm_bits> pmuwakepm[8];
  Register<pmusleeppm_bits> pmusleeppm[8];
  Register<pmuie_bits> pmuie;
  Register<pmucause_bits> pmucause;
  Register<pmusleep_bits> pmusleep;
  Register<pmukey_bits> pmukey;
};
}  // namespace deri::mmio
