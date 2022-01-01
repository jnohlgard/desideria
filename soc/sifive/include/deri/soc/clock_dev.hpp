/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/callback.hpp"
#include "deri/dev/clock.hpp"
#include "deri/irq.hpp"
#include "deri/log.hpp"

namespace deri::log {
struct Clock;
}  // namespace deri::log

namespace deri::soc {
class Clock {
  using Logger = log::Logger<log::Clock>;

 public:
  using OnClockChange = dev::clock::OnClockChange;
  enum class Core {};
  enum class TileLink {};

  [[nodiscard]] static unsigned current(Core) { return 16'000'000u; }
  [[nodiscard]] static unsigned current(TileLink) { return current(Core{}); }

  static void onClockChange(OnClockChange &on_clock_change, TileLink) {
    arch::CriticalSection cs{};
    tlclk_users.remove(on_clock_change);
    tlclk_users.push_front(on_clock_change);
  }

 private:
  static inline ForwardList<OnClockChange> tlclk_users{};
};
}  // namespace deri::soc
