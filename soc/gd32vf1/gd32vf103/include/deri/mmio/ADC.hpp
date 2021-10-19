/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct ADC_regs {
  enum class STAT_bits : uint32_t;
  enum class CTL0_bits : uint32_t;
  enum class CTL1_bits : uint32_t;
  enum class SAMPT0_bits : uint32_t;
  enum class SAMPT1_bits : uint32_t;
  enum class IOFF0_bits : uint32_t;
  enum class IOFF1_bits : uint32_t;
  enum class IOFF2_bits : uint32_t;
  enum class IOFF3_bits : uint32_t;
  enum class WDHT_bits : uint32_t;
  enum class WDLT_bits : uint32_t;
  enum class RSQ0_bits : uint32_t;
  enum class RSQ1_bits : uint32_t;
  enum class RSQ2_bits : uint32_t;
  enum class ISQ_bits : uint32_t;
  enum class IDATA0_bits : uint32_t;
  enum class IDATA1_bits : uint32_t;
  enum class IDATA2_bits : uint32_t;
  enum class IDATA3_bits : uint32_t;
  enum class RDATA_bits : uint32_t;
  enum class OVSAMPCTL_bits : uint32_t;
  enum class STAT_shift : unsigned;
  enum class CTL0_shift : unsigned;
  enum class CTL1_shift : unsigned;
  enum class SAMPT0_shift : unsigned;
  enum class SAMPT1_shift : unsigned;
  enum class IOFF0_shift : unsigned;
  enum class IOFF1_shift : unsigned;
  enum class IOFF2_shift : unsigned;
  enum class IOFF3_shift : unsigned;
  enum class WDHT_shift : unsigned;
  enum class WDLT_shift : unsigned;
  enum class RSQ0_shift : unsigned;
  enum class RSQ1_shift : unsigned;
  enum class RSQ2_shift : unsigned;
  enum class ISQ_shift : unsigned;
  enum class IDATA0_shift : unsigned;
  enum class IDATA1_shift : unsigned;
  enum class IDATA2_shift : unsigned;
  enum class IDATA3_shift : unsigned;
  enum class RDATA_shift : unsigned;
  enum class OVSAMPCTL_shift : unsigned;

  Register<STAT_bits> STAT;
  Register<CTL0_bits> CTL0;
  Register<CTL1_bits> CTL1;
  Register<SAMPT0_bits> SAMPT0;
  Register<SAMPT1_bits> SAMPT1;
  Register<IOFF0_bits> IOFF0;
  Register<IOFF1_bits> IOFF1;
  Register<IOFF2_bits> IOFF2;
  Register<IOFF3_bits> IOFF3;
  Register<WDHT_bits> WDHT;
  Register<WDLT_bits> WDLT;
  Register<RSQ0_bits> RSQ0;
  Register<RSQ1_bits> RSQ1;
  Register<RSQ2_bits> RSQ2;
  Register<ISQ_bits> ISQ;
  const Register<IDATA0_bits> IDATA0;
  const Register<IDATA1_bits> IDATA1;
  const Register<IDATA2_bits> IDATA2;
  const Register<IDATA3_bits> IDATA3;
  const Register<RDATA_bits> RDATA;
  const Reserved<uint32_t> reserved_0[12];
  // Base + 0x80
  Register<OVSAMPCTL_bits> OVSAMPCTL;
};
}  // namespace deri::mmio
