/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "riscv/csr/encoding.h"
#include "deri/arch/irq.h"

namespace deri::arch::riscv {
void init() {
  // Clear all IRQ enable flags
  clear_csr(mie, 0b1111'1111'1111u);
  irq_disable();
}
}  // namespace deri::arch::riscv
