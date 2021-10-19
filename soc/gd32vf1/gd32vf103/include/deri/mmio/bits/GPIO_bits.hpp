/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/GPIO.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for GPIO CTL[2]
 *
 * port control register
 */
enum class GPIO_regs::CTL_bits : uint32_t {
  CTL7_mask = (0x3 << 30),  ///< Port x configuration bits (x = 7)
  MD7_mask = (0x3 << 28),   ///< Port x mode bits (x = 7)
  CTL6_mask = (0x3 << 26),  ///< Port x configuration bits (x = 6)
  MD6_mask = (0x3 << 24),   ///< Port x mode bits (x = 6)
  CTL5_mask = (0x3 << 22),  ///< Port x configuration bits (x = 5)
  MD5_mask = (0x3 << 20),   ///< Port x mode bits (x = 5)
  CTL4_mask = (0x3 << 18),  ///< Port x configuration bits (x = 4)
  MD4_mask = (0x3 << 16),   ///< Port x mode bits (x = 4)
  CTL3_mask = (0x3 << 14),  ///< Port x configuration bits (x = 3)
  MD3_mask = (0x3 << 12),   ///< Port x mode bits (x = 3 )
  CTL2_mask = (0x3 << 10),  ///< Port x configuration bits (x = 2)
  MD2_mask = (0x3 << 8),    ///< Port x mode bits (x = 2 )
  CTL1_mask = (0x3 << 6),   ///< Port x configuration bits (x = 1)
  MD1_mask = (0x3 << 4),    ///< Port x mode bits (x = 1)
  CTL0_mask = (0x3 << 2),   ///< Port x configuration bits (x = 0)
  MD0_mask = (0x3 << 0),    ///< Port x mode bits (x = 0)
};
void HasBitwiseOperators(GPIO_regs::CTL_bits);

/**
 * Bit shifts for GPIO CTL[2]
 */
enum class GPIO_regs::CTL_shift : unsigned {
  CTL7 = 30,
  MD7 = 28,
  CTL6 = 26,
  MD6 = 24,
  CTL5 = 22,
  MD5 = 20,
  CTL4 = 18,
  MD4 = 16,
  CTL3 = 14,
  MD3 = 12,
  CTL2 = 10,
  MD2 = 8,
  CTL1 = 6,
  MD1 = 4,
  CTL0 = 2,
  MD0 = 0,
};

/**
 * Bitmasks for GPIO ISTAT
 *
 * Port input status register
 */
enum class GPIO_regs::ISTAT_bits : uint32_t {
  ISTAT15 = (1 << 15),        ///< Port input status
  ISTAT14 = (1 << 14),        ///< Port input status
  ISTAT13 = (1 << 13),        ///< Port input status
  ISTAT12 = (1 << 12),        ///< Port input status
  ISTAT11 = (1 << 11),        ///< Port input status
  ISTAT10 = (1 << 10),        ///< Port input status
  ISTAT9 = (1 << 9),          ///< Port input status
  ISTAT8 = (1 << 8),          ///< Port input status
  ISTAT7 = (1 << 7),          ///< Port input status
  ISTAT6 = (1 << 6),          ///< Port input status
  ISTAT5 = (1 << 5),          ///< Port input status
  ISTAT4 = (1 << 4),          ///< Port input status
  ISTAT3 = (1 << 3),          ///< Port input status
  ISTAT2 = (1 << 2),          ///< Port input status
  ISTAT1 = (1 << 1),          ///< Port input status
  ISTAT0 = (1 << 0),          ///< Port input status
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(GPIO_regs::ISTAT_bits);

/**
 * Bit shifts for GPIO ISTAT
 */
enum class GPIO_regs::ISTAT_shift : unsigned {
  ISTAT15 = 15,
  ISTAT14 = 14,
  ISTAT13 = 13,
  ISTAT12 = 12,
  ISTAT11 = 11,
  ISTAT10 = 10,
  ISTAT9 = 9,
  ISTAT8 = 8,
  ISTAT7 = 7,
  ISTAT6 = 6,
  ISTAT5 = 5,
  ISTAT4 = 4,
  ISTAT3 = 3,
  ISTAT2 = 2,
  ISTAT1 = 1,
  ISTAT0 = 0,
};

/**
 * Bitmasks for GPIO OCTL
 *
 * Port output control register
 */
enum class GPIO_regs::OCTL_bits : uint32_t {
  OCTL15 = (1 << 15),         ///< Port output control
  OCTL14 = (1 << 14),         ///< Port output control
  OCTL13 = (1 << 13),         ///< Port output control
  OCTL12 = (1 << 12),         ///< Port output control
  OCTL11 = (1 << 11),         ///< Port output control
  OCTL10 = (1 << 10),         ///< Port output control
  OCTL9 = (1 << 9),           ///< Port output control
  OCTL8 = (1 << 8),           ///< Port output control
  OCTL7 = (1 << 7),           ///< Port output control
  OCTL6 = (1 << 6),           ///< Port output control
  OCTL5 = (1 << 5),           ///< Port output control
  OCTL4 = (1 << 4),           ///< Port output control
  OCTL3 = (1 << 3),           ///< Port output control
  OCTL2 = (1 << 2),           ///< Port output control
  OCTL1 = (1 << 1),           ///< Port output control
  OCTL0 = (1 << 0),           ///< Port output control
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(GPIO_regs::OCTL_bits);

/**
 * Bit shifts for GPIO OCTL
 */
enum class GPIO_regs::OCTL_shift : unsigned {
  OCTL15 = 15,
  OCTL14 = 14,
  OCTL13 = 13,
  OCTL12 = 12,
  OCTL11 = 11,
  OCTL10 = 10,
  OCTL9 = 9,
  OCTL8 = 8,
  OCTL7 = 7,
  OCTL6 = 6,
  OCTL5 = 5,
  OCTL4 = 4,
  OCTL3 = 3,
  OCTL2 = 2,
  OCTL1 = 1,
  OCTL0 = 0,
};

/**
 * Bitmasks for GPIO BOP
 *
 * Port bit operate register
 */
enum class GPIO_regs::BOP_bits : uint32_t {
  CR15 = (1 << 31),   ///< Port 15 Clear bit
  CR14 = (1 << 30),   ///< Port 14 Clear bit
  CR13 = (1 << 29),   ///< Port 13 Clear bit
  CR12 = (1 << 28),   ///< Port 12 Clear bit
  CR11 = (1 << 27),   ///< Port 11 Clear bit
  CR10 = (1 << 26),   ///< Port 10 Clear bit
  CR9 = (1 << 25),    ///< Port 9 Clear bit
  CR8 = (1 << 24),    ///< Port 8 Clear bit
  CR7 = (1 << 23),    ///< Port 7 Clear bit
  CR6 = (1 << 22),    ///< Port 6 Clear bit
  CR5 = (1 << 21),    ///< Port 5 Clear bit
  CR4 = (1 << 20),    ///< Port 4 Clear bit
  CR3 = (1 << 19),    ///< Port 3 Clear bit
  CR2 = (1 << 18),    ///< Port 2 Clear bit
  CR1 = (1 << 17),    ///< Port 1 Clear bit
  CR0 = (1 << 16),    ///< Port 0 Clear bit
  BOP15 = (1 << 15),  ///< Port 15 Set bit
  BOP14 = (1 << 14),  ///< Port 14 Set bit
  BOP13 = (1 << 13),  ///< Port 13 Set bit
  BOP12 = (1 << 12),  ///< Port 12 Set bit
  BOP11 = (1 << 11),  ///< Port 11 Set bit
  BOP10 = (1 << 10),  ///< Port 10 Set bit
  BOP9 = (1 << 9),    ///< Port 9 Set bit
  BOP8 = (1 << 8),    ///< Port 8 Set bit
  BOP7 = (1 << 7),    ///< Port 7 Set bit
  BOP6 = (1 << 6),    ///< Port 6 Set bit
  BOP5 = (1 << 5),    ///< Port 5 Set bit
  BOP4 = (1 << 4),    ///< Port 4 Set bit
  BOP3 = (1 << 3),    ///< Port 3 Set bit
  BOP2 = (1 << 2),    ///< Port 2 Set bit
  BOP1 = (1 << 1),    ///< Port 1 Set bit
  BOP0 = (1 << 0),    ///< Port 0 Set bit
};
void HasBitwiseOperators(GPIO_regs::BOP_bits);

/**
 * Bit shifts for GPIO BOP
 */
enum class GPIO_regs::BOP_shift : unsigned {
  CR15 = 31,
  CR14 = 30,
  CR13 = 29,
  CR12 = 28,
  CR11 = 27,
  CR10 = 26,
  CR9 = 25,
  CR8 = 24,
  CR7 = 23,
  CR6 = 22,
  CR5 = 21,
  CR4 = 20,
  CR3 = 19,
  CR2 = 18,
  CR1 = 17,
  CR0 = 16,
  BOP15 = 15,
  BOP14 = 14,
  BOP13 = 13,
  BOP12 = 12,
  BOP11 = 11,
  BOP10 = 10,
  BOP9 = 9,
  BOP8 = 8,
  BOP7 = 7,
  BOP6 = 6,
  BOP5 = 5,
  BOP4 = 4,
  BOP3 = 3,
  BOP2 = 2,
  BOP1 = 1,
  BOP0 = 0,
};

/**
 * Bitmasks for GPIO BC
 *
 * Port bit clear register
 */
enum class GPIO_regs::BC_bits : uint32_t {
  CR15 = (1 << 15),           ///< Port 15 Clear bit
  CR14 = (1 << 14),           ///< Port 14 Clear bit
  CR13 = (1 << 13),           ///< Port 13 Clear bit
  CR12 = (1 << 12),           ///< Port 12 Clear bit
  CR11 = (1 << 11),           ///< Port 11 Clear bit
  CR10 = (1 << 10),           ///< Port 10 Clear bit
  CR9 = (1 << 9),             ///< Port 9 Clear bit
  CR8 = (1 << 8),             ///< Port 8 Clear bit
  CR7 = (1 << 7),             ///< Port 7 Clear bit
  CR6 = (1 << 6),             ///< Port 6 Clear bit
  CR5 = (1 << 5),             ///< Port 5 Clear bit
  CR4 = (1 << 4),             ///< Port 4 Clear bit
  CR3 = (1 << 3),             ///< Port 3 Clear bit
  CR2 = (1 << 2),             ///< Port 2 Clear bit
  CR1 = (1 << 1),             ///< Port 1 Clear bit
  CR0 = (1 << 0),             ///< Port 0 Clear bit
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(GPIO_regs::BC_bits);

/**
 * Bit shifts for GPIO BC
 */
enum class GPIO_regs::BC_shift : unsigned {
  CR15 = 15,
  CR14 = 14,
  CR13 = 13,
  CR12 = 12,
  CR11 = 11,
  CR10 = 10,
  CR9 = 9,
  CR8 = 8,
  CR7 = 7,
  CR6 = 6,
  CR5 = 5,
  CR4 = 4,
  CR3 = 3,
  CR2 = 2,
  CR1 = 1,
  CR0 = 0,
};

/**
 * Bitmasks for GPIO LOCK
 *
 * GPIO port configuration lock register
 */
enum class GPIO_regs::LOCK_bits : uint32_t {
  LKK = (1 << 16),            ///< Lock sequence key
  LK15 = (1 << 15),           ///< Port Lock bit 15
  LK14 = (1 << 14),           ///< Port Lock bit 14
  LK13 = (1 << 13),           ///< Port Lock bit 13
  LK12 = (1 << 12),           ///< Port Lock bit 12
  LK11 = (1 << 11),           ///< Port Lock bit 11
  LK10 = (1 << 10),           ///< Port Lock bit 10
  LK9 = (1 << 9),             ///< Port Lock bit 9
  LK8 = (1 << 8),             ///< Port Lock bit 8
  LK7 = (1 << 7),             ///< Port Lock bit 7
  LK6 = (1 << 6),             ///< Port Lock bit 6
  LK5 = (1 << 5),             ///< Port Lock bit 5
  LK4 = (1 << 4),             ///< Port Lock bit 4
  LK3 = (1 << 3),             ///< Port Lock bit 3
  LK2 = (1 << 2),             ///< Port Lock bit 2
  LK1 = (1 << 1),             ///< Port Lock bit 1
  LK0 = (1 << 0),             ///< Port Lock bit 0
  Reserved_mask = 0xfffe0000  ///< All reserved bits
};
void HasBitwiseOperators(GPIO_regs::LOCK_bits);

/**
 * Bit shifts for GPIO LOCK
 */
enum class GPIO_regs::LOCK_shift : unsigned {
  LKK = 16,
  LK15 = 15,
  LK14 = 14,
  LK13 = 13,
  LK12 = 12,
  LK11 = 11,
  LK10 = 10,
  LK9 = 9,
  LK8 = 8,
  LK7 = 7,
  LK6 = 6,
  LK5 = 5,
  LK4 = 4,
  LK3 = 3,
  LK2 = 2,
  LK1 = 1,
  LK0 = 0,
};

static_assert(offsetof(GPIO_regs, CTL) == 0x0);
static_assert(offsetof(GPIO_regs, ISTAT) == 0x8);
static_assert(offsetof(GPIO_regs, OCTL) == 0xc);
static_assert(offsetof(GPIO_regs, BOP) == 0x10);
static_assert(offsetof(GPIO_regs, BC) == 0x14);
static_assert(offsetof(GPIO_regs, LOCK) == 0x18);
}  // namespace deri::mmio
