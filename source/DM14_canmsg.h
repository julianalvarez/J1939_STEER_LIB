/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:52 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef DM14_CANMSG_H
#define DM14_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_DM14                            0xD900U
#define SIZE_DM14                           8U

#define CMD_ERASE_DM14                      0U
#define CMD_READ_DM14                       1U
#define CMD_WRITE_DM14                      2U
#define CMD_STATUS_REQ_DM14                 3U
#define CMD_OPERATION_COMPLETED_DM14        4U
#define CMD_OPERATION_FAILED_DM14           5U
#define CMD_BOOTLOADER_DM14                 6U
#define CMD_EDCP_GENERATION_DM14            7U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || defined (__GNUC__) || defined (WIN32) || (__TI_ARM__)
#pragma pack(1)
#endif

/* DM14 - Memory Access Request */
typedef struct tagDM14
{
    uint8_t      NumberRequested;
    unsigned int Rvd                :1;
	unsigned int Command            :3;
    unsigned int PointerTypes       :1;
    unsigned int NumberRequestedExt :3;
    unsigned int Pointer            :24;
	unsigned int PointerExtension   :8;
	uint16_t     KeyOrUserLevel;
} DM14_T;

#if defined  (__ghs__) || defined (__GNUC__) || defined (WIN32) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 DM14_CANMSG (uint32_t Command, 
                                     uint32_t Pointer,
                                     uint32_t NumberRequested,
                                     uint32_t PointerTypes, 
                                     uint32_t KeyOrUserLevel,
									 uint32_t DestinationAddress);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: DM14_canmsg.h$ */
