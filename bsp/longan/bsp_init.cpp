/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/bsp_init.hpp"

#include "deri/bsp/console.hpp"
#include "deri/console.hpp"
#include "deri/soc/init.hpp"
#include "deri/span_literals.hpp"
#include "deri/time.hpp"

using namespace deri::literals;

namespace deri::bsp {
void init() {
  soc::init();
  sys::time::init();
  Console::write(std::as_bytes("Board init done\n"_span));
}
}  // namespace deri::bsp
