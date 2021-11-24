/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/irq_clic.hpp"

#include "deri/mmio/bits/CLIC_bits.hpp"

#include "riscv/csr/encoding.h"

namespace deri::dev::irq {

using CLICINT_regs = mmio::CLIC_regs::CLICINT_regs;

void IrqClic::enable_irq(IrqClic::IRQ irq) {
  using CLICINTIE_bits = CLICINT_regs::CLICINTIE_bits;
  using CLICINTATTR_bits = CLICINT_regs::CLICINTATTR_bits;

  auto &clicint = CLIC.clicint[static_cast<size_t>(irq)];
  // Hardware vectoring enabled
  clicint.clicintattr.store(CLICINTATTR_bits::SHV);
  clicint.clicintie.store(CLICINTIE_bits::IE);
}

void IrqClic::disable_irq(IrqClic::IRQ irq) {
  using CLICINTIE_bits = CLICINT_regs::CLICINTIE_bits;

  auto &clicint = CLIC.clicint[static_cast<size_t>(irq)];
  clicint.clicintie.store(static_cast<CLICINTIE_bits>(0));
}

void IrqClic::init(isr_func *default_handler) {
  using CLICCFG_bits = mmio::CLIC_regs::CLICCFG_bits;
  // Enable hardware vectoring
  CLIC.cliccfg.store(CLICCFG_bits::NVBITS);
  // Switch to CLIC mode
  write_csr(mtvec, reinterpret_cast<uintptr_t>(default_handler) | 0b000011u);
}

void IrqClic::setVectorTable(isr_func *const *vector_table) {
  write_csr(mtvt, vector_table);
}

}  // namespace deri::dev::irq
