/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
#ifndef DERI_ARCH_IMPL_IRQ_H_
#define DERI_ARCH_IMPL_IRQ_H_

#include "deri/arch/asm.h"

#include <atomic>

namespace deri::arch::native::impl {
inline atomic_flag isr_lock = ATOMIC_FLAG_INIT;
}

[[gnu::always_inline]] static inline unsigned long irq_disable(void) {
  using namespace deri::arch::native::impl;
  auto previous = isr_lock.test_and_set();
  return previous;
}

[[gnu::always_inline]] static inline void irq_restore(unsigned long saved) {
  using namespace deri::arch::native::impl;
  if (saved) {
    isr_lock.clear();
  }
}

#endif // DESIDERIA_ARCH_RISCV_IRQ_H_
