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

  /**
   * Get the frequency of the CK_SYS clock by querying the hardware.
   *
   * @return CK_SYS frequency
   */
  [[nodiscard]] uint32_t sysFreq() const;

  /**
   * Get the frequency of the CK_AHB clock by querying the hardware.
   *
   * @return CK_AHB frequency
   */
  [[nodiscard]] uint32_t ahbFreq() const;

  /**
   * Get the frequency of the CK_APB1 clock by querying the hardware.
   *
   * @return CK_APB1 frequency
   */
  [[nodiscard]] uint32_t apb1Freq() const;

  /**
   * Get the frequency of the CK_APB2 clock by querying the hardware.
   *
   * @return CK_APB2 frequency
   */
  [[nodiscard]] uint32_t apb2Freq() const;

 private:
  mmio::RCU_regs RCU;
};

}  // namespace deri::dev::clock
