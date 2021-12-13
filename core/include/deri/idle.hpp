/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/thread.hpp"

namespace deri {
class IdleThread {
 public:
  static void init();

 private:
  [[noreturn]] static int loop();
};
}  // namespace deri
