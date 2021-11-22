/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <array>
#include <cstdint>

namespace deri::mmio {
struct TIMER_regs {
  // These registers are described as 16 bits wide in the reference
  // documentation, but they allow both 16-bit and 32-bit access. There are
  // padding bytes between each register in the address map to align each
  // register to an even 32-bit address, so describing them as uint32_t just
  // makes this struct definition so much more readable because we don't need
  // to put any Reserved<uint16_t> between each register.
  enum class CTL0_bits : uint32_t;
  enum class CTL1_bits : uint32_t;
  enum class SMCFG_bits : uint32_t;
  enum class DMAINTEN_bits : uint32_t;
  enum class INTF_bits : uint32_t;
  enum class SWEVG_bits : uint32_t;
  enum class CHCTL0_Output_bits : uint32_t;
  enum class CHCTL0_Input_bits : uint32_t;
  enum class CHCTL1_Output_bits : uint32_t;
  enum class CHCTL1_Input_bits : uint32_t;
  enum class CHCTL2_bits : uint32_t;
  enum class CNT_bits : uint32_t;
  enum class PSC_bits : uint32_t;
  enum class CAR_bits : uint32_t;
  enum class CREP_bits : uint32_t;
  enum class CHxCV_bits : uint32_t;
  enum class CCHP_bits : uint32_t;
  enum class DMACFG_bits : uint32_t;
  enum class DMATB_bits : uint32_t;
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
  enum class CHxCV_shift : unsigned;
  enum class CCHP_shift : unsigned;
  enum class DMACFG_shift : unsigned;
  enum class DMATB_shift : unsigned;

  Register<CTL0_bits> CTL0;
  Register<CTL1_bits> CTL1;
  Register<SMCFG_bits> SMCFG;
  Register<DMAINTEN_bits> DMAINTEN;
  Register<INTF_bits> INTF;
  Register<SWEVG_bits> SWEVG;
  union CHCTL0_bits {
    Register<CHCTL0_Output_bits> out;
    Register<CHCTL0_Input_bits> in;
  };
  CHCTL0_bits CHCTL0;
  union CHCTL1_bits {
    Register<CHCTL1_Output_bits> out;
    Register<CHCTL1_Input_bits> in;
  };
  CHCTL1_bits CHCTL1;
  Register<CHCTL2_bits> CHCTL2;
  Register<CNT_bits> CNT;
  Register<PSC_bits> PSC;
  Register<CAR_bits> CAR;
  Register<CREP_bits> CREP;
  std::array<Register<CHxCV_bits>, 4> CHxCV;
  Register<CCHP_bits> CCHP;
  Register<DMACFG_bits> DMACFG;
  Register<DMATB_bits> DMATB;
};
}  // namespace deri::mmio
