/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/mmio_driver.hpp"
#include "deri/dev/timer.hpp"
#include "deri/dev/timer_riscv.hpp"
#include "deri/soc/mtime_dev.hpp"

namespace deri::soc {
using TimerPeriph = dev::timer::TimerRiscv;

template <>
struct HardwareMap<mtime_dev>
    : public detail::HardwareMapDefinition<mtime_dev, Clock::TileLink{}> {};

template <>
struct TimerDevice<0> {
  static inline auto &device{mtime_dev};
};

inline auto &mtime() { return MTimer::get(); }

}  // namespace deri::soc
