/*
* Copyright (c) 2021 Joakim Nohlgård
*/

#include "deri/dev/clock_gd32.h"
#include "deri/mmio/peripherals.hpp"

namespace deri::dev::clock {

using mmio::RCU;
void enableModules(AHBEN_bits bits) { RCU.AHBEN |= bits; }
void enableModules(APB1EN_bits bits) { RCU.APB1EN |= bits; }
void enableModules(APB2EN_bits bits) { RCU.APB2EN |= bits; }

}  // namespace deri::dev::clock
