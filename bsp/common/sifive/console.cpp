/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/console.h"
#include "deri/bsp/devices.h"

namespace deri {
dev::CharDev *console = &deri::bsp::uart0;
} // namespace deri

namespace deri::bsp {
void console_init() { deri::bsp::uart0.init(); }
} // namespace deri::bsp
