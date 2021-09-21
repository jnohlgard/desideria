/*
 * This file contains alias mappings from C++ symbols to linker script defined MMIO addresses
 */

/* Unused aliases do not need to refer to an existing symbol, so extraneous entries are not a concern in this file. */

/* Mangled names are compatible with GCC on Linux */

/* UART device names */
PROVIDE(_ZN4deri3bsp5uart0E = UART0$);
PROVIDE(_ZN4deri3bsp5uart1E = UART1$);
PROVIDE(_ZN4deri3bsp5uart2E = UART2$);
PROVIDE(_ZN4deri3bsp5uart3E = UART3$);
PROVIDE(_ZN4deri3bsp5uart4E = UART4$);
PROVIDE(_ZN4deri3bsp5uart5E = UART5$);
PROVIDE(_ZN4deri3bsp6usart0E = USART0$);
PROVIDE(_ZN4deri3bsp6usart1E = USART1$);
PROVIDE(_ZN4deri3bsp6usart2E = USART2$);
PROVIDE(_ZN4deri3bsp6usart3E = USART3$);
PROVIDE(_ZN4deri3bsp6usart4E = USART4$);
PROVIDE(_ZN4deri3bsp6usart5E = USART5$);
