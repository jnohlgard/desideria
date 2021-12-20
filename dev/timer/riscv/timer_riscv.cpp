/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/timer_riscv.hpp"

#include "deri/soc/irq_dev.hpp"

#include "riscv/csr/encoding.h"

namespace deri::dev::timer {

using IRQ = soc::Irq::IRQ;
void TimerRiscv::disableInterrupt(TimerRiscv::Channel) {
  soc::Irq::disable(IRQ::CLIC_INT_TMR);
}
void TimerRiscv::enableInterrupt(TimerRiscv::Channel) {
  soc::Irq::enable(IRQ::CLIC_INT_TMR);
}
}  // namespace deri::dev::timer
