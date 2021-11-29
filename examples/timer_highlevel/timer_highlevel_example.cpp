/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/console.hpp"
#include "deri/time.hpp"

#include <algorithm>
#include <array>

#include <stdio.h>

using deri::console;

namespace config {
using namespace deri::bsp::config;
}

using GpioOut = deri::dev::gpio::GpioOutGd32;
using GpioManager = deri::dev::gpio::GpioManagerGd32;
static std::array<GpioOut, config::leds.size()> led_gpios;

void buttonCallback(uintptr_t id) {
  auto now = deri::SystemTimer::now().time_since_epoch();
  long now_ticks = now.count();
  auto now_ms(std::chrono::duration_cast<std::chrono::milliseconds>(now));
  printf("Callback for button %u at time %ld ms (%ld ticks)\n",
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
    deri::soc::gpio.setInterruptHandler(
        button.gpio,
        GpioManager::Edge::RISING,
        {.func = &buttonCallback, .arg = arg++});
    GpioManager::enableInterrupt(button.gpio);
  }
}

struct ScheduledLed : public deri::SystemTimer::Schedulable {
  GpioOut led{};
  deri::SystemTimer::TimerManager::Count timeout{};
};

static std::array<ScheduledLed, config::leds.size()> schedulables;

void timerCallback(deri::SystemTimer::TimerManager &timer,
                   deri::SystemTimer::Schedulable &schedulable,
                   uintptr_t arg) {
  auto led_schedule = reinterpret_cast<ScheduledLed *>(arg);
  led_schedule->led.toggle();
  schedulable.target = led_schedule->timeout +
                       deri::SystemTimer::now().time_since_epoch().count();
  timer.schedule(schedulable);
}

void initTimers() {
  auto arg = 0;
  auto timeout_prev = 1;
  auto timeout = 1;
  auto base = deri::SystemTimer::now().time_since_epoch().count();

  for (auto &&schedulable : schedulables) {
    auto tmp = timeout;
    timeout += timeout_prev;
    timeout_prev = tmp;
    schedulable.led = led_gpios[arg++];
    schedulable.timeout = timeout * 250000;
    schedulable.callback.arg = reinterpret_cast<uintptr_t>(&schedulable);
    schedulable.callback.func = timerCallback;
    schedulable.target = schedulable.timeout + base;
    deri::SystemTimer::schedule(schedulable);
  }
}

int main() {
  puts("High level timer example");
  printf("Each timer tick is %ld / %ld seconds\n",
         static_cast<long>(deri::SystemTimer::period::num),
         static_cast<long>(deri::SystemTimer::period::den));
  initLeds();
  initButtons();
  initTimers();

  while (1) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
