/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once
#include "deri/dev/charbuf.h"
#include "deri/dev/uart/gd32.h"

namespace deri::bsp {
using Console = dev::BlockingDevice<dev::uart::UsartGd32>;
/**
 * Initialize the console UART settings
 */
void console_init();
}  // namespace deri::bsp
