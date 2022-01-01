/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/interrupts.hpp"

namespace deri::dev::irq {

class IrqClint {
 public:
  enum class IRQ {
    SOFTWARE = (1 << 3),   ///< Machine-level software interrupt
    TIMER = (1 << 7),      ///< Machine-level timer interrupt
    EXTERNAL = (1 << 11),  ///< Machine-level external interrupt
  };

  static void enable(IRQ);
  static void disable(IRQ);

  /**
   * Set the interrupt vector table address
   *
   * @note @p vector_table must be aligned to XLEN*4 (128 bytes for rv32)
   *
   * @param vector_table address of the table
   */
  static void setVectorTable(isr_func *vector_table);

  [[nodiscard]] static bool isInIrq();
};

}  // namespace deri::dev::irq
