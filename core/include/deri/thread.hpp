/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/arch/thread.hpp"
#include "deri/list.hpp"
#include "deri/span_align.hpp"

#include <atomic>
#include <cstddef>
#include <span>

namespace deri {
class Thread : public ForwardListNode<Thread> {
 public:
  enum class Id : unsigned {};
  enum class Priority : int8_t {
    HIGHEST = -100,
    HIGH = -50,
    NORMAL = 0,
    LOW = 50,
    LOWEST = 100,
    IDLE = 127,
  };
  enum class Status {
    WAITING,
    RUNNING,
    BLOCKED,
    // TODO: MUTEX_WAIT etc
  };

  Thread(std::span<std::byte> stack,
         Priority priority,
         uintptr_t initial_pc,
         std::span<const char> name)
      : id{next_thread_id++},
        priority{priority},
        stack_area(stack),
        name{name} {
    saved_context.setProgramCounter(initial_pc);
    saved_context.setStackPointer(stack_area);
  }

  [[nodiscard]] static Thread &create(std::span<std::byte> stack,
                                      Priority priority,
                                      uintptr_t initial_pc,
                                      std::span<const char> name) {
    // put the TCB at the beginning of the stack space
    auto aligned_stack = span_align(stack, 4);
    void *tcb_address = aligned_stack.data();
    // advance the stack
    aligned_stack = aligned_stack.last(stack.size() - sizeof(Thread));
    Thread &thread =
        *new (tcb_address) Thread(aligned_stack, priority, initial_pc, name);

    return thread;
  }

  template <typename Function>
  [[nodiscard]] static Thread &create(std::span<std::byte> stack,
                                      Priority priority,
                                      Function entry_point,
                                      std::span<const char> name) {
    return create(
        stack, priority, reinterpret_cast<uintptr_t>(entry_point), name);
  }

  void start();

  void yield();

  void setPriority(Priority new_priority) { priority = new_priority; }

  template <class Compare = std::less<>>
  class PriorityCompare {
   public:
    constexpr bool operator()(const Thread &lhs, const Thread &rhs) const {
      return compare(lhs.priority, rhs.priority);
    }

   private:
    Compare compare{};
  };

  arch::SavedContext *context() { return &saved_context; }

 private:
  arch::SavedContext saved_context{};
  Priority priority{};
  Status status{};
  Id id{};
  std::span<std::byte> stack_area{};
  std::span<const char> name{};

  inline static std::atomic<unsigned> next_thread_id{};
};

class Scheduler {
 public:
  static Thread *run();
  static void request_run();
  static void enqueue(Thread &thread) { run_queue.push(thread); }
  [[noreturn]] static void init();
  static void yield(Thread &thread) {
    run_queue.push(thread, Thread::PriorityCompare<std::less_equal<>>());
  }

 private:
  inline static OrderedForwardList<Thread, Thread::PriorityCompare<>>
      run_queue{};
};
}  // namespace deri
