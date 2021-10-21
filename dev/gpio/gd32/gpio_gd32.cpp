#include "deri/dev/gpio/gd32.h"
#include "deri/mmio/bits/GPIO_bits.hpp"

#include <cstdint>

namespace deri::dev::gpio {
using CTL_bits = mmio::GPIO_regs::CTL_bits;
using CTL_shift = mmio::GPIO_regs::CTL_shift;

constexpr unsigned ctlShift(GpioGd32::PinNum pin) {
  return static_cast<unsigned>(pin) % 8 * 4;
}
constexpr unsigned ctlOffset(GpioGd32::PinNum pin) {
  return static_cast<unsigned>(pin) / 8;
}
constexpr uint32_t ctlMask(GpioGd32::PinNum pin) {
  return 0b1111 << ctlShift(pin);
}

constexpr CTL_bits applyCtlBits(CTL_bits ctl,
                                GpioGd32::PinNum pin,
                                CTL_bits bits) {
  ctl &= static_cast<CTL_bits>(~ctlMask(pin));
  ctl |= static_cast<CTL_bits>(
      static_cast<std::underlying_type_t<CTL_bits>>(bits) << ctlShift(pin));
  return ctl;
}

void GpioGd32::writeCTLReg(PinNum pin, CTL_bits bits) {
  CTL[ctlOffset(pin)].store(
      applyCtlBits(CTL[ctlOffset(pin)].load(), pin, bits));
}

void GpioGd32::initAnalog(PinNum pin) {
  writeCTLReg(pin, static_cast<CTL_bits>(0));
}

CTL_bits operator<<(uint32_t value, mmio::GPIO_regs::CTL_shift shift) {
  return static_cast<CTL_bits>(value << static_cast<unsigned>(shift));
}

void GpioGd32::initInput(GpioGd32::PinNum pin, GpioGd32::DigitalIn mode) {
  switch (mode) {
    case DigitalIn::FLOATING:
      writeCTLReg(pin, 0b01 << CTL_shift::CTL0);
      return;
    case DigitalIn::PULL_UP:
      writeCTLReg(pin, 0b10 << CTL_shift::CTL0);
      OCTL |= static_cast<OCTL_bits>(1 << static_cast<unsigned>(pin));
      return;
    case DigitalIn::PULL_DOWN:
      writeCTLReg(pin, 0b10 << CTL_shift::CTL0);
      OCTL &= static_cast<OCTL_bits>(~(1 << static_cast<unsigned>(pin)));
      return;
  }
}

CTL_bits speedBits(GpioGd32::DigitalOutSpeed speed) {
  switch (speed) {
    case GpioGd32::DigitalOutSpeed::D10MHZ:
      return 0b01 << CTL_shift::MD0;
    case GpioGd32::DigitalOutSpeed::D2MHZ:
      return 0b10 << CTL_shift::MD0;
    case GpioGd32::DigitalOutSpeed::D50MHZ:
      return 0b11 << CTL_shift::MD0;
  }
  return CTL_bits{};
}

void GpioGd32::initOutGpio(GpioGd32::PinNum pin,
                           GpioGd32::DigitalOutMode mode,
                           GpioGd32::DigitalOutSpeed speed) {
  auto bits = speedBits(speed);
  switch (mode) {
    case DigitalOutMode::PUSH_PULL:
      bits |= 0b00 << CTL_shift::CTL0;
      break;
    case DigitalOutMode::OPEN_DRAIN:
      bits |= 0b01 << CTL_shift::CTL0;
      break;
  }
  writeCTLReg(pin, bits);

}
void GpioGd32::initOutAfio(GpioGd32::PinNum pin,
                           GpioGd32::DigitalOutMode mode,
                           GpioGd32::DigitalOutSpeed speed) {
  auto bits = speedBits(speed);
  switch (mode) {
    case DigitalOutMode::PUSH_PULL:
      bits |= 0b10 << CTL_shift::CTL0;
      break;
    case DigitalOutMode::OPEN_DRAIN:
      bits |= 0b11 << CTL_shift::CTL0;
      break;
  }
  writeCTLReg(pin, bits);
}
}  // namespace deri::dev::gpio
