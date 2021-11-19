/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/clock_gd32.h"

namespace deri::dev::clock {

uint32_t RcuGd32::systemFrequency() const {
  using CFG0_bits = mmio::RCU_regs::CFG0_bits;
  using CFG0_shift = mmio::RCU_regs::CFG0_shift;

  switch ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) >> CFG0_shift::SCSS) {
    case 0b00:
      // IRC8M is the current clock source
      return 8'000'000u;
    case 0b01:
      // TODO HXTAL is the current clock source
      return 0;
    case 0b10:
      // TODO PLL is the current clock source
      return 0;
  }
  return 0;
}
}  // namespace deri::dev::clock
