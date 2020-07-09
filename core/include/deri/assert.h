/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#ifndef DERI_ASSERT_H_
#define DERI_ASSERT_H_

extern "C" {
#include <stdio.h>
}

namespace deri {

// Get the current program counter
__attribute__((noinline)) void *get_pc();

__attribute__((cold)) void failed_assertion(const char *msg);

__attribute__((always_inline)) inline void assert(bool check, const char *msg = nullptr) {
  if (!check) {
    failed_assertion(msg);
  }
}

}

#endif // DERI_ASSERT_H_
