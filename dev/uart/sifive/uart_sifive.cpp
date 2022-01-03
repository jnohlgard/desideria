/*
 * Copyright (C) 2020-2022 Joakim Nohlgård <joakim@nohlgard.se>
 */

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

void UartSiFive::enableRxInterrupt() {
  using ie_bits = mmio::UART_regs::ie_bits;
  using rxctrl_bits = mmio::UART_regs::rxctrl_bits;
  // Enable receiver and RX interrupt
  UART.ie |= ie_bits::rxwm;
  UART.rxctrl |= rxctrl_bits::enable;
}

void UartSiFive::disableRxInterrupt() {
  using ie_bits = mmio::UART_regs::ie_bits;
  using rxctrl_bits = mmio::UART_regs::rxctrl_bits;
  // Disable receiver and RX interrupt
  UART.ie &= ~ie_bits::rxwm;
  UART.rxctrl &= ~rxctrl_bits::enable;
}
bool UartSiFive::checkAndClearTxIrq() {
  using ie_bits = mmio::UART_regs::ie_bits;
  using ip_bits = mmio::UART_regs::ip_bits;
  auto ip = static_cast<uint32_t>(UART.ip.load());
  auto ie = static_cast<uint32_t>(UART.ie.load());
  if (!!(static_cast<ip_bits>(ip & ie) & ip_bits::txwm)) {
    // Disable transmit buffer empty IRQ to avoid an infinite interrupt loop
    UART.ie &= ~ie_bits::txwm;
    return true;
  }
  return false;
}

void UartSiFive::enableTxBufferAvailableInterrupt() {
  enableTxCompleteInterrupt();
}

void UartSiFive::enableTxCompleteInterrupt() {
  using ie_bits = mmio::UART_regs::ie_bits;
  using txctrl_bits = mmio::UART_regs::txctrl_bits;
  using txctrl_shift = mmio::UART_regs::txctrl_shift;
  // Set TX watermark level to 1 (trigger interrupt when hardware TX buffer
  // contains <1 byte)
  auto txctrl = UART.txctrl.load();
  txctrl &= ~txctrl_bits::counter_mask;
  txctrl |=
      maskedBitsFromValue(1u, txctrl_bits::counter_mask, txctrl_shift::counter);
  UART.txctrl.store(txctrl);
  // Enable TX watermark IRQ
  UART.ie |= ie_bits::txwm;
}

void UartSiFive::disableTxInterrupts() {
  using ie_bits = mmio::UART_regs::ie_bits;
  UART.ie &= ~ie_bits::txwm;
}

}  // namespace deri::dev::uart
