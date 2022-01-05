/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/timer_dev.hpp"

extern "C" {

[[gnu::interrupt, gnu::used]] void isr_mtime();
void isr_mtime() {
  deri::soc::MTimer::static_instance->channelInterrupt(
      deri::dev::timer::TimerRiscv::Channel{});
}
}
