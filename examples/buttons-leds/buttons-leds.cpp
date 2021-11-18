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
  deri::soc::gpio.initOutGpio(deri::bsp::led0);
  auto &led0_port = deri::soc::gpioPortDev(deri::bsp::led0);
  led0_port.set(deri::bsp::led0.pin);
  deri::soc::gpio.initOutGpio(deri::bsp::led1);
  auto &led1_port = deri::soc::gpioPortDev(deri::bsp::led1);
  led1_port.clear(deri::bsp::led1.pin);
  deri::soc::gpio.initOutGpio(deri::bsp::led2);
  auto &led2_port = deri::soc::gpioPortDev(deri::bsp::led2);
  led2_port.set(deri::bsp::led2.pin);
}

void initButtons() {
  deri::soc::gpio.initInput(deri::bsp::button0);
  deri::soc::gpio.setInterruptHandler(
      deri::bsp::button0,
      deri::dev::gpio::GpioManagerGd32::Edge::RISING,
      {.func = &buttonCallback, .arg = 0});
  deri::soc::gpio.enableInterrupt(deri::bsp::button0);
  deri::soc::gpio.initInput(deri::bsp::button1);
  deri::soc::gpio.setInterruptHandler(
      deri::bsp::button1,
      deri::dev::gpio::GpioManagerGd32::Edge::FALLING,
      {.func = &buttonCallback, .arg = 1});
  deri::soc::gpio.enableInterrupt(deri::bsp::button1);
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
