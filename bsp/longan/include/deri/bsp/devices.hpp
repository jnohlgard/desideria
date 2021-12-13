/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

#include "deri/bsp/config.hpp"
#include "deri/dev/timer_manager.hpp"
#include "deri/dev/uart_gd32.hpp"

namespace deri::bsp {
// HXTAL is populated with a 8 MHz crystal
inline constexpr uint32_t hxtal_freq = 8'000'000u;

extern deri::dev::uart::UsartGd32 uart0;
}  // namespace deri::bsp
