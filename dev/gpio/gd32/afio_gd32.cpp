/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/afio_gd32.h"

#include "deri/soc/clock_dev.h"
#include "deri/mmio/bits/AFIO_bits.hpp"

namespace deri::dev::gpio {

namespace {

template <typename BitsType>
BitsType applyExtiSource(auto pin_number,
                         AfioGd32::ExtiSource source,
                         BitsType reg) {
  auto shift = (pin_number % 4) * 4;
  return (reg & static_cast<BitsType>(~(0b1111 << shift))) |
         static_cast<BitsType>(
             static_cast<std::underlying_type_t<BitsType>>(source) << shift);
}

}  // namespace

void AfioGd32::setExtiSource(Gpio::Pin pin, AfioGd32::ExtiSource source) {
  auto pin_number = static_cast<std::underlying_type_t<Gpio::Pin>>(pin);
  if (pin_number < 4) {
    AFIO.EXTISS0.store(
        applyExtiSource(pin_number, source, AFIO.EXTISS0.load()));
  } else if (pin_number < 8) {
    AFIO.EXTISS1.store(
        applyExtiSource(pin_number, source, AFIO.EXTISS1.load()));
  } else if (pin_number < 12) {
    AFIO.EXTISS2.store(
        applyExtiSource(pin_number, source, AFIO.EXTISS2.load()));
  } else if (pin_number < 16) {
    AFIO.EXTISS3.store(
        applyExtiSource(pin_number, source, AFIO.EXTISS3.load()));
  }
}

void AfioGd32::init() {
  soc::rcu.enableModules(clock::RcuGd32::APB2EN_bits::AFEN);
}

}  // namespace deri::dev::gpio
