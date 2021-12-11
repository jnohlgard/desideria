/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/arch/perf.hpp"
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
      ++count;
      deri::Scheduler::yield();
    }
  }
  static void printEvent(deri::SystemTimer::TimerManager &timer,
                         deri::SystemTimer::Schedulable &schedulable,
                         uintptr_t /* arg */) {
    static auto last_cycles = deri::arch::Perf::cycles();
    static auto last_inst = deri::arch::Perf::instructionsRetired();
    static auto last_update = deri::HighResolutionTimer::now();
    auto now_cycles = deri::arch::Perf::cycles();
    auto now_inst = deri::arch::Perf::instructionsRetired();
    auto now = deri::HighResolutionTimer::now();
    auto interval = now - last_update;
    auto interval_us(
        std::chrono::duration_cast<std::chrono::microseconds>(interval));
    long cycles_diff = now_cycles - last_cycles;
    long inst_diff = now_inst - last_inst;
    auto count_now = count.load();
    long cycles_per_count = cycles_diff / count_now;
    long inst_per_count = inst_diff / count_now;

    printf(
        "%lu context switches in %ld us (%ld core cycles, %ld instructions). "
        "%ld cycles per "
        "switch, %ld instructions per switch\n",
        count_now,
        static_cast<long>(interval_us.count()),
        cycles_diff,
        inst_diff,
        cycles_per_count,
        inst_per_count);
    last_update = deri::HighResolutionTimer::now();
    last_cycles = deri::arch::Perf::cycles();
    last_inst = deri::arch::Perf::instructionsRetired();
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
