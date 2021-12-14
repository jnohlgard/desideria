/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/irq.hpp"

#include <cstddef>
#include <cstdint>

// See https://itanium-cxx-abi.github.io/cxx-abi/abi.html#once-ctor
extern "C" int __cxa_guard_acquire(__int64_t *guard_object);
extern "C" void __cxa_guard_release(__int64_t *guard_object);
extern "C" void __cxa_guard_abort(__int64_t *guard_object);

namespace {
inline uint32_t *statePtrFromGuard(__int64_t *guard_object) {
  return reinterpret_cast<uint32_t *>(guard_object) + 1;
}
}  // namespace
/**
 * This function is called before initialization takes place.
 *
 * If this function returns 1, either __cxa_guard_release or __cxa_guard_abort
 * must be called with the same argument. The first byte of the guard_object is
 * not modified by this function.
 *
 * A thread-safe implementation will probably guard access to the first byte of
 * the guard_object with a mutex. If this function returns 1, the mutex will
 * have been acquired by the calling thread.
 *
 * @param guard_object
 * @return 1 if the initialization is not yet complete; 0 otherwise
 */
int __cxa_guard_acquire(__int64_t *guard_object) {
  auto state = deri::arch::irq_disable();
  auto &first_byte = *reinterpret_cast<std::byte *>(guard_object);
  if (first_byte != std::byte{0}) {
    deri::arch::irq_restore(state);
    return 0;
  }
  auto state_ptr = statePtrFromGuard(guard_object);
  *state_ptr = state;
  return 1;
}

/**
 * This function is called after initialization is complete.
 *
 * Sets the first byte of the guard object to a non-zero value.
 * A thread-safe implementation will release the mutex acquired by @ref
 * __cxa_guard_acquire after setting the first byte of the guard object.
 *
 * @param guard_object
 */
void __cxa_guard_release(__int64_t *guard_object) {
  auto &first_byte = *reinterpret_cast<std::byte *>(guard_object);
  first_byte = std::byte{1};
  auto &state = *statePtrFromGuard(guard_object);
  deri::arch::irq_restore(state);
}

/**
 * This function is called if the initialization terminates by throwing an
 * exception.
 *
 * A thread-safe implementation will release the mutex acquired by
 * @ref __cxa_guard_acquire.
 *
 * @param guard_object
 */
void __cxa_guard_abort(__int64_t *guard_object) {
  auto &state = *statePtrFromGuard(guard_object);
  deri::arch::irq_restore(state);
}
