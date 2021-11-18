/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/mmio/bits/EXTI_bits.hpp"

namespace deri::dev::gpio {

class ExtiGd32 : private mmio::EXTI_regs {
 public:
  enum class Line : unsigned;
  void enableLine(Line line) {
    INTEN |= static_cast<INTEN_bits>(1 << static_cast<unsigned>(line));
  }
  void disableLine(Line line) {
    INTEN &= static_cast<INTEN_bits>(~(1 << static_cast<unsigned>(line)));
  }
  void enableRising(Line line) {
    RTEN |= static_cast<RTEN_bits>(1 << static_cast<unsigned>(line));
  }
  void disableRising(Line line) {
    RTEN &= static_cast<RTEN_bits>(~(1 << static_cast<unsigned>(line)));
  }
  void enableFalling(Line line) {
    FTEN |= static_cast<FTEN_bits>(1 << static_cast<unsigned>(line));
  }
  void disableFalling(Line line) {
    FTEN &= static_cast<FTEN_bits>(~(1 << static_cast<unsigned>(line)));
  }
  void clearPending(PD_bits lines_mask) {
    // PD is write-1-to-clear
    PD.store(lines_mask);
  }
  void clearPending(Line line) {
    auto mask = static_cast<PD_bits>(1 << static_cast<unsigned>(line));
    clearPending(mask);
  }
  PD_bits pending() {
    return PD.load();
  }

  // Needs to be implemented in each SoC specific code
  static void clicInterruptEnable(Line line);
  static void clicInterruptDisable(Line line);
};
}  // namespace deri::dev
