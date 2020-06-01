/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_BSP_MEMORY_MAP_H_
#define DERI_BSP_MEMORY_MAP_H_

#define UART0_BASE 0x10013000
#define UART0 ((SiFiveUartRegs*)UART0_BASE)

#define SIFIVE_TEST_REG_BASE 0x00100000
#define SIFIVE_TEST_REG ((SiFiveTestRegs *)SIFIVE_TEST_REG_BASE)

#endif // DERI_BSP_MEMORY_MAP_H_
