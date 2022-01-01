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
  void init(isr_func *default_handler);
  void enable(IRQ irq);
  void disable(IRQ irq);

  /**
   * Set the interrupt vector table address
   *
   * @note @p vector_table must be aligned to 64 bytes or even more, see chip
   * docs.
   *
   * @param vector_table address of the table
   */
  static void setVectorTable(isr_func *const *vector_table);

 private:
  mmio::CLIC_regs CLIC;
};

static_assert(sizeof(IrqClic) == sizeof(mmio::CLIC_regs));
}  // namespace deri::dev::irq
