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
  using CFG0_shift = mmio::RCU_regs::CFG0_shift;

  /// User-friendly configuration for the prescaler settings
  struct PrescalerConfig {
    unsigned ahb{1};
    unsigned apb1{1};
    unsigned apb2{1};
    unsigned adc{2};

    [[nodiscard]] constexpr CFG0_bits bits() const {
      auto ahb_bits = ahbBits(ahb);
      CFG0_bits cfg0{};
      if (!ahb_bits.has_value()) {
        Logger::error("Invalid AHB prescaler setting %u\n", ahb);
        panic();
      }
      cfg0 |= *ahb_bits;
      auto apb1_bits = apb1Bits(apb1);
      if (!apb1_bits.has_value()) {
        Logger::error("Invalid APB1 prescaler setting %u\n", apb1);
        panic();
      }
      cfg0 |= *apb1_bits;
      auto apb2_bits = apb2Bits(apb2);
      if (!apb2_bits.has_value()) {
        Logger::error("Invalid APB2 prescaler setting %u\n", apb2);
        panic();
      }
      cfg0 |= *apb2_bits;
      auto adc_bits = adcBits(adc);
      if (!adc_bits.has_value()) {
        Logger::error("Invalid ADC prescaler setting %u\n", adc);
        panic();
      }
      cfg0 |= *adc_bits;
      return cfg0;
    }

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

    [[nodiscard]] constexpr CFG0_bits bits() const { return prescaler.bits(); }

    PrescalerConfig prescaler{};
  };

  struct HxtalConfig {
    static constexpr unsigned scs{0b01};
    static constexpr CFG0_bits scss{
        maskedBitsFromValue(scs, CFG0_bits::SCSS_mask, CFG0_shift::SCSS)};

    [[nodiscard]] constexpr CFG0_bits bits() const {
      return prescaler.bits() |
             maskedBitsFromValue(scs, CFG0_bits::SCS_mask, CFG0_shift::SCS);
    }

    PrescalerConfig prescaler{};
  };

  void setConfig(const Irc8MConfig &config) {
    arch::CriticalSection cs{};
    RCU.CFG0.store(config.bits());
    while ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) != Irc8MConfig::scss) {
      // wait for hardware to confirm clock source change
    }
  }

  void setConfig(const HxtalConfig &config) {
    using CTL_bits = mmio::RCU_regs::CTL_bits;
    arch::CriticalSection cs{};
    RCU.CTL |= CTL_bits::HXTALEN;
    while (!!(RCU.CTL.load() & CTL_bits::HXTALSTB)) {
      // Wait for the oscillator to stabilize
    }
    RCU.CFG0.store(config.bits());
    while ((RCU.CFG0.load() & CFG0_bits::SCSS_mask) != Irc8MConfig::scss) {
      // wait for hardware to confirm clock source change
    }
  }

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

  mmio::RCU_regs RCU;
};

constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::ahbBits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::AHBPSC);
  switch (prescaler) {
    case 1:
      return CFG0{};
    case 2:
      return CFG0{0b1000u << shift};
    case 4:
      return CFG0{0b1001u << shift};
    case 8:
      return CFG0{0b1010u << shift};
    case 16:
      return CFG0{0b1011u << shift};
    case 64:
      return CFG0{0b1100u << shift};
    case 128:
      return CFG0{0b1101u << shift};
    case 256:
      return CFG0{0b1110u << shift};
    case 512:
      return CFG0{0b1111u << shift};
    default:
      return std::nullopt;
  }
}
constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::apb1Bits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::APB1PSC);
  switch (prescaler) {
    case 1:
      return CFG0{};
    case 2:
      return CFG0{0b100u << shift};
    case 4:
      return CFG0{0b101u << shift};
    case 8:
      return CFG0{0b110u << shift};
    case 16:
      return CFG0{0b111u << shift};
    default:
      return std::nullopt;
  }
}
constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::apb2Bits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::APB2PSC);
  switch (prescaler) {
    case 1:
      return CFG0{};
    case 2:
      return CFG0{0b100u << shift};
    case 4:
      return CFG0{0b101u << shift};
    case 8:
      return CFG0{0b110u << shift};
    case 16:
      return CFG0{0b111u << shift};
    default:
      return std::nullopt;
  }
}
constexpr std::optional<mmio::RCU_regs::CFG0_bits>
RcuGd32::PrescalerConfig::adcBits(unsigned int prescaler) {
  using CFG0 = mmio::RCU_regs::CFG0_bits;
  constexpr auto shift =
      static_cast<unsigned>(mmio::RCU_regs::CFG0_shift::ADCPSC_1_0);
  switch (prescaler) {
    case 2:
      return CFG0{};
    case 4:
      return CFG0{0b01u << shift};
    case 6:
      return CFG0{0b10u << shift};
    case 8:
      return CFG0{0b11u << shift};
    case 12:
      return CFG0::ADCPSC_2 | CFG0{0b01u << shift};
    case 16:
      return CFG0::ADCPSC_2 | CFG0{0b11u << shift};
    default:
      return std::nullopt;
  }
}

}  // namespace deri::dev::clock
