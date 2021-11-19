/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/bsp_init.h"

#include "deri/bsp/console.h"
#include "deri/console.h"
#include "deri/soc/init.h"
#include "deri/span_literals.h"

using namespace deri::literals;

namespace deri::bsp {
void init() {
  soc::init();
  console_init();
  console.write(std::as_bytes("Board init done\n"_span));
}
}  // namespace deri::bsp
