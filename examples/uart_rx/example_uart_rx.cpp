/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp/console.hpp"
#include "deri/mutex.hpp"
#include "deri/ring_buffer.hpp"

#include <cstddef>

#include <stdio.h>

deri::Mutex rx_signal{};

deri::RingBuffer<std::byte, 16> rx_buffer;

void onUartRx(std::byte data, uintptr_t) {
  if (rx_buffer.put(data)) {
    rx_signal.unlock();
  }
}

int main() {
  puts("UART RX tester");
  puts("Anything received over this UART will be reported back");

  deri::bsp::console().setRxCallback({onUartRx});

  rx_signal.lock();
  while (true) {
    rx_signal.lock();
    while (auto data = rx_buffer.get()) {
      printf("RX: %02x '%c'\n",
             static_cast<unsigned>(*data),
             static_cast<char>(*data));
    }
  }
  return 0;
}
