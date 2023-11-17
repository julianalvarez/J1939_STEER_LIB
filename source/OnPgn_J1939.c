/*******************************************************************************
** $Revision: 9$
** $Date: 29/05/2014 09:04:14 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include <assert.h>
#include "j1939.h"
#include "N2K_GPD_canmsg.h"
#include "SAGSM_canmsg.h"
#include "SAGPS_canmsg.h"
#include "SFT_canmsg.h"
#include "DBC_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static uint32_t         (*FunctionAllFilter)(uint32_t ctrl, J1939_MESSAGE_T* pMsg);

/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t OnPgn_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t DataLength, void* pMsg,
                     uint32_t (*FunctionA)(uint32_t Addr), 
                     uint32_t TimeOut, void (*FunctionTM)(void))
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if (tREG_MSG[ctrl][i].eType == NONE_EVENT) {
            tREG_MSG[ctrl][i].eType          = ONPGN_EVENT;
            tREG_MSG[ctrl][i].Pgn            = Pgn;
            tREG_MSG[ctrl][i].pMsg           = pMsg;
            tREG_MSG[ctrl][i].FunctionA      = FunctionA;
            tREG_MSG[ctrl][i].CounterTimeOut = 0U;
            tREG_MSG[ctrl][i].TimeOut        = (uint16_t)(TimeOut / PERIOD_TIMER_J1939);
            tREG_MSG[ctrl][i].FunctionTM     = FunctionTM;
            tREG_MSG[ctrl][i].Length         = DataLength;
#ifdef J1939_FAST_PACKET_PROTOCOL
            tREG_MSG[ctrl][i].bfFastPacket   = false;
            tREG_MSG[ctrl][i].Frame          = 0xFFU;
#endif
            result = RC_SUCCESS;
            
            if (DataLength > 8) {
#ifdef J1939_FAST_PACKET_PROTOCOL
                /* Fast Packet - Messages > 8 bytes for NMEA2000 */
                if ((Pgn == PGN_N2K_GPS_POSITION_DATA) ||
                    (Pgn == PGN_SMARTANTENNA_GSM) ||
                    (Pgn == PGN_SMARTANTENNA_GPS) ||
                    (Pgn == PGN_STRING_FP_TRANSPORT)||
					(Pgn == PGN_DYNAMIC_BEZIER_CONTROL)) {
                    tREG_MSG[ctrl][i].bfFastPacket = true;
                    if (AddFilter_J1939 (ctrl, Pgn)) {
                        return RC_ERROR;
                    }
                    break;
                }
#endif                           
                                
#ifdef J1939_TRANSPORT_PROTOCOL
                /* Transport Protocol - Messages > 8 bytes for J1939 */
                result = RegisterTP_R_J1939 (ctrl,
                                             Pgn,
                                             pMsg, 
                                             MAX_TP_PACKETS_J1939,
                                             NULL,
                                             NULL);
                break;
#endif
            } else {
                /* Messages with <= 8 bytes */
                if (AddFilter_J1939 (ctrl, Pgn)) {
                    return RC_ERROR;
                }
                break;                
            }
        } 
    }

    
    return result;
}

/*
 *  
 */
int32_t OnPgnAllFilter_J1939 (uint32_t ctrl, uint32_t (*FunctionA)(uint32_t ctrl, J1939_MESSAGE_T* pMsg))
{
    FunctionAllFilter = FunctionA;
    
    return RC_SUCCESS;    
}

/*
 *
 */
int32_t FunctionAllFilter_J1939 (uint32_t ctrl, J1939_MESSAGE_T* pMsg)
{
    FunctionAllFilter (ctrl, pMsg);

    return RC_SUCCESS;
}

int32_t Deregister_onPgn_J1939 (uint32_t ctrl, uint32_t Pgn)
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].eType == ONPGN_EVENT) && (tREG_MSG[ctrl][i].Pgn == Pgn)) {
            tREG_MSG[ctrl][i].eType = NONE_EVENT;
            result = RC_SUCCESS;
        }
    }
    
    return result;  
}


/*
 *  [TODO]
 * DO NOT USE this, we have to check the conditional Pgn == 0!!
 */
int32_t ClearRegisteredOnPgn_J1939 (uint32_t ctrl)
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0U; i < MAX_REG_MSG_J1939; i++) {
        if (tREG_MSG[ctrl][i].eType == ONPGN_EVENT) {
            tREG_MSG[ctrl][i].eType          = NONE_EVENT;
            tREG_MSG[ctrl][i].Pgn            = 0;
            tREG_MSG[ctrl][i].pMsg           = 0;
            tREG_MSG[ctrl][i].FunctionA      = 0;
            tREG_MSG[ctrl][i].CounterTimeOut = 0;
            tREG_MSG[ctrl][i].TimeOut        = 0;
            tREG_MSG[ctrl][i].FunctionTM     = 0;

            /* [TODO]
             *  Make it for TP
                
            if (sizeMsg > 8) {
                result = RegisterTP_R_J1939 (ctrl,
                                             Pgn,
                                             pMsg, 
                                             0xFFU,
                                             NULL,
                                             NULL);
            } else {
                result = RC_SUCCESS;
            } */

            /*
            if (deleteFilter_J1939 (ctrl, Pgn)) {
                return RC_ERROR;
            }*/
        }
    }

    return result < 0 ? result : i;
}


/* End of $Workfile: OnPgn_J1939.c$ */

