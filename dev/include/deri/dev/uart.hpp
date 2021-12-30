/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/arch/irq.hpp"
#include "deri/callback.hpp"
#include "deri/dev/clock.hpp"
#include "deri/mutex.hpp"

#include <cstdint>
#include <mutex>
#include <optional>

namespace deri::dev::uart {

template <class UartDeviceType>
class UartBlockingDriver {
 public:
  using UartDevice = UartDeviceType;
  using RxCallback = Callback<void(std::byte, uintptr_t)>;
  static constexpr auto driver_name = "UartBlockingDriver";

  explicit UartBlockingDriver(UartDevice &uart) : uart(uart) {}

  void init() { uart.init(); }

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
  [[nodiscard]] auto tryWrite(std::span<const std::byte> buffer) {
    return uart.tryWrite(buffer);
  }

  /**
   * Blocking write
   *
   * This will use either interrupts or spinning until all bytes have been
   * written to the wire.
   *
   * @param buffer Data to write to the UART
   */
  void write(std::span<const std::byte> buffer) {
    while (!buffer.empty()) {
      buffer = tryWrite(buffer);
    }
  }

  /**
   * Write a single byte, blocking
   *
   * @param data
   */
  void write(std::byte data) { write(std::span<const std::byte, 1>(&data, 1)); }

  clock::OnClockChange &clockChangeCallback() { return on_clock_change; }

 private:
  void updateBaudReg() { uart.setBaud(module_clock, baudrate); }

  UartDevice &uart{};
  clock::OnClockChange on_clock_change{
      .callback = {.func = clock::updateModuleClockCallback<
                       std::remove_pointer_t<decltype(this)>>,
                   .arg = reinterpret_cast<uintptr_t>(this)}};
  unsigned module_clock{};
  unsigned baudrate{};
};

template <class UartDeviceType>
class UartIrqDriver {
 public:
  using UartDevice = UartDeviceType;
  using RxCallback = Callback<void(std::byte, uintptr_t)>;
  static constexpr auto driver_name = "UartIrqDriver";

  explicit UartIrqDriver(UartDevice &uart) : uart(uart) {}

  void init() { uart.init(); }

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
  [[nodiscard]] auto tryWrite(std::span<const std::byte> buffer) {
    return uart.tryWrite(buffer);
  }

  /**
   * Blocking write
   *
   * This will use either interrupts or spinning until all bytes have been
   * written to the wire.
   *
   * @param buffer Data to write to the UART
   */
  void write(std::span<const std::byte> buffer) {
    if (arch::isIrqEnabled()) {
      writeIrq(buffer);
    } else {
      writeSpin(buffer);
    }
  }

  /**
   * Write a single byte, blocking
   *
   * @param data
   */
  void write(std::byte data) { write(std::span<const std::byte, 1>(&data, 1)); }

  void setRxCallback(RxCallback new_callback);

  void interrupt();
  clock::OnClockChange &clockChangeCallback() { return on_clock_change; }

 private:
  void writeIrq(std::span<const std::byte> buffer);

  void writeSpin(std::span<const std::byte> buffer);
  void updateBaudReg() { uart.setBaud(module_clock, baudrate); }

  UartDevice &uart{};
  Mutex tx_mutex{};
  Mutex tx_irq_signal{};
  RxCallback rx_callback{};
  clock::OnClockChange on_clock_change{
      .callback = {.func = clock::updateModuleClockCallback<
                       std::remove_pointer_t<decltype(this)>>,
                   .arg = reinterpret_cast<uintptr_t>(this)}};
  unsigned module_clock{};
  unsigned baudrate{};
};

template <class UartDeviceType>
void UartIrqDriver<UartDeviceType>::setRxCallback(
    UartIrqDriver::RxCallback new_callback) {
  rx_callback = new_callback;
  if (rx_callback.func != nullptr) {
    uart.enableRxInterrupt();
  } else {
    uart.disableRxInterrupt();
  }
}
template <class UartDeviceType>
void UartIrqDriver<UartDeviceType>::interrupt() {
  if (uart.checkAndClearTxIrq()) {
    tx_irq_signal.unlock();
  }
  // drain the RX buffer
  while (auto data = uart.getRxByte()) {
    if (rx_callback.func != nullptr) {
      rx_callback.func(*data, rx_callback.arg);
    }
  }
}
template <class UartDeviceType>
void UartIrqDriver<UartDeviceType>::writeIrq(
    std::span<const std::byte> buffer) {
  std::scoped_lock lock{tx_mutex};
  // We have exclusive access to the UART (except for any interrupt handlers
  // using writeSpin() to print stuff)
  tx_irq_signal.lock();
  while (!buffer.empty()) {
    {
      arch::CriticalSection cs{};
      buffer = tryWrite(buffer);
      if (buffer.empty()) {
        // Wait for transmission complete
        uart.disableTxInterrupts();
        uart.enableTxCompleteInterrupt();
      } else {
        // Wait for empty transmit buffer
        uart.enableTxBufferAvailableInterrupt();
      }
    }
    // Block until interrupt handler has run
    tx_irq_signal.lock();
  }
  uart.disableTxInterrupts();
  tx_irq_signal.unlock();
}
template <class UartDeviceType>
void UartIrqDriver<UartDeviceType>::writeSpin(
    std::span<const std::byte> buffer) {
  // Intentionally not taking the tx_mutex to allow writing from interrupt
  // context, e.g. for console debug messages from within an interrupt handler
  while (!buffer.empty()) {
    buffer = tryWrite(buffer);
  }
}
}  // namespace deri::dev::uart
