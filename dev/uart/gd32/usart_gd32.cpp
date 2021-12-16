/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/arch/irq.hpp"
#include "deri/bitwise_enums.hpp"
#include "deri/dev/uart_gd32.hpp"
#include "deri/irq.hpp"
#include "deri/mmio/bits/USART_bits.hpp"

#include <mutex>

namespace deri::dev::uart {

using CTL0_bits = mmio::USART_regs::CTL0_bits;
using BAUD_bits = mmio::USART_regs::BAUD_bits;
using STAT_bits = mmio::USART_regs::STAT_bits;
using DATA_bits = mmio::USART_regs::DATA_bits;

void UsartGd32::init() {
  auto ctl0 = regs.CTL0.load();
  ctl0 &= CTL0_bits::Reserved_mask;
  ctl0 |= CTL0_bits::UEN;
  regs.CTL0.store(ctl0);
}

auto UsartGd32::tryWrite(std::span<const std::byte> buffer)
    -> decltype(buffer) {
  while (!buffer.empty() && regs.STAT.any(STAT_bits::TBE)) {
    regs.DATA.store(static_cast<DATA_bits>(buffer.front()));
    regs.CTL0 |= CTL0_bits::TEN;
    buffer = buffer.last(buffer.size() - 1);
  }
  return buffer;
}

void UsartGd32::write(std::span<const std::byte> buffer) {
  if (arch::isIrqEnabled()) {
    writeIrq(buffer);
  } else {
    writeSpin(buffer);
  }
}

void UsartGd32::writeIrq(std::span<const std::byte> buffer) {
  std::scoped_lock lock{tx_mutex};
  // We have exclusive access to the UART (except for any interrupt handlers
  // using writeSpin() to print stuff)
  tx_irq_signal.lock();
  regs.CTL0 &= ~(CTL0_bits::TCIE | CTL0_bits::TBEIE);
  while (!buffer.empty()) {
    if (regs.STAT.any(STAT_bits::TBE)) {
      {
        arch::CriticalSection cs{};
        // Clear STAT_TC flag
        regs.STAT.store(~STAT_bits::TC);
        // Put outgoing data in transmit buffer
        regs.DATA.store(static_cast<DATA_bits>(buffer.front()));
        buffer = buffer.last(buffer.size() - 1);
        // Enable transmitter and interrupt
        if (buffer.empty()) {
          // Wait for transmission complete
          regs.CTL0 &= ~CTL0_bits::TBEIE;
          regs.CTL0 |= CTL0_bits::TEN | CTL0_bits::TCIE;
        } else {
          // Wait for empty transmit buffer
          regs.CTL0 |= CTL0_bits::TEN | CTL0_bits::TBEIE;
        }
      }
      // Block until interrupt handler has run
      tx_irq_signal.lock();
    }
  }
  regs.CTL0 &= ~(CTL0_bits::TCIE | CTL0_bits::TBEIE);
  tx_irq_signal.unlock();
}

void UsartGd32::writeSpin(std::span<const std::byte> buffer) {
  // Disable IRQ for transmit buffer
  regs.CTL0 &= ~(CTL0_bits::TCIE | CTL0_bits::TBEIE);
  while (!buffer.empty()) {
    buffer = tryWrite(buffer);
  }
}

void UsartGd32::interrupt() {
  if (regs.STAT.any(STAT_bits::TC | STAT_bits::TBE)) {
    regs.STAT.store(~STAT_bits::TC);
    tx_irq_signal.unlock();
  }
  if (regs.STAT.any(STAT_bits::RBNE)) {
    auto data = static_cast<std::byte>(regs.DATA.load());
    if (rx_callback.func != nullptr) {
      rx_callback.func(data, rx_callback.arg);
    }
  }
}

void UsartGd32::updateBaudReg() {
  if (baudrate == 0) {
    // avoid divide by zero
    return;
  }
  auto baud = regs.BAUD.load();
  baud &= BAUD_bits::Reserved_mask;
  uint32_t divider = (module_clock + baudrate / 2) / baudrate;
  baud |= static_cast<BAUD_bits>(divider) &
          (BAUD_bits::INTDIV_mask | BAUD_bits::FRADIV_mask);
  regs.BAUD.store(baud);
}

void UsartGd32::setRxCallback(UsartGd32::RxCallback new_callback) {
  rx_callback = new_callback;
  if (rx_callback.func != nullptr) {
    // Enable receiver and RX interrupt
    regs.CTL0 |= CTL0_bits::RBNEIE | CTL0_bits::REN;
  } else {
    // Disable RX interrupt
    regs.CTL0 &= ~(CTL0_bits::RBNEIE | CTL0_bits::REN);
  }
}

}  // namespace deri::dev::uart
