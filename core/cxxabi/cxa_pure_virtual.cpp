/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/panic.hpp"

extern "C" {
// Pure virtual function calls will end up here.
// This should only happen if we manage to instantiate an abstract class and
// call methods on it.
[[noreturn]] void __cxa_pure_virtual() { deri::panic(); }
}
