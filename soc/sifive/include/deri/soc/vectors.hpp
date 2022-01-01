/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/arch/irq.hpp"

extern "C" {
void isr_unused();
void isr_software();
void isr_mtime();
void plic_unhandled();
void plic_unused();
void plic_WATCHDOG();
void plic_RTC();
void plic_UART0();
void plic_UART1();
void plic_QSPI0();
void plic_QSPI1();
void plic_QSPI2();
void plic_GPIO0();
void plic_GPIO1();
void plic_GPIO2();
void plic_GPIO3();
void plic_GPIO4();
void plic_GPIO5();
void plic_GPIO6();
void plic_GPIO7();
void plic_GPIO8();
void plic_GPIO9();
void plic_GPIO10();
void plic_GPIO11();
void plic_GPIO12();
void plic_GPIO13();
void plic_GPIO14();
void plic_GPIO15();
void plic_GPIO16();
void plic_GPIO17();
void plic_GPIO18();
void plic_GPIO19();
void plic_GPIO20();
void plic_GPIO21();
void plic_GPIO22();
void plic_GPIO23();
void plic_GPIO24();
void plic_GPIO25();
void plic_GPIO26();
void plic_GPIO27();
void plic_GPIO28();
void plic_GPIO29();
void plic_GPIO30();
void plic_GPIO31();
void plic_PWM0CMP0();
void plic_PWM0CMP1();
void plic_PWM0CMP2();
void plic_PWM0CMP3();
void plic_PWM1CMP0();
void plic_PWM1CMP1();
void plic_PWM1CMP2();
void plic_PWM1CMP3();
void plic_PWM2CMP0();
void plic_PWM2CMP1();
void plic_PWM2CMP2();
void plic_PWM2CMP3();
void plic_I2C0();
}  // extern "C"

namespace deri::soc {
// CLINT vectoring uses asm jump instructions, clint_vector_table must be
// declared a function and written in (inline) asm.
void clint_vector_table();
extern arch::isr_func *const vector_table[];
}  // namespace deri::soc
