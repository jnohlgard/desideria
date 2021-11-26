/*
 * Copyright (c) 2021 Joakim Nohlgård
 */
#include "deri/time.hpp"

#include "deri/bsp/config.hpp"

namespace deri::sys::time {
void init() {
  LowPowerTimer::init();
  if constexpr (!std::is_same_v<LowPowerTimer, SystemTimer>) {
    SystemTimer::init();
  }
  if constexpr (!std::is_same_v<SystemTimer, HighResolutionTimer> &&
                !std::is_same_v<LowPowerTimer, HighResolutionTimer>) {
    HighResolutionTimer::init();
  }
}
}  // namespace deri::sys::time
