/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
#pragma once

#include "riscv/csr/encoding.h"

namespace deri::arch {

/// IRQ handler function signature
using isr_func = void();

static inline unsigned long irq_disable() {
  unsigned long previous = __extension__ clear_csr(mstatus, MSTATUS_MIE);
  return previous & MSTATUS_MIE;
}

static inline void irq_restore(
    unsigned long saved) {
  __extension__ set_csr(mstatus, saved & MSTATUS_MIE);
}

static inline void irq_enable() {
  __extension__ set_csr(mstatus, MSTATUS_MIE);
}

}  // namespace deri::arch
