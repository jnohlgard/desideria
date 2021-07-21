/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#pragma once

#include "deri/registers.h"

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <span>

namespace deri::dev::uart {

#pragma GCC diagnostic push
// Need to suppress this and other similar warnings:
// 'deri::dev::uart::UartSiFive::rxdata' should be initialized in the member
// initialization list [-Weffc++]
#pragma GCC diagnostic ignored "-Weffc++"

class UartSiFive {
  enum class txctrl_mask : std::uint32_t {
    txen = 0x00000001,
    nstop = 0x00000002,
    txcnt = 0x00070000,
  };
  volatile std::atomic_uint32_t txdata;
  volatile std::uint32_t rxdata;
  volatile std::uint32_t txctrl;
  volatile std::uint32_t rxctrl;
  volatile std::uint32_t ie;
  volatile std::uint32_t ip;
  volatile std::uint32_t div;

 public:
  void init();

  auto write(std::span<const std::byte> buffer) -> decltype(buffer);
};
#pragma GCC diagnostic pop

}  // namespace deri::dev::uart
