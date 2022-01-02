/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/irq_clic.hpp"
#include "deri/irq/platform_clic.hpp"

namespace deri::soc {
using Irq = irq::IrqPlatformClic;
static constexpr auto mtime_irq = Irq::IRQ::CLIC_INT_TMR;
}  // namespace deri::soc
