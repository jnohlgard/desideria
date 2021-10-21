#include "deri/dev/uart_sifive.h"

namespace deri::dev::uart {

void UartSiFive::init() {
  // disable interrupts
  ie = 0;
  // set divisor
  div = 0;
  // enable transmitter
  txctrl = static_cast<std::uint32_t>(txctrl_mask::txen);
}

auto UartSiFive::write(std::span<const std::byte> buffer) -> decltype(buffer) {
  while (!buffer.empty() &&
      txdata.fetch_or(static_cast<std::uint32_t>(buffer.front())) == 0) {
    buffer = buffer.last(buffer.size() - 1);
  }

  return buffer;
}

}  // namespace deri::dev::uart
