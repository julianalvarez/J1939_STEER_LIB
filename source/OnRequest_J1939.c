#include "j1939.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t OnRequest_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t Priority, 
                         uint32_t DataLength, void* pMsg, 
                         uint32_t (*FunctionA)(uint32_t Addr))
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if (tREG_MSG[ctrl][i].eType == NONE_EVENT) {
            tREG_MSG[ctrl][i].eType     = ONREQUEST_EVENT;
            tREG_MSG[ctrl][i].Pgn       = Pgn;
            tREG_MSG[ctrl][i].Priority  = (uint8_t)Priority;
            tREG_MSG[ctrl][i].Length    = DataLength;
            tREG_MSG[ctrl][i].pMsg      = pMsg;
            tREG_MSG[ctrl][i].FunctionA = FunctionA;     
#ifdef J1939_FAST_PACKET_PROTOCOL
            tREG_MSG[ctrl][i].bfFastPacket = false;
            tREG_MSG[ctrl][i].Frame        = 0xFFU;
#endif
            if (DataLength > 8) {
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

int32_t Deregister_onRequest_J1939 (uint32_t ctrl, uint32_t Pgn)
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].eType == ONREQUEST_EVENT) && (tREG_MSG[ctrl][i].Pgn == Pgn)) {
            tREG_MSG[ctrl][i].eType = NONE_EVENT;
            result = RC_SUCCESS;
        }
    }
    
    return result;  
}

/* End of $Workfile: OnRequest_J1939.c$ */

