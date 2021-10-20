/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/TIMER.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for TIMER CTL0
 *
 * control register 0
 */
enum class TIMER_regs::CTL0_bits : uint16_t {
  CKDIV_mask = (0x3u << 8),  ///< Clock division
  ARSE = (1u << 7),          ///< Auto-reload shadow enable
  CAM_mask = (0x3u << 5),    ///< Counter aligns mode selection
  DIR = (1u << 4),           ///< Direction
  SPM = (1u << 3),           ///< Single pulse mode
  UPS = (1u << 2),           ///< Update source
  UPDIS = (1u << 1),         ///< Update disable
  CEN = (1u << 0),           ///< Counter enable
  Reserved_mask = 0xfc00     ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::CTL0_bits);

/**
 * Bit shifts for TIMER CTL0
 */
enum class TIMER_regs::CTL0_shift : unsigned {
  CKDIV = 8,
  ARSE = 7,
  CAM = 5,
  DIR = 4,
  SPM = 3,
  UPS = 2,
  UPDIS = 1,
  CEN = 0,
};

/**
 * Bitmasks for TIMER CTL1
 *
 * control register 1
 */
enum class TIMER_regs::CTL1_bits : uint16_t {
  ISO3 = (1u << 14),       ///< Idle state of channel 3 output
  ISO2N = (1u << 13),      ///< Idle state of channel 2 complementary output
  ISO2 = (1u << 12),       ///< Idle state of channel 2 output
  ISO1N = (1u << 11),      ///< Idle state of channel 1 complementary output
  ISO1 = (1u << 10),       ///< Idle state of channel 1 output
  ISO0N = (1u << 9),       ///< Idle state of channel 0 complementary output
  ISO0 = (1u << 8),        ///< Idle state of channel 0 output
  TI0S = (1u << 7),        ///< Channel 0 trigger input selection
  MMC_mask = (0x7u << 4),  ///< Master mode control
  DMAS = (1u << 3),        ///< DMA request source selection
  CCUC = (1u << 2),  ///< Commutation control shadow register update control
  CCSE = (1u << 0),  ///< Commutation control shadow enable
  Reserved_mask = 0x8002  ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::CTL1_bits);

/**
 * Bit shifts for TIMER CTL1
 */
enum class TIMER_regs::CTL1_shift : unsigned {
  ISO3 = 14,
  ISO2N = 13,
  ISO2 = 12,
  ISO1N = 11,
  ISO1 = 10,
  ISO0N = 9,
  ISO0 = 8,
  TI0S = 7,
  MMC = 4,
  DMAS = 3,
  CCUC = 2,
  CCSE = 0,
};

/**
 * Bitmasks for TIMER SMCFG
 *
 * slave mode configuration register
 */
enum class TIMER_regs::SMCFG_bits : uint16_t {
  ETP = (1u << 15),           ///< External trigger polarity
  SMC1 = (1u << 14),          ///< Part of SMC for enable External clock mode1
  ETPSC_mask = (0x3u << 12),  ///< External trigger prescaler
  ETFC_mask = (0xfu << 8),    ///< External trigger filter control
  MSM = (1u << 7),            ///< Master/Slave mode
  TRGS_mask = (0x7u << 4),    ///< Trigger selection
  SMC_mask = (0x7u << 0),     ///< Slave mode selection
  Reserved_mask = 0x0008      ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::SMCFG_bits);

/**
 * Bit shifts for TIMER SMCFG
 */
enum class TIMER_regs::SMCFG_shift : unsigned {
  ETP = 15,
  SMC1 = 14,
  ETPSC = 12,
  ETFC = 8,
  MSM = 7,
  TRGS = 4,
  SMC = 0,
};

/**
 * Bitmasks for TIMER DMAINTEN
 *
 * DMA/Interrupt enable register
 */
enum class TIMER_regs::DMAINTEN_bits : uint16_t {
  TRGDEN = (1u << 14),    ///< Trigger DMA request enable
  CMTDEN = (1u << 13),    ///< Commutation DMA request enable
  CH3DEN = (1u << 12),    ///< Channel 3 capture/compare DMA request enable
  CH2DEN = (1u << 11),    ///< Channel 2 capture/compare DMA request enable
  CH1DEN = (1u << 10),    ///< Channel 1 capture/compare DMA request enable
  CH0DEN = (1u << 9),     ///< Channel 0 capture/compare DMA request enable
  UPDEN = (1u << 8),      ///< Update DMA request enable
  BRKIE = (1u << 7),      ///< Break interrupt enable
  TRGIE = (1u << 6),      ///< Trigger interrupt enable
  CMTIE = (1u << 5),      ///< commutation interrupt enable
  CH3IE = (1u << 4),      ///< Channel 3 capture/compare interrupt enable
  CH2IE = (1u << 3),      ///< Channel 2 capture/compare interrupt enable
  CH1IE = (1u << 2),      ///< Channel 1 capture/compare interrupt enable
  CH0IE = (1u << 1),      ///< Channel 0 capture/compare interrupt enable
  UPIE = (1u << 0),       ///< Update interrupt enable
  Reserved_mask = 0x8000  ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::DMAINTEN_bits);

/**
 * Bit shifts for TIMER DMAINTEN
 */
enum class TIMER_regs::DMAINTEN_shift : unsigned {
  TRGDEN = 14,
  CMTDEN = 13,
  CH3DEN = 12,
  CH2DEN = 11,
  CH1DEN = 10,
  CH0DEN = 9,
  UPDEN = 8,
  BRKIE = 7,
  TRGIE = 6,
  CMTIE = 5,
  CH3IE = 4,
  CH2IE = 3,
  CH1IE = 2,
  CH0IE = 1,
  UPIE = 0,
};

/**
 * Bitmasks for TIMER INTF
 *
 * Interrupt flag register
 */
enum class TIMER_regs::INTF_bits : uint16_t {
  CH3OF = (1u << 12),     ///< Channel 3 over capture flag
  CH2OF = (1u << 11),     ///< Channel 2 over capture flag
  CH1OF = (1u << 10),     ///< Channel 1 over capture flag
  CH0OF = (1u << 9),      ///< Channel 0 over capture flag
  BRKIF = (1u << 7),      ///< Break interrupt flag
  TRGIF = (1u << 6),      ///< Trigger interrupt flag
  CMTIF = (1u << 5),      ///< Channel commutation interrupt flag
  CH3IF = (1u << 4),      ///< Channel 3 capture/compare interrupt flag
  CH2IF = (1u << 3),      ///< Channel 2 capture/compare interrupt flag
  CH1IF = (1u << 2),      ///< Channel 1 capture/compare interrupt flag
  CH0IF = (1u << 1),      ///< Channel 0 capture/compare interrupt flag
  UPIF = (1u << 0),       ///< Update interrupt flag
  Reserved_mask = 0xe100  ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::INTF_bits);

/**
 * Bit shifts for TIMER INTF
 */
enum class TIMER_regs::INTF_shift : unsigned {
  CH3OF = 12,
  CH2OF = 11,
  CH1OF = 10,
  CH0OF = 9,
  BRKIF = 7,
  TRGIF = 6,
  CMTIF = 5,
  CH3IF = 4,
  CH2IF = 3,
  CH1IF = 2,
  CH0IF = 1,
  UPIF = 0,
};

/**
 * Bitmasks for TIMER SWEVG
 *
 * Software event generation register
 */
enum class TIMER_regs::SWEVG_bits : uint16_t {
  BRKG = (1u << 7),       ///< Break event generation
  TRGG = (1u << 6),       ///< Trigger event generation
  CMTG = (1u << 5),       ///< Channel commutation event generation
  CH3G = (1u << 4),       ///< Channel 3 capture or compare event generation
  CH2G = (1u << 3),       ///< Channel 2 capture or compare event generation
  CH1G = (1u << 2),       ///< Channel 1 capture or compare event generation
  CH0G = (1u << 1),       ///< Channel 0 capture or compare event generation
  UPG = (1u << 0),        ///< Update event generation
  Reserved_mask = 0xff00  ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::SWEVG_bits);

/**
 * Bit shifts for TIMER SWEVG
 */
enum class TIMER_regs::SWEVG_shift : unsigned {
  BRKG = 7,
  TRGG = 6,
  CMTG = 5,
  CH3G = 4,
  CH2G = 3,
  CH1G = 2,
  CH0G = 1,
  UPG = 0,
};

/**
 * Bitmasks for TIMER CHCTL0_Output
 *
 * Channel control register 0 (output mode)
 */
enum class TIMER_regs::CHCTL0_Output_bits : uint16_t {
  CH1COMCEN = (1u << 15),         ///< Channel 1 output compare clear enable
  CH1COMCTL_mask = (0x7u << 12),  ///< Channel 1 compare output control
  CH1COMSEN = (1u << 11),         ///< Channel 1 output compare shadow enable
  CH1COMFEN = (1u << 10),         ///< Channel 1 output compare fast enable
  CH1MS_mask = (0x3u << 8),       ///< Channel 1 mode selection
  CH0COMCEN = (1u << 7),          ///< Channel 0 output compare clear enable
  CH0COMCTL_mask = (0x7u << 4),   ///< Channel 0 compare output control
  CH0COMSEN = (1u << 3),          ///< Channel 0 compare output shadow enable
  CH0COMFEN = (1u << 2),          ///< Channel 0 output compare fast enable
  CH0MS_mask = (0x3u << 0),       ///< Channel 0 I/O mode selection
};
void HasBitwiseOperators(TIMER_regs::CHCTL0_Output_bits);

/**
 * Bit shifts for TIMER CHCTL0_Output
 */
enum class TIMER_regs::CHCTL0_Output_shift : unsigned {
  CH1COMCEN = 15,
  CH1COMCTL = 12,
  CH1COMSEN = 11,
  CH1COMFEN = 10,
  CH1MS = 8,
  CH0COMCEN = 7,
  CH0COMCTL = 4,
  CH0COMSEN = 3,
  CH0COMFEN = 2,
  CH0MS = 0,
};

/**
 * Bitmasks for TIMER CHCTL0_Input
 *
 * Channel control register 0 (input mode)
 */
enum class TIMER_regs::CHCTL0_Input_bits : uint16_t {
  CH1CAPFLT_mask = (0xfu << 12),  ///< Channel 1 input capture filter control
  CH1CAPPSC_mask = (0x3u << 10),  ///< Channel 1 input capture prescaler
  CH1MS_mask = (0x3u << 8),       ///< Channel 1 mode selection
  CH0CAPFLT_mask = (0xfu << 4),   ///< Channel 0 input capture filter control
  CH0CAPPSC_mask = (0x3u << 2),   ///< Channel 0 input capture prescaler
  CH0MS_mask = (0x3u << 0),       ///< Channel 0 mode selection
};
void HasBitwiseOperators(TIMER_regs::CHCTL0_Input_bits);

/**
 * Bit shifts for TIMER CHCTL0_Input
 */
enum class TIMER_regs::CHCTL0_Input_shift : unsigned {
  CH1CAPFLT = 12,
  CH1CAPPSC = 10,
  CH1MS = 8,
  CH0CAPFLT = 4,
  CH0CAPPSC = 2,
  CH0MS = 0,
};

/**
 * Bitmasks for TIMER CHCTL1_Output
 *
 * Channel control register 1 (output mode)
 */
enum class TIMER_regs::CHCTL1_Output_bits : uint16_t {
  CH3COMCEN = (1u << 15),         ///< Channel 3 output compare clear enable
  CH3COMCTL_mask = (0x7u << 12),  ///< Channel 3 compare output control
  CH3COMSEN = (1u << 11),         ///< Channel 3 output compare shadow enable
  CH3COMFEN = (1u << 10),         ///< Channel 3 output compare fast enable
  CH3MS_mask = (0x3u << 8),       ///< Channel 3 mode selection
  CH2COMCEN = (1u << 7),          ///< Channel 2 output compare clear enable
  CH2COMCTL_mask = (0x7u << 4),   ///< Channel 2 compare output control
  CH2COMSEN = (1u << 3),          ///< Channel 2 compare output shadow enable
  CH2COMFEN = (1u << 2),          ///< Channel 2 output compare fast enable
  CH2MS_mask = (0x3u << 0),       ///< Channel 2 I/O mode selection
};
void HasBitwiseOperators(TIMER_regs::CHCTL1_Output_bits);

/**
 * Bit shifts for TIMER CHCTL1_Output
 */
enum class TIMER_regs::CHCTL1_Output_shift : unsigned {
  CH3COMCEN = 15,
  CH3COMCTL = 12,
  CH3COMSEN = 11,
  CH3COMFEN = 10,
  CH3MS = 8,
  CH2COMCEN = 7,
  CH2COMCTL = 4,
  CH2COMSEN = 3,
  CH2COMFEN = 2,
  CH2MS = 0,
};

/**
 * Bitmasks for TIMER CHCTL1_Input
 *
 * Channel control register 1 (input mode)
 */
enum class TIMER_regs::CHCTL1_Input_bits : uint16_t {
  CH3CAPFLT_mask = (0xfu << 12),  ///< Channel 3 input capture filter control
  CH3CAPPSC_mask = (0x3u << 10),  ///< Channel 3 input capture prescaler
  CH3MS_mask = (0x3u << 8),       ///< Channel 3 mode selection
  CH2CAPFLT_mask = (0xfu << 4),   ///< Channel 2 input capture filter control
  CH2CAPPSC_mask = (0x3u << 2),   ///< Channel 2 input capture prescaler
  CH2MS_mask = (0x3u << 0),       ///< Channel 2 mode selection
};
void HasBitwiseOperators(TIMER_regs::CHCTL1_Input_bits);

/**
 * Bit shifts for TIMER CHCTL1_Input
 */
enum class TIMER_regs::CHCTL1_Input_shift : unsigned {
  CH3CAPFLT = 12,
  CH3CAPPSC = 10,
  CH3MS = 8,
  CH2CAPFLT = 4,
  CH2CAPPSC = 2,
  CH2MS = 0,
};

/**
 * Bitmasks for TIMER CHCTL2
 *
 * Channel control register 2
 */
enum class TIMER_regs::CHCTL2_bits : uint16_t {
  CH3P = (1u << 13),      ///< Channel 3 capture/compare function polarity
  CH3EN = (1u << 12),     ///< Channel 3 capture/compare function enable
  CH2NP = (1u << 11),     ///< Channel 2 complementary output polarity
  CH2NEN = (1u << 10),    ///< Channel 2 complementary output enable
  CH2P = (1u << 9),       ///< Channel 2 capture/compare function polarity
  CH2EN = (1u << 8),      ///< Channel 2 capture/compare function enable
  CH1NP = (1u << 7),      ///< Channel 1 complementary output polarity
  CH1NEN = (1u << 6),     ///< Channel 1 complementary output enable
  CH1P = (1u << 5),       ///< Channel 1 capture/compare function polarity
  CH1EN = (1u << 4),      ///< Channel 1 capture/compare function enable
  CH0NP = (1u << 3),      ///< Channel 0 complementary output polarity
  CH0NEN = (1u << 2),     ///< Channel 0 complementary output enable
  CH0P = (1u << 1),       ///< Channel 0 capture/compare function polarity
  CH0EN = (1u << 0),      ///< Channel 0 capture/compare function enable
  Reserved_mask = 0xc000  ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::CHCTL2_bits);

/**
 * Bit shifts for TIMER CHCTL2
 */
enum class TIMER_regs::CHCTL2_shift : unsigned {
  CH3P = 13,
  CH3EN = 12,
  CH2NP = 11,
  CH2NEN = 10,
  CH2P = 9,
  CH2EN = 8,
  CH1NP = 7,
  CH1NEN = 6,
  CH1P = 5,
  CH1EN = 4,
  CH0NP = 3,
  CH0NEN = 2,
  CH0P = 1,
  CH0EN = 0,
};

/**
 * Bitmasks for TIMER CNT
 *
 * counter
 */
enum class TIMER_regs::CNT_bits : uint16_t {
  CNT_mask = (0xffffu << 0),  ///< current counter value
};
void HasBitwiseOperators(TIMER_regs::CNT_bits);

/**
 * Bit shifts for TIMER CNT
 */
enum class TIMER_regs::CNT_shift : unsigned {
  CNT = 0,
};

/**
 * Bitmasks for TIMER PSC
 *
 * prescaler
 */
enum class TIMER_regs::PSC_bits : uint16_t {
  PSC_mask = (0xffffu << 0),  ///< Prescaler value of the counter clock
};
void HasBitwiseOperators(TIMER_regs::PSC_bits);

/**
 * Bit shifts for TIMER PSC
 */
enum class TIMER_regs::PSC_shift : unsigned {
  PSC = 0,
};

/**
 * Bitmasks for TIMER CAR
 *
 * Counter auto reload register
 */
enum class TIMER_regs::CAR_bits : uint16_t {
  CARL_mask = (0xffffu << 0),  ///< Counter auto reload value
};
void HasBitwiseOperators(TIMER_regs::CAR_bits);

/**
 * Bit shifts for TIMER CAR
 */
enum class TIMER_regs::CAR_shift : unsigned {
  CARL = 0,
};

/**
 * Bitmasks for TIMER CREP
 *
 * Counter repetition register
 */
enum class TIMER_regs::CREP_bits : uint16_t {
  CREP_mask = (0xffu << 0),  ///< Counter repetition value
  Reserved_mask = 0xff00     ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::CREP_bits);

/**
 * Bit shifts for TIMER CREP
 */
enum class TIMER_regs::CREP_shift : unsigned {
  CREP = 0,
};

/**
 * Bitmasks for TIMER CH0CV
 *
 * Channel 0 capture/compare value register
 */
enum class TIMER_regs::CH0CV_bits : uint16_t {
  CH0VAL_mask = (0xffffu << 0),  ///< Capture or compare value of channel0
};
void HasBitwiseOperators(TIMER_regs::CH0CV_bits);

/**
 * Bit shifts for TIMER CH0CV
 */
enum class TIMER_regs::CH0CV_shift : unsigned {
  CH0VAL = 0,
};

/**
 * Bitmasks for TIMER CH1CV
 *
 * Channel 1 capture/compare value register
 */
enum class TIMER_regs::CH1CV_bits : uint16_t {
  CH1VAL_mask = (0xffffu << 0),  ///< Capture or compare value of channel1
};
void HasBitwiseOperators(TIMER_regs::CH1CV_bits);

/**
 * Bit shifts for TIMER CH1CV
 */
enum class TIMER_regs::CH1CV_shift : unsigned {
  CH1VAL = 0,
};

/**
 * Bitmasks for TIMER CH2CV
 *
 * Channel 2 capture/compare value register
 */
enum class TIMER_regs::CH2CV_bits : uint16_t {
  CH2VAL_mask = (0xffffu << 0),  ///< Capture or compare value of channel 2
};
void HasBitwiseOperators(TIMER_regs::CH2CV_bits);

/**
 * Bit shifts for TIMER CH2CV
 */
enum class TIMER_regs::CH2CV_shift : unsigned {
  CH2VAL = 0,
};

/**
 * Bitmasks for TIMER CH3CV
 *
 * Channel 3 capture/compare value register
 */
enum class TIMER_regs::CH3CV_bits : uint16_t {
  CH3VAL_mask = (0xffffu << 0),  ///< Capture or compare value of channel 3
};
void HasBitwiseOperators(TIMER_regs::CH3CV_bits);

/**
 * Bit shifts for TIMER CH3CV
 */
enum class TIMER_regs::CH3CV_shift : unsigned {
  CH3VAL = 0,
};

/**
 * Bitmasks for TIMER CCHP
 *
 * channel complementary protection register
 */
enum class TIMER_regs::CCHP_bits : uint16_t {
  POEN = (1u << 15),          ///< Primary output enable
  OAEN = (1u << 14),          ///< Output automatic enable
  BRKP = (1u << 13),          ///< Break polarity
  BRKEN = (1u << 12),         ///< Break enable
  ROS = (1u << 11),           ///< Run mode off-state configure
  IOS = (1u << 10),           ///< Idle mode off-state configure
  PROT_mask = (0x3u << 8),    ///< Complementary register protect control
  DTCFG_mask = (0xffu << 0),  ///< Dead time configure
};
void HasBitwiseOperators(TIMER_regs::CCHP_bits);

/**
 * Bit shifts for TIMER CCHP
 */
enum class TIMER_regs::CCHP_shift : unsigned {
  POEN = 15,
  OAEN = 14,
  BRKP = 13,
  BRKEN = 12,
  ROS = 11,
  IOS = 10,
  PROT = 8,
  DTCFG = 0,
};

/**
 * Bitmasks for TIMER DMACFG
 *
 * DMA configuration register
 */
enum class TIMER_regs::DMACFG_bits : uint16_t {
  DMATC_mask = (0x1fu << 8),  ///< DMA transfer count
  DMATA_mask = (0x1fu << 0),  ///< DMA transfer access start address
  Reserved_mask = 0xe0e0      ///< All reserved bits
};
void HasBitwiseOperators(TIMER_regs::DMACFG_bits);

/**
 * Bit shifts for TIMER DMACFG
 */
enum class TIMER_regs::DMACFG_shift : unsigned {
  DMATC = 8,
  DMATA = 0,
};

/**
 * Bitmasks for TIMER DMATB
 *
 * DMA transfer buffer register
 */
enum class TIMER_regs::DMATB_bits : uint16_t {
  DMATB_mask = (0xffffu << 0),  ///< DMA transfer buffer
};
void HasBitwiseOperators(TIMER_regs::DMATB_bits);

/**
 * Bit shifts for TIMER DMATB
 */
enum class TIMER_regs::DMATB_shift : unsigned {
  DMATB = 0,
};

static_assert(offsetof(TIMER_regs, CTL0) == 0x0);
static_assert(offsetof(TIMER_regs, CTL1) == 0x4);
static_assert(offsetof(TIMER_regs, SMCFG) == 0x8);
static_assert(offsetof(TIMER_regs, DMAINTEN) == 0xc);
static_assert(offsetof(TIMER_regs, INTF) == 0x10);
static_assert(offsetof(TIMER_regs, SWEVG) == 0x14);
static_assert(offsetof(TIMER_regs, CHCTL0_Output) == 0x18);
static_assert(offsetof(TIMER_regs, CHCTL0_Input) == 0x18);
static_assert(offsetof(TIMER_regs, CHCTL1_Output) == 0x1c);
static_assert(offsetof(TIMER_regs, CHCTL1_Input) == 0x1c);
static_assert(offsetof(TIMER_regs, CHCTL2) == 0x20);
static_assert(offsetof(TIMER_regs, CNT) == 0x24);
static_assert(offsetof(TIMER_regs, PSC) == 0x28);
static_assert(offsetof(TIMER_regs, CAR) == 0x2c);
static_assert(offsetof(TIMER_regs, CREP) == 0x30);
static_assert(offsetof(TIMER_regs, CH0CV) == 0x34);
static_assert(offsetof(TIMER_regs, CH1CV) == 0x38);
static_assert(offsetof(TIMER_regs, CH2CV) == 0x3c);
static_assert(offsetof(TIMER_regs, CH3CV) == 0x40);
static_assert(offsetof(TIMER_regs, CCHP) == 0x44);
static_assert(offsetof(TIMER_regs, DMACFG) == 0x48);
static_assert(offsetof(TIMER_regs, DMATB) == 0x4c);
}  // namespace deri::mmio
