/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/span_literals.hpp"
#include "deri/thread.hpp"

#include <algorithm>
#include <array>
#include <span>

#include <stdio.h>

using namespace deri::literals;

namespace config {
using namespace deri::bsp::config;
}

using GpioOut = deri::soc::GpioOut;
using GpioManager = deri::soc::GpioManager;
using GpioTrigger = deri::dev::gpio::GpioInConfig::Trigger;
static std::array<GpioOut, config::leds.size()> led_gpios;

struct ButtonThread {
  std::array<std::byte, 2048> stack{};
  volatile bool button{};
  unsigned id{};

  [[noreturn]] static void activate(ButtonThread &self) {
    while (true) {
      while (!self.button) {
        deri::Scheduler::yield();
      }
      self.button = false;
      led_gpios[self.id % led_gpios.size()].toggle();
      printf("Thread for button %u activated.\n", self.id);
    }
  }
  static ButtonThread &instance(unsigned index) {
    static std::array<ButtonThread, config::buttons.size()> instances;
    return instances[index];
  }
  static void callback(uintptr_t id) {
    printf("Callback for button %u\n", static_cast<unsigned>(id));
    instance(id).button = true;
  }
};

void initLeds() {
  std::transform(
      begin(config::leds),
      end(config::leds),
      begin(led_gpios),
      [](const auto &led) { return deri::soc::gpio.initOutGpio(led); });
}

void initButtons() {
  using deri::Thread;
  uintptr_t arg = 0;
  for (auto &&button : config::buttons) {
    auto &button_thread = ButtonThread::instance(arg);
    button_thread.id = arg;
    auto &thread = Thread::create(std::span(button_thread.stack),
                                  Thread::Priority::NORMAL,
                                  "button"_span,
                                  ButtonThread::activate,
                                  button_thread);
    thread.start();
    deri::soc::gpio.initInput(button);
    deri::soc::gpio.setInterruptHandler(
        button.gpio,
        GpioTrigger::RISING,
        {.func = &ButtonThread::callback, .arg = arg++});
    GpioManager::enableInterrupt(button.gpio);
  }
}

int main() {
  puts("Thread example");
  printf("Press any button to switch threads\n");
  initLeds();
  initButtons();

  while (true) {
    deri::Scheduler::yield();
    asm volatile("" ::: "memory");
  }
  return 0;
}
