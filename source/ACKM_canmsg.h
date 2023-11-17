/*******************************************************************************
** $Revision: 2$
** $Date: 30/11/2012 08:57:31 a.m.$
** $Author: Admin Ariel Moreno$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef ACKM_CANMSG_H
#define ACKM_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_ACKNOWLEDGMENT                  0xE800U
#define SIZE_ACKNOWLEDGMENT                 8U

#define POSITIVE_ACKM                       0U
#define NEGATIVE_ACKM                       1U
#define ACCESS_DENIED_ACKM                  2U
#define CANNOT_RESPOND_ACKM                 3U

/* Typedefs *******************************************************************/
/*** STANDARD CAN MESSAGES: ***************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagACKM
{
    uint8_t  ControlByte;
    uint8_t  GroupFunctionValue;
    uint16_t Rvd;
    uint8_t  Rvd1;
    uint16_t Pgn;
    uint8_t  Pgn1;
} ACKM_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                     ACKM_CANMSG (uint32_t ctrl, uint32_t ControlByte, uint32_t Pgn, 
                                         uint32_t GroupFunction, uint32_t DestinationAddress);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: ACKM_canmsg.h$ */
