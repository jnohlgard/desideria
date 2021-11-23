/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.hpp"

#include "deri/bsp/devices.hpp"
#include "deri/console.hpp"

namespace deri {
namespace bsp {
void console_init() { usart0.init(); }
}  // namespace bsp
bsp::Console console{bsp::usart0};
}  // namespace deri
