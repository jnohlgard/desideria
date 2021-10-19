/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/DMA.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for DMA INTF
 *
 * Interrupt flag register
 */
enum class DMA_regs::INTF_bits : uint32_t {
  GIF0 = (1 << 0),            ///< Global interrupt flag of channel 0
  FTFIF0 = (1 << 1),          ///< Full Transfer finish flag of channe 0
  HTFIF0 = (1 << 2),          ///< Half transfer finish flag of channel 0
  ERRIF0 = (1 << 3),          ///< Error flag of channel 0
  GIF1 = (1 << 4),            ///< Global interrupt flag of channel 1
  FTFIF1 = (1 << 5),          ///< Full Transfer finish flag of channe 1
  HTFIF1 = (1 << 6),          ///< Half transfer finish flag of channel 1
  ERRIF1 = (1 << 7),          ///< Error flag of channel 1
  GIF2 = (1 << 8),            ///< Global interrupt flag of channel 2
  FTFIF2 = (1 << 9),          ///< Full Transfer finish flag of channe 2
  HTFIF2 = (1 << 10),         ///< Half transfer finish flag of channel 2
  ERRIF2 = (1 << 11),         ///< Error flag of channel 2
  GIF3 = (1 << 12),           ///< Global interrupt flag of channel 3
  FTFIF3 = (1 << 13),         ///< Full Transfer finish flag of channe 3
  HTFIF3 = (1 << 14),         ///< Half transfer finish flag of channel 3
  ERRIF3 = (1 << 15),         ///< Error flag of channel 3
  GIF4 = (1 << 16),           ///< Global interrupt flag of channel 4
  FTFIF4 = (1 << 17),         ///< Full Transfer finish flag of channe 4
  HTFIF4 = (1 << 18),         ///< Half transfer finish flag of channel 4
  ERRIF4 = (1 << 19),         ///< Error flag of channel 4
  GIF5 = (1 << 20),           ///< Global interrupt flag of channel 5
  FTFIF5 = (1 << 21),         ///< Full Transfer finish flag of channe 5
  HTFIF5 = (1 << 22),         ///< Half transfer finish flag of channel 5
  ERRIF5 = (1 << 23),         ///< Error flag of channel 5
  GIF6 = (1 << 24),           ///< Global interrupt flag of channel 6
  FTFIF6 = (1 << 25),         ///< Full Transfer finish flag of channe 6
  HTFIF6 = (1 << 26),         ///< Half transfer finish flag of channel 6
  ERRIF6 = (1 << 27),         ///< Error flag of channel 6
  Reserved_mask = 0xf0000000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::INTF_bits);

/**
 * Bit shifts for DMA INTF
 */
enum class DMA_regs::INTF_shift : unsigned {
  GIF0 = 0,
  FTFIF0 = 1,
  HTFIF0 = 2,
  ERRIF0 = 3,
  GIF1 = 4,
  FTFIF1 = 5,
  HTFIF1 = 6,
  ERRIF1 = 7,
  GIF2 = 8,
  FTFIF2 = 9,
  HTFIF2 = 10,
  ERRIF2 = 11,
  GIF3 = 12,
  FTFIF3 = 13,
  HTFIF3 = 14,
  ERRIF3 = 15,
  GIF4 = 16,
  FTFIF4 = 17,
  HTFIF4 = 18,
  ERRIF4 = 19,
  GIF5 = 20,
  FTFIF5 = 21,
  HTFIF5 = 22,
  ERRIF5 = 23,
  GIF6 = 24,
  FTFIF6 = 25,
  HTFIF6 = 26,
  ERRIF6 = 27,
};

/**
 * Bitmasks for DMA INTC
 *
 * Interrupt flag clear register
 */
enum class DMA_regs::INTC_bits : uint32_t {
  GIFC0 = (1 << 0),    ///< Clear global interrupt flag of channel 0
  FTFIFC0 = (1 << 1),  ///< Clear bit for full transfer finish flag of channel 0
  HTFIFC0 = (1 << 2),  ///< Clear bit for half transfer finish flag of channel 0
  ERRIFC0 = (1 << 3),  ///< Clear bit for error flag of channel 0
  GIFC1 = (1 << 4),    ///< Clear global interrupt flag of channel 1
  FTFIFC1 = (1 << 5),  ///< Clear bit for full transfer finish flag of channel 1
  HTFIFC1 = (1 << 6),  ///< Clear bit for half transfer finish flag of channel 1
  ERRIFC1 = (1 << 7),  ///< Clear bit for error flag of channel 1
  GIFC2 = (1 << 8),    ///< Clear global interrupt flag of channel 2
  FTFIFC2 = (1 << 9),  ///< Clear bit for full transfer finish flag of channel 2
  HTFIFC2 =
      (1 << 10),  ///< Clear bit for half transfer finish flag of channel 2
  ERRIFC2 = (1 << 11),  ///< Clear bit for error flag of channel 2
  GIFC3 = (1 << 12),    ///< Clear global interrupt flag of channel 3
  FTFIFC3 =
      (1 << 13),  ///< Clear bit for full transfer finish flag of channel 3
  HTFIFC3 =
      (1 << 14),  ///< Clear bit for half transfer finish flag of channel 3
  ERRIFC3 = (1 << 15),  ///< Clear bit for error flag of channel 3
  GIFC4 = (1 << 16),    ///< Clear global interrupt flag of channel 4
  FTFIFC4 =
      (1 << 17),  ///< Clear bit for full transfer finish flag of channel 4
  HTFIFC4 =
      (1 << 18),  ///< Clear bit for half transfer finish flag of channel 4
  ERRIFC4 = (1 << 19),  ///< Clear bit for error flag of channel 4
  GIFC5 = (1 << 20),    ///< Clear global interrupt flag of channel 5
  FTFIFC5 =
      (1 << 21),  ///< Clear bit for full transfer finish flag of channel 5
  HTFIFC5 =
      (1 << 22),  ///< Clear bit for half transfer finish flag of channel 5
  ERRIFC5 = (1 << 23),  ///< Clear bit for error flag of channel 5
  GIFC6 = (1 << 24),    ///< Clear global interrupt flag of channel 6
  FTFIFC6 =
      (1 << 25),  ///< Clear bit for full transfer finish flag of channel 6
  HTFIFC6 =
      (1 << 26),  ///< Clear bit for half transfer finish flag of channel 6
  ERRIFC6 = (1 << 27),        ///< Clear bit for error flag of channel 6
  Reserved_mask = 0xf0000000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::INTC_bits);

/**
 * Bit shifts for DMA INTC
 */
enum class DMA_regs::INTC_shift : unsigned {
  GIFC0 = 0,
  FTFIFC0 = 1,
  HTFIFC0 = 2,
  ERRIFC0 = 3,
  GIFC1 = 4,
  FTFIFC1 = 5,
  HTFIFC1 = 6,
  ERRIFC1 = 7,
  GIFC2 = 8,
  FTFIFC2 = 9,
  HTFIFC2 = 10,
  ERRIFC2 = 11,
  GIFC3 = 12,
  FTFIFC3 = 13,
  HTFIFC3 = 14,
  ERRIFC3 = 15,
  GIFC4 = 16,
  FTFIFC4 = 17,
  HTFIFC4 = 18,
  ERRIFC4 = 19,
  GIFC5 = 20,
  FTFIFC5 = 21,
  HTFIFC5 = 22,
  ERRIFC5 = 23,
  GIFC6 = 24,
  FTFIFC6 = 25,
  HTFIFC6 = 26,
  ERRIFC6 = 27,
};

/**
 * Bitmasks for DMA CH0CTL
 *
 * Channel 0 control register
 */
enum class DMA_regs::CH0CTL_bits : uint32_t {
  CHEN = (1 << 0),   ///< Channel enable
  FTFIE = (1 << 1),  ///< Enable bit for channel full transfer finish interrupt
  HTFIE = (1 << 2),  ///< Enable bit for channel half transfer finish interrupt
  ERRIE = (1 << 3),  ///< Enable bit for channel error interrupt
  DIR = (1 << 4),    ///< Transfer direction
  CMEN = (1 << 5),   ///< Circular mode enable
  PNAGA = (1 << 6),  ///< Next address generation algorithm of peripheral
  MNAGA = (1 << 7),  ///< Next address generation algorithm of memory
  PWIDTH_mask = (0x3 << 8),   ///< Transfer data size of peripheral
  MWIDTH_mask = (0x3 << 10),  ///< Transfer data size of memory
  PRIO_mask = (0x3 << 12),    ///< Priority level
  M2M = (1 << 14),            ///< Memory to Memory Mode
  Reserved_mask = 0xffff8000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH0CTL_bits);

/**
 * Bit shifts for DMA CH0CTL
 */
enum class DMA_regs::CH0CTL_shift : unsigned {
  CHEN = 0,
  FTFIE = 1,
  HTFIE = 2,
  ERRIE = 3,
  DIR = 4,
  CMEN = 5,
  PNAGA = 6,
  MNAGA = 7,
  PWIDTH = 8,
  MWIDTH = 10,
  PRIO = 12,
  M2M = 14,
};

/**
 * Bitmasks for DMA CH0CNT
 *
 * Channel 0 counter register
 */
enum class DMA_regs::CH0CNT_bits : uint32_t {
  CNT_mask = (0xffff << 0),   ///< Transfer counter
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH0CNT_bits);

/**
 * Bit shifts for DMA CH0CNT
 */
enum class DMA_regs::CH0CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for DMA CH0PADDR
 *
 * Channel 0 peripheral base address register
 */
enum class DMA_regs::CH0PADDR_bits : uint32_t {
  PADDR_mask = (0xffffffff << 0),  ///< Peripheral base address
};
void HasBitwiseOperators(DMA_regs::CH0PADDR_bits);

/**
 * Bit shifts for DMA CH0PADDR
 */
enum class DMA_regs::CH0PADDR_shift : unsigned {
  PADDR = 0,
};

/**
 * Bitmasks for DMA CH0MADDR
 *
 * Channel 0 memory base address register
 */
enum class DMA_regs::CH0MADDR_bits : uint32_t {
  MADDR_mask = (0xffffffff << 0),  ///< Memory base address
};
void HasBitwiseOperators(DMA_regs::CH0MADDR_bits);

/**
 * Bit shifts for DMA CH0MADDR
 */
enum class DMA_regs::CH0MADDR_shift : unsigned {
  MADDR = 0,
};

/**
 * Bitmasks for DMA CH1CTL
 *
 * Channel 1 control register
 */
enum class DMA_regs::CH1CTL_bits : uint32_t {
  CHEN = (1 << 0),   ///< Channel enable
  FTFIE = (1 << 1),  ///< Enable bit for channel full transfer finish interrupt
  HTFIE = (1 << 2),  ///< Enable bit for channel half transfer finish interrupt
  ERRIE = (1 << 3),  ///< Enable bit for channel error interrupt
  DIR = (1 << 4),    ///< Transfer direction
  CMEN = (1 << 5),   ///< Circular mode enable
  PNAGA = (1 << 6),  ///< Next address generation algorithm of peripheral
  MNAGA = (1 << 7),  ///< Next address generation algorithm of memory
  PWIDTH_mask = (0x3 << 8),   ///< Transfer data size of peripheral
  MWIDTH_mask = (0x3 << 10),  ///< Transfer data size of memory
  PRIO_mask = (0x3 << 12),    ///< Priority level
  M2M = (1 << 14),            ///< Memory to Memory Mode
  Reserved_mask = 0xffff8000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH1CTL_bits);

/**
 * Bit shifts for DMA CH1CTL
 */
enum class DMA_regs::CH1CTL_shift : unsigned {
  CHEN = 0,
  FTFIE = 1,
  HTFIE = 2,
  ERRIE = 3,
  DIR = 4,
  CMEN = 5,
  PNAGA = 6,
  MNAGA = 7,
  PWIDTH = 8,
  MWIDTH = 10,
  PRIO = 12,
  M2M = 14,
};

/**
 * Bitmasks for DMA CH1CNT
 *
 * Channel 1 counter register
 */
enum class DMA_regs::CH1CNT_bits : uint32_t {
  CNT_mask = (0xffff << 0),   ///< Transfer counter
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH1CNT_bits);

/**
 * Bit shifts for DMA CH1CNT
 */
enum class DMA_regs::CH1CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for DMA CH1PADDR
 *
 * Channel 1 peripheral base address register
 */
enum class DMA_regs::CH1PADDR_bits : uint32_t {
  PADDR_mask = (0xffffffff << 0),  ///< Peripheral base address
};
void HasBitwiseOperators(DMA_regs::CH1PADDR_bits);

/**
 * Bit shifts for DMA CH1PADDR
 */
enum class DMA_regs::CH1PADDR_shift : unsigned {
  PADDR = 0,
};

/**
 * Bitmasks for DMA CH1MADDR
 *
 * Channel 1 memory base address register
 */
enum class DMA_regs::CH1MADDR_bits : uint32_t {
  MADDR_mask = (0xffffffff << 0),  ///< Memory base address
};
void HasBitwiseOperators(DMA_regs::CH1MADDR_bits);

/**
 * Bit shifts for DMA CH1MADDR
 */
enum class DMA_regs::CH1MADDR_shift : unsigned {
  MADDR = 0,
};

/**
 * Bitmasks for DMA CH2CTL
 *
 * Channel 2 control register
 */
enum class DMA_regs::CH2CTL_bits : uint32_t {
  CHEN = (1 << 0),   ///< Channel enable
  FTFIE = (1 << 1),  ///< Enable bit for channel full transfer finish interrupt
  HTFIE = (1 << 2),  ///< Enable bit for channel half transfer finish interrupt
  ERRIE = (1 << 3),  ///< Enable bit for channel error interrupt
  DIR = (1 << 4),    ///< Transfer direction
  CMEN = (1 << 5),   ///< Circular mode enable
  PNAGA = (1 << 6),  ///< Next address generation algorithm of peripheral
  MNAGA = (1 << 7),  ///< Next address generation algorithm of memory
  PWIDTH_mask = (0x3 << 8),   ///< Transfer data size of peripheral
  MWIDTH_mask = (0x3 << 10),  ///< Transfer data size of memory
  PRIO_mask = (0x3 << 12),    ///< Priority level
  M2M = (1 << 14),            ///< Memory to Memory Mode
  Reserved_mask = 0xffff8000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH2CTL_bits);

/**
 * Bit shifts for DMA CH2CTL
 */
enum class DMA_regs::CH2CTL_shift : unsigned {
  CHEN = 0,
  FTFIE = 1,
  HTFIE = 2,
  ERRIE = 3,
  DIR = 4,
  CMEN = 5,
  PNAGA = 6,
  MNAGA = 7,
  PWIDTH = 8,
  MWIDTH = 10,
  PRIO = 12,
  M2M = 14,
};

/**
 * Bitmasks for DMA CH2CNT
 *
 * Channel 2 counter register
 */
enum class DMA_regs::CH2CNT_bits : uint32_t {
  CNT_mask = (0xffff << 0),   ///< Transfer counter
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH2CNT_bits);

/**
 * Bit shifts for DMA CH2CNT
 */
enum class DMA_regs::CH2CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for DMA CH2PADDR
 *
 * Channel 2 peripheral base address register
 */
enum class DMA_regs::CH2PADDR_bits : uint32_t {
  PADDR_mask = (0xffffffff << 0),  ///< Peripheral base address
};
void HasBitwiseOperators(DMA_regs::CH2PADDR_bits);

/**
 * Bit shifts for DMA CH2PADDR
 */
enum class DMA_regs::CH2PADDR_shift : unsigned {
  PADDR = 0,
};

/**
 * Bitmasks for DMA CH2MADDR
 *
 * Channel 2 memory base address register
 */
enum class DMA_regs::CH2MADDR_bits : uint32_t {
  MADDR_mask = (0xffffffff << 0),  ///< Memory base address
};
void HasBitwiseOperators(DMA_regs::CH2MADDR_bits);

/**
 * Bit shifts for DMA CH2MADDR
 */
enum class DMA_regs::CH2MADDR_shift : unsigned {
  MADDR = 0,
};

/**
 * Bitmasks for DMA CH3CTL
 *
 * Channel 3 control register
 */
enum class DMA_regs::CH3CTL_bits : uint32_t {
  CHEN = (1 << 0),   ///< Channel enable
  FTFIE = (1 << 1),  ///< Enable bit for channel full transfer finish interrupt
  HTFIE = (1 << 2),  ///< Enable bit for channel half transfer finish interrupt
  ERRIE = (1 << 3),  ///< Enable bit for channel error interrupt
  DIR = (1 << 4),    ///< Transfer direction
  CMEN = (1 << 5),   ///< Circular mode enable
  PNAGA = (1 << 6),  ///< Next address generation algorithm of peripheral
  MNAGA = (1 << 7),  ///< Next address generation algorithm of memory
  PWIDTH_mask = (0x3 << 8),   ///< Transfer data size of peripheral
  MWIDTH_mask = (0x3 << 10),  ///< Transfer data size of memory
  PRIO_mask = (0x3 << 12),    ///< Priority level
  M2M = (1 << 14),            ///< Memory to Memory Mode
  Reserved_mask = 0xffff8000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH3CTL_bits);

/**
 * Bit shifts for DMA CH3CTL
 */
enum class DMA_regs::CH3CTL_shift : unsigned {
  CHEN = 0,
  FTFIE = 1,
  HTFIE = 2,
  ERRIE = 3,
  DIR = 4,
  CMEN = 5,
  PNAGA = 6,
  MNAGA = 7,
  PWIDTH = 8,
  MWIDTH = 10,
  PRIO = 12,
  M2M = 14,
};

/**
 * Bitmasks for DMA CH3CNT
 *
 * Channel 3 counter register
 */
enum class DMA_regs::CH3CNT_bits : uint32_t {
  CNT_mask = (0xffff << 0),   ///< Transfer counter
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH3CNT_bits);

/**
 * Bit shifts for DMA CH3CNT
 */
enum class DMA_regs::CH3CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for DMA CH3PADDR
 *
 * Channel 3 peripheral base address register
 */
enum class DMA_regs::CH3PADDR_bits : uint32_t {
  PADDR_mask = (0xffffffff << 0),  ///< Peripheral base address
};
void HasBitwiseOperators(DMA_regs::CH3PADDR_bits);

/**
 * Bit shifts for DMA CH3PADDR
 */
enum class DMA_regs::CH3PADDR_shift : unsigned {
  PADDR = 0,
};

/**
 * Bitmasks for DMA CH3MADDR
 *
 * Channel 3 memory base address register
 */
enum class DMA_regs::CH3MADDR_bits : uint32_t {
  MADDR_mask = (0xffffffff << 0),  ///< Memory base address
};
void HasBitwiseOperators(DMA_regs::CH3MADDR_bits);

/**
 * Bit shifts for DMA CH3MADDR
 */
enum class DMA_regs::CH3MADDR_shift : unsigned {
  MADDR = 0,
};

/**
 * Bitmasks for DMA CH4CTL
 *
 * Channel 4 control register
 */
enum class DMA_regs::CH4CTL_bits : uint32_t {
  CHEN = (1 << 0),   ///< Channel enable
  FTFIE = (1 << 1),  ///< Enable bit for channel full transfer finish interrupt
  HTFIE = (1 << 2),  ///< Enable bit for channel half transfer finish interrupt
  ERRIE = (1 << 3),  ///< Enable bit for channel error interrupt
  DIR = (1 << 4),    ///< Transfer direction
  CMEN = (1 << 5),   ///< Circular mode enable
  PNAGA = (1 << 6),  ///< Next address generation algorithm of peripheral
  MNAGA = (1 << 7),  ///< Next address generation algorithm of memory
  PWIDTH_mask = (0x3 << 8),   ///< Transfer data size of peripheral
  MWIDTH_mask = (0x3 << 10),  ///< Transfer data size of memory
  PRIO_mask = (0x3 << 12),    ///< Priority level
  M2M = (1 << 14),            ///< Memory to Memory Mode
  Reserved_mask = 0xffff8000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH4CTL_bits);

/**
 * Bit shifts for DMA CH4CTL
 */
enum class DMA_regs::CH4CTL_shift : unsigned {
  CHEN = 0,
  FTFIE = 1,
  HTFIE = 2,
  ERRIE = 3,
  DIR = 4,
  CMEN = 5,
  PNAGA = 6,
  MNAGA = 7,
  PWIDTH = 8,
  MWIDTH = 10,
  PRIO = 12,
  M2M = 14,
};

/**
 * Bitmasks for DMA CH4CNT
 *
 * Channel 4 counter register
 */
enum class DMA_regs::CH4CNT_bits : uint32_t {
  CNT_mask = (0xffff << 0),   ///< Transfer counter
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH4CNT_bits);

/**
 * Bit shifts for DMA CH4CNT
 */
enum class DMA_regs::CH4CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for DMA CH4PADDR
 *
 * Channel 4 peripheral base address register
 */
enum class DMA_regs::CH4PADDR_bits : uint32_t {
  PADDR_mask = (0xffffffff << 0),  ///< Peripheral base address
};
void HasBitwiseOperators(DMA_regs::CH4PADDR_bits);

/**
 * Bit shifts for DMA CH4PADDR
 */
enum class DMA_regs::CH4PADDR_shift : unsigned {
  PADDR = 0,
};

/**
 * Bitmasks for DMA CH4MADDR
 *
 * Channel 4 memory base address register
 */
enum class DMA_regs::CH4MADDR_bits : uint32_t {
  MADDR_mask = (0xffffffff << 0),  ///< Memory base address
};
void HasBitwiseOperators(DMA_regs::CH4MADDR_bits);

/**
 * Bit shifts for DMA CH4MADDR
 */
enum class DMA_regs::CH4MADDR_shift : unsigned {
  MADDR = 0,
};

/**
 * Bitmasks for DMA CH5CTL
 *
 * Channel 5 control register
 */
enum class DMA_regs::CH5CTL_bits : uint32_t {
  CHEN = (1 << 0),   ///< Channel enable
  FTFIE = (1 << 1),  ///< Enable bit for channel full transfer finish interrupt
  HTFIE = (1 << 2),  ///< Enable bit for channel half transfer finish interrupt
  ERRIE = (1 << 3),  ///< Enable bit for channel error interrupt
  DIR = (1 << 4),    ///< Transfer direction
  CMEN = (1 << 5),   ///< Circular mode enable
  PNAGA = (1 << 6),  ///< Next address generation algorithm of peripheral
  MNAGA = (1 << 7),  ///< Next address generation algorithm of memory
  PWIDTH_mask = (0x3 << 8),   ///< Transfer data size of peripheral
  MWIDTH_mask = (0x3 << 10),  ///< Transfer data size of memory
  PRIO_mask = (0x3 << 12),    ///< Priority level
  M2M = (1 << 14),            ///< Memory to Memory Mode
  Reserved_mask = 0xffff8000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH5CTL_bits);

/**
 * Bit shifts for DMA CH5CTL
 */
enum class DMA_regs::CH5CTL_shift : unsigned {
  CHEN = 0,
  FTFIE = 1,
  HTFIE = 2,
  ERRIE = 3,
  DIR = 4,
  CMEN = 5,
  PNAGA = 6,
  MNAGA = 7,
  PWIDTH = 8,
  MWIDTH = 10,
  PRIO = 12,
  M2M = 14,
};

/**
 * Bitmasks for DMA CH5CNT
 *
 * Channel 5 counter register
 */
enum class DMA_regs::CH5CNT_bits : uint32_t {
  CNT_mask = (0xffff << 0),   ///< Transfer counter
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH5CNT_bits);

/**
 * Bit shifts for DMA CH5CNT
 */
enum class DMA_regs::CH5CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for DMA CH5PADDR
 *
 * Channel 5 peripheral base address register
 */
enum class DMA_regs::CH5PADDR_bits : uint32_t {
  PADDR_mask = (0xffffffff << 0),  ///< Peripheral base address
};
void HasBitwiseOperators(DMA_regs::CH5PADDR_bits);

/**
 * Bit shifts for DMA CH5PADDR
 */
enum class DMA_regs::CH5PADDR_shift : unsigned {
  PADDR = 0,
};

/**
 * Bitmasks for DMA CH5MADDR
 *
 * Channel 5 memory base address register
 */
enum class DMA_regs::CH5MADDR_bits : uint32_t {
  MADDR_mask = (0xffffffff << 0),  ///< Memory base address
};
void HasBitwiseOperators(DMA_regs::CH5MADDR_bits);

/**
 * Bit shifts for DMA CH5MADDR
 */
enum class DMA_regs::CH5MADDR_shift : unsigned {
  MADDR = 0,
};

/**
 * Bitmasks for DMA CH6CTL
 *
 * Channel 6 control register
 */
enum class DMA_regs::CH6CTL_bits : uint32_t {
  CHEN = (1 << 0),   ///< Channel enable
  FTFIE = (1 << 1),  ///< Enable bit for channel full transfer finish interrupt
  HTFIE = (1 << 2),  ///< Enable bit for channel half transfer finish interrupt
  ERRIE = (1 << 3),  ///< Enable bit for channel error interrupt
  DIR = (1 << 4),    ///< Transfer direction
  CMEN = (1 << 5),   ///< Circular mode enable
  PNAGA = (1 << 6),  ///< Next address generation algorithm of peripheral
  MNAGA = (1 << 7),  ///< Next address generation algorithm of memory
  PWIDTH_mask = (0x3 << 8),   ///< Transfer data size of peripheral
  MWIDTH_mask = (0x3 << 10),  ///< Transfer data size of memory
  PRIO_mask = (0x3 << 12),    ///< Priority level
  M2M = (1 << 14),            ///< Memory to Memory Mode
  Reserved_mask = 0xffff8000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH6CTL_bits);

/**
 * Bit shifts for DMA CH6CTL
 */
enum class DMA_regs::CH6CTL_shift : unsigned {
  CHEN = 0,
  FTFIE = 1,
  HTFIE = 2,
  ERRIE = 3,
  DIR = 4,
  CMEN = 5,
  PNAGA = 6,
  MNAGA = 7,
  PWIDTH = 8,
  MWIDTH = 10,
  PRIO = 12,
  M2M = 14,
};

/**
 * Bitmasks for DMA CH6CNT
 *
 * Channel 6 counter register
 */
enum class DMA_regs::CH6CNT_bits : uint32_t {
  CNT_mask = (0xffff << 0),   ///< Transfer counter
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(DMA_regs::CH6CNT_bits);

/**
 * Bit shifts for DMA CH6CNT
 */
enum class DMA_regs::CH6CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for DMA CH6PADDR
 *
 * Channel 6 peripheral base address register
 */
enum class DMA_regs::CH6PADDR_bits : uint32_t {
  PADDR_mask = (0xffffffff << 0),  ///< Peripheral base address
};
void HasBitwiseOperators(DMA_regs::CH6PADDR_bits);

/**
 * Bit shifts for DMA CH6PADDR
 */
enum class DMA_regs::CH6PADDR_shift : unsigned {
  PADDR = 0,
};

/**
 * Bitmasks for DMA CH6MADDR
 *
 * Channel 6 memory base address register
 */
enum class DMA_regs::CH6MADDR_bits : uint32_t {
  MADDR_mask = (0xffffffff << 0),  ///< Memory base address
};
void HasBitwiseOperators(DMA_regs::CH6MADDR_bits);

/**
 * Bit shifts for DMA CH6MADDR
 */
enum class DMA_regs::CH6MADDR_shift : unsigned {
  MADDR = 0,
};

static_assert(offsetof(DMA_regs, INTF) == 0x0);
static_assert(offsetof(DMA_regs, INTC) == 0x4);
static_assert(offsetof(DMA_regs, CH0CTL) == 0x8);
static_assert(offsetof(DMA_regs, CH0CNT) == 0xc);
static_assert(offsetof(DMA_regs, CH0PADDR) == 0x10);
static_assert(offsetof(DMA_regs, CH0MADDR) == 0x14);
static_assert(offsetof(DMA_regs, CH1CTL) == 0x1c);
static_assert(offsetof(DMA_regs, CH1CNT) == 0x20);
static_assert(offsetof(DMA_regs, CH1PADDR) == 0x24);
static_assert(offsetof(DMA_regs, CH1MADDR) == 0x28);
static_assert(offsetof(DMA_regs, CH2CTL) == 0x30);
static_assert(offsetof(DMA_regs, CH2CNT) == 0x34);
static_assert(offsetof(DMA_regs, CH2PADDR) == 0x38);
static_assert(offsetof(DMA_regs, CH2MADDR) == 0x3c);
static_assert(offsetof(DMA_regs, CH3CTL) == 0x44);
static_assert(offsetof(DMA_regs, CH3CNT) == 0x48);
static_assert(offsetof(DMA_regs, CH3PADDR) == 0x4c);
static_assert(offsetof(DMA_regs, CH3MADDR) == 0x50);
static_assert(offsetof(DMA_regs, CH4CTL) == 0x58);
static_assert(offsetof(DMA_regs, CH4CNT) == 0x5c);
static_assert(offsetof(DMA_regs, CH4PADDR) == 0x60);
static_assert(offsetof(DMA_regs, CH4MADDR) == 0x64);
static_assert(offsetof(DMA_regs, CH5CTL) == 0x6c);
static_assert(offsetof(DMA_regs, CH5CNT) == 0x70);
static_assert(offsetof(DMA_regs, CH5PADDR) == 0x74);
static_assert(offsetof(DMA_regs, CH5MADDR) == 0x78);
static_assert(offsetof(DMA_regs, CH6CTL) == 0x80);
static_assert(offsetof(DMA_regs, CH6CNT) == 0x84);
static_assert(offsetof(DMA_regs, CH6PADDR) == 0x88);
static_assert(offsetof(DMA_regs, CH6MADDR) == 0x8c);
}  // namespace deri::mmio
