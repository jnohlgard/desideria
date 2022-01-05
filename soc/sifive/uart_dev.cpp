/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/uart_dev.hpp"

using namespace deri::soc;

extern "C" {
void plic_UART0() { Uart<0>::static_instance->interrupt(); }
}
