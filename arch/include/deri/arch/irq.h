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
  inline ScopedCriticalSection() : mask(irq_disable()) {}
  inline ~ScopedCriticalSection() { irq_restore(mask); }

private:
  unsigned long mask;
};

#endif // __cplusplus

#endif // DERI_ARCH_IRQ_H_
