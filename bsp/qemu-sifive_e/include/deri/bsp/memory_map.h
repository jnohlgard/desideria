/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

#include <cstdint>

constexpr static uintptr_t SIFIVE_TEST_REG_BASE = 0x00100000ul;
#define SIFIVE_TEST_REG ((SiFiveTestRegs *)SIFIVE_TEST_REG_BASE)
