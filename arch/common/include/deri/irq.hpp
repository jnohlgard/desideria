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
  void lock() noexcept { mask = irq_disable(); }

  bool try_lock() noexcept {
    lock();
    return true;
  }

  void unlock() noexcept { irq_restore(mask); }

 private:
  unsigned long mask{};
};

class CriticalSection {
 public:
  CriticalSection() { irq_lock.lock(); }
  ~CriticalSection() { irq_lock.unlock(); }

 private:
  IrqLock irq_lock{};
};

}
