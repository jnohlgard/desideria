/*
 * Copyright (c) 2021 Joakim Nohlgård
 */
#include "deri/dev/gpio_sifive.hpp"

#include "deri/log.hpp"
#include "deri/mmio/bits/GPIO_bits.hpp"
#include "deri/soc/gpio_dev.hpp"

namespace deri::log {
struct Gpio;
}

namespace deri::mmio {
extern dev::gpio::GpioPortSifive GPIO;
}

namespace deri::dev::gpio {
using Logger = log::Logger<log::Gpio>;

using mmio::GPIO_regs;

namespace {
unsigned pinMask(GpioPortSifive::Pin pin) {
  return 1u << static_cast<unsigned>(pin);
}
}  // namespace

void GpioPortSifive::initIof(GpioPortSifive::Pin pin, GpioPortSifive::Iof iof) {
  if (iof == Iof::IOF0) {
    GPIO.iof_sel &= ~GPIO_regs::iof_sel_bits{pinMask(pin)};
  } else {
    GPIO.iof_sel |= GPIO_regs::iof_sel_bits{pinMask(pin)};
  }
  GPIO.iof_en |= GPIO_regs::iof_en_bits{pinMask(pin)};
}

void GpioPortSifive::initInGpio(GpioPortSifive::Pin pin,
                                GpioPortSifive::PullConfig pull) {
  GPIO.input_en |= GPIO_regs::input_en_bits{pinMask(pin)};
  GPIO.iof_en &= ~GPIO_regs::iof_en_bits{pinMask(pin)};
  if (pull == PullConfig::FLOATING) {
    GPIO.pullup &= ~GPIO_regs::pullup_bits{pinMask(pin)};
  } else if (pull == GpioInConfig::PullConfig::PULL_UP) {
    GPIO.pullup |= GPIO_regs::pullup_bits{pinMask(pin)};
  } else {
    Logger::error("Invalid pull config for GPIO pin %u: %u\n",
                  static_cast<unsigned>(pin),
                  static_cast<unsigned>(pull));
  }
}

void GpioPortSifive::initInIof(GpioPortSifive::Pin pin,
                               GpioPortSifive::PullConfig pull,
                               Iof iof) {
  initInGpio(pin, pull);
  initIof(pin, iof);
}

void GpioPortSifive::initOutGpio(GpioPortSifive::Pin pin,
                                 GpioPortSifive::Polarity polarity,
                                 GpioPortSifive::DriveStrength strength) {
  GPIO.output_en |= GPIO_regs::output_en_bits{pinMask(pin)};
  GPIO.iof_en &= ~GPIO_regs::iof_en_bits{pinMask(pin)};
  if (polarity == Polarity::INVERTED) {
    GPIO.out_xor |= GPIO_regs::out_xor_bits{pinMask(pin)};
  } else {
    GPIO.out_xor &= ~GPIO_regs::out_xor_bits{pinMask(pin)};
  }
  if (strength == DriveStrength::HIGH) {
    GPIO.drive |= GPIO_regs::drive_bits{pinMask(pin)};
  } else {
    GPIO.drive &= ~GPIO_regs::drive_bits{pinMask(pin)};
  }
}
void GpioPortSifive::initOutIof(GpioPortSifive::Pin pin,
                                GpioPortSifive::Polarity polarity,
                                GpioPortSifive::DriveStrength strength,
                                Iof iof) {
  initOutGpio(pin, polarity, strength);
  initIof(pin, iof);
}

GpioInSifive GpioManagerSifive::initInGpio(Gpio gpio,
                                           GpioManagerSifive::PullConfig pull) {
  mmio::GPIO.initInGpio(gpio.pin, pull);
  return GpioInSifive{.port = mmio::GPIO, .pin = gpio.pin};
}
void GpioManagerSifive::initInIof(Gpio gpio,
                                  GpioManagerSifive::PullConfig pull,
                                  GpioManagerSifive::Iof iof) {
  mmio::GPIO.initInIof(gpio.pin, pull, iof);
}
GpioOutSifive GpioManagerSifive::initOutGpio(
    Gpio gpio,
    GpioManagerSifive::Polarity polarity,
    GpioManagerSifive::DriveStrength strength) {
  mmio::GPIO.initOutGpio(gpio.pin, polarity, strength);
  return GpioOutSifive{mmio::GPIO, gpio.pin, polarity};
}
void GpioManagerSifive::initOutIof(Gpio gpio,
                                   GpioManagerSifive::Polarity polarity,
                                   GpioManagerSifive::DriveStrength strength,
                                   GpioManagerSifive::Iof iof) {
  mmio::GPIO.initOutIof(gpio.pin, polarity, strength, iof);
}

}  // namespace deri::dev::gpio
