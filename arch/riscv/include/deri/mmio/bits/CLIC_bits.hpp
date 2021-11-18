/*
 * Copyright (C) 2021 Joakim Nohlgård <joakim@nohlgard.se>
 */
#pragma once

#include "deri/mmio/CLIC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * CLIC Configuration
 *
 * Defines how many privilege modes are supported, how the @c clicintctl[i]
 * registers are subdivided into level and priority fields, and whether
 * selective hardware vectoring is supported.
 */
enum class CLIC_regs::CLICCFG_bits : uint8_t {
  /// specifies whether the selective interrupt hardware vectoring feature is
  /// implemented or not.
  NVBITS = (0x1u << 0),

  /// indicates how many upper bits in clicintctl[i] are assigned to encode the
  /// interrupt level.
  NLBITS_mask = (0xfu << 1),

  /// specifies how many bits are physically implemented in clicintattr[i].mode
  /// to represent an input i's privilege mode
  NMBITS_mask = (0x3u << 5),
  Reserved_mask = 0xe1  ///< All reserved bits
};
void HasBitwiseOperators(CLIC_regs::CLICCFG_bits);

/**
 * Bit shifts for @c cliccfg
 */
enum class CLIC_regs::CLICCFG_shift : unsigned {
  NVBITS = 0,
  NLBITS = 1,
  NMBITS = 5,
};

/**
 * CLIC Information
 *
 * show information useful for debugging
 */
enum class CLIC_regs::CLICINFO_bits : uint32_t {
  /// number of maximum interrupt inputs supported
  NUM_INTERRUPT_mask = (0x1fffu << 0),
  /// version, 20:17 for architecture version, 16:13 for implementation version
  VERSION_mask = (0xffu << 13),
  /// specifies how many hardware bits are actually implemented in the
  /// clicintctl registers, with 0 ≤ CLICINTCTLBITS ≤ 8. The implemented bits
  /// are kept left-justified in the most-significant bits of each 8-bit
  /// clicintctl[i] register, with the lower unimplemented bits treated as
  /// hardwired to 1.
  CLICINTCTLBITS_mask = (0xfu << 21),
  /// specifies the number of maximum interrupt triggers supported in this
  /// implementation. Valid values are 0 to 32
  NUM_TRIGGER_mask = (0x3fu << 25),
  Reserved_mask = 0x80000000  ///< All reserved bits
};
void HasBitwiseOperators(CLIC_regs::CLICINFO_bits);

/**
 * Bit shifts for @c clicinfo
 */
enum class CLIC_regs::CLICINFO_shift : unsigned {
  NUM_INTERRUPT = 0,
  VERSION = 13,
  CLICINTCTLBITS = 21,
  NUM_TRIGGER = 25,
};

/**
 * CLIC Interrupt Trigger
 *
 * Optional interrupt triggers (clicinttrig[i]) are used to generate a
 * breakpoint exception, entry into Debug Mode, or a trace action. The actual
 * number of triggers supported is specified in clicinfo.num_trigger.
 */
enum class CLIC_regs::CLICINTTRIG_bits : uint32_t {
  /// selects which number of interrupt input is used as the source for this
  /// interrupt trigger.
  INTERRUPT_NUMBER_mask = (0x1fffu << 0),
  /// enable/disable this interrupt trigger.
  ENABLE = (1u << 31),
  Reserved_mask = 0x7fffe000  ///< All reserved bits
};

/**
 * Bit shifts for @c clicinttrig
 */
enum class CLIC_regs::CLICINTTRIG_shift : unsigned {
  INTERRUPT_NUMBER = 0,
  ENABLE = 31,
};

/**
 * CLIC Interrupt Pending
 *
 * The clicintip[i] register is the pending flag register for the interrupt
 * source.
 *
 * Software should assume clicintip[i]=0 means no interrupt pending, and
 * clicintip[i]!=0 indicates an interrupt is pending to accommodate possible
 * future expansion of the clicintip field.
 */
enum class CLIC_regs::CLICINT_regs::CLICINTIP_bits : uint8_t {
  IP = (1u << 0),       ///< Interrupt pending
  Reserved_mask = 0xfe  ///< All reserved bits
};
void HasBitwiseOperators(CLIC_regs::CLICINT_regs::CLICINTIP_bits);

/**
 * Bit shifts for CLICINTIP
 */
enum class CLIC_regs::CLICINT_regs::CLICINTIP_shift : unsigned {
  IP = 0,
};

/**
 * CLIC Interrupt Enable
 *
 * The clicintie[i] register is the enable bit register for the interrupt
 * source.
 *
 * Software should assume clicintie[i]=0 means no interrupt enabled, and
 * clicintie[i]!=0 indicates an interrupt is enabled to accommodate possible
 * future expansion of the clicintie field.
 */
enum class CLIC_regs::CLICINT_regs::CLICINTIE_bits : uint8_t {
  IE = (1u << 0),       ///< Interrupt enabled
  Reserved_mask = 0xfe  ///< All reserved bits
};
void HasBitwiseOperators(CLIC_regs::CLICINT_regs::CLICINTIE_bits);

/**
 * Bit shifts for CLICINTIE
 */
enum class CLIC_regs::CLICINT_regs::CLICINTIE_shift : unsigned {
  IE = 0,
};

/**
 * CLIC Interrupt Attribute
 *
 * The clicintattr[i] register is used to indicate the attribute of the
 * interrupt source. The software can set the attribute of the interrupt source
 * by writing this register.
 */
enum class CLIC_regs::CLICINT_regs::CLICINTATTR_bits : uint8_t {
  /// Selective Hardware Vectoring. If shv is 0, it assigns this interrupt to be
  /// non-vectored and thus it jumps to the common code at xtvec. If shv is 1,
  /// it assigns this interrupt to be hardware vectored and thus it
  /// automatically jumps to the trap-handler function pointer specified in xtvt
  /// CSR.
  SHV = (1u << 0),

  /// specifies the trigger type and polarity for each interrupt input. Bit 1,
  /// trig[0], is defined as "edge-triggered" (0: level-triggered, 1:
  /// edge-triggered); while bit 2, trig[1], is defined as "negative-edge" (0:
  /// positive-edge, 1: negative-edge).
  TRIG_mask = (0x3u << 1),

  /// specifies which privilege mode this interrupt operates in. This field uses
  /// the same encoding as the mstatus.mpp (11: machine mode, 01: supervisor
  /// mode, 00 user mode).
  MODE_mask = (0x3u << 6),

  Reserved_mask = 0x38  ///< All reserved bits
};
void HasBitwiseOperators(CLIC_regs::CLICINT_regs::CLICINTATTR_bits);

/**
 * Bit shifts for CLICINTATTR
 */
enum class CLIC_regs::CLICINT_regs::CLICINTATTR_shift : unsigned {
  SHV = 0,
  TRIG = 1,
  MODE = 6,
};

/**
 * Bitmasks for CLICINTCTL
 *
 * The clicintctl[i] register is the control register of the interrupt source.
 * The software can set the level and priority by writing this register. The
 * level and priority field are dynamically allocated based on the value of
 * cliccfg.nlbits. Please see ECLIC Interrupt Level and Priority for more
 * details.
 */
enum class CLIC_regs::CLICINT_regs::CLICINTCTL_bits : uint8_t {
  LEVEL_PRIORITY_mask = (0xffu << 0),  ///< LEVEL_PRIORITY
};
void HasBitwiseOperators(CLIC_regs::CLICINT_regs::CLICINTCTL_bits);

/**
 * Bit shifts for CLICINTCTL
 */
enum class CLIC_regs::CLICINT_regs::CLICINTCTL_shift : unsigned {
  LEVEL_PRIORITY = 0,
};

static_assert(offsetof(CLIC_regs, cliccfg) == 0x0);
static_assert(offsetof(CLIC_regs, clicinfo) == 0x4);
static_assert(offsetof(CLIC_regs, clicinttrig) == 0x40);
static_assert(offsetof(CLIC_regs, clicint) == 0x1000);
static_assert(offsetof(CLIC_regs::CLICINT_regs, clicintip) == 0x0);
static_assert(offsetof(CLIC_regs::CLICINT_regs, clicintie) == 0x1);
static_assert(offsetof(CLIC_regs::CLICINT_regs, clicintattr) == 0x2);
static_assert(offsetof(CLIC_regs::CLICINT_regs, clicintctl) == 0x3);
}  // namespace deri::mmio
