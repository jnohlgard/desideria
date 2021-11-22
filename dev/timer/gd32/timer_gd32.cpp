/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/timer_gd32.h"

#include "deri/mmio/bits/TIMER_bits.hpp"
#include "deri/soc/clock_dev.h"
#include "deri/soc/irq_dev.h"

namespace deri::dev::timer {
using SMCFG_bits = mmio::TIMER_regs::SMCFG_bits;
using SMCFG_shift = mmio::TIMER_regs::SMCFG_shift;

namespace {
constexpr SMCFG_bits applyTriggerSource(SMCFG_bits smcfg,
                                        unsigned trigger_number) {
  smcfg &= ~(SMCFG_bits::TRGS_mask);
  smcfg |= static_cast<SMCFG_bits>(trigger_number
                                   << static_cast<unsigned>(SMCFG_shift::TRGS));
  smcfg |= SMCFG_bits::SMC_ExternalClock0;
  return smcfg;
}
}  // namespace

void TimerGd32::init() {
  soc::rcu.enableModules(clock::RcuGd32::APB2EN_bits::TIMER0EN);
  TIMER.CTL0.store(static_cast<mmio::TIMER_regs::CTL0_bits>(0));
  soc::clic.enable_irq(mmio::IRQ::TIMER0_Channel);
  soc::clic.enable_irq(mmio::IRQ::TIMER0_UP);
}

void TimerGd32::setSource(TimerGd32::ClockSource source) {
  auto smcfg = TIMER.SMCFG.load();
  smcfg &= ~(SMCFG_bits::SMC_mask);
  switch (source) {
    case ClockSource::CK_TIMER:
      break;
    case ClockSource::ITI0:
      smcfg = applyTriggerSource(smcfg, 0b000u);
      break;
    case ClockSource::ITI1:
      smcfg = applyTriggerSource(smcfg, 0b001u);
      break;
    case ClockSource::ITI2:
      smcfg = applyTriggerSource(smcfg, 0b010u);
      break;
    case ClockSource::ITI3:
      smcfg = applyTriggerSource(smcfg, 0b011u);
      break;
    case ClockSource::EXTERNAL_TRIGGER:
      smcfg = applyTriggerSource(smcfg, 0b111u);
      break;
  }
  TIMER.SMCFG.store(smcfg);
}

}  // namespace deri::dev::timer
