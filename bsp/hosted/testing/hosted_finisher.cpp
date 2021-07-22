/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include "deri/bsp/hosted_finisher.h"

#include <cstdlib>

void deri::dev::HostedFinisher::pass() { std::exit(0); }

void deri::dev::HostedFinisher::fail(unsigned int code) {
  std::exit(static_cast<int>(code));
}
