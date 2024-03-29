/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/dev/gpio_gd32.hpp"

#include "deri/dev/afio_gd32.hpp"
#include "deri/dev/exti_gd32.hpp"
#include "deri/mmio/bits/AFIO_bits.hpp"
#include "deri/mmio/bits/GPIO_bits.hpp"
#include "deri/soc/clock_dev.hpp"
#include "deri/soc/gpio_dev.hpp"

#include <cstdint>

namespace deri::dev::gpio {
using CTL_bits = mmio::GPIO_regs::CTL_bits;
using CTL_shift = mmio::GPIO_regs::CTL_shift;
using OCTL_bits = mmio::GPIO_regs::OCTL_bits;

namespace {
void enableModule(Gpio::Port port) {
  soc::Clock::enable(soc::gpioPortClockEnableBits(port));
}
constexpr unsigned ctlShift(GpioPortGd32::Pin pin) {
  return static_cast<unsigned>(pin) % 8 * 4;
}
constexpr unsigned ctlOffset(GpioPortGd32::Pin pin) {
  return static_cast<unsigned>(pin) / 8;
}
constexpr uint32_t ctlMask(GpioPortGd32::Pin pin) {
  return 0b1111 << ctlShift(pin);
}

constexpr CTL_bits applyCtlBits(CTL_bits ctl,
                                GpioPortGd32::Pin pin,
                                CTL_bits bits) {
  ctl &= static_cast<CTL_bits>(~ctlMask(pin));
  ctl |= static_cast<CTL_bits>(
      static_cast<std::underlying_type_t<CTL_bits>>(bits) << ctlShift(pin));
  return ctl;
}

}  // namespace

void GpioPortGd32::writeCTLReg(Pin pin, CTL_bits bits) {
  GPIO.CTL[ctlOffset(pin)].store(
      applyCtlBits(GPIO.CTL[ctlOffset(pin)].load(), pin, bits));
}

void GpioPortGd32::initAnalog(Pin pin) {
  writeCTLReg(pin, static_cast<CTL_bits>(0));
}

CTL_bits operator<<(uint32_t value, mmio::GPIO_regs::CTL_shift shift) {
  return static_cast<CTL_bits>(value << static_cast<unsigned>(shift));
}

void GpioPortGd32::initInput(GpioPortGd32::Pin pin,
                             GpioPortGd32::PullConfig pull) {
  switch (pull) {
    case PullConfig::FLOATING:
      writeCTLReg(pin, 0b01 << CTL_shift::CTL0);
      return;
    case PullConfig::PULL_UP:
      writeCTLReg(pin, 0b10 << CTL_shift::CTL0);
      GPIO.OCTL |= static_cast<OCTL_bits>(1 << static_cast<unsigned>(pin));
      return;
    case PullConfig::PULL_DOWN:
      writeCTLReg(pin, 0b10 << CTL_shift::CTL0);
      GPIO.OCTL &= static_cast<OCTL_bits>(~(1 << static_cast<unsigned>(pin)));
      return;
  }
}

CTL_bits speedBits(GpioPortGd32::DigitalOutSpeed speed) {
  switch (speed) {
    case GpioPortGd32::DigitalOutSpeed::D10MHZ:
      return 0b01 << CTL_shift::MD0;
    case GpioPortGd32::DigitalOutSpeed::D2MHZ:
      return 0b10 << CTL_shift::MD0;
    case GpioPortGd32::DigitalOutSpeed::D50MHZ:
      return 0b11 << CTL_shift::MD0;
  }
  return CTL_bits{};
}

void GpioPortGd32::initOutGpio(GpioPortGd32::Pin pin,
                               GpioPortGd32::OutputMode mode,
                               GpioPortGd32::DigitalOutSpeed speed) {
  auto bits = speedBits(speed);
  switch (mode) {
    case OutputMode::PUSH_PULL:
      bits |= 0b00 << CTL_shift::CTL0;
      break;
    case OutputMode::OPEN_DRAIN:
      bits |= 0b01 << CTL_shift::CTL0;
      break;
  }
  writeCTLReg(pin, bits);
}
void GpioPortGd32::initOutAfio(GpioPortGd32::Pin pin,
                               GpioPortGd32::OutputMode mode,
                               GpioPortGd32::DigitalOutSpeed speed) {
  auto bits = speedBits(speed);
  switch (mode) {
    case OutputMode::PUSH_PULL:
      bits |= 0b10 << CTL_shift::CTL0;
      break;
    case OutputMode::OPEN_DRAIN:
      bits |= 0b11 << CTL_shift::CTL0;
      break;
  }
  writeCTLReg(pin, bits);
}

void GpioManagerGd32::initAnalog(Gpio gpio) {
  enableModule(gpio.port);
  soc::gpioPortDev(gpio.port).initAnalog(gpio.pin);
}

GpioInGd32 GpioManagerGd32::initInput(Gpio gpio,
                                      GpioManagerGd32::PullConfig mode) {
  enableModule(gpio.port);
  GpioInGd32 gpio_in{.port = soc::gpioPortDev(gpio.port), .pin = gpio.pin};
  gpio_in.port.initInput(gpio.pin, mode);
  return gpio_in;
}

GpioOutGd32 GpioManagerGd32::initOutGpio(
    Gpio gpio,
    GpioManagerGd32::OutputMode mode,
    GpioManagerGd32::DigitalOutSpeed speed) {
  enableModule(gpio.port);
  GpioOutGd32 gpio_out{soc::gpioPortDev(gpio.port), gpio.pin};
  gpio_out.port->initOutGpio(gpio.pin, mode, speed);
  return gpio_out;
}

void GpioManagerGd32::initOutAfio(Gpio gpio,
                                  GpioManagerGd32::OutputMode mode,
                                  GpioManagerGd32::DigitalOutSpeed speed) {
  enableModule(gpio.port);
  soc::gpioPortDev(gpio.port).initOutAfio(gpio.pin, mode, speed);
}

void GpioManagerGd32::setInterruptHandler(Gpio gpio,
                                          GpioManagerGd32::Trigger trigger,
                                          GpioManagerGd32::Callback callback) {
  auto line = static_cast<ExtiGd32::Line>(gpio.pin);
  mmio::EXTI.disableLine(line);
  mmio::EXTI.disableRising(line);
  mmio::EXTI.disableFalling(line);
  mmio::EXTI.clearPending(line);
  mmio::AFIO.setExtiSource(gpio.pin, gpio.port);
  if (!!(trigger & Trigger::RISING)) {
    mmio::EXTI.enableRising(line);
  }
  if (!!(trigger & Trigger::FALLING)) {
    mmio::EXTI.enableFalling(line);
  }
  callbacks[static_cast<unsigned>(line)] = callback;
}

void GpioManagerGd32::clearInterruptHandler(Gpio gpio) {
  auto line = static_cast<ExtiGd32::Line>(gpio.pin);
  mmio::EXTI.disableLine(line);
  mmio::EXTI.disableRising(line);
  mmio::EXTI.disableFalling(line);
  mmio::EXTI.clearPending(line);
  callbacks[static_cast<unsigned>(line)] = {};
}

void GpioManagerGd32::enableInterrupt(Gpio gpio) {
  auto line = static_cast<ExtiGd32::Line>(gpio.pin);
  mmio::EXTI.enableLine(line);
  dev::gpio::ExtiGd32::clicInterruptEnable(line);
}

void GpioManagerGd32::disableInterrupt(Gpio gpio) {
  auto line = static_cast<ExtiGd32::Line>(gpio.pin);
  mmio::EXTI.disableLine(line);
  // we don't disable the CLIC line because some of them are shared between
  // multiple pins
}

}  // namespace deri::dev::gpio
