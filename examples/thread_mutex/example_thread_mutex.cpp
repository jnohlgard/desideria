/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/config.hpp"
#include "deri/console.hpp"
#include "deri/mutex.hpp"
#include "deri/span_literals.hpp"
#include "deri/thread.hpp"

#include <algorithm>
#include <array>
#include <span>

#include <stdio.h>

using deri::console;
using namespace deri::literals;

namespace config {
using namespace deri::bsp::config;
}

using GpioOut = deri::dev::gpio::GpioOutGd32;
using GpioManager = deri::dev::gpio::GpioManagerGd32;
static std::array<GpioOut, config::leds.size()> led_gpios;

struct ConsumerThread {
  inline static deri::Mutex mutex{};
  std::array<std::byte, 2048> stack{};
  unsigned id{};

  [[noreturn]] static void loop(ConsumerThread &self) {
    while (true) {
      mutex.lock();
      led_gpios[self.id % led_gpios.size()].toggle();
      printf("Mutex consumer %u activated.\n", self.id);
    }
  }
  static ConsumerThread &instance(unsigned index) {
    static std::array<ConsumerThread, 4> instances;
    return instances[index];
  }
  static void callback(uintptr_t id) {
    printf("Callback for button %u\n", static_cast<unsigned>(id));
    mutex.unlock();
  }
};

void initLeds() {
  std::transform(begin(config::leds),
                 end(config::leds),
                 begin(led_gpios),
                 [](const auto &led) {
                   auto gpio = deri::soc::gpio.initOutGpio(led);
                   gpio.clear();
                   return gpio;
                 });
}

void initButtons() {
  uintptr_t arg = 0;
  for (auto &&button : config::buttons) {
    deri::soc::gpio.initInput(button);
    deri::soc::gpio.setInterruptHandler(
        button.gpio,
        GpioManager::Edge::RISING,
        {.func = &ConsumerThread::callback, .arg = arg++});
    GpioManager::enableInterrupt(button.gpio);
  }
}

void initThreads() {
  using deri::Thread;
  for (auto k = 0; k < 4; ++k) {
    auto &consumer = ConsumerThread::instance(k);
    consumer.id = k;
    printf("Starting consumer thread %u\n", consumer.id);
    auto &thread = Thread::create(std::span(consumer.stack),
                                  Thread::Priority::NORMAL,
                                  "consumer"_span,
                                  ConsumerThread::loop,
                                  consumer);
    thread.start();
  }
}

int main() {
  puts("Thread mutex example");
  printf("Press any button to switch threads\n");
  // Begin with the mutex locked
  ConsumerThread::mutex.lock();
  initLeds();
  initThreads();
  initButtons();
  deri::Scheduler::activeThread().block();
  deri::Scheduler::update();
  while (true) {
    deri::Scheduler::yield();
    asm volatile("" ::: "memory");
  }
  return 0;
}
