/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.h"
#include "deri/console.h"
#include "deri/soc/timer_dev.h"

#include <array>
#include <algorithm>

#include <stdio.h>

using deri::console;

namespace config {
using namespace deri::bsp::config;
}

static auto &timer = deri::soc::timers[0];
using Timer = std::remove_cvref_t<decltype(timer)>;
using GpioOut = deri::dev::gpio::GpioOutGd32;
using GpioManager = deri::dev::gpio::GpioManagerGd32;
static std::array<GpioOut, config::leds.size()> led_gpios;

void buttonCallback(uintptr_t id) {
  printf("Callback for button %u at time %lu\n",
         static_cast<unsigned>(id),
         static_cast<unsigned long>(timer.read()));
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

static unsigned led_active = 0;

void initTimer() {
  timer.init();
  timer.underlyingTimer().setPrescaler(
      deri::dev::timer::TimerGd32::Prescaler{8000u - 1});
  timer.setPeriod(Timer::Count{500u - 1});
  timer.setPeriodHandler({.func = [](uintptr_t) {
    led_gpios[led_active % led_gpios.size()].clear();
    ++led_active;
    led_gpios[led_active % led_gpios.size()].set();
  }});
  timer.start();
}

int main() {
  puts("Timer example");
  initLeds();
  initButtons();
  initTimer();

  while (1) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
