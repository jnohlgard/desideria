/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/function.hpp"
#include "deri/forward_list.hpp"
#include "deri/log.hpp"

namespace deri::log {
struct Clock;
}  // namespace deri::log

namespace deri::dev::clock {

struct OnClockChange : ForwardListNode<OnClockChange> {
  Function<void(unsigned)> callback{};
};
}  // namespace deri::dev::clock
