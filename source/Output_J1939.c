/*******************************************************************************
** $Revision: 5$
** $Date: 15/10/2014 03:12:12 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include <string.h>
#include "j1939.h"
#include "N2K_GPD_canmsg.h"
#include "SAGSM_canmsg.h"
#include "SAGPS_canmsg.h"
#include "SFT_canmsg.h"
#include "DBC_canmsg.h"

/* Defines ********************************************************************/
#define MAX_BLOCKED_PGNS  10
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static BlockOutputJ1939_T       blockedPgns[MAX_BLOCKED_PGNS];

/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t Output_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t Priority, 
                      uint32_t DataLength, void* pMsg, uint8_t SourceAddress)
{
    J1939_MESSAGE_T     tJ1939Msg;
#ifdef J1939_FAST_PACKET_PROTOCOL
    int32_t             Result;
    uint8_t*            pSrc;
    uint8_t             Frame;
    uint8_t             BytesLeft;
    uint8_t             Bytes2Copy;
    uint32_t            i;
#endif

    tJ1939Msg.Priority      = (uint8_t)Priority;
    tJ1939Msg.Pgn           = Pgn;
    tJ1939Msg.SourceAddress = SourceAddress;
    tJ1939Msg.Length        = DataLength;
    tJ1939Msg.pData         = pMsg;

#ifdef J1939_FAST_PACKET_PROTOCOL    
    if ((Pgn == PGN_N2K_GPS_POSITION_DATA) ||
        (Pgn == PGN_SMARTANTENNA_GSM) ||
        (Pgn == PGN_SMARTANTENNA_GPS) ||
        (Pgn == PGN_STRING_FP_TRANSPORT) ||
		(Pgn == PGN_DYNAMIC_BEZIER_CONTROL)) {        
        for (i = 0; i < MAX_REG_MSG_J1939; i++) {
            if ((tREG_MSG[ctrl][i].eType == PGN_EVENT) &&
                (tREG_MSG[ctrl][i].Pgn == Pgn) &&
                (tREG_MSG[ctrl][i].bfFastPacket == true)) {
                Result = RC_ERROR;
                Frame = tREG_MSG[ctrl][i].Frame;
                BytesLeft = tJ1939Msg.Length - 6U;
                /* Send Data = Fast-Packet */
                tJ1939Msg.Data[0] = Frame++;
                tJ1939Msg.Data[1] = tJ1939Msg.Length;
                pSrc = tJ1939Msg.pData;
                memcpy (&tJ1939Msg.Data[2], pSrc, 6U);
                tJ1939Msg.Length = 8U;
                Result |= EnqueueMessage_J1939 (ctrl, &tJ1939Msg);
                pSrc += 6U;
                
                do {
                    tJ1939Msg.Data[0] = Frame++;
                    memset (&tJ1939Msg.Data[1], 0xFFU, 7U);
                    Bytes2Copy = (BytesLeft < 7U) ? BytesLeft : 7U;
                    memcpy (&tJ1939Msg.Data[1], pSrc, Bytes2Copy);
                    pSrc += Bytes2Copy;
                    BytesLeft -= Bytes2Copy;
                    tJ1939Msg.Length = Bytes2Copy +1;
                    Result |= EnqueueMessage_J1939 (ctrl, &tJ1939Msg);
                } while (BytesLeft);
                
                /* Get ready the next frame (multiple of 0x20) */
                tREG_MSG[ctrl][i].Frame += 0x20U;
                return Result;
            }
        }
    }         
#endif           
    if (DataLength <= 8) {
        /* Send Data = 8 Bytes */
        memcpy (tJ1939Msg.Data, pMsg, tJ1939Msg.Length);
    }        
      
    /* Send Data = 8 Bytes or Multi-Packet */        
    return (EnqueueMessage_J1939 (ctrl, &tJ1939Msg));
}

int32_t Block_Output_J1939 (uint32_t ctrl, uint32_t Pgn)
{
  uint8_t   index;
  int32_t   result = RC_ERROR;  
  
  for(index = 0; index < MAX_BLOCKED_PGNS; index++) {
    if(blockedPgns[index].Pgn == 0xFFFF) {
      blockedPgns[index].Ctrl = ctrl;
      blockedPgns[index].Pgn = Pgn;
      
      result = RC_SUCCESS;
      break;
    }
  }
  
  return result;  
}

int32_t Clear_Output_J1939 (uint32_t ctrl, uint32_t Pgn)
{
  uint32_t            index;
  int32_t             result;  

  for(index = 0; index < MAX_BLOCKED_PGNS; index++) {
    if(blockedPgns[index].Pgn == Pgn) {
      blockedPgns[index].Pgn = 0xFFFF;
      
      result = RC_SUCCESS;
      break;
    }
  }
    
  return result;  
}

int32_t Init_Output_J1939(void)
{
  uint32_t            index;
  int32_t             result = RC_SUCCESS; 
  
  for(index = 0; index < MAX_BLOCKED_PGNS; index++) {
    blockedPgns[index].Pgn = 0xFFFF;
  }
  
  return result;
}


/* End of $Workfile: Output_J1939.c$ */

