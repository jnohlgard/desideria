/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.h"

#include "deri/bsp/devices.h"
#include "deri/dev/clock_gd32.h"

namespace deri {
using namespace dev::clock;
using PinNum = dev::gpio::GpioGd32::PinNum;
namespace bsp {
void console_init() {
  enableModules(APB2EN_bits::USART0EN | APB2EN_bits::PAEN);
  gpioa.initOutAfio(static_cast<PinNum>(9));
  uart0.init();
}
}  // namespace bsp
bsp::Console console{bsp::uart0};
}  // namespace deri
