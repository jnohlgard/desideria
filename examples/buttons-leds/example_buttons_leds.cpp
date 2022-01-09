/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/soc/gpio_dev.hpp"

#include <cstdio>

void buttonCallback(unsigned id) { printf("Callback for button %u\n", id); }

void initLeds() {
  for (auto &&led : deri::bsp::config::leds) {
    auto gpio = deri::soc::gpio.initOutGpio(led);
    gpio.set();
  }
}

void initButtons() {
  uintptr_t arg = 0;
  for (auto &&button : deri::bsp::config::buttons) {
    deri::soc::gpio.initInput(button);
    deri::soc::gpio.setInterruptHandler(
        button.gpio, deri::dev::gpio::GpioInConfig::Trigger::RISING, [arg]() {
          buttonCallback(arg);
        });
    deri::soc::GpioManager::enableInterrupt(button.gpio);
    ++arg;
  }
}

int main() {
  puts("Buttons and LEDs example");
  initLeds();
  initButtons();

  while (1) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
