/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/timer.hpp"
#include "deri/dev/timer_gd32.hpp"
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"

#include <array>

namespace deri::soc {
using TimerPeriph = dev::timer::TimerGd32;
extern TimerPeriph timer0;
extern TimerPeriph timer1;
extern TimerPeriph timer2;
extern TimerPeriph timer3;
extern TimerPeriph timer4;
extern TimerPeriph timer5;
extern TimerPeriph timer6;

enum class TimerModule {
  TIMER0,
  TIMER1,
  TIMER2,
  TIMER3,
  TIMER4,
  TIMER5,
  TIMER6,
};

inline void enableModule(TimerModule module) {
  using APB2EN_bits = dev::clock::RcuGd32::APB2EN_bits;
  using APB1EN_bits = dev::clock::RcuGd32::APB1EN_bits;
  switch (module) {
    case TimerModule::TIMER0:
      rcu.enableModules(APB2EN_bits::TIMER0EN);
      break;
    case TimerModule::TIMER1:
      rcu.enableModules(APB1EN_bits::TIMER1EN);
      break;
    case TimerModule::TIMER2:
      rcu.enableModules(APB1EN_bits::TIMER2EN);
      break;
    case TimerModule::TIMER3:
      rcu.enableModules(APB1EN_bits::TIMER3EN);
      break;
    case TimerModule::TIMER4:
      rcu.enableModules(APB1EN_bits::TIMER4EN);
      break;
    case TimerModule::TIMER5:
      rcu.enableModules(APB1EN_bits::TIMER5EN);
      break;
    case TimerModule::TIMER6:
      rcu.enableModules(APB1EN_bits::TIMER6EN);
      break;
  }
}

inline void enableIrq(TimerModule module) {
  using IRQ = mmio::IRQ;
  switch (module) {
    case TimerModule::TIMER0:
      clic.enable_irq(IRQ::TIMER0_UP);
      clic.enable_irq(IRQ::TIMER0_Channel);
      break;
    case TimerModule::TIMER1:
      clic.enable_irq(IRQ::TIMER1);
      break;
    case TimerModule::TIMER2:
      clic.enable_irq(IRQ::TIMER2);
      break;
    case TimerModule::TIMER3:
      clic.enable_irq(IRQ::TIMER3);
      break;
    case TimerModule::TIMER4:
      clic.enable_irq(IRQ::TIMER4);
      break;
    case TimerModule::TIMER5:
      clic.enable_irq(IRQ::TIMER5);
      break;
    case TimerModule::TIMER6:
      clic.enable_irq(IRQ::TIMER6);
      break;
  }
}

inline uint32_t moduleFrequency(TimerModule module) {
  return rcu.timerFreq(static_cast<unsigned>(module));
}

using TimerDriver = dev::timer::TimerDriver<TimerPeriph>;

struct TimerConfig {
  [[nodiscard]] TimerDriver &init() const;

  [[nodiscard]] uint32_t module_clock() const {
    return soc::rcu.timerFreq(static_cast<unsigned>(module_id));
  }

  [[nodiscard]] auto computePrescaler(uint32_t tick_rate) const {
    return TimerPeriph::computePrescaler(module_clock(), tick_rate);
  }

  TimerModule module_id;
  TimerPeriph &dev;
  TimerPeriph::ClockSource clock_source{TimerPeriph::ClockSource::CK_TIMER};
};

inline constexpr std::array timer_config = {
    TimerConfig{TimerModule::TIMER0, timer0},
    TimerConfig{TimerModule::TIMER1, timer1},
    TimerConfig{TimerModule::TIMER2, timer2},
    TimerConfig{TimerModule::TIMER3, timer3},
    TimerConfig{TimerModule::TIMER4, timer4},
    TimerConfig{TimerModule::TIMER5, timer5},
    TimerConfig{TimerModule::TIMER6, timer6},
};

inline std::array<TimerDriver, timer_config.size()> timers;

inline TimerDriver &TimerConfig::init() const {
  enableModule(module_id);
  enableIrq(module_id);
  auto &driver = timers[static_cast<unsigned>(module_id)];
  driver = TimerDriver{dev};
  driver.init();
  return driver;
}

}  // namespace deri::soc
