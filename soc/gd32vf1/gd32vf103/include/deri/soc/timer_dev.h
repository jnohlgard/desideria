/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/timer.h"
#include "deri/dev/timer_gd32.h"

#include <array>

namespace deri::soc {
using TimerPeriph = dev::timer::TimerGd32;
extern TimerPeriph timer0;
extern TimerPeriph timer1;
extern TimerPeriph timer2;
extern TimerPeriph timer3;
extern TimerPeriph timer4;
extern TimerPeriph timer5;
extern TimerPeriph timer6;

using TimerDriver = dev::timer::TimerDriver<TimerPeriph>;

inline std::array timers = {
    TimerDriver{timer0},
    TimerDriver{timer1},
    TimerDriver{timer2},
    TimerDriver{timer3},
    TimerDriver{timer4},
    TimerDriver{timer5},
    TimerDriver{timer6},
};

}  // namespace deri::soc
