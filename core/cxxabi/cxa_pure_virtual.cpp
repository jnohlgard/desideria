/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/die.hpp"

// Pure virtual function calls will end up here.
// This should only happen if we manage to instantiate an abstract class and
// call methods on it.
extern "C" void __cxa_pure_virtual()
{
  deri::die(1);
  while (1) {}
  __builtin_unreachable();
}
