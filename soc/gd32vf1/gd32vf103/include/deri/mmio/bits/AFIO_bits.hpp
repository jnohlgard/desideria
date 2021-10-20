/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/AFIO.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for AFIO EC
 *
 * Event control register
 */
enum class AFIO_regs::EC_bits : uint32_t {
  EOE = (1u << 7),            ///< Event output enable
  PORT_mask = (0x7u << 4),    ///< Event output port selection
  PIN_mask = (0xfu << 0),     ///< Event output pin selection
  Reserved_mask = 0xffffff00  ///< All reserved bits
};
void HasBitwiseOperators(AFIO_regs::EC_bits);

/**
 * Bit shifts for AFIO EC
 */
enum class AFIO_regs::EC_shift : unsigned {
  EOE = 7,
  PORT = 4,
  PIN = 0,
};

/**
 * Bitmasks for AFIO PCF0
 *
 * AFIO port configuration register 0
 */
enum class AFIO_regs::PCF0_bits : uint32_t {
  TIMER1ITI1_REMAP = (1u << 29),  ///< TIMER1 internal trigger 1 remapping
  SPI2_REMAP = (1u << 28),        ///< SPI2/I2S2 remapping
  SWJ_CFG_mask = (0x7u << 24),    ///< Serial wire JTAG configuration
  CAN1_REMAP = (1u << 22),        ///< CAN1 I/O remapping
  TIMER4CH3_IREMAP = (1u << 16),  ///< TIMER4 channel3 internal remapping
  PD01_REMAP = (1u << 15),        ///< Port D0/Port D1 mapping on OSC_IN/OSC_OUT
  CAN0_REMAP_mask = (0x3u << 13),    ///< CAN0 alternate interface remapping
  TIMER3_REMAP = (1u << 12),         ///< TIMER3 remapping
  TIMER2_REMAP_mask = (0x3u << 10),  ///< TIMER2 remapping
  TIMER1_REMAP_mask = (0x3u << 8),   ///< TIMER1 remapping
  TIMER0_REMAP_mask = (0x3u << 6),   ///< TIMER0 remapping
  USART2_REMAP_mask = (0x3u << 4),   ///< USART2 remapping
  USART1_REMAP = (1u << 3),          ///< USART1 remapping
  USART0_REMAP = (1u << 2),          ///< USART0 remapping
  I2C0_REMAP = (1u << 1),            ///< I2C0 remapping
  SPI0_REMAP = (1u << 0),            ///< SPI0 remapping
  Reserved_mask = 0xc8be0000         ///< All reserved bits
};
void HasBitwiseOperators(AFIO_regs::PCF0_bits);

/**
 * Bit shifts for AFIO PCF0
 */
enum class AFIO_regs::PCF0_shift : unsigned {
  TIMER1ITI1_REMAP = 29,
  SPI2_REMAP = 28,
  SWJ_CFG = 24,
  CAN1_REMAP = 22,
  TIMER4CH3_IREMAP = 16,
  PD01_REMAP = 15,
  CAN0_REMAP = 13,
  TIMER3_REMAP = 12,
  TIMER2_REMAP = 10,
  TIMER1_REMAP = 8,
  TIMER0_REMAP = 6,
  USART2_REMAP = 4,
  USART1_REMAP = 3,
  USART0_REMAP = 2,
  I2C0_REMAP = 1,
  SPI0_REMAP = 0,
};

/**
 * Bitmasks for AFIO EXTISS0
 *
 * EXTI sources selection register 0
 */
enum class AFIO_regs::EXTISS0_bits : uint32_t {
  EXTI3_SS_mask = (0xfu << 12),  ///< EXTI 3 sources selection
  EXTI2_SS_mask = (0xfu << 8),   ///< EXTI 2 sources selection
  EXTI1_SS_mask = (0xfu << 4),   ///< EXTI 1 sources selection
  EXTI0_SS_mask = (0xfu << 0),   ///< EXTI 0 sources selection
  Reserved_mask = 0xffff0000     ///< All reserved bits
};
void HasBitwiseOperators(AFIO_regs::EXTISS0_bits);

/**
 * Bit shifts for AFIO EXTISS0
 */
enum class AFIO_regs::EXTISS0_shift : unsigned {
  EXTI3_SS = 12,
  EXTI2_SS = 8,
  EXTI1_SS = 4,
  EXTI0_SS = 0,
};

/**
 * Bitmasks for AFIO EXTISS1
 *
 * EXTI sources selection register 1
 */
enum class AFIO_regs::EXTISS1_bits : uint32_t {
  EXTI7_SS_mask = (0xfu << 12),  ///< EXTI 7 sources selection
  EXTI6_SS_mask = (0xfu << 8),   ///< EXTI 6 sources selection
  EXTI5_SS_mask = (0xfu << 4),   ///< EXTI 5 sources selection
  EXTI4_SS_mask = (0xfu << 0),   ///< EXTI 4 sources selection
  Reserved_mask = 0xffff0000     ///< All reserved bits
};
void HasBitwiseOperators(AFIO_regs::EXTISS1_bits);

/**
 * Bit shifts for AFIO EXTISS1
 */
enum class AFIO_regs::EXTISS1_shift : unsigned {
  EXTI7_SS = 12,
  EXTI6_SS = 8,
  EXTI5_SS = 4,
  EXTI4_SS = 0,
};

/**
 * Bitmasks for AFIO EXTISS2
 *
 * EXTI sources selection register 2
 */
enum class AFIO_regs::EXTISS2_bits : uint32_t {
  EXTI11_SS_mask = (0xfu << 12),  ///< EXTI 11 sources selection
  EXTI10_SS_mask = (0xfu << 8),   ///< EXTI 10 sources selection
  EXTI9_SS_mask = (0xfu << 4),    ///< EXTI 9 sources selection
  EXTI8_SS_mask = (0xfu << 0),    ///< EXTI 8 sources selection
  Reserved_mask = 0xffff0000      ///< All reserved bits
};
void HasBitwiseOperators(AFIO_regs::EXTISS2_bits);

/**
 * Bit shifts for AFIO EXTISS2
 */
enum class AFIO_regs::EXTISS2_shift : unsigned {
  EXTI11_SS = 12,
  EXTI10_SS = 8,
  EXTI9_SS = 4,
  EXTI8_SS = 0,
};

/**
 * Bitmasks for AFIO EXTISS3
 *
 * EXTI sources selection register 3
 */
enum class AFIO_regs::EXTISS3_bits : uint32_t {
  EXTI15_SS_mask = (0xfu << 12),  ///< EXTI 15 sources selection
  EXTI14_SS_mask = (0xfu << 8),   ///< EXTI 14 sources selection
  EXTI13_SS_mask = (0xfu << 4),   ///< EXTI 13 sources selection
  EXTI12_SS_mask = (0xfu << 0),   ///< EXTI 12 sources selection
  Reserved_mask = 0xffff0000      ///< All reserved bits
};
void HasBitwiseOperators(AFIO_regs::EXTISS3_bits);

/**
 * Bit shifts for AFIO EXTISS3
 */
enum class AFIO_regs::EXTISS3_shift : unsigned {
  EXTI15_SS = 12,
  EXTI14_SS = 8,
  EXTI13_SS = 4,
  EXTI12_SS = 0,
};

/**
 * Bitmasks for AFIO PCF1
 *
 * AFIO port configuration register 1
 */
enum class AFIO_regs::PCF1_bits : uint32_t {
  EXMC_NADV = (1u << 10),     ///< EXMC_NADV connect/disconnect
  Reserved_mask = 0xfffffbff  ///< All reserved bits
};
void HasBitwiseOperators(AFIO_regs::PCF1_bits);

/**
 * Bit shifts for AFIO PCF1
 */
enum class AFIO_regs::PCF1_shift : unsigned {
  EXMC_NADV = 10,
};

static_assert(offsetof(AFIO_regs, EC) == 0x0);
static_assert(offsetof(AFIO_regs, PCF0) == 0x4);
static_assert(offsetof(AFIO_regs, EXTISS0) == 0x8);
static_assert(offsetof(AFIO_regs, EXTISS1) == 0xc);
static_assert(offsetof(AFIO_regs, EXTISS2) == 0x10);
static_assert(offsetof(AFIO_regs, EXTISS3) == 0x14);
static_assert(offsetof(AFIO_regs, PCF1) == 0x1c);
}  // namespace deri::mmio
