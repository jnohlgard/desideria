/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#include "deri/console.h"
#include "deri/dev/charnull.h"

namespace deri {
namespace dev {
namespace {
dev::CharNull null{};
}
} // namespace dev
dev::CharDev *console = &dev::null;
} // namespace deri
