/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_DEV_CHAR_HPP_
#define DERI_DEV_CHAR_HPP_

#include <cstddef>

namespace deri::dev {

class CharDev {
public:
  virtual size_t write(const char *buf, size_t len) = 0;
};

} // namespace deri::dev

#endif // DERI_DEV_CHAR_HPP_
