/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/uart_dev.hpp"

using namespace deri::soc;
extern "C" {
[[gnu::interrupt]] void isr_USART0() { Uart<0>::static_instance->interrupt(); }
[[gnu::interrupt]] void isr_USART1() { Uart<1>::static_instance->interrupt(); }
[[gnu::interrupt]] void isr_USART2() { Uart<2>::static_instance->interrupt(); }
[[gnu::interrupt]] void isr_UART3() { Uart<3>::static_instance->interrupt(); }
[[gnu::interrupt]] void isr_UART4() { Uart<4>::static_instance->interrupt(); }
}
