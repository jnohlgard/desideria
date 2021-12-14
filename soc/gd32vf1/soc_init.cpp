/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/arch_init.hpp"
#include "deri/arch/irq.hpp"
#include "deri/dev/afio_gd32.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/soc/irq_dev.hpp"
#include "deri/soc/vectors.hpp"

namespace deri::soc {
void init() {
  arch::init();
  clic.init(deri_exception_handler);
  dev::irq::IrqClic::setVectorTable(vector_table);
  afio.init();
  arch::irqEnable();
}
}  // namespace deri::soc
