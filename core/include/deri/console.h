/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_CONSOLE_H_
#define DERI_DEV_CONSOLE_H_

#include "deri/dev/char.hpp"

namespace deri {
/**
 * Kernel console device
 *
 * Should be set up in early boot by the board initialization code
 */
extern dev::CharDev *console;
}
#endif // DERI_DEV_CONSOLE_H_
