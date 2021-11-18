/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/CLIC.hpp"
#include "deri/mmio/interrupts.hpp"

namespace deri::dev::irq {

class IrqClic {
 public:
  using IRQ = mmio::IRQ;
  using isr_func = void();
  void init();
  void enable_irq(IRQ irq);
  void disable_irq(IRQ irq);

  /**
   * Set the interrupt vector table address
   *
   * @note @p vector_table must be aligned to 64 bytes
   *
   * @param vector_table address of the table
   */
  void setVectorTable(isr_func *const *vector_table);

 private:
  mmio::CLIC_regs CLIC;
};

static_assert(sizeof(IrqClic) == sizeof(mmio::CLIC_regs));
}  // namespace deri::dev::irq
