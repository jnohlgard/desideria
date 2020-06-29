/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/dev/charnull.h"

namespace deri::dev {

size_t CharNull::write(const char *, size_t len) { return len; }

} // namespace deri::dev
