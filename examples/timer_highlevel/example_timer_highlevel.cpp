/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/log.hpp"
#include "deri/soc/gpio_dev.hpp"
#include "deri/time.hpp"

#include <algorithm>
#include <array>
#include <chrono>

using namespace std::literals;

namespace config = deri::bsp::config;

namespace log {
struct Example;
}

using Logger = deri::log::Logger<log::Example>;

using Timer = deri::SystemTimer;
using GpioOut = deri::soc::GpioOut;
using GpioManager = deri::soc::GpioManager;
static std::array<GpioOut, config::leds.size()> led_gpios;

void buttonCallback(uintptr_t id) {
  auto now = Timer::now().time_since_epoch();
  long now_ticks = now.count();
  auto now_ms(std::chrono::duration_cast<std::chrono::milliseconds>(now));
  Logger::print("Callback for button %u at time %ld ms (%ld ticks)\n",
                 static_cast<unsigned>(id),
                 static_cast<long>(now_ms.count()),
                 now_ticks);
}

void initLeds() {
  std::transform(
      begin(config::leds),
      end(config::leds),
      begin(led_gpios),
      [](const auto &led) { return deri::soc::gpio.initOutGpio(led); });
}

void initButtons() {
  uintptr_t arg = 0;
  for (auto &&button : config::buttons) {
    deri::soc::gpio.initInput(button);
    deri::soc::gpio.setInterruptHandler(button.gpio,
                                        GpioManager::Trigger::RISING,
                                        [arg] { buttonCallback(arg); });
    GpioManager::enableInterrupt(button.gpio);
    ++arg;
  }
}

struct ScheduledLed : public Timer::Schedulable {
  GpioOut led{};
  Timer::TimerManager::Count timeout{};
  Timer::TimerManager::Count last_event{};
  inline static std::atomic_uint num_updates{0};
};

static std::array<ScheduledLed, config::leds.size()> schedulables;

void timerCallback(Timer::TimerManager &timer,
                   Timer::Schedulable &schedulable,
                   uintptr_t arg) {
  auto led_schedule = reinterpret_cast<ScheduledLed *>(arg);
  led_schedule->led.toggle();
  led_schedule->last_event = Timer::now().time_since_epoch().count();
  schedulable.target += led_schedule->timeout;
  timer.schedule(schedulable);
  ++ScheduledLed::num_updates;
}

void initTimers() {
  auto arg = 0;
  auto timeout_prev = 1;
  auto timeout = 1;
  auto base = Timer::now().time_since_epoch().count();

  for (auto &&schedulable : schedulables) {
    // Fibonacci series of timer durations
    auto tmp = timeout;
    timeout += timeout_prev;
    timeout_prev = tmp;
    schedulable.led = led_gpios[arg++];
    schedulable.timeout = Timer::count(timeout * 250ms);
    schedulable.callback = [&schedulable](Timer::TimerManager &timer,
                                          Timer::Schedulable &) {
      schedulable.led.toggle();
      schedulable.last_event = Timer::now().time_since_epoch().count();
      schedulable.target += schedulable.timeout;
      timer.schedule(schedulable);
      ++ScheduledLed::num_updates;
    };
    schedulable.target = schedulable.timeout + base;
    Timer::schedule(schedulable);
  }
}

int main() {
  Logger::print("High level timer example\n");
  Logger::print("Each timer tick is %ld / %ld seconds\n",
                 static_cast<long>(Timer::period::num),
                 static_cast<long>(Timer::period::den));
  initLeds();
  initButtons();
  initTimers();

  while (1) {
    while (ScheduledLed::num_updates < 31) {
      asm volatile("" ::: "memory");
    }
    unsigned num_updates = ScheduledLed::num_updates.exchange(0);
    Logger::print("after %4u updates: %ld: %10ld %ld: %10ld %ld: %10ld\n",
                   num_updates,
                   static_cast<long>(schedulables[0].timeout),
                   static_cast<long>(schedulables[0].last_event),
                   static_cast<long>(schedulables[1].timeout),
                   static_cast<long>(schedulables[1].last_event),
                   static_cast<long>(schedulables[2].timeout),
                   static_cast<long>(schedulables[2].last_event));
  }
  return 0;
}
