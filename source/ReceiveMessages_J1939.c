/*******************************************************************************
** $Revision: 6$
** $Date: 08/01/2014 05:50:20 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"
#include "../../hal/hal.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
void ReceiveMessages_J1939 (uint32_t ctrl, J1939_MESSAGE_T* pJ1939Msg)
{
    uint32_t		    i;
 
#ifdef READ_OWN_MSG_CAN
    if (pJ1939Msg->SourceAddress == J1939_Address[ctrl]) {
		/* Discart Msg */
        continue;           
	}
#endif
    
#ifdef J1939_BRIDGE
    i = 0U;
    while ((tFILTERGW[ctrl][i].Pgn != PGN_INVALID) && (i < MAX_FILTERGW_J1939)) {
        if (GET_PDUFORMAT (tFILTERGW[ctrl][i].Pgn) == GET_PDUFORMAT (pJ1939Msg->Pgn)) {
            if (IF_PDU1 (pJ1939Msg->Pgn) ||
                (GET_PDUSPECIFIC(tFILTERGW[ctrl][i].Pgn) == GET_PDUSPECIFIC(pJ1939Msg->Pgn))) {
                /* Put it in FIFO RX */
                if (J1939_CIR_BUF_FULL (j1939_RXGW[ctrl])) {
                    J1939_FlagsGW[ctrl].ReceivedMessagesDropped = true;
                } else {
                    J1939_CIR_BUF_PUSH(j1939_RXGW[ctrl], *pJ1939Msg);
                }
                break;
            }
        }       
        i++;
    }
#endif

    
    /* if PDU1 */
    if (IF_PDU1 (pJ1939Msg->Pgn)) {
        /* if the destination is GLOBAL_ADDRESS | ADDRESS ELSE discart */
        if ((GET_PDUSPECIFIC (pJ1939Msg->Pgn) != J1939_Address[ctrl]) &&
            (GET_PDUSPECIFIC (pJ1939Msg->Pgn) != J1939_ADDRESS_GLOBAL)) { 
            /* not our ADDRESS or not GLOBAL_ADDRESS */
            /* Discart Msg */
            return;
        }
    } 

    /* Software Filter */
    /* if All Filter is = enabled, means all messages goes trough */
    if (ifAllFilter_J1939(ctrl) == true) {
        /* Put it in FIFO RX */
        if (J1939_CIR_BUF_FULL (j1939_RX[ctrl])) {
            J1939_Flags[ctrl].ReceivedMessagesDropped = true;
        } else {
            J1939_CIR_BUF_PUSH(j1939_RX[ctrl], *pJ1939Msg);
        }
    } else {
        /* If not, check if is in the FILTER Table */
        i = 0U;
        while ((tFILTER[ctrl][i].Pgn != PGN_INVALID) && (i < MAX_FILTER_J1939)) {
            if (GET_PDUFORMAT (tFILTER[ctrl][i].Pgn) == GET_PDUFORMAT (pJ1939Msg->Pgn)) {
                if (IF_PDU1 (pJ1939Msg->Pgn) ||
                    (GET_PDUSPECIFIC(tFILTER[ctrl][i].Pgn) == GET_PDUSPECIFIC(pJ1939Msg->Pgn))) {
                    /* Put it in FIFO RX */
                    if (J1939_CIR_BUF_FULL (j1939_RX[ctrl])) {
                        J1939_Flags[ctrl].ReceivedMessagesDropped = true;
                    } else {
                        J1939_CIR_BUF_PUSH(j1939_RX[ctrl], *pJ1939Msg);
                    }
                    break;
                }
            }       
            i++;
        }
    }
}

/* End of $Workfile: ReceiveMessages_J1939.c$ */

