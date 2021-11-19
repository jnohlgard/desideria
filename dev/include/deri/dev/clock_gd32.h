/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/bits/RCU_bits.hpp"

namespace deri::dev::clock {

class RcuGd32 {
 public:
  using AHBEN_bits = mmio::RCU_regs::AHBEN_bits;
  using APB1EN_bits = mmio::RCU_regs::APB1EN_bits;
  using APB2EN_bits = mmio::RCU_regs::APB2EN_bits;

  void enableModules(AHBEN_bits bits) { RCU.AHBEN |= bits; }
  void enableModules(APB1EN_bits bits) { RCU.APB1EN |= bits; }
  void enableModules(APB2EN_bits bits) { RCU.APB2EN |= bits; }

  [[nodiscard]] uint32_t systemFrequency() const;

 private:
  mmio::RCU_regs RCU;
};

}  // namespace deri::dev::clock
