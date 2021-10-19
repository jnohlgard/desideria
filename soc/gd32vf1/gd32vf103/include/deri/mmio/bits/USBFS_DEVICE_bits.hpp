/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/USBFS_DEVICE.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for USBFS_DEVICE DCFG
 *
 * device configuration register (DCFG)
 */
enum class USBFS_DEVICE_regs::DCFG_bits : uint32_t {
  DS_mask = (0x3 << 0),       ///< Device speed
  NZLSOH = (1 << 2),          ///< Non-zero-length status OUT handshake
  DAR_mask = (0x7f << 4),     ///< Device address
  EOPFT_mask = (0x3 << 11),   ///< end of periodic frame time
  Reserved_mask = 0xffffe008  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DCFG_bits);

/**
 * Bit shifts for USBFS_DEVICE DCFG
 */
enum class USBFS_DEVICE_regs::DCFG_shift : unsigned {
  DS = 0,
  NZLSOH = 2,
  DAR = 4,
  EOPFT = 11,
};

/**
 * Bitmasks for USBFS_DEVICE DCTL
 *
 * device control register (DCTL)
 */
enum class USBFS_DEVICE_regs::DCTL_bits : uint32_t {
  RWKUP = (1 << 0),           ///< Remote wakeup
  SD = (1 << 1),              ///< Soft disconnect
  GINS = (1 << 2),            ///< Global IN NAK status
  GONS = (1 << 3),            ///< Global OUT NAK status
  SGINAK = (1 << 7),          ///< Set global IN NAK
  CGINAK = (1 << 8),          ///< Clear global IN NAK
  SGONAK = (1 << 9),          ///< Set global OUT NAK
  CGONAK = (1 << 10),         ///< Clear global OUT NAK
  POIF = (1 << 11),           ///< Power-on initialization flag
  Reserved_mask = 0xfffff070  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DCTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DCTL
 */
enum class USBFS_DEVICE_regs::DCTL_shift : unsigned {
  RWKUP = 0,
  SD = 1,
  GINS = 2,
  GONS = 3,
  SGINAK = 7,
  CGINAK = 8,
  SGONAK = 9,
  CGONAK = 10,
  POIF = 11,
};

/**
 * Bitmasks for USBFS_DEVICE DSTAT
 *
 * device status register (DSTAT)
 */
enum class USBFS_DEVICE_regs::DSTAT_bits : uint32_t {
  SPST = (1 << 0),              ///< Suspend status
  ES_mask = (0x3 << 1),         ///< Enumerated speed
  FNRSOF_mask = (0x3fff << 8),  ///< Frame number of the received SOF
  Reserved_mask = 0xffc000f8    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DSTAT_bits);

/**
 * Bit shifts for USBFS_DEVICE DSTAT
 */
enum class USBFS_DEVICE_regs::DSTAT_shift : unsigned {
  SPST = 0,
  ES = 1,
  FNRSOF = 8,
};

/**
 * Bitmasks for USBFS_DEVICE DIEPINTEN
 *
 * device IN endpoint common interrupt mask register (DIEPINTEN)
 */
enum class USBFS_DEVICE_regs::DIEPINTEN_bits : uint32_t {
  TFEN = (1 << 0),       ///< Transfer finished interrupt enable
  EPDISEN = (1 << 1),    ///< Endpoint disabled interrupt enable
  CITOEN = (1 << 3),     ///< Control IN timeout condition interrupt enable
                         ///< (Non-isochronous endpoints)
  EPTXFUDEN = (1 << 4),  ///< Endpoint Tx FIFO underrun interrupt enable bit
  IEPNEEN = (1 << 6),    ///< IN endpoint NAK effective interrupt enable
  Reserved_mask = 0xffffffa4  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEPINTEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEPINTEN
 */
enum class USBFS_DEVICE_regs::DIEPINTEN_shift : unsigned {
  TFEN = 0,
  EPDISEN = 1,
  CITOEN = 3,
  EPTXFUDEN = 4,
  IEPNEEN = 6,
};

/**
 * Bitmasks for USBFS_DEVICE DOEPINTEN
 *
 * device OUT endpoint common interrupt enable register (DOEPINTEN)
 */
enum class USBFS_DEVICE_regs::DOEPINTEN_bits : uint32_t {
  TFEN = (1 << 0),            ///< Transfer finished interrupt enable
  EPDISEN = (1 << 1),         ///< Endpoint disabled interrupt enable
  STPFEN = (1 << 3),          ///< SETUP phase finished interrupt enable
  EPRXFOVREN = (1 << 4),      ///< Endpoint Rx FIFO overrun interrupt enable
  BTBSTPEN = (1 << 6),        ///< Back-to-back SETUP packets interrupt enable
  Reserved_mask = 0xffffffa4  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEPINTEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEPINTEN
 */
enum class USBFS_DEVICE_regs::DOEPINTEN_shift : unsigned {
  TFEN = 0,
  EPDISEN = 1,
  STPFEN = 3,
  EPRXFOVREN = 4,
  BTBSTPEN = 6,
};

/**
 * Bitmasks for USBFS_DEVICE DAEPINT
 *
 * device all endpoints interrupt register (DAEPINT)
 */
enum class USBFS_DEVICE_regs::DAEPINT_bits : uint32_t {
  IEPITB_mask = (0xf << 0),   ///< Device all IN endpoint interrupt bits
  OEPITB_mask = (0xf << 16),  ///< Device all OUT endpoint interrupt bits
  Reserved_mask = 0xfff0fff0  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DAEPINT_bits);

/**
 * Bit shifts for USBFS_DEVICE DAEPINT
 */
enum class USBFS_DEVICE_regs::DAEPINT_shift : unsigned {
  IEPITB = 0,
  OEPITB = 16,
};

/**
 * Bitmasks for USBFS_DEVICE DAEPINTEN
 *
 * Device all endpoints interrupt enable register (DAEPINTEN)
 */
enum class USBFS_DEVICE_regs::DAEPINTEN_bits : uint32_t {
  IEPIE_mask = (0xf << 0),    ///< IN EP interrupt interrupt enable bits
  OEPIE_mask = (0xf << 16),   ///< OUT endpoint interrupt enable bits
  Reserved_mask = 0xfff0fff0  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DAEPINTEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DAEPINTEN
 */
enum class USBFS_DEVICE_regs::DAEPINTEN_shift : unsigned {
  IEPIE = 0,
  OEPIE = 16,
};

/**
 * Bitmasks for USBFS_DEVICE DVBUSDT
 *
 * device VBUS discharge time register
 */
enum class USBFS_DEVICE_regs::DVBUSDT_bits : uint32_t {
  DVBUSDT_mask = (0xffff << 0),  ///< Device VBUS discharge time
  Reserved_mask = 0xffff0000     ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DVBUSDT_bits);

/**
 * Bit shifts for USBFS_DEVICE DVBUSDT
 */
enum class USBFS_DEVICE_regs::DVBUSDT_shift : unsigned {
  DVBUSDT = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DVBUSPT
 *
 * device VBUS pulsing time register
 */
enum class USBFS_DEVICE_regs::DVBUSPT_bits : uint32_t {
  DVBUSPT_mask = (0xfff << 0),  ///< Device VBUS pulsing time
  Reserved_mask = 0xfffff000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DVBUSPT_bits);

/**
 * Bit shifts for USBFS_DEVICE DVBUSPT
 */
enum class USBFS_DEVICE_regs::DVBUSPT_shift : unsigned {
  DVBUSPT = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEPFEINTEN
 *
 * device IN endpoint FIFO empty interrupt enable register
 */
enum class USBFS_DEVICE_regs::DIEPFEINTEN_bits : uint32_t {
  IEPTXFEIE_mask = (0xf << 0),  ///< IN EP Tx FIFO empty interrupt enable bits
  Reserved_mask = 0xfffffff0    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEPFEINTEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEPFEINTEN
 */
enum class USBFS_DEVICE_regs::DIEPFEINTEN_shift : unsigned {
  IEPTXFEIE = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP0CTL
 *
 * device IN endpoint 0 control register (DIEP0CTL)
 */
enum class USBFS_DEVICE_regs::DIEP0CTL_bits : uint32_t {
  MPL_mask = (0x3 << 0),      ///< Maximum packet length
  EPACT = (1 << 15),          ///< endpoint active
  NAKS = (1 << 17),           ///< NAK status
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  STALL = (1 << 21),          ///< STALL handshake
  TXFNUM_mask = (0xf << 22),  ///< TxFIFO number
  CNAK = (1 << 26),           ///< Clear NAK
  SNAK = (1 << 27),           ///< Set NAK
  EPD = (1 << 30),            ///< Endpoint disable
  EPEN = (1 << 31),           ///< Endpoint enable
  Reserved_mask = 0x30117ffc  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP0CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP0CTL
 */
enum class USBFS_DEVICE_regs::DIEP0CTL_shift : unsigned {
  MPL = 0,
  EPACT = 15,
  NAKS = 17,
  EPTYPE = 18,
  STALL = 21,
  TXFNUM = 22,
  CNAK = 26,
  SNAK = 27,
  EPD = 30,
  EPEN = 31,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP0INTF
 *
 * device endpoint-0 interrupt register
 */
enum class USBFS_DEVICE_regs::DIEP0INTF_bits : uint32_t {
  TXFE = (1 << 7),            ///< Transmit FIFO empty
  IEPNE = (1 << 6),           ///< IN endpoint NAK effective
  EPTXFUD = (1 << 4),         ///< Endpoint Tx FIFO underrun
  CITO = (1 << 3),            ///< Control in timeout interrupt
  EPDIS = (1 << 1),           ///< Endpoint finished
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffff24  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP0INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP0INTF
 */
enum class USBFS_DEVICE_regs::DIEP0INTF_shift : unsigned {
  TXFE = 7,
  IEPNE = 6,
  EPTXFUD = 4,
  CITO = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP0LEN
 *
 * device IN endpoint-0 transfer length register
 */
enum class USBFS_DEVICE_regs::DIEP0LEN_bits : uint32_t {
  PCNT_mask = (0x3 << 19),    ///< Packet count
  TLEN_mask = (0x7f << 0),    ///< Transfer length
  Reserved_mask = 0xffe7ff80  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP0LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP0LEN
 */
enum class USBFS_DEVICE_regs::DIEP0LEN_shift : unsigned {
  PCNT = 19,
  TLEN = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP0TFSTAT
 *
 * device IN endpoint 0 transmit FIFO status register
 */
enum class USBFS_DEVICE_regs::DIEP0TFSTAT_bits : uint32_t {
  IEPTFS_mask = (0xffff << 0),  ///< IN endpoint TxFIFO space remaining
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP0TFSTAT_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP0TFSTAT
 */
enum class USBFS_DEVICE_regs::DIEP0TFSTAT_shift : unsigned {
  IEPTFS = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP1CTL
 *
 * device in endpoint-1 control register
 */
enum class USBFS_DEVICE_regs::DIEP1CTL_bits : uint32_t {
  EPEN = (1 << 31),             ///< Endpoint enable
  EPD = (1 << 30),              ///< Endpoint disable
  SD1PID_SODDFRM = (1 << 29),   ///< Set DATA1 PID/Set odd frame
  SD0PID_SEVENFRM = (1 << 28),  ///< SD0PID/SEVNFRM
  SNAK = (1 << 27),             ///< Set NAK
  CNAK = (1 << 26),             ///< Clear NAK
  TXFNUM_mask = (0xf << 22),    ///< Tx FIFO number
  STALL = (1 << 21),            ///< STALL handshake
  EPTYPE_mask = (0x3 << 18),    ///< Endpoint type
  NAKS = (1 << 17),             ///< NAK status
  EOFRM_DPID = (1 << 16),       ///< EOFRM/DPID
  EPACT = (1 << 15),            ///< Endpoint active
  MPL_mask = (0x7ff << 0),      ///< maximum packet length
  Reserved_mask = 0x00107800    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP1CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP1CTL
 */
enum class USBFS_DEVICE_regs::DIEP1CTL_shift : unsigned {
  EPEN = 31,
  EPD = 30,
  SD1PID_SODDFRM = 29,
  SD0PID_SEVENFRM = 28,
  SNAK = 27,
  CNAK = 26,
  TXFNUM = 22,
  STALL = 21,
  EPTYPE = 18,
  NAKS = 17,
  EOFRM_DPID = 16,
  EPACT = 15,
  MPL = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP1INTF
 *
 * device endpoint-1 interrupt register
 */
enum class USBFS_DEVICE_regs::DIEP1INTF_bits : uint32_t {
  TXFE = (1 << 7),            ///< Transmit FIFO empty
  IEPNE = (1 << 6),           ///< IN endpoint NAK effective
  EPTXFUD = (1 << 4),         ///< Endpoint Tx FIFO underrun
  CITO = (1 << 3),            ///< Control in timeout interrupt
  EPDIS = (1 << 1),           ///< Endpoint finished
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffff24  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP1INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP1INTF
 */
enum class USBFS_DEVICE_regs::DIEP1INTF_shift : unsigned {
  TXFE = 7,
  IEPNE = 6,
  EPTXFUD = 4,
  CITO = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP1LEN
 *
 * device IN endpoint-1 transfer length register
 */
enum class USBFS_DEVICE_regs::DIEP1LEN_bits : uint32_t {
  MCPF_mask = (0x3 << 29),     ///< Multi packet count per frame
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP1LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP1LEN
 */
enum class USBFS_DEVICE_regs::DIEP1LEN_shift : unsigned {
  MCPF = 29,
  PCNT = 19,
  TLEN = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP1TFSTAT
 *
 * device IN endpoint 1 transmit FIFO status register
 */
enum class USBFS_DEVICE_regs::DIEP1TFSTAT_bits : uint32_t {
  IEPTFS_mask = (0xffff << 0),  ///< IN endpoint TxFIFO space remaining
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP1TFSTAT_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP1TFSTAT
 */
enum class USBFS_DEVICE_regs::DIEP1TFSTAT_shift : unsigned {
  IEPTFS = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP2CTL
 *
 * device endpoint-2 control register
 */
enum class USBFS_DEVICE_regs::DIEP2CTL_bits : uint32_t {
  EPEN = (1 << 31),             ///< Endpoint enable
  EPD = (1 << 30),              ///< Endpoint disable
  SD1PID_SODDFRM = (1 << 29),   ///< Set DATA1 PID/Set odd frame
  SD0PID_SEVENFRM = (1 << 28),  ///< SD0PID/SEVNFRM
  SNAK = (1 << 27),             ///< Set NAK
  CNAK = (1 << 26),             ///< Clear NAK
  TXFNUM_mask = (0xf << 22),    ///< Tx FIFO number
  STALL = (1 << 21),            ///< STALL handshake
  EPTYPE_mask = (0x3 << 18),    ///< Endpoint type
  NAKS = (1 << 17),             ///< NAK status
  EOFRM_DPID = (1 << 16),       ///< EOFRM/DPID
  EPACT = (1 << 15),            ///< Endpoint active
  MPL_mask = (0x7ff << 0),      ///< maximum packet length
  Reserved_mask = 0x00107800    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP2CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP2CTL
 */
enum class USBFS_DEVICE_regs::DIEP2CTL_shift : unsigned {
  EPEN = 31,
  EPD = 30,
  SD1PID_SODDFRM = 29,
  SD0PID_SEVENFRM = 28,
  SNAK = 27,
  CNAK = 26,
  TXFNUM = 22,
  STALL = 21,
  EPTYPE = 18,
  NAKS = 17,
  EOFRM_DPID = 16,
  EPACT = 15,
  MPL = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP2INTF
 *
 * device endpoint-2 interrupt register
 */
enum class USBFS_DEVICE_regs::DIEP2INTF_bits : uint32_t {
  TXFE = (1 << 7),            ///< Transmit FIFO empty
  IEPNE = (1 << 6),           ///< IN endpoint NAK effective
  EPTXFUD = (1 << 4),         ///< Endpoint Tx FIFO underrun
  CITO = (1 << 3),            ///< Control in timeout interrupt
  EPDIS = (1 << 1),           ///< Endpoint finished
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffff24  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP2INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP2INTF
 */
enum class USBFS_DEVICE_regs::DIEP2INTF_shift : unsigned {
  TXFE = 7,
  IEPNE = 6,
  EPTXFUD = 4,
  CITO = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP2LEN
 *
 * device IN endpoint-2 transfer length register
 */
enum class USBFS_DEVICE_regs::DIEP2LEN_bits : uint32_t {
  MCPF_mask = (0x3 << 29),     ///< Multi packet count per frame
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP2LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP2LEN
 */
enum class USBFS_DEVICE_regs::DIEP2LEN_shift : unsigned {
  MCPF = 29,
  PCNT = 19,
  TLEN = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP2TFSTAT
 *
 * device IN endpoint 2 transmit FIFO status register
 */
enum class USBFS_DEVICE_regs::DIEP2TFSTAT_bits : uint32_t {
  IEPTFS_mask = (0xffff << 0),  ///< IN endpoint TxFIFO space remaining
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP2TFSTAT_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP2TFSTAT
 */
enum class USBFS_DEVICE_regs::DIEP2TFSTAT_shift : unsigned {
  IEPTFS = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP3CTL
 *
 * device endpoint-3 control register
 */
enum class USBFS_DEVICE_regs::DIEP3CTL_bits : uint32_t {
  EPEN = (1 << 31),             ///< Endpoint enable
  EPD = (1 << 30),              ///< Endpoint disable
  SD1PID_SODDFRM = (1 << 29),   ///< Set DATA1 PID/Set odd frame
  SD0PID_SEVENFRM = (1 << 28),  ///< SD0PID/SEVNFRM
  SNAK = (1 << 27),             ///< Set NAK
  CNAK = (1 << 26),             ///< Clear NAK
  TXFNUM_mask = (0xf << 22),    ///< Tx FIFO number
  STALL = (1 << 21),            ///< STALL handshake
  EPTYPE_mask = (0x3 << 18),    ///< Endpoint type
  NAKS = (1 << 17),             ///< NAK status
  EOFRM_DPID = (1 << 16),       ///< EOFRM/DPID
  EPACT = (1 << 15),            ///< Endpoint active
  MPL_mask = (0x7ff << 0),      ///< maximum packet length
  Reserved_mask = 0x00107800    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP3CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP3CTL
 */
enum class USBFS_DEVICE_regs::DIEP3CTL_shift : unsigned {
  EPEN = 31,
  EPD = 30,
  SD1PID_SODDFRM = 29,
  SD0PID_SEVENFRM = 28,
  SNAK = 27,
  CNAK = 26,
  TXFNUM = 22,
  STALL = 21,
  EPTYPE = 18,
  NAKS = 17,
  EOFRM_DPID = 16,
  EPACT = 15,
  MPL = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP3INTF
 *
 * device endpoint-3 interrupt register
 */
enum class USBFS_DEVICE_regs::DIEP3INTF_bits : uint32_t {
  TXFE = (1 << 7),            ///< Transmit FIFO empty
  IEPNE = (1 << 6),           ///< IN endpoint NAK effective
  EPTXFUD = (1 << 4),         ///< Endpoint Tx FIFO underrun
  CITO = (1 << 3),            ///< Control in timeout interrupt
  EPDIS = (1 << 1),           ///< Endpoint finished
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffff24  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP3INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP3INTF
 */
enum class USBFS_DEVICE_regs::DIEP3INTF_shift : unsigned {
  TXFE = 7,
  IEPNE = 6,
  EPTXFUD = 4,
  CITO = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP3LEN
 *
 * device IN endpoint-3 transfer length register
 */
enum class USBFS_DEVICE_regs::DIEP3LEN_bits : uint32_t {
  MCPF_mask = (0x3 << 29),     ///< Multi packet count per frame
  PCNT_mask = (0x3ff << 19),   ///< Packet count
  TLEN_mask = (0x7ffff << 0),  ///< Transfer length
  Reserved_mask = 0x80000000   ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP3LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP3LEN
 */
enum class USBFS_DEVICE_regs::DIEP3LEN_shift : unsigned {
  MCPF = 29,
  PCNT = 19,
  TLEN = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DIEP3TFSTAT
 *
 * device IN endpoint 3 transmit FIFO status register
 */
enum class USBFS_DEVICE_regs::DIEP3TFSTAT_bits : uint32_t {
  IEPTFS_mask = (0xffff << 0),  ///< IN endpoint TxFIFO space remaining
  Reserved_mask = 0xffff0000    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DIEP3TFSTAT_bits);

/**
 * Bit shifts for USBFS_DEVICE DIEP3TFSTAT
 */
enum class USBFS_DEVICE_regs::DIEP3TFSTAT_shift : unsigned {
  IEPTFS = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP0CTL
 *
 * device endpoint-0 control register
 */
enum class USBFS_DEVICE_regs::DOEP0CTL_bits : uint32_t {
  EPEN = (1 << 31),           ///< Endpoint enable
  EPD = (1 << 30),            ///< Endpoint disable
  SNAK = (1 << 27),           ///< Set NAK
  CNAK = (1 << 26),           ///< Clear NAK
  STALL = (1 << 21),          ///< STALL handshake
  SNOOP = (1 << 20),          ///< Snoop mode
  EPTYPE_mask = (0x3 << 18),  ///< Endpoint type
  NAKS = (1 << 17),           ///< NAK status
  EPACT = (1 << 15),          ///< Endpoint active
  MPL_mask = (0x3 << 0),      ///< Maximum packet length
  Reserved_mask = 0x33c17ffc  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP0CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP0CTL
 */
enum class USBFS_DEVICE_regs::DOEP0CTL_shift : unsigned {
  EPEN = 31,
  EPD = 30,
  SNAK = 27,
  CNAK = 26,
  STALL = 21,
  SNOOP = 20,
  EPTYPE = 18,
  NAKS = 17,
  EPACT = 15,
  MPL = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP0INTF
 *
 * device out endpoint-0 interrupt flag register
 */
enum class USBFS_DEVICE_regs::DOEP0INTF_bits : uint32_t {
  BTBSTP = (1 << 6),          ///< Back-to-back SETUP packets
  EPRXFOVR = (1 << 4),        ///< Endpoint Rx FIFO overrun
  STPF = (1 << 3),            ///< Setup phase finished
  EPDIS = (1 << 1),           ///< Endpoint disabled
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffffa4  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP0INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP0INTF
 */
enum class USBFS_DEVICE_regs::DOEP0INTF_shift : unsigned {
  BTBSTP = 6,
  EPRXFOVR = 4,
  STPF = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP0LEN
 *
 * device OUT endpoint-0 transfer length register
 */
enum class USBFS_DEVICE_regs::DOEP0LEN_bits : uint32_t {
  STPCNT_mask = (0x3 << 29),  ///< SETUP packet count
  PCNT = (1 << 19),           ///< Packet count
  TLEN_mask = (0x7f << 0),    ///< Transfer length
  Reserved_mask = 0x9ff7ff80  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP0LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP0LEN
 */
enum class USBFS_DEVICE_regs::DOEP0LEN_shift : unsigned {
  STPCNT = 29,
  PCNT = 19,
  TLEN = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP1CTL
 *
 * device endpoint-1 control register
 */
enum class USBFS_DEVICE_regs::DOEP1CTL_bits : uint32_t {
  EPEN = (1 << 31),             ///< Endpoint enable
  EPD = (1 << 30),              ///< Endpoint disable
  SD1PID_SODDFRM = (1 << 29),   ///< SD1PID/SODDFRM
  SD0PID_SEVENFRM = (1 << 28),  ///< SD0PID/SEVENFRM
  SNAK = (1 << 27),             ///< Set NAK
  CNAK = (1 << 26),             ///< Clear NAK
  STALL = (1 << 21),            ///< STALL handshake
  SNOOP = (1 << 20),            ///< Snoop mode
  EPTYPE_mask = (0x3 << 18),    ///< Endpoint type
  NAKS = (1 << 17),             ///< NAK status
  EOFRM_DPID = (1 << 16),       ///< EOFRM/DPID
  EPACT = (1 << 15),            ///< Endpoint active
  MPL_mask = (0x7ff << 0),      ///< maximum packet length
  Reserved_mask = 0x03c07800    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP1CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP1CTL
 */
enum class USBFS_DEVICE_regs::DOEP1CTL_shift : unsigned {
  EPEN = 31,
  EPD = 30,
  SD1PID_SODDFRM = 29,
  SD0PID_SEVENFRM = 28,
  SNAK = 27,
  CNAK = 26,
  STALL = 21,
  SNOOP = 20,
  EPTYPE = 18,
  NAKS = 17,
  EOFRM_DPID = 16,
  EPACT = 15,
  MPL = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP1INTF
 *
 * device out endpoint-1 interrupt flag register
 */
enum class USBFS_DEVICE_regs::DOEP1INTF_bits : uint32_t {
  BTBSTP = (1 << 6),          ///< Back-to-back SETUP packets
  EPRXFOVR = (1 << 4),        ///< Endpoint Rx FIFO overrun
  STPF = (1 << 3),            ///< Setup phase finished
  EPDIS = (1 << 1),           ///< Endpoint disabled
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffffa4  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP1INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP1INTF
 */
enum class USBFS_DEVICE_regs::DOEP1INTF_shift : unsigned {
  BTBSTP = 6,
  EPRXFOVR = 4,
  STPF = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP1LEN
 *
 * device OUT endpoint-1 transfer length register
 */
enum class USBFS_DEVICE_regs::DOEP1LEN_bits : uint32_t {
  STPCNT_RXDPID_mask = (0x3 << 29),  ///< SETUP packet count/Received data PID
  PCNT_mask = (0x3ff << 19),         ///< Packet count
  TLEN_mask = (0x7ffff << 0),        ///< Transfer length
  Reserved_mask = 0x80000000         ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP1LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP1LEN
 */
enum class USBFS_DEVICE_regs::DOEP1LEN_shift : unsigned {
  STPCNT_RXDPID = 29,
  PCNT = 19,
  TLEN = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP2CTL
 *
 * device endpoint-2 control register
 */
enum class USBFS_DEVICE_regs::DOEP2CTL_bits : uint32_t {
  EPEN = (1 << 31),             ///< Endpoint enable
  EPD = (1 << 30),              ///< Endpoint disable
  SD1PID_SODDFRM = (1 << 29),   ///< SD1PID/SODDFRM
  SD0PID_SEVENFRM = (1 << 28),  ///< SD0PID/SEVENFRM
  SNAK = (1 << 27),             ///< Set NAK
  CNAK = (1 << 26),             ///< Clear NAK
  STALL = (1 << 21),            ///< STALL handshake
  SNOOP = (1 << 20),            ///< Snoop mode
  EPTYPE_mask = (0x3 << 18),    ///< Endpoint type
  NAKS = (1 << 17),             ///< NAK status
  EOFRM_DPID = (1 << 16),       ///< EOFRM/DPID
  EPACT = (1 << 15),            ///< Endpoint active
  MPL_mask = (0x7ff << 0),      ///< maximum packet length
  Reserved_mask = 0x03c07800    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP2CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP2CTL
 */
enum class USBFS_DEVICE_regs::DOEP2CTL_shift : unsigned {
  EPEN = 31,
  EPD = 30,
  SD1PID_SODDFRM = 29,
  SD0PID_SEVENFRM = 28,
  SNAK = 27,
  CNAK = 26,
  STALL = 21,
  SNOOP = 20,
  EPTYPE = 18,
  NAKS = 17,
  EOFRM_DPID = 16,
  EPACT = 15,
  MPL = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP2INTF
 *
 * device out endpoint-2 interrupt flag register
 */
enum class USBFS_DEVICE_regs::DOEP2INTF_bits : uint32_t {
  BTBSTP = (1 << 6),          ///< Back-to-back SETUP packets
  EPRXFOVR = (1 << 4),        ///< Endpoint Rx FIFO overrun
  STPF = (1 << 3),            ///< Setup phase finished
  EPDIS = (1 << 1),           ///< Endpoint disabled
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffffa4  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP2INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP2INTF
 */
enum class USBFS_DEVICE_regs::DOEP2INTF_shift : unsigned {
  BTBSTP = 6,
  EPRXFOVR = 4,
  STPF = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP2LEN
 *
 * device OUT endpoint-2 transfer length register
 */
enum class USBFS_DEVICE_regs::DOEP2LEN_bits : uint32_t {
  STPCNT_RXDPID_mask = (0x3 << 29),  ///< SETUP packet count/Received data PID
  PCNT_mask = (0x3ff << 19),         ///< Packet count
  TLEN_mask = (0x7ffff << 0),        ///< Transfer length
  Reserved_mask = 0x80000000         ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP2LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP2LEN
 */
enum class USBFS_DEVICE_regs::DOEP2LEN_shift : unsigned {
  STPCNT_RXDPID = 29,
  PCNT = 19,
  TLEN = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP3CTL
 *
 * device endpoint-3 control register
 */
enum class USBFS_DEVICE_regs::DOEP3CTL_bits : uint32_t {
  EPEN = (1 << 31),             ///< Endpoint enable
  EPD = (1 << 30),              ///< Endpoint disable
  SD1PID_SODDFRM = (1 << 29),   ///< SD1PID/SODDFRM
  SD0PID_SEVENFRM = (1 << 28),  ///< SD0PID/SEVENFRM
  SNAK = (1 << 27),             ///< Set NAK
  CNAK = (1 << 26),             ///< Clear NAK
  STALL = (1 << 21),            ///< STALL handshake
  SNOOP = (1 << 20),            ///< Snoop mode
  EPTYPE_mask = (0x3 << 18),    ///< Endpoint type
  NAKS = (1 << 17),             ///< NAK status
  EOFRM_DPID = (1 << 16),       ///< EOFRM/DPID
  EPACT = (1 << 15),            ///< Endpoint active
  MPL_mask = (0x7ff << 0),      ///< maximum packet length
  Reserved_mask = 0x03c07800    ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP3CTL_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP3CTL
 */
enum class USBFS_DEVICE_regs::DOEP3CTL_shift : unsigned {
  EPEN = 31,
  EPD = 30,
  SD1PID_SODDFRM = 29,
  SD0PID_SEVENFRM = 28,
  SNAK = 27,
  CNAK = 26,
  STALL = 21,
  SNOOP = 20,
  EPTYPE = 18,
  NAKS = 17,
  EOFRM_DPID = 16,
  EPACT = 15,
  MPL = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP3INTF
 *
 * device out endpoint-3 interrupt flag register
 */
enum class USBFS_DEVICE_regs::DOEP3INTF_bits : uint32_t {
  BTBSTP = (1 << 6),          ///< Back-to-back SETUP packets
  EPRXFOVR = (1 << 4),        ///< Endpoint Rx FIFO overrun
  STPF = (1 << 3),            ///< Setup phase finished
  EPDIS = (1 << 1),           ///< Endpoint disabled
  TF = (1 << 0),              ///< Transfer finished
  Reserved_mask = 0xffffffa4  ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP3INTF_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP3INTF
 */
enum class USBFS_DEVICE_regs::DOEP3INTF_shift : unsigned {
  BTBSTP = 6,
  EPRXFOVR = 4,
  STPF = 3,
  EPDIS = 1,
  TF = 0,
};

/**
 * Bitmasks for USBFS_DEVICE DOEP3LEN
 *
 * device OUT endpoint-3 transfer length register
 */
enum class USBFS_DEVICE_regs::DOEP3LEN_bits : uint32_t {
  STPCNT_RXDPID_mask = (0x3 << 29),  ///< SETUP packet count/Received data PID
  PCNT_mask = (0x3ff << 19),         ///< Packet count
  TLEN_mask = (0x7ffff << 0),        ///< Transfer length
  Reserved_mask = 0x80000000         ///< All reserved bits
};
void HasBitwiseOperators(USBFS_DEVICE_regs::DOEP3LEN_bits);

/**
 * Bit shifts for USBFS_DEVICE DOEP3LEN
 */
enum class USBFS_DEVICE_regs::DOEP3LEN_shift : unsigned {
  STPCNT_RXDPID = 29,
  PCNT = 19,
  TLEN = 0,
};

static_assert(offsetof(USBFS_DEVICE_regs, DCFG) == 0x0);
static_assert(offsetof(USBFS_DEVICE_regs, DCTL) == 0x4);
static_assert(offsetof(USBFS_DEVICE_regs, DSTAT) == 0x8);
static_assert(offsetof(USBFS_DEVICE_regs, DIEPINTEN) == 0x10);
static_assert(offsetof(USBFS_DEVICE_regs, DOEPINTEN) == 0x14);
static_assert(offsetof(USBFS_DEVICE_regs, DAEPINT) == 0x18);
static_assert(offsetof(USBFS_DEVICE_regs, DAEPINTEN) == 0x1c);
static_assert(offsetof(USBFS_DEVICE_regs, DVBUSDT) == 0x28);
static_assert(offsetof(USBFS_DEVICE_regs, DVBUSPT) == 0x2c);
static_assert(offsetof(USBFS_DEVICE_regs, DIEPFEINTEN) == 0x34);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP0CTL) == 0x100);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP1CTL) == 0x120);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP2CTL) == 0x140);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP3CTL) == 0x160);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP0CTL) == 0x300);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP1CTL) == 0x320);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP2CTL) == 0x340);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP3CTL) == 0x360);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP0INTF) == 0x108);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP1INTF) == 0x128);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP2INTF) == 0x148);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP3INTF) == 0x168);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP0INTF) == 0x308);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP1INTF) == 0x328);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP2INTF) == 0x348);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP3INTF) == 0x368);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP0LEN) == 0x110);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP0LEN) == 0x310);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP1LEN) == 0x130);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP2LEN) == 0x150);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP3LEN) == 0x170);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP1LEN) == 0x330);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP2LEN) == 0x350);
static_assert(offsetof(USBFS_DEVICE_regs, DOEP3LEN) == 0x370);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP0TFSTAT) == 0x118);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP1TFSTAT) == 0x138);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP2TFSTAT) == 0x158);
static_assert(offsetof(USBFS_DEVICE_regs, DIEP3TFSTAT) == 0x178);
}  // namespace deri::mmio
