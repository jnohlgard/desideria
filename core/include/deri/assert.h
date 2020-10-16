/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#ifndef DERI_ASSERT_H_
#define DERI_ASSERT_H_

namespace deri {

// Get the current program counter
[[gnu::noinline]] void *get_pc();

[[gnu::cold]] void failed_assertion(const char *msg);

[[gnu::always_inline]] inline void assert(bool check, const char *msg = nullptr) {
  if (!check) {
    failed_assertion(msg);
  }
}

}

#endif // DERI_ASSERT_H_
