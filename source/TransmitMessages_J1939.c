/*******************************************************************************
** $Revision: 3$
** $Date: 16/12/2013 07:30:54 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"
#include "hal/hal.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t TransmitMessages_J1939 (uint32_t ctrl, J1939_MESSAGE_T* pJ1939Msg)
{
    int32_t             result;

    result = RC_SUCCESS;

    if (pJ1939Msg->Length <= 8) {
        /* Force to Extended id Message */
        pJ1939Msg->bfEFF = 1;   
        PutMSG_CAN (ctrl, pJ1939Msg);
    } 
    
#ifdef J1939_TRANSPORT_PROTOCOL
    else if (J1939_TP_TxBsy[ctrl] == true) {
        J1939_CIR_BUF_PUSH (j1939_TP_TX[ctrl], *pJ1939Msg);
    } else {
        result = TP_O_J1939 (ctrl,
                             pJ1939Msg->Pgn,
                             pJ1939Msg->pData);
    }        
#endif

    return (result);  
}

/* End of $Workfile: TransmitMessages_J1939.c$ */

