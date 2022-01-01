#include "deri/dev/uart_sifive.hpp"

#include "deri/mmio/UART.hpp"
#include "deri/mmio/bits/UART_bits.hpp"

#include <cstdint>

namespace deri::dev::uart {

void UartSiFive::init() {
  // disable interrupts
  UART.ie.store({});
  UART.txctrl.store(mmio::UART_regs::txctrl_bits::enable);
}

auto UartSiFive::tryWrite(std::span<const std::byte> buffer)
    -> decltype(buffer) {
  while (!buffer.empty() &&
         !UART.txdata.fetch_or(mmio::UART_regs::txdata_bits{buffer.front()})) {
    buffer = buffer.last(buffer.size() - 1);
  }

  return buffer;
}

void UartSiFive::setBaud(unsigned int pclk, unsigned int baudrate) {
  if (pclk == 0) {
    // Avoid division by 0
    return;
  }
  auto div = pclk / baudrate - 1;
  UART.div.store(mmio::UART_regs::div_bits{div});
}
std::optional<std::byte> UartSiFive::getRxByte() {
  auto rx = UART.rxdata.load();
  if (static_cast<uint32_t>(rx) > 0xffu) {
    return std::nullopt;
  }
  return static_cast<std::byte>(rx);
}

}  // namespace deri::dev::uart
