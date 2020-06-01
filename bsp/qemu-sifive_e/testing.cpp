/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/memory_map.h"
#include "deri/dev/sifive_test.h"

namespace deri::dev {
// TODO hard-coded global for now
SiFiveTest sifive_test(SIFIVE_TEST_REG);
}
