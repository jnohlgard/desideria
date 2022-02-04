/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct BKP_regs {
  enum class DATA0_bits : uint16_t;
  enum class DATA1_bits : uint16_t;
  enum class DATA2_bits : uint16_t;
  enum class DATA3_bits : uint16_t;
  enum class DATA4_bits : uint16_t;
  enum class DATA5_bits : uint16_t;
  enum class DATA6_bits : uint16_t;
  enum class DATA7_bits : uint16_t;
  enum class DATA8_bits : uint16_t;
  enum class DATA9_bits : uint16_t;
  enum class OCTL_bits : uint16_t;
  enum class TPCTL_bits : uint16_t;
  enum class TPCS_bits : uint16_t;
  enum class DATA10_bits : uint16_t;
  enum class DATA11_bits : uint16_t;
  enum class DATA12_bits : uint16_t;
  enum class DATA13_bits : uint16_t;
  enum class DATA14_bits : uint16_t;
  enum class DATA15_bits : uint16_t;
  enum class DATA16_bits : uint16_t;
  enum class DATA17_bits : uint16_t;
  enum class DATA18_bits : uint16_t;
  enum class DATA19_bits : uint16_t;
  enum class DATA20_bits : uint16_t;
  enum class DATA21_bits : uint16_t;
  enum class DATA22_bits : uint16_t;
  enum class DATA23_bits : uint16_t;
  enum class DATA24_bits : uint16_t;
  enum class DATA25_bits : uint16_t;
  enum class DATA26_bits : uint16_t;
  enum class DATA27_bits : uint16_t;
  enum class DATA28_bits : uint16_t;
  enum class DATA29_bits : uint16_t;
  enum class DATA30_bits : uint16_t;
  enum class DATA31_bits : uint16_t;
  enum class DATA32_bits : uint16_t;
  enum class DATA33_bits : uint16_t;
  enum class DATA34_bits : uint16_t;
  enum class DATA35_bits : uint16_t;
  enum class DATA36_bits : uint16_t;
  enum class DATA37_bits : uint16_t;
  enum class DATA38_bits : uint16_t;
  enum class DATA39_bits : uint16_t;
  enum class DATA40_bits : uint16_t;
  enum class DATA41_bits : uint16_t;
  enum class DATA0_shift : unsigned;
  enum class DATA1_shift : unsigned;
  enum class DATA2_shift : unsigned;
  enum class DATA3_shift : unsigned;
  enum class DATA4_shift : unsigned;
  enum class DATA5_shift : unsigned;
  enum class DATA6_shift : unsigned;
  enum class DATA7_shift : unsigned;
  enum class DATA8_shift : unsigned;
  enum class DATA9_shift : unsigned;
  enum class OCTL_shift : unsigned;
  enum class TPCTL_shift : unsigned;
  enum class TPCS_shift : unsigned;
  enum class DATA10_shift : unsigned;
  enum class DATA11_shift : unsigned;
  enum class DATA12_shift : unsigned;
  enum class DATA13_shift : unsigned;
  enum class DATA14_shift : unsigned;
  enum class DATA15_shift : unsigned;
  enum class DATA16_shift : unsigned;
  enum class DATA17_shift : unsigned;
  enum class DATA18_shift : unsigned;
  enum class DATA19_shift : unsigned;
  enum class DATA20_shift : unsigned;
  enum class DATA21_shift : unsigned;
  enum class DATA22_shift : unsigned;
  enum class DATA23_shift : unsigned;
  enum class DATA24_shift : unsigned;
  enum class DATA25_shift : unsigned;
  enum class DATA26_shift : unsigned;
  enum class DATA27_shift : unsigned;
  enum class DATA28_shift : unsigned;
  enum class DATA29_shift : unsigned;
  enum class DATA30_shift : unsigned;
  enum class DATA31_shift : unsigned;
  enum class DATA32_shift : unsigned;
  enum class DATA33_shift : unsigned;
  enum class DATA34_shift : unsigned;
  enum class DATA35_shift : unsigned;
  enum class DATA36_shift : unsigned;
  enum class DATA37_shift : unsigned;
  enum class DATA38_shift : unsigned;
  enum class DATA39_shift : unsigned;
  enum class DATA40_shift : unsigned;
  enum class DATA41_shift : unsigned;

  const Reserved<uint32_t> reserved_0;
  // Base + 0x4
  Register<DATA0_bits> DATA0;
  const Reserved<uint16_t> reserved_1;
  // Base + 0x8
  Register<DATA1_bits> DATA1;
  const Reserved<uint16_t> reserved_2;
  // Base + 0xc
  Register<DATA2_bits> DATA2;
  const Reserved<uint16_t> reserved_3;
  // Base + 0x10
  Register<DATA3_bits> DATA3;
  const Reserved<uint16_t> reserved_4;
  // Base + 0x14
  Register<DATA4_bits> DATA4;
  const Reserved<uint16_t> reserved_5;
  // Base + 0x18
  Register<DATA5_bits> DATA5;
  const Reserved<uint16_t> reserved_6;
  // Base + 0x1c
  Register<DATA6_bits> DATA6;
  const Reserved<uint16_t> reserved_7;
  // Base + 0x20
  Register<DATA7_bits> DATA7;
  const Reserved<uint16_t> reserved_8;
  // Base + 0x24
  Register<DATA8_bits> DATA8;
  const Reserved<uint16_t> reserved_9;
  // Base + 0x28
  Register<DATA9_bits> DATA9;
  const Reserved<uint16_t> reserved_10;
  // Base + 0x2c
  Register<OCTL_bits> OCTL;
  const Reserved<uint16_t> reserved_11;
  // Base + 0x30
  Register<TPCTL_bits> TPCTL;
  const Reserved<uint16_t> reserved_12;
  // Base + 0x34
  Register<TPCS_bits> TPCS;
  const Reserved<uint16_t> reserved_13;
  const Reserved<uint32_t> reserved_14[2];
  // Base + 0x40
  Register<DATA10_bits> DATA10;
  const Reserved<uint16_t> reserved_15;
  // Base + 0x44
  Register<DATA11_bits> DATA11;
  const Reserved<uint16_t> reserved_16;
  // Base + 0x48
  Register<DATA12_bits> DATA12;
  const Reserved<uint16_t> reserved_17;
  // Base + 0x4c
  Register<DATA13_bits> DATA13;
  const Reserved<uint16_t> reserved_18;
  // Base + 0x50
  Register<DATA14_bits> DATA14;
  const Reserved<uint16_t> reserved_19;
  // Base + 0x54
  Register<DATA15_bits> DATA15;
  const Reserved<uint16_t> reserved_20;
  // Base + 0x58
  Register<DATA16_bits> DATA16;
  const Reserved<uint16_t> reserved_21;
  // Base + 0x5c
  Register<DATA17_bits> DATA17;
  const Reserved<uint16_t> reserved_22;
  // Base + 0x60
  Register<DATA18_bits> DATA18;
  const Reserved<uint16_t> reserved_23;
  // Base + 0x64
  Register<DATA19_bits> DATA19;
  const Reserved<uint16_t> reserved_24;
  // Base + 0x68
  Register<DATA20_bits> DATA20;
  const Reserved<uint16_t> reserved_25;
  // Base + 0x6c
  Register<DATA21_bits> DATA21;
  const Reserved<uint16_t> reserved_26;
  // Base + 0x70
  Register<DATA22_bits> DATA22;
  const Reserved<uint16_t> reserved_27;
  // Base + 0x74
  Register<DATA23_bits> DATA23;
  const Reserved<uint16_t> reserved_28;
  // Base + 0x78
  Register<DATA24_bits> DATA24;
  const Reserved<uint16_t> reserved_29;
  // Base + 0x7c
  Register<DATA25_bits> DATA25;
  const Reserved<uint16_t> reserved_30;
  // Base + 0x80
  Register<DATA26_bits> DATA26;
  const Reserved<uint16_t> reserved_31;
  // Base + 0x84
  Register<DATA27_bits> DATA27;
  const Reserved<uint16_t> reserved_32;
  // Base + 0x88
  Register<DATA28_bits> DATA28;
  const Reserved<uint16_t> reserved_33;
  // Base + 0x8c
  Register<DATA29_bits> DATA29;
  const Reserved<uint16_t> reserved_34;
  // Base + 0x90
  Register<DATA30_bits> DATA30;
  const Reserved<uint16_t> reserved_35;
  // Base + 0x94
  Register<DATA31_bits> DATA31;
  const Reserved<uint16_t> reserved_36;
  // Base + 0x98
  Register<DATA32_bits> DATA32;
  const Reserved<uint16_t> reserved_37;
  // Base + 0x9c
  Register<DATA33_bits> DATA33;
  const Reserved<uint16_t> reserved_38;
  // Base + 0xa0
  Register<DATA34_bits> DATA34;
  const Reserved<uint16_t> reserved_39;
  // Base + 0xa4
  Register<DATA35_bits> DATA35;
  const Reserved<uint16_t> reserved_40;
  // Base + 0xa8
  Register<DATA36_bits> DATA36;
  const Reserved<uint16_t> reserved_41;
  // Base + 0xac
  Register<DATA37_bits> DATA37;
  const Reserved<uint16_t> reserved_42;
  // Base + 0xb0
  Register<DATA38_bits> DATA38;
  const Reserved<uint16_t> reserved_43;
  // Base + 0xb4
  Register<DATA39_bits> DATA39;
  const Reserved<uint16_t> reserved_44;
  // Base + 0xb8
  Register<DATA40_bits> DATA40;
  const Reserved<uint16_t> reserved_45;
  // Base + 0xbc
  Register<DATA41_bits> DATA41;
};
}  // namespace deri::mmio
