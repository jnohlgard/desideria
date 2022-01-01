/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/timer.hpp"
#include "deri/dev/timer_riscv.hpp"

namespace deri::soc {
dev::timer::TimerDriver<dev::timer::TimerRiscv> &mtime();
}  // namespace deri::soc
