/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/DAC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for DAC CTL
 *
 * control register
 */
enum class DAC_regs::CTL_bits : uint32_t {
  DEN0 = (1u << 0),            ///< DAC0 enable
  DBOFF0 = (1u << 1),          ///< DAC0 output buffer turn off
  DTEN0 = (1u << 2),           ///< DAC0 trigger enable
  DTSEL0_mask = (0x7u << 3),   ///< DAC0 trigger selection
  DWM0_mask = (0x3u << 6),     ///< DAC0 noise wave mode
  DWBW0_mask = (0xfu << 8),    ///< DAC0 noise wave bit width
  DDMAEN0 = (1u << 12),        ///< DAC0 DMA enable
  DEN1 = (1u << 16),           ///< DAC1 enable
  DBOFF1 = (1u << 17),         ///< DAC1 output buffer turn off
  DTEN1 = (1u << 18),          ///< DAC1 trigger enable
  DTSEL1_mask = (0x7u << 19),  ///< DAC1 trigger selection
  DWM1_mask = (0x3u << 22),    ///< DAC1 noise wave mode
  DWBW1_mask = (0xfu << 24),   ///< DAC1 noise wave bit width
  DDMAEN1 = (1u << 28),        ///< DAC1 DMA enable
  Reserved_mask = 0xe000e000   ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::CTL_bits);

/**
 * Bit shifts for DAC CTL
 */
enum class DAC_regs::CTL_shift : unsigned {
  DEN0 = 0,
  DBOFF0 = 1,
  DTEN0 = 2,
  DTSEL0 = 3,
  DWM0 = 6,
  DWBW0 = 8,
  DDMAEN0 = 12,
  DEN1 = 16,
  DBOFF1 = 17,
  DTEN1 = 18,
  DTSEL1 = 19,
  DWM1 = 22,
  DWBW1 = 24,
  DDMAEN1 = 28,
};

/**
 * Bitmasks for DAC SWT
 *
 * software trigger register
 */
enum class DAC_regs::SWT_bits : uint32_t {
  SWTR0 = (1u << 0),          ///< DAC0 software trigger
  SWTR1 = (1u << 1),          ///< DAC1 software trigger
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::SWT_bits);

/**
 * Bit shifts for DAC SWT
 */
enum class DAC_regs::SWT_shift : unsigned {
  SWTR0 = 0,
  SWTR1 = 1,
};

/**
 * Bitmasks for DAC DAC0_R12DH
 *
 * DAC0 12-bit right-aligned data holding register
 */
enum class DAC_regs::DAC0_R12DH_bits : uint32_t {
  DAC0_DH_mask = (0xfffu << 0),  ///< DAC0 12-bit right-aligned data
  Reserved_mask = 0xfffff000     ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC0_R12DH_bits);

/**
 * Bit shifts for DAC DAC0_R12DH
 */
enum class DAC_regs::DAC0_R12DH_shift : unsigned {
  DAC0_DH = 0,
};

/**
 * Bitmasks for DAC DAC0_L12DH
 *
 * DAC0 12-bit left-aligned data holding register
 */
enum class DAC_regs::DAC0_L12DH_bits : uint32_t {
  DAC0_DH_mask = (0xfffu << 4),  ///< DAC0 12-bit left-aligned data
  Reserved_mask = 0xffff000f     ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC0_L12DH_bits);

/**
 * Bit shifts for DAC DAC0_L12DH
 */
enum class DAC_regs::DAC0_L12DH_shift : unsigned {
  DAC0_DH = 4,
};

/**
 * Bitmasks for DAC DAC0_R8DH
 *
 * DAC0 8-bit right aligned data holding register
 */
enum class DAC_regs::DAC0_R8DH_bits : uint32_t {
  DAC0_DH_mask = (0xffu << 0),  ///< DAC0 8-bit right-aligned data
  Reserved_mask = 0xffffff00    ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC0_R8DH_bits);

/**
 * Bit shifts for DAC DAC0_R8DH
 */
enum class DAC_regs::DAC0_R8DH_shift : unsigned {
  DAC0_DH = 0,
};

/**
 * Bitmasks for DAC DAC1_R12DH
 *
 * DAC1 12-bit right-aligned data holding register
 */
enum class DAC_regs::DAC1_R12DH_bits : uint32_t {
  DAC1_DH_mask = (0xfffu << 0),  ///< DAC1 12-bit right-aligned data
  Reserved_mask = 0xfffff000     ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC1_R12DH_bits);

/**
 * Bit shifts for DAC DAC1_R12DH
 */
enum class DAC_regs::DAC1_R12DH_shift : unsigned {
  DAC1_DH = 0,
};

/**
 * Bitmasks for DAC DAC1_L12DH
 *
 * DAC1 12-bit left aligned data holding register
 */
enum class DAC_regs::DAC1_L12DH_bits : uint32_t {
  DAC1_DH_mask = (0xfffu << 4),  ///< DAC1 12-bit left-aligned data
  Reserved_mask = 0xffff000f     ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC1_L12DH_bits);

/**
 * Bit shifts for DAC DAC1_L12DH
 */
enum class DAC_regs::DAC1_L12DH_shift : unsigned {
  DAC1_DH = 4,
};

/**
 * Bitmasks for DAC DAC1_R8DH
 *
 * DAC1 8-bit right aligned data holding register
 */
enum class DAC_regs::DAC1_R8DH_bits : uint32_t {
  DAC1_DH_mask = (0xffu << 0),  ///< DAC1 8-bit right-aligned data
  Reserved_mask = 0xffffff00    ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC1_R8DH_bits);

/**
 * Bit shifts for DAC DAC1_R8DH
 */
enum class DAC_regs::DAC1_R8DH_shift : unsigned {
  DAC1_DH = 0,
};

/**
 * Bitmasks for DAC DACC_R12DH
 *
 * DAC concurrent mode 12-bit right-aligned data holding register
 */
enum class DAC_regs::DACC_R12DH_bits : uint32_t {
  DAC0_DH_mask = (0xfffu << 0),   ///< DAC0 12-bit right-aligned data
  DAC1_DH_mask = (0xfffu << 16),  ///< DAC1 12-bit right-aligned data
  Reserved_mask = 0xf000f000      ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DACC_R12DH_bits);

/**
 * Bit shifts for DAC DACC_R12DH
 */
enum class DAC_regs::DACC_R12DH_shift : unsigned {
  DAC0_DH = 0,
  DAC1_DH = 16,
};

/**
 * Bitmasks for DAC DACC_L12DH
 *
 * DAC concurrent mode 12-bit left aligned data holding register
 */
enum class DAC_regs::DACC_L12DH_bits : uint32_t {
  DAC0_DH_mask = (0xfffu << 4),   ///< DAC0 12-bit left-aligned data
  DAC1_DH_mask = (0xfffu << 20),  ///< DAC1 12-bit left-aligned data
  Reserved_mask = 0x000f000f      ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DACC_L12DH_bits);

/**
 * Bit shifts for DAC DACC_L12DH
 */
enum class DAC_regs::DACC_L12DH_shift : unsigned {
  DAC0_DH = 4,
  DAC1_DH = 20,
};

/**
 * Bitmasks for DAC DACC_R8DH
 *
 * DAC concurrent mode 8-bit right aligned data holding register
 */
enum class DAC_regs::DACC_R8DH_bits : uint32_t {
  DAC0_DH_mask = (0xffu << 0),  ///< DAC0 8-bit right-aligned data
  DAC1_DH_mask = (0xffu << 8),  ///< DAC1 8-bit right-aligned data
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DACC_R8DH_bits);

/**
 * Bit shifts for DAC DACC_R8DH
 */
enum class DAC_regs::DACC_R8DH_shift : unsigned {
  DAC0_DH = 0,
  DAC1_DH = 8,
};

/**
 * Bitmasks for DAC DAC0_DO
 *
 * DAC0 data output register
 */
enum class DAC_regs::DAC0_DO_bits : uint32_t {
  DAC0_DO_mask = (0xfffu << 0),  ///< DAC0 data output
  Reserved_mask = 0xfffff000     ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC0_DO_bits);

/**
 * Bit shifts for DAC DAC0_DO
 */
enum class DAC_regs::DAC0_DO_shift : unsigned {
  DAC0_DO = 0,
};

/**
 * Bitmasks for DAC DAC1_DO
 *
 * DAC1 data output register
 */
enum class DAC_regs::DAC1_DO_bits : uint32_t {
  DAC1_DO_mask = (0xfffu << 0),  ///< DAC1 data output
  Reserved_mask = 0xfffff000     ///< All reserved bits
};
void HasBitwiseOperators(DAC_regs::DAC1_DO_bits);

/**
 * Bit shifts for DAC DAC1_DO
 */
enum class DAC_regs::DAC1_DO_shift : unsigned {
  DAC1_DO = 0,
};

static_assert(offsetof(DAC_regs, CTL) == 0x0);
static_assert(offsetof(DAC_regs, SWT) == 0x4);
static_assert(offsetof(DAC_regs, DAC0_R12DH) == 0x8);
static_assert(offsetof(DAC_regs, DAC0_L12DH) == 0xc);
static_assert(offsetof(DAC_regs, DAC0_R8DH) == 0x10);
static_assert(offsetof(DAC_regs, DAC1_R12DH) == 0x14);
static_assert(offsetof(DAC_regs, DAC1_L12DH) == 0x18);
static_assert(offsetof(DAC_regs, DAC1_R8DH) == 0x1c);
static_assert(offsetof(DAC_regs, DACC_R12DH) == 0x20);
static_assert(offsetof(DAC_regs, DACC_L12DH) == 0x24);
static_assert(offsetof(DAC_regs, DACC_R8DH) == 0x28);
static_assert(offsetof(DAC_regs, DAC0_DO) == 0x2c);
static_assert(offsetof(DAC_regs, DAC1_DO) == 0x30);
}  // namespace deri::mmio
