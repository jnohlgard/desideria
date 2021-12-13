/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/idle.hpp"

#include "deri/arch/irq.hpp"
#include "deri/span_literals.hpp"
#include "deri/thread.hpp"

#include <array>
#include <cstddef>

using namespace deri::literals;
namespace deri {

int IdleThread::loop() {
  while (true) {
    arch::wait_for_interrupt();
  }
}

void IdleThread::init() {
  static std::array<std::byte, deri::arch::idle_stack_size> idle_stack{};
  auto &thread = Thread::create(std::span(idle_stack),
                                Thread::Priority::IDLE,
                                "idle"_span,
                                IdleThread::loop);
  thread.start();
}
}  // namespace deri
