/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

namespace deri {

// Get the current program counter
[[gnu::noinline]] void *get_pc();

[[gnu::cold]] void failed_assertion(const char *msg);

[[gnu::always_inline]] inline void assert(bool check,
                                          const char *msg = nullptr) {
  if (!check) [[unlikely]] {
    failed_assertion(msg);
  }
}

}  // namespace deri
