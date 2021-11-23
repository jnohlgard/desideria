/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.hpp"

#include "deri/bsp/devices.hpp"
#include "deri/console.hpp"

namespace deri {
namespace bsp {
void console_init() { uart0.init(); }
}  // namespace bsp
bsp::Console console{bsp::uart0};
}  // namespace deri
