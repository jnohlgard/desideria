/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_ARCH_IRQ_H_
#define DERI_ARCH_IRQ_H_

#include "deri/arch/impl/irq_impl.h"

#ifdef __cplusplus

namespace deri::arch {

/**
 * Scoped IRQ disabling lock
 */
class InterruptGuard {
public:
  /**
   * Enter critical section
   *
   * This will disable interrupts globally until the object is destructed
   */
  InterruptGuard();
  /**
   * Leave critical section
   */
  ~InterruptGuard();

  // No copying
  InterruptGuard(const InterruptGuard &) = delete;
  InterruptGuard &operator=(const InterruptGuard &) = delete;

  // Moving would be OK but right now we do not have a use case
  InterruptGuard(InterruptGuard &&) = delete;
  InterruptGuard &operator=(InterruptGuard &&) = delete;

private:
  const unsigned long mask;
};

__attribute__((always_inline)) inline InterruptGuard::InterruptGuard() : mask(irq_disable()) {}
__attribute__((always_inline)) inline InterruptGuard::~InterruptGuard() { irq_restore(mask); }
} // namespace deri::arch

#endif // __cplusplus

#endif // DERI_ARCH_IRQ_H_
