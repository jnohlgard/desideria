/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
#ifndef DERI_ARCH_IMPL_IRQ_H_
#define DERI_ARCH_IMPL_IRQ_H_

#include "deri/arch/asm.h"
#include "riscv/csr/encoding.h"

__attribute__((always_inline)) static inline unsigned long irq_disable(void) {
  unsigned long previous = __extension__ clear_csr(mstatus, MSTATUS_MIE);
  return previous & MSTATUS_MIE;
}

__attribute__((always_inline)) static inline void irq_restore(unsigned long saved) {
  __extension__ set_csr(mstatus, saved & MSTATUS_MIE);
}

#endif // DESIDERIA_ARCH_RISCV_IRQ_H_
