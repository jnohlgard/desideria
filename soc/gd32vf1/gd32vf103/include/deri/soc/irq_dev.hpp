/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/irq_clic.hpp"

namespace deri::mmio {
extern dev::irq::IrqClic CLIC;
}

namespace deri::soc {
class Irq {
 public:
  using IRQ = dev::irq::IrqClic::IRQ;

  template <typename Bits>
  static void enable(Bits bits) {
    mmio::CLIC.enableIrq(bits);
  }
  template <typename Bits>
  static void disable(Bits bits) {
    mmio::CLIC.disableIrq(bits);
  }
  template <typename Table>
  static void setVectorTable(Table &&table) {
    dev::irq::IrqClic::setVectorTable(std::forward<Table>(table));
  }
};
}
