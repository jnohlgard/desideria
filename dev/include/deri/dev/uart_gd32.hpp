/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/registers.hpp"
#include "deri/mmio/USART.hpp"

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <span>

namespace deri::dev::uart {

class UsartGd32 {
 public:
  /**
   * Initialize the hardware module
   */
  void init();

  /**
   * Turn on the transmitter
   */
  void transmitterOn();

  /**
   * Turn off the transmitter
   */
  void transmitterOff();

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
  [[nodiscard]] auto write(std::span<const std::byte> buffer)
      -> decltype(buffer);

 private:
  mmio::USART_regs USART;
};

static_assert(sizeof(UsartGd32) == sizeof(mmio::USART_regs));

}  // namespace deri::dev::uart
