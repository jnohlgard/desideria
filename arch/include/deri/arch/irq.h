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
class ScopedCriticalSection {
public:
  __attribute__((always_inline)) inline ScopedCriticalSection() : mask(irq_disable()) {}
  __attribute__((always_inline)) inline ~ScopedCriticalSection() { irq_restore(mask); }
  ScopedCriticalSection(const ScopedCriticalSection &) = delete;
  ScopedCriticalSection& operator=(const ScopedCriticalSection &) = delete;

private:
  const unsigned long mask;
};

#endif // __cplusplus

#endif // DERI_ARCH_IRQ_H_
