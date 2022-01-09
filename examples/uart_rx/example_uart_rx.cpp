/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.hpp"
#include "deri/log.hpp"
#include "deri/mutex.hpp"
#include "deri/ring_buffer.hpp"

#include <cstddef>

namespace log {
struct Example;
}  // namespace log

using Logger = deri::log::Logger<log::Example>;

deri::Mutex rx_signal{};

deri::RingBuffer<std::byte, 16> rx_buffer;

void onUartRx(std::byte data) {
  if (rx_buffer.put(data)) {
    rx_signal.unlock();
  }
}

int main() {
  Logger::printf("UART RX tester\n");
  Logger::printf("Anything received over this UART will be reported back\n");

  deri::bsp::console().setRxCallback(onUartRx);

  rx_signal.lock();
  while (true) {
    rx_signal.lock();
    while (auto data = rx_buffer.get()) {
      Logger::printf("RX: %02x '%c'\n",
                     static_cast<unsigned>(*data),
                     static_cast<char>(*data));
    }
  }
  return 0;
}
