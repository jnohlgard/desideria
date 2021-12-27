/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/irq.hpp"
#include "deri/log.hpp"
#include "deri/mmio/bits/RCU_bits.hpp"
#include "deri/panic.hpp"

#include <optional>

namespace deri::log {
struct RcuGd32;
}

namespace deri::dev::clock {

class RcuGd32 {
  using Logger = log::Logger<log::RcuGd32>;

 public:
  using AHBEN_bits = mmio::RCU_regs::AHBEN_bits;
  using APB1EN_bits = mmio::RCU_regs::APB1EN_bits;
  using APB2EN_bits = mmio::RCU_regs::APB2EN_bits;
  using CFG0_bits = mmio::RCU_regs::CFG0_bits;
  using CFG1_bits = mmio::RCU_regs::CFG1_bits;
  using CFG0_shift = mmio::RCU_regs::CFG0_shift;
  using CFG1_shift = mmio::RCU_regs::CFG1_shift;
  using CTL_bits = mmio::RCU_regs::CTL_bits;

  /// User-friendly configuration for the prescaler settings
  struct PrescalerConfig {
    unsigned ahb{1};
    unsigned apb1{1};
    unsigned apb2{1};
    unsigned adc{2};

    [[nodiscard]] constexpr CFG0_bits bits() const;

   private:
    [[nodiscard]] static constexpr std::optional<CFG0_bits> ahbBits(
        unsigned prescaler);
    [[nodiscard]] static constexpr std::optional<CFG0_bits> apb1Bits(
        unsigned prescaler);
    [[nodiscard]] static constexpr std::optional<CFG0_bits> apb2Bits(
        unsigned prescaler);
    [[nodiscard]] static constexpr std::optional<CFG0_bits> adcBits(
        unsigned prescaler);
  };

  struct Irc8MConfig {
    static constexpr unsigned scs{0b00};
    static constexpr CFG0_bits scss{
        maskedBitsFromValue(scs, CFG0_bits::SCSS_mask, CFG0_shift::SCSS)};

    [[nodiscard]] constexpr CFG0_bits bits() const;

    PrescalerConfig prescaler{};
  };

  struct HxtalConfig {
    static constexpr unsigned scs{0b01};
    static constexpr CFG0_bits scss{
        maskedBitsFromValue(scs, CFG0_bits::SCSS_mask, CFG0_shift::SCSS)};

    [[nodiscard]] constexpr CFG0_bits bits() const;

    PrescalerConfig prescaler{};
  };

  struct PllConfig {
    struct Fraction {
      unsigned numerator{2};
      unsigned denominator{1};
    };

    static constexpr unsigned scs{0b10};
    static constexpr CFG0_bits scss{
        maskedBitsFromValue(scs, CFG0_bits::SCSS_mask, CFG0_shift::SCSS)};

    [[nodiscard]] constexpr CFG0_bits bits() const;

    PrescalerConfig prescaler{};
    Fraction pll_factor{};
  };

  void failsafeConfig();
  void setConfig(const Irc8MConfig &config);
  void setConfig(const HxtalConfig &config);
  void setConfig(const PllConfig &config);

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

  /**
   * Get the frequency of the CK_TIMERx clock by querying the hardware.
   *
   * @return CK_TIMERx frequency
   */
  [[nodiscard]] uint32_t timerFreq(APB1EN_bits) const {
    return timerFreq(apb1Prescaler());
  }
  [[nodiscard]] uint32_t timerFreq(APB2EN_bits) const {
    return timerFreq(apb2Prescaler());
  }

 private:
  [[nodiscard]] uint32_t timerFreq(unsigned bus_divider) const {
    auto ck_ahb = ahbFreq();
    // TIMER clocks have a x2 multiplier when the APB bus divider is > (x / 1)
    if (bus_divider < 2) {
      return ck_ahb;
    } else {
      return ck_ahb >> (bus_divider - 1);
    }
  }

  /**
   * Get the prescaler of the CK_AHB clock by querying the hardware.
   *
   * @return CK_AHB shift
   */
  [[nodiscard]] unsigned ahbPrescaler() const;

  /**
   * Get the prescaler of the CK_APB1 clock by querying the hardware.
   *
   * @return CK_APB1 shift
   */
  [[nodiscard]] unsigned apb1Prescaler() const;
  /**
   * Get the prescaler of the CK_APB2 clock by querying the hardware.
   *
   * @return CK_APB2 shift
   */
  [[nodiscard]] unsigned apb2Prescaler() const;

  void enableHxtal();
  mmio::RCU_regs RCU;
};

}  // namespace deri::dev::clock
