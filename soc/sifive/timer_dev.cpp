/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/soc/timer_dev.hpp"

namespace deri::soc {
dev::timer::TimerDriver<dev::timer::TimerRiscv> &mtime() {
  static auto &instance = []() -> auto & {
    static auto device = dev::timer::TimerRiscv{};
    static auto driver = dev::timer::TimerDriver{device};
    return driver;
  }
  ();
  return instance;
}
}  // namespace deri::soc

extern "C" {

[[gnu::interrupt, gnu::used]] void isr_mtime();
void isr_mtime() {
  deri::soc::mtime().channelInterrupt(deri::dev::timer::TimerRiscv::Channel{});
}
}
