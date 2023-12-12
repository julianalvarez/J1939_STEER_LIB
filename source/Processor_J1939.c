/*******************************************************************************
** $Revision: 20$
** $Date: 15/10/2014 03:12:12 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include <string.h>
#include <stdio.h>
#include "j1939.h"
#include "hal/hal.h"
#include "include/canmsg/ACKM_canmsg.h"
#include "include/canmsg/TPCM_canmsg.h"
#include "include/canmsg/DM14_canmsg.h"
#include "include/canmsg/DM15_canmsg.h"
#include "include/canmsg/DM16_canmsg.h"
#include "include/canmsg/CA_canmsg.h"
#include "cmsis_gcc.h"

extern uint32_t TIME_Get(void);
/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static uint32_t         __LastCTRLRcv_J1939;
static J1939_MESSAGE_T  __LastMSGRcv_J1939;

/* Prototypes *****************************************************************/
/* Functions ******************************************************************/


/* [TODO]
 *          Allow TP with COMMANDS, ONCOMMANDS, REQUESTS, and ONREQUESTS
 */
void Processor_J1939 (void)
{

    uint32_t            i;
    uint32_t            ctrl;
    uint32_t            Result;
    uint32_t			ControlByte;
    J1939_MESSAGE_T     tJ1939Msg;
    uint32_t            bMessageToProcess;
#ifdef J1939_DIAGNOSTIC_MEMORY
    uint32_t			Address;
    uint32_t			Size;
#endif   

    for (ctrl = 0; ctrl < MAX_PORT_J1939; ctrl++) {
        if (J1939_Flags[ctrl].PortInitialized == false) {
            continue;
        }
        /*
         * BRIDGE
         */
#ifdef J1939_BRIDGE
        __disable_irq();

        while (1) {
            __disable_irq();
            if (J1939_CIR_BUF_COUNT(j1939_RXGW[ctrl])) {
                tJ1939Msg = J1939_CIR_BUF_POP (j1939_RXGW[ctrl]);
                __enable_irq();

                Output_J1939 (ctrl == 0 ? 1 : 0,
                              tJ1939Msg.Pgn, 
                              tJ1939Msg.Priority, 
                              tJ1939Msg.Length, 
                              tJ1939Msg.Data,
                              tJ1939Msg.SourceAddress);
            } else {
                __enable_irq();
                break;
            }
        }
#endif         
        /***************************************
                TIMER PROCESSOR
        ***************************************/
        TimerEvent_J1939 (ctrl);
        TimerProcess_J1939 (ctrl);

        /***************************************
                TRANSMITER PROCESSOR
        ***************************************/
        if (J1939_Flags[ctrl].WaitingForAddressClaimContention == true) {
            if (ContentionWaitTime[ctrl] == 0) {
                if (J1939_Flags[ctrl].CannotClaimAddress) {
                    AddressClaim_J1939(ctrl);
                } else {
                    J1939_Flags[ctrl].WaitingForAddressClaimContention = false;
                    SetAddressFilter_CAN (ctrl, J1939_Address[ctrl]);
                }
            }
        } else {

#ifdef J1939_TRANSPORT_PROTOCOL     
            /* Process Transport Protocol */
            for (i = 0; i < MAX_TRANSPORT_PROTOCOL_J1939; i++) {   
                if (TP_Get_SM_J1939 (&tTP[ctrl][i]) == DT_O_SM_J1939) {
                    /* Send Data Transfer */
                    TP_SM_J1939 (&tTP[ctrl][i]);
                }
            }
#endif
            /* Process PGN */
            for (i = 0; i < MAX_REG_MSG_J1939; i++) {
                if (tREG_MSG[ctrl][i].eType == PGN_EVENT) {
                    if (tREG_MSG[ctrl][i].pMsg != NULL) {
                        /* Fill all of NOT AVAILABLE */
                        memset(tREG_MSG[ctrl][i].pMsg, 0xFFU, tREG_MSG[ctrl][i].Length);
                        tREG_MSG[ctrl][i].Function(); 
                        if (memcmp (tREG_MSG[ctrl][i].pMsg, tREG_MSG[ctrl][i].pMsg_Old, tREG_MSG[ctrl][i].Length)) {
                            /* Set the changed Flag */
                            tREG_MSG[ctrl][i].bfChanged = true;
    
                            /* Update the Old Content */
                            memcpy (tREG_MSG[ctrl][i].pMsg_Old, tREG_MSG[ctrl][i].pMsg, tREG_MSG[ctrl][i].Length);
                        }
                    }

                    if (tREG_MSG[ctrl][i].bfChanged == true) { 
                        /* Changed event */
                        if (tREG_MSG[ctrl][i].bfOnChangeTime == true) {
                            tREG_MSG[ctrl][i].bfChanged = false;
    
                            /* Reset Counter and Flag */
                            tREG_MSG[ctrl][i].bfOnChangeTime = false;
                            tREG_MSG[ctrl][i].bfCycleTime = false;
                            tREG_MSG[ctrl][i].CounterOC = 0U;
                            tREG_MSG[ctrl][i].CounterCT = 0U;

                            Output_J1939 (ctrl,
                                          tREG_MSG[ctrl][i].Pgn, 
                                          tREG_MSG[ctrl][i].Priority, 
                                          tREG_MSG[ctrl][i].Length, 
                                          tREG_MSG[ctrl][i].pMsg_Old,
                                          J1939_Address[ctrl]);
                            
#ifdef DEBUG_J1939
                            printf ("<<< evPGN OC 0x%x \n", tREG_MSG[ctrl][i].Pgn);
#endif
                        }
                    } else if (tREG_MSG[ctrl][i].bfCycleTime == true) {
                        /* CycleTime event */
                        if (tREG_MSG[ctrl][i].pMsg == NULL) {
    	                    /* Fill all of NOT AVAILABLE */
                            memset(tREG_MSG[ctrl][i].pMsg_Old, 0xFFU, tREG_MSG[ctrl][i].Length);
                            tREG_MSG[ctrl][i].Function(); 
                        }
    
                        /* Reset Counter and Flag */
                        tREG_MSG[ctrl][i].bfOnChangeTime = false;
                        tREG_MSG[ctrl][i].bfCycleTime = false;
                        tREG_MSG[ctrl][i].CounterOC = 0U;
                        tREG_MSG[ctrl][i].CounterCT = 0U;
                   
      	                Output_J1939 (ctrl,
                                      tREG_MSG[ctrl][i].Pgn, 
                                      tREG_MSG[ctrl][i].Priority,
                                      tREG_MSG[ctrl][i].Length, 
                                      tREG_MSG[ctrl][i].pMsg_Old,
                                      J1939_Address[ctrl]);
#ifdef DEBUG_J1939
                        printf ("<<< evPGN CT 0x%x \n", tREG_MSG[ctrl][i].Pgn);
#endif
                    }
                }
            }
        }

        /***************************************
                  RECEIVER PROCESSOR
        ***************************************/
        while (true) {
            __disable_irq();

            if (J1939_CIR_BUF_COUNT(j1939_RX[ctrl])) {
                DequeueMessage_J1939 (ctrl, &tJ1939Msg);
                __enable_irq();

                if (ifAllFilter_J1939 (ctrl)) {
                    FunctionAllFilter_J1939 (ctrl, &tJ1939Msg);
                }

                /* Optional user can ask this parameter from the last Message recevied */
                __LastCTRLRcv_J1939 = ctrl;
                __LastMSGRcv_J1939  = tJ1939Msg;
                    
                /* 
                 * Process Protocol Data Unit Format (PDU Format = PF) 
                 */
                bMessageToProcess = false;
                switch ((tJ1939Msg.Pgn & 0x3FF00) >> 8)
                {
                    case J1939_PF_ADDRESS_CLAIM:
                    {
                        OnAddressClaim_J1939(ctrl, tJ1939Msg);
                        bMessageToProcess = true;   // allow to process callbacks registered with address claim pgn
                        break;
                    }
                    
                    case J1939_PF_REQUEST:
                    {
                        /* Process Claim Address */
                        if ((tJ1939Msg.Data[1] == J1939_PF_ADDRESS_CLAIM) &&
                            (tJ1939Msg.Data[0] == 0x00U)) {
                            OnRequestForAddressClaim_J1939 (ctrl);
                            //break; Commaneted to allow external functions to connect to address claim
                        }
                        /* Ignore other requests if cannot claim adddress */                        
                        if (J1939_Flags[ctrl].CannotClaimAddress) {
                            break;
                        }
                        
                        /* Process ONREQUEST */
                        for (i = 0; i < MAX_REG_MSG_J1939; i++) { 
                            if (tREG_MSG[ctrl][i].eType == ONREQUEST_EVENT) {
                                /* Check if is Registered */
                                if ((tJ1939Msg.Data[1] == (GET_PDUFORMAT (tREG_MSG[ctrl][i].Pgn) & 0xFF)) &&
                                    (tJ1939Msg.Data[2] == (GET_PDUFORMAT (tREG_MSG[ctrl][i].Pgn) >> 8))) {
#ifdef DEBUG_J1939
                                    Result = ((uint32_t)tJ1939Msg.Data[2]) << 16 |
                                             ((uint32_t)tJ1939Msg.Data[1]) << 8  |
                                             (uint32_t)tJ1939Msg.Data[0];                                            
                                    printf (">>> evONREQUEST 0x%x \n", Result);
#endif
                                    if ((tJ1939Msg.Data[1] < 240U) ||
                                        (tJ1939Msg.Data[0] == GET_PDUSPECIFIC (tREG_MSG[ctrl][i].Pgn))) {
                                        ControlByte = tREG_MSG[ctrl][i].FunctionA (tJ1939Msg.SourceAddress);

                                        /* if PDU 1 send the Address of the Requested ELSE PDU 2 */
                                        Result = (tJ1939Msg.Data[1] < 240U) ? tJ1939Msg.SourceAddress : GET_PDUSPECIFIC (tREG_MSG[ctrl][i].Pgn);
                                        if (ControlByte == POSITIVE_ACKM) {
                                            if (tREG_MSG[ctrl][i].pMsg != NULL) { // To avoid return code for request if undesired
                                                Output_J1939 (ctrl,
                                                              (tREG_MSG[ctrl][i].Pgn & 0x3FF00U) | Result,
                                                              tREG_MSG[ctrl][i].Priority,
                                                              tREG_MSG[ctrl][i].Length, 
                                                              tREG_MSG[ctrl][i].pMsg,
                                                              J1939_Address[ctrl]);
                                            }
                                        } else {
		                                    ACKM_CANMSG (ctrl,
                                                         ControlByte, 
                                                         (tREG_MSG[ctrl][i].Pgn & 0x3FF00U) | Result,
                                                         0xFFU,
		                                                 tJ1939Msg.SourceAddress);       
                                        }
                                        break;
                                    }
                                }                              
                            }
                        }

                        if (i == MAX_REG_MSG_J1939) {
                            /* PGN Requested is NOT SUPPORTED we have to send NACK */
                            /* if DA != GLOBAL we send NACK */
                            if (GET_PDUSPECIFIC(tJ1939Msg.Pgn) != J1939_ADDRESS_GLOBAL) {
                                ACKM_CANMSG (ctrl,
                                             NEGATIVE_ACKM,
                                             ((((uint32_t)tJ1939Msg.Data[2]) << 16) | 
                                              (((uint32_t)tJ1939Msg.Data[1]) << 8)  | 
                                              tJ1939Msg.Data[0]),
                                             0xFFU,
                                             tJ1939Msg.SourceAddress);
                            }
                        }
                    } break;

                    case J1939_PF_ACKNOWLEDGMENT:
                    {
                        /* Ignore message if cannot claim adddress */                        
                        if (J1939_Flags[ctrl].CannotClaimAddress) {
                            break;
                        }
                        /* Process REQUEST (NACKED) or COMMAND (NACKED/ACKED) */
                        for (i = 0U; i < MAX_REG_MSG_J1939; i++) {
                            if ((tREG_MSG[ctrl][i].eType == REQUEST_EVENT) ||
                                (tREG_MSG[ctrl][i].eType == COMMAND_EVENT)) {
                                if ((tJ1939Msg.Data[5] == GET_PDUSPECIFIC (tREG_MSG[ctrl][i].Pgn)) &&
                                    (tJ1939Msg.Data[6] == (GET_PDUFORMAT (tREG_MSG[ctrl][i].Pgn) & 0xFFU)) &&
                                    (tJ1939Msg.Data[7] == (GET_PDUFORMAT (tREG_MSG[ctrl][i].Pgn) >> 8))) {
                                    /* Call REQUEST that were NACKED or COMMAND that were ACKED/NACKED */
                                    if (tREG_MSG[ctrl][i].FunctionAC != NULL) {  
                                        tREG_MSG[ctrl][i].FunctionAC (tJ1939Msg.SourceAddress, tJ1939Msg.Data[0]);
                                    }
                                    /* UNregister it */
                                    tREG_MSG[ctrl][i].Pgn = NONE_EVENT;                               
                                    break;
                                }
                            }
                        }
                    } break;
#ifdef J1939_TRANSPORT_PROTOCOL     
                    case J1939_PF_TPCM:
                    {
                        Result = ((uint32_t)tJ1939Msg.Data[7] << 16 | 
                                  (uint32_t)tJ1939Msg.Data[6] << 8  | 
                                  (uint32_t)tJ1939Msg.Data[5]);
#ifdef DEBUG_J1939_TP
                        printf (">TPCM ");
#endif
                        for (i = 0; i < MAX_TRANSPORT_PROTOCOL_J1939; i++) {
                            /* Compare Pgn */
                            if ((tTP[ctrl][i].Pgn == Result) &&
                                (tTP[ctrl][i].TotalMessageSize != 0U)) {  

                                switch (tJ1939Msg.Data[0])
                                {
                                    /* BAM control */
                                    case BAM_TPCM:
#ifdef DEBUG_J1939_TP
                                        printf ("BAM ");
#endif
                                        if (tTP[ctrl][i].Flag.bfResponder) {                                        
                                            tTP[ctrl][i].Flag.bfBAM = true;
                                        }
                                
                                    /* Request To Send */
                                    case RTS_TPCM:           
#ifdef DEBUG_J1939_TP
                                        printf ("RTS ");
#endif
                                        if (tTP[ctrl][i].Flag.bfResponder) {                                   
                                            /* Save Source Address */
                                            tTP[ctrl][i].DestinationAddress = tJ1939Msg.SourceAddress;
                
                                            /* Total Message Size in Bytes */
                                            tTP[ctrl][i].TotalMessageSize = (((uint32_t)tJ1939Msg.Data[2] << 8) |
                                                                              (uint32_t)tJ1939Msg.Data[1]);  

                                            /* Total Number of Packets */
                                            tTP[ctrl][i].TotalNumberOfPackets = tJ1939Msg.Data[3];

                                            /* Originator Max Packet - 0xFF = No Limit */
                                            tTP[ctrl][i].MaximumNumberOfPackets = tJ1939Msg.Data[4];
              
                                            /* Limit transfer for each CTS to Originator MAX */
                                            if (tTP[ctrl][i].MaximumNumberOfPackets < tTP[ctrl][i].NumberOfPacketsCanSent) {
                                                tTP[ctrl][i].NumberOfPacketsCanSent = (uint8_t)tTP[ctrl][i].MaximumNumberOfPackets;
                                            }
             
                                            /* Ini Vars */
                                            tTP[ctrl][i].MessageSize              = 0U;
                                            tTP[ctrl][i].NumberOfPackets          = 0U;
                                            tTP[ctrl][i].NextPacketNumberToBeSent = 1U;

                                            /* State: RTS */
                                            if (tTP[ctrl][i].Flag.bfBAM) {                                       
                                                TP_Set_SM_J1939 (&tTP[ctrl][i], BAM_R_SM_J1939);                  
                                            } else {
                                                TP_Set_SM_J1939 (&tTP[ctrl][i], RTS_R_SM_J1939);                  
                                            }
                                        }
                                        break;
                        
                                    /* Clear to Send */
                                    case CTS_TPCM:
#ifdef DEBUG_J1939_TP
                                        printf ("CTS ");
#endif
                                        if ((tTP[ctrl][i].DestinationAddress == tJ1939Msg.SourceAddress) &&
                                            (tTP[ctrl][i].Flag.bfOriginator)) { 
                                            /* Number of Packet Can Sent for each CTS */
                                            if (tTP[ctrl][i].MaximumNumberOfPackets >= tJ1939Msg.Data[1]) {
                                                tTP[ctrl][i].NumberOfPacketsCanSent = tJ1939Msg.Data[1];
                                            } else {
                                                tTP[ctrl][i].NumberOfPacketsCanSent = (uint8_t)tTP[ctrl][i].MaximumNumberOfPackets; 
                                            }

                                            /* Next Packet Sequence Number */
                                            tTP[ctrl][i].NextPacketNumberToBeSent = tJ1939Msg.Data[2];  
                
                                            /* State: CTS */
                                            TP_Set_SM_J1939 (&tTP[ctrl][i], CTS_O_SM_J1939);                  
                                        }
                                        break;
                        
                                    /* End of Message */
                                    case EOMACK_TPCM:
#ifdef DEBUG_J1939_TP
                                        printf ("EOMACK ");
#endif
                                        if ((tTP[ctrl][i].DestinationAddress == tJ1939Msg.SourceAddress) &&
                                            (tTP[ctrl][i].Flag.bfOriginator)) { 
                                            /* Total Bytes Transfer */
                                            tTP[ctrl][i].TotalMessageSize = ((uint16_t)tJ1939Msg.Data[2] << 8) | tJ1939Msg.Data[1];
                                
                                            /* State: EOMACK */
                                            TP_Set_SM_J1939 (&tTP[ctrl][i], EOMACK_O_SM_J1939);                                                              
                                        }
                                        break;
                        
                                    /* Connection Abort */
                                    case CONN_ABORT_TPCM:
#ifdef DEBUG_J1939_TP
                                        printf ("ABORT ");
#endif
                                        if ((tTP[ctrl][i].Flag.bfOriginator) &&
                                            (tTP[ctrl][i].DestinationAddress == tJ1939Msg.SourceAddress)) {
                                             tTP[ctrl][i].pfABORT();
                                        }
                                        break;
                                      
                                    default:
#ifdef DEBUG_J1939_TP
                                        printf ("UNKNOWN ");
#endif
                                        break;
                        
                                }
                            }
                        }
#ifdef DEBUG_J1939_TP
                        printf ("0x%x\n", Result);
#endif

                    } break;

                    case J1939_PF_TPDT:
                    {
                        for (i = 0; i < MAX_TRANSPORT_PROTOCOL_J1939; i++) {
                            /* Determine if there a Valid Connection */
                            if ((TP_Get_SM_J1939 (&tTP[ctrl][i]) != IDLE_R_SM_J1939)) {
                                if ((tTP[ctrl][i].DestinationAddress == tJ1939Msg.SourceAddress) &&
                                    (tTP[ctrl][i].Flag.bfResponder)) {                
#ifdef DEBUG_J1939_TP
                                    printf (">TPDT %02d\n", tJ1939Msg.Data[0]);
#endif
                                    /* State: DT */
                                    TP_SetData_SM_J1939 (&tTP[ctrl][i], tJ1939Msg.Data);
                                    if (tTP[ctrl][i].Flag.bfMessageReceived == true) {
                                        tTP[ctrl][i].Flag.bfMessageReceived = false;
                                        bMessageToProcess = true;
                                        tJ1939Msg.Pgn    = tTP[ctrl][i].Pgn;
                                        tJ1939Msg.Length = tTP[ctrl][i].TotalMessageSize;
                                        break;
                                    }
                                }
                            }
                        }
                    } break;
#endif    
#ifdef J1939_DIAGNOSTIC_MEMORY
                    case J1939_PF_DM14:
                    {
                        /* Ignore message if cannot claim adddress */                        
                        if (J1939_Flags[ctrl].CannotClaimAddress) {
                            break;
                        }
                        ControlByte = (tJ1939Msg.Data.Byte[1] >> 1) & 0x07;
                        Address     = tJ1939Msg.Data.Byte[5] << 24;
                        Address    |= tJ1939Msg.Data.Byte[4] << 16;
                        Address    |= tJ1939Msg.Data.Byte[3] << 8;
                        Address    |= tJ1939Msg.Data.Byte[2];
                        Size        = tJ1939Msg.Data.Byte[0];
                        Size       |= ((U32)tJ1939Msg.Data.Byte[1] << 3);               
            
                        switch (ControlByte)
                        {
                            case CMD_ERASE_DM14:
                                Ini_BLR (tJ1939Msg.SourceAddress, Address, Size);
                                Set_State_BLR (ERASE_BL); 
                                break;
            
                            case CMD_READ_DM14:
                                Ini_BLR (tJ1939Msg.SourceAddress, Address, Size);
                                Set_State_BLR (READ_BL);
                                break;

                            case CMD_WRITE_DM14: 
                                Ini_BLR (tJ1939Msg.SourceAddress, Address, Size);
                                Set_State_BLR (WRITE_BL);
                                break;
            
                            case CMD_OPERATION_COMPLETED_DM14:
                                Set_State_BLR (COMPLETED_BL);
                                break;

                            default:
                                break;
                        }
                    } break;      

                    case J1939_PF_DM15:
                    {
                        /* Ignore message if cannot claim adddress */                        
                        if (J1939_Flags[ctrl].CannotClaimAddress) {
                            break;
                        }
                        ControlByte = (tJ1939Msg.Data.Byte[1] >> 1) & 0x07;
                        Size        = tJ1939Msg.Data.Byte[0];
                        Size       |= ((U32)tJ1939Msg.Data.Byte[1] << 3);               
          
                        switch (ControlByte)
                        {
                            case STATUS_PROCEED_DM15:
                                Set_State_BLO (PROCEED_BL);
                                break;
            
                            case STATUS_BUSY_DM15:
                                break;

                            case STATUS_OPERATION_COMPLETED_DM15: 
                                Set_State_BLO (COMPLETED_BL); 
                                break;
            
                            case STATUS_OPERATION_FAILED_DM15:
                                break;

                            default:
                                break;
                        }
                    } break;      

                    case J1939_PF_DM16:
                    {
                        /* Ignore message if cannot claim adddress */                        
                        if (J1939_Flags[ctrl].CannotClaimAddress) {
                            break;
                        }
                        while (tTP[ctrl][i].TotalMessageSize != 0U) {
                            if (tTP[ctrl][i].Pgn == PGN_DM16) {
                                for (j = 0U; i < tJ1939Msg.Data.Byte[0]; i++) {
                                    tTP[ctrl][i].Data[j] = tJ1939Msg.Data.Byte[j + 1];
                                }
                                WriteEOMACK_BLR(); 
                                break;            
                            }

                            /* Check */
                            assert (i >= MAX_TRANSPORT_PROTOCOL_J1939);
                            i++;
                        }
                    } break;
#endif
                    default:
                    {
                        bMessageToProcess = true;
                    } break;
                }
                
                /* Ignore all messages but commanded address if cannot claim adddress */                        
                if (J1939_Flags[ctrl].CannotClaimAddress && tJ1939Msg.Pgn != PGN_COMMANDED_ADDRESS) {
                    bMessageToProcess = false;
                }

                /* Process ONPGN, ONCOMMAND, REQUEST */
                if (bMessageToProcess == true) {
                    bMessageToProcess = false;
                    for (i = 0; i < MAX_REG_MSG_J1939; i++) { 
                        /* Check if is Registered */
                        if (GET_PDUFORMAT (tREG_MSG[ctrl][i].Pgn) == GET_PDUFORMAT (tJ1939Msg.Pgn)) {
                            if (IF_PDU1 (tJ1939Msg.Pgn) ||  
                                (GET_PDUSPECIFIC (tREG_MSG[ctrl][i].Pgn) == GET_PDUSPECIFIC (tJ1939Msg.Pgn))) {
                                if (tJ1939Msg.Length <= 8) {
                                    /* REQUEST has pMsg == NULL! */
                                    if ((tREG_MSG[ctrl][i].pMsg != NULL) && (tREG_MSG[ctrl][i].eType != ONREQUEST_EVENT)) {
#ifdef J1939_FAST_PACKET_PROTOCOL
                                        if (tREG_MSG[ctrl][i].bfFastPacket == false) {
#endif
                                            memcpy (tREG_MSG[ctrl][i].pMsg, tJ1939Msg.Data, tJ1939Msg.Length);
#ifdef J1939_FAST_PACKET_PROTOCOL
                                        }
#endif
                                    }
                                }

                                switch (tREG_MSG[ctrl][i].eType) 
                                {
                                    case REQUEST_EVENT:
                                        /* Reset Entry and Timeout Counter */
#ifdef DEBUG_J1939
                                        printf (">>> evREQUEST 0x%x \n", tJ1939Msg.Pgn);
#endif
                                        tREG_MSG[ctrl][i].eType = NONE_EVENT;
                                        tREG_MSG[ctrl][i].CounterTimeOut = 0U;
                                        if (tREG_MSG[ctrl][i].FunctionAC != NULL) {   
                                            tREG_MSG[ctrl][i].FunctionAC (tJ1939Msg.SourceAddress, POSITIVE_ACKM);
                                        }
                                        break;

                                    case ONPGN_EVENT:
                                        /* Reset Timeout Counter */
#ifdef DEBUG_J1939
                                        printf (">>> evONPGN 0x%x \n", tJ1939Msg.Pgn);
#endif
                                        /* We have received a 8 Bytes message */
#ifdef J1939_FAST_PACKET_PROTOCOL
                                        if (tREG_MSG[ctrl][i].bfFastPacket == false) {
#endif
                                            tREG_MSG[ctrl][i].CounterTimeOut = 0U;
                                            if (tREG_MSG[ctrl][i].FunctionA != NULL) {   
                                                tREG_MSG[ctrl][i].FunctionA (tJ1939Msg.SourceAddress);
                                            }
#ifdef J1939_FAST_PACKET_PROTOCOL
                                        } else {
                                            /* We have a Fast Packet message */
                                            /* Find Start of Fast-Packet */
                                            if ((tREG_MSG[ctrl][i].Frame == 0xFFU) && 
                                                ((tJ1939Msg.Data[0] & 0x1FU) == 0U)) {
                                                tREG_MSG[ctrl][i].Length = tJ1939Msg.Data[1];
                                                tREG_MSG[ctrl][i].Frame = tJ1939Msg.Data[0];
                                                memcpy (tREG_MSG[ctrl][i].pMsg, &tJ1939Msg.Data[2], 6U);
                                                tREG_MSG[ctrl][i].CounterByte = 6U;
                                                tREG_MSG[ctrl][i].Frame++;
                                            } else {
                                                /* Check each Frame Sequence */
                                                if (tREG_MSG[ctrl][i].Frame == tJ1939Msg.Data[0]) {
                                                    Result = tREG_MSG[ctrl][i].Length - tREG_MSG[ctrl][i].CounterByte;
                                                    if (Result > 7U) {
                                                        Result = 7U;
                                                    }
                                                    memcpy ((((uint8_t*)tREG_MSG[ctrl][i].pMsg) + tREG_MSG[ctrl][i].CounterByte), &tJ1939Msg.Data[1], Result);
                                                    tREG_MSG[ctrl][i].CounterByte += 7U;
                                                    tREG_MSG[ctrl][i].Frame++;
                                                    if (tREG_MSG[ctrl][i].CounterByte >= tREG_MSG[ctrl][i].Length) {
                                                        /* End Packet */
                                                        tREG_MSG[ctrl][i].CounterByte = 0U;
                                                        tREG_MSG[ctrl][i].Frame = 0xFFU;
                                                        tREG_MSG[ctrl][i].CounterTimeOut = 0U;
                                                        if (tREG_MSG[ctrl][i].FunctionA != NULL) {   
                                                            tREG_MSG[ctrl][i].FunctionA (tJ1939Msg.SourceAddress);
                                                        }                                                        
                                                    }
                                                } else {
                                                    /* Error Frame Sequence */    
                                                    tREG_MSG[ctrl][i].Frame = 0xFFU;
                                                }
                                            }   
                                        }
#endif
                                        break;

                                    case ONCOMMAND_EVENT:
#ifdef DEBUG_J1939
                                        printf (">>> evONCOMMAND 0x%x \n", tJ1939Msg.Pgn);
#endif
                                        Result = tREG_MSG[ctrl][i].FunctionA (tJ1939Msg.SourceAddress);                      
                                        ACKM_CANMSG (ctrl,
                                                     Result, 
                                                     tREG_MSG[ctrl][i].Pgn,
                                                     0xFFU,
                                                     tJ1939Msg.SourceAddress);             
                                        break;
                                    default:
                                    {
                                    } break;
                                }
                            }
                        }
                    }         
                }

            } else {
                __enable_irq();      
                break;
            }
        }
    }
}

/*
 * get CAN Ctrl number where the last Message was Received
 */
uint32_t getCTRLRcv_J1939 (void)
{
    return __LastCTRLRcv_J1939;
}

/*
 * get complete structure last Message Received
 */
J1939_MESSAGE_T* getMSGRcv_J1939 (void)
{
    return &__LastMSGRcv_J1939;
}

/* End of $Workfile: Processor_J1939.c$ */

