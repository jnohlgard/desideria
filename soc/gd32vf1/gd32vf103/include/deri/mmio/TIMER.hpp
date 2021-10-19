/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct TIMER_regs {
  enum class CTL0_bits : uint16_t;
  enum class CTL1_bits : uint16_t;
  enum class SMCFG_bits : uint16_t;
  enum class DMAINTEN_bits : uint16_t;
  enum class INTF_bits : uint16_t;
  enum class SWEVG_bits : uint16_t;
  enum class CHCTL0_Output_bits : uint16_t;
  enum class CHCTL0_Input_bits : uint16_t;
  enum class CHCTL1_Output_bits : uint16_t;
  enum class CHCTL1_Input_bits : uint16_t;
  enum class CHCTL2_bits : uint16_t;
  enum class CNT_bits : uint16_t;
  enum class PSC_bits : uint16_t;
  enum class CAR_bits : uint16_t;
  enum class CREP_bits : uint16_t;
  enum class CH0CV_bits : uint16_t;
  enum class CH1CV_bits : uint16_t;
  enum class CH2CV_bits : uint16_t;
  enum class CH3CV_bits : uint16_t;
  enum class CCHP_bits : uint16_t;
  enum class DMACFG_bits : uint16_t;
  enum class DMATB_bits : uint16_t;
  enum class CTL0_shift : unsigned;
  enum class CTL1_shift : unsigned;
  enum class SMCFG_shift : unsigned;
  enum class DMAINTEN_shift : unsigned;
  enum class INTF_shift : unsigned;
  enum class SWEVG_shift : unsigned;
  enum class CHCTL0_Output_shift : unsigned;
  enum class CHCTL0_Input_shift : unsigned;
  enum class CHCTL1_Output_shift : unsigned;
  enum class CHCTL1_Input_shift : unsigned;
  enum class CHCTL2_shift : unsigned;
  enum class CNT_shift : unsigned;
  enum class PSC_shift : unsigned;
  enum class CAR_shift : unsigned;
  enum class CREP_shift : unsigned;
  enum class CH0CV_shift : unsigned;
  enum class CH1CV_shift : unsigned;
  enum class CH2CV_shift : unsigned;
  enum class CH3CV_shift : unsigned;
  enum class CCHP_shift : unsigned;
  enum class DMACFG_shift : unsigned;
  enum class DMATB_shift : unsigned;

  Register<CTL0_bits> CTL0;
  const Reserved<uint16_t> reserved_0;
  // Base + 0x4
  Register<CTL1_bits> CTL1;
  const Reserved<uint16_t> reserved_1;
  // Base + 0x8
  Register<SMCFG_bits> SMCFG;
  const Reserved<uint16_t> reserved_2;
  // Base + 0xc
  Register<DMAINTEN_bits> DMAINTEN;
  const Reserved<uint16_t> reserved_3;
  // Base + 0x10
  Register<INTF_bits> INTF;
  const Reserved<uint16_t> reserved_4;
  // Base + 0x14
  Register<SWEVG_bits> SWEVG;
  const Reserved<uint16_t> reserved_5;
  // Base + 0x18
  Register<CHCTL0_Output_bits> CHCTL0_Output;
  Register<CHCTL0_Input_bits> CHCTL0_Input;
  Register<CHCTL1_Output_bits> CHCTL1_Output;
  Register<CHCTL1_Input_bits> CHCTL1_Input;
  Register<CHCTL2_bits> CHCTL2;
  const Reserved<uint16_t> reserved_6;
  // Base + 0x24
  Register<CNT_bits> CNT;
  const Reserved<uint16_t> reserved_7;
  // Base + 0x28
  Register<PSC_bits> PSC;
  const Reserved<uint16_t> reserved_8;
  // Base + 0x2c
  Register<CAR_bits> CAR;
  const Reserved<uint16_t> reserved_9;
  // Base + 0x30
  Register<CREP_bits> CREP;
  const Reserved<uint16_t> reserved_10;
  // Base + 0x34
  Register<CH0CV_bits> CH0CV;
  const Reserved<uint16_t> reserved_11;
  // Base + 0x38
  Register<CH1CV_bits> CH1CV;
  const Reserved<uint16_t> reserved_12;
  // Base + 0x3c
  Register<CH2CV_bits> CH2CV;
  const Reserved<uint16_t> reserved_13;
  // Base + 0x40
  Register<CH3CV_bits> CH3CV;
  const Reserved<uint16_t> reserved_14;
  // Base + 0x44
  Register<CCHP_bits> CCHP;
  const Reserved<uint16_t> reserved_15;
  // Base + 0x48
  Register<DMACFG_bits> DMACFG;
  const Reserved<uint16_t> reserved_16;
  // Base + 0x4c
  Register<DMATB_bits> DMATB;
};
}  // namespace deri::mmio
