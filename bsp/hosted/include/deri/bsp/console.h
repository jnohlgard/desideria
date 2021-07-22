/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once
#include "deri/dev/charnull.h"

namespace deri::bsp {
using Console = dev::BlackHole;
/**
 * Initialize the console UART settings
 */
void console_init();
}  // namespace deri::bsp
