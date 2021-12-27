/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/callback.hpp"
#include "deri/forward_list.hpp"
#include "deri/log.hpp"

namespace deri::log {
struct Clock;
}  // namespace deri::log

namespace deri::dev::clock {

struct OnClockChange : ForwardListNode<OnClockChange> {
  Callback<void(unsigned, uintptr_t)> callback{};
};

template <class Driver>
void updateModuleClockCallback(unsigned module_clock, uintptr_t arg) {
  using Logger = log::Logger<log::Clock>;

  auto &self = *reinterpret_cast<Driver *>(arg);
  self.updateModuleClock(module_clock);
  Logger::info("New module clock %s @ %p: %u\n",
               Driver::driver_name,
               static_cast<const void *>(&self),
               module_clock);
}
}  // namespace deri::dev::clock
