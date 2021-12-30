/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/PMU.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for PMU pmuwakepm[8]
 *
 * PMU Wake Program Memory
 */
enum class PMU_regs::pmuwakepm_bits : uint32_t {
  isolate = (1u << 9),
  hfclkrst = (1u << 8),
  corerst = (1u << 7),
  pmu_out_1_en = (1u << 5),
  pmu_out_0_en = (1u << 4),
  delay_mask = (0xfu << 0),
  Reserved_mask = 0xfffffc40  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::pmuwakepm_bits);

/**
 * Bit shifts for PMU pmuwakepm[8]
 */
enum class PMU_regs::pmuwakepm_shift : unsigned {
  isolate = 9,
  hfclkrst = 8,
  corerst = 7,
  pmu_out_1_en = 5,
  pmu_out_0_en = 4,
  delay = 0,
};

/**
 * Bitmasks for PMU pmusleeppm[8]
 *
 * PMU Sleep Program Memory
 */
enum class PMU_regs::pmusleeppm_bits : uint32_t {
  isolate = (1u << 9),
  hfclkrst = (1u << 8),
  corerst = (1u << 7),
  pmu_out_1_en = (1u << 5),
  pmu_out_0_en = (1u << 4),
  delay_mask = (0xfu << 0),
  Reserved_mask = 0xfffffc40  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::pmusleeppm_bits);

/**
 * Bit shifts for PMU pmusleeppm[8]
 */
enum class PMU_regs::pmusleeppm_shift : unsigned {
  isolate = 9,
  hfclkrst = 8,
  corerst = 7,
  pmu_out_1_en = 5,
  pmu_out_0_en = 4,
  delay = 0,
};

/**
 * Bitmasks for PMU pmuie
 *
 * PMU Interrupt Enable Register
 */
enum class PMU_regs::pmuie_bits : uint32_t {
  awakeup = (1u << 3),
  dwakeup = (1u << 2),
  rtc = (1u << 1),
  Reserved_mask = 0xfffffff1  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::pmuie_bits);

/**
 * Bit shifts for PMU pmuie
 */
enum class PMU_regs::pmuie_shift : unsigned {
  awakeup = 3,
  dwakeup = 2,
  rtc = 1,
};

/**
 * Bitmasks for PMU pmucause
 *
 * PMU Cause Register
 */
enum class PMU_regs::pmucause_bits : uint32_t {
  resetcause_mask = (0x3u << 8),
  wakeupcause_mask = (0x3u << 0),
  Reserved_mask = 0xfffffcfc  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::pmucause_bits);

/**
 * Bit shifts for PMU pmucause
 */
enum class PMU_regs::pmucause_shift : unsigned {
  resetcause = 8,
  wakeupcause = 0,
};

/**
 * Bitmasks for PMU pmusleep
 *
 * PMU Sleep Register
 */
enum class PMU_regs::pmusleep_bits : uint32_t {
  sleep = (1u << 0),
  Reserved_mask = 0xfffffffe  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::pmusleep_bits);

/**
 * Bit shifts for PMU pmusleep
 */
enum class PMU_regs::pmusleep_shift : unsigned {
  sleep = 0,
};

/**
 * Bitmasks for PMU pmukey
 *
 * PMU Key Register
 */
enum class PMU_regs::pmukey_bits : uint32_t {
  Reserved_mask = 0xffffffff  ///< All reserved bits
};
void HasBitwiseOperators(PMU_regs::pmukey_bits);

/**
 * Bit shifts for PMU pmukey
 */
enum class PMU_regs::pmukey_shift : unsigned {};

static_assert(offsetof(PMU_regs, pmuwakepm) == 0x0);
static_assert(offsetof(PMU_regs, pmusleeppm) == 0x20);
static_assert(offsetof(PMU_regs, pmuie) == 0x40);
static_assert(offsetof(PMU_regs, pmucause) == 0x44);
static_assert(offsetof(PMU_regs, pmusleep) == 0x48);
static_assert(offsetof(PMU_regs, pmukey) == 0x4c);
}  // namespace deri::mmio
