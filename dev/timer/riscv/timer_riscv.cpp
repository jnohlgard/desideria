/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/timer_riscv.hpp"

#include "deri/soc/irq_dev.hpp"

#include "riscv/csr/encoding.h"

namespace deri::dev::timer {

void TimerRiscv::disableInterrupt(TimerRiscv::Channel) {
  Logger::debug("TimerRiscv::disableInterrupt\n");
  soc::Irq::disable(soc::mtime_irq);
}
void TimerRiscv::enableInterrupt(TimerRiscv::Channel) {
  Logger::debug("TimerRiscv::enableInterrupt\n");
  soc::Irq::enable(soc::mtime_irq);
}
TimerRiscv::Count TimerRiscv::read() const {
  while (true) {
    auto mtimeh = mmio::mtime.hi.load();
    auto mtime = mmio::mtime.lo.load();
    asm volatile("" ::: "memory");
    auto mtimeh2 = mmio::mtime.hi.load();
    if (mtimeh == mtimeh2) {
      auto count = static_cast<Count>((static_cast<uint64_t>(mtimeh) << 32u) |
                                      static_cast<uint32_t>(mtime));
      Logger::debug("mtime=%lld\n", static_cast<int64_t>(count));
      return count;
    }
  }
}
void TimerRiscv::setCompare(TimerRiscv::Channel, TimerRiscv::Count target) {
  Logger::debug("mtimecmp=%lld\n", static_cast<int64_t>(target));
  mmio::mtimecmp.lo.store(mmio::MTIME_bits{~0u});
  mmio::mtimecmp.hi.store(mmio::MTIME_bits{
      static_cast<uint32_t>(static_cast<uint64_t>(target) >> 32)});
  mmio::mtimecmp.lo.store(mmio::MTIME_bits{static_cast<uint32_t>(target)});
}
}  // namespace deri::dev::timer
