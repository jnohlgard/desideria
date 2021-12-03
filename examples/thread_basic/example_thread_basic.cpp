/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/console.hpp"

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
  printf("Callback for button %u\n", static_cast<unsigned>(id));
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

int main() {
  puts("Thread example");
  printf("Press any button to switch threads\n");
  initLeds();
  initButtons();

  while (1) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
