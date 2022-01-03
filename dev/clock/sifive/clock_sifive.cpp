/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/clock_sifive.hpp"

#include "deri/bsp/devices.hpp"
#include "deri/soc/clock_dev.hpp"

namespace deri::dev::clock {

using pllcfg_bits = mmio::PRCI_regs::pllcfg_bits;
using hfxosccfg_bits = mmio::PRCI_regs::hfxosccfg_bits;

void PrciSifive::failsafeConfig() {}

void PrciSifive::setConfig(const PrciSifive::HfxoscConfig &) {
  arch::CriticalSection cs{};
  PRCI.hfxosccfg.store(hfxosccfg_bits::enable);
  while (!PRCI.hfxosccfg.any(hfxosccfg_bits::ready)) {
    // Spin until oscillator is stable
  }
  // Bypass the PLL to forward hfxosc directly to hfclk
  PRCI.pllcfg |= pllcfg_bits::bypass;
}

void PrciSifive::setConfig(const PrciSifive::HfroscConfig &config) {
  arch::CriticalSection cs{};
  PRCI.hfrosccfg.store(mmio::PRCI_regs::hfrosccfg_bits::enable |
                       config.hfrosccfg);
  while (!PRCI.hfrosccfg.any(mmio::PRCI_regs::hfrosccfg_bits::ready)) {
    // Spin until oscillator is stable
  }
  // Switch clock source
  PRCI.pllcfg &= ~(pllcfg_bits::bypass | pllcfg_bits::sel);
}

void PrciSifive::setConfig(const PrciSifive::PllConfig &config) {
  arch::CriticalSection cs{};
  // Switch to HFXOSC clock while messing with the settings
  setConfig(HfxoscConfig{});
  // Use HFXOSC as reference clock for the PLL, set dividers and multiplier
  PRCI.pllcfg.store(pllcfg_bits::refsel | config.pllcfg);
  PRCI.plloutdiv.store(config.plloutdiv);
  while (!PRCI.pllcfg.any(mmio::PRCI_regs::pllcfg_bits::lock)) {
    // Spin until PLL is stable
  }
  // Switch core clock source
  PRCI.pllcfg |= pllcfg_bits::sel;
}

uint32_t PrciSifive::coreFreq() const {
  auto pllcfg = PRCI.pllcfg.load();
  if (!!(pllcfg & mmio::PRCI_regs::pllcfg_bits::bypass)) {
    // Bypass mode
    return bsp::hfxosc_freq;
  } else if (!!(pllcfg & mmio::PRCI_regs::pllcfg_bits::sel)) {
    // PLL selected
    return pllFreq();
  } else {
    // HFROSC selected
    return hfroscFreq();
  }
}

uint32_t PrciSifive::hfroscFreq() const {
  // The HFROSC clock frequency is very inexact, and we don't account for the
  // trim value here.
  using hfrosccfg_bits = mmio::PRCI_regs::hfrosccfg_bits;
  using hfrosccfg_shift = mmio::PRCI_regs::hfrosccfg_shift;
  auto hfrosccfg = PRCI.hfrosccfg.load();
  auto div =
      1u + extractValueFromBits(
               hfrosccfg, hfrosccfg_bits::div_mask, hfrosccfg_shift::div);
  return soc::Clock::hfrosc_center_freq / div;
}

uint32_t PrciSifive::pllFreq() const {
  using pllcfg_bits = mmio::PRCI_regs::pllcfg_bits;
  using pllcfg_shift = mmio::PRCI_regs::pllcfg_shift;
  using plloutdiv_bits = mmio::PRCI_regs::plloutdiv_bits;
  using plloutdiv_shift = mmio::PRCI_regs::plloutdiv_shift;
  auto pllcfg = PRCI.pllcfg.load();
  auto plloutdiv = PRCI.plloutdiv.load();
  // R = N + 1
  auto div_R = 1u + extractValueFromBits(
                        pllcfg, pllcfg_bits::pllr_mask, pllcfg_shift::pllr);
  // F = 2 * (N + 1)
  auto mult_F = (1u + extractValueFromBits(
                          pllcfg, pllcfg_bits::pllf_mask, pllcfg_shift::pllf))
                << 1u;
  // Q = 2**N
  auto div_Q = 1u << extractValueFromBits(
                   pllcfg, pllcfg_bits::pllq_mask, pllcfg_shift::pllq);
  // outdiv = 2 * (N + 1), except when divby1 is set.
  auto div_final = 1;
  if (!(plloutdiv & plloutdiv_bits::divby1)) {
    div_final = extractValueFromBits(
        plloutdiv, plloutdiv_bits::div_mask, plloutdiv_shift::div);
  }
  auto input_freq = bsp::hfxosc_freq;
  auto pll_freq = input_freq * mult_F;
  pll_freq /= div_R * div_Q * div_final;
  return pll_freq;
}
}  // namespace deri::dev::clock
