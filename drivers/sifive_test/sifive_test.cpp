/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/dev/sifive_test.h"

struct SiFiveTestRegs {
  volatile uint32_t cmd;
};

/**
 * Possible commands
 *
 * @see https://github.com/qemu/qemu/blob/master/include/hw/riscv/sifive_test.h
 */
enum {
  FINISHER_FAIL = 0x3333,
  FINISHER_PASS = 0x5555,
  FINISHER_RESET = 0x7777
};

namespace deri::dev {

SiFiveTest::SiFiveTest(SiFiveTestRegs *dev) : dev(dev) {}

// See https://github.com/qemu/qemu/blob/master/hw/riscv/sifive_test.c

void SiFiveTest::poweroff() {
  // Writing to the test device will power off the virtual machine
  dev->cmd = FINISHER_PASS;
  __builtin_unreachable();
}

void SiFiveTest::reset() {
  dev->cmd = FINISHER_RESET;
  __builtin_unreachable();
}

void SiFiveTest::fail(uint16_t code) {
  dev->cmd = (code << 16) | FINISHER_FAIL;
  __builtin_unreachable();
}

} // namespace deri::dev
