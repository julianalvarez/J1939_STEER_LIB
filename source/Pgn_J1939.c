
/* Include ********************************************************************/
#include "j1939.h"
#include "canmsg/N2K_GPD_canmsg.h"
#include "canmsg/SAGSM_canmsg.h"
#include "canmsg/SAGPS_canmsg.h"
#include "canmsg/SFT_canmsg.h"
#include "canmsg/DBC_canmsg.h"


/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t Pgn_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t Priority, uint32_t DataLength, 
                   void* pMsg, void* pMsg_Old, uint32_t OnChangeTime, 
                   uint32_t CycleTime, void (*Function)(void))   
{
    uint32_t            i;
    int32_t             result;  

    i = 0U;
    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if (tREG_MSG[ctrl][i].eType == NONE_EVENT) {
            tREG_MSG[ctrl][i].eType          = PGN_EVENT;
            tREG_MSG[ctrl][i].Pgn            = Pgn;
            tREG_MSG[ctrl][i].Priority       = (uint8_t)Priority;
            tREG_MSG[ctrl][i].Length         = DataLength;
            tREG_MSG[ctrl][i].pMsg           = pMsg;
            tREG_MSG[ctrl][i].pMsg_Old       = pMsg_Old;
            tREG_MSG[ctrl][i].bfChanged      = false;
            tREG_MSG[ctrl][i].bfOnChangeTime = false;
            tREG_MSG[ctrl][i].bfCycleTime    = false;
            tREG_MSG[ctrl][i].CounterCT      = 0U;
            tREG_MSG[ctrl][i].CounterOC      = 0U; 
            tREG_MSG[ctrl][i].CycleTime      = (uint16_t)(CycleTime / PERIOD_TIMER_J1939);
            tREG_MSG[ctrl][i].OnChangeTime   = (uint16_t)(OnChangeTime / PERIOD_TIMER_J1939);
            tREG_MSG[ctrl][i].Function       = Function;
            tREG_MSG[ctrl][i].FunctionTM     = NULL;
#ifdef J1939_FAST_PACKET_PROTOCOL
            tREG_MSG[ctrl][i].bfFastPacket   = false;
            tREG_MSG[ctrl][i].Frame          = 0U;
#endif            
            if (DataLength > 8) {

#ifdef J1939_FAST_PACKET_PROTOCOL
                if ((Pgn == PGN_N2K_GPS_POSITION_DATA) ||
                    (Pgn == PGN_SMARTANTENNA_GSM) ||
                    (Pgn == PGN_SMARTANTENNA_GPS) ||
                    (Pgn == PGN_STRING_FP_TRANSPORT)||
					(Pgn == PGN_DYNAMIC_BEZIER_CONTROL)) {
                    tREG_MSG[ctrl][i].bfFastPacket = true;
                    return RC_SUCCESS;
                }      
#endif                           
                
#ifdef J1939_TRANSPORT_PROTOCOL
                result = RegisterTP_O_J1939 (ctrl,
                                             Pgn,
                                             DataLength,
                                             MAX_TP_PACKETS_J1939,
                                             IF_PDU1(Pgn) ? GET_PDUSPECIFIC(Pgn) : 0xFFU,
                                             NULL,
                                             NULL);
#endif
            } else {
                result = RC_SUCCESS;
            }
            break;
        }
    }
    
    return result;       
}

int32_t OneShootPgn_J1939 (uint32_t ctrl, uint32_t Pgn)
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].Pgn == Pgn) &&
            ((tREG_MSG[ctrl][i].eType == PGN_EVENT) ||
             (tREG_MSG[ctrl][i].eType == ONREQUEST_EVENT))) {
            result = RC_SUCCESS;
            tREG_MSG[ctrl][i].bfCycleTime = true;
            break;
        }
    }
    
    return result; 
} 

int32_t Deregister_Pgn_J1939 (uint32_t ctrl, uint32_t Pgn)
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].eType == PGN_EVENT) && (tREG_MSG[ctrl][i].Pgn == Pgn)) {
            tREG_MSG[ctrl][i].eType = NONE_EVENT;
            result = RC_SUCCESS;
        }
    }
    
    return result;  
}

int32_t Deregister_Pgn_Function_J1939(uint32_t ctrl, uint32_t Pgn, void (*Function)(void))
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].eType == PGN_EVENT) && (tREG_MSG[ctrl][i].Pgn == Pgn) && (tREG_MSG[ctrl][i].Function == Function)) {
            tREG_MSG[ctrl][i].eType = NONE_EVENT;
            result = RC_SUCCESS;
        }
    }
    
    return result;  
}

/* End of $Workfile: Pgn_J1939.c$ */

