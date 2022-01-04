/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/soc/timer_dev.hpp"

#include <algorithm>
#include <array>

#include <stdio.h>

namespace config {
using namespace deri::bsp::config;
}

static auto &timer = deri::soc::timer<0>();
using GpioOut = deri::soc::GpioOut;
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
        deri::dev::gpio::GpioInConfig::Trigger::RISING,
        {.func = &buttonCallback, .arg = arg++});
    deri::soc::GpioManager::enableInterrupt(button.gpio);
  }
}

void initTimer() {
  auto &driver = deri::soc::timer<0>();
  driver.setTickRateHz(1000);
  driver.setPeriod(std::remove_cvref_t<decltype(driver)>::Count{500u - 1});
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
  puts("Low level timer example");
  initLeds();
  initButtons();
  initTimer();

  while (true) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
