/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/console.hpp"
#include "deri/soc/timer_dev.hpp"

#include <algorithm>
#include <array>

#include <stdio.h>

using deri::console;

namespace config {
using namespace deri::bsp::config;
}

static auto &timer_config = deri::soc::timer_config[0];
static auto &timer = deri::soc::timers[0];
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

void initTimer() {
  auto &driver = timer_config.init();
  driver.underlyingTimer().setPrescaler(
      deri::dev::timer::TimerGd32::Count{8000u - 1});
  driver.setPeriod(deri::soc::TimerDriver::Count{500u - 1});
  driver.setPeriodHandler({.func = [](uintptr_t) {
    static unsigned led_active = 0;
    led_gpios[led_active].clear();
    ++led_active;
    if (led_active >= led_gpios.size()) {
      led_active = 0;
    }
    led_gpios[led_active].set();
  }});
  driver.start();
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
