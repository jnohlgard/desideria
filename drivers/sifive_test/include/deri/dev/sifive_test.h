/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_SIFIVE_TEST_H_
#define DERI_DEV_SIFIVE_TEST_H_

#include "deri/testing/finish.h"
#include <stdint.h>

struct SiFiveTestRegs;

#ifdef __cplusplus

namespace deri::dev {

class SiFiveTest : public deri::testing::Finisher {
public:
  SiFiveTest(SiFiveTestRegs *dev);

  /**
   * Power off the virtual device and exit qemu with exit code 0
   */
  [[noreturn]] void pass() override;

  /**
   * Signal QEMU to trigger a reset of the emulated hardware
   */
  [[noreturn]] void reset();

  /**
   * Power off the virtual device and exit qemu with the given exit code
   * @param code Code to pass back to the parent process
   */
  [[noreturn]] void fail(unsigned int code) override;

private:
  SiFiveTestRegs *dev;
};

/**
 * Global handle for the test interface
 */
extern SiFiveTest sifive_test;

} // namespace deri::dev

#endif // __cplusplus

#endif // DERI_DEV_SIFIVE_TEST_H_
