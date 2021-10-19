/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.h"

#include <cstdint>

namespace deri::mmio {
struct USBFS_DEVICE_regs {
  enum class DCFG_bits : uint32_t;
  enum class DCTL_bits : uint32_t;
  enum class DSTAT_bits : uint32_t;
  enum class DIEPINTEN_bits : uint32_t;
  enum class DOEPINTEN_bits : uint32_t;
  enum class DAEPINT_bits : uint32_t;
  enum class DAEPINTEN_bits : uint32_t;
  enum class DVBUSDT_bits : uint32_t;
  enum class DVBUSPT_bits : uint32_t;
  enum class DIEPFEINTEN_bits : uint32_t;
  enum class DIEP0CTL_bits : uint32_t;
  enum class DIEP0INTF_bits : uint32_t;
  enum class DIEP0LEN_bits : uint32_t;
  enum class DIEP0TFSTAT_bits : uint32_t;
  enum class DIEP1CTL_bits : uint32_t;
  enum class DIEP1INTF_bits : uint32_t;
  enum class DIEP1LEN_bits : uint32_t;
  enum class DIEP1TFSTAT_bits : uint32_t;
  enum class DIEP2CTL_bits : uint32_t;
  enum class DIEP2INTF_bits : uint32_t;
  enum class DIEP2LEN_bits : uint32_t;
  enum class DIEP2TFSTAT_bits : uint32_t;
  enum class DIEP3CTL_bits : uint32_t;
  enum class DIEP3INTF_bits : uint32_t;
  enum class DIEP3LEN_bits : uint32_t;
  enum class DIEP3TFSTAT_bits : uint32_t;
  enum class DOEP0CTL_bits : uint32_t;
  enum class DOEP0INTF_bits : uint32_t;
  enum class DOEP0LEN_bits : uint32_t;
  enum class DOEP1CTL_bits : uint32_t;
  enum class DOEP1INTF_bits : uint32_t;
  enum class DOEP1LEN_bits : uint32_t;
  enum class DOEP2CTL_bits : uint32_t;
  enum class DOEP2INTF_bits : uint32_t;
  enum class DOEP2LEN_bits : uint32_t;
  enum class DOEP3CTL_bits : uint32_t;
  enum class DOEP3INTF_bits : uint32_t;
  enum class DOEP3LEN_bits : uint32_t;
  enum class DCFG_shift : unsigned;
  enum class DCTL_shift : unsigned;
  enum class DSTAT_shift : unsigned;
  enum class DIEPINTEN_shift : unsigned;
  enum class DOEPINTEN_shift : unsigned;
  enum class DAEPINT_shift : unsigned;
  enum class DAEPINTEN_shift : unsigned;
  enum class DVBUSDT_shift : unsigned;
  enum class DVBUSPT_shift : unsigned;
  enum class DIEPFEINTEN_shift : unsigned;
  enum class DIEP0CTL_shift : unsigned;
  enum class DIEP0INTF_shift : unsigned;
  enum class DIEP0LEN_shift : unsigned;
  enum class DIEP0TFSTAT_shift : unsigned;
  enum class DIEP1CTL_shift : unsigned;
  enum class DIEP1INTF_shift : unsigned;
  enum class DIEP1LEN_shift : unsigned;
  enum class DIEP1TFSTAT_shift : unsigned;
  enum class DIEP2CTL_shift : unsigned;
  enum class DIEP2INTF_shift : unsigned;
  enum class DIEP2LEN_shift : unsigned;
  enum class DIEP2TFSTAT_shift : unsigned;
  enum class DIEP3CTL_shift : unsigned;
  enum class DIEP3INTF_shift : unsigned;
  enum class DIEP3LEN_shift : unsigned;
  enum class DIEP3TFSTAT_shift : unsigned;
  enum class DOEP0CTL_shift : unsigned;
  enum class DOEP0INTF_shift : unsigned;
  enum class DOEP0LEN_shift : unsigned;
  enum class DOEP1CTL_shift : unsigned;
  enum class DOEP1INTF_shift : unsigned;
  enum class DOEP1LEN_shift : unsigned;
  enum class DOEP2CTL_shift : unsigned;
  enum class DOEP2INTF_shift : unsigned;
  enum class DOEP2LEN_shift : unsigned;
  enum class DOEP3CTL_shift : unsigned;
  enum class DOEP3INTF_shift : unsigned;
  enum class DOEP3LEN_shift : unsigned;

  Register<DCFG_bits> DCFG;
  Register<DCTL_bits> DCTL;
  const Register<DSTAT_bits> DSTAT;
  const Reserved<uint32_t> reserved_0;
  // Base + 0x10
  Register<DIEPINTEN_bits> DIEPINTEN;
  Register<DOEPINTEN_bits> DOEPINTEN;
  const Register<DAEPINT_bits> DAEPINT;
  Register<DAEPINTEN_bits> DAEPINTEN;
  const Reserved<uint32_t> reserved_1[2];
  // Base + 0x28
  Register<DVBUSDT_bits> DVBUSDT;
  Register<DVBUSPT_bits> DVBUSPT;
  const Reserved<uint32_t> reserved_2;
  // Base + 0x34
  Register<DIEPFEINTEN_bits> DIEPFEINTEN;
  const Reserved<uint32_t> reserved_3[50];
  // Base + 0x100
  Register<DIEP0CTL_bits> DIEP0CTL;
  const Reserved<uint32_t> reserved_4;
  // Base + 0x108
  Register<DIEP0INTF_bits> DIEP0INTF;
  const Reserved<uint32_t> reserved_5;
  // Base + 0x110
  Register<DIEP0LEN_bits> DIEP0LEN;
  const Reserved<uint32_t> reserved_6;
  // Base + 0x118
  const Register<DIEP0TFSTAT_bits> DIEP0TFSTAT;
  const Reserved<uint32_t> reserved_7;
  // Base + 0x120
  Register<DIEP1CTL_bits> DIEP1CTL;
  const Reserved<uint32_t> reserved_8;
  // Base + 0x128
  Register<DIEP1INTF_bits> DIEP1INTF;
  const Reserved<uint32_t> reserved_9;
  // Base + 0x130
  Register<DIEP1LEN_bits> DIEP1LEN;
  const Reserved<uint32_t> reserved_10;
  // Base + 0x138
  const Register<DIEP1TFSTAT_bits> DIEP1TFSTAT;
  const Reserved<uint32_t> reserved_11;
  // Base + 0x140
  Register<DIEP2CTL_bits> DIEP2CTL;
  const Reserved<uint32_t> reserved_12;
  // Base + 0x148
  Register<DIEP2INTF_bits> DIEP2INTF;
  const Reserved<uint32_t> reserved_13;
  // Base + 0x150
  Register<DIEP2LEN_bits> DIEP2LEN;
  const Reserved<uint32_t> reserved_14;
  // Base + 0x158
  const Register<DIEP2TFSTAT_bits> DIEP2TFSTAT;
  const Reserved<uint32_t> reserved_15;
  // Base + 0x160
  Register<DIEP3CTL_bits> DIEP3CTL;
  const Reserved<uint32_t> reserved_16;
  // Base + 0x168
  Register<DIEP3INTF_bits> DIEP3INTF;
  const Reserved<uint32_t> reserved_17;
  // Base + 0x170
  Register<DIEP3LEN_bits> DIEP3LEN;
  const Reserved<uint32_t> reserved_18;
  // Base + 0x178
  const Register<DIEP3TFSTAT_bits> DIEP3TFSTAT;
  const Reserved<uint32_t> reserved_19[97];
  // Base + 0x300
  Register<DOEP0CTL_bits> DOEP0CTL;
  const Reserved<uint32_t> reserved_20;
  // Base + 0x308
  Register<DOEP0INTF_bits> DOEP0INTF;
  const Reserved<uint32_t> reserved_21;
  // Base + 0x310
  Register<DOEP0LEN_bits> DOEP0LEN;
  const Reserved<uint32_t> reserved_22[3];
  // Base + 0x320
  Register<DOEP1CTL_bits> DOEP1CTL;
  const Reserved<uint32_t> reserved_23;
  // Base + 0x328
  Register<DOEP1INTF_bits> DOEP1INTF;
  const Reserved<uint32_t> reserved_24;
  // Base + 0x330
  Register<DOEP1LEN_bits> DOEP1LEN;
  const Reserved<uint32_t> reserved_25[3];
  // Base + 0x340
  Register<DOEP2CTL_bits> DOEP2CTL;
  const Reserved<uint32_t> reserved_26;
  // Base + 0x348
  Register<DOEP2INTF_bits> DOEP2INTF;
  const Reserved<uint32_t> reserved_27;
  // Base + 0x350
  Register<DOEP2LEN_bits> DOEP2LEN;
  const Reserved<uint32_t> reserved_28[3];
  // Base + 0x360
  Register<DOEP3CTL_bits> DOEP3CTL;
  const Reserved<uint32_t> reserved_29;
  // Base + 0x368
  Register<DOEP3INTF_bits> DOEP3INTF;
  const Reserved<uint32_t> reserved_30;
  // Base + 0x370
  Register<DOEP3LEN_bits> DOEP3LEN;
};
}  // namespace deri::mmio
