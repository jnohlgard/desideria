/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/uart_gd32.h"

namespace deri::bsp {
// HXTAL is populated with a 8 MHz crystal
inline constexpr uint32_t hxtal_freq = 8'000'000u;

extern deri::dev::uart::UsartGd32 uart0;
}  // namespace deri::bsp
