/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:54 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef TPCM_CANMSG_H
#define TPCM_CANMSG_H

/* Include ********************************************************************/
#include "../types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/

/*** J1939 STANDARD PGNs ***/
#define PGN_TPCM                            0xEC00U
#define SIZE_TPCM                           8U

#define RTS_TPCM                            16U
#define CTS_TPCM                            17U
#define EOMACK_TPCM                         18U
#define BAM_TPCM                            32U
#define CONN_ABORT_TPCM                     255U

/* Typedefs *******************************************************************/
/*** STANDARD CAN MESSAGES: ***************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

/* TP.CM Request to Send */
typedef struct tagRTS
{
    uint8_t  ControlByte;
    uint16_t TotalMessageSize;
    uint8_t  TotalNumberOfPackets;
    uint8_t  MaximumNumberOfPackets;
    uint16_t Pgn;
    uint8_t  Pgn1;
} RTS_T;

/* TP.CM Clear to Send */
typedef struct tagCTS
{
    uint8_t  ControlByte;
    uint8_t  NumberOfPacketsCanSent;
    uint8_t  NextPacketNumberToBeSent;
    uint16_t Rvd;
    uint16_t Pgn;
    uint8_t  Pgn1;
} CTS_T;

/* TP.CM End Of Message Acknowledge */
typedef struct tagEOMACK
{
    uint8_t  ControlByte;
    uint16_t TotalMessageSize;
    uint8_t  TotalNumberOfPackets;
    uint8_t  Rvd;
    uint16_t Pgn;
    uint8_t  Pgn1;
} EOMACK_T;

/* TP.CM Broadcast Announce Message */
typedef struct tagBAM
{
    uint8_t  ControlByte;
    uint16_t TotalMessageSize;
    uint8_t  TotalNumberOfPackets;
    uint8_t  Rvd;
    uint16_t Pgn;
    uint8_t  Pgn1;
} BAM_T;

/* TP.CM Connection Abort */
typedef struct tagCONNABORT
{
    uint8_t  ControlByte;
    uint8_t  ConnectionAbortReason;
    uint16_t Rvd;
    uint8_t  Rvd1;
    uint16_t Pgn;
    uint8_t  Pgn1;
} CONNABORT_T;

/* TP.CM - Connection Management */
typedef union
{
    RTS_T      RTS;
    CTS_T      CTS;
    EOMACK_T   EOMACK;
    BAM_T      BAM;
    CONNABORT_T CONNABORT;
} TPCM_U;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 TPCM_RTS_CANMSG (uint32_t ctrl,
                                         uint32_t Pgn,
                                         uint32_t DestinationAddress, 
                                         uint32_t TotalMessageSize,
                                         uint32_t TotalNumberOfPackets,
                                         uint32_t MaximumNumberOfPackets);

int32_t                 TPCM_CTS_CANMSG (uint32_t ctrl,
                                         uint32_t Pgn,
                                         uint32_t DestinationAddress, 
                                         uint32_t NumberOfPacketsCanSent,
                                         uint32_t NextPacketNumberToBeSent);

int32_t                 TPCM_EOMACK_CANMSG (uint32_t ctrl,
                                            uint32_t Pgn,
                                            uint32_t DestinationAddress, 
                                            uint32_t TotalMessageSize,
                                            uint32_t TotalNumberOfPackets);

int32_t                 TPCM_BAM_CANMSG (uint32_t ctrl,
                                         uint32_t Pgn,
                                         uint32_t DestinationAddress, 
                                         uint32_t TotalMessageSize,
                                         uint32_t TotalNumberOfPackets);

int32_t                 TPCM_ABORT_CANMSG (uint32_t ctrl,
                                           uint32_t Pgn,
                                           uint32_t DestinationAddress, 
                                           uint32_t ConnectionAbortReason);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: TPCM_canmsg.h$ */
