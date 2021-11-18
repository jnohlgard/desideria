/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/devices.h"
#include "deri/console.h"
#include "deri/soc/gpio_dev.h"
#include "deri/span_literals.h"

#include <span>

#include <stdio.h>

using deri::console;
using namespace deri::literals;

void buttonCallback(uintptr_t id) {
  printf("Callback for button %u\n", static_cast<unsigned>(id));
}

void initLeds() {
  for (auto &&led : deri::bsp::leds) {
    deri::soc::gpio.initOutGpio(led);
    auto &led0_port = deri::soc::gpioPortDev(led);
    led0_port.set(led.pin);
  }
}

void initButtons() {
  uintptr_t arg = 0;
  for (auto &&button : deri::bsp::buttons) {
    deri::soc::gpio.initInput(button);
    deri::soc::gpio.setInterruptHandler(
        button,
        deri::dev::gpio::GpioManagerGd32::Edge::RISING,
        {.func = &buttonCallback, .arg = arg++});
    deri::soc::gpio.enableInterrupt(button);
  }
}

int main() {
  puts("Buttons and LEDs example\n");
  initLeds();
  initButtons();

  while (1) {
    asm volatile("" ::: "memory");
  }
  return 0;
}
