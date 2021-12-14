/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#include "deri/bitwise_enums.hpp"
#include "deri/dev/uart_gd32.hpp"
#include "deri/mmio/bits/USART_bits.hpp"

namespace deri::dev::uart {

using CTL0_bits = mmio::USART_regs::CTL0_bits;
using BAUD_bits = mmio::USART_regs::BAUD_bits;
using STAT_bits = mmio::USART_regs::STAT_bits;
using DATA_bits = mmio::USART_regs::DATA_bits;

void UsartGd32::init() {
  auto ctl0 = USART.CTL0.load();
  ctl0 &= CTL0_bits::Reserved_mask;
  ctl0 |= CTL0_bits::UEN;
  USART.CTL0.store(ctl0);
}

void UsartGd32::setBaud(unsigned pclk, unsigned baudrate) {
  auto baud = USART.BAUD.load();
  baud &= BAUD_bits::Reserved_mask;
  uint32_t divider = (pclk + baudrate / 2) / baudrate;
  baud |= static_cast<BAUD_bits>(divider) &
          (BAUD_bits::INTDIV_mask | BAUD_bits::FRADIV_mask);
  USART.BAUD.store(baud);
}

auto UsartGd32::write(std::span<const std::byte> buffer) -> decltype(buffer) {
  while (!buffer.empty() && USART.STAT.any(STAT_bits::TBE)) {
    USART.DATA.store(static_cast<DATA_bits>(buffer.front()));
    USART.CTL0 |= CTL0_bits::TEN;
    buffer = buffer.last(buffer.size() - 1);
  }
  return buffer;
}

static_assert(sizeof(UsartGd32) == 0x1C);

}  // namespace deri::dev::uart
