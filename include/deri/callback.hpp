/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <cstdint>

namespace deri {

template <typename Function>
struct Callback {
  Function *func{nullptr};
  uintptr_t arg{};
};

}  // namespace deri
