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
  mmio::CLIC.init(deri_exception_handler);
  Irq::setVectorTable(vector_table);
  mmio::AFIO.init();
}
}  // namespace deri::soc
