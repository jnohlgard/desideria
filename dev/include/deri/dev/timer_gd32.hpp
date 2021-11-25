/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/TIMER.hpp"
#include "deri/mmio/bits/TIMER_bits.hpp"

namespace deri::dev::timer {

class TimerGd32 {
 public:
  static constexpr unsigned max_value = 0xffffu;
  static constexpr unsigned num_channels = 4;

  enum class ClockSource {
    CK_TIMER,
    ITI0,
    ITI1,
    ITI2,
    ITI3,
    EXTERNAL_TRIGGER,
  };

  enum class Channel {
    CH0 = 0,
    CH1,
    CH2,
    CH3,
  };

  enum class Count : uint16_t {};
  using Period = mmio::TIMER_regs::CAR_bits;
  using Target = mmio::TIMER_regs::CHxCV_bits;

  void init();

  void setSource(ClockSource source);

  /**
   * Set clock prescaler division factor
   *
   * The module clock is divided by (prescaler+1) to generate the counter clock.
   *
   * @param prescaler Prescaler value of the counter clock
   */
  void setPrescaler(Count prescaler) {
    TIMER.PSC.store(mmio::TIMER_regs::PSC_bits{
        static_cast<uint16_t>(prescaler)});
  }

  /**
   * Start the timer
   */
  void start() { TIMER.CTL0 |= mmio::TIMER_regs::CTL0_bits::CEN; }
  /**
   * Stop the timer
   */
  void stop() { TIMER.CTL0 &= ~mmio::TIMER_regs::CTL0_bits::CEN; }

  /**
   * Read the current hardware counter value
   * @return Current count
   */
  [[nodiscard]] Count read() const {
    return static_cast<Count>(TIMER.CNT.load());
  }

  /**
   * Set the period of the timer.
   *
   * When the counter increments when count = period, the count will reset back
   * to 0 The length of a whole period is (max_count+1) ticks
   *
   * @param period
   */
  void setPeriod(Count max_count) {
    TIMER.CAR.store(Period{max_count});
    // When writing the CAR register all INTF flags may become set.
    TIMER.INTF.store(mmio::TIMER_regs::INTF_bits{0});
  }

  /**
   * Set the compare value for the given channel
   *
   * @param channel channel to configure
   * @param target value to compare
   */
  void setCompare(Channel channel, Count target) {
    TIMER.CHxCV[static_cast<unsigned>(channel)].store(Target{target});
  }

  void disableInterrupt(Channel channel) {
    TIMER.DMAINTEN &= ~channelInterruptEnableBit(channel);
  }

  void enableInterrupt(Channel channel) {
    TIMER.DMAINTEN |= channelInterruptEnableBit(channel);
  }

  void clearInterruptFlag(Channel channel) {
    // INTF is write 0 to clear
    TIMER.INTF.store(~channelInterruptFlagBit(channel));
  }

  void clearInterruptFlag(mmio::TIMER_regs::INTF_bits bits) {
    // INTF is write 0 to clear, writing 1 has no effect
    TIMER.INTF.store(~bits);
  }

  [[nodiscard]] auto interruptFlag() const {
    // INTF gets set regardless if the interrupt is enabled or not, so we need
    // to check both enabled and flagged
    using INTF_bits = mmio::TIMER_regs::INTF_bits;
    using BitsInt = std::underlying_type_t<INTF_bits>;
    auto inten = static_cast<BitsInt>(
        TIMER.DMAINTEN.load() & mmio::TIMER_regs::DMAINTEN_bits::AllChannels);
    auto intf = static_cast<BitsInt>(TIMER.INTF.load());
    return static_cast<INTF_bits>(inten & intf);
  }

  void disablePeriodInterrupt() {
    TIMER.DMAINTEN &= ~mmio::TIMER_regs::DMAINTEN_bits::UPIE;
  }

  void enablePeriodInterrupt() {
    TIMER.DMAINTEN |= mmio::TIMER_regs::DMAINTEN_bits::UPIE;
  }

  void clearPeriodFlag() {
    // INTF is write 0 to clear
    TIMER.INTF.store(~mmio::TIMER_regs::INTF_bits::UPIF);
  }

 private:
  static constexpr mmio::TIMER_regs::DMAINTEN_bits channelInterruptEnableBit(
      Channel channel) {
    using DMAINTEN_bits = mmio::TIMER_regs::DMAINTEN_bits;
    return static_cast<DMAINTEN_bits>(
        static_cast<std::underlying_type_t<DMAINTEN_bits>>(DMAINTEN_bits::CH0IE)
        << static_cast<unsigned>(channel));
  }
  static constexpr mmio::TIMER_regs::INTF_bits channelInterruptFlagBit(
      Channel channel) {
    using INTF_bits = mmio::TIMER_regs::INTF_bits;
    return static_cast<INTF_bits>(
        static_cast<std::underlying_type_t<INTF_bits>>(INTF_bits::CH0IF)
        << static_cast<unsigned>(channel));
  }

  mmio::TIMER_regs TIMER;
};
void HasArithmeticOperators(TimerGd32::Count);

static_assert(sizeof(TimerGd32) == sizeof(mmio::TIMER_regs));

}  // namespace deri::dev::timer
