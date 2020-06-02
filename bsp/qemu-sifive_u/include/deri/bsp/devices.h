/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#ifndef DERI_BSP_DEVICES_H_
#define DERI_BSP_DEVICES_H_

#include "deri/dev/sifive_uart.h"

namespace deri::bsp {
extern deri::dev::SiFiveUart uart0;
extern deri::dev::SiFiveUart uart1;
} // namespace deri::bsp

#endif // DERI_BSP_DEVICES_H_
