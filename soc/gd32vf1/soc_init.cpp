/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/afio_gd32.h"
#include "deri/soc/gpio_dev.h"
#include "deri/soc/irq_dev.h"
#include "deri/soc/vectors.h"

namespace deri::soc {
void init() {
  clic.init();
  clic.setVectorTable(vector_table);
  soc::afio.init();
  arch::irq_enable();
}
}  // namespace deri::soc
