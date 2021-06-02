/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

#include "deri/bsp/memory_map.h"
#include "deri/dev/uart/sifive.h"

namespace deri::bsp {
inline static deri::dev::uart::UartSiFive &uart0{
    *(reinterpret_cast<dev::uart::UartSiFive *>(UART0_BASE))};
inline static deri::dev::uart::UartSiFive &uart1{
    *(reinterpret_cast<dev::uart::UartSiFive *>(UART1_BASE))};
}  // namespace deri::bsp
