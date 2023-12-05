/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:52 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef TPDT_CANMSG_H
#define TPDT_CANMSG_H

/* Include ********************************************************************/
#include "../types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/

/*** J1939 STANDARD PGNs ***/
#define PGN_TPDT                            0xEB00U
#define SIZE_TPDT                           8U

/* Typedefs *******************************************************************/
/*** STANDARD CAN MESSAGES: ***************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

/* Transport Protocol - Data Transfer */
typedef struct tagTPDT
{
    uint8_t SequenceNumber;
    uint8_t Byte[7]; 
} TPDT_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 TPDT_CANMSG (uint32_t ctrl,
                                     uint32_t DestinationAddress, 
                                     uint32_t SequenceNumber, 
                                     uint8_t* pByte);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: TPDT_canmsg.h$ */
