/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/soc/gpio_dev.hpp"

#include <stdio.h>

void buttonCallback(uintptr_t id) {
  printf("Callback for button %u\n", static_cast<unsigned>(id));
}

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
        button.gpio,
        deri::dev::gpio::GpioManagerGd32::Edge::RISING,
        {.func = &buttonCallback, .arg = arg++});
    deri::dev::gpio::GpioManagerGd32::enableInterrupt(button.gpio);
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
