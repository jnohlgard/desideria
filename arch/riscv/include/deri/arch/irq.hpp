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

[[gnu::always_inline]] [[nodiscard]] inline unsigned long
irqDisable() noexcept {
  asm volatile("" ::: "memory");
  auto previous = clear_csr(mstatus, MSTATUS_MIE);
  asm volatile("" ::: "memory");
  return previous & MSTATUS_MIE;
}

[[gnu::always_inline]] inline void irqRestore(unsigned long saved) noexcept {
  asm volatile("" ::: "memory");
  set_csr(mstatus, saved & MSTATUS_MIE);
  asm volatile("" ::: "memory");
}

[[gnu::always_inline]] inline void irqEnable() noexcept {
  asm volatile("" ::: "memory");
  set_csr(mstatus, MSTATUS_MIE);
  asm volatile("" ::: "memory");
}

[[gnu::always_inline]] [[nodiscard]] inline unsigned long
isIrqEnabled() noexcept {
  asm volatile("" ::: "memory");
  auto mstatus = read_csr(mstatus);
  asm volatile("" ::: "memory");
  return mstatus & MSTATUS_MIE;
}

[[gnu::always_inline]] [[nodiscard]] inline unsigned long isInIrq() noexcept {
  asm volatile("" ::: "memory");
  // NB: mintstatus requires CLIC interrupt controller.
  auto mintstatus = read_csr(mintstatus);
  asm volatile("" ::: "memory");
  return mintstatus;
}

[[gnu::always_inline]] inline void waitForInterrupt() noexcept {
  asm volatile("wfi" ::: "memory");
}

}  // namespace deri::arch
