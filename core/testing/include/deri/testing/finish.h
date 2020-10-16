/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#ifndef DERI_TESTING_FINISH_H_
#define DERI_TESTING_FINISH_H_

#ifdef __cplusplus

namespace deri::testing {
/**
 * An interface for passing test results from the OS to an external test monitor
 *
 * This can either be implemented through a special hardware device or through
 * communications channels to a system emulator or hypervisor.
 *
 * @note The test finisher is expected to stop emulation or turn off the device.
 * Control should never return back to the system under test.
 */
class Finisher {
public:
  virtual ~Finisher() = default;

  /**
   * Power off the system and signal a test pass
   */
  [[noreturn]] virtual void pass() = 0;

  /**
   * Power off the system and signal a test failure
   *
   * @attention Avoid using @p code = 0 as this may be treated as a test pass
   * if the code is passed on from the emulator as a shell exit code.
   *
   * @param[in] code    exit code, used on devices where this is possible
   */
  [[noreturn]] virtual void fail(unsigned code) = 0;
};

/// Global testing interface handle
extern Finisher *finish;
} // namespace deri::testing
#endif // DERI_TESTING_FINISH_H_

#endif // DERI_DEV_POWERCTL_H_
