/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/ECLIC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for ECLIC CLICCFG
 *
 * cliccfg Register
 */
enum class ECLIC_regs::CLICCFG_bits : uint8_t {
  NLBITS_mask = (0xf << 1),  ///< NLBITS
  Reserved_mask = 0xe1       ///< All reserved bits
};
void HasBitwiseOperators(ECLIC_regs::CLICCFG_bits);

/**
 * Bit shifts for ECLIC CLICCFG
 */
enum class ECLIC_regs::CLICCFG_shift : unsigned {
  NLBITS = 1,
};

/**
 * Bitmasks for ECLIC CLICINFO
 *
 * clicinfo Register
 */
enum class ECLIC_regs::CLICINFO_bits : uint32_t {
  NUM_INTERRUPT_mask = (0x1fff << 0),  ///< NUM_INTERRUPT
  VERSION_mask = (0xff << 13),         ///< VERSION
  CLICINTCTLBITS_mask = (0xf << 21),   ///< CLICINTCTLBITS
  Reserved_mask = 0xfe000000           ///< All reserved bits
};
void HasBitwiseOperators(ECLIC_regs::CLICINFO_bits);

/**
 * Bit shifts for ECLIC CLICINFO
 */
enum class ECLIC_regs::CLICINFO_shift : unsigned {
  NUM_INTERRUPT = 0,
  VERSION = 13,
  CLICINTCTLBITS = 21,
};

/**
 * Bitmasks for ECLIC MTH
 *
 * MTH Register
 */
enum class ECLIC_regs::MTH_bits : uint8_t {
  MTH_mask = (0xff << 0),  ///< MTH
};
void HasBitwiseOperators(ECLIC_regs::MTH_bits);

/**
 * Bit shifts for ECLIC MTH
 */
enum class ECLIC_regs::MTH_shift : unsigned {
  MTH = 0,
};

/**
 * Bitmasks for ECLIC_CLICINT CLICINTIP
 *
 * The clicintip[i] register is the pending flag register for the interrupt
 * source.
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTIP_bits : uint8_t {
  IP = (1 << 0),        ///< IP
  Reserved_mask = 0xfe  ///< All reserved bits
};
void HasBitwiseOperators(ECLIC_regs::CLICINT_regs::CLICINTIP_bits);

/**
 * Bit shifts for ECLIC_CLICINT CLICINTIP
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTIP_shift : unsigned {
  IP = 0,
};

/**
 * Bitmasks for ECLIC_CLICINT CLICINTIE
 *
 * The clicintie[i] register is the enable bit register for the interrupt
 * source.
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTIE_bits : uint8_t {
  IE = (1 << 0),        ///< IE
  Reserved_mask = 0xfe  ///< All reserved bits
};
void HasBitwiseOperators(ECLIC_regs::CLICINT_regs::CLICINTIE_bits);

/**
 * Bit shifts for ECLIC_CLICINT CLICINTIE
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTIE_shift : unsigned {
  IE = 0,
};

/**
 * Bitmasks for ECLIC_CLICINT CLICINTATTR
 *
 * The clicintattr[i] register is used to indicate the attribute of the
 * interrupt source. The software can set the attribute of the interrupt source
 * by writing this register.
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTATTR_bits : uint8_t {
  SHV = (1 << 0),          ///< SHV
  TRIG_mask = (0x3 << 1),  ///< TRIG
  Reserved_mask = 0xf8     ///< All reserved bits
};
void HasBitwiseOperators(ECLIC_regs::CLICINT_regs::CLICINTATTR_bits);

/**
 * Bit shifts for ECLIC_CLICINT CLICINTATTR
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTATTR_shift : unsigned {
  SHV = 0,
  TRIG = 1,
};

/**
 * Bitmasks for ECLIC_CLICINT CLICINTCTL
 *
 * The clicintctl[i] register is the control register of the interrupt source.
 * The software can set the level and priority by writing this register. The
 * level and priority field are dynamically allocated based on the value of
 * cliccfg.nlbits. Please see ECLIC Interrupt Level and Priority for more
 * details.
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTCTL_bits : uint8_t {
  LEVEL_PRIORITY_mask = (0xff << 0),  ///< LEVEL_PRIORITY
};
void HasBitwiseOperators(ECLIC_regs::CLICINT_regs::CLICINTCTL_bits);

/**
 * Bit shifts for ECLIC_CLICINT CLICINTCTL
 */
enum class ECLIC_regs::CLICINT_regs::CLICINTCTL_shift : unsigned {
  LEVEL_PRIORITY = 0,
};

static_assert(offsetof(ECLIC_regs, CLICCFG) == 0x0);
static_assert(offsetof(ECLIC_regs, CLICINFO) == 0x4);
static_assert(offsetof(ECLIC_regs, MTH) == 0xb);
static_assert(offsetof(ECLIC_regs, CLICINT) == 0x1000);
static_assert(offsetof(ECLIC_regs::CLICINT_regs, CLICINTIP) == 0x0);
static_assert(offsetof(ECLIC_regs::CLICINT_regs, CLICINTIE) == 0x1);
static_assert(offsetof(ECLIC_regs::CLICINT_regs, CLICINTATTR) == 0x2);
static_assert(offsetof(ECLIC_regs::CLICINT_regs, CLICINTCTL) == 0x3);
}  // namespace deri::mmio
