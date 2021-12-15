/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/uart_dev.hpp"

extern "C" {
[[gnu::interrupt]] void isr_USART0() { deri::soc::uart0().interrupt(); }
[[gnu::interrupt]] void isr_USART1() { deri::soc::uart1().interrupt(); }
[[gnu::interrupt]] void isr_USART2() { deri::soc::uart2().interrupt(); }
[[gnu::interrupt]] void isr_UART3() { deri::soc::uart3().interrupt(); }
[[gnu::interrupt]] void isr_UART4() { deri::soc::uart4().interrupt(); }
}
