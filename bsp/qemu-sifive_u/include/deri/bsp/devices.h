/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

#include "deri/bsp/memory_map.h"
#include "deri/dev/uart/sifive.h"

namespace deri::bsp {
extern deri::dev::uart::UartSiFive uart0;
extern deri::dev::uart::UartSiFive uart1;
}  // namespace deri::bsp
