/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/registers.h"

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <span>

namespace deri::dev::gd32::usart {

enum class STAT_bits : uint32_t;
enum class DATA_bits : uint32_t;
enum class BAUD_bits : uint32_t;
enum class CTL0_bits : uint32_t;
enum class CTL1_bits : uint32_t;
enum class CTL2_bits : uint32_t;
enum class GP_bits : uint32_t;
}

namespace deri::dev::uart {

#pragma GCC diagnostic push
// Need to suppress this and other similar warnings:
// 'deri::dev::uart::UartSiFive::rxdata' should be initialized in the member
// initialization list [-Weffc++]
#pragma GCC diagnostic ignored "-Weffc++"

class UsartGd32 {
  Register<gd32::usart::STAT_bits> STAT;
  Register<gd32::usart::DATA_bits> DATA;
  Register<gd32::usart::BAUD_bits> BAUD;
  Register<gd32::usart::CTL0_bits> CTL0;
  Register<gd32::usart::CTL1_bits> CTL1;
  Register<gd32::usart::CTL2_bits> CTL2;
  Register<gd32::usart::GP_bits> GP;

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
  [[nodiscard]] auto write(std::span<const std::byte> buffer) -> decltype(buffer);
};
#pragma GCC diagnostic pop

static_assert(sizeof(UsartGd32) == 0x1C);

}  // namespace deri::hal::periph
