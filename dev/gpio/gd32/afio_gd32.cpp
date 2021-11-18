/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/afio_gd32.h"

#include "deri/dev/clock_gd32.h"
#include "deri/mmio/bits/AFIO_bits.hpp"

namespace deri::dev::gpio {
namespace {
auto applyExtiSource(auto pin_number, AfioGd32::ExtiSource source, auto reg) {
  auto shift = (pin_number % 4) * 4;
  return (reg & static_cast<decltype(reg)>(~(0b1111 << shift))) |
         static_cast<decltype(reg)>(
             static_cast<std::underlying_type_t<decltype(reg)>>(source)
             << shift);
}
}  // namespace

void AfioGd32::setExtiSource(Gpio::Pin pin, AfioGd32::ExtiSource source) {
  auto pin_number = static_cast<std::underlying_type_t<Gpio::Pin>>(pin);
  if (pin_number < 4) {
    EXTISS0.store(applyExtiSource(pin_number, source, EXTISS0.load()));
  } else if (pin_number < 8) {
    EXTISS1.store(applyExtiSource(pin_number, source, EXTISS1.load()));
  } else if (pin_number < 12) {
    EXTISS2.store(applyExtiSource(pin_number, source, EXTISS2.load()));
  } else if (pin_number < 16) {
    EXTISS3.store(applyExtiSource(pin_number, source, EXTISS3.load()));
  }
}
void AfioGd32::init() {
  clock::enableModules(mmio::RCU_regs::APB2EN_bits::AFEN);
}
}  // namespace deri::dev::gpio
