/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/testing/finish.hpp"
#include "global_ctor_test.hpp"

namespace test {
// The value is not used, we only use the address of this symbol
long canary = 0x12345678l;
}

int main() {
  if (test::sut.verify(&test::canary)) {
    deri::testing::finish(0);
  }

  deri::testing::finish(1);

  return 0;
}
