/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/irq_clic.h"

#include "deri/mmio/bits/ECLIC_bits.hpp"
#include "riscv/csr/encoding.h"

namespace deri::dev::irq {
using CLICINT_regs = mmio::ECLIC_regs::CLICINT_regs;
void IrqClic::enable_irq(IrqClic::IRQ irq) {
  using CLICINTIE_bits = CLICINT_regs::CLICINTIE_bits;
  using CLICINTATTR_bits = CLICINT_regs::CLICINTATTR_bits;

  auto &clicint = CLIC.CLICINT[static_cast<size_t>(irq)];
  // Hardware vectoring enabled
  clicint.CLICINTATTR.store(CLICINTATTR_bits::SHV);
  clicint.CLICINTIE.store(CLICINTIE_bits::IE);
}

void IrqClic::disable_irq(IrqClic::IRQ irq) {
  using CLICINTIE_bits = CLICINT_regs::CLICINTIE_bits;

  auto &clicint = CLIC.CLICINT[static_cast<size_t>(irq)];
  clicint.CLICINTIE.store(static_cast<CLICINTIE_bits>(0));
}

void IrqClic::init() {
  using CLICCFG_bits = mmio::ECLIC_regs::CLICCFG_bits;
  // Enable hardware vectoring
  // FIXME: Missing enum for nvbits field
  CLIC.CLICCFG.store(static_cast<CLICCFG_bits>(1));
  // Switch to CLIC mode
  write_csr(mtvec, 0b000011u);
}
void IrqClic::setVectorTable(isr_func *const *vector_table) {
  write_csr(mtvt, vector_table);
}
}  // namespace deri::dev::irq
