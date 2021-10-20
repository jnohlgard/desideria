/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/CAN.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for CAN CTL
 *
 * Control register
 */
enum class CAN_regs::CTL_bits : uint32_t {
  DFZ = (1u << 16),           ///< Debug freeze
  SWRST = (1u << 15),         ///< Software reset
  TTC = (1u << 7),            ///< Time-triggered communication
  ABOR = (1u << 6),           ///< Automatic bus-off recovery
  AWU = (1u << 5),            ///< Automatic wakeup
  ARD = (1u << 4),            ///< Automatic retransmission disable
  RFOD = (1u << 3),           ///< Receive FIFO overwrite disable
  TFO = (1u << 2),            ///< Transmit FIFO order
  SLPWMOD = (1u << 1),        ///< Sleep working mode
  IWMOD = (1u << 0),          ///< Initial working mode
  Reserved_mask = 0xfffe7f00  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::CTL_bits);

/**
 * Bit shifts for CAN CTL
 */
enum class CAN_regs::CTL_shift : unsigned {
  DFZ = 16,
  SWRST = 15,
  TTC = 7,
  ABOR = 6,
  AWU = 5,
  ARD = 4,
  RFOD = 3,
  TFO = 2,
  SLPWMOD = 1,
  IWMOD = 0,
};

/**
 * Bitmasks for CAN STAT
 *
 * Status register
 */
enum class CAN_regs::STAT_bits : uint32_t {
  RXL = (1u << 11),     ///< RX level
  LASTRX = (1u << 10),  ///< Last sample value of RX pin
  RS = (1u << 9),       ///< Receiving state
  TS = (1u << 8),       ///< Transmitting state
  SLPIF =
      (1u
       << 4),  ///< Status change interrupt flag of sleep working mode entering
  WUIF = (1u << 3),   ///< Status change interrupt flag of wakeup from sleep
                      ///< working mode
  ERRIF = (1u << 2),  ///< Error interrupt flag
  SLPWS = (1u << 1),  ///< Sleep working state
  IWS = (1u << 0),    ///< Initial working state
  Reserved_mask = 0xfffff0e0  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::STAT_bits);

/**
 * Bit shifts for CAN STAT
 */
enum class CAN_regs::STAT_shift : unsigned {
  RXL = 11,
  LASTRX = 10,
  RS = 9,
  TS = 8,
  SLPIF = 4,
  WUIF = 3,
  ERRIF = 2,
  SLPWS = 1,
  IWS = 0,
};

/**
 * Bitmasks for CAN TSTAT
 *
 * Transmit status register
 */
enum class CAN_regs::TSTAT_bits : uint32_t {
  TMLS2 = (1u << 31),  ///< Transmit mailbox 2 last sending in transmit FIFO
  TMLS1 = (1u << 30),  ///< Transmit mailbox 1 last sending in transmit FIFO
  TMLS0 = (1u << 29),  ///< Transmit mailbox 0 last sending in transmit FIFO
  TME2 = (1u << 28),   ///< Transmit mailbox 2 empty
  TME1 = (1u << 27),   ///< Transmit mailbox 1 empty
  TME0 = (1u << 26),   ///< Transmit mailbox 0 empty
  NUM_mask =
      (0x3u << 24),  ///< number of the transmit FIFO mailbox in which the frame
                     ///< will be transmitted if at least one mailbox is empty
  MST2 = (1u << 23),          ///< Mailbox 2 stop transmitting
  MTE2 = (1u << 19),          ///< Mailbox 2 transmit error
  MAL2 = (1u << 18),          ///< Mailbox 2 arbitration lost
  MTFNERR2 = (1u << 17),      ///< Mailbox 2 transmit finished and no error
  MTF2 = (1u << 16),          ///< Mailbox 2 transmit finished
  MST1 = (1u << 15),          ///< Mailbox 1 stop transmitting
  MTE1 = (1u << 11),          ///< Mailbox 1 transmit error
  MAL1 = (1u << 10),          ///< Mailbox 1 arbitration lost
  MTFNERR1 = (1u << 9),       ///< Mailbox 1 transmit finished and no error
  MTF1 = (1u << 8),           ///< Mailbox 1 transmit finished
  MST0 = (1u << 7),           ///< Mailbox 0 stop transmitting
  MTE0 = (1u << 3),           ///< Mailbox 0 transmit error
  MAL0 = (1u << 2),           ///< Mailbox 0 arbitration lost
  MTFNERR0 = (1u << 1),       ///< Mailbox 0 transmit finished and no error
  MTF0 = (1u << 0),           ///< Mailbox 0 transmit finished
  Reserved_mask = 0x00707070  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::TSTAT_bits);

/**
 * Bit shifts for CAN TSTAT
 */
enum class CAN_regs::TSTAT_shift : unsigned {
  TMLS2 = 31,
  TMLS1 = 30,
  TMLS0 = 29,
  TME2 = 28,
  TME1 = 27,
  TME0 = 26,
  NUM = 24,
  MST2 = 23,
  MTE2 = 19,
  MAL2 = 18,
  MTFNERR2 = 17,
  MTF2 = 16,
  MST1 = 15,
  MTE1 = 11,
  MAL1 = 10,
  MTFNERR1 = 9,
  MTF1 = 8,
  MST0 = 7,
  MTE0 = 3,
  MAL0 = 2,
  MTFNERR0 = 1,
  MTF0 = 0,
};

/**
 * Bitmasks for CAN RFIFO0
 *
 * Receive message FIFO0 register
 */
enum class CAN_regs::RFIFO0_bits : uint32_t {
  RFD0 = (1u << 5),           ///< Receive FIFO0 dequeue
  RFO0 = (1u << 4),           ///< Receive FIFO0 overfull
  RFF0 = (1u << 3),           ///< Receive FIFO0 full
  RFL0_mask = (0x3u << 0),    ///< Receive FIFO0 length
  Reserved_mask = 0xffffffc4  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::RFIFO0_bits);

/**
 * Bit shifts for CAN RFIFO0
 */
enum class CAN_regs::RFIFO0_shift : unsigned {
  RFD0 = 5,
  RFO0 = 4,
  RFF0 = 3,
  RFL0 = 0,
};

/**
 * Bitmasks for CAN RFIFO1
 *
 * Receive message FIFO1 register
 */
enum class CAN_regs::RFIFO1_bits : uint32_t {
  RFD1 = (1u << 5),           ///< Receive FIFO1 dequeue
  RFO1 = (1u << 4),           ///< Receive FIFO1 overfull
  RFF1 = (1u << 3),           ///< Receive FIFO1 full
  RFL1_mask = (0x3u << 0),    ///< Receive FIFO1 length
  Reserved_mask = 0xffffffc4  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::RFIFO1_bits);

/**
 * Bit shifts for CAN RFIFO1
 */
enum class CAN_regs::RFIFO1_shift : unsigned {
  RFD1 = 5,
  RFO1 = 4,
  RFF1 = 3,
  RFL1 = 0,
};

/**
 * Bitmasks for CAN INTEN
 *
 * Interrupt enable register
 */
enum class CAN_regs::INTEN_bits : uint32_t {
  SLPWIE = (1u << 17),        ///< Sleep working interrupt enable
  WIE = (1u << 16),           ///< Wakeup interrupt enable
  ERRIE = (1u << 15),         ///< Error interrupt enable
  ERRNIE = (1u << 11),        ///< Error number interrupt enable
  BOIE = (1u << 10),          ///< Bus-off interrupt enable
  PERRIE = (1u << 9),         ///< Passive error interrupt enable
  WERRIE = (1u << 8),         ///< Warning error interrupt enable
  RFOIE1 = (1u << 6),         ///< Receive FIFO1 overfull interrupt enable
  RFFIE1 = (1u << 5),         ///< Receive FIFO1 full interrupt enable
  RFNEIE1 = (1u << 4),        ///< Receive FIFO1 not empty interrupt enable
  RFOIE0 = (1u << 3),         ///< Receive FIFO0 overfull interrupt enable
  RFFIE0 = (1u << 2),         ///< Receive FIFO0 full interrupt enable
  RFNEIE0 = (1u << 1),        ///< Receive FIFO0 not empty interrupt enable
  TMEIE = (1u << 0),          ///< Transmit mailbox empty interrupt enable
  Reserved_mask = 0xfffc7080  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::INTEN_bits);

/**
 * Bit shifts for CAN INTEN
 */
enum class CAN_regs::INTEN_shift : unsigned {
  SLPWIE = 17,
  WIE = 16,
  ERRIE = 15,
  ERRNIE = 11,
  BOIE = 10,
  PERRIE = 9,
  WERRIE = 8,
  RFOIE1 = 6,
  RFFIE1 = 5,
  RFNEIE1 = 4,
  RFOIE0 = 3,
  RFFIE0 = 2,
  RFNEIE0 = 1,
  TMEIE = 0,
};

/**
 * Bitmasks for CAN ERR
 *
 * Error register
 */
enum class CAN_regs::ERR_bits : uint32_t {
  RECNT_mask =
      (0xffu << 24),  ///< Receive Error Count defined by the CAN standard
  TECNT_mask =
      (0xffu << 16),  ///< Transmit Error Count defined by the CAN standard
  ERRN_mask = (0x7u << 4),    ///< Error number
  BOERR = (1u << 2),          ///< Bus-off error
  PERR = (1u << 1),           ///< Passive error
  WERR = (1u << 0),           ///< Warning error
  Reserved_mask = 0x0000ff88  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::ERR_bits);

/**
 * Bit shifts for CAN ERR
 */
enum class CAN_regs::ERR_shift : unsigned {
  RECNT = 24,
  TECNT = 16,
  ERRN = 4,
  BOERR = 2,
  PERR = 1,
  WERR = 0,
};

/**
 * Bitmasks for CAN BT
 *
 * Bit timing register
 */
enum class CAN_regs::BT_bits : uint32_t {
  SCMOD = (1u << 31),            ///< Silent communication mode
  LCMOD = (1u << 30),            ///< Loopback communication mode
  SJW_mask = (0x3u << 24),       ///< Resynchronization jump width
  BS2_mask = (0x7u << 20),       ///< Bit segment 2
  BS1_mask = (0xfu << 16),       ///< Bit segment 1
  BAUDPSC_mask = (0x3ffu << 0),  ///< Baud rate prescaler
  Reserved_mask = 0x3c80fc00     ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::BT_bits);

/**
 * Bit shifts for CAN BT
 */
enum class CAN_regs::BT_shift : unsigned {
  SCMOD = 31,
  LCMOD = 30,
  SJW = 24,
  BS2 = 20,
  BS1 = 16,
  BAUDPSC = 0,
};

/**
 * Bitmasks for CAN TMI0
 *
 * Transmit mailbox identifier register 0
 */
enum class CAN_regs::TMI0_bits : uint32_t {
  SFID_EFID_mask = (0x7ffu << 21),  ///< The frame identifier
  EFID_mask = (0x3ffffu << 3),      ///< The frame identifier
  FF = (1u << 2),                   ///< Frame format
  FT = (1u << 1),                   ///< Frame type
  TEN = (1u << 0),                  ///< Transmit enable
};
void HasBitwiseOperators(CAN_regs::TMI0_bits);

/**
 * Bit shifts for CAN TMI0
 */
enum class CAN_regs::TMI0_shift : unsigned {
  SFID_EFID = 21,
  EFID = 3,
  FF = 2,
  FT = 1,
  TEN = 0,
};

/**
 * Bitmasks for CAN TMP0
 *
 * Transmit mailbox property register 0
 */
enum class CAN_regs::TMP0_bits : uint32_t {
  TS_mask = (0xffffu << 16),  ///< Time stamp
  TSEN = (1u << 8),           ///< Time stamp enable
  DLENC_mask = (0xfu << 0),   ///< Data length code
  Reserved_mask = 0x0000fef0  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::TMP0_bits);

/**
 * Bit shifts for CAN TMP0
 */
enum class CAN_regs::TMP0_shift : unsigned {
  TS = 16,
  TSEN = 8,
  DLENC = 0,
};

/**
 * Bitmasks for CAN TMDATA00
 *
 * Transmit mailbox data0 register
 */
enum class CAN_regs::TMDATA00_bits : uint32_t {
  DB3_mask = (0xffu << 24),  ///< Data byte 3
  DB2_mask = (0xffu << 16),  ///< Data byte 2
  DB1_mask = (0xffu << 8),   ///< Data byte 1
  DB0_mask = (0xffu << 0),   ///< Data byte 0
};
void HasBitwiseOperators(CAN_regs::TMDATA00_bits);

/**
 * Bit shifts for CAN TMDATA00
 */
enum class CAN_regs::TMDATA00_shift : unsigned {
  DB3 = 24,
  DB2 = 16,
  DB1 = 8,
  DB0 = 0,
};

/**
 * Bitmasks for CAN TMDATA10
 *
 * Transmit mailbox data1 register
 */
enum class CAN_regs::TMDATA10_bits : uint32_t {
  DB7_mask = (0xffu << 24),  ///< Data byte 7
  DB6_mask = (0xffu << 16),  ///< Data byte 6
  DB5_mask = (0xffu << 8),   ///< Data byte 5
  DB4_mask = (0xffu << 0),   ///< Data byte 4
};
void HasBitwiseOperators(CAN_regs::TMDATA10_bits);

/**
 * Bit shifts for CAN TMDATA10
 */
enum class CAN_regs::TMDATA10_shift : unsigned {
  DB7 = 24,
  DB6 = 16,
  DB5 = 8,
  DB4 = 0,
};

/**
 * Bitmasks for CAN TMI1
 *
 * Transmit mailbox identifier register 1
 */
enum class CAN_regs::TMI1_bits : uint32_t {
  SFID_EFID_mask = (0x7ffu << 21),  ///< The frame identifier
  EFID_mask = (0x3ffffu << 3),      ///< The frame identifier
  FF = (1u << 2),                   ///< Frame format
  FT = (1u << 1),                   ///< Frame type
  TEN = (1u << 0),                  ///< Transmit enable
};
void HasBitwiseOperators(CAN_regs::TMI1_bits);

/**
 * Bit shifts for CAN TMI1
 */
enum class CAN_regs::TMI1_shift : unsigned {
  SFID_EFID = 21,
  EFID = 3,
  FF = 2,
  FT = 1,
  TEN = 0,
};

/**
 * Bitmasks for CAN TMP1
 *
 * Transmit mailbox property register 1
 */
enum class CAN_regs::TMP1_bits : uint32_t {
  TS_mask = (0xffffu << 16),  ///< Time stamp
  TSEN = (1u << 8),           ///< Time stamp enable
  DLENC_mask = (0xfu << 0),   ///< Data length code
  Reserved_mask = 0x0000fef0  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::TMP1_bits);

/**
 * Bit shifts for CAN TMP1
 */
enum class CAN_regs::TMP1_shift : unsigned {
  TS = 16,
  TSEN = 8,
  DLENC = 0,
};

/**
 * Bitmasks for CAN TMDATA01
 *
 * Transmit mailbox data0 register
 */
enum class CAN_regs::TMDATA01_bits : uint32_t {
  DB3_mask = (0xffu << 24),  ///< Data byte 3
  DB2_mask = (0xffu << 16),  ///< Data byte 2
  DB1_mask = (0xffu << 8),   ///< Data byte 1
  DB0_mask = (0xffu << 0),   ///< Data byte 0
};
void HasBitwiseOperators(CAN_regs::TMDATA01_bits);

/**
 * Bit shifts for CAN TMDATA01
 */
enum class CAN_regs::TMDATA01_shift : unsigned {
  DB3 = 24,
  DB2 = 16,
  DB1 = 8,
  DB0 = 0,
};

/**
 * Bitmasks for CAN TMDATA11
 *
 * Transmit mailbox data1 register
 */
enum class CAN_regs::TMDATA11_bits : uint32_t {
  DB7_mask = (0xffu << 24),  ///< Data byte 7
  DB6_mask = (0xffu << 16),  ///< Data byte 6
  DB5_mask = (0xffu << 8),   ///< Data byte 5
  DB4_mask = (0xffu << 0),   ///< Data byte 4
};
void HasBitwiseOperators(CAN_regs::TMDATA11_bits);

/**
 * Bit shifts for CAN TMDATA11
 */
enum class CAN_regs::TMDATA11_shift : unsigned {
  DB7 = 24,
  DB6 = 16,
  DB5 = 8,
  DB4 = 0,
};

/**
 * Bitmasks for CAN TMI2
 *
 * Transmit mailbox identifier register 2
 */
enum class CAN_regs::TMI2_bits : uint32_t {
  SFID_EFID_mask = (0x7ffu << 21),  ///< The frame identifier
  EFID_mask = (0x3ffffu << 3),      ///< The frame identifier
  FF = (1u << 2),                   ///< Frame format
  FT = (1u << 1),                   ///< Frame type
  TEN = (1u << 0),                  ///< Transmit enable
};
void HasBitwiseOperators(CAN_regs::TMI2_bits);

/**
 * Bit shifts for CAN TMI2
 */
enum class CAN_regs::TMI2_shift : unsigned {
  SFID_EFID = 21,
  EFID = 3,
  FF = 2,
  FT = 1,
  TEN = 0,
};

/**
 * Bitmasks for CAN TMP2
 *
 * Transmit mailbox property register 2
 */
enum class CAN_regs::TMP2_bits : uint32_t {
  TS_mask = (0xffffu << 16),  ///< Time stamp
  TSEN = (1u << 8),           ///< Time stamp enable
  DLENC_mask = (0xfu << 0),   ///< Data length code
  Reserved_mask = 0x0000fef0  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::TMP2_bits);

/**
 * Bit shifts for CAN TMP2
 */
enum class CAN_regs::TMP2_shift : unsigned {
  TS = 16,
  TSEN = 8,
  DLENC = 0,
};

/**
 * Bitmasks for CAN TMDATA02
 *
 * Transmit mailbox data0 register
 */
enum class CAN_regs::TMDATA02_bits : uint32_t {
  DB3_mask = (0xffu << 24),  ///< Data byte 3
  DB2_mask = (0xffu << 16),  ///< Data byte 2
  DB1_mask = (0xffu << 8),   ///< Data byte 1
  DB0_mask = (0xffu << 0),   ///< Data byte 0
};
void HasBitwiseOperators(CAN_regs::TMDATA02_bits);

/**
 * Bit shifts for CAN TMDATA02
 */
enum class CAN_regs::TMDATA02_shift : unsigned {
  DB3 = 24,
  DB2 = 16,
  DB1 = 8,
  DB0 = 0,
};

/**
 * Bitmasks for CAN TMDATA12
 *
 * Transmit mailbox data1 register
 */
enum class CAN_regs::TMDATA12_bits : uint32_t {
  DB7_mask = (0xffu << 24),  ///< Data byte 7
  DB6_mask = (0xffu << 16),  ///< Data byte 6
  DB5_mask = (0xffu << 8),   ///< Data byte 5
  DB4_mask = (0xffu << 0),   ///< Data byte 4
};
void HasBitwiseOperators(CAN_regs::TMDATA12_bits);

/**
 * Bit shifts for CAN TMDATA12
 */
enum class CAN_regs::TMDATA12_shift : unsigned {
  DB7 = 24,
  DB6 = 16,
  DB5 = 8,
  DB4 = 0,
};

/**
 * Bitmasks for CAN RFIFOMI0
 *
 * Receive FIFO mailbox identifier register
 */
enum class CAN_regs::RFIFOMI0_bits : uint32_t {
  SFID_EFID_mask = (0x7ffu << 21),  ///< The frame identifier
  EFID_mask = (0x3ffffu << 3),      ///< The frame identifier
  FF = (1u << 2),                   ///< Frame format
  FT = (1u << 1),                   ///< Frame type
  Reserved_mask = 0x00000001        ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::RFIFOMI0_bits);

/**
 * Bit shifts for CAN RFIFOMI0
 */
enum class CAN_regs::RFIFOMI0_shift : unsigned {
  SFID_EFID = 21,
  EFID = 3,
  FF = 2,
  FT = 1,
};

/**
 * Bitmasks for CAN RFIFOMP0
 *
 * Receive FIFO0 mailbox property register
 */
enum class CAN_regs::RFIFOMP0_bits : uint32_t {
  TS_mask = (0xffffu << 16),  ///< Time stamp
  FI_mask = (0xffu << 8),     ///< Filtering index
  DLENC_mask = (0xfu << 0),   ///< Data length code
  Reserved_mask = 0x000000f0  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::RFIFOMP0_bits);

/**
 * Bit shifts for CAN RFIFOMP0
 */
enum class CAN_regs::RFIFOMP0_shift : unsigned {
  TS = 16,
  FI = 8,
  DLENC = 0,
};

/**
 * Bitmasks for CAN RFIFOMDATA00
 *
 * Receive FIFO0 mailbox data0 register
 */
enum class CAN_regs::RFIFOMDATA00_bits : uint32_t {
  DB3_mask = (0xffu << 24),  ///< Data byte 3
  DB2_mask = (0xffu << 16),  ///< Data byte 2
  DB1_mask = (0xffu << 8),   ///< Data byte 1
  DB0_mask = (0xffu << 0),   ///< Data byte 0
};
void HasBitwiseOperators(CAN_regs::RFIFOMDATA00_bits);

/**
 * Bit shifts for CAN RFIFOMDATA00
 */
enum class CAN_regs::RFIFOMDATA00_shift : unsigned {
  DB3 = 24,
  DB2 = 16,
  DB1 = 8,
  DB0 = 0,
};

/**
 * Bitmasks for CAN RFIFOMDATA10
 *
 * Receive FIFO0 mailbox data1 register
 */
enum class CAN_regs::RFIFOMDATA10_bits : uint32_t {
  DB7_mask = (0xffu << 24),  ///< Data byte 7
  DB6_mask = (0xffu << 16),  ///< Data byte 6
  DB5_mask = (0xffu << 8),   ///< Data byte 5
  DB4_mask = (0xffu << 0),   ///< Data byte 4
};
void HasBitwiseOperators(CAN_regs::RFIFOMDATA10_bits);

/**
 * Bit shifts for CAN RFIFOMDATA10
 */
enum class CAN_regs::RFIFOMDATA10_shift : unsigned {
  DB7 = 24,
  DB6 = 16,
  DB5 = 8,
  DB4 = 0,
};

/**
 * Bitmasks for CAN RFIFOMI1
 *
 * Receive FIFO1 mailbox identifier register
 */
enum class CAN_regs::RFIFOMI1_bits : uint32_t {
  SFID_EFID_mask = (0x7ffu << 21),  ///< The frame identifier
  EFID_mask = (0x3ffffu << 3),      ///< The frame identifier
  FF = (1u << 2),                   ///< Frame format
  FT = (1u << 1),                   ///< Frame type
  Reserved_mask = 0x00000001        ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::RFIFOMI1_bits);

/**
 * Bit shifts for CAN RFIFOMI1
 */
enum class CAN_regs::RFIFOMI1_shift : unsigned {
  SFID_EFID = 21,
  EFID = 3,
  FF = 2,
  FT = 1,
};

/**
 * Bitmasks for CAN RFIFOMP1
 *
 * Receive FIFO1 mailbox property register
 */
enum class CAN_regs::RFIFOMP1_bits : uint32_t {
  TS_mask = (0xffffu << 16),  ///< Time stamp
  FI_mask = (0xffu << 8),     ///< Filtering index
  DLENC_mask = (0xfu << 0),   ///< Data length code
  Reserved_mask = 0x000000f0  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::RFIFOMP1_bits);

/**
 * Bit shifts for CAN RFIFOMP1
 */
enum class CAN_regs::RFIFOMP1_shift : unsigned {
  TS = 16,
  FI = 8,
  DLENC = 0,
};

/**
 * Bitmasks for CAN RFIFOMDATA01
 *
 * Receive FIFO1 mailbox data0 register
 */
enum class CAN_regs::RFIFOMDATA01_bits : uint32_t {
  DB3_mask = (0xffu << 24),  ///< Data byte 3
  DB2_mask = (0xffu << 16),  ///< Data byte 2
  DB1_mask = (0xffu << 8),   ///< Data byte 1
  DB0_mask = (0xffu << 0),   ///< Data byte 0
};
void HasBitwiseOperators(CAN_regs::RFIFOMDATA01_bits);

/**
 * Bit shifts for CAN RFIFOMDATA01
 */
enum class CAN_regs::RFIFOMDATA01_shift : unsigned {
  DB3 = 24,
  DB2 = 16,
  DB1 = 8,
  DB0 = 0,
};

/**
 * Bitmasks for CAN RFIFOMDATA11
 *
 * Receive FIFO1 mailbox data1 register
 */
enum class CAN_regs::RFIFOMDATA11_bits : uint32_t {
  DB7_mask = (0xffu << 24),  ///< Data byte 7
  DB6_mask = (0xffu << 16),  ///< Data byte 6
  DB5_mask = (0xffu << 8),   ///< Data byte 5
  DB4_mask = (0xffu << 0),   ///< Data byte 4
};
void HasBitwiseOperators(CAN_regs::RFIFOMDATA11_bits);

/**
 * Bit shifts for CAN RFIFOMDATA11
 */
enum class CAN_regs::RFIFOMDATA11_shift : unsigned {
  DB7 = 24,
  DB6 = 16,
  DB5 = 8,
  DB4 = 0,
};

/**
 * Bitmasks for CAN FCTL
 *
 * Filter control register
 */
enum class CAN_regs::FCTL_bits : uint32_t {
  HBC1F_mask = (0x3fu << 8),  ///< Header bank of CAN1 filter
  FLD = (1u << 0),            ///< Filter lock disable
  Reserved_mask = 0xffffc0fe  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::FCTL_bits);

/**
 * Bit shifts for CAN FCTL
 */
enum class CAN_regs::FCTL_shift : unsigned {
  HBC1F = 8,
  FLD = 0,
};

/**
 * Bitmasks for CAN FMCFG
 *
 * Filter mode configuration register
 */
enum class CAN_regs::FMCFG_bits : uint32_t {
  FMOD27 = (1u << 27),        ///< Filter mode
  FMOD26 = (1u << 26),        ///< Filter mode
  FMOD25 = (1u << 25),        ///< Filter mode
  FMOD24 = (1u << 24),        ///< Filter mode
  FMOD23 = (1u << 23),        ///< Filter mode
  FMOD22 = (1u << 22),        ///< Filter mode
  FMOD21 = (1u << 21),        ///< Filter mode
  FMOD20 = (1u << 20),        ///< Filter mode
  FMOD19 = (1u << 19),        ///< Filter mode
  FMOD18 = (1u << 18),        ///< Filter mode
  FMOD17 = (1u << 17),        ///< Filter mode
  FMOD16 = (1u << 16),        ///< Filter mode
  FMOD15 = (1u << 15),        ///< Filter mode
  FMOD14 = (1u << 14),        ///< Filter mode
  FMOD13 = (1u << 13),        ///< Filter mode
  FMOD12 = (1u << 12),        ///< Filter mode
  FMOD11 = (1u << 11),        ///< Filter mode
  FMOD10 = (1u << 10),        ///< Filter mode
  FMOD9 = (1u << 9),          ///< Filter mode
  FMOD8 = (1u << 8),          ///< Filter mode
  FMOD7 = (1u << 7),          ///< Filter mode
  FMOD6 = (1u << 6),          ///< Filter mode
  FMOD5 = (1u << 5),          ///< Filter mode
  FMOD4 = (1u << 4),          ///< Filter mode
  FMOD3 = (1u << 3),          ///< Filter mode
  FMOD2 = (1u << 2),          ///< Filter mode
  FMOD1 = (1u << 1),          ///< Filter mode
  FMOD0 = (1u << 0),          ///< Filter mode
  Reserved_mask = 0xf0000000  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::FMCFG_bits);

/**
 * Bit shifts for CAN FMCFG
 */
enum class CAN_regs::FMCFG_shift : unsigned {
  FMOD27 = 27,
  FMOD26 = 26,
  FMOD25 = 25,
  FMOD24 = 24,
  FMOD23 = 23,
  FMOD22 = 22,
  FMOD21 = 21,
  FMOD20 = 20,
  FMOD19 = 19,
  FMOD18 = 18,
  FMOD17 = 17,
  FMOD16 = 16,
  FMOD15 = 15,
  FMOD14 = 14,
  FMOD13 = 13,
  FMOD12 = 12,
  FMOD11 = 11,
  FMOD10 = 10,
  FMOD9 = 9,
  FMOD8 = 8,
  FMOD7 = 7,
  FMOD6 = 6,
  FMOD5 = 5,
  FMOD4 = 4,
  FMOD3 = 3,
  FMOD2 = 2,
  FMOD1 = 1,
  FMOD0 = 0,
};

/**
 * Bitmasks for CAN FSCFG
 *
 * Filter scale configuration register
 */
enum class CAN_regs::FSCFG_bits : uint32_t {
  FS0 = (1u << 0),            ///< Filter scale configuration
  FS1 = (1u << 1),            ///< Filter scale configuration
  FS2 = (1u << 2),            ///< Filter scale configuration
  FS3 = (1u << 3),            ///< Filter scale configuration
  FS4 = (1u << 4),            ///< Filter scale configuration
  FS5 = (1u << 5),            ///< Filter scale configuration
  FS6 = (1u << 6),            ///< Filter scale configuration
  FS7 = (1u << 7),            ///< Filter scale configuration
  FS8 = (1u << 8),            ///< Filter scale configuration
  FS9 = (1u << 9),            ///< Filter scale configuration
  FS10 = (1u << 10),          ///< Filter scale configuration
  FS11 = (1u << 11),          ///< Filter scale configuration
  FS12 = (1u << 12),          ///< Filter scale configuration
  FS13 = (1u << 13),          ///< Filter scale configuration
  FS14 = (1u << 14),          ///< Filter scale configuration
  FS15 = (1u << 15),          ///< Filter scale configuration
  FS16 = (1u << 16),          ///< Filter scale configuration
  FS17 = (1u << 17),          ///< Filter scale configuration
  FS18 = (1u << 18),          ///< Filter scale configuration
  FS19 = (1u << 19),          ///< Filter scale configuration
  FS20 = (1u << 20),          ///< Filter scale configuration
  FS21 = (1u << 21),          ///< Filter scale configuration
  FS22 = (1u << 22),          ///< Filter scale configuration
  FS23 = (1u << 23),          ///< Filter scale configuration
  FS24 = (1u << 24),          ///< Filter scale configuration
  FS25 = (1u << 25),          ///< Filter scale configuration
  FS26 = (1u << 26),          ///< Filter scale configuration
  FS27 = (1u << 27),          ///< Filter scale configuration
  Reserved_mask = 0xf0000000  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::FSCFG_bits);

/**
 * Bit shifts for CAN FSCFG
 */
enum class CAN_regs::FSCFG_shift : unsigned {
  FS0 = 0,
  FS1 = 1,
  FS2 = 2,
  FS3 = 3,
  FS4 = 4,
  FS5 = 5,
  FS6 = 6,
  FS7 = 7,
  FS8 = 8,
  FS9 = 9,
  FS10 = 10,
  FS11 = 11,
  FS12 = 12,
  FS13 = 13,
  FS14 = 14,
  FS15 = 15,
  FS16 = 16,
  FS17 = 17,
  FS18 = 18,
  FS19 = 19,
  FS20 = 20,
  FS21 = 21,
  FS22 = 22,
  FS23 = 23,
  FS24 = 24,
  FS25 = 25,
  FS26 = 26,
  FS27 = 27,
};

/**
 * Bitmasks for CAN FAFIFO
 *
 * Filter associated FIFO register
 */
enum class CAN_regs::FAFIFO_bits : uint32_t {
  FAF0 = (1u << 0),           ///< Filter 0 associated with FIFO
  FAF1 = (1u << 1),           ///< Filter 1 associated with FIFO
  FAF2 = (1u << 2),           ///< Filter 2 associated with FIFO
  FAF3 = (1u << 3),           ///< Filter 3 associated with FIFO
  FAF4 = (1u << 4),           ///< Filter 4 associated with FIFO
  FAF5 = (1u << 5),           ///< Filter 5 associated with FIFO
  FAF6 = (1u << 6),           ///< Filter 6 associated with FIFO
  FAF7 = (1u << 7),           ///< Filter 7 associated with FIFO
  FAF8 = (1u << 8),           ///< Filter 8 associated with FIFO
  FAF9 = (1u << 9),           ///< Filter 9 associated with FIFO
  FAF10 = (1u << 10),         ///< Filter 10 associated with FIFO
  FAF11 = (1u << 11),         ///< Filter 11 associated with FIFO
  FAF12 = (1u << 12),         ///< Filter 12 associated with FIFO
  FAF13 = (1u << 13),         ///< Filter 13 associated with FIFO
  FAF14 = (1u << 14),         ///< Filter 14 associated with FIFO
  FAF15 = (1u << 15),         ///< Filter 15 associated with FIFO
  FAF16 = (1u << 16),         ///< Filter 16 associated with FIFO
  FAF17 = (1u << 17),         ///< Filter 17 associated with FIFO
  FAF18 = (1u << 18),         ///< Filter 18 associated with FIFO
  FAF19 = (1u << 19),         ///< Filter 19 associated with FIFO
  FAF20 = (1u << 20),         ///< Filter 20 associated with FIFO
  FAF21 = (1u << 21),         ///< Filter 21 associated with FIFO
  FAF22 = (1u << 22),         ///< Filter 22 associated with FIFO
  FAF23 = (1u << 23),         ///< Filter 23 associated with FIFO
  FAF24 = (1u << 24),         ///< Filter 24 associated with FIFO
  FAF25 = (1u << 25),         ///< Filter 25 associated with FIFO
  FAF26 = (1u << 26),         ///< Filter 26 associated with FIFO
  FAF27 = (1u << 27),         ///< Filter 27 associated with FIFO
  Reserved_mask = 0xf0000000  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::FAFIFO_bits);

/**
 * Bit shifts for CAN FAFIFO
 */
enum class CAN_regs::FAFIFO_shift : unsigned {
  FAF0 = 0,
  FAF1 = 1,
  FAF2 = 2,
  FAF3 = 3,
  FAF4 = 4,
  FAF5 = 5,
  FAF6 = 6,
  FAF7 = 7,
  FAF8 = 8,
  FAF9 = 9,
  FAF10 = 10,
  FAF11 = 11,
  FAF12 = 12,
  FAF13 = 13,
  FAF14 = 14,
  FAF15 = 15,
  FAF16 = 16,
  FAF17 = 17,
  FAF18 = 18,
  FAF19 = 19,
  FAF20 = 20,
  FAF21 = 21,
  FAF22 = 22,
  FAF23 = 23,
  FAF24 = 24,
  FAF25 = 25,
  FAF26 = 26,
  FAF27 = 27,
};

/**
 * Bitmasks for CAN FW
 *
 * Filter working register
 */
enum class CAN_regs::FW_bits : uint32_t {
  FW0 = (1u << 0),            ///< Filter working
  FW1 = (1u << 1),            ///< Filter working
  FW2 = (1u << 2),            ///< Filter working
  FW3 = (1u << 3),            ///< Filter working
  FW4 = (1u << 4),            ///< Filter working
  FW5 = (1u << 5),            ///< Filter working
  FW6 = (1u << 6),            ///< Filter working
  FW7 = (1u << 7),            ///< Filter working
  FW8 = (1u << 8),            ///< Filter working
  FW9 = (1u << 9),            ///< Filter working
  FW10 = (1u << 10),          ///< Filter working
  FW11 = (1u << 11),          ///< Filter working
  FW12 = (1u << 12),          ///< Filter working
  FW13 = (1u << 13),          ///< Filter working
  FW14 = (1u << 14),          ///< Filter working
  FW15 = (1u << 15),          ///< Filter working
  FW16 = (1u << 16),          ///< Filter working
  FW17 = (1u << 17),          ///< Filter working
  FW18 = (1u << 18),          ///< Filter working
  FW19 = (1u << 19),          ///< Filter working
  FW20 = (1u << 20),          ///< Filter working
  FW21 = (1u << 21),          ///< Filter working
  FW22 = (1u << 22),          ///< Filter working
  FW23 = (1u << 23),          ///< Filter working
  FW24 = (1u << 24),          ///< Filter working
  FW25 = (1u << 25),          ///< Filter working
  FW26 = (1u << 26),          ///< Filter working
  FW27 = (1u << 27),          ///< Filter working
  Reserved_mask = 0xf0000000  ///< All reserved bits
};
void HasBitwiseOperators(CAN_regs::FW_bits);

/**
 * Bit shifts for CAN FW
 */
enum class CAN_regs::FW_shift : unsigned {
  FW0 = 0,
  FW1 = 1,
  FW2 = 2,
  FW3 = 3,
  FW4 = 4,
  FW5 = 5,
  FW6 = 6,
  FW7 = 7,
  FW8 = 8,
  FW9 = 9,
  FW10 = 10,
  FW11 = 11,
  FW12 = 12,
  FW13 = 13,
  FW14 = 14,
  FW15 = 15,
  FW16 = 16,
  FW17 = 17,
  FW18 = 18,
  FW19 = 19,
  FW20 = 20,
  FW21 = 21,
  FW22 = 22,
  FW23 = 23,
  FW24 = 24,
  FW25 = 25,
  FW26 = 26,
  FW27 = 27,
};

/**
 * Bitmasks for CAN F0DATA0
 *
 * Filter 0 data 0 register
 */
enum class CAN_regs::F0DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F0DATA0_bits);

/**
 * Bit shifts for CAN F0DATA0
 */
enum class CAN_regs::F0DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F0DATA1
 *
 * Filter 0 data 1 register
 */
enum class CAN_regs::F0DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F0DATA1_bits);

/**
 * Bit shifts for CAN F0DATA1
 */
enum class CAN_regs::F0DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F1DATA0
 *
 * Filter 1 data 0 register
 */
enum class CAN_regs::F1DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F1DATA0_bits);

/**
 * Bit shifts for CAN F1DATA0
 */
enum class CAN_regs::F1DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F1DATA1
 *
 * Filter 1 data 1 register
 */
enum class CAN_regs::F1DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F1DATA1_bits);

/**
 * Bit shifts for CAN F1DATA1
 */
enum class CAN_regs::F1DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F2DATA0
 *
 * Filter 2 data 0 register
 */
enum class CAN_regs::F2DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F2DATA0_bits);

/**
 * Bit shifts for CAN F2DATA0
 */
enum class CAN_regs::F2DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F2DATA1
 *
 * Filter 2 data 1 register
 */
enum class CAN_regs::F2DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F2DATA1_bits);

/**
 * Bit shifts for CAN F2DATA1
 */
enum class CAN_regs::F2DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F3DATA0
 *
 * Filter 3 data 0 register
 */
enum class CAN_regs::F3DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F3DATA0_bits);

/**
 * Bit shifts for CAN F3DATA0
 */
enum class CAN_regs::F3DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F3DATA1
 *
 * Filter 3 data 1 register
 */
enum class CAN_regs::F3DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F3DATA1_bits);

/**
 * Bit shifts for CAN F3DATA1
 */
enum class CAN_regs::F3DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F4DATA0
 *
 * Filter 4 data 0 register
 */
enum class CAN_regs::F4DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F4DATA0_bits);

/**
 * Bit shifts for CAN F4DATA0
 */
enum class CAN_regs::F4DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F4DATA1
 *
 * Filter 4 data 1 register
 */
enum class CAN_regs::F4DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F4DATA1_bits);

/**
 * Bit shifts for CAN F4DATA1
 */
enum class CAN_regs::F4DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F5DATA0
 *
 * Filter 5 data 0 register
 */
enum class CAN_regs::F5DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F5DATA0_bits);

/**
 * Bit shifts for CAN F5DATA0
 */
enum class CAN_regs::F5DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F5DATA1
 *
 * Filter 5 data 1 register
 */
enum class CAN_regs::F5DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F5DATA1_bits);

/**
 * Bit shifts for CAN F5DATA1
 */
enum class CAN_regs::F5DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F6DATA0
 *
 * Filter 6 data 0 register
 */
enum class CAN_regs::F6DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F6DATA0_bits);

/**
 * Bit shifts for CAN F6DATA0
 */
enum class CAN_regs::F6DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F6DATA1
 *
 * Filter 6 data 1 register
 */
enum class CAN_regs::F6DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F6DATA1_bits);

/**
 * Bit shifts for CAN F6DATA1
 */
enum class CAN_regs::F6DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F7DATA0
 *
 * Filter 7 data 0 register
 */
enum class CAN_regs::F7DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F7DATA0_bits);

/**
 * Bit shifts for CAN F7DATA0
 */
enum class CAN_regs::F7DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F7DATA1
 *
 * Filter 7 data 1 register
 */
enum class CAN_regs::F7DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F7DATA1_bits);

/**
 * Bit shifts for CAN F7DATA1
 */
enum class CAN_regs::F7DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F8DATA0
 *
 * Filter 8 data 0 register
 */
enum class CAN_regs::F8DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F8DATA0_bits);

/**
 * Bit shifts for CAN F8DATA0
 */
enum class CAN_regs::F8DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F8DATA1
 *
 * Filter 8 data 1 register
 */
enum class CAN_regs::F8DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F8DATA1_bits);

/**
 * Bit shifts for CAN F8DATA1
 */
enum class CAN_regs::F8DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F9DATA0
 *
 * Filter 9 data 0 register
 */
enum class CAN_regs::F9DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F9DATA0_bits);

/**
 * Bit shifts for CAN F9DATA0
 */
enum class CAN_regs::F9DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F9DATA1
 *
 * Filter 9 data 1 register
 */
enum class CAN_regs::F9DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F9DATA1_bits);

/**
 * Bit shifts for CAN F9DATA1
 */
enum class CAN_regs::F9DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F10DATA0
 *
 * Filter 10 data 0 register
 */
enum class CAN_regs::F10DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F10DATA0_bits);

/**
 * Bit shifts for CAN F10DATA0
 */
enum class CAN_regs::F10DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F10DATA1
 *
 * Filter 10 data 1 register
 */
enum class CAN_regs::F10DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F10DATA1_bits);

/**
 * Bit shifts for CAN F10DATA1
 */
enum class CAN_regs::F10DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F11DATA0
 *
 * Filter 11 data 0 register
 */
enum class CAN_regs::F11DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F11DATA0_bits);

/**
 * Bit shifts for CAN F11DATA0
 */
enum class CAN_regs::F11DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F11DATA1
 *
 * Filter 11 data 1 register
 */
enum class CAN_regs::F11DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F11DATA1_bits);

/**
 * Bit shifts for CAN F11DATA1
 */
enum class CAN_regs::F11DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F12DATA0
 *
 * Filter 12 data 0 register
 */
enum class CAN_regs::F12DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F12DATA0_bits);

/**
 * Bit shifts for CAN F12DATA0
 */
enum class CAN_regs::F12DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F12DATA1
 *
 * Filter 12 data 1 register
 */
enum class CAN_regs::F12DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F12DATA1_bits);

/**
 * Bit shifts for CAN F12DATA1
 */
enum class CAN_regs::F12DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F13DATA0
 *
 * Filter 13 data 0 register
 */
enum class CAN_regs::F13DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F13DATA0_bits);

/**
 * Bit shifts for CAN F13DATA0
 */
enum class CAN_regs::F13DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F13DATA1
 *
 * Filter 13 data 1 register
 */
enum class CAN_regs::F13DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F13DATA1_bits);

/**
 * Bit shifts for CAN F13DATA1
 */
enum class CAN_regs::F13DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F14DATA0
 *
 * Filter 14 data 0 register
 */
enum class CAN_regs::F14DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F14DATA0_bits);

/**
 * Bit shifts for CAN F14DATA0
 */
enum class CAN_regs::F14DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F14DATA1
 *
 * Filter 14 data 1 register
 */
enum class CAN_regs::F14DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F14DATA1_bits);

/**
 * Bit shifts for CAN F14DATA1
 */
enum class CAN_regs::F14DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F15DATA0
 *
 * Filter 15 data 0 register
 */
enum class CAN_regs::F15DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F15DATA0_bits);

/**
 * Bit shifts for CAN F15DATA0
 */
enum class CAN_regs::F15DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F15DATA1
 *
 * Filter 15 data 1 register
 */
enum class CAN_regs::F15DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F15DATA1_bits);

/**
 * Bit shifts for CAN F15DATA1
 */
enum class CAN_regs::F15DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F16DATA0
 *
 * Filter 16 data 0 register
 */
enum class CAN_regs::F16DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F16DATA0_bits);

/**
 * Bit shifts for CAN F16DATA0
 */
enum class CAN_regs::F16DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F16DATA1
 *
 * Filter 16 data 1 register
 */
enum class CAN_regs::F16DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F16DATA1_bits);

/**
 * Bit shifts for CAN F16DATA1
 */
enum class CAN_regs::F16DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F17DATA0
 *
 * Filter 17 data 0 register
 */
enum class CAN_regs::F17DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F17DATA0_bits);

/**
 * Bit shifts for CAN F17DATA0
 */
enum class CAN_regs::F17DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F17DATA1
 *
 * Filter 17 data 1 register
 */
enum class CAN_regs::F17DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F17DATA1_bits);

/**
 * Bit shifts for CAN F17DATA1
 */
enum class CAN_regs::F17DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F18DATA0
 *
 * Filter 18 data 0 register
 */
enum class CAN_regs::F18DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F18DATA0_bits);

/**
 * Bit shifts for CAN F18DATA0
 */
enum class CAN_regs::F18DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F18DATA1
 *
 * Filter 18 data 1 register
 */
enum class CAN_regs::F18DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F18DATA1_bits);

/**
 * Bit shifts for CAN F18DATA1
 */
enum class CAN_regs::F18DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F19DATA0
 *
 * Filter 19 data 0 register
 */
enum class CAN_regs::F19DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F19DATA0_bits);

/**
 * Bit shifts for CAN F19DATA0
 */
enum class CAN_regs::F19DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F19DATA1
 *
 * Filter 19 data 1 register
 */
enum class CAN_regs::F19DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F19DATA1_bits);

/**
 * Bit shifts for CAN F19DATA1
 */
enum class CAN_regs::F19DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F20DATA0
 *
 * Filter 20 data 0 register
 */
enum class CAN_regs::F20DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F20DATA0_bits);

/**
 * Bit shifts for CAN F20DATA0
 */
enum class CAN_regs::F20DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F20DATA1
 *
 * Filter 20 data 1 register
 */
enum class CAN_regs::F20DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F20DATA1_bits);

/**
 * Bit shifts for CAN F20DATA1
 */
enum class CAN_regs::F20DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F21DATA0
 *
 * Filter 21 data 0 register
 */
enum class CAN_regs::F21DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F21DATA0_bits);

/**
 * Bit shifts for CAN F21DATA0
 */
enum class CAN_regs::F21DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F21DATA1
 *
 * Filter 21 data 1 register
 */
enum class CAN_regs::F21DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F21DATA1_bits);

/**
 * Bit shifts for CAN F21DATA1
 */
enum class CAN_regs::F21DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F22DATA0
 *
 * Filter 22 data 0 register
 */
enum class CAN_regs::F22DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F22DATA0_bits);

/**
 * Bit shifts for CAN F22DATA0
 */
enum class CAN_regs::F22DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F22DATA1
 *
 * Filter 22 data 1 register
 */
enum class CAN_regs::F22DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F22DATA1_bits);

/**
 * Bit shifts for CAN F22DATA1
 */
enum class CAN_regs::F22DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F23DATA0
 *
 * Filter 23 data 0 register
 */
enum class CAN_regs::F23DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F23DATA0_bits);

/**
 * Bit shifts for CAN F23DATA0
 */
enum class CAN_regs::F23DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F23DATA1
 *
 * Filter 23 data 1 register
 */
enum class CAN_regs::F23DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F23DATA1_bits);

/**
 * Bit shifts for CAN F23DATA1
 */
enum class CAN_regs::F23DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F24DATA0
 *
 * Filter 24 data 0 register
 */
enum class CAN_regs::F24DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F24DATA0_bits);

/**
 * Bit shifts for CAN F24DATA0
 */
enum class CAN_regs::F24DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F24DATA1
 *
 * Filter 24 data 1 register
 */
enum class CAN_regs::F24DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F24DATA1_bits);

/**
 * Bit shifts for CAN F24DATA1
 */
enum class CAN_regs::F24DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F25DATA0
 *
 * Filter 25 data 0 register
 */
enum class CAN_regs::F25DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F25DATA0_bits);

/**
 * Bit shifts for CAN F25DATA0
 */
enum class CAN_regs::F25DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F25DATA1
 *
 * Filter 25 data 1 register
 */
enum class CAN_regs::F25DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F25DATA1_bits);

/**
 * Bit shifts for CAN F25DATA1
 */
enum class CAN_regs::F25DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F26DATA0
 *
 * Filter 26 data 0 register
 */
enum class CAN_regs::F26DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F26DATA0_bits);

/**
 * Bit shifts for CAN F26DATA0
 */
enum class CAN_regs::F26DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F26DATA1
 *
 * Filter 26 data 1 register
 */
enum class CAN_regs::F26DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F26DATA1_bits);

/**
 * Bit shifts for CAN F26DATA1
 */
enum class CAN_regs::F26DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F27DATA0
 *
 * Filter 27 data 0 register
 */
enum class CAN_regs::F27DATA0_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F27DATA0_bits);

/**
 * Bit shifts for CAN F27DATA0
 */
enum class CAN_regs::F27DATA0_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

/**
 * Bitmasks for CAN F27DATA1
 *
 * Filter 27 data 1 register
 */
enum class CAN_regs::F27DATA1_bits : uint32_t {
  FD0 = (1u << 0),    ///< Filter bits
  FD1 = (1u << 1),    ///< Filter bits
  FD2 = (1u << 2),    ///< Filter bits
  FD3 = (1u << 3),    ///< Filter bits
  FD4 = (1u << 4),    ///< Filter bits
  FD5 = (1u << 5),    ///< Filter bits
  FD6 = (1u << 6),    ///< Filter bits
  FD7 = (1u << 7),    ///< Filter bits
  FD8 = (1u << 8),    ///< Filter bits
  FD9 = (1u << 9),    ///< Filter bits
  FD10 = (1u << 10),  ///< Filter bits
  FD11 = (1u << 11),  ///< Filter bits
  FD12 = (1u << 12),  ///< Filter bits
  FD13 = (1u << 13),  ///< Filter bits
  FD14 = (1u << 14),  ///< Filter bits
  FD15 = (1u << 15),  ///< Filter bits
  FD16 = (1u << 16),  ///< Filter bits
  FD17 = (1u << 17),  ///< Filter bits
  FD18 = (1u << 18),  ///< Filter bits
  FD19 = (1u << 19),  ///< Filter bits
  FD20 = (1u << 20),  ///< Filter bits
  FD21 = (1u << 21),  ///< Filter bits
  FD22 = (1u << 22),  ///< Filter bits
  FD23 = (1u << 23),  ///< Filter bits
  FD24 = (1u << 24),  ///< Filter bits
  FD25 = (1u << 25),  ///< Filter bits
  FD26 = (1u << 26),  ///< Filter bits
  FD27 = (1u << 27),  ///< Filter bits
  FD28 = (1u << 28),  ///< Filter bits
  FD29 = (1u << 29),  ///< Filter bits
  FD30 = (1u << 30),  ///< Filter bits
  FD31 = (1u << 31),  ///< Filter bits
};
void HasBitwiseOperators(CAN_regs::F27DATA1_bits);

/**
 * Bit shifts for CAN F27DATA1
 */
enum class CAN_regs::F27DATA1_shift : unsigned {
  FD0 = 0,
  FD1 = 1,
  FD2 = 2,
  FD3 = 3,
  FD4 = 4,
  FD5 = 5,
  FD6 = 6,
  FD7 = 7,
  FD8 = 8,
  FD9 = 9,
  FD10 = 10,
  FD11 = 11,
  FD12 = 12,
  FD13 = 13,
  FD14 = 14,
  FD15 = 15,
  FD16 = 16,
  FD17 = 17,
  FD18 = 18,
  FD19 = 19,
  FD20 = 20,
  FD21 = 21,
  FD22 = 22,
  FD23 = 23,
  FD24 = 24,
  FD25 = 25,
  FD26 = 26,
  FD27 = 27,
  FD28 = 28,
  FD29 = 29,
  FD30 = 30,
  FD31 = 31,
};

static_assert(offsetof(CAN_regs, CTL) == 0x0);
static_assert(offsetof(CAN_regs, STAT) == 0x4);
static_assert(offsetof(CAN_regs, TSTAT) == 0x8);
static_assert(offsetof(CAN_regs, RFIFO0) == 0xc);
static_assert(offsetof(CAN_regs, RFIFO1) == 0x10);
static_assert(offsetof(CAN_regs, INTEN) == 0x14);
static_assert(offsetof(CAN_regs, ERR) == 0x18);
static_assert(offsetof(CAN_regs, BT) == 0x1c);
static_assert(offsetof(CAN_regs, TMI0) == 0x180);
static_assert(offsetof(CAN_regs, TMP0) == 0x184);
static_assert(offsetof(CAN_regs, TMDATA00) == 0x188);
static_assert(offsetof(CAN_regs, TMDATA10) == 0x18c);
static_assert(offsetof(CAN_regs, TMI1) == 0x190);
static_assert(offsetof(CAN_regs, TMP1) == 0x194);
static_assert(offsetof(CAN_regs, TMDATA01) == 0x198);
static_assert(offsetof(CAN_regs, TMDATA11) == 0x19c);
static_assert(offsetof(CAN_regs, TMI2) == 0x1a0);
static_assert(offsetof(CAN_regs, TMP2) == 0x1a4);
static_assert(offsetof(CAN_regs, TMDATA02) == 0x1a8);
static_assert(offsetof(CAN_regs, TMDATA12) == 0x1ac);
static_assert(offsetof(CAN_regs, RFIFOMI0) == 0x1b0);
static_assert(offsetof(CAN_regs, RFIFOMP0) == 0x1b4);
static_assert(offsetof(CAN_regs, RFIFOMDATA00) == 0x1b8);
static_assert(offsetof(CAN_regs, RFIFOMDATA10) == 0x1bc);
static_assert(offsetof(CAN_regs, RFIFOMI1) == 0x1c0);
static_assert(offsetof(CAN_regs, RFIFOMP1) == 0x1c4);
static_assert(offsetof(CAN_regs, RFIFOMDATA01) == 0x1c8);
static_assert(offsetof(CAN_regs, RFIFOMDATA11) == 0x1cc);
static_assert(offsetof(CAN_regs, FCTL) == 0x200);
static_assert(offsetof(CAN_regs, FMCFG) == 0x204);
static_assert(offsetof(CAN_regs, FSCFG) == 0x20c);
static_assert(offsetof(CAN_regs, FAFIFO) == 0x214);
static_assert(offsetof(CAN_regs, FW) == 0x21c);
static_assert(offsetof(CAN_regs, F0DATA0) == 0x240);
static_assert(offsetof(CAN_regs, F0DATA1) == 0x244);
static_assert(offsetof(CAN_regs, F1DATA0) == 0x248);
static_assert(offsetof(CAN_regs, F1DATA1) == 0x24c);
static_assert(offsetof(CAN_regs, F2DATA0) == 0x250);
static_assert(offsetof(CAN_regs, F2DATA1) == 0x254);
static_assert(offsetof(CAN_regs, F3DATA0) == 0x258);
static_assert(offsetof(CAN_regs, F3DATA1) == 0x25c);
static_assert(offsetof(CAN_regs, F4DATA0) == 0x260);
static_assert(offsetof(CAN_regs, F4DATA1) == 0x264);
static_assert(offsetof(CAN_regs, F5DATA0) == 0x268);
static_assert(offsetof(CAN_regs, F5DATA1) == 0x26c);
static_assert(offsetof(CAN_regs, F6DATA0) == 0x270);
static_assert(offsetof(CAN_regs, F6DATA1) == 0x274);
static_assert(offsetof(CAN_regs, F7DATA0) == 0x278);
static_assert(offsetof(CAN_regs, F7DATA1) == 0x27c);
static_assert(offsetof(CAN_regs, F8DATA0) == 0x280);
static_assert(offsetof(CAN_regs, F8DATA1) == 0x284);
static_assert(offsetof(CAN_regs, F9DATA0) == 0x288);
static_assert(offsetof(CAN_regs, F9DATA1) == 0x28c);
static_assert(offsetof(CAN_regs, F10DATA0) == 0x290);
static_assert(offsetof(CAN_regs, F10DATA1) == 0x294);
static_assert(offsetof(CAN_regs, F11DATA0) == 0x298);
static_assert(offsetof(CAN_regs, F11DATA1) == 0x29c);
static_assert(offsetof(CAN_regs, F12DATA0) == 0x2a0);
static_assert(offsetof(CAN_regs, F12DATA1) == 0x2a4);
static_assert(offsetof(CAN_regs, F13DATA0) == 0x2a8);
static_assert(offsetof(CAN_regs, F13DATA1) == 0x2ac);
static_assert(offsetof(CAN_regs, F14DATA0) == 0x2b0);
static_assert(offsetof(CAN_regs, F14DATA1) == 0x2b4);
static_assert(offsetof(CAN_regs, F15DATA0) == 0x2b8);
static_assert(offsetof(CAN_regs, F15DATA1) == 0x2bc);
static_assert(offsetof(CAN_regs, F16DATA0) == 0x2c0);
static_assert(offsetof(CAN_regs, F16DATA1) == 0x2c4);
static_assert(offsetof(CAN_regs, F17DATA0) == 0x2c8);
static_assert(offsetof(CAN_regs, F17DATA1) == 0x2cc);
static_assert(offsetof(CAN_regs, F18DATA0) == 0x2d0);
static_assert(offsetof(CAN_regs, F18DATA1) == 0x2d4);
static_assert(offsetof(CAN_regs, F19DATA0) == 0x2d8);
static_assert(offsetof(CAN_regs, F19DATA1) == 0x2dc);
static_assert(offsetof(CAN_regs, F20DATA0) == 0x2e0);
static_assert(offsetof(CAN_regs, F20DATA1) == 0x2e4);
static_assert(offsetof(CAN_regs, F21DATA0) == 0x2e8);
static_assert(offsetof(CAN_regs, F21DATA1) == 0x2ec);
static_assert(offsetof(CAN_regs, F22DATA0) == 0x2f0);
static_assert(offsetof(CAN_regs, F22DATA1) == 0x2f4);
static_assert(offsetof(CAN_regs, F23DATA0) == 0x2f8);
static_assert(offsetof(CAN_regs, F23DATA1) == 0x2fc);
static_assert(offsetof(CAN_regs, F24DATA0) == 0x300);
static_assert(offsetof(CAN_regs, F24DATA1) == 0x304);
static_assert(offsetof(CAN_regs, F25DATA0) == 0x308);
static_assert(offsetof(CAN_regs, F25DATA1) == 0x30c);
static_assert(offsetof(CAN_regs, F26DATA0) == 0x310);
static_assert(offsetof(CAN_regs, F26DATA1) == 0x314);
static_assert(offsetof(CAN_regs, F27DATA0) == 0x318);
static_assert(offsetof(CAN_regs, F27DATA1) == 0x31c);
}  // namespace deri::mmio
