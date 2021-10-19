/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/BKP.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for BKP DATA0
 *
 * Backup data register 0
 */
enum class BKP_regs::DATA0_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA0_bits);

/**
 * Bit shifts for BKP DATA0
 */
enum class BKP_regs::DATA0_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA1
 *
 * Backup data register 1
 */
enum class BKP_regs::DATA1_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA1_bits);

/**
 * Bit shifts for BKP DATA1
 */
enum class BKP_regs::DATA1_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA2
 *
 * Backup data register 2
 */
enum class BKP_regs::DATA2_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA2_bits);

/**
 * Bit shifts for BKP DATA2
 */
enum class BKP_regs::DATA2_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA3
 *
 * Backup data register 3
 */
enum class BKP_regs::DATA3_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA3_bits);

/**
 * Bit shifts for BKP DATA3
 */
enum class BKP_regs::DATA3_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA4
 *
 * Backup data register 4
 */
enum class BKP_regs::DATA4_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA4_bits);

/**
 * Bit shifts for BKP DATA4
 */
enum class BKP_regs::DATA4_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA5
 *
 * Backup data register 5
 */
enum class BKP_regs::DATA5_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA5_bits);

/**
 * Bit shifts for BKP DATA5
 */
enum class BKP_regs::DATA5_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA6
 *
 * Backup data register 6
 */
enum class BKP_regs::DATA6_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA6_bits);

/**
 * Bit shifts for BKP DATA6
 */
enum class BKP_regs::DATA6_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA7
 *
 * Backup data register 7
 */
enum class BKP_regs::DATA7_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA7_bits);

/**
 * Bit shifts for BKP DATA7
 */
enum class BKP_regs::DATA7_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA8
 *
 * Backup data register 8
 */
enum class BKP_regs::DATA8_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA8_bits);

/**
 * Bit shifts for BKP DATA8
 */
enum class BKP_regs::DATA8_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA9
 *
 * Backup data register 9
 */
enum class BKP_regs::DATA9_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA9_bits);

/**
 * Bit shifts for BKP DATA9
 */
enum class BKP_regs::DATA9_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP OCTL
 *
 * RTC signal output control register
 */
enum class BKP_regs::OCTL_bits : uint16_t {
  ROSEL = (1 << 9),         ///< RTC output selection
  ASOEN = (1 << 8),         ///< RTC alarm or second signal output enable
  COEN = (1 << 7),          ///< RTC clock calibration output enable
  RCCV_mask = (0x7f << 0),  ///< RTC clock calibration value
  Reserved_mask = 0xfc00    ///< All reserved bits
};
void HasBitwiseOperators(BKP_regs::OCTL_bits);

/**
 * Bit shifts for BKP OCTL
 */
enum class BKP_regs::OCTL_shift : unsigned {
  ROSEL = 9,
  ASOEN = 8,
  COEN = 7,
  RCCV = 0,
};

/**
 * Bitmasks for BKP TPCTL
 *
 * Tamper pin control register
 */
enum class BKP_regs::TPCTL_bits : uint16_t {
  TPAL = (1 << 1),        ///< TAMPER pin active level
  TPEN = (1 << 0),        ///< TAMPER detection enable
  Reserved_mask = 0xfffc  ///< All reserved bits
};
void HasBitwiseOperators(BKP_regs::TPCTL_bits);

/**
 * Bit shifts for BKP TPCTL
 */
enum class BKP_regs::TPCTL_shift : unsigned {
  TPAL = 1,
  TPEN = 0,
};

/**
 * Bitmasks for BKP TPCS
 *
 * Tamper control and status register
 */
enum class BKP_regs::TPCS_bits : uint16_t {
  TIF = (1 << 9),         ///< Tamper interrupt flag
  TEF = (1 << 8),         ///< Tamper event flag
  TPIE = (1 << 2),        ///< Tamper interrupt enable
  TIR = (1 << 1),         ///< Tamper interrupt reset
  TER = (1 << 0),         ///< Tamper event reset
  Reserved_mask = 0xfcf8  ///< All reserved bits
};
void HasBitwiseOperators(BKP_regs::TPCS_bits);

/**
 * Bit shifts for BKP TPCS
 */
enum class BKP_regs::TPCS_shift : unsigned {
  TIF = 9,
  TEF = 8,
  TPIE = 2,
  TIR = 1,
  TER = 0,
};

/**
 * Bitmasks for BKP DATA10
 *
 * Backup data register 10
 */
enum class BKP_regs::DATA10_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA10_bits);

/**
 * Bit shifts for BKP DATA10
 */
enum class BKP_regs::DATA10_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA11
 *
 * Backup data register 11
 */
enum class BKP_regs::DATA11_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA11_bits);

/**
 * Bit shifts for BKP DATA11
 */
enum class BKP_regs::DATA11_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA12
 *
 * Backup data register 12
 */
enum class BKP_regs::DATA12_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA12_bits);

/**
 * Bit shifts for BKP DATA12
 */
enum class BKP_regs::DATA12_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA13
 *
 * Backup data register 13
 */
enum class BKP_regs::DATA13_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA13_bits);

/**
 * Bit shifts for BKP DATA13
 */
enum class BKP_regs::DATA13_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA14
 *
 * Backup data register 14
 */
enum class BKP_regs::DATA14_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA14_bits);

/**
 * Bit shifts for BKP DATA14
 */
enum class BKP_regs::DATA14_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA15
 *
 * Backup data register 15
 */
enum class BKP_regs::DATA15_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA15_bits);

/**
 * Bit shifts for BKP DATA15
 */
enum class BKP_regs::DATA15_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA16
 *
 * Backup data register 16
 */
enum class BKP_regs::DATA16_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA16_bits);

/**
 * Bit shifts for BKP DATA16
 */
enum class BKP_regs::DATA16_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA17
 *
 * Backup data register 17
 */
enum class BKP_regs::DATA17_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA17_bits);

/**
 * Bit shifts for BKP DATA17
 */
enum class BKP_regs::DATA17_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA18
 *
 * Backup data register 18
 */
enum class BKP_regs::DATA18_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA18_bits);

/**
 * Bit shifts for BKP DATA18
 */
enum class BKP_regs::DATA18_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA19
 *
 * Backup data register 19
 */
enum class BKP_regs::DATA19_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA19_bits);

/**
 * Bit shifts for BKP DATA19
 */
enum class BKP_regs::DATA19_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA20
 *
 * Backup data register 20
 */
enum class BKP_regs::DATA20_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA20_bits);

/**
 * Bit shifts for BKP DATA20
 */
enum class BKP_regs::DATA20_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA21
 *
 * Backup data register 21
 */
enum class BKP_regs::DATA21_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA21_bits);

/**
 * Bit shifts for BKP DATA21
 */
enum class BKP_regs::DATA21_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA22
 *
 * Backup data register 22
 */
enum class BKP_regs::DATA22_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA22_bits);

/**
 * Bit shifts for BKP DATA22
 */
enum class BKP_regs::DATA22_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA23
 *
 * Backup data register 23
 */
enum class BKP_regs::DATA23_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA23_bits);

/**
 * Bit shifts for BKP DATA23
 */
enum class BKP_regs::DATA23_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA24
 *
 * Backup data register 24
 */
enum class BKP_regs::DATA24_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA24_bits);

/**
 * Bit shifts for BKP DATA24
 */
enum class BKP_regs::DATA24_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA25
 *
 * Backup data register 25
 */
enum class BKP_regs::DATA25_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA25_bits);

/**
 * Bit shifts for BKP DATA25
 */
enum class BKP_regs::DATA25_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA26
 *
 * Backup data register 26
 */
enum class BKP_regs::DATA26_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA26_bits);

/**
 * Bit shifts for BKP DATA26
 */
enum class BKP_regs::DATA26_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA27
 *
 * Backup data register 27
 */
enum class BKP_regs::DATA27_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA27_bits);

/**
 * Bit shifts for BKP DATA27
 */
enum class BKP_regs::DATA27_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA28
 *
 * Backup data register 28
 */
enum class BKP_regs::DATA28_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA28_bits);

/**
 * Bit shifts for BKP DATA28
 */
enum class BKP_regs::DATA28_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA29
 *
 * Backup data register 29
 */
enum class BKP_regs::DATA29_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA29_bits);

/**
 * Bit shifts for BKP DATA29
 */
enum class BKP_regs::DATA29_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA30
 *
 * Backup data register 30
 */
enum class BKP_regs::DATA30_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA30_bits);

/**
 * Bit shifts for BKP DATA30
 */
enum class BKP_regs::DATA30_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA31
 *
 * Backup data register 31
 */
enum class BKP_regs::DATA31_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA31_bits);

/**
 * Bit shifts for BKP DATA31
 */
enum class BKP_regs::DATA31_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA32
 *
 * Backup data register 32
 */
enum class BKP_regs::DATA32_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA32_bits);

/**
 * Bit shifts for BKP DATA32
 */
enum class BKP_regs::DATA32_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA33
 *
 * Backup data register 33
 */
enum class BKP_regs::DATA33_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA33_bits);

/**
 * Bit shifts for BKP DATA33
 */
enum class BKP_regs::DATA33_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA34
 *
 * Backup data register 34
 */
enum class BKP_regs::DATA34_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA34_bits);

/**
 * Bit shifts for BKP DATA34
 */
enum class BKP_regs::DATA34_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA35
 *
 * Backup data register 35
 */
enum class BKP_regs::DATA35_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA35_bits);

/**
 * Bit shifts for BKP DATA35
 */
enum class BKP_regs::DATA35_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA36
 *
 * Backup data register 36
 */
enum class BKP_regs::DATA36_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA36_bits);

/**
 * Bit shifts for BKP DATA36
 */
enum class BKP_regs::DATA36_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA37
 *
 * Backup data register 37
 */
enum class BKP_regs::DATA37_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA37_bits);

/**
 * Bit shifts for BKP DATA37
 */
enum class BKP_regs::DATA37_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA38
 *
 * Backup data register 38
 */
enum class BKP_regs::DATA38_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA38_bits);

/**
 * Bit shifts for BKP DATA38
 */
enum class BKP_regs::DATA38_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA39
 *
 * Backup data register 39
 */
enum class BKP_regs::DATA39_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA39_bits);

/**
 * Bit shifts for BKP DATA39
 */
enum class BKP_regs::DATA39_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA40
 *
 * Backup data register 40
 */
enum class BKP_regs::DATA40_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA40_bits);

/**
 * Bit shifts for BKP DATA40
 */
enum class BKP_regs::DATA40_shift : unsigned {
  DATA = 0,
};

/**
 * Bitmasks for BKP DATA41
 *
 * Backup data register 41
 */
enum class BKP_regs::DATA41_bits : uint16_t {
  DATA_mask = (0xffff << 0),  ///< Backup data
};
void HasBitwiseOperators(BKP_regs::DATA41_bits);

/**
 * Bit shifts for BKP DATA41
 */
enum class BKP_regs::DATA41_shift : unsigned {
  DATA = 0,
};

static_assert(offsetof(BKP_regs, DATA0) == 0x4);
static_assert(offsetof(BKP_regs, DATA1) == 0x8);
static_assert(offsetof(BKP_regs, DATA2) == 0xc);
static_assert(offsetof(BKP_regs, DATA3) == 0x10);
static_assert(offsetof(BKP_regs, DATA4) == 0x14);
static_assert(offsetof(BKP_regs, DATA5) == 0x18);
static_assert(offsetof(BKP_regs, DATA6) == 0x1c);
static_assert(offsetof(BKP_regs, DATA7) == 0x20);
static_assert(offsetof(BKP_regs, DATA8) == 0x24);
static_assert(offsetof(BKP_regs, DATA9) == 0x28);
static_assert(offsetof(BKP_regs, DATA10) == 0x40);
static_assert(offsetof(BKP_regs, DATA11) == 0x44);
static_assert(offsetof(BKP_regs, DATA12) == 0x48);
static_assert(offsetof(BKP_regs, DATA13) == 0x4c);
static_assert(offsetof(BKP_regs, DATA14) == 0x50);
static_assert(offsetof(BKP_regs, DATA15) == 0x54);
static_assert(offsetof(BKP_regs, DATA16) == 0x58);
static_assert(offsetof(BKP_regs, DATA17) == 0x5c);
static_assert(offsetof(BKP_regs, DATA18) == 0x60);
static_assert(offsetof(BKP_regs, DATA19) == 0x64);
static_assert(offsetof(BKP_regs, DATA20) == 0x68);
static_assert(offsetof(BKP_regs, DATA21) == 0x6c);
static_assert(offsetof(BKP_regs, DATA22) == 0x70);
static_assert(offsetof(BKP_regs, DATA23) == 0x74);
static_assert(offsetof(BKP_regs, DATA24) == 0x78);
static_assert(offsetof(BKP_regs, DATA25) == 0x7c);
static_assert(offsetof(BKP_regs, DATA26) == 0x80);
static_assert(offsetof(BKP_regs, DATA27) == 0x84);
static_assert(offsetof(BKP_regs, DATA28) == 0x88);
static_assert(offsetof(BKP_regs, DATA29) == 0x8c);
static_assert(offsetof(BKP_regs, DATA30) == 0x90);
static_assert(offsetof(BKP_regs, DATA31) == 0x94);
static_assert(offsetof(BKP_regs, DATA32) == 0x98);
static_assert(offsetof(BKP_regs, DATA33) == 0x9c);
static_assert(offsetof(BKP_regs, DATA34) == 0xa0);
static_assert(offsetof(BKP_regs, DATA35) == 0xa4);
static_assert(offsetof(BKP_regs, DATA36) == 0xa8);
static_assert(offsetof(BKP_regs, DATA37) == 0xac);
static_assert(offsetof(BKP_regs, DATA38) == 0xb0);
static_assert(offsetof(BKP_regs, DATA39) == 0xb4);
static_assert(offsetof(BKP_regs, DATA40) == 0xb8);
static_assert(offsetof(BKP_regs, DATA41) == 0xbc);
static_assert(offsetof(BKP_regs, OCTL) == 0x2c);
static_assert(offsetof(BKP_regs, TPCTL) == 0x30);
static_assert(offsetof(BKP_regs, TPCS) == 0x34);
}  // namespace deri::mmio
