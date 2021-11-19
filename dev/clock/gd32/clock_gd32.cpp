/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/clock_gd32.h"
#include "deri/bsp/devices.h"

namespace deri::dev::clock {

uint32_t RcuGd32::sysFreq() const {
  using CFG0_bits = mmio::RCU_regs::CFG0_bits;
  using CFG0_shift = mmio::RCU_regs::CFG0_shift;

  switch ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) >> CFG0_shift::SCSS) {
    case 0b00:
      // IRC8M is the current clock source
      return 8'000'000u;
    case 0b01:
      // HXTAL is the current clock source
      return bsp::hxtal_freq;
    case 0b10:
      // TODO PLL is the current clock source
      return 0;
  }
  return 0;
}

uint32_t RcuGd32::ahbFreq() const {
  auto ck_sys = sysFreq();
  auto ahbpsc = (RCU.CFG0.load() & mmio::RCU_regs::CFG0_bits::AHBPSC_mask) >>
                mmio::RCU_regs::CFG0_shift::AHBPSC;
  if (ahbpsc < 0b1000u) {
    return ck_sys;
  }
  return ck_sys >> ((ahbpsc & 0b111u) + 1);
}

uint32_t RcuGd32::apb1Freq() const {
  auto ck_ahb = ahbFreq();
  auto apb1psc = (RCU.CFG0.load() & mmio::RCU_regs::CFG0_bits::APB1PSC_mask) >>
                 mmio::RCU_regs::CFG0_shift::APB1PSC;
  if (apb1psc < 0b100u) {
    return ck_ahb;
  }
  return ck_ahb >> ((apb1psc & 0b11u) + 1);
}

uint32_t RcuGd32::apb2Freq() const {
  auto ck_ahb = ahbFreq();
  auto apb2psc = (RCU.CFG0.load() & mmio::RCU_regs::CFG0_bits::APB2PSC_mask) >>
                 mmio::RCU_regs::CFG0_shift::APB2PSC;
  if (apb2psc < 0b100u) {
    return ck_ahb;
  }
  return ck_ahb >> ((apb2psc & 0b11u) + 1);
}

}  // namespace deri::dev::clock
