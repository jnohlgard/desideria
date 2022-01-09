/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/arch/irq.hpp"
#include "deri/arch/perf.hpp"
#include "deri/log.hpp"
#include "deri/span_literals.hpp"
#include "deri/thread.hpp"
#include "deri/time.hpp"

#include <array>
#include <atomic>
#include <chrono>
#include <cstddef>

namespace log {
struct Example {
  static constexpr auto level = deri::log::Level::INFO;
};
}  // namespace log
using Logger = deri::log::Logger<log::Example>;
using namespace std::literals;

using namespace deri::literals;

class BenchContextSwitch {
  inline static volatile std::atomic_ulong count{1};

 public:
  [[noreturn]] static void countThread() {
    while (true) {
      ++count;
      deri::Scheduler::yield();
    }
  }
  static void printEvent(deri::HighResolutionTimer::TimerManager &timer,
                         deri::HighResolutionTimer::Schedulable &schedulable) {
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

    Logger::printf(
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
    count.store(1);
    ++iterations;
    schedulable.target = deri::HighResolutionTimer::count(
        deri::HighResolutionTimer::now() + 1000ms);
    timer.schedule(schedulable);
  }
  static inline unsigned iterations{};
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
  static deri::HighResolutionTimer::Schedulable print_event{
      .target = deri::HighResolutionTimer::count(
          deri::HighResolutionTimer::now() + 1000ms),
      .callback = BenchContextSwitch::printEvent,
  };
  Logger::printf("Initial timer target = %lld, now = %lld\n",
                 print_event.target,
                 deri::HighResolutionTimer::now().time_since_epoch().count());
  deri::HighResolutionTimer::schedule(print_event);
}

void baseline() {
  static constexpr long unsigned baseline_count = 50000u;
  Logger::printf("Testing %lu no-op context switches as baseline\n",
                 baseline_count);
  auto last_update = deri::HighResolutionTimer::now();
  auto last_cycles = deri::arch::Perf::cycles();
  auto last_inst = deri::arch::Perf::instructionsRetired();
  for (auto k = 0; k < baseline_count; ++k) {
    asm volatile("" ::: "memory");
    deri::Scheduler::yield();
    asm volatile("" ::: "memory");
  }
  auto now_cycles = deri::arch::Perf::cycles();
  auto now_inst = deri::arch::Perf::instructionsRetired();
  auto now = deri::HighResolutionTimer::now();
  auto interval = now - last_update;
  auto interval_us(
      std::chrono::duration_cast<std::chrono::microseconds>(interval));
  long cycles_diff = now_cycles - last_cycles;
  long inst_diff = now_inst - last_inst;
  auto cycles_per_count = cycles_diff / baseline_count;
  auto inst_per_count = inst_diff / baseline_count;
  Logger::printf(
      "%lu no-op context switches in %ld us (%ld core cycles, %ld "
      "instructions). %lu cycles per switch, %lu instructions per switch\n",
      baseline_count,
      static_cast<long>(interval_us.count()),
      cycles_diff,
      inst_diff,
      cycles_per_count,
      inst_per_count);
}

void measureTimer() {
  unsigned wakeups{};
  while (BenchContextSwitch::iterations < 2) {
    deri::arch::waitForInterrupt();
    ++wakeups;
  }
  Logger::printf("%u wakeups during idle\n", wakeups);
}

int main() {
  Logger::printf("Context switch benchmark\n");
  Logger::printf("HighResolutionTimer resolution: %lld ticks in 1000ms\n",
                 deri::HighResolutionTimer::count(1000ms));
  baseline();
  Logger::printf(
      "measure twice without switching to get timer instruction overhead\n");
  initTimer();
  measureTimer();
  Logger::printf("Start two threads to switch between\n");
  initThreads();
  deri::Scheduler::yield();
  while (true) {
    // NB: the other threads have a higher priority than main, we should not end
    // up here.
    asm volatile("ebreak" ::: "memory");
  }
  return 0;
}
