/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_SIFIVE_UART_H_
#define DERI_DEV_SIFIVE_UART_H_

#include <deri/dev/char.h>
#include <stdint.h>

#ifdef __cplusplus
namespace deri::dev {

struct SifiveUartRegs;

class SifiveUart : public CharDev {
public:
  SifiveUart(SifiveUartRegs *dev);
  void init();
  long write(const char *buf, long len, long off); //override;

private:
  SifiveUartRegs *dev;
};

} // namespace deri::dev
#endif // __cplusplus
#endif // DERI_DEV_SIFIVE_UART_H_
