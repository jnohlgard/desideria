/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/uart_dev.hpp"

#include <array>

namespace deri::soc {
std::array<dev::uart::UartIrqDriver<soc::UartPeriph> *, 2> uart;
}

extern "C" {
void plic_UART0() { deri::soc::uart[0]->interrupt(); }
}
