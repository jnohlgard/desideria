/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once
#include "deri/dev/irq_clint.hpp"
#include "deri/dev/irq_plic.hpp"
#include "deri/soc/irq_dev.hpp"

namespace deri::mmio {
extern dev::irq::IrqPlic PLIC;
}

namespace deri::irq {
class IrqPlatformPlicClint {
  using IrqPlic = dev::irq::IrqPlic;
  using IrqClint = dev::irq::IrqClint;

 public:
  using IRQ = IrqPlic::IRQ;

  static void enable(IrqPlic::IRQ plic_irq) { mmio::PLIC.enable(plic_irq); }

  static void disable(IrqPlic::IRQ plic_irq) { mmio::PLIC.disable(plic_irq); }

  static void enable(IrqClint::IRQ clint_irq) { IrqClint::enable(clint_irq); }
  static void disable(IrqClint::IRQ clint_irq) { IrqClint::disable(clint_irq); }

  static void setVectorTable(isr_func *const *table) {
    dev::irq::IrqPlic::setVectorTable(table);
  }

  [[gnu::always_inline]] [[nodiscard]] inline static bool isInIrq() noexcept {
    return IrqClint::isInIrq() || IrqPlic::isInIrq();
  }
};
}  // namespace deri::irq
