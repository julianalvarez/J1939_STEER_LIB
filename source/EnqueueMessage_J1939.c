/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:17 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t EnqueueMessage_J1939 (uint32_t ctrl, J1939_MESSAGE_T* pJ1939Msg)
{
    int32_t             result;

    result = RC_SUCCESS;

    if (J1939_Flags[ctrl].CannotClaimAddress == true) {
        result = RC_CANNOTTRANSMIT;
    } else {
        TransmitMessages_J1939 (ctrl, pJ1939Msg);
    }

    return result;
}

/* End of $Workfile: EnqueueMessage_J1939.c$ */

