/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include "deri/bsp/memory_map.h"
#include "deri/dev/uart/sifive.h"

namespace deri::bsp {
// This is probably undefined behaviour...
dev::uart::UartSiFive &uart0 =
    *(reinterpret_cast<dev::uart::UartSiFive *>(UART0_BASE));
}  // namespace deri::bsp
