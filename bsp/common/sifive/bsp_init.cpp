/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/bsp_init.h"
#include "deri/bsp/console.h"
#include "deri/console.h"

namespace deri::bsp {
void init() {
  console_init();
  static constexpr char hello_msg[] = "Board init done\n";
  console.write(std::as_bytes(std::span<const char>{hello_msg, sizeof hello_msg}));
}
} // namespace deri::bsp
