/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/timer.hpp"
#include "deri/dev/timer_gd32.hpp"
#include "deri/dev/timer_riscv.hpp"
#include "deri/soc/soc.hpp"

#include <array>

namespace deri::soc {
using TimerPeriph = dev::timer::TimerGd32;
}

namespace deri::mmio {
extern soc::TimerPeriph TIMER0;
extern soc::TimerPeriph TIMER1;
extern soc::TimerPeriph TIMER2;
extern soc::TimerPeriph TIMER3;
extern soc::TimerPeriph TIMER4;
extern soc::TimerPeriph TIMER5;
extern soc::TimerPeriph TIMER6;
}  // namespace deri::mmio

namespace deri::soc {
using TimerPeriphDriver = dev::timer::TimerDriver<TimerPeriph>;

extern std::array<TimerPeriphDriver *, 7> timers;

TimerPeriphDriver &timer0();
TimerPeriphDriver &timer1();
TimerPeriphDriver &timer2();
TimerPeriphDriver &timer3();
TimerPeriphDriver &timer4();
TimerPeriphDriver &timer5();
TimerPeriphDriver &timer6();

dev::timer::TimerDriver<dev::timer::TimerRiscv> &mtime();

}  // namespace deri::soc
