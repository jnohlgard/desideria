/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/irq.hpp"
#include "deri/log.hpp"
#include "deri/mmio/bits/PRCI_bits.hpp"
#include "deri/panic.hpp"

#include <optional>

namespace deri::log {
struct PrciSifive;
}

namespace deri::dev::clock {

class PrciSifive {
  using Logger = log::Logger<log::PrciSifive>;

 public:
  /// User-friendly configuration for the prescaler settings

  struct HfroscConfig {
    using hfrosccfg_bits = mmio::PRCI_regs::hfrosccfg_bits;
    struct HfroscDivider {
      [[nodiscard]] constexpr hfrosccfg_bits hfrosccfg() const;
      // 1 <= divider value <= 64
      unsigned div{5};
      // 1 <= trim value <= 32
      unsigned trim{17};
    };
    constexpr HfroscConfig(HfroscDivider divider)
        : hfrosccfg{divider.hfrosccfg()} {}
    hfrosccfg_bits hfrosccfg;
  };

  struct HfxoscConfig {
    // HFXOSC without PLL does not have any software configuration knobs
  };

  struct PllConfig {
    using pllcfg_bits = mmio::PRCI_regs::pllcfg_bits;
    using plloutdiv_bits = mmio::PRCI_regs::plloutdiv_bits;
    struct PllFactors {
      // FE310-G002 user manual, 6.5 Internal High-Frequency PLL (HFPLL)
      // Input (from HFXOSC/HFROSC) frequency requirement: 6-48 MHz
      unsigned div_R{1};  // ∈ [1, 2, 3, 4]
      // After dividing by R, allowed frequency range: 6-12 MHz
      unsigned mult_F{2};  // ∈ [2, 4, 6, 8, ..., 128]
      // After multiplying by F, allowed frequency range: 384-768 MHz
      unsigned div_Q{2};  // ∈ [2, 4, 8]
      // After dividing by Q, allowed frequency range: 48-384 MHz
      unsigned div_final{1};  // ∈ [1, 2, 4, 6, 8, ..., 128]
      [[nodiscard]] constexpr pllcfg_bits pllcfg() const;
      [[nodiscard]] constexpr plloutdiv_bits plloutdiv() const;
    };
    constexpr PllConfig(PllFactors factors)
        : pllcfg{factors.pllcfg()}, plloutdiv{factors.plloutdiv()} {}

    pllcfg_bits pllcfg;
    plloutdiv_bits plloutdiv;
  };

  void failsafeConfig();
  void setConfig(const HfxoscConfig &config);
  void setConfig(const HfroscConfig &config);
  void setConfig(const PllConfig &config);

  /**
   * Get the frequency of the coreclk clock by querying the hardware.
   *
   * @return coreclk frequency
   */
  [[nodiscard]] uint32_t coreFreq() const;

  /**
   * Get the frequency of the tlclk clock by querying the hardware.
   *
   * @return tlclk frequency
   */
  [[nodiscard]] uint32_t tlFreq() const {
    // tlclk is the same as coreclk on FE310
    return coreFreq();
  }

 private:
  [[nodiscard]] uint32_t pllFreq() const;
  [[nodiscard]] uint32_t hfroscFreq() const;

  mmio::PRCI_regs PRCI;
};

constexpr PrciSifive::PllConfig::pllcfg_bits
clock::PrciSifive::PllConfig::PllFactors::pllcfg() const {
  using pllcfg_shift = mmio::PRCI_regs::pllcfg_shift;
  auto pll_R = div_R - 1;
  if (pll_R > 3u) {
    // TODO: Compile time checking of invalid inputs.
    pll_R = 3u;
  }
  auto pll_F = (mult_F >> 1) - 1;
  if (pll_F > 0x3fu) {
    // TODO: Compile time checking of invalid inputs.
    pll_F = 0x3fu;
  }
  unsigned pll_Q;
  switch (div_Q) {
    case 2:
      pll_Q = 0b01u;
      break;
    case 4:
      pll_Q = 0b10u;
      break;
    case 8:
    default:
      // TODO: Compile time checking of invalid inputs.
      pll_Q = 0b11u;
      break;
  }
  return maskedBitsFromValue(
             pll_R, pllcfg_bits::pllr_mask, pllcfg_shift::pllr) |
         maskedBitsFromValue(
             pll_F, pllcfg_bits::pllf_mask, pllcfg_shift::pllf) |
         maskedBitsFromValue(pll_Q, pllcfg_bits::pllq_mask, pllcfg_shift::pllq);
}

constexpr PrciSifive::PllConfig::plloutdiv_bits
PrciSifive::PllConfig::PllFactors::plloutdiv() const {
  using plloutdiv_shift = mmio::PRCI_regs::plloutdiv_shift;
  if (div_final == 1) {
    return plloutdiv_bits::divby1;
  }
  auto pll_outdiv = (div_final >> 1) - 1;
  if (pll_outdiv > 63u) {
    pll_outdiv = 63u;
  }
  return maskedBitsFromValue(
      pll_outdiv, plloutdiv_bits::div_mask, plloutdiv_shift::div);
}

constexpr PrciSifive::HfroscConfig::hfrosccfg_bits
PrciSifive::HfroscConfig::HfroscDivider::hfrosccfg() const {
  using hfrosccfg_shift = mmio::PRCI_regs::hfrosccfg_shift;
  auto hfrosc_div = div - 1;
  auto hfrosc_trim = trim;
  if (hfrosc_trim > 31u) {
    // TODO: Compile time checking of invalid inputs.
    hfrosc_trim = 31u;
  }
  if (hfrosc_div > 63u) {
    // TODO: Compile time checking of invalid inputs.
    hfrosc_div = 63u;
  }

  return maskedBitsFromValue(
             hfrosc_div, hfrosccfg_bits::div_mask, hfrosccfg_shift::div) |
         maskedBitsFromValue(
             hfrosc_trim, hfrosccfg_bits::trim_mask, hfrosccfg_shift::trim);
}

}  // namespace deri::dev::clock
