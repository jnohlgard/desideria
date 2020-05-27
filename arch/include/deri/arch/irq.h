/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_ARCH_IRQ_H_
#define DERI_ARCH_IRQ_H_

#include "deri/arch/impl/irq_impl.h"

#ifdef __cplusplus

/**
 * Scoped IRQ disabling lock
 */
class InterruptGuard {
public:
  __attribute__((always_inline)) inline InterruptGuard() : mask(irq_disable()) {}
  __attribute__((always_inline)) inline ~InterruptGuard() { irq_restore(mask); }
  InterruptGuard(const InterruptGuard &) = delete;
  InterruptGuard(InterruptGuard &&) = delete;
  InterruptGuard &operator=(const InterruptGuard &) = delete;
  InterruptGuard &operator=(InterruptGuard &&) = delete;

private:
  const unsigned long mask;
};

#endif // __cplusplus

#endif // DERI_ARCH_IRQ_H_
