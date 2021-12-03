/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/timer.hpp"
#include "deri/irq.hpp"
#include "deri/list.hpp"

#include <atomic>
#include <chrono>
#include <cstdint>

namespace deri::dev {

template <class TimerDeviceType, typename CountType = std::int64_t>
class TimerManager {
 public:
  using TimerDevice = TimerDeviceType;
  using TimerDriver = timer::TimerDriver<TimerDevice>;
  using Count = CountType;
  using LowerCount = uint32_t;
  enum class Frequency : unsigned long;
  struct Schedulable;
  using TimerCallback =
      Callback<void(TimerManager &, Schedulable &, uintptr_t)>;
  static constexpr auto num_channels = TimerDriver::num_channels;

  struct Schedulable : public ForwardListNode<Schedulable> {
    Count target{};
    TimerCallback callback{};

    auto operator<=>(const Schedulable &other) const {
      return target <=> other.target;
    }
    auto operator<=>(Count other) const { return target <=> other; }
    bool operator==(const Schedulable &other) const = delete;
  };

  explicit TimerManager(TimerDriver &timer, Frequency tick_rate_hz)
      : timer{&timer}, tick_rate_hz{tick_rate_hz} {}
  TimerManager() = default;
  TimerManager(const TimerManager &) = default;
  TimerManager &operator=(TimerManager &&rhs) noexcept {
    if (this == &rhs) {
      return *this;
    }
    timer = rhs.timer;
    tick_rate_hz = rhs.tick_rate_hz;
    queue = std::move(rhs.queue);
    count.store(rhs.count.load());
    return *this;
  }

  void init() {
    arch::CriticalSection cs;
    timer->setPeriod(
        static_cast<typename TimerDriver::Count>(TimerDriver::max_value));
    timer->setCompareHandler(typename TimerDriver::Channel{0},
                             {[](auto, uintptr_t arg) {
                                auto *self =
                                    reinterpret_cast<decltype(this)>(arg);
                                auto now = self->read();
                                self->update(now);
                              },
                              reinterpret_cast<uintptr_t>(this)});
    timer->start();
    auto now = read();
    update(now);
  }

  Count read() {
    auto now_lower = read_lower();
    if (now_lower < checkpoint) {
      // Counter wrapped around, update long count
      count += static_cast<Count>(TimerDriver::max_value) + 1;
    }
    checkpoint = now_lower;
    return count + now_lower;
  }

  void schedule(Schedulable &schedulable) {
    arch::CriticalSection cs;
    queue.remove(schedulable);
    auto now = read();
    queue.push(schedulable);
    update(now);
  }

 private:
  static constexpr auto checkpoint_step = TimerDriver::max_value / 2;

  LowerCount read_lower() const {
    return static_cast<LowerCount>(timer->read());
  }
  void update(Count now) {
    arch::CriticalSection cs;
    if (in_update) {
      return;
    }
    in_update = true;

    // pop periodic_update from list
    queue.remove(periodic_update);

    while (!queue.empty()) {
      auto &scheduled = queue.front();
      if (scheduled > now) {
        break;
      }
      // Remove expired timer, run callback
      queue.pop();
      scheduled.callback.func(*this, scheduled, scheduled.callback.arg);
    }

    // insert periodic_update into list
    now = read();
    periodic_update.target = now + checkpoint_step;
    queue.push(periodic_update);

    auto lower_target = queue.front().target - count;
    if (queue.front().target + 100 < now) {
      lower_target = read_lower() + 100;
    }
    timer->setCompare(typename TimerDriver::Channel{0},
                      typename TimerDriver::Count(lower_target));
    in_update = false;
  }

  TimerDriver *timer{nullptr};
  OrderedForwardList<Schedulable> queue{};
  Frequency tick_rate_hz{};
  LowerCount checkpoint{};
  std::atomic<Count> count{0};
  Schedulable periodic_update{
      .callback =
          {
              .func = [](TimerManager &,
                         Schedulable &,
                         uintptr_t) { /* no-op to trigger an update */ },
          },
  };
  bool in_update{false};
};
}  // namespace deri::dev
