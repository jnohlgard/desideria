/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

#include "deri/bsp/memory_map.hpp"
#include "deri/dev/uart_sifive.hpp"

namespace deri::bsp {
extern deri::dev::uart::UartSiFive uart0;
extern deri::dev::uart::UartSiFive uart1;
}  // namespace deri::bsp
