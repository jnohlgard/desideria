/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */
#ifndef DESIDERIA_ARCH_RISCV_IRQ_H_
#define DESIDERIA_ARCH_RISCV_IRQ_H_

#include "riscv/asm.h"
#include "riscv/csr/encoding.h"

static inline unsigned long irq_disable(void) {
  unsigned long previous = clear_csr(mstatus, MSTATUS_MIE);
  return previous & MSTATUS_MIE;
}

static inline void irq_restore(unsigned long saved) {
  set_csr(mstatus, saved & MSTATUS_MIE);
}

#endif // DESIDERIA_ARCH_RISCV_IRQ_H_
