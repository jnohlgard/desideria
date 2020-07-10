/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_SIFIVE_UART_H_
#define DERI_DEV_SIFIVE_UART_H_

#include <cstddef>
#include <deri/dev/char.hpp>

struct SiFiveUartRegs;

#ifdef __cplusplus
namespace deri::dev {

class SiFiveUart : public CharDev {
public:
  explicit SiFiveUart(SiFiveUartRegs *dev);
  SiFiveUart(const SiFiveUart&) = default;
  SiFiveUart& operator=(const SiFiveUart&) = default;
  void init();
  size_t write(const char *buf, size_t len) override;

private:
  SiFiveUartRegs *dev;
};

} // namespace deri::dev
#endif // __cplusplus
#endif // DERI_DEV_SIFIVE_UART_H_
