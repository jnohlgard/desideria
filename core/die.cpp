/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/die.h"
namespace deri {

void die(unsigned int code) {
  (void)code;
  while (1) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
}

}
