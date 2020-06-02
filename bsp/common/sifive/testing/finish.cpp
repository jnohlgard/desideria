/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/testing/finish.h"
#include "deri/bsp/memory_map.h"
#include "deri/dev/sifive_test.h"

namespace deri::dev {
SiFiveTest sifive_test(SIFIVE_TEST_REG);
} // namespace deri::dev

namespace deri::testing {
Finisher *finish = &deri::dev::sifive_test;
}
