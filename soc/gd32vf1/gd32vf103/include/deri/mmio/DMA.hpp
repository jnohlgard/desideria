/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct DMA_regs {
  enum class INTF_bits : uint32_t;
  enum class INTC_bits : uint32_t;
  enum class CH0CTL_bits : uint32_t;
  enum class CH0CNT_bits : uint32_t;
  enum class CH0PADDR_bits : uint32_t;
  enum class CH0MADDR_bits : uint32_t;
  enum class CH1CTL_bits : uint32_t;
  enum class CH1CNT_bits : uint32_t;
  enum class CH1PADDR_bits : uint32_t;
  enum class CH1MADDR_bits : uint32_t;
  enum class CH2CTL_bits : uint32_t;
  enum class CH2CNT_bits : uint32_t;
  enum class CH2PADDR_bits : uint32_t;
  enum class CH2MADDR_bits : uint32_t;
  enum class CH3CTL_bits : uint32_t;
  enum class CH3CNT_bits : uint32_t;
  enum class CH3PADDR_bits : uint32_t;
  enum class CH3MADDR_bits : uint32_t;
  enum class CH4CTL_bits : uint32_t;
  enum class CH4CNT_bits : uint32_t;
  enum class CH4PADDR_bits : uint32_t;
  enum class CH4MADDR_bits : uint32_t;
  enum class CH5CTL_bits : uint32_t;
  enum class CH5CNT_bits : uint32_t;
  enum class CH5PADDR_bits : uint32_t;
  enum class CH5MADDR_bits : uint32_t;
  enum class CH6CTL_bits : uint32_t;
  enum class CH6CNT_bits : uint32_t;
  enum class CH6PADDR_bits : uint32_t;
  enum class CH6MADDR_bits : uint32_t;
  enum class INTF_shift : unsigned;
  enum class INTC_shift : unsigned;
  enum class CH0CTL_shift : unsigned;
  enum class CH0CNT_shift : unsigned;
  enum class CH0PADDR_shift : unsigned;
  enum class CH0MADDR_shift : unsigned;
  enum class CH1CTL_shift : unsigned;
  enum class CH1CNT_shift : unsigned;
  enum class CH1PADDR_shift : unsigned;
  enum class CH1MADDR_shift : unsigned;
  enum class CH2CTL_shift : unsigned;
  enum class CH2CNT_shift : unsigned;
  enum class CH2PADDR_shift : unsigned;
  enum class CH2MADDR_shift : unsigned;
  enum class CH3CTL_shift : unsigned;
  enum class CH3CNT_shift : unsigned;
  enum class CH3PADDR_shift : unsigned;
  enum class CH3MADDR_shift : unsigned;
  enum class CH4CTL_shift : unsigned;
  enum class CH4CNT_shift : unsigned;
  enum class CH4PADDR_shift : unsigned;
  enum class CH4MADDR_shift : unsigned;
  enum class CH5CTL_shift : unsigned;
  enum class CH5CNT_shift : unsigned;
  enum class CH5PADDR_shift : unsigned;
  enum class CH5MADDR_shift : unsigned;
  enum class CH6CTL_shift : unsigned;
  enum class CH6CNT_shift : unsigned;
  enum class CH6PADDR_shift : unsigned;
  enum class CH6MADDR_shift : unsigned;

  const Register<INTF_bits> INTF;
  Register<INTC_bits> INTC;
  Register<CH0CTL_bits> CH0CTL;
  Register<CH0CNT_bits> CH0CNT;
  Register<CH0PADDR_bits> CH0PADDR;
  Register<CH0MADDR_bits> CH0MADDR;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x1c
  Register<CH1CTL_bits> CH1CTL;
  Register<CH1CNT_bits> CH1CNT;
  Register<CH1PADDR_bits> CH1PADDR;
  Register<CH1MADDR_bits> CH1MADDR;
  const Reserved<uint32_t> reserved_1;
  // Base + 0x30
  Register<CH2CTL_bits> CH2CTL;
  Register<CH2CNT_bits> CH2CNT;
  Register<CH2PADDR_bits> CH2PADDR;
  Register<CH2MADDR_bits> CH2MADDR;
  const Reserved<uint32_t> reserved_2;
  // Base + 0x44
  Register<CH3CTL_bits> CH3CTL;
  Register<CH3CNT_bits> CH3CNT;
  Register<CH3PADDR_bits> CH3PADDR;
  Register<CH3MADDR_bits> CH3MADDR;
  const Reserved<uint32_t> reserved_3;
  // Base + 0x58
  Register<CH4CTL_bits> CH4CTL;
  Register<CH4CNT_bits> CH4CNT;
  Register<CH4PADDR_bits> CH4PADDR;
  Register<CH4MADDR_bits> CH4MADDR;
  const Reserved<uint32_t> reserved_4;
  // Base + 0x6c
  Register<CH5CTL_bits> CH5CTL;
  Register<CH5CNT_bits> CH5CNT;
  Register<CH5PADDR_bits> CH5PADDR;
  Register<CH5MADDR_bits> CH5MADDR;
  const Reserved<uint32_t> reserved_5;
  // Base + 0x80
  Register<CH6CTL_bits> CH6CTL;
  Register<CH6CNT_bits> CH6CNT;
  Register<CH6PADDR_bits> CH6PADDR;
  Register<CH6MADDR_bits> CH6MADDR;
};
}  // namespace deri::mmio
