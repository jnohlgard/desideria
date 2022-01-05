/*
 * Copyright (c) 2022 Joakim Nohlgård
 */

#pragma once

#include "deri/soc/clock_dev.hpp"
#include "deri/soc/irq_dev.hpp"

#include <type_traits>

namespace deri::soc {

template <auto &device>
class MmioDriver;
template <auto &device>
struct HardwareMap;
template <typename Device>
struct DefaultConfig;
template <auto &device>
struct Config : DefaultConfig<std::remove_cvref_t<decltype(device)>> {};

template <auto &device>
struct HardwareMap {};

template <auto &device>
struct MmioDriver {
  using Device = decltype(device);
  using Driver = typename Config<device>::Driver;
  inline static Driver *static_instance{};

  inline static auto &get() {
    static auto &instance = []() -> auto & {
      Clock::enable(HardwareMap<device>::clock_enable);
      static auto driver = Driver{device};
      driver.init();
      driver.updateModuleClock(HardwareMap<device>::moduleClock());
      HardwareMap<device>::enableIrqs();
      Clock::onClockChange<HardwareMap<device>::clock_enable>(
          driver.clockChangeCallback());
      static_instance = &driver;
      return driver;
    }
    ();
    return instance;
  }
};

namespace detail {
template <auto &device, auto clock_bits, auto... irq_signals>
struct HardwareMapDefinition {
  static constexpr auto clock_enable{clock_bits};
  static void enableIrqs() { (Irq::enable(irq_signals), ...); }
  static auto moduleClock() { return soc::Clock::current(clock_enable); }
};
}  // namespace detail

// Specific device types below, these should be specialized in headers for each
// SOC

template <unsigned index>
struct TimerDevice;

template <unsigned index>
inline auto &timer_device{TimerDevice<index>::device};

template <unsigned index>
using Timer = MmioDriver<timer_device<index>>;

template <unsigned index>
inline auto &timer() {
  return Timer<index>::get();
}

template <unsigned index>
struct UartDevice;

template <unsigned index>
inline auto &uart_device{UartDevice<index>::device};

template <unsigned index>
using Uart = MmioDriver<uart_device<index>>;

template <unsigned index>
inline auto &uart() {
  return Uart<index>::get();
}

}  // namespace deri::soc
