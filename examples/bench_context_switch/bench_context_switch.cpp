/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/span_literals.hpp"
#include "deri/thread.hpp"
#include "deri/time.hpp"

#include <array>
#include <atomic>
#include <chrono>
#include <cstddef>

#include <stdio.h>

using namespace std::literals;

using namespace deri::literals;

class BenchContextSwitch {
  inline static volatile std::atomic_ulong count{};

 public:
  [[noreturn]] static void countThread() {
    while (true) {
      deri::Scheduler::yield();
      ++count;
    }
  }
  static void printEvent(deri::SystemTimer::TimerManager &timer,
                         deri::SystemTimer::Schedulable &schedulable,
                         uintptr_t /* arg */) {
    static auto last_update = deri::HighResolutionTimer::now();
    auto now = deri::HighResolutionTimer::now();
    auto interval = now - last_update;
    auto interval_us(
        std::chrono::duration_cast<std::chrono::microseconds>(interval));

    printf("%lu context switches in %ld us\n",
           count.load(),
           static_cast<long>(interval_us.count()));
    last_update = deri::HighResolutionTimer::now();
    count.store(0);
    schedulable.target =
        (deri::HighResolutionTimer::now() + 1000ms).time_since_epoch().count();
    timer.schedule(schedulable);
  }
};

void initThreads() {
  static std::array<std::array<std::byte, 2048>, 2> stacks;
  using deri::Thread;
  for (auto &&stack : stacks) {
    auto &thread = Thread::create(std::span(stack),
                                  Thread::Priority::HIGH,
                                  "switcher"_span,
                                  BenchContextSwitch::countThread);
    thread.start();
  }
}

void initTimer() {
  static deri::SystemTimer::Schedulable print_event{
      .target = deri::SystemTimer::now().time_since_epoch().count(),
      .callback = {.func = BenchContextSwitch::printEvent},
  };
  deri::SystemTimer::schedule(print_event);
}

int main() {
  puts("Context switch benchmark");

  initTimer();
  initThreads();
  deri::Scheduler::yield();
  while (true) {
    // NB: the other threads have a higher priority than main, we should not end
    // up here.
    asm volatile("ebreak" ::: "memory");
  }
  return 0;
}
