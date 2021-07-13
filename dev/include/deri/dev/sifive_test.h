/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

#include "deri/testing/finish.h"
#include <stdint.h>

struct SiFiveTestRegs;

namespace deri::dev {

class SiFiveTest : public deri::testing::Finisher {
public:
  explicit SiFiveTest(SiFiveTestRegs *dev);
  SiFiveTest(const SiFiveTest&) = default;
  SiFiveTest& operator=(const SiFiveTest&) = default;

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
