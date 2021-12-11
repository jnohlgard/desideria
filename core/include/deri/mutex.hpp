/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/thread.hpp"

#include <atomic>

namespace deri {
class Mutex {
 public:
  void lock() noexcept {
    while (!try_lock()) {
      Scheduler::yield();
    }
  }
  bool try_lock() noexcept {
    return !state.test_and_set(std::memory_order_acquire);
  }
  void unlock() noexcept { state.clear(std::memory_order_release); }

 private:
  std::atomic_flag state{};
};
}  // namespace deri
