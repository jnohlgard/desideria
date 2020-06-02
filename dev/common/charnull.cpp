/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/dev/charnull.h"

namespace deri::dev {

long CharNull::write(const char *, long len) { return len; }

} // namespace deri::dev
