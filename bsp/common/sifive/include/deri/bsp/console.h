/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once
#include "deri/dev/charbuf.h"
#include "deri/dev/uart/sifive.h"

namespace deri::bsp {
using Console = dev::CharBuf<dev::uart::UartSiFive>;
/**
 * Initialize the console UART settings
 */
void console_init();
} // namespace deri::bsp
