/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once
#include "deri/arch/irq.hpp"

namespace deri::arch {

/**
 * Lockable intended for use with std::scoped_lock
 */
class IrqLock {
 public:
  [[gnu::always_inline]] void lock() noexcept { mask = irq_disable(); }

  [[gnu::always_inline]] bool try_lock() noexcept {
    lock();
    return true;
  }

  [[gnu::always_inline]] void unlock() noexcept { irq_restore(mask); }

 private:
  unsigned long mask{};
};

class CriticalSection {
 public:
  [[gnu::always_inline]] CriticalSection() { irq_lock.lock(); }
  [[gnu::always_inline]] ~CriticalSection() { irq_lock.unlock(); }

 private:
  IrqLock irq_lock{};
};

}
