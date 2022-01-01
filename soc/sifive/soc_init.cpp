/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/arch_init.hpp"
#include "deri/soc/irq_dev.hpp"
#include "deri/soc/vectors.hpp"

namespace deri::soc {
void init() {
  arch::init();
  dev::irq::IrqClint::setVectorTable(clint_vector_table);
  Irq::setVectorTable(vector_table);
  mmio::PLIC.init();
}
}  // namespace deri::soc
