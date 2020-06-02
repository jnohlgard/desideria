/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/bsp_init.h"
#include "deri/bsp/console.h"
#include "deri/console.h"

namespace deri::bsp {
void init() {
  console_init();
  static const char hello_msg[] = "Board init done\n";
  deri::console->write(hello_msg, sizeof(hello_msg));
}
} // namespace deri::bsp
