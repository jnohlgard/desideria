/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.h"

#include "deri/bsp/devices.h"
#include "deri/console.h"

namespace deri {
namespace bsp {
void console_init() { uart0.init(); }
}  // namespace bsp
bsp::Console console{bsp::uart0};
}  // namespace deri
