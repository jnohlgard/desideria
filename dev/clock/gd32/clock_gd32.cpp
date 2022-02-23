/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/clock_gd32.hpp"

#include "deri/bsp/devices.hpp"

namespace deri::dev::clock {

namespace {
constexpr RcuGd32::PllConfig::Fraction pllFraction(RcuGd32::CFG0_bits cfg0,
                                                   RcuGd32::CFG1_bits cfg1) {
  using CFG0_bits = RcuGd32::CFG0_bits;
  using CFG0_shift = RcuGd32::CFG0_shift;
  using CFG1_bits = RcuGd32::CFG1_bits;
  using CFG1_shift = RcuGd32::CFG1_shift;
  RcuGd32::PllConfig::Fraction result{};
  auto predv0 =
      extractValueFromBits(cfg1, CFG1_bits::PREDV0_mask, CFG1_shift::PREDV0);
  result.denominator = predv0 + 1;
  auto pllmf30 = extractValueFromBits(
      cfg0, CFG0_bits::PLLMF_3_0_mask, CFG0_shift::PLLMF_3_0);
  if (!!(cfg0 & CFG0_bits::PLLMF_4)) {
    result.numerator = 17 + pllmf30;
  } else if (pllmf30 < 13) {
    result.numerator = 2 + pllmf30;
  } else if (pllmf30 == 13) {
    // x 6.5
    result.numerator = 13;
    result.denominator *= 2;
  } else {
    result.numerator = 16;
  }
  return result;
}
}  // namespace

uint32_t RcuGd32::sysFreq() const {
  using CFG0_bits = mmio::RCU_regs::CFG0_bits;
  using CFG0_shift = mmio::RCU_regs::CFG0_shift;

  switch (extractValueFromBits(
      RCU.CFG0.load(), CFG0_bits::SCSS_mask, CFG0_shift::SCSS)) {
    case 0b00:
      // IRC8M is the current clock source
      return 8'000'000u;
    case 0b01:
      // HXTAL is the current clock source
      return bsp::hxtal_freq;
    case 0b10:
      // PLL is the current clock source
      auto pll_fraction = pllFraction(RCU.CFG0.load(), RCU.CFG1.load());
      // TODO check CFG0::PLLSEL
      return (bsp::hxtal_freq * pll_fraction.numerator) /
             pll_fraction.denominator;
  }
  return 0;
}

uint32_t RcuGd32::ahbFreq() const {
  auto ck_sys = sysFreq();
  return ck_sys >> ahbPrescaler();
}

uint32_t RcuGd32::apb1Freq() const {
  auto ck_ahb = ahbFreq();
  return ck_ahb >> apb1Prescaler();
}

uint32_t RcuGd32::apb2Freq() const {
  auto ck_ahb = ahbFreq();
  return ck_ahb >> apb2Prescaler();
}

using CFG0_bits = mmio::RCU_regs::CFG0_bits;
using CFG0_shift = mmio::RCU_regs::CFG0_shift;

unsigned RcuGd32::apb1Prescaler() const {
  auto psc = extractValueFromBits(
      RCU.CFG0.load(), CFG0_bits::APB1PSC_mask, CFG0_shift::APB1PSC);
  if (psc < 0b100u) {
    return 0;
  }
  return ((psc & 0b11u) + 1);
}

unsigned RcuGd32::apb2Prescaler() const {
  auto psc = extractValueFromBits(
      RCU.CFG0.load(), CFG0_bits::APB2PSC_mask, CFG0_shift::APB2PSC);
  if (psc < 0b100u) {
    return 0;
  }
  return ((psc & 0b11u) + 1);
}

unsigned RcuGd32::ahbPrescaler() const {
  auto psc = extractValueFromBits(
      RCU.CFG0.load(), CFG0_bits::AHBPSC_mask, CFG0_shift::AHBPSC);
  if (psc < 0b1000u) {
    return 0;
  }
  return ((psc & 0b111u) + 1);
}

void RcuGd32::enableHxtal() {
  using CTL_bits = mmio::RCU_regs::CTL_bits;
  RCU.CTL |= CTL_bits::HXTALEN;
  while (!RCU.CTL.any(CTL_bits::HXTALSTB)) {
    // Wait for the oscillator to stabilize
  }
}
void RcuGd32::failsafeConfig() {
  // Back down to IRC8M while messing with the clocks
  RCU.CFG0.store({});
  while ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) != Irc8MConfig::scss) {
    // wait for hardware to confirm clock source change
  }
}

void RcuGd32::setConfig(const RcuGd32::Irc8MConfig &config) {
  arch::CriticalSection cs{};
  failsafeConfig();
  RCU.CFG0.store(config.bits());
  while ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) != Irc8MConfig::scss) {
    // wait for hardware to confirm clock source change
  }
}

void RcuGd32::setConfig(const RcuGd32::HxtalConfig &config) {
  arch::CriticalSection cs{};
  failsafeConfig();
  // Enable HXTAL oscillator
  enableHxtal();
  RCU.CFG0.store(config.bits());
  while ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) != HxtalConfig::scss) {
    // wait for hardware to confirm clock source change
  }
}

void RcuGd32::setConfig(const RcuGd32::PllConfig &config) {
  arch::CriticalSection cs{};
  if (config.pll_factor.denominator == 0 ||
      16 < config.pll_factor.denominator) {
    Logger::error("Invalid PLL divider %u\n", config.pll_factor.denominator);
    panic();
  }
  if (config.pll_factor.numerator < 2 || 32 < config.pll_factor.numerator ||
      config.pll_factor.numerator == 15) {
    Logger::error("Invalid PLL multiplier %u\n", config.pll_factor.numerator);
    panic();
  }
  failsafeConfig();
  // Enable HXTAL oscillator
  enableHxtal();
  // Disable PLL in case it was enabled before
  RCU.CTL &= ~CTL_bits::PLLEN;
  auto cfg1 = RCU.CFG1.load();
  // Set prescaler divider for PLL input clock
  cfg1 &= ~(CFG1_bits::PREDV0_mask | CFG1_bits::PREDV0SEL);
  cfg1 |= maskedBitsFromValue(config.pll_factor.denominator - 1,
                              CFG1_bits::PREDV0_mask,
                              CFG1_shift::PREDV0);
  RCU.CFG1.store(cfg1);
  // Set PLL multiplier
  auto cfg0 = RCU.CFG0.load();
  cfg0 &= ~(CFG0_bits::PLLMF_4 | CFG0_bits::PLLMF_3_0_mask | CFG0_bits::PLLSEL);
  if (config.pll_factor.numerator > 16) {
    cfg0 |= CFG0_bits::PLLMF_4 |
            maskedBitsFromValue(config.pll_factor.numerator - 17,
                                CFG0_bits::PLLMF_3_0_mask,
                                CFG0_shift::PLLMF_3_0);
  } else if (config.pll_factor.numerator <= 14) {
    cfg0 |= maskedBitsFromValue(config.pll_factor.numerator - 2,
                                CFG0_bits::PLLMF_3_0_mask,
                                CFG0_shift::PLLMF_3_0);
  } else {
    // x 16
    cfg0 |= maskedBitsFromValue(
        0b1111u, CFG0_bits::PLLMF_3_0_mask, CFG0_shift::PLLMF_3_0);
  }
  // Select HXTAL as PLL input clock
  cfg0 |= CFG0_bits::PLLSEL;
  RCU.CFG0.store(cfg0);
  // Turn on PLL
  RCU.CTL |= CTL_bits::PLLEN;
  while (!RCU.CTL.any(CTL_bits::PLLSTB)) {
    // Wait until PLL output is stable
  }
  cfg0 |= config.bits();
  RCU.CFG0.store(cfg0);
  while ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) != PllConfig::scss) {
    // wait for hardware to confirm clock source change
  }
}

constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::ahbBits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::AHBPSC);
  switch (prescaler) {
    case 1:
      return CFG0{};
    case 2:
      return CFG0{0b1000u << shift};
    case 4:
      return CFG0{0b1001u << shift};
    case 8:
      return CFG0{0b1010u << shift};
    case 16:
      return CFG0{0b1011u << shift};
    case 64:
      return CFG0{0b1100u << shift};
    case 128:
      return CFG0{0b1101u << shift};
    case 256:
      return CFG0{0b1110u << shift};
    case 512:
      return CFG0{0b1111u << shift};
    default:
      return std::nullopt;
  }
}
constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::apb1Bits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::APB1PSC);
  switch (prescaler) {
    case 1:
      return CFG0{};
    case 2:
      return CFG0{0b100u << shift};
    case 4:
      return CFG0{0b101u << shift};
    case 8:
      return CFG0{0b110u << shift};
    case 16:
      return CFG0{0b111u << shift};
    default:
      return std::nullopt;
  }
}
constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::apb2Bits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::APB2PSC);
  switch (prescaler) {
    case 1:
      return CFG0{};
    case 2:
      return CFG0{0b100u << shift};
    case 4:
      return CFG0{0b101u << shift};
    case 8:
      return CFG0{0b110u << shift};
    case 16:
      return CFG0{0b111u << shift};
    default:
      return std::nullopt;
  }
}
constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::adcBits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::ADCPSC_1_0);
  switch (prescaler) {
    case 2:
      return CFG0{};
    case 4:
      return CFG0{0b01u << shift};
    case 6:
      return CFG0{0b10u << shift};
    case 8:
      return CFG0{0b11u << shift};
    case 12:
      return CFG0::ADCPSC_2 | CFG0{0b01u << shift};
    case 16:
      return CFG0::ADCPSC_2 | CFG0{0b11u << shift};
    default:
      return std::nullopt;
  }
}
constexpr RcuGd32::CFG0_bits RcuGd32::PrescalerConfig::bits() const {
  auto ahb_bits = ahbBits(ahb);
  CFG0_bits cfg0{};
  if (!ahb_bits.has_value()) {
    Logger::error << "Invalid AHB prescaler setting " << ahb;
    panic();
  }
  cfg0 |= *ahb_bits;
  auto apb1_bits = apb1Bits(apb1);
  if (!apb1_bits.has_value()) {
    Logger::error("Invalid APB1 prescaler setting %u\n", apb1);
    panic();
  }
  cfg0 |= *apb1_bits;
  auto apb2_bits = apb2Bits(apb2);
  if (!apb2_bits.has_value()) {
    Logger::error("Invalid APB2 prescaler setting %u\n", apb2);
    panic();
  }
  cfg0 |= *apb2_bits;
  auto adc_bits = adcBits(adc);
  if (!adc_bits.has_value()) {
    Logger::error("Invalid ADC prescaler setting %u\n", adc);
    panic();
  }
  cfg0 |= *adc_bits;
  return cfg0;
}

constexpr CFG0_bits RcuGd32::Irc8MConfig::bits() const {
  return prescaler.bits();
}
constexpr CFG0_bits RcuGd32::HxtalConfig::bits() const {
  return prescaler.bits() |
         maskedBitsFromValue(scs, CFG0_bits::SCS_mask, CFG0_shift::SCS);
}

constexpr CFG0_bits RcuGd32::PllConfig::bits() const {
  return prescaler.bits() |
         maskedBitsFromValue(scs, CFG0_bits::SCS_mask, CFG0_shift::SCS);
}
}  // namespace deri::dev::clock
