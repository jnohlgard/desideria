/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/arch/irq.hpp"

#include "riscv/csr/encoding.h"

namespace deri::arch {
void init() {
  // Clear all IRQ enable flags
  (void)irqDisable();
  clear_csr(mie, 0b1111'1111'1111u);
}

}  // namespace deri::arch
