/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once
#include "deri/dev/charbuf.hpp"
#include "deri/dev/uart_gd32.hpp"

namespace deri::bsp {
using Console = dev::BlockingDevice<dev::uart::UsartGd32>;
/**
 * Initialize the console UART settings
 */
void console_init();
}  // namespace deri::bsp
