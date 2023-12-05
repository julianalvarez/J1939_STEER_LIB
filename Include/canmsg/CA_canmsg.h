/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:51 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef CA_CANMSG_H
#define CA_CANMSG_H

/* Include ********************************************************************/
#include "../types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_COMMANDED_ADDRESS               0xFED8U
#define SIZE_COMMANDED_ADDRESS              9U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagCOMMANDED_ADDRESS
{
    uint32_t Identity_Number    :21;
    uint32_t Manufacturer_Code  :11;

    uint8_t  Ecu_Instance       :3;
    uint8_t  Function_Instance  :5;

    uint8_t  Function;

    uint8_t  Reserved           :1;
    uint8_t  Vehicle_System     :7;

    uint8_t  Vehicle_Instance   :4;
    uint8_t  Industry_Group     :3;
    uint8_t  Arbitrary_Address  :1;

    uint8_t Commanded_Address;
} COMMANDED_ADDRESS_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
int32_t     CA_CANMSG(uint32_t ctrl);

#if defined(__cplusplus)
extern "C" 
{
#endif

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: CA_canmsg.h$ */
