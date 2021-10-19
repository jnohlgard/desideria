/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct USBFS_HOST_regs {
  enum class HCTL_bits : uint32_t;
  enum class HFT_bits : uint32_t;
  enum class HFINFR_bits : uint32_t;
  enum class HPTFQSTAT_bits : uint32_t;
  enum class HACHINT_bits : uint32_t;
  enum class HACHINTEN_bits : uint32_t;
  enum class HPCS_bits : uint32_t;
  enum class HCH0CTL_bits : uint32_t;
  enum class HCH0INTF_bits : uint32_t;
  enum class HCH0INTEN_bits : uint32_t;
  enum class HCH0LEN_bits : uint32_t;
  enum class HCH1CTL_bits : uint32_t;
  enum class HCH1INTF_bits : uint32_t;
  enum class HCH1INTEN_bits : uint32_t;
  enum class HCH1LEN_bits : uint32_t;
  enum class HCH2CTL_bits : uint32_t;
  enum class HCH2INTF_bits : uint32_t;
  enum class HCH2INTEN_bits : uint32_t;
  enum class HCH2LEN_bits : uint32_t;
  enum class HCH3CTL_bits : uint32_t;
  enum class HCH3INTF_bits : uint32_t;
  enum class HCH3INTEN_bits : uint32_t;
  enum class HCH3LEN_bits : uint32_t;
  enum class HCH4CTL_bits : uint32_t;
  enum class HCH4INTF_bits : uint32_t;
  enum class HCH4INTEN_bits : uint32_t;
  enum class HCH4LEN_bits : uint32_t;
  enum class HCH5CTL_bits : uint32_t;
  enum class HCH5INTF_bits : uint32_t;
  enum class HCH5INTEN_bits : uint32_t;
  enum class HCH5LEN_bits : uint32_t;
  enum class HCH6CTL_bits : uint32_t;
  enum class HCH6INTF_bits : uint32_t;
  enum class HCH6INTEN_bits : uint32_t;
  enum class HCH6LEN_bits : uint32_t;
  enum class HCH7CTL_bits : uint32_t;
  enum class HCH7INTF_bits : uint32_t;
  enum class HCH7INTEN_bits : uint32_t;
  enum class HCH7LEN_bits : uint32_t;
  enum class HCTL_shift : unsigned;
  enum class HFT_shift : unsigned;
  enum class HFINFR_shift : unsigned;
  enum class HPTFQSTAT_shift : unsigned;
  enum class HACHINT_shift : unsigned;
  enum class HACHINTEN_shift : unsigned;
  enum class HPCS_shift : unsigned;
  enum class HCH0CTL_shift : unsigned;
  enum class HCH0INTF_shift : unsigned;
  enum class HCH0INTEN_shift : unsigned;
  enum class HCH0LEN_shift : unsigned;
  enum class HCH1CTL_shift : unsigned;
  enum class HCH1INTF_shift : unsigned;
  enum class HCH1INTEN_shift : unsigned;
  enum class HCH1LEN_shift : unsigned;
  enum class HCH2CTL_shift : unsigned;
  enum class HCH2INTF_shift : unsigned;
  enum class HCH2INTEN_shift : unsigned;
  enum class HCH2LEN_shift : unsigned;
  enum class HCH3CTL_shift : unsigned;
  enum class HCH3INTF_shift : unsigned;
  enum class HCH3INTEN_shift : unsigned;
  enum class HCH3LEN_shift : unsigned;
  enum class HCH4CTL_shift : unsigned;
  enum class HCH4INTF_shift : unsigned;
  enum class HCH4INTEN_shift : unsigned;
  enum class HCH4LEN_shift : unsigned;
  enum class HCH5CTL_shift : unsigned;
  enum class HCH5INTF_shift : unsigned;
  enum class HCH5INTEN_shift : unsigned;
  enum class HCH5LEN_shift : unsigned;
  enum class HCH6CTL_shift : unsigned;
  enum class HCH6INTF_shift : unsigned;
  enum class HCH6INTEN_shift : unsigned;
  enum class HCH6LEN_shift : unsigned;
  enum class HCH7CTL_shift : unsigned;
  enum class HCH7INTF_shift : unsigned;
  enum class HCH7INTEN_shift : unsigned;
  enum class HCH7LEN_shift : unsigned;

  Register<HCTL_bits> HCTL;
  Register<HFT_bits> HFT;
  const Register<HFINFR_bits> HFINFR;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x10
  Register<HPTFQSTAT_bits> HPTFQSTAT;
  const Register<HACHINT_bits> HACHINT;
  Register<HACHINTEN_bits> HACHINTEN;
  const Reserved<uint32_t> reserved_1[9];
  // Base + 0x40
  Register<HPCS_bits> HPCS;
  const Reserved<uint32_t> reserved_2[47];
  // Base + 0x100
  Register<HCH0CTL_bits> HCH0CTL;
  const Reserved<uint32_t> reserved_3;
  // Base + 0x108
  Register<HCH0INTF_bits> HCH0INTF;
  Register<HCH0INTEN_bits> HCH0INTEN;
  Register<HCH0LEN_bits> HCH0LEN;
  const Reserved<uint32_t> reserved_4[3];
  // Base + 0x120
  Register<HCH1CTL_bits> HCH1CTL;
  const Reserved<uint32_t> reserved_5;
  // Base + 0x128
  Register<HCH1INTF_bits> HCH1INTF;
  Register<HCH1INTEN_bits> HCH1INTEN;
  Register<HCH1LEN_bits> HCH1LEN;
  const Reserved<uint32_t> reserved_6[3];
  // Base + 0x140
  Register<HCH2CTL_bits> HCH2CTL;
  const Reserved<uint32_t> reserved_7;
  // Base + 0x148
  Register<HCH2INTF_bits> HCH2INTF;
  Register<HCH2INTEN_bits> HCH2INTEN;
  Register<HCH2LEN_bits> HCH2LEN;
  const Reserved<uint32_t> reserved_8[3];
  // Base + 0x160
  Register<HCH3CTL_bits> HCH3CTL;
  const Reserved<uint32_t> reserved_9;
  // Base + 0x168
  Register<HCH3INTF_bits> HCH3INTF;
  Register<HCH3INTEN_bits> HCH3INTEN;
  Register<HCH3LEN_bits> HCH3LEN;
  const Reserved<uint32_t> reserved_10[3];
  // Base + 0x180
  Register<HCH4CTL_bits> HCH4CTL;
  const Reserved<uint32_t> reserved_11;
  // Base + 0x188
  Register<HCH4INTF_bits> HCH4INTF;
  Register<HCH4INTEN_bits> HCH4INTEN;
  Register<HCH4LEN_bits> HCH4LEN;
  const Reserved<uint32_t> reserved_12[3];
  // Base + 0x1a0
  Register<HCH5CTL_bits> HCH5CTL;
  const Reserved<uint32_t> reserved_13;
  // Base + 0x1a8
  Register<HCH5INTF_bits> HCH5INTF;
  Register<HCH5INTEN_bits> HCH5INTEN;
  Register<HCH5LEN_bits> HCH5LEN;
  const Reserved<uint32_t> reserved_14[3];
  // Base + 0x1c0
  Register<HCH6CTL_bits> HCH6CTL;
  const Reserved<uint32_t> reserved_15;
  // Base + 0x1c8
  Register<HCH6INTF_bits> HCH6INTF;
  Register<HCH6INTEN_bits> HCH6INTEN;
  Register<HCH6LEN_bits> HCH6LEN;
  const Reserved<uint32_t> reserved_16[3];
  // Base + 0x1e0
  Register<HCH7CTL_bits> HCH7CTL;
  const Reserved<uint32_t> reserved_17;
  // Base + 0x1e8
  Register<HCH7INTF_bits> HCH7INTF;
  Register<HCH7INTEN_bits> HCH7INTEN;
  Register<HCH7LEN_bits> HCH7LEN;
};
}  // namespace deri::mmio
