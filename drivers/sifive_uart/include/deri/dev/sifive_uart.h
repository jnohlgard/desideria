/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_SIFIVE_UART_H_
#define DERI_DEV_SIFIVE_UART_H_

#include <deri/dev/char.h>
#include <stdint.h>

struct SiFiveUartRegs;

#ifdef __cplusplus
namespace deri::dev {

class SiFiveUart : public CharDev {
public:
  SiFiveUart(SiFiveUartRegs *dev);
  void init();
  long write(const char *buf, long len, long off); //override;

private:
  SiFiveUartRegs *dev;
};

} // namespace deri::dev
#endif // __cplusplus
#endif // DERI_DEV_SIFIVE_UART_H_