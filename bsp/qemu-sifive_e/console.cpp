/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/console.h"
#include "deri/bsp/memory_map.h"
#include "deri/dev/sifive_uart.h"

namespace deri::bsp {
deri::dev::SiFiveUart uart0(UART0);
deri::dev::SiFiveUart uart1(UART1);
} // namespace deri::bsp

namespace deri {
dev::CharDev *console = &deri::bsp::uart0;
} // namespace deri

namespace deri::bsp {
void console_init() { deri::bsp::uart0.init(); }
} // namespace deri::bsp
