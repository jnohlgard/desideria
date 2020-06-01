/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_SIFIVE_TEST_SIFIVE_TEST_H_
#define DERI_DEV_SIFIVE_TEST_SIFIVE_TEST_H_

#include <stdint.h>

struct SiFiveTestRegs;

#ifdef __cplusplus

namespace deri::dev {

class SiFiveTest {
public:
  SiFiveTest(SiFiveTestRegs *dev);

  /**
   * Power off the virtual device and exit qemu with exit code 0
   */
  __attribute__((noreturn)) void poweroff();

  /**
   * Signal QEMU to trigger a reset of the emulated hardware
   */
  __attribute__((noreturn)) void reset();

  /**
   * Power off the virtual device and exit qemu with the given exit code
   * @param code Code to pass back to the parent process
   */
  __attribute__((noreturn)) void fatal_error(unsigned int code);

private:
  SiFiveTestRegs *dev;
};

} // namespace deri::dev

#endif // __cplusplus

#endif // DERI_DEV_SIFIVE_TEST_SIFIVE_TEST_H_
