/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:50 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef RQST_CANMSG_H
#define RQST_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_REQUEST                         0xEA00U
#define SIZE_REQUEST			            3U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagRQST
{
    uint16_t Pgn;
    uint8_t  Pgn1;
} RQST_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 RQST_CANMSG (uint32_t ctrl, uint32_t Pgn, uint32_t DestinationAddress);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: RQST_canmsg.h$ */

