/* Include ********************************************************************/
#include "j1939.h"
#include "canmsg/rqst_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/

/*
 *   FunctionAC return the if was knowledge or the pgn was received
 *              but when the callback is called the data is not there
 *              See there is NO message structure (pMsg) in the API!
 *
 *   FunctionTM is called if no responce was received.
 */
int32_t Request_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t DestinationAddress, 
                       void (*FunctionAC)(uint32_t Addr, uint32_t ControlByte),
                       uint32_t TimeOut, void (*FunctionTM)(void))
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if (tREG_MSG[ctrl][i].eType == NONE_EVENT) {
            tREG_MSG[ctrl][i].eType          = REQUEST_EVENT;
            tREG_MSG[ctrl][i].Pgn            = Pgn;
            tREG_MSG[ctrl][i].pMsg           = NULL;
            tREG_MSG[ctrl][i].FunctionAC     = FunctionAC;
            tREG_MSG[ctrl][i].CounterTimeOut = 0U;
            tREG_MSG[ctrl][i].TimeOut        = (uint16_t)(TimeOut / PERIOD_TIMER_J1939);
            tREG_MSG[ctrl][i].FunctionTM     = FunctionTM;
#ifdef J1939_FAST_PACKET_PROTOCOL
            tREG_MSG[ctrl][i].bfFastPacket   = false;
            tREG_MSG[ctrl][i].Frame          = 0xFFU;
#endif            
            result = RC_SUCCESS;
                    
            /* Request Message	  */
            result = RQST_CANMSG (ctrl, Pgn, DestinationAddress);
            if (AddFilter_J1939 (ctrl, Pgn)) {
                return RC_ERROR;
            }				  
            break;
        }
        i++;
    }

    return result;
}

int32_t Deregister_Request_J1939 (uint32_t ctrl, uint32_t Pgn)
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].eType == REQUEST_EVENT) && (tREG_MSG[ctrl][i].Pgn == Pgn)) {
            tREG_MSG[ctrl][i].eType = NONE_EVENT;
            result = RC_SUCCESS;
        }
    }
    
    return result;  
}

/* End of $Workfile: Request_J1939.c$ */

