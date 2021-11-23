/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#pragma once

namespace test {
class Sut {
public:
  /**
   * @param expected canary value that will be compared during testing
   */
  explicit Sut(const void *expected);

  bool verify(const void *actual);

private:
  const void *expected;
};

extern Sut sut;

extern long canary;
}
