/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/bits/EXTI_bits.hpp"

namespace deri::dev::gpio {

class ExtiGd32 {
 public:
  using INTEN_bits = mmio::EXTI_regs::INTEN_bits;
  using RTEN_bits = mmio::EXTI_regs::RTEN_bits;
  using FTEN_bits = mmio::EXTI_regs::FTEN_bits;
  using PD_bits = mmio::EXTI_regs::PD_bits;

  enum class Line : unsigned;

  void enableLine(Line line) {
    EXTI.INTEN |= static_cast<INTEN_bits>(1 << static_cast<unsigned>(line));
  }

  void disableLine(Line line) {
    EXTI.INTEN &= static_cast<INTEN_bits>(~(1 << static_cast<unsigned>(line)));
  }

  void enableRising(Line line) {
    EXTI.RTEN |= static_cast<RTEN_bits>(1 << static_cast<unsigned>(line));
  }

  void disableRising(Line line) {
    EXTI.RTEN &= static_cast<RTEN_bits>(~(1 << static_cast<unsigned>(line)));
  }

  void enableFalling(Line line) {
    EXTI.FTEN |= static_cast<FTEN_bits>(1 << static_cast<unsigned>(line));
  }

  void disableFalling(Line line) {
    EXTI.FTEN &= static_cast<FTEN_bits>(~(1 << static_cast<unsigned>(line)));
  }

  void clearPending(PD_bits lines_mask) {
    // PD is write-1-to-clear
    EXTI.PD.store(lines_mask);
  }

  void clearPending(Line line) {
    auto mask = static_cast<PD_bits>(1 << static_cast<unsigned>(line));
    clearPending(mask);
  }

  [[nodiscard]] PD_bits pending() const { return EXTI.PD.load(); }

  // Needs to be implemented in each SoC specific code
  static void clicInterruptEnable(Line line);
  static void clicInterruptDisable(Line line);

 private:
  mmio::EXTI_regs EXTI;
};

static_assert(sizeof(ExtiGd32) == sizeof(mmio::EXTI_regs));

}  // namespace deri::dev::gpio
