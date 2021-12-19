/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/dev/clock_gd32.hpp"
namespace deri::mmio {
extern dev::clock::RcuGd32 RCU;
}  // namespace deri::mmio

namespace deri::soc {
class Clock {
 public:
  enum class Core {};
  using AHB = mmio::RCU_regs::AHBEN_bits;
  using APB1 = mmio::RCU_regs::APB1EN_bits;
  using APB2 = mmio::RCU_regs::APB2EN_bits;

  template <typename Bits>
  static void enable(Bits bits) {
    mmio::RCU.enableModules(bits);
  }

  [[nodiscard]] static unsigned current(AHB) { return mmio::RCU.ahbFreq(); }
  [[nodiscard]] static unsigned current(APB1) { return mmio::RCU.apb1Freq(); }
  [[nodiscard]] static unsigned current(APB2) { return mmio::RCU.apb2Freq(); }
};
}  // namespace deri::soc
