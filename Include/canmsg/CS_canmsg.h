/*******************************************************************************
** $Revision: 4$
** $Date: 02/02/2011 03:05:34 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef CS_CANMSG_H
#define CS_CANMSG_H

/*! \page CS Can Status
 *  \section sec130 Receive Warning:
 *      0b00 = <B>FALSE</B>    \n
 *      0b01 = <B>TRUE</B>     \n
 *      0b10 = <B>ERROR</B>    \n
 *      0b11 = <B>NA</B>       \n
 *  \section sec131 Transmit Warning:
 *      0b00 = <B>FALSE</B>    \n
 *      0b01 = <B>TRUE</B>     \n
 *      0b10 = <B>ERROR</B>    \n
 *      0b11 = <B>NA</B>       \n
 *  \note Recv and Trans Warnings become TRUE when errors reach a value > 96 errors.
 *  \section sec132 Receive Passive:
 *      0b00 = <B>FALSE</B>    \n
 *      0b01 = <B>TRUE</B>     \n
 *      0b10 = <B>ERROR</B>    \n
 *      0b11 = <B>NA</B>       \n
 *  \section sec133 Transmit Passive:
 *      0b00 = <B>FALSE</B>    \n
 *      0b01 = <B>TRUE</B>     \n
 *      0b10 = <B>ERROR</B>    \n
 *      0b11 = <B>NA</B>       \n
 *  \note Recv and Trans Passive become TRUE when errors reach a value > 127 errors.
 *  \section sec136 Port Number:
 *      0b0000 = <B>Port 0</B> \n
 *      0b0001 = <B>Port 1</B> \n
 *      0b0010 = <B>Port 2</B> \n
 *      0b1111 = <B>NA</B>     \n
 *  \section sec134 Receive Error Counter:
 *      0x00 - 0xFF
 *  \section sec135 Transmit Error Counter:
 *      0x00 - 0xFF
 *  \note Recv and Trans Error Counters doesn't have <B>RVD, ERROR or NA Values</B>.
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_CAN_STATUS                      0xFF01U
#define PGN_CAN_STATUS_2                    0xFF0FU // Defined as shadow of 0xFF01 to avoid collisions with AGCO/BOSH
#define SIZE_CAN_STATUS                     3U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagCAN_STATUS
{
    unsigned int ReceiveWarning     :1;
    unsigned int TransmitWarning    :1;
    unsigned int ReceiveBusPassive  :1;
    unsigned int TransmitBusPassive :1;
    unsigned int Port 	            :4;
    uint8_t      ReceiveErrorCounter;
    uint8_t      TransmitErrorCounter; 
} CAN_STATUS_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 CS_CANMSG (uint32_t ctrl);
int32_t                 CS_2_CANMSG (uint32_t ctrl);
int32_t                 CS_CANMSG_CONFIGURABLE (uint32_t ctrl, uint32_t ctrl_info, bool usePGN_2);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: CS_canmsg.h$ */


