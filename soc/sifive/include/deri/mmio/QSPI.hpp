/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct QSPI_regs {
  enum class sckdiv_bits : uint32_t;
  enum class sckmode_bits : uint32_t;
  enum class csid_bits : uint32_t;
  enum class csdef_bits : uint32_t;
  enum class csmode_bits : uint32_t;
  enum class delay0_bits : uint32_t;
  enum class delay1_bits : uint32_t;
  enum class fmt_bits : uint32_t;
  enum class txdata_bits : uint32_t;
  enum class rxdata_bits : uint32_t;
  enum class txmark_bits : uint32_t;
  enum class rxmark_bits : uint32_t;
  enum class fctrl_bits : uint32_t;
  enum class ffmt_bits : uint32_t;
  enum class ie_bits : uint32_t;
  enum class ip_bits : uint32_t;
  enum class sckdiv_shift : unsigned;
  enum class sckmode_shift : unsigned;
  enum class csid_shift : unsigned;
  enum class csdef_shift : unsigned;
  enum class csmode_shift : unsigned;
  enum class delay0_shift : unsigned;
  enum class delay1_shift : unsigned;
  enum class fmt_shift : unsigned;
  enum class txdata_shift : unsigned;
  enum class rxdata_shift : unsigned;
  enum class txmark_shift : unsigned;
  enum class rxmark_shift : unsigned;
  enum class fctrl_shift : unsigned;
  enum class ffmt_shift : unsigned;
  enum class ie_shift : unsigned;
  enum class ip_shift : unsigned;

  Register<sckdiv_bits> sckdiv;
  Register<sckmode_bits> sckmode;
  const Reserved<uint32_t> reserved_0[2];
  // Base + 0x10
  Register<csid_bits> csid;
  Register<csdef_bits> csdef;
  Register<csmode_bits> csmode;
  const Reserved<uint32_t> reserved_1[3];
  // Base + 0x28
  Register<delay0_bits> delay0;
  Register<delay1_bits> delay1;
  const Reserved<uint32_t> reserved_2[4];
  // Base + 0x40
  Register<fmt_bits> fmt;
  const Reserved<uint32_t> reserved_3;
  // Base + 0x48
  Register<txdata_bits> txdata;
  Register<rxdata_bits> rxdata;
  Register<txmark_bits> txmark;
  Register<rxmark_bits> rxmark;
  const Reserved<uint32_t> reserved_4[2];
  // Base + 0x60
  Register<fctrl_bits> fctrl;
  Register<ffmt_bits> ffmt;
  const Reserved<uint32_t> reserved_5[2];
  // Base + 0x70
  Register<ie_bits> ie;
  Register<ip_bits> ip;
};
}  // namespace deri::mmio
