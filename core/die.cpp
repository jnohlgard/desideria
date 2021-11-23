/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/die.hpp"
namespace deri {

void die(unsigned int code) {
  (void)code;
  while (true) {
    asm volatile("" ::: "memory");
  }
  __builtin_unreachable();
}

}
