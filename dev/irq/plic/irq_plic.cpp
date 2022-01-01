/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/irq_plic.hpp"

#include "deri/irq.hpp"
#include "deri/log.hpp"
#include "deri/panic.hpp"
#include "deri/soc/irq_dev.hpp"
#include "deri/soc/vectors.hpp"

#include "riscv/csr/encoding.h"

#include <algorithm>

namespace deri::log {
struct IrqPlic;
}

namespace deri::dev::irq {
using Logger = log::Logger<log::IrqPlic>;

void irq::IrqPlic::init() {
  // Disable all PLIC interrupts
  for (auto &enable : PLIC.enable) {
    enable.store({});
  }
  // Enable the external interrupt source in CLINT
  soc::Irq::enable(soc::Irq::external_irq);
}

void IrqPlic::enable(IrqPlic::IRQ irq) {
  auto irq_num = static_cast<std::underlying_type_t<IRQ>>(irq);
  auto reg_num = irq_num >> 5;
  auto bit_num = irq_num & ((1u << 5) - 1);
  PLIC.enable[reg_num] |= mmio::PLIC_regs::enable_bits{1u << bit_num};
}

void IrqPlic::disable(IrqPlic::IRQ irq) {
  auto irq_num = static_cast<std::underlying_type_t<IRQ>>(irq);
  auto reg_num = irq_num >> 5;
  auto bit_num = irq_num & ((1u << 5) - 1);
  PLIC.enable[reg_num] &= mmio::PLIC_regs::enable_bits{~(1u << bit_num)};
}

IrqPlic::Claim::Claim() : bits{mmio::PLIC.PLIC.claim.load()} {
  ++ongoing_claims;
}
IrqPlic::Claim::~Claim() {
  mmio::PLIC.PLIC.claim.store(bits);
  --ongoing_claims;
}
uint32_t IrqPlic::Claim::num() const { return static_cast<uint32_t>(bits); }

[[gnu::interrupt]] void IrqPlic::external_handler() {
  Claim claim{};
  handleInterrupt(IRQ(claim.num()));
}
void IrqPlic::setVectorTable(isr_func *const *new_vector_table) {
  vector_table = new_vector_table;
}
void IrqPlic::handleInterrupt(IrqPlic::IRQ irq) {
  if (vector_table == nullptr) {
    panic();
  }
  auto *handler = vector_table[static_cast<unsigned>(irq)];
  if (handler == plic_unhandled) {
    Logger::critical("Unhandled PLIC interrupt %u\n",
                     static_cast<unsigned>(irq));
    panic();
  }
  handler();
}

}  // namespace deri::dev::irq
