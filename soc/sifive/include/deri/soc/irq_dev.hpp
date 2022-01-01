/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/irq_clint.hpp"
#include "deri/dev/irq_plic.hpp"
#include "deri/irq/platform_clint_plic.hpp"

namespace deri::soc {
class Irq : public irq::IrqPlatformPlicClint {
 public:
  constexpr static auto mtime_irq = dev::irq::IrqClint::IRQ::TIMER;
  constexpr static auto external_irq = dev::irq::IrqClint::IRQ::EXTERNAL;
};
}  // namespace deri::soc
