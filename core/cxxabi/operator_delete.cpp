/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/die.hpp"
#include <cstddef>

// operator delete is required if we use any classes which have virtual
// destructors, regardless if they are ever heap allocated or not.

// http://en.cppreference.com/w/cpp/memory/new/operator_delete
void operator delete(void* p)
{
  (void)p;
  deri::die(123);
}

void operator delete(void* p, size_t t)
{
  (void)p;
  (void)t;
  deri::die(123);
}
