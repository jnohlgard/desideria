/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

namespace deri::dev {

/**
 * Black hole character device, a.k.a. @c /dev/null
 */
class CharNull {
 public:
  void write(const auto &) {}
};

inline CharNull null{};
}  // namespace deri::dev
