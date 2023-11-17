/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:49 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef DM16_CANMSG_H
#define DM16_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_DM16                            0xD700U
#define SIZE_DM16                           8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

/* DM16 - Binary Data Transfer */
typedef struct tagDM16
{
  uint8_t NumberOfOccurrence;
  uint8_t Data[7];
} DM16_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 DM16_CANMSG (uint32_t NumberOfOccurrence, 
                                     uint8_t* Data, 
                                     uint32_t DestinationAddress);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: DM16_canmsg.h$ */
