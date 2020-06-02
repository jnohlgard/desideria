/*
 * Copyright (c) 2020 Joakim Nohlgård
 */

#ifndef GLOBAL_CTOR_TEST_H_
#define GLOBAL_CTOR_TEST_H_

namespace test {
class Sut {
public:
  /**
   * @param expected canary value that will be compared during testing
   */
  Sut(const void *expected);

  bool verify(const void *actual);

private:
  const void *expected;
};

extern Sut sut;

extern long canary;
}

#endif // GLOBAL_CTOR_TEST_H_
