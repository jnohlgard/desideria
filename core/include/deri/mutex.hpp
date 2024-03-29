/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/irq.hpp"
#include "deri/thread.hpp"

#include <atomic>

namespace deri {
class Mutex {
 public:
  void lock() noexcept {
    arch::CriticalSection cs{};
    while (!try_lock()) {
      auto &thread = Scheduler::activeThread();
      thread.block(Thread::Status::MUTEX_WAIT);
      waiters.push(thread);
      deri::Scheduler::update();
    }
  }
  bool try_lock() noexcept {
    return !state.test_and_set(std::memory_order_acquire);
  }
  void unlock() noexcept {
    arch::CriticalSection cs{};
    state.clear(std::memory_order_release);
    if (!waiters.empty()) {
      auto &thread = waiters.front();
      waiters.pop();
      thread.unblock();
      deri::Scheduler::update();
    }
  }

 private:
  Thread::PriorityQueue waiters{};
  std::atomic_flag state{};
};
}  // namespace deri
