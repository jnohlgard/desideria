/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "riscv/csr/encoding.h"
#include "deri/arch/irq.hpp"

namespace deri::arch {
void init() {
  // Clear all IRQ enable flags
  irq_disable();
  clear_csr(mie, 0b1111'1111'1111u);
}
}  // namespace deri::arch::riscv
