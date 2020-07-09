/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/assert.h"

namespace deri {

void failed_assertion(const char *msg) {
  void *failed_pc = reinterpret_cast<void *>(
      reinterpret_cast<uintptr_t>(
          __builtin_extract_return_addr(__builtin_return_address(0))) -
      2);
  printf("Failed assertion: %p\n", failed_pc);
  if (msg) {
    printf("error: %s\n", msg);
  }
  while (1) {
  }
}

} // namespace deri
