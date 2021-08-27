/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bitwise_enums.h"
#include "deri/registers.h"

namespace deri::dev {

namespace {

/**
 * Possible commands
 *
 * @see https://github.com/qemu/qemu/blob/master/include/hw/misc/sifive_test.h
 */
enum class SifiveTestCommand : uint32_t {
  FAIL = 0x3333,
  PASS = 0x5555,
  RESET = 0x7777,
};
void HasBitwiseOperators(SifiveTestCommand);

}  // namespace

class SifiveTest {
  Register<SifiveTestCommand> cmd;

  [[noreturn]] void pass() {
    cmd.store(SifiveTestCommand::PASS);
    while (true) {
    }
  }

  [[noreturn]] void fail(int code) {
    auto composed_command = SifiveTestCommand::FAIL;
    composed_command |= static_cast<SifiveTestCommand>(code << 16);
    cmd.store(composed_command);
    while (true) {
    }
  }
};

// See https://github.com/qemu/qemu/blob/master/hw/misc/sifive_test.c

}  // namespace deri::dev
