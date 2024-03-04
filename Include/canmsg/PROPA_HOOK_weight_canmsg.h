/*******************************************************************************
** $Revision: 0$
** $Date: 17/05/2018 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PROPA_HOOK_WEIGHT_CANMSG_H
#define PROPA_HOOK_WEIGHT_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/

/******************************** Enums *********************************/

/******************************** General Msg *********************************/

/* PROPA Messages */
typedef struct tagHOOK_MSG_WEIGHT
{
    uint32_t currentWeight;			 /* Data bytes: byte 0 - 3 Weight. Unit: kg Factor: 1  Offset: 0*/
	uint16_t Rvd1;			         /* Reserved*/
	uint8_t  Rvd2;			         /* Reserved*/
	uint8_t  stable_measurement;    /* 0: unstable measurement / 1: stable measurement*/
} HOOK_MSG_WEIGHT_T;


#endif /* end PROPA_HOOK_WEIGHT_CANMSG_H */

/* End of $Workfile: PROPA_HOOK_weight_canmsg.h$ */
