/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/USBFS_GLOBAL.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for USBFS_GLOBAL GOTGCS
 *
 * Global OTG control and status register (USBFS_GOTGCS)
 */
enum class USBFS_GLOBAL_regs::GOTGCS_bits : uint32_t {
  SRPS = (1u << 0),           ///< SRP success
  SRPREQ = (1u << 1),         ///< SRP request
  HNPS = (1u << 8),           ///< Host success
  HNPREQ = (1u << 9),         ///< HNP request
  HHNPEN = (1u << 10),        ///< Host HNP enable
  DHNPEN = (1u << 11),        ///< Device HNP enabled
  IDPS = (1u << 16),          ///< ID pin status
  DI = (1u << 17),            ///< Debounce interval
  ASV = (1u << 18),           ///< A-session valid
  BSV = (1u << 19),           ///< B-session valid
  Reserved_mask = 0xfff0f0fc  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GOTGCS_bits);

/**
 * Bit shifts for USBFS_GLOBAL GOTGCS
 */
enum class USBFS_GLOBAL_regs::GOTGCS_shift : unsigned {
  SRPS = 0,
  SRPREQ = 1,
  HNPS = 8,
  HNPREQ = 9,
  HHNPEN = 10,
  DHNPEN = 11,
  IDPS = 16,
  DI = 17,
  ASV = 18,
  BSV = 19,
};

/**
 * Bitmasks for USBFS_GLOBAL GOTGINTF
 *
 * Global OTG interrupt flag register (USBFS_GOTGINTF)
 */
enum class USBFS_GLOBAL_regs::GOTGINTF_bits : uint32_t {
  SESEND = (1u << 2),         ///< Session end
  SRPEND = (1u << 8),         ///< Session request success status change
  HNPEND = (1u << 9),         ///< HNP end
  HNPDET = (1u << 17),        ///< Host negotiation request detected
  ADTO = (1u << 18),          ///< A-device timeout
  DF = (1u << 19),            ///< Debounce finish
  Reserved_mask = 0xfff1fcfb  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GOTGINTF_bits);

/**
 * Bit shifts for USBFS_GLOBAL GOTGINTF
 */
enum class USBFS_GLOBAL_regs::GOTGINTF_shift : unsigned {
  SESEND = 2,
  SRPEND = 8,
  HNPEND = 9,
  HNPDET = 17,
  ADTO = 18,
  DF = 19,
};

/**
 * Bitmasks for USBFS_GLOBAL GAHBCS
 *
 * Global AHB control and status register (USBFS_GAHBCS)
 */
enum class USBFS_GLOBAL_regs::GAHBCS_bits : uint32_t {
  GINTEN = (1u << 0),         ///< Global interrupt enable
  TXFTH = (1u << 7),          ///< Tx FIFO threshold
  PTXFTH = (1u << 8),         ///< Periodic Tx FIFO threshold
  Reserved_mask = 0xfffffe7e  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GAHBCS_bits);

/**
 * Bit shifts for USBFS_GLOBAL GAHBCS
 */
enum class USBFS_GLOBAL_regs::GAHBCS_shift : unsigned {
  GINTEN = 0,
  TXFTH = 7,
  PTXFTH = 8,
};

/**
 * Bitmasks for USBFS_GLOBAL GUSBCS
 *
 * Global USB control and status register (USBFS_GUSBCSR)
 */
enum class USBFS_GLOBAL_regs::GUSBCS_bits : uint32_t {
  TOC_mask = (0x7u << 0),     ///< Timeout calibration
  SRPCEN = (1u << 8),         ///< SRP capability enable
  HNPCEN = (1u << 9),         ///< HNP capability enable
  UTT_mask = (0xfu << 10),    ///< USB turnaround time
  FHM = (1u << 29),           ///< Force host mode
  FDM = (1u << 30),           ///< Force device mode
  Reserved_mask = 0x9fffc0f8  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GUSBCS_bits);

/**
 * Bit shifts for USBFS_GLOBAL GUSBCS
 */
enum class USBFS_GLOBAL_regs::GUSBCS_shift : unsigned {
  TOC = 0,
  SRPCEN = 8,
  HNPCEN = 9,
  UTT = 10,
  FHM = 29,
  FDM = 30,
};

/**
 * Bitmasks for USBFS_GLOBAL GRSTCTL
 *
 * Global reset control register (USBFS_GRSTCTL)
 */
enum class USBFS_GLOBAL_regs::GRSTCTL_bits : uint32_t {
  CSRST = (1u << 0),           ///< Core soft reset
  HCSRST = (1u << 1),          ///< HCLK soft reset
  HFCRST = (1u << 2),          ///< Host frame counter reset
  RXFF = (1u << 4),            ///< RxFIFO flush
  TXFF = (1u << 5),            ///< TxFIFO flush
  TXFNUM_mask = (0x1fu << 6),  ///< TxFIFO number
  Reserved_mask = 0xfffff808   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GRSTCTL_bits);

/**
 * Bit shifts for USBFS_GLOBAL GRSTCTL
 */
enum class USBFS_GLOBAL_regs::GRSTCTL_shift : unsigned {
  CSRST = 0,
  HCSRST = 1,
  HFCRST = 2,
  RXFF = 4,
  TXFF = 5,
  TXFNUM = 6,
};

/**
 * Bitmasks for USBFS_GLOBAL GINTF
 *
 * Global interrupt flag register (USBFS_GINTF)
 */
enum class USBFS_GLOBAL_regs::GINTF_bits : uint32_t {
  COPM = (1u << 0),       ///< Current operation mode
  MFIF = (1u << 1),       ///< Mode fault interrupt flag
  OTGIF = (1u << 2),      ///< OTG interrupt flag
  SOF = (1u << 3),        ///< Start of frame
  RXFNEIF = (1u << 4),    ///< RxFIFO non-empty interrupt flag
  NPTXFEIF = (1u << 5),   ///< Non-periodic TxFIFO empty interrupt flag
  GNPINAK = (1u << 6),    ///< Global Non-Periodic IN NAK effective
  GONAK = (1u << 7),      ///< Global OUT NAK effective
  ESP = (1u << 10),       ///< Early suspend
  SP = (1u << 11),        ///< USB suspend
  RST = (1u << 12),       ///< USB reset
  ENUMF = (1u << 13),     ///< Enumeration finished
  ISOOPDIF = (1u << 14),  ///< Isochronous OUT packet dropped interrupt
  EOPFIF = (1u << 15),    ///< End of periodic frame interrupt flag
  IEPIF = (1u << 18),     ///< IN endpoint interrupt flag
  OEPIF = (1u << 19),     ///< OUT endpoint interrupt flag
  ISOINCIF =
      (1u << 20),  ///< Isochronous IN transfer Not Complete Interrupt Flag
  PXNCIF_ISOONCIF = (1u << 21),  ///< periodic transfer not complete interrupt
                                 ///< flag(Host mode)/isochronous OUT transfer
                                 ///< not complete interrupt flag(Device mode)
  HPIF = (1u << 24),             ///< Host port interrupt flag
  HCIF = (1u << 25),             ///< Host channels interrupt flag
  PTXFEIF = (1u << 26),          ///< Periodic TxFIFO empty interrupt flag
  IDPSC = (1u << 28),            ///< ID pin status change
  DISCIF = (1u << 29),           ///< Disconnect interrupt flag
  SESIF = (1u << 30),            ///< Session interrupt flag
  WKUPIF = (1u << 31),           ///< Wakeup interrupt flag
  Reserved_mask = 0x08c30300     ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GINTF_bits);

/**
 * Bit shifts for USBFS_GLOBAL GINTF
 */
enum class USBFS_GLOBAL_regs::GINTF_shift : unsigned {
  COPM = 0,
  MFIF = 1,
  OTGIF = 2,
  SOF = 3,
  RXFNEIF = 4,
  NPTXFEIF = 5,
  GNPINAK = 6,
  GONAK = 7,
  ESP = 10,
  SP = 11,
  RST = 12,
  ENUMF = 13,
  ISOOPDIF = 14,
  EOPFIF = 15,
  IEPIF = 18,
  OEPIF = 19,
  ISOINCIF = 20,
  PXNCIF_ISOONCIF = 21,
  HPIF = 24,
  HCIF = 25,
  PTXFEIF = 26,
  IDPSC = 28,
  DISCIF = 29,
  SESIF = 30,
  WKUPIF = 31,
};

/**
 * Bitmasks for USBFS_GLOBAL GINTEN
 *
 * Global interrupt enable register (USBFS_GINTEN)
 */
enum class USBFS_GLOBAL_regs::GINTEN_bits : uint32_t {
  MFIE = (1u << 1),      ///< Mode fault interrupt enable
  OTGIE = (1u << 2),     ///< OTG interrupt enable
  SOFIE = (1u << 3),     ///< Start of frame interrupt enable
  RXFNEIE = (1u << 4),   ///< Receive FIFO non-empty interrupt enable
  NPTXFEIE = (1u << 5),  ///< Non-periodic TxFIFO empty interrupt enable
  GNPINAKIE =
      (1u << 6),  ///< Global non-periodic IN NAK effective interrupt enable
  GONAKIE = (1u << 7),    ///< Global OUT NAK effective interrupt enable
  ESPIE = (1u << 10),     ///< Early suspend interrupt enable
  SPIE = (1u << 11),      ///< USB suspend interrupt enable
  RSTIE = (1u << 12),     ///< USB reset interrupt enable
  ENUMFIE = (1u << 13),   ///< Enumeration finish interrupt enable
  ISOOPDIE = (1u << 14),  ///< Isochronous OUT packet dropped interrupt enable
  EOPFIE = (1u << 15),    ///< End of periodic frame interrupt enable
  IEPIE = (1u << 18),     ///< IN endpoints interrupt enable
  OEPIE = (1u << 19),     ///< OUT endpoints interrupt enable
  ISOINCIE =
      (1u << 20),  ///< isochronous IN transfer not complete interrupt enable
  PXNCIE_ISOONCIE = (1u << 21),  ///< periodic transfer not compelete Interrupt
                                 ///< enable(Host mode)/isochronous OUT transfer
                                 ///< not complete interrupt enable(Device mode)
  HPIE = (1u << 24),             ///< Host port interrupt enable
  HCIE = (1u << 25),             ///< Host channels interrupt enable
  PTXFEIE = (1u << 26),          ///< Periodic TxFIFO empty interrupt enable
  IDPSCIE = (1u << 28),          ///< ID pin status change interrupt enable
  DISCIE = (1u << 29),           ///< Disconnect interrupt enable
  SESIE = (1u << 30),            ///< Session interrupt enable
  WKUPIE = (1u << 31),           ///< Wakeup interrupt enable
  Reserved_mask = 0x08c30301     ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GINTEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL GINTEN
 */
enum class USBFS_GLOBAL_regs::GINTEN_shift : unsigned {
  MFIE = 1,
  OTGIE = 2,
  SOFIE = 3,
  RXFNEIE = 4,
  NPTXFEIE = 5,
  GNPINAKIE = 6,
  GONAKIE = 7,
  ESPIE = 10,
  SPIE = 11,
  RSTIE = 12,
  ENUMFIE = 13,
  ISOOPDIE = 14,
  EOPFIE = 15,
  IEPIE = 18,
  OEPIE = 19,
  ISOINCIE = 20,
  PXNCIE_ISOONCIE = 21,
  HPIE = 24,
  HCIE = 25,
  PTXFEIE = 26,
  IDPSCIE = 28,
  DISCIE = 29,
  SESIE = 30,
  WKUPIE = 31,
};

/**
 * Bitmasks for USBFS_GLOBAL GRSTATR_Device
 *
 * Global Receive status read(Device mode)
 */
enum class USBFS_GLOBAL_regs::GRSTATR_Device_bits : uint32_t {
  EPNUM_mask = (0xfu << 0),     ///< Endpoint number
  BCOUNT_mask = (0x7ffu << 4),  ///< Byte count
  DPID_mask = (0x3u << 15),     ///< Data PID
  RPCKST_mask = (0xfu << 17),   ///< Recieve packet status
  Reserved_mask = 0xffe00000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GRSTATR_Device_bits);

/**
 * Bit shifts for USBFS_GLOBAL GRSTATR_Device
 */
enum class USBFS_GLOBAL_regs::GRSTATR_Device_shift : unsigned {
  EPNUM = 0,
  BCOUNT = 4,
  DPID = 15,
  RPCKST = 17,
};

/**
 * Bitmasks for USBFS_GLOBAL GRSTATR_Host
 *
 * Global Receive status read(Host mode)
 */
enum class USBFS_GLOBAL_regs::GRSTATR_Host_bits : uint32_t {
  CNUM_mask = (0xfu << 0),      ///< Channel number
  BCOUNT_mask = (0x7ffu << 4),  ///< Byte count
  DPID_mask = (0x3u << 15),     ///< Data PID
  RPCKST_mask = (0xfu << 17),   ///< Reivece packet status
  Reserved_mask = 0xffe00000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GRSTATR_Host_bits);

/**
 * Bit shifts for USBFS_GLOBAL GRSTATR_Host
 */
enum class USBFS_GLOBAL_regs::GRSTATR_Host_shift : unsigned {
  CNUM = 0,
  BCOUNT = 4,
  DPID = 15,
  RPCKST = 17,
};

/**
 * Bitmasks for USBFS_GLOBAL GRSTATP_Device
 *
 * Global Receive status pop(Device mode)
 */
enum class USBFS_GLOBAL_regs::GRSTATP_Device_bits : uint32_t {
  EPNUM_mask = (0xfu << 0),     ///< Endpoint number
  BCOUNT_mask = (0x7ffu << 4),  ///< Byte count
  DPID_mask = (0x3u << 15),     ///< Data PID
  RPCKST_mask = (0xfu << 17),   ///< Recieve packet status
  Reserved_mask = 0xffe00000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GRSTATP_Device_bits);

/**
 * Bit shifts for USBFS_GLOBAL GRSTATP_Device
 */
enum class USBFS_GLOBAL_regs::GRSTATP_Device_shift : unsigned {
  EPNUM = 0,
  BCOUNT = 4,
  DPID = 15,
  RPCKST = 17,
};

/**
 * Bitmasks for USBFS_GLOBAL GRSTATP_Host
 *
 * Global Receive status pop(Host mode)
 */
enum class USBFS_GLOBAL_regs::GRSTATP_Host_bits : uint32_t {
  CNUM_mask = (0xfu << 0),      ///< Channel number
  BCOUNT_mask = (0x7ffu << 4),  ///< Byte count
  DPID_mask = (0x3u << 15),     ///< Data PID
  RPCKST_mask = (0xfu << 17),   ///< Reivece packet status
  Reserved_mask = 0xffe00000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GRSTATP_Host_bits);

/**
 * Bit shifts for USBFS_GLOBAL GRSTATP_Host
 */
enum class USBFS_GLOBAL_regs::GRSTATP_Host_shift : unsigned {
  CNUM = 0,
  BCOUNT = 4,
  DPID = 15,
  RPCKST = 17,
};

/**
 * Bitmasks for USBFS_GLOBAL GRFLEN
 *
 * Global Receive FIFO size register (USBFS_GRFLEN)
 */
enum class USBFS_GLOBAL_regs::GRFLEN_bits : uint32_t {
  RXFD_mask = (0xffffu << 0),  ///< Rx FIFO depth
  Reserved_mask = 0xffff0000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GRFLEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL GRFLEN
 */
enum class USBFS_GLOBAL_regs::GRFLEN_shift : unsigned {
  RXFD = 0,
};

/**
 * Bitmasks for USBFS_GLOBAL HNPTFLEN
 *
 * Host non-periodic transmit FIFO length register (Host mode)
 */
enum class USBFS_GLOBAL_regs::HNPTFLEN_bits : uint32_t {
  HNPTXRSAR_mask =
      (0xffffu << 0),  ///< host non-periodic transmit Tx RAM start address
  HNPTXFD_mask = (0xffffu << 16),  ///< host non-periodic TxFIFO depth
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::HNPTFLEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL HNPTFLEN
 */
enum class USBFS_GLOBAL_regs::HNPTFLEN_shift : unsigned {
  HNPTXRSAR = 0,
  HNPTXFD = 16,
};

/**
 * Bitmasks for USBFS_GLOBAL DIEP0TFLEN
 *
 * Device IN endpoint 0 transmit FIFO length (Device mode)
 */
enum class USBFS_GLOBAL_regs::DIEP0TFLEN_bits : uint32_t {
  IEP0TXFD_mask = (0xffffu << 16),   ///< in endpoint 0 Tx FIFO depth
  IEP0TXRSAR_mask = (0xffffu << 0),  ///< in endpoint 0 Tx RAM start address
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::DIEP0TFLEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL DIEP0TFLEN
 */
enum class USBFS_GLOBAL_regs::DIEP0TFLEN_shift : unsigned {
  IEP0TXFD = 16,
  IEP0TXRSAR = 0,
};

/**
 * Bitmasks for USBFS_GLOBAL HNPTFQSTAT
 *
 * Host non-periodic transmit FIFO/queue status register (HNPTFQSTAT)
 */
enum class USBFS_GLOBAL_regs::HNPTFQSTAT_bits : uint32_t {
  NPTXFS_mask = (0xffffu << 0),  ///< Non-periodic TxFIFO space
  NPTXRQS_mask = (0xffu << 16),  ///< Non-periodic transmit request queue space
  NPTXRQTOP_mask =
      (0x7fu << 24),  ///< Top of the non-periodic transmit request queue
  Reserved_mask = 0x80000000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::HNPTFQSTAT_bits);

/**
 * Bit shifts for USBFS_GLOBAL HNPTFQSTAT
 */
enum class USBFS_GLOBAL_regs::HNPTFQSTAT_shift : unsigned {
  NPTXFS = 0,
  NPTXRQS = 16,
  NPTXRQTOP = 24,
};

/**
 * Bitmasks for USBFS_GLOBAL GCCFG
 *
 * Global core configuration register (USBFS_GCCFG)
 */
enum class USBFS_GLOBAL_regs::GCCFG_bits : uint32_t {
  PWRON = (1u << 16),         ///< Power on
  VBUSACEN = (1u << 18),      ///< The VBUS A-device Comparer enable
  VBUSBCEN = (1u << 19),      ///< The VBUS B-device Comparer enable
  SOFOEN = (1u << 20),        ///< SOF output enable
  VBUSIG = (1u << 21),        ///< VBUS ignored
  Reserved_mask = 0xffc2ffff  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::GCCFG_bits);

/**
 * Bit shifts for USBFS_GLOBAL GCCFG
 */
enum class USBFS_GLOBAL_regs::GCCFG_shift : unsigned {
  PWRON = 16,
  VBUSACEN = 18,
  VBUSBCEN = 19,
  SOFOEN = 20,
  VBUSIG = 21,
};

/**
 * Bitmasks for USBFS_GLOBAL CID
 *
 * core ID register
 */
enum class USBFS_GLOBAL_regs::CID_bits : uint32_t {
  CID_mask = (0xffffffffu << 0),  ///< Core ID
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::CID_bits);

/**
 * Bit shifts for USBFS_GLOBAL CID
 */
enum class USBFS_GLOBAL_regs::CID_shift : unsigned {
  CID = 0,
};

/**
 * Bitmasks for USBFS_GLOBAL HPTFLEN
 *
 * Host periodic transmit FIFO length register (HPTFLEN)
 */
enum class USBFS_GLOBAL_regs::HPTFLEN_bits : uint32_t {
  HPTXFSAR_mask = (0xffffu << 0),  ///< Host periodic TxFIFO start address
  HPTXFD_mask = (0xffffu << 16),   ///< Host periodic TxFIFO depth
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::HPTFLEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL HPTFLEN
 */
enum class USBFS_GLOBAL_regs::HPTFLEN_shift : unsigned {
  HPTXFSAR = 0,
  HPTXFD = 16,
};

/**
 * Bitmasks for USBFS_GLOBAL DIEP1TFLEN
 *
 * device IN endpoint transmit FIFO size register (DIEP1TFLEN)
 */
enum class USBFS_GLOBAL_regs::DIEP1TFLEN_bits : uint32_t {
  IEPTXRSAR_mask =
      (0xffffu << 0),  ///< IN endpoint FIFO transmit RAM start address
  IEPTXFD_mask = (0xffffu << 16),  ///< IN endpoint TxFIFO depth
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::DIEP1TFLEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL DIEP1TFLEN
 */
enum class USBFS_GLOBAL_regs::DIEP1TFLEN_shift : unsigned {
  IEPTXRSAR = 0,
  IEPTXFD = 16,
};

/**
 * Bitmasks for USBFS_GLOBAL DIEP2TFLEN
 *
 * device IN endpoint transmit FIFO size register (DIEP2TFLEN)
 */
enum class USBFS_GLOBAL_regs::DIEP2TFLEN_bits : uint32_t {
  IEPTXRSAR_mask =
      (0xffffu << 0),  ///< IN endpoint FIFO transmit RAM start address
  IEPTXFD_mask = (0xffffu << 16),  ///< IN endpoint TxFIFO depth
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::DIEP2TFLEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL DIEP2TFLEN
 */
enum class USBFS_GLOBAL_regs::DIEP2TFLEN_shift : unsigned {
  IEPTXRSAR = 0,
  IEPTXFD = 16,
};

/**
 * Bitmasks for USBFS_GLOBAL DIEP3TFLEN
 *
 * device IN endpoint transmit FIFO size register (FS_DIEP3TXFLEN)
 */
enum class USBFS_GLOBAL_regs::DIEP3TFLEN_bits : uint32_t {
  IEPTXRSAR_mask =
      (0xffffu << 0),  ///< IN endpoint FIFO4 transmit RAM start address
  IEPTXFD_mask = (0xffffu << 16),  ///< IN endpoint TxFIFO depth
};
void HasBitwiseOperators(USBFS_GLOBAL_regs::DIEP3TFLEN_bits);

/**
 * Bit shifts for USBFS_GLOBAL DIEP3TFLEN
 */
enum class USBFS_GLOBAL_regs::DIEP3TFLEN_shift : unsigned {
  IEPTXRSAR = 0,
  IEPTXFD = 16,
};

static_assert(offsetof(USBFS_GLOBAL_regs, GOTGCS) == 0x0);
static_assert(offsetof(USBFS_GLOBAL_regs, GOTGINTF) == 0x4);
static_assert(offsetof(USBFS_GLOBAL_regs, GAHBCS) == 0x8);
static_assert(offsetof(USBFS_GLOBAL_regs, GUSBCS) == 0xc);
static_assert(offsetof(USBFS_GLOBAL_regs, GRSTCTL) == 0x10);
static_assert(offsetof(USBFS_GLOBAL_regs, GINTF) == 0x14);
static_assert(offsetof(USBFS_GLOBAL_regs, GINTEN) == 0x18);
static_assert(offsetof(USBFS_GLOBAL_regs, GRSTATR_Device) == 0x1c);
static_assert(offsetof(USBFS_GLOBAL_regs, GRSTATR_Host) == 0x1c);
static_assert(offsetof(USBFS_GLOBAL_regs, GRSTATP_Device) == 0x20);
static_assert(offsetof(USBFS_GLOBAL_regs, GRSTATP_Host) == 0x20);
static_assert(offsetof(USBFS_GLOBAL_regs, GRFLEN) == 0x24);
static_assert(offsetof(USBFS_GLOBAL_regs, HNPTFLEN) == 0x28);
static_assert(offsetof(USBFS_GLOBAL_regs, DIEP0TFLEN) == 0x28);
static_assert(offsetof(USBFS_GLOBAL_regs, HNPTFQSTAT) == 0x2c);
static_assert(offsetof(USBFS_GLOBAL_regs, GCCFG) == 0x38);
static_assert(offsetof(USBFS_GLOBAL_regs, CID) == 0x3c);
static_assert(offsetof(USBFS_GLOBAL_regs, HPTFLEN) == 0x100);
static_assert(offsetof(USBFS_GLOBAL_regs, DIEP1TFLEN) == 0x104);
static_assert(offsetof(USBFS_GLOBAL_regs, DIEP2TFLEN) == 0x108);
static_assert(offsetof(USBFS_GLOBAL_regs, DIEP3TFLEN) == 0x10c);
}  // namespace deri::mmio
