/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.h"

#include "deri/bsp/devices.h"
#include "deri/console.h"

namespace deri {
namespace bsp {
void console_init() { usart0.init(); }
}  // namespace bsp
bsp::Console console{bsp::usart0};
}  // namespace deri
