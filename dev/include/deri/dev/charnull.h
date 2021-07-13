/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

namespace deri::dev {

/**
 * Black hole character device, a.k.a. @c /dev/null
 */
class BlackHole {
 public:
  void write(const auto &) {}
};

inline BlackHole null{};
}  // namespace deri::dev
