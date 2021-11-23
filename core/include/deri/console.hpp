/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

#include "deri/bsp/console.hpp"

namespace deri {
/**
 * Kernel console device
 *
 * Should be set up in early boot by the board initialization code
 */
extern bsp::Console console;
}
