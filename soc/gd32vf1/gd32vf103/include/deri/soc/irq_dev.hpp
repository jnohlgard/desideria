/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/irq_clic.hpp"
#include "deri/irq/platform_clic.hpp"

namespace deri::soc {
class Irq : public irq::IrqPlatformClic {
 public:
  static constexpr auto mtime_irq = IRQ::CLIC_INT_TMR;
};
}  // namespace deri::soc
