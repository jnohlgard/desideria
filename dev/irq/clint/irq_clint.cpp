/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/irq_clint.hpp"

#include "deri/irq.hpp"

#include "riscv/csr/encoding.h"

#include <cstdint>

namespace deri::dev::irq {

void IrqClint::setVectorTable(isr_func *vector_table) {
  write_csr(mtvec, reinterpret_cast<uintptr_t>(vector_table) | 1u);
}
void IrqClint::enable(IrqClint::IRQ irq) { set_csr(mie, irq); }
void IrqClint::disable(IrqClint::IRQ irq) { clear_csr(mie, irq); }
bool IrqClint::isInIrq() {
  auto pending = read_csr(mip);
  auto mstatus = read_csr(mstatus);
  return mstatus & MSTATUS_MPIE && pending;
}
}  // namespace deri::dev::irq
