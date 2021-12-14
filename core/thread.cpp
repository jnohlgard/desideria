/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/thread.hpp"

#include "deri/arch/syscall.hpp"
#include "deri/idle.hpp"
#include "deri/irq.hpp"
#include "deri/span_literals.hpp"

extern "C" {
// defined in linker script:
extern std::byte _main_stack_start[];
extern std::byte _main_stack_end[];

int main();
}

namespace deri {

void Thread::start() { Scheduler::yield(*this); }

void Thread::block(Status blocked_status) {
  status = blocked_status;
  Scheduler::block(*this);
}

void Thread::unblock() {
  status = Status::WAITING;
  Scheduler::yield(*this);
}

void Scheduler::init() {
  using namespace deri::literals;

  // Start the idle thread
  IdleThread::init();

  // Start the main thread
  auto &main_thread =
      Thread::create(std::span(_main_stack_start, _main_stack_end),
                     Thread::Priority::NORMAL,
                     "main"_span,
                     main);
  main_thread.start();

  // Enable interrupts globally
  arch::irqEnable();

  // Switch to the main thread
  arch::syscall(Syscall::SCHEDULER_UPDATE);

  // we will never return here.
  __builtin_unreachable();
}

void Scheduler::yield(Thread &thread) {
  arch::CriticalSection cs{};
  run_queue.remove(thread);
  run_queue.push(thread);
}

void Scheduler::block(Thread &thread) {
  arch::CriticalSection cs{};
  run_queue.remove(thread);
}

void Scheduler::yield() {
  arch::CriticalSection cs{};
  auto &current_thread = activeThread();
  run_queue.pop();
  run_queue.push(current_thread);
  update();
}

}  // namespace deri
