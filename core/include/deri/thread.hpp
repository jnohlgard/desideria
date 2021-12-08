/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/arch/syscall.hpp"
#include "deri/arch/thread.hpp"
#include "deri/list.hpp"
#include "deri/span_align.hpp"
#include "deri/syscall.hpp"

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

  Thread(const Thread &) = delete;
  Thread &operator=(const Thread &) = delete;

  Thread(std::span<std::byte> stack,
         Priority priority,
         std::span<const char> name,
         uintptr_t initial_pc)
      : priority{priority},
        id{next_thread_id++},
        stack_area(stack),
        name{name} {
    saved_context.setProgramCounter(initial_pc);
    saved_context.setStackPointer(stack_area);
  }

  [[nodiscard]] static Thread &create(std::span<std::byte> stack,
                                      Priority priority,
                                      std::span<const char> name,
                                      uintptr_t initial_pc) {
    // put the TCB at the beginning of the stack space
    auto aligned_stack = span_align(stack, 4);
    void *tcb_address = aligned_stack.data();
    // advance the stack
    aligned_stack = aligned_stack.last(stack.size() - sizeof(Thread));
    Thread &thread =
        *new (tcb_address) Thread(aligned_stack, priority, name, initial_pc);

    return thread;
  }

  template <typename Function>
  [[nodiscard]] static Thread &create(std::span<std::byte> stack,
                                      Priority priority,
                                      std::span<const char> name,
                                      Function *entry_point) {
    return create(
        stack, priority, name, reinterpret_cast<uintptr_t>(entry_point));
  }

  template <typename Object>
  [[nodiscard]] static Thread &create(std::span<std::byte> stack,
                                      Priority priority,
                                      std::span<const char> name,
                                      void (*static_invoker)(Object &),
                                      Object &object) {
    auto &thread = create(stack, priority, name, static_invoker);
    thread.context().setArg0(&object);
    return thread;
  }

  void start();

  void yield();

  void setPriority(Priority new_priority) { priority = new_priority; }

  template <class Compare = std::less_equal<>>
  class PriorityCompare {
   public:
    constexpr bool operator()(const Thread &lhs, const Thread &rhs) const {
      return compare(lhs.priority, rhs.priority);
    }

   private:
    [[no_unique_address]] Compare compare{};
  };

  arch::SavedContext &context() { return saved_context; }

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
  static Thread *run() { return &run_queue.front(); }
  static void request_run();
  [[noreturn]] static void init();
  static void yield(Thread &thread) {
    run_queue.remove(thread);
    run_queue.push(thread);
  }
  static void yield() {
    auto &current_thread = run_queue.front();
    run_queue.pop();
    run_queue.push(current_thread);
    arch::syscall(Syscall::SCHEDULER_UPDATE);
  }

 private:
  inline static OrderedForwardList<Thread,
                                   Thread::PriorityCompare<std::less_equal<>>>
      run_queue{};
};

}  // namespace deri
