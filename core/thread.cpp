/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/thread.hpp"

#include "deri/arch/irq.hpp"
#include "deri/arch/syscall.hpp"
#include "deri/span_literals.hpp"

extern "C" {
extern std::byte _main_stack_start[];
extern std::byte _main_stack_end[];

int main();
}

extern "C" {
void deri_restore_context(deri::arch::SavedContext *);
}

namespace deri {

namespace {
std::array<std::byte, deri::arch::idle_stack_size> idle_stack;
[[noreturn]] int idle_loop() {
  while (true) {
    arch::wait_for_interrupt();
  }
}
}  // namespace

void Scheduler::init() {
  using namespace deri::literals;
  auto &idle_thread = Thread::create(
      std::span(idle_stack), Thread::Priority::IDLE, "idle"_span, idle_loop);
  idle_thread.start();

  auto &main_thread =
      Thread::create(std::span(_main_stack_start, _main_stack_end),
                     Thread::Priority::NORMAL,
                     "main"_span,
                     main);
  main_thread.start();
  // Switch to the main thread
  arch::syscall(Syscall::SCHEDULER_UPDATE);
  // we will never return here.
  __builtin_unreachable();
}

void Thread::start() { Scheduler::yield(*this); }
}  // namespace deri
