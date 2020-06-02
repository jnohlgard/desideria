/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include "deri/bsp/memory_map.h"
#include "deri/dev/sifive_uart.h"

namespace deri::bsp {
deri::dev::SiFiveUart uart1(UART1);
} // namespace deri::bsp
