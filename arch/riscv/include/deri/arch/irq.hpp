/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
#pragma once

#include "riscv/csr/encoding.h"

extern "C" {
// trap.S
void deri_exception_handler();
}

namespace deri::arch {

/// IRQ handler function signature
using isr_func = void();

[[gnu::always_inline]] [[nodiscard]] inline unsigned long irq_disable() {
  asm volatile("" ::: "memory");
  auto previous = clear_csr(mstatus, MSTATUS_MIE);
  asm volatile("" ::: "memory");
  return previous & MSTATUS_MIE;
}

[[gnu::always_inline]] inline void irq_restore(unsigned long saved) {
  asm volatile("" ::: "memory");
  set_csr(mstatus, saved & MSTATUS_MIE);
  asm volatile("" ::: "memory");
}

[[gnu::always_inline]] inline void irq_enable() {
  asm volatile("" ::: "memory");
  set_csr(mstatus, MSTATUS_MIE);
  asm volatile("" ::: "memory");
}

[[gnu::always_inline]] [[nodiscard]] inline unsigned long is_irq_enabled() {
  asm volatile("" ::: "memory");
  auto mstatus = read_csr(mstatus);
  asm volatile("" ::: "memory");
  return mstatus & MSTATUS_MIE;
}

[[gnu::always_inline]] inline void wait_for_interrupt() {
  asm volatile("wfi" ::: "memory");
}

}  // namespace deri::arch
