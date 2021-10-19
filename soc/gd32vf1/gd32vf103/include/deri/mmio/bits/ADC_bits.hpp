/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/ADC.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for ADC STAT
 *
 * status register
 */
enum class ADC_regs::STAT_bits : uint32_t {
  STRC = (1 << 4),            ///< Start flag of regular channel group
  STIC = (1 << 3),            ///< Start flag of inserted channel group
  EOIC = (1 << 2),            ///< End of inserted group conversion flag
  EOC = (1 << 1),             ///< End of group conversion flag
  WDE = (1 << 0),             ///< Analog watchdog event flag
  Reserved_mask = 0xffffffe0  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::STAT_bits);

/**
 * Bit shifts for ADC STAT
 */
enum class ADC_regs::STAT_shift : unsigned {
  STRC = 4,
  STIC = 3,
  EOIC = 2,
  EOC = 1,
  WDE = 0,
};

/**
 * Bitmasks for ADC CTL0
 *
 * control register 0
 */
enum class ADC_regs::CTL0_bits : uint32_t {
  RWDEN = (1 << 23),          ///< Regular channel analog watchdog enable
  IWDEN = (1 << 22),          ///< Inserted channel analog watchdog enable
  SYNCM_mask = (0xf << 16),   ///< sync mode selection
  DISNUM_mask = (0x7 << 13),  ///< Number of conversions in discontinuous mode
  DISIC = (1 << 12),          ///< Discontinuous mode on inserted channels
  DISRC = (1 << 11),          ///< Discontinuous mode on regular channels
  ICA = (1 << 10),            ///< Inserted channel group convert automatically
  WDSC = (1 << 9),    ///< When in scan mode, analog watchdog is effective on a
                      ///< single channel
  SM = (1 << 8),      ///< Scan mode
  EOICIE = (1 << 7),  ///< Interrupt enable for EOIC
  WDEIE = (1 << 6),   ///< Interrupt enable for WDE
  EOCIE = (1 << 5),   ///< Interrupt enable for EOC
  WDCHSEL_mask = (0x1f << 0),  ///< Analog watchdog channel select
  Reserved_mask = 0xff300000   ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::CTL0_bits);

/**
 * Bit shifts for ADC CTL0
 */
enum class ADC_regs::CTL0_shift : unsigned {
  RWDEN = 23,
  IWDEN = 22,
  SYNCM = 16,
  DISNUM = 13,
  DISIC = 12,
  DISRC = 11,
  ICA = 10,
  WDSC = 9,
  SM = 8,
  EOICIE = 7,
  WDEIE = 6,
  EOCIE = 5,
  WDCHSEL = 0,
};

/**
 * Bitmasks for ADC CTL1
 *
 * control register 1
 */
enum class ADC_regs::CTL1_bits : uint32_t {
  TSVREN = (1 << 23),         ///< Channel 16 and 17 enable of ADC0
  SWRCST = (1 << 22),         ///< Start on regular channel
  SWICST = (1 << 21),         ///< Start on inserted channel
  ETERC = (1 << 20),          ///< External trigger enable for regular channel
  ETSRC_mask = (0x7 << 17),   ///< External trigger select for regular channel
  ETEIC = (1 << 15),          ///< External trigger select for inserted channel
  ETSIC_mask = (0x7 << 12),   ///< External trigger select for inserted channel
  DAL = (1 << 11),            ///< Data alignment
  DMA = (1 << 8),             ///< DMA request enable
  RSTCLB = (1 << 3),          ///< Reset calibration
  CLB = (1 << 2),             ///< ADC calibration
  CTN = (1 << 1),             ///< Continuous mode
  ADCON = (1 << 0),           ///< ADC on
  Reserved_mask = 0xff0106f0  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::CTL1_bits);

/**
 * Bit shifts for ADC CTL1
 */
enum class ADC_regs::CTL1_shift : unsigned {
  TSVREN = 23,
  SWRCST = 22,
  SWICST = 21,
  ETERC = 20,
  ETSRC = 17,
  ETEIC = 15,
  ETSIC = 12,
  DAL = 11,
  DMA = 8,
  RSTCLB = 3,
  CLB = 2,
  CTN = 1,
  ADCON = 0,
};

/**
 * Bitmasks for ADC SAMPT0
 *
 * Sample time register 0
 */
enum class ADC_regs::SAMPT0_bits : uint32_t {
  SPT10_mask = (0x7 << 0),    ///< Channel 10 sample time selection
  SPT11_mask = (0x7 << 3),    ///< Channel 11 sample time selection
  SPT12_mask = (0x7 << 6),    ///< Channel 12 sample time selection
  SPT13_mask = (0x7 << 9),    ///< Channel 13 sample time selection
  SPT14_mask = (0x7 << 12),   ///< Channel 14 sample time selection
  SPT15_mask = (0x7 << 15),   ///< Channel 15 sample time selection
  SPT16_mask = (0x7 << 18),   ///< Channel 16 sample time selection
  SPT17_mask = (0x7 << 21),   ///< Channel 17 sample time selection
  Reserved_mask = 0xff000000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::SAMPT0_bits);

/**
 * Bit shifts for ADC SAMPT0
 */
enum class ADC_regs::SAMPT0_shift : unsigned {
  SPT10 = 0,
  SPT11 = 3,
  SPT12 = 6,
  SPT13 = 9,
  SPT14 = 12,
  SPT15 = 15,
  SPT16 = 18,
  SPT17 = 21,
};

/**
 * Bitmasks for ADC SAMPT1
 *
 * Sample time register 1
 */
enum class ADC_regs::SAMPT1_bits : uint32_t {
  SPT0_mask = (0x7 << 0),     ///< Channel 0 sample time selection
  SPT1_mask = (0x7 << 3),     ///< Channel 1 sample time selection
  SPT2_mask = (0x7 << 6),     ///< Channel 2 sample time selection
  SPT3_mask = (0x7 << 9),     ///< Channel 3 sample time selection
  SPT4_mask = (0x7 << 12),    ///< Channel 4 sample time selection
  SPT5_mask = (0x7 << 15),    ///< Channel 5 sample time selection
  SPT6_mask = (0x7 << 18),    ///< Channel 6 sample time selection
  SPT7_mask = (0x7 << 21),    ///< Channel 7 sample time selection
  SPT8_mask = (0x7 << 24),    ///< Channel 8 sample time selection
  SPT9_mask = (0x7 << 27),    ///< Channel 9 sample time selection
  Reserved_mask = 0xc0000000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::SAMPT1_bits);

/**
 * Bit shifts for ADC SAMPT1
 */
enum class ADC_regs::SAMPT1_shift : unsigned {
  SPT0 = 0,
  SPT1 = 3,
  SPT2 = 6,
  SPT3 = 9,
  SPT4 = 12,
  SPT5 = 15,
  SPT6 = 18,
  SPT7 = 21,
  SPT8 = 24,
  SPT9 = 27,
};

/**
 * Bitmasks for ADC IOFF0
 *
 * Inserted channel data offset register 0
 */
enum class ADC_regs::IOFF0_bits : uint32_t {
  IOFF_mask = (0xfff << 0),   ///< Data offset for inserted channel 0
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IOFF0_bits);

/**
 * Bit shifts for ADC IOFF0
 */
enum class ADC_regs::IOFF0_shift : unsigned {
  IOFF = 0,
};

/**
 * Bitmasks for ADC IOFF1
 *
 * Inserted channel data offset register 1
 */
enum class ADC_regs::IOFF1_bits : uint32_t {
  IOFF_mask = (0xfff << 0),   ///< Data offset for inserted channel 1
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IOFF1_bits);

/**
 * Bit shifts for ADC IOFF1
 */
enum class ADC_regs::IOFF1_shift : unsigned {
  IOFF = 0,
};

/**
 * Bitmasks for ADC IOFF2
 *
 * Inserted channel data offset register 2
 */
enum class ADC_regs::IOFF2_bits : uint32_t {
  IOFF_mask = (0xfff << 0),   ///< Data offset for inserted channel 2
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IOFF2_bits);

/**
 * Bit shifts for ADC IOFF2
 */
enum class ADC_regs::IOFF2_shift : unsigned {
  IOFF = 0,
};

/**
 * Bitmasks for ADC IOFF3
 *
 * Inserted channel data offset register 3
 */
enum class ADC_regs::IOFF3_bits : uint32_t {
  IOFF_mask = (0xfff << 0),   ///< Data offset for inserted channel 3
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IOFF3_bits);

/**
 * Bit shifts for ADC IOFF3
 */
enum class ADC_regs::IOFF3_shift : unsigned {
  IOFF = 0,
};

/**
 * Bitmasks for ADC WDHT
 *
 * watchdog higher threshold register
 */
enum class ADC_regs::WDHT_bits : uint32_t {
  WDHT_mask = (0xfff << 0),   ///< Analog watchdog higher threshold
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::WDHT_bits);

/**
 * Bit shifts for ADC WDHT
 */
enum class ADC_regs::WDHT_shift : unsigned {
  WDHT = 0,
};

/**
 * Bitmasks for ADC WDLT
 *
 * watchdog lower threshold register
 */
enum class ADC_regs::WDLT_bits : uint32_t {
  WDLT_mask = (0xfff << 0),   ///< Analog watchdog lower threshold
  Reserved_mask = 0xfffff000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::WDLT_bits);

/**
 * Bit shifts for ADC WDLT
 */
enum class ADC_regs::WDLT_shift : unsigned {
  WDLT = 0,
};

/**
 * Bitmasks for ADC RSQ0
 *
 * regular sequence register 0
 */
enum class ADC_regs::RSQ0_bits : uint32_t {
  RL_mask = (0xf << 20),      ///< Regular channel group length
  RSQ15_mask = (0x1f << 15),  ///< 16th conversion in regular sequence
  RSQ14_mask = (0x1f << 10),  ///< 15th conversion in regular sequence
  RSQ13_mask = (0x1f << 5),   ///< 14th conversion in regular sequence
  RSQ12_mask = (0x1f << 0),   ///< 13th conversion in regular sequence
  Reserved_mask = 0xff000000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::RSQ0_bits);

/**
 * Bit shifts for ADC RSQ0
 */
enum class ADC_regs::RSQ0_shift : unsigned {
  RL = 20,
  RSQ15 = 15,
  RSQ14 = 10,
  RSQ13 = 5,
  RSQ12 = 0,
};

/**
 * Bitmasks for ADC RSQ1
 *
 * regular sequence register 1
 */
enum class ADC_regs::RSQ1_bits : uint32_t {
  RSQ11_mask = (0x1f << 25),  ///< 12th conversion in regular sequence
  RSQ10_mask = (0x1f << 20),  ///< 11th conversion in regular sequence
  RSQ9_mask = (0x1f << 15),   ///< 10th conversion in regular sequence
  RSQ8_mask = (0x1f << 10),   ///< 9th conversion in regular sequence
  RSQ7_mask = (0x1f << 5),    ///< 8th conversion in regular sequence
  RSQ6_mask = (0x1f << 0),    ///< 7th conversion in regular sequence
  Reserved_mask = 0xc0000000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::RSQ1_bits);

/**
 * Bit shifts for ADC RSQ1
 */
enum class ADC_regs::RSQ1_shift : unsigned {
  RSQ11 = 25,
  RSQ10 = 20,
  RSQ9 = 15,
  RSQ8 = 10,
  RSQ7 = 5,
  RSQ6 = 0,
};

/**
 * Bitmasks for ADC RSQ2
 *
 * regular sequence register 2
 */
enum class ADC_regs::RSQ2_bits : uint32_t {
  RSQ5_mask = (0x1f << 25),   ///< 6th conversion in regular sequence
  RSQ4_mask = (0x1f << 20),   ///< 5th conversion in regular sequence
  RSQ3_mask = (0x1f << 15),   ///< 4th conversion in regular sequence
  RSQ2_mask = (0x1f << 10),   ///< 3rd conversion in regular sequence
  RSQ1_mask = (0x1f << 5),    ///< 2nd conversion in regular sequence
  RSQ0_mask = (0x1f << 0),    ///< 1st conversion in regular sequence
  Reserved_mask = 0xc0000000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::RSQ2_bits);

/**
 * Bit shifts for ADC RSQ2
 */
enum class ADC_regs::RSQ2_shift : unsigned {
  RSQ5 = 25,
  RSQ4 = 20,
  RSQ3 = 15,
  RSQ2 = 10,
  RSQ1 = 5,
  RSQ0 = 0,
};

/**
 * Bitmasks for ADC ISQ
 *
 * Inserted sequence register
 */
enum class ADC_regs::ISQ_bits : uint32_t {
  IL_mask = (0x3 << 20),      ///< Inserted channel group length
  ISQ3_mask = (0x1f << 15),   ///< 4th conversion in inserted sequence
  ISQ2_mask = (0x1f << 10),   ///< 3rd conversion in inserted sequence
  ISQ1_mask = (0x1f << 5),    ///< 2nd conversion in inserted sequence
  ISQ0_mask = (0x1f << 0),    ///< 1st conversion in inserted sequence
  Reserved_mask = 0xffc00000  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::ISQ_bits);

/**
 * Bit shifts for ADC ISQ
 */
enum class ADC_regs::ISQ_shift : unsigned {
  IL = 20,
  ISQ3 = 15,
  ISQ2 = 10,
  ISQ1 = 5,
  ISQ0 = 0,
};

/**
 * Bitmasks for ADC IDATA0
 *
 * Inserted data register 0
 */
enum class ADC_regs::IDATA0_bits : uint32_t {
  IDATAn_mask = (0xffff << 0),  ///< Inserted number n conversion data
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IDATA0_bits);

/**
 * Bit shifts for ADC IDATA0
 */
enum class ADC_regs::IDATA0_shift : unsigned {
  IDATAn = 0,
};

/**
 * Bitmasks for ADC IDATA1
 *
 * Inserted data register 1
 */
enum class ADC_regs::IDATA1_bits : uint32_t {
  IDATAn_mask = (0xffff << 0),  ///< Inserted number n conversion data
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IDATA1_bits);

/**
 * Bit shifts for ADC IDATA1
 */
enum class ADC_regs::IDATA1_shift : unsigned {
  IDATAn = 0,
};

/**
 * Bitmasks for ADC IDATA2
 *
 * Inserted data register 2
 */
enum class ADC_regs::IDATA2_bits : uint32_t {
  IDATAn_mask = (0xffff << 0),  ///< Inserted number n conversion data
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IDATA2_bits);

/**
 * Bit shifts for ADC IDATA2
 */
enum class ADC_regs::IDATA2_shift : unsigned {
  IDATAn = 0,
};

/**
 * Bitmasks for ADC IDATA3
 *
 * Inserted data register 3
 */
enum class ADC_regs::IDATA3_bits : uint32_t {
  IDATAn_mask = (0xffff << 0),  ///< Inserted number n conversion data
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::IDATA3_bits);

/**
 * Bit shifts for ADC IDATA3
 */
enum class ADC_regs::IDATA3_shift : unsigned {
  IDATAn = 0,
};

/**
 * Bitmasks for ADC RDATA
 *
 * regular data register
 */
enum class ADC_regs::RDATA_bits : uint32_t {
  ADC1RDTR_mask = (0xffff << 16),  ///< ADC regular channel data
  RDATA_mask = (0xffff << 0),      ///< Regular channel data
};
void HasBitwiseOperators(ADC_regs::RDATA_bits);

/**
 * Bit shifts for ADC RDATA
 */
enum class ADC_regs::RDATA_shift : unsigned {
  ADC1RDTR = 16,
  RDATA = 0,
};

/**
 * Bitmasks for ADC OVSAMPCTL
 *
 * Oversample control register
 */
enum class ADC_regs::OVSAMPCTL_bits : uint32_t {
  DRES_mask = (0x3 << 12),    ///< ADC resolution
  TOVS = (1 << 9),            ///< Triggered Oversampling
  OVSS_mask = (0xf << 5),     ///< Oversampling shift
  OVSR_mask = (0x7 << 2),     ///< Oversampling ratio
  OVSEN = (1 << 0),           ///< Oversampler Enable
  Reserved_mask = 0xffffcc02  ///< All reserved bits
};
void HasBitwiseOperators(ADC_regs::OVSAMPCTL_bits);

/**
 * Bit shifts for ADC OVSAMPCTL
 */
enum class ADC_regs::OVSAMPCTL_shift : unsigned {
  DRES = 12,
  TOVS = 9,
  OVSS = 5,
  OVSR = 2,
  OVSEN = 0,
};

static_assert(offsetof(ADC_regs, STAT) == 0x0);
static_assert(offsetof(ADC_regs, CTL0) == 0x4);
static_assert(offsetof(ADC_regs, CTL1) == 0x8);
static_assert(offsetof(ADC_regs, SAMPT0) == 0xc);
static_assert(offsetof(ADC_regs, SAMPT1) == 0x10);
static_assert(offsetof(ADC_regs, IOFF0) == 0x14);
static_assert(offsetof(ADC_regs, IOFF1) == 0x18);
static_assert(offsetof(ADC_regs, IOFF2) == 0x1c);
static_assert(offsetof(ADC_regs, IOFF3) == 0x20);
static_assert(offsetof(ADC_regs, WDHT) == 0x24);
static_assert(offsetof(ADC_regs, WDLT) == 0x28);
static_assert(offsetof(ADC_regs, RSQ0) == 0x2c);
static_assert(offsetof(ADC_regs, RSQ1) == 0x30);
static_assert(offsetof(ADC_regs, RSQ2) == 0x34);
static_assert(offsetof(ADC_regs, ISQ) == 0x38);
static_assert(offsetof(ADC_regs, IDATA0) == 0x3c);
static_assert(offsetof(ADC_regs, IDATA1) == 0x40);
static_assert(offsetof(ADC_regs, IDATA2) == 0x44);
static_assert(offsetof(ADC_regs, IDATA3) == 0x48);
static_assert(offsetof(ADC_regs, RDATA) == 0x4c);
static_assert(offsetof(ADC_regs, OVSAMPCTL) == 0x80);
}  // namespace deri::mmio
