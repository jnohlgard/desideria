/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/USBFS_HOST.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for USBFS_HOST HCTL
 *
 * host configuration register (HCTL)
 */
enum class USBFS_HOST_regs::HCTL_bits : uint32_t {
  CLKSEL_mask = (0x3 << 0),   ///< clock select for USB clock
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCTL_bits);

/**
 * Bit shifts for USBFS_HOST HCTL
 */
enum class USBFS_HOST_regs::HCTL_shift : unsigned {
  CLKSEL = 0,
};

/**
 * Bitmasks for USBFS_HOST HFT
 *
 * Host frame interval register
 */
enum class USBFS_HOST_regs::HFT_bits : uint32_t {
  FRI_mask = (0xffff << 0),   ///< Frame interval
  Reserved_mask = 0xffff0000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HFT_bits);

/**
 * Bit shifts for USBFS_HOST HFT
 */
enum class USBFS_HOST_regs::HFT_shift : unsigned {
  FRI = 0,
};

/**
 * Bitmasks for USBFS_HOST HFINFR
 *
 * FS host frame number/frame time remaining register (HFINFR)
 */
enum class USBFS_HOST_regs::HFINFR_bits : uint32_t {
  FRNUM_mask = (0xffff << 0),  ///< Frame number
  FRT_mask = (0xffff << 16),   ///< Frame remaining time
};
void HasBitwiseOperators(USBFS_HOST_regs::HFINFR_bits);

/**
 * Bit shifts for USBFS_HOST HFINFR
 */
enum class USBFS_HOST_regs::HFINFR_shift : unsigned {
  FRNUM = 0,
  FRT = 16,
};

/**
 * Bitmasks for USBFS_HOST HPTFQSTAT
 *
 * Host periodic transmit FIFO/queue status register (HPTFQSTAT)
 */
enum class USBFS_HOST_regs::HPTFQSTAT_bits : uint32_t {
  PTXFS_mask = (0xffff << 0),  ///< Periodic transmit data FIFO space available
  PTXREQS_mask =
      (0xff << 16),  ///< Periodic transmit request queue space available
  PTXREQT_mask = (0xff << 24),  ///< Top of the periodic transmit request queue
};
void HasBitwiseOperators(USBFS_HOST_regs::HPTFQSTAT_bits);

/**
 * Bit shifts for USBFS_HOST HPTFQSTAT
 */
enum class USBFS_HOST_regs::HPTFQSTAT_shift : unsigned {
  PTXFS = 0,
  PTXREQS = 16,
  PTXREQT = 24,
};

/**
 * Bitmasks for USBFS_HOST HACHINT
 *
 * Host all channels interrupt register
 */
enum class USBFS_HOST_regs::HACHINT_bits : uint32_t {
  HACHINT_mask = (0xff << 0),  ///< Host all channel interrupts
  Reserved_mask = 0xffffff00   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HACHINT_bits);

/**
 * Bit shifts for USBFS_HOST HACHINT
 */
enum class USBFS_HOST_regs::HACHINT_shift : unsigned {
  HACHINT = 0,
};

/**
 * Bitmasks for USBFS_HOST HACHINTEN
 *
 * host all channels interrupt mask register
 */
enum class USBFS_HOST_regs::HACHINTEN_bits : uint32_t {
  CINTEN_mask = (0xff << 0),  ///< Channel interrupt enable
  Reserved_mask = 0xffffff00  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HACHINTEN_bits);

/**
 * Bit shifts for USBFS_HOST HACHINTEN
 */
enum class USBFS_HOST_regs::HACHINTEN_shift : unsigned {
  CINTEN = 0,
};

/**
 * Bitmasks for USBFS_HOST HPCS
 *
 * Host port control and status register (USBFS_HPCS)
 */
enum class USBFS_HOST_regs::HPCS_bits : uint32_t {
  PCST = (1 << 0),            ///< Port connect status
  PCD = (1 << 1),             ///< Port connect detected
  PE = (1 << 2),              ///< Port enable
  PEDC = (1 << 3),            ///< Port enable/disable change
  PREM = (1 << 6),            ///< Port resume
  PSP = (1 << 7),             ///< Port suspend
  PRST = (1 << 8),            ///< Port reset
  PLST_mask = (0x3 << 10),    ///< Port line status
  PP = (1 << 12),             ///< Port power
  PS_mask = (0x3 << 17),      ///< Port speed
  Reserved_mask = 0xfff9e230  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HPCS_bits);

/**
 * Bit shifts for USBFS_HOST HPCS
 */
enum class USBFS_HOST_regs::HPCS_shift : unsigned {
  PCST = 0,
  PCD = 1,
  PE = 2,
  PEDC = 3,
  PREM = 6,
  PSP = 7,
  PRST = 8,
  PLST = 10,
  PP = 12,
  PS = 17,
};

/**
 * Bitmasks for USBFS_HOST HCH0CTL
 *
 * host channel-0 characteristics register (HCH0CTL)
 */
enum class USBFS_HOST_regs::HCH0CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH0CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH0CTL
 */
enum class USBFS_HOST_regs::HCH0CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH0INTF
 *
 * host channel-0 interrupt register (USBFS_HCHxINTF)
 */
enum class USBFS_HOST_regs::HCH0INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH0INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH0INTF
 */
enum class USBFS_HOST_regs::HCH0INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH0INTEN
 *
 * host channel-0 interrupt enable register (HCH0INTEN)
 */
enum class USBFS_HOST_regs::HCH0INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH0INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH0INTEN
 */
enum class USBFS_HOST_regs::HCH0INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH0LEN
 *
 * host channel-0 transfer length register
 */
enum class USBFS_HOST_regs::HCH0LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH0LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH0LEN
 */
enum class USBFS_HOST_regs::HCH0LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

/**
 * Bitmasks for USBFS_HOST HCH1CTL
 *
 * host channel-1 characteristics register (HCH1CTL)
 */
enum class USBFS_HOST_regs::HCH1CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH1CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH1CTL
 */
enum class USBFS_HOST_regs::HCH1CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH1INTF
 *
 * host channel-1 interrupt register (HCH1INTF)
 */
enum class USBFS_HOST_regs::HCH1INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH1INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH1INTF
 */
enum class USBFS_HOST_regs::HCH1INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH1INTEN
 *
 * host channel-1 interrupt enable register (HCH1INTEN)
 */
enum class USBFS_HOST_regs::HCH1INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH1INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH1INTEN
 */
enum class USBFS_HOST_regs::HCH1INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH1LEN
 *
 * host channel-1 transfer length register
 */
enum class USBFS_HOST_regs::HCH1LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH1LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH1LEN
 */
enum class USBFS_HOST_regs::HCH1LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

/**
 * Bitmasks for USBFS_HOST HCH2CTL
 *
 * host channel-2 characteristics register (HCH2CTL)
 */
enum class USBFS_HOST_regs::HCH2CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH2CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH2CTL
 */
enum class USBFS_HOST_regs::HCH2CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH2INTF
 *
 * host channel-2 interrupt register (HCH2INTF)
 */
enum class USBFS_HOST_regs::HCH2INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH2INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH2INTF
 */
enum class USBFS_HOST_regs::HCH2INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH2INTEN
 *
 * host channel-2 interrupt enable register (HCH2INTEN)
 */
enum class USBFS_HOST_regs::HCH2INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH2INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH2INTEN
 */
enum class USBFS_HOST_regs::HCH2INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH2LEN
 *
 * host channel-2 transfer length register
 */
enum class USBFS_HOST_regs::HCH2LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH2LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH2LEN
 */
enum class USBFS_HOST_regs::HCH2LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

/**
 * Bitmasks for USBFS_HOST HCH3CTL
 *
 * host channel-3 characteristics register (HCH3CTL)
 */
enum class USBFS_HOST_regs::HCH3CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH3CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH3CTL
 */
enum class USBFS_HOST_regs::HCH3CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH3INTF
 *
 * host channel-3 interrupt register (HCH3INTF)
 */
enum class USBFS_HOST_regs::HCH3INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH3INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH3INTF
 */
enum class USBFS_HOST_regs::HCH3INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH3INTEN
 *
 * host channel-3 interrupt enable register (HCH3INTEN)
 */
enum class USBFS_HOST_regs::HCH3INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH3INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH3INTEN
 */
enum class USBFS_HOST_regs::HCH3INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH3LEN
 *
 * host channel-3 transfer length register
 */
enum class USBFS_HOST_regs::HCH3LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH3LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH3LEN
 */
enum class USBFS_HOST_regs::HCH3LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

/**
 * Bitmasks for USBFS_HOST HCH4CTL
 *
 * host channel-4 characteristics register (HCH4CTL)
 */
enum class USBFS_HOST_regs::HCH4CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH4CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH4CTL
 */
enum class USBFS_HOST_regs::HCH4CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH4INTF
 *
 * host channel-4 interrupt register (HCH4INTF)
 */
enum class USBFS_HOST_regs::HCH4INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH4INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH4INTF
 */
enum class USBFS_HOST_regs::HCH4INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH4INTEN
 *
 * host channel-4 interrupt enable register (HCH4INTEN)
 */
enum class USBFS_HOST_regs::HCH4INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH4INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH4INTEN
 */
enum class USBFS_HOST_regs::HCH4INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH4LEN
 *
 * host channel-4 transfer length register
 */
enum class USBFS_HOST_regs::HCH4LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH4LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH4LEN
 */
enum class USBFS_HOST_regs::HCH4LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

/**
 * Bitmasks for USBFS_HOST HCH5CTL
 *
 * host channel-5 characteristics register (HCH5CTL)
 */
enum class USBFS_HOST_regs::HCH5CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH5CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH5CTL
 */
enum class USBFS_HOST_regs::HCH5CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH5INTF
 *
 * host channel-5 interrupt register (HCH5INTF)
 */
enum class USBFS_HOST_regs::HCH5INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH5INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH5INTF
 */
enum class USBFS_HOST_regs::HCH5INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH5INTEN
 *
 * host channel-5 interrupt enable register (HCH5INTEN)
 */
enum class USBFS_HOST_regs::HCH5INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH5INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH5INTEN
 */
enum class USBFS_HOST_regs::HCH5INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH5LEN
 *
 * host channel-5 transfer length register
 */
enum class USBFS_HOST_regs::HCH5LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH5LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH5LEN
 */
enum class USBFS_HOST_regs::HCH5LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

/**
 * Bitmasks for USBFS_HOST HCH6CTL
 *
 * host channel-6 characteristics register (HCH6CTL)
 */
enum class USBFS_HOST_regs::HCH6CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH6CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH6CTL
 */
enum class USBFS_HOST_regs::HCH6CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH6INTF
 *
 * host channel-6 interrupt register (HCH6INTF)
 */
enum class USBFS_HOST_regs::HCH6INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH6INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH6INTF
 */
enum class USBFS_HOST_regs::HCH6INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH6INTEN
 *
 * host channel-6 interrupt enable register (HCH6INTEN)
 */
enum class USBFS_HOST_regs::HCH6INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH6INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH6INTEN
 */
enum class USBFS_HOST_regs::HCH6INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH6LEN
 *
 * host channel-6 transfer length register
 */
enum class USBFS_HOST_regs::HCH6LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH6LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH6LEN
 */
enum class USBFS_HOST_regs::HCH6LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

/**
 * Bitmasks for USBFS_HOST HCH7CTL
 *
 * host channel-7 characteristics register (HCH7CTL)
 */
enum class USBFS_HOST_regs::HCH7CTL_bits : uint32_t {
  MPL_mask = (0x7ff << 0),    ///< Maximum packet size
  EPNUM_mask = (0xf << 11),   ///< Endpoint number
  EPDIR = (1 << 15),          ///< Endpoint direction
  LSD = (1 << 17),            ///< Low-speed device
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  DAR_mask = (0x7f << 22),    ///< Device address
  ODDFRM = (1 << 29),         ///< Odd frame
  CDIS = (1 << 30),           ///< Channel disable
  CEN = (1 << 31),            ///< Channel enable
  Reserved_mask = 0x00310000  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH7CTL_bits);

/**
 * Bit shifts for USBFS_HOST HCH7CTL
 */
enum class USBFS_HOST_regs::HCH7CTL_shift : unsigned {
  MPL = 0,
  EPNUM = 11,
  EPDIR = 15,
  LSD = 17,
  EPTYPE = 18,
  DAR = 22,
  ODDFRM = 29,
  CDIS = 30,
  CEN = 31,
};

/**
 * Bitmasks for USBFS_HOST HCH7INTF
 *
 * host channel-7 interrupt register (HCH7INTF)
 */
enum class USBFS_HOST_regs::HCH7INTF_bits : uint32_t {
  TF = (1 << 0),              ///< Transfer finished
  CH = (1 << 1),              ///< Channel halted
  STALL = (1 << 3),           ///< STALL response received interrupt
  NAK = (1 << 4),             ///< NAK response received interrupt
  ACK = (1 << 5),             ///< ACK response received/transmitted interrupt
  USBER = (1 << 7),           ///< USB bus error
  BBER = (1 << 8),            ///< Babble error
  REQOVR = (1 << 9),          ///< Request queue overrun
  DTER = (1 << 10),           ///< Data toggle error
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH7INTF_bits);

/**
 * Bit shifts for USBFS_HOST HCH7INTF
 */
enum class USBFS_HOST_regs::HCH7INTF_shift : unsigned {
  TF = 0,
  CH = 1,
  STALL = 3,
  NAK = 4,
  ACK = 5,
  USBER = 7,
  BBER = 8,
  REQOVR = 9,
  DTER = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH7INTEN
 *
 * host channel-7 interrupt enable register (HCH7INTEN)
 */
enum class USBFS_HOST_regs::HCH7INTEN_bits : uint32_t {
  TFIE = (1 << 0),            ///< Transfer completed interrupt enable
  CHIE = (1 << 1),            ///< Channel halted interrupt enable
  STALLIE = (1 << 3),         ///< STALL interrupt enable
  NAKIE = (1 << 4),           ///< NAK interrupt enable
  ACKIE = (1 << 5),           ///< ACK interrupt enable
  USBERIE = (1 << 7),         ///< USB bus error interrupt enable
  BBERIE = (1 << 8),          ///< Babble error interrupt enable
  REQOVRIE = (1 << 9),        ///< request queue overrun interrupt enable
  DTERIE = (1 << 10),         ///< Data toggle error interrupt enable
  Reserved_mask = 0xfffff844  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH7INTEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH7INTEN
 */
enum class USBFS_HOST_regs::HCH7INTEN_shift : unsigned {
  TFIE = 0,
  CHIE = 1,
  STALLIE = 3,
  NAKIE = 4,
  ACKIE = 5,
  USBERIE = 7,
  BBERIE = 8,
  REQOVRIE = 9,
  DTERIE = 10,
};

/**
 * Bitmasks for USBFS_HOST HCH7LEN
 *
 * host channel-7 transfer length register
 */
enum class USBFS_HOST_regs::HCH7LEN_bits : uint32_t {
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  DPID_mask = (0x3 << 29),     ///< Data PID
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_HOST_regs::HCH7LEN_bits);

/**
 * Bit shifts for USBFS_HOST HCH7LEN
 */
enum class USBFS_HOST_regs::HCH7LEN_shift : unsigned {
  TLEN = 0,
  PCNT = 19,
  DPID = 29,
};

static_assert(offsetof(USBFS_HOST_regs, HCTL) == 0x0);
static_assert(offsetof(USBFS_HOST_regs, HFT) == 0x4);
static_assert(offsetof(USBFS_HOST_regs, HFINFR) == 0x8);
static_assert(offsetof(USBFS_HOST_regs, HPTFQSTAT) == 0x10);
static_assert(offsetof(USBFS_HOST_regs, HACHINT) == 0x14);
static_assert(offsetof(USBFS_HOST_regs, HACHINTEN) == 0x18);
static_assert(offsetof(USBFS_HOST_regs, HPCS) == 0x40);
static_assert(offsetof(USBFS_HOST_regs, HCH0CTL) == 0x100);
static_assert(offsetof(USBFS_HOST_regs, HCH1CTL) == 0x120);
static_assert(offsetof(USBFS_HOST_regs, HCH2CTL) == 0x140);
static_assert(offsetof(USBFS_HOST_regs, HCH3CTL) == 0x160);
static_assert(offsetof(USBFS_HOST_regs, HCH4CTL) == 0x180);
static_assert(offsetof(USBFS_HOST_regs, HCH5CTL) == 0x1a0);
static_assert(offsetof(USBFS_HOST_regs, HCH6CTL) == 0x1c0);
static_assert(offsetof(USBFS_HOST_regs, HCH7CTL) == 0x1e0);
static_assert(offsetof(USBFS_HOST_regs, HCH0INTF) == 0x108);
static_assert(offsetof(USBFS_HOST_regs, HCH1INTF) == 0x128);
static_assert(offsetof(USBFS_HOST_regs, HCH2INTF) == 0x148);
static_assert(offsetof(USBFS_HOST_regs, HCH3INTF) == 0x168);
static_assert(offsetof(USBFS_HOST_regs, HCH4INTF) == 0x188);
static_assert(offsetof(USBFS_HOST_regs, HCH5INTF) == 0x1a8);
static_assert(offsetof(USBFS_HOST_regs, HCH6INTF) == 0x1c8);
static_assert(offsetof(USBFS_HOST_regs, HCH7INTF) == 0x1e8);
static_assert(offsetof(USBFS_HOST_regs, HCH0INTEN) == 0x10c);
static_assert(offsetof(USBFS_HOST_regs, HCH1INTEN) == 0x12c);
static_assert(offsetof(USBFS_HOST_regs, HCH2INTEN) == 0x14c);
static_assert(offsetof(USBFS_HOST_regs, HCH3INTEN) == 0x16c);
static_assert(offsetof(USBFS_HOST_regs, HCH4INTEN) == 0x18c);
static_assert(offsetof(USBFS_HOST_regs, HCH5INTEN) == 0x1ac);
static_assert(offsetof(USBFS_HOST_regs, HCH6INTEN) == 0x1cc);
static_assert(offsetof(USBFS_HOST_regs, HCH7INTEN) == 0x1ec);
static_assert(offsetof(USBFS_HOST_regs, HCH0LEN) == 0x110);
static_assert(offsetof(USBFS_HOST_regs, HCH1LEN) == 0x130);
static_assert(offsetof(USBFS_HOST_regs, HCH2LEN) == 0x150);
static_assert(offsetof(USBFS_HOST_regs, HCH3LEN) == 0x170);
static_assert(offsetof(USBFS_HOST_regs, HCH4LEN) == 0x190);
static_assert(offsetof(USBFS_HOST_regs, HCH5LEN) == 0x1b0);
static_assert(offsetof(USBFS_HOST_regs, HCH6LEN) == 0x1d0);
static_assert(offsetof(USBFS_HOST_regs, HCH7LEN) == 0x1f0);
}  // namespace deri::mmio
