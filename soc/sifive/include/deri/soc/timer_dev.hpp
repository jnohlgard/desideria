/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/mmio_driver.hpp"
#include "deri/dev/timer.hpp"
#include "deri/dev/timer_riscv.hpp"

namespace deri::soc {
using TimerPeriph = dev::timer::TimerRiscv;

template <>
struct DefaultConfig<dev::timer::TimerRiscv> {
  using Driver = dev::timer::TimerDriver<dev::timer::TimerRiscv>;
};

// this is a virtual device only used for tagging the template specializations,
// the address of the mtime registers are provided by the linker as separate
// symbols because of register layout differences between different vendor
// implementations of the RISC-V timer spec.
inline dev::timer::TimerRiscv mtime_dev{};
static_assert(sizeof(mtime_dev) == 1);

template <>
struct HardwareMap<mtime_dev>
    : public detail::HardwareMapDefinition<mtime_dev, Clock::TileLink{}> {};

template <>
struct TimerDevice<0> {
  static inline auto &device{mtime_dev};
};

using MTimer = MmioDriver<mtime_dev>;

inline dev::timer::TimerDriver<dev::timer::TimerRiscv> &mtime() {
  return MTimer::get();
}

}  // namespace deri::soc
