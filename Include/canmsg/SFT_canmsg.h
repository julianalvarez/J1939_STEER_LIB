/*******************************************************************************
** $Revision: 0$
** $Date: 06/09/2016 15:35:00 p.m.$
** $Author: Federico Baulies$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef SFT_CANMSG_H
#define SFT_CANMSG_H

/*! String Fast Packet Transport
 *
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_STRING_FP_TRANSPORT	    0xFFD7U
#define SIZE_STRING_FP_TRANSPORT    34U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagSTRING_FP_TRANSPORT_DATA
{
    uint8_t      singleByte_00; // Sent as Fast Packet: 6 bytes + 7 bytes x4 = 34 bytes
    uint8_t      singleByte_01;
    uint8_t      singleByte_02;
    uint8_t      singleByte_03;
    uint8_t      singleByte_04;
    uint8_t      singleByte_05;
    uint8_t      singleByte_06;
    uint8_t      singleByte_07;
    uint8_t      singleByte_08;
    uint8_t      singleByte_09;
    uint8_t      singleByte_10;
    uint8_t      singleByte_11;
    uint8_t      singleByte_12;
    uint8_t      singleByte_13;
    uint8_t      singleByte_14;
    uint8_t      singleByte_15;
    uint8_t      singleByte_16;
    uint8_t      singleByte_17;
    uint8_t      singleByte_18;
    uint8_t      singleByte_19;
    uint8_t      singleByte_20;
    uint8_t      singleByte_21;
    uint8_t      singleByte_22;
    uint8_t      singleByte_23;
    uint8_t      singleByte_24;
    uint8_t      singleByte_25;
    uint8_t      singleByte_26;
    uint8_t      singleByte_27;
    uint8_t      singleByte_28;
    uint8_t      singleByte_29;
    uint8_t      singleByte_30;
    uint8_t      singleByte_31;
    uint8_t      singleByte_32;
    uint8_t      singleByte_33;
} STRING_FP_TRANSPORT_DATA;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: SFT_canmsg.h$ */
