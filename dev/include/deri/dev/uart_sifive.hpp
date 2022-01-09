/*
 * Copyright (C) 2020-2022 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

#include "deri/mmio/UART.hpp"
#include "deri/registers.hpp"

#include <cstddef>
#include <optional>
#include <span>

namespace deri::dev::uart {

class UartSiFive {
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

  void disableTxInterrupts();

  void enableTxCompleteInterrupt();
  void enableTxBufferAvailableInterrupt();

  bool checkAndClearTxIrq();
  bool checkRxIrq();

  void enableRxInterrupt();

  void disableRxInterrupt();

  std::optional<std::byte> getRxByte();

 private:
  mmio::UART_regs UART;
};

}  // namespace deri::dev::uart
