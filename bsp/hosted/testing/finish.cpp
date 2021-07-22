/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/testing/finish.h"

#include "deri/bsp/hosted_finisher.h"

namespace deri::dev {
namespace {
HostedFinisher hosted_finisher{};
}
}  // namespace deri::dev

namespace deri::testing {
Finisher &finish{deri::dev::hosted_finisher};
}
