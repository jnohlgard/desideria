/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/irq_clic.hpp"
#include "deri/soc/irq_dev.hpp"

#include "riscv/csr/encoding.h"

namespace deri::mmio {
extern dev::irq::IrqClic CLIC;
}

namespace deri::irq {
class IrqPlatformClic {
 public:
  using IRQ = dev::irq::IrqClic::IRQ;

  template <typename Bits>
  static void enable(Bits bits) {
    mmio::CLIC.enable(bits);
  }
  template <typename Bits>
  static void disable(Bits bits) {
    mmio::CLIC.disable(bits);
  }
  static void setVectorTable(isr_func *const *table) {
    dev::irq::IrqClic::setVectorTable(table);
  }

  [[nodiscard]] inline static bool isInIrq() { return read_csr(mintstatus); }
};

}  // namespace deri::irq
