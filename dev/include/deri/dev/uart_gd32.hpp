/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/USART.hpp"
#include "deri/mutex.hpp"
#include "deri/registers.hpp"

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <span>

namespace deri::dev::uart {

class UsartGd32 {
 public:
  explicit UsartGd32(mmio::USART_regs &regs) : regs{regs} {}

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
   * @param[in] baudrate desired baud rate (baud)
   */
  void setBaud(unsigned new_baudrate) {
    baudrate = new_baudrate;
    updateBaudReg();
  }

  void updateModuleClock(unsigned new_clock) {
    module_clock = new_clock;
    updateBaudReg();
  }
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
  [[nodiscard]] auto try_write(std::span<const std::byte> buffer)
      -> decltype(buffer);

  /**
   * Blocking write
   *
   * This will use either interrupts or spinning until all bytes have been
   * written to the wire.
   *
   * @param buffer Data to write to the UART
   */
  void write(std::span<const std::byte> buffer);

  void interrupt();

 private:
  void writeIrq(std::span<const std::byte> buffer);
  void writeSpin(std::span<const std::byte> buffer);
  void updateBaudReg();

  mmio::USART_regs &regs;

  Mutex mutex{};
  Mutex irq_signal{};
  unsigned module_clock{};
  unsigned baudrate{};
};

}  // namespace deri::dev::uart
