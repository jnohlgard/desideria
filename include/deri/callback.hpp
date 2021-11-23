/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include <cstdint>
#include <type_traits>

namespace deri {

template <typename Function>
struct Callback {
  Function *func;
  uintptr_t arg;
};

}  // namespace deri
