/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/EXTI.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for EXTI INTEN
 *
 * Interrupt enable register (EXTI_INTEN)
 */
enum class EXTI_regs::INTEN_bits : uint32_t {
  INTEN0 = (1u << 0),         ///< Enable Interrupt on line 0
  INTEN1 = (1u << 1),         ///< Enable Interrupt on line 1
  INTEN2 = (1u << 2),         ///< Enable Interrupt on line 2
  INTEN3 = (1u << 3),         ///< Enable Interrupt on line 3
  INTEN4 = (1u << 4),         ///< Enable Interrupt on line 4
  INTEN5 = (1u << 5),         ///< Enable Interrupt on line 5
  INTEN6 = (1u << 6),         ///< Enable Interrupt on line 6
  INTEN7 = (1u << 7),         ///< Enable Interrupt on line 7
  INTEN8 = (1u << 8),         ///< Enable Interrupt on line 8
  INTEN9 = (1u << 9),         ///< Enable Interrupt on line 9
  INTEN10 = (1u << 10),       ///< Enable Interrupt on line 10
  INTEN11 = (1u << 11),       ///< Enable Interrupt on line 11
  INTEN12 = (1u << 12),       ///< Enable Interrupt on line 12
  INTEN13 = (1u << 13),       ///< Enable Interrupt on line 13
  INTEN14 = (1u << 14),       ///< Enable Interrupt on line 14
  INTEN15 = (1u << 15),       ///< Enable Interrupt on line 15
  INTEN16 = (1u << 16),       ///< Enable Interrupt on line 16
  INTEN17 = (1u << 17),       ///< Enable Interrupt on line 17
  INTEN18 = (1u << 18),       ///< Enable Interrupt on line 18
  Reserved_mask = 0xfff80000  ///< All reserved bits
};
void HasBitwiseOperators(EXTI_regs::INTEN_bits);

/**
 * Bit shifts for EXTI INTEN
 */
enum class EXTI_regs::INTEN_shift : unsigned {
  INTEN0 = 0,
  INTEN1 = 1,
  INTEN2 = 2,
  INTEN3 = 3,
  INTEN4 = 4,
  INTEN5 = 5,
  INTEN6 = 6,
  INTEN7 = 7,
  INTEN8 = 8,
  INTEN9 = 9,
  INTEN10 = 10,
  INTEN11 = 11,
  INTEN12 = 12,
  INTEN13 = 13,
  INTEN14 = 14,
  INTEN15 = 15,
  INTEN16 = 16,
  INTEN17 = 17,
  INTEN18 = 18,
};

/**
 * Bitmasks for EXTI EVEN
 *
 * Event enable register (EXTI_EVEN)
 */
enum class EXTI_regs::EVEN_bits : uint32_t {
  EVEN0 = (1u << 0),          ///< Enable Event on line 0
  EVEN1 = (1u << 1),          ///< Enable Event on line 1
  EVEN2 = (1u << 2),          ///< Enable Event on line 2
  EVEN3 = (1u << 3),          ///< Enable Event on line 3
  EVEN4 = (1u << 4),          ///< Enable Event on line 4
  EVEN5 = (1u << 5),          ///< Enable Event on line 5
  EVEN6 = (1u << 6),          ///< Enable Event on line 6
  EVEN7 = (1u << 7),          ///< Enable Event on line 7
  EVEN8 = (1u << 8),          ///< Enable Event on line 8
  EVEN9 = (1u << 9),          ///< Enable Event on line 9
  EVEN10 = (1u << 10),        ///< Enable Event on line 10
  EVEN11 = (1u << 11),        ///< Enable Event on line 11
  EVEN12 = (1u << 12),        ///< Enable Event on line 12
  EVEN13 = (1u << 13),        ///< Enable Event on line 13
  EVEN14 = (1u << 14),        ///< Enable Event on line 14
  EVEN15 = (1u << 15),        ///< Enable Event on line 15
  EVEN16 = (1u << 16),        ///< Enable Event on line 16
  EVEN17 = (1u << 17),        ///< Enable Event on line 17
  EVEN18 = (1u << 18),        ///< Enable Event on line 18
  Reserved_mask = 0xfff80000  ///< All reserved bits
};
void HasBitwiseOperators(EXTI_regs::EVEN_bits);

/**
 * Bit shifts for EXTI EVEN
 */
enum class EXTI_regs::EVEN_shift : unsigned {
  EVEN0 = 0,
  EVEN1 = 1,
  EVEN2 = 2,
  EVEN3 = 3,
  EVEN4 = 4,
  EVEN5 = 5,
  EVEN6 = 6,
  EVEN7 = 7,
  EVEN8 = 8,
  EVEN9 = 9,
  EVEN10 = 10,
  EVEN11 = 11,
  EVEN12 = 12,
  EVEN13 = 13,
  EVEN14 = 14,
  EVEN15 = 15,
  EVEN16 = 16,
  EVEN17 = 17,
  EVEN18 = 18,
};

/**
 * Bitmasks for EXTI RTEN
 *
 * Rising Edge Trigger Enable register (EXTI_RTEN)
 */
enum class EXTI_regs::RTEN_bits : uint32_t {
  RTEN0 = (1u << 0),          ///< Rising edge trigger enable of line 0
  RTEN1 = (1u << 1),          ///< Rising edge trigger enable of line 1
  RTEN2 = (1u << 2),          ///< Rising edge trigger enable of line 2
  RTEN3 = (1u << 3),          ///< Rising edge trigger enable of line 3
  RTEN4 = (1u << 4),          ///< Rising edge trigger enable of line 4
  RTEN5 = (1u << 5),          ///< Rising edge trigger enable of line 5
  RTEN6 = (1u << 6),          ///< Rising edge trigger enable of line 6
  RTEN7 = (1u << 7),          ///< Rising edge trigger enable of line 7
  RTEN8 = (1u << 8),          ///< Rising edge trigger enable of line 8
  RTEN9 = (1u << 9),          ///< Rising edge trigger enable of line 9
  RTEN10 = (1u << 10),        ///< Rising edge trigger enable of line 10
  RTEN11 = (1u << 11),        ///< Rising edge trigger enable of line 11
  RTEN12 = (1u << 12),        ///< Rising edge trigger enable of line 12
  RTEN13 = (1u << 13),        ///< Rising edge trigger enable of line 13
  RTEN14 = (1u << 14),        ///< Rising edge trigger enable of line 14
  RTEN15 = (1u << 15),        ///< Rising edge trigger enable of line 15
  RTEN16 = (1u << 16),        ///< Rising edge trigger enable of line 16
  RTEN17 = (1u << 17),        ///< Rising edge trigger enable of line 17
  RTEN18 = (1u << 18),        ///< Rising edge trigger enable of line 18
  Reserved_mask = 0xfff80000  ///< All reserved bits
};
void HasBitwiseOperators(EXTI_regs::RTEN_bits);

/**
 * Bit shifts for EXTI RTEN
 */
enum class EXTI_regs::RTEN_shift : unsigned {
  RTEN0 = 0,
  RTEN1 = 1,
  RTEN2 = 2,
  RTEN3 = 3,
  RTEN4 = 4,
  RTEN5 = 5,
  RTEN6 = 6,
  RTEN7 = 7,
  RTEN8 = 8,
  RTEN9 = 9,
  RTEN10 = 10,
  RTEN11 = 11,
  RTEN12 = 12,
  RTEN13 = 13,
  RTEN14 = 14,
  RTEN15 = 15,
  RTEN16 = 16,
  RTEN17 = 17,
  RTEN18 = 18,
};

/**
 * Bitmasks for EXTI FTEN
 *
 * Falling Egde Trigger Enable register (EXTI_FTEN)
 */
enum class EXTI_regs::FTEN_bits : uint32_t {
  FTEN0 = (1u << 0),          ///< Falling edge trigger enable of line 0
  FTEN1 = (1u << 1),          ///< Falling edge trigger enable of line 1
  FTEN2 = (1u << 2),          ///< Falling edge trigger enable of line 2
  FTEN3 = (1u << 3),          ///< Falling edge trigger enable of line 3
  FTEN4 = (1u << 4),          ///< Falling edge trigger enable of line 4
  FTEN5 = (1u << 5),          ///< Falling edge trigger enable of line 5
  FTEN6 = (1u << 6),          ///< Falling edge trigger enable of line 6
  FTEN7 = (1u << 7),          ///< Falling edge trigger enable of line 7
  FTEN8 = (1u << 8),          ///< Falling edge trigger enable of line 8
  FTEN9 = (1u << 9),          ///< Falling edge trigger enable of line 9
  FTEN10 = (1u << 10),        ///< Falling edge trigger enable of line 10
  FTEN11 = (1u << 11),        ///< Falling edge trigger enable of line 11
  FTEN12 = (1u << 12),        ///< Falling edge trigger enable of line 12
  FTEN13 = (1u << 13),        ///< Falling edge trigger enable of line 13
  FTEN14 = (1u << 14),        ///< Falling edge trigger enable of line 14
  FTEN15 = (1u << 15),        ///< Falling edge trigger enable of line 15
  FTEN16 = (1u << 16),        ///< Falling edge trigger enable of line 16
  FTEN17 = (1u << 17),        ///< Falling edge trigger enable of line 17
  FTEN18 = (1u << 18),        ///< Falling edge trigger enable of line 18
  Reserved_mask = 0xfff80000  ///< All reserved bits
};
void HasBitwiseOperators(EXTI_regs::FTEN_bits);

/**
 * Bit shifts for EXTI FTEN
 */
enum class EXTI_regs::FTEN_shift : unsigned {
  FTEN0 = 0,
  FTEN1 = 1,
  FTEN2 = 2,
  FTEN3 = 3,
  FTEN4 = 4,
  FTEN5 = 5,
  FTEN6 = 6,
  FTEN7 = 7,
  FTEN8 = 8,
  FTEN9 = 9,
  FTEN10 = 10,
  FTEN11 = 11,
  FTEN12 = 12,
  FTEN13 = 13,
  FTEN14 = 14,
  FTEN15 = 15,
  FTEN16 = 16,
  FTEN17 = 17,
  FTEN18 = 18,
};

/**
 * Bitmasks for EXTI SWIEV
 *
 * Software interrupt event register (EXTI_SWIEV)
 */
enum class EXTI_regs::SWIEV_bits : uint32_t {
  SWIEV0 = (1u << 0),         ///< Interrupt/Event software trigger on line 0
  SWIEV1 = (1u << 1),         ///< Interrupt/Event software trigger on line 1
  SWIEV2 = (1u << 2),         ///< Interrupt/Event software trigger on line 2
  SWIEV3 = (1u << 3),         ///< Interrupt/Event software trigger on line 3
  SWIEV4 = (1u << 4),         ///< Interrupt/Event software trigger on line 4
  SWIEV5 = (1u << 5),         ///< Interrupt/Event software trigger on line 5
  SWIEV6 = (1u << 6),         ///< Interrupt/Event software trigger on line 6
  SWIEV7 = (1u << 7),         ///< Interrupt/Event software trigger on line 7
  SWIEV8 = (1u << 8),         ///< Interrupt/Event software trigger on line 8
  SWIEV9 = (1u << 9),         ///< Interrupt/Event software trigger on line 9
  SWIEV10 = (1u << 10),       ///< Interrupt/Event software trigger on line 10
  SWIEV11 = (1u << 11),       ///< Interrupt/Event software trigger on line 11
  SWIEV12 = (1u << 12),       ///< Interrupt/Event software trigger on line 12
  SWIEV13 = (1u << 13),       ///< Interrupt/Event software trigger on line 13
  SWIEV14 = (1u << 14),       ///< Interrupt/Event software trigger on line 14
  SWIEV15 = (1u << 15),       ///< Interrupt/Event software trigger on line 15
  SWIEV16 = (1u << 16),       ///< Interrupt/Event software trigger on line 16
  SWIEV17 = (1u << 17),       ///< Interrupt/Event software trigger on line 17
  SWIEV18 = (1u << 18),       ///< Interrupt/Event software trigger on line 18
  Reserved_mask = 0xfff80000  ///< All reserved bits
};
void HasBitwiseOperators(EXTI_regs::SWIEV_bits);

/**
 * Bit shifts for EXTI SWIEV
 */
enum class EXTI_regs::SWIEV_shift : unsigned {
  SWIEV0 = 0,
  SWIEV1 = 1,
  SWIEV2 = 2,
  SWIEV3 = 3,
  SWIEV4 = 4,
  SWIEV5 = 5,
  SWIEV6 = 6,
  SWIEV7 = 7,
  SWIEV8 = 8,
  SWIEV9 = 9,
  SWIEV10 = 10,
  SWIEV11 = 11,
  SWIEV12 = 12,
  SWIEV13 = 13,
  SWIEV14 = 14,
  SWIEV15 = 15,
  SWIEV16 = 16,
  SWIEV17 = 17,
  SWIEV18 = 18,
};

/**
 * Bitmasks for EXTI PD
 *
 * Pending register (EXTI_PD)
 */
enum class EXTI_regs::PD_bits : uint32_t {
  PD0 = (1u << 0),            ///< Interrupt pending status of line 0
  PD1 = (1u << 1),            ///< Interrupt pending status of line 1
  PD2 = (1u << 2),            ///< Interrupt pending status of line 2
  PD3 = (1u << 3),            ///< Interrupt pending status of line 3
  PD4 = (1u << 4),            ///< Interrupt pending status of line 4
  PD5 = (1u << 5),            ///< Interrupt pending status of line 5
  PD6 = (1u << 6),            ///< Interrupt pending status of line 6
  PD7 = (1u << 7),            ///< Interrupt pending status of line 7
  PD8 = (1u << 8),            ///< Interrupt pending status of line 8
  PD9 = (1u << 9),            ///< Interrupt pending status of line 9
  PD10 = (1u << 10),          ///< Interrupt pending status of line 10
  PD11 = (1u << 11),          ///< Interrupt pending status of line 11
  PD12 = (1u << 12),          ///< Interrupt pending status of line 12
  PD13 = (1u << 13),          ///< Interrupt pending status of line 13
  PD14 = (1u << 14),          ///< Interrupt pending status of line 14
  PD15 = (1u << 15),          ///< Interrupt pending status of line 15
  PD16 = (1u << 16),          ///< Interrupt pending status of line 16
  PD17 = (1u << 17),          ///< Interrupt pending status of line 17
  PD18 = (1u << 18),          ///< Interrupt pending status of line 18
  Reserved_mask = 0xfff80000  ///< All reserved bits
};
void HasBitwiseOperators(EXTI_regs::PD_bits);

/**
 * Bit shifts for EXTI PD
 */
enum class EXTI_regs::PD_shift : unsigned {
  PD0 = 0,
  PD1 = 1,
  PD2 = 2,
  PD3 = 3,
  PD4 = 4,
  PD5 = 5,
  PD6 = 6,
  PD7 = 7,
  PD8 = 8,
  PD9 = 9,
  PD10 = 10,
  PD11 = 11,
  PD12 = 12,
  PD13 = 13,
  PD14 = 14,
  PD15 = 15,
  PD16 = 16,
  PD17 = 17,
  PD18 = 18,
};

static_assert(offsetof(EXTI_regs, INTEN) == 0x0);
static_assert(offsetof(EXTI_regs, EVEN) == 0x4);
static_assert(offsetof(EXTI_regs, RTEN) == 0x8);
static_assert(offsetof(EXTI_regs, FTEN) == 0xc);
static_assert(offsetof(EXTI_regs, SWIEV) == 0x10);
static_assert(offsetof(EXTI_regs, PD) == 0x14);
}  // namespace deri::mmio
