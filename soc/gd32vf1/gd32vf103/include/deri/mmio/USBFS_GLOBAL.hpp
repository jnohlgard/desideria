/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/registers.hpp"

#include <cstdint>

namespace deri::mmio {
struct USBFS_GLOBAL_regs {
  enum class GOTGCS_bits : uint32_t;
  enum class GOTGINTF_bits : uint32_t;
  enum class GAHBCS_bits : uint32_t;
  enum class GUSBCS_bits : uint32_t;
  enum class GRSTCTL_bits : uint32_t;
  enum class GINTF_bits : uint32_t;
  enum class GINTEN_bits : uint32_t;
  enum class GRSTATR_Device_bits : uint32_t;
  enum class GRSTATR_Host_bits : uint32_t;
  enum class GRSTATP_Device_bits : uint32_t;
  enum class GRSTATP_Host_bits : uint32_t;
  enum class GRFLEN_bits : uint32_t;
  enum class HNPTFLEN_bits : uint32_t;
  enum class DIEP0TFLEN_bits : uint32_t;
  enum class HNPTFQSTAT_bits : uint32_t;
  enum class GCCFG_bits : uint32_t;
  enum class CID_bits : uint32_t;
  enum class HPTFLEN_bits : uint32_t;
  enum class DIEP1TFLEN_bits : uint32_t;
  enum class DIEP2TFLEN_bits : uint32_t;
  enum class DIEP3TFLEN_bits : uint32_t;
  enum class GOTGCS_shift : unsigned;
  enum class GOTGINTF_shift : unsigned;
  enum class GAHBCS_shift : unsigned;
  enum class GUSBCS_shift : unsigned;
  enum class GRSTCTL_shift : unsigned;
  enum class GINTF_shift : unsigned;
  enum class GINTEN_shift : unsigned;
  enum class GRSTATR_Device_shift : unsigned;
  enum class GRSTATR_Host_shift : unsigned;
  enum class GRSTATP_Device_shift : unsigned;
  enum class GRSTATP_Host_shift : unsigned;
  enum class GRFLEN_shift : unsigned;
  enum class HNPTFLEN_shift : unsigned;
  enum class DIEP0TFLEN_shift : unsigned;
  enum class HNPTFQSTAT_shift : unsigned;
  enum class GCCFG_shift : unsigned;
  enum class CID_shift : unsigned;
  enum class HPTFLEN_shift : unsigned;
  enum class DIEP1TFLEN_shift : unsigned;
  enum class DIEP2TFLEN_shift : unsigned;
  enum class DIEP3TFLEN_shift : unsigned;

  Register<GOTGCS_bits> GOTGCS;
  Register<GOTGINTF_bits> GOTGINTF;
  Register<GAHBCS_bits> GAHBCS;
  Register<GUSBCS_bits> GUSBCS;
  Register<GRSTCTL_bits> GRSTCTL;
  Register<GINTF_bits> GINTF;
  Register<GINTEN_bits> GINTEN;
  const Register<GRSTATR_Device_bits> GRSTATR_Device;
  const Register<GRSTATR_Host_bits> GRSTATR_Host;
  const Register<GRSTATP_Device_bits> GRSTATP_Device;
  const Register<GRSTATP_Host_bits> GRSTATP_Host;
  Register<GRFLEN_bits> GRFLEN;
  Register<HNPTFLEN_bits> HNPTFLEN;
  Register<DIEP0TFLEN_bits> DIEP0TFLEN;
  const Register<HNPTFQSTAT_bits> HNPTFQSTAT;
  Register<GCCFG_bits> GCCFG;
  Register<CID_bits> CID;
  const Reserved<uint32_t> reserved_0[47];
  // Base + 0x100
  Register<HPTFLEN_bits> HPTFLEN;
  Register<DIEP1TFLEN_bits> DIEP1TFLEN;
  Register<DIEP2TFLEN_bits> DIEP2TFLEN;
  Register<DIEP3TFLEN_bits> DIEP3TFLEN;
};
}  // namespace deri::mmio
