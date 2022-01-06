/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#pragma once
#include "deri/dev/mmio_driver.hpp"
#include "deri/dev/timer_riscv.hpp"

namespace deri::soc {
// this is a virtual device only used for tagging the template specializations,
// the address of the mtime registers are provided by the linker as separate
// symbols because of register layout differences between different vendor
// implementations of the RISC-V timer spec.
inline dev::timer::TimerRiscv mtime_dev{};
static_assert(sizeof(mtime_dev) == 1);

template <>
struct DefaultConfig<dev::timer::TimerRiscv> {
  using Driver = dev::timer::TimerDriver<dev::timer::TimerRiscv>;
};

using MTimer = MmioDriver<mtime_dev>;

}  // namespace deri::soc
