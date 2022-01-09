/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/USART.hpp"
#include "deri/mmio/bits/USART_bits.hpp"
#include "deri/registers.hpp"

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>

namespace deri::dev::uart {

class UsartGd32 {
 public:
  /**
   * Initialize the hardware module
   */
  void init();

  /**
   * Set the baud rate divider register
   *
   * No checking is made to ensure that the desired baud can be reached
   *
   * This function must be called every time the peripheral clock frequency is
   * changed.
   *
   * @param[in] pclk peripheral clock (Hz)
   * @param[in] baudrate desired baud rate (baud)
   */
  void setBaud(unsigned pclk, unsigned baudrate);

  /**
   * Write some bytes to the UART.
   *
   * This function will never block and will only write data if there is space
   * available in the hardware transmit register.
   *
   * @param buffer Data to write to the UART
   * @return @p buffer trimmed to contain only what was not yet written to the
   * transmit register
   */
  [[nodiscard]] auto tryWrite(std::span<const std::byte> buffer)
      -> decltype(buffer);

  void disableTxInterrupts() {
    using CTL0_bits = mmio::USART_regs::CTL0_bits;
    USART.CTL0 &= ~(CTL0_bits::TCIE | CTL0_bits::TBEIE);
  }

  void enableTxCompleteInterrupt() {
    using CTL0_bits = mmio::USART_regs::CTL0_bits;
    USART.CTL0 |= CTL0_bits::TCIE;
  }
  void enableTxBufferAvailableInterrupt() {
    using CTL0_bits = mmio::USART_regs::CTL0_bits;
    USART.CTL0 |= CTL0_bits::TBEIE;
  }

  bool checkAndClearTxIrq() {
    using STAT_bits = mmio::USART_regs::STAT_bits;
    using CTL0_bits = mmio::USART_regs::CTL0_bits;
    if (!!(flagsEnabledAndSet() & (STAT_bits::TC | STAT_bits::TBE))) {
      USART.STAT.store(~STAT_bits::TC);
      // Disable transmit buffer empty IRQ to avoid an infinite interrupt loop
      USART.CTL0 &= ~CTL0_bits::TBEIE;
      return true;
    }
    return false;
  }

  bool checkRxIrq() {
    using STAT_bits = mmio::USART_regs::STAT_bits;
    return !!(flagsEnabledAndSet() & STAT_bits::RBNE);
  }

  std::optional<std::byte> getRxByte() {
    using STAT_bits = mmio::USART_regs::STAT_bits;
    if (USART.STAT.any(STAT_bits::RBNE)) {
      return static_cast<std::byte>(USART.DATA.load());
    }
    return std::nullopt;
  }

  void enableRxInterrupt() {
    using CTL0_bits = mmio::USART_regs::CTL0_bits;
    // Enable receiver and RX interrupt
    USART.CTL0 |= CTL0_bits::RBNEIE | CTL0_bits::REN;
  }

  void disableRxInterrupt() {
    using CTL0_bits = mmio::USART_regs::CTL0_bits;
    // Disable receiver and RX interrupt
    USART.CTL0 &= ~(CTL0_bits::RBNEIE | CTL0_bits::REN);
  }

 private:
  mmio::USART_regs::STAT_bits flagsEnabledAndSet() {
    using STAT_bits = mmio::USART_regs::STAT_bits;
    return static_cast<STAT_bits>(static_cast<uint32_t>(USART.STAT.load()) &
                                  static_cast<uint32_t>(USART.CTL0.load()));
  }
  mmio::USART_regs USART;
};

static_assert(sizeof(UsartGd32) == sizeof(mmio::USART_regs));

}  // namespace deri::dev::uart
