/*******************************************************************************
** $Revision: 7$
** $Date: 21/08/2013 03:21:48 p.m.$
** $Author: Federico Baulies$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"
#ifdef J1939_TRANSPORT_PROTOCOL
#include <string.h>
#include "TPCM_canmsg.h"
#include "TPDT_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
extern void             Conn_Abort_J1939 (void);

/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Origniator States */
static void             _IDLE_O_SM_J1939 (J1939_TP_T* pTP);
static void             _BAM_O_SM_J1939 (J1939_TP_T* pTP);
static void             _RTS_O_SM_J1939 (J1939_TP_T* pTP);
static void             _CTS_O_SM_J1939 (J1939_TP_T* pTP);
static void             _DT_O_SM_J1939 (J1939_TP_T* pTP);
static void             _EOMACK_O_SM_J1939 (J1939_TP_T* pTP);

/* Responder States */
static void             _IDLE_R_SM_J1939 (J1939_TP_T* pTP);
static void             _BAM_R_SM_J1939 (J1939_TP_T* pTP);
static void             _RTS_R_SM_J1939 (J1939_TP_T* pTP);
static void             _CTS_R_SM_J1939 (J1939_TP_T* pTP);
static void             _DT_R_SM_J1939 (J1939_TP_T* pTP, uint8_t* pData);
static void             _EOMACK_R_SM_J1939 (J1939_TP_T* pTP);

void                    (*tp_sm_table[12])() = {_IDLE_O_SM_J1939,
                                                _BAM_O_SM_J1939,
                                                _RTS_O_SM_J1939, 
                                                _CTS_O_SM_J1939,
                                                _DT_O_SM_J1939,
                                                _EOMACK_O_SM_J1939,
                                                _IDLE_R_SM_J1939,
                                                _BAM_R_SM_J1939,
                                                _RTS_R_SM_J1939, 
                                                _CTS_R_SM_J1939,
                                                _DT_R_SM_J1939,
                                                _EOMACK_R_SM_J1939};

/* Functions ******************************************************************/

/*
 * Call State
 */
void TP_SM_J1939 (J1939_TP_T* pTP)
{
    tp_sm_table[pTP->CurrState](pTP);
}

/*
 * Set State
 */
void TP_Set_SM_J1939 (J1939_TP_T* pTP, J1939_TP_E NewState)
{
    pTP->CurrState = NewState;
    (tp_sm_table[NewState])(pTP);
}

/*
 * Set Data
 */
void TP_SetData_SM_J1939 (J1939_TP_T* pTP, uint8_t* pData)
{
    (tp_sm_table[DT_R_SM_J1939])(pTP, pData);
}

/*
 * Get Current State
 */
J1939_TP_E TP_Get_SM_J1939 (J1939_TP_T* pTP)
{
    return (pTP->CurrState);
}

/*
 * Register Transport Protocol Message Originator
 */
int32_t RegisterTP_O_J1939 (uint32_t ctrl,
                            uint32_t Pgn,
                            uint32_t DataLength,
                            uint32_t MaximumNumberOfPackets,
                            uint32_t DestinationAddress,
                            void (*pfEOMACK)(void),
                            void (*pfABORT)(void))
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR;
     
    for (i = 0; i < MAX_TRANSPORT_PROTOCOL_J1939; i++) { 
        if ((tTP[ctrl][i].Pgn == Pgn) && 
            (tTP[ctrl][i].Flag.bfOriginator)) {
            /* Already Registered */
            result = RC_SUCCESS;
            break;
        }           
            
        if (tTP[ctrl][i].Pgn == 0) {
            result = RC_SUCCESS;
            tTP[ctrl][i].Flag.bfOriginator      = true;
            tTP[ctrl][i].Flag.bfResponder       = false;
            tTP[ctrl][i].Flag.bfMessageReceived = false;
            tTP[ctrl][i].Ctrl = ctrl;
            tTP[ctrl][i].Pgn  = Pgn;         

            /* Total Message Size in Bytes */
            tTP[ctrl][i].TotalMessageSize = (uint16_t)DataLength;
        
            /* Total Number of Packets */
            tTP[ctrl][i].TotalNumberOfPackets = (uint16_t)(DataLength / 7U);
            if ((DataLength % 0x7U) != 0U) {
                tTP[ctrl][i].TotalNumberOfPackets++;
            }
        
            /* Initialize Counters */
            tTP[ctrl][i].NumberOfPackets = 0U;
            tTP[ctrl][i].SequenceNumber  = 0U;
        
            /* Initialize Destination Address */
            tTP[ctrl][i].DestinationAddress = (uint8_t)DestinationAddress;
        
            /* Initialize Function pointers */ 
            tTP[ctrl][i].pfEOMACK = pfEOMACK;
            tTP[ctrl][i].pfABORT  = pfABORT;
        
            /* Max Number of Packets can be sent to one CTS */
            tTP[ctrl][i].MaximumNumberOfPackets = (uint16_t)MaximumNumberOfPackets;
            break;
        }
    }
    
    return result;
}

/*
 * Transport Protocol Transmission Originator 
 */
int32_t TP_O_J1939 (uint32_t ctrl,
                    uint32_t Pgn,
                    void*    pMsg)
{
    uint32_t            i;
    int32_t             result;

    result = RC_ERROR; 

    for (i = 0; i < MAX_TRANSPORT_PROTOCOL_J1939; i++) { 
        if ((tTP[ctrl][i].Pgn == Pgn) &&
            (tTP[ctrl][i].Flag.bfOriginator)) {
            result = RC_SUCCESS;
            /* Block TP */
            J1939_TP_TxBsy[ctrl] = true;
            /* Initialize */
            tTP[ctrl][i].pMsg            = pMsg;
            tTP[ctrl][i].NumberOfPackets = 0U;
            tTP[ctrl][i].SequenceNumber  = 0U;
            tTP[ctrl][i].MessageSize     = 0U;
    
            if (tTP[ctrl][i].DestinationAddress == J1939_ADDRESS_GLOBAL) {
                /* Set Flag Broadcast Announce Message */
                tTP[ctrl][i].Flag.bfBAM = true;
        
                /* Next State: Send BAM */
                TP_Set_SM_J1939 (&tTP[ctrl][i], BAM_O_SM_J1939);  
            } else {
                /* Clear Flag Broadcast Announce Message */
                tTP[ctrl][i].Flag.bfBAM = false;
            
                /* Next State: Send RTS */
                TP_Set_SM_J1939 (&tTP[ctrl][i], RTS_O_SM_J1939);
            }
            break;
        }
    }

    return result;
}

/*
 * BAM State
 */
static void _BAM_O_SM_J1939 (J1939_TP_T* pTP)
{
    /* Send BAM */
    TPCM_BAM_CANMSG (pTP->Ctrl,
                     pTP->Pgn,
                     pTP->DestinationAddress, 
                     pTP->TotalMessageSize,
                     pTP->TotalNumberOfPackets);

    /* State: Send DT */
    TP_Set_SM_J1939 (pTP, DT_O_SM_J1939);			
}

/*
 * RTS State
 */
static void _RTS_O_SM_J1939 (J1939_TP_T* pTP)
{
    /* Send RTS */
    TPCM_RTS_CANMSG (pTP->Ctrl,
                     pTP->Pgn,
                     pTP->DestinationAddress, 
                     pTP->TotalMessageSize,
                     pTP->TotalNumberOfPackets,
                     pTP->MaximumNumberOfPackets);
    
    /* TimeOut - Tr */
    TimeOut_J1939 (pTP->Ctrl, TIMEOUT_R_J1939, pTP->pfABORT);
}

/*
 * CTS State
 */
static void _CTS_O_SM_J1939 (J1939_TP_T* pTP)
{
    /* Reset TimeOut - T3 */
    ResetTimeOut_J1939 (pTP->Ctrl, pTP->pfABORT);
    
    /* Clear Packet Number Counter for a CTS */
    pTP->NumberOfPackets = 0U;
    
    /* Hold the Connection */
    if (pTP->NumberOfPacketsCanSent == 0U)  {
        /* TimeOut - T4 */
        TimeOut_J1939 (pTP->Ctrl, TIMEOUT_4_J1939, pTP->pfABORT);
    } else if (pTP->NextPacketNumberToBeSent == pTP->SequenceNumber) {
        /* Re-Send Last Packet */			
        pTP->MessageSize -= 7U;
        pTP->SequenceNumber--;
    
        /* TimeOut - T1 */
        TimeOut_J1939 (pTP->Ctrl, TIMEOUT_1_J1939, pTP->pfABORT);
    
        /* State: Send DT */
        TP_Set_SM_J1939 (pTP, DT_O_SM_J1939);			
    }
    
    if (pTP->NextPacketNumberToBeSent == (pTP->SequenceNumber + 1U)) {
        /* TimeOut - T1 */
        TimeOut_J1939 (pTP->Ctrl, TIMEOUT_1_J1939, pTP->pfABORT);
    
        /* State: Send DT */
        TP_Set_SM_J1939 (pTP, DT_O_SM_J1939);			
    } else {
        /* Error - Abort */
        if (pTP->pfABORT != NULL) {
            pTP->pfABORT();
        }
    }
}

/*
 * Data State
 */
static void _DT_O_SM_J1939 (J1939_TP_T* pTP)
{
    uint32_t            MessageLeft;
    uint8_t             pData[8];

    /* Reset TimeOut - T1 Or T4 */
    ResetTimeOut_J1939 (pTP->Ctrl, pTP->pfABORT);

    /* Calc of bytes left */
    MessageLeft = pTP->TotalMessageSize - pTP->MessageSize;  

    /* Actualize Sequence Number*/
    pTP->SequenceNumber++;

    /* Actualize the packet number for this CTS */
    pTP->NumberOfPackets++;

    /* Fill the rest with 0xFFU */
    memset (pData, 0xFF, 8);
    /* Fill with Data */
    memcpy (pData, &((uint8_t*)(pTP->pMsg))[pTP->MessageSize], (MessageLeft > 7) ? 7U : MessageLeft);

    /* Transport Protocol - Data Transfer */
    TPDT_CANMSG (pTP->Ctrl,
                 pTP->DestinationAddress, 
                 pTP->SequenceNumber, 
                 pData);

    /* Actualize Bytes sent */
    pTP->MessageSize += 7U;

    /* If the total bytes of message was SENT */
    if (pTP->MessageSize >= pTP->TotalMessageSize) {
        /* We have Finished */
        if (pTP->Flag.bfBAM == false) {
            /* TimeOut - T3 */
            TimeOut_J1939 (pTP->Ctrl, TIMEOUT_3_J1939, pTP->pfABORT);
        }

        /* State: IDLE */
        TP_Set_SM_J1939 (pTP, IDLE_O_SM_J1939);			
    } else if (pTP->Flag.bfBAM == false) {
        if (pTP->NumberOfPacketsCanSent == pTP->NumberOfPackets) {
            /* We need to wait a CTS */
            /* TimeOut - T3 */
            TimeOut_J1939 (pTP->Ctrl, TIMEOUT_3_J1939, pTP->pfABORT);

            /* State: IDLE */
            TP_Set_SM_J1939 (pTP, IDLE_O_SM_J1939);			      
        } else {
            /* We need send more Data */
            /* TimeOut - T1 */
            TimeOut_J1939 (pTP->Ctrl, TIMEOUT_1_J1939, pTP->pfABORT);
        }
    }
}

/*
 * End of Message 
 */
static void _EOMACK_O_SM_J1939 (J1939_TP_T* pTP)
{
    /* Reset TimeOut - T3 */
    ResetTimeOut_J1939 (pTP->Ctrl, pTP->pfABORT);

    /* Reset Entry */
    pTP->TotalMessageSize = 0U;
    pTP->Flag.bfResponder = false;

    /* Check if Total Size (Originator) == Total Size (Responder) */
    if (pTP->MessageSize >= pTP->TotalMessageSize) {
        /* Call Finished Function */
        if (pTP->pfEOMACK != NULL) {
            pTP->pfEOMACK();
        }
    } else {
        /* Call Connection Abort Function */
        if (pTP->pfABORT != NULL) {
            pTP->pfABORT();
        }
    }
}

/*
 *
 */
static void _IDLE_O_SM_J1939 (J1939_TP_T* pTP)
{
    J1939_MESSAGE_T     tJ1939Msg;

    /* unBlock TP */
    J1939_TP_TxBsy[pTP->Ctrl] = false;
    if (J1939_CIR_BUF_EMPTY (j1939_TP_TX[pTP->Ctrl]) == false) {
        tJ1939Msg = J1939_CIR_BUF_POP (j1939_TP_TX[pTP->Ctrl]);
        TP_O_J1939 (pTP->Ctrl, tJ1939Msg.Pgn, tJ1939Msg.pData);                
    }        
}

/*
 *  Register Transport Protocol Message Responder 
 */
int32_t RegisterTP_R_J1939 (uint32_t ctrl,
                            uint32_t Pgn,
                            void*    pMsg, 
                            uint32_t NumberOfPacketsCanSent,
                            uint32_t (*pfEOMACKA) (uint32_t Addr),
                            void     (*pfABORT)(void))
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 

    for (i = 0; i < MAX_TRANSPORT_PROTOCOL_J1939; i++) { 
        if (tTP[ctrl][i].Pgn == 0) {
            result = RC_SUCCESS;

            /* Add a Mark to show that this entry was taken */
            tTP[ctrl][i].TotalMessageSize = 0xFFFFU;
        
            /* Responder */
            tTP[ctrl][i].Flag.bfOriginator      = false;
            tTP[ctrl][i].Flag.bfResponder       = true;
            tTP[ctrl][i].Flag.bfMessageReceived = false;
            tTP[ctrl][i].Ctrl = ctrl;
            tTP[ctrl][i].Pgn  = Pgn;
            tTP[ctrl][i].pMsg = pMsg;
        
            /* Number of Packets Can receive between CTS */
            tTP[ctrl][i].NumberOfPacketsCanSent = (uint8_t)NumberOfPacketsCanSent;
        
            /* Initialize Function pointers */ 
            tTP[ctrl][i].pfEOMACKA = pfEOMACKA;
            tTP[ctrl][i].pfABORT   = pfABORT;
        
            /* Clear Flag Broadcast Announce Message */
            tTP[ctrl][i].Flag.bfBAM = false;
            break;
        }
    }

    return result;
}

/*
 *
 */
static void _BAM_R_SM_J1939 (J1939_TP_T* pTP)
{
    /* TimeOut - Tr */
    TimeOut_J1939 (pTP->Ctrl, TIMEOUT_R_J1939, pTP->pfABORT);	
}

/*
 *
 */
static void _RTS_R_SM_J1939 (J1939_TP_T* pTP)
{
    /* TimeOut - Tr */
    TimeOut_J1939 (pTP->Ctrl, TIMEOUT_R_J1939, pTP->pfABORT);

    /*  Next State: Waiting for CTS */
    TP_Set_SM_J1939 (pTP, CTS_R_SM_J1939);			  
}

/*
 *
 */
static void _CTS_R_SM_J1939 (J1939_TP_T* pTP)
{
    /* Send CTS */ 
    TPCM_CTS_CANMSG (pTP->Ctrl,
                     pTP->Pgn,
                     pTP->DestinationAddress, 
                     pTP->NumberOfPacketsCanSent,
                     pTP->NextPacketNumberToBeSent);

    /* TimeOut - T2 */
    TimeOut_J1939 (pTP->Ctrl, TIMEOUT_2_J1939, pTP->pfABORT);
}

/*
 *
 */
static void _DT_R_SM_J1939 (J1939_TP_T* pTP, uint8_t* pData)
{
    uint32_t            MessageLeft;

    /* Reset TimeOut - T1 */
    ResetTimeOut_J1939 (pTP->Ctrl, pTP->pfABORT);

    /* if SequenceNumber from struct Match with received SequenceNumber */
    if (pTP->NextPacketNumberToBeSent == pData[0]) {
        pTP->NextPacketNumberToBeSent++;
        pTP->NumberOfPackets++;
    } else {
        /* Connection Abort */
        if (pTP->pfABORT != NULL) {
            pTP->pfABORT();
        }
    }
  
    /* Calc of bytes left */
    MessageLeft = (pTP->TotalMessageSize - pTP->MessageSize);  

    /* Copy Data */
    memcpy (((uint8_t*)pTP->pMsg + pTP->MessageSize), (pData + 1), (MessageLeft > 7) ? 7U : MessageLeft);
    pTP->MessageSize += ((MessageLeft > 7) ? 7U : MessageLeft);

    if (MessageLeft > 7U) {    
        /* Check if is time to send a CTS */
        if (pTP->NumberOfPacketsCanSent == pTP->NumberOfPackets) {
            if (pTP->Flag.bfBAM == false) {
                /* Reset Count for next CTS */
                pTP->NumberOfPackets = 0U;

                /* Next State: Send CTS */
                TP_Set_SM_J1939 (pTP, CTS_R_SM_J1939);			  
            }
        } else {
            /* TimeOut - T1 */
            TimeOut_J1939 (pTP->Ctrl, TIMEOUT_1_J1939, pTP->pfABORT);
        }
    } else {
        pTP->Flag.bfMessageReceived = true;
        if (pTP->Flag.bfBAM == false) {
            /* Next State: Send EOMACK */
            TP_Set_SM_J1939 (pTP, EOMACK_R_SM_J1939);			  
        } else if (pTP->pfEOMACKA != NULL) {
            pTP->pfEOMACKA (pTP->DestinationAddress);
        } else {
/* LNG */
            TP_Set_SM_J1939 (pTP, IDLE_R_SM_J1939);
        }
    }
}

/*
 * End of Message 
 */
static void _EOMACK_R_SM_J1939 (J1939_TP_T* pTP)
{
    /* Send EOMACK */
    TPCM_EOMACK_CANMSG (pTP->Ctrl,
                        pTP->Pgn,
                        pTP->DestinationAddress, 
                        pTP->TotalMessageSize,
                        pTP->TotalNumberOfPackets);

    /* Call Finished Function */
    if (pTP->pfEOMACKA != NULL) {
        pTP->pfEOMACKA (pTP->DestinationAddress);
    } else {
/* LNG */
        TP_Set_SM_J1939 (pTP, IDLE_R_SM_J1939);
    }
}

/*
 *
 */
static void _IDLE_R_SM_J1939 (J1939_TP_T* pTP)
{
}

#endif

/* End of $Workfile: TP_J1939.c$ */

