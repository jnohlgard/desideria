/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include "deri/bsp/memory_map.h"
#include "deri/dev/uart/sifive.h"

namespace deri::bsp {
dev::uart::UartSiFive &uart1 =
    *(reinterpret_cast<dev::uart::UartSiFive *>(UART1_BASE));
}  // namespace deri::bsp
