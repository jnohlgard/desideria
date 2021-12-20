/*
 * Copyright (c) 2021 Joakim Nohlgård
 */
#include "deri/time.hpp"

#include "deri/bsp/config.hpp"

namespace deri::sys::time {
void init() {
  LowPowerTimer::init();
  SystemTimer::init();
  HighResolutionTimer::init();
}
}  // namespace deri::sys::time
