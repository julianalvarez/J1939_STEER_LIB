/*******************************************************************************
** $Revision: 4$
** $Date: 16/12/2013 07:30:39 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

/* Include ********************************************************************/
#include <stdio.h>
#include "j1939.h"
#include "TPCM_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t TPCM_RTS_CANMSG (uint32_t ctrl,
                         uint32_t Pgn,
                         uint32_t DestinationAddress, 
                         uint32_t TotalMessageSize,
                         uint32_t TotalNumberOfPackets,
                         uint32_t MaximumNumberOfPackets)
{
    int32_t             result;
    TPCM_U              tTPCM;

    result = RC_SUCCESS;
    
    /* Fill Data members */
    tTPCM.RTS.ControlByte            = RTS_TPCM;
    tTPCM.RTS.TotalMessageSize       = (uint16_t)TotalMessageSize;
    tTPCM.RTS.TotalNumberOfPackets   = (uint8_t)TotalNumberOfPackets;
    tTPCM.RTS.MaximumNumberOfPackets = (uint8_t)MaximumNumberOfPackets;
    tTPCM.RTS.Pgn                    = (uint16_t)(Pgn & 0xFFFFU);
    tTPCM.RTS.Pgn1                   = ((uint8_t)(Pgn & 0x30000U) >> 16);

#ifdef DEBUG_J1939_TP
    printf ("<TPCM: RTS, Pgn: 0x%x, Size: %d, Packets: %d, MaxPackets: %d\n", 
            Pgn, TotalMessageSize, TotalNumberOfPackets, MaximumNumberOfPackets); 
#endif         
    
    /* Send the Message */
    result = Output_J1939 (ctrl,
                           (PGN_TPCM | DestinationAddress), 
                           J1939_INFO_PRIORITY, 
                           SIZE_TPCM, 
                           &tTPCM,
                           J1939_Address[ctrl]);
    
    return result;
}

/*******************************************************************************
 *    Function Name:  .
 *    Parameters:     .
 *    Return Value:   .
 *
 *    Description:    .
 *
 *    Notes:          .
 ******************************************************************************/
int32_t TPCM_CTS_CANMSG (uint32_t ctrl,
                         uint32_t Pgn,
                         uint32_t DestinationAddress, 
                         uint32_t NumberOfPacketsCanSent,
                         uint32_t NextPacketNumberToBeSent)
{
    int32_t             result;  
    TPCM_U              tTPCM;
    
    /* Fill Data members */
    tTPCM.CTS.ControlByte              = CTS_TPCM;
    tTPCM.CTS.NumberOfPacketsCanSent   = (uint8_t)NumberOfPacketsCanSent;
    tTPCM.CTS.NextPacketNumberToBeSent = (uint8_t)NextPacketNumberToBeSent;
    tTPCM.CTS.Rvd                      = 0xFFFFU;
    tTPCM.CTS.Pgn                      = (uint16_t)(Pgn & 0xFFFFU);
    tTPCM.CTS.Pgn1                     = (uint8_t)((Pgn & 0x30000U) >> 16);

#ifdef DEBUG_J1939_TP
    printf ("<TPCM: CTS, Pgn: 0x%x, NumberPacketCanSent: %d, NextPacket: %d\n", 
            Pgn, NumberOfPacketsCanSent, NextPacketNumberToBeSent); 
#endif         
    
    /* Send the Message */
    result = Output_J1939 (ctrl,
                           (PGN_TPCM | DestinationAddress), 
                           J1939_INFO_PRIORITY, 
                           SIZE_TPCM, 
                           &tTPCM,
                           J1939_Address[ctrl]);
    
    return result;
}

/*******************************************************************************
 *    Function Name:  .
 *    Parameters:     .
 *    Return Value:   .
 *
 *    Description:    .
 *
 *    Notes:          .
 ******************************************************************************/
int32_t TPCM_EOMACK_CANMSG (uint32_t ctrl,
                            uint32_t Pgn,
                            uint32_t DestinationAddress, 
                            uint32_t TotalMessageSize,
                            uint32_t TotalNumberOfPackets)
{
    int32_t             result;
    TPCM_U              tTPCM;

    /* Fill Data members */
    tTPCM.EOMACK.ControlByte          = EOMACK_TPCM;
    tTPCM.EOMACK.TotalMessageSize     = (uint16_t)TotalMessageSize;
    tTPCM.EOMACK.TotalNumberOfPackets = (uint8_t)TotalNumberOfPackets;
    tTPCM.EOMACK.Rvd                  = 0xFFU;
    tTPCM.EOMACK.Pgn                  = (uint16_t)(Pgn & 0xFFFFU);
    tTPCM.EOMACK.Pgn1                 = (uint8_t)((Pgn & 0x30000U) >> 16);

#ifdef DEBUG_J1939_TP
    printf ("<TPCM: EOMACK, Pgn: 0x%x, Size: %d, Packets: %d\n", 
            Pgn, TotalMessageSize, TotalNumberOfPackets); 
#endif         


    /* Send the Message */
    result = Output_J1939 (ctrl,
                         (PGN_TPCM | DestinationAddress), 
                         J1939_INFO_PRIORITY, 
                         SIZE_TPCM, 
                         &tTPCM,
                         J1939_Address[ctrl]);

    return result;
}

/*******************************************************************************
 *    Function Name:  .
 *    Parameters:     .
 *    Return Value:   .
 *
 *    Description:    .
 *
 *    Notes:          .
 ******************************************************************************/
int32_t TPCM_BAM_CANMSG (uint32_t ctrl,
                         uint32_t Pgn,
                         uint32_t DestinationAddress, 
                         uint32_t TotalMessageSize,
                         uint32_t TotalNumberOfPackets)
{
    int32_t             result;
    TPCM_U              tTPCM;

    /* Fill Data members */
    tTPCM.BAM.ControlByte          = BAM_TPCM;
    tTPCM.BAM.TotalMessageSize     = (uint16_t)TotalMessageSize;
    tTPCM.BAM.TotalNumberOfPackets = (uint8_t)TotalNumberOfPackets;
    tTPCM.BAM.Rvd                  = 0xFFU;
    tTPCM.BAM.Pgn                  = (uint16_t)(Pgn & 0xFFFFU);
    tTPCM.BAM.Pgn1                 = (uint8_t)((Pgn & 0x30000U) >> 16);

#ifdef DEBUG_J1939_TP
    printf ("<TPCM: BAM, Pgn: 0x%x, Size: %d, Packets: %d\n", 
            Pgn, TotalMessageSize, TotalNumberOfPackets); 
#endif         
    
    /* Send the Message */
    result = Output_J1939 (ctrl,
                         (PGN_TPCM | DestinationAddress), 
                         J1939_INFO_PRIORITY, 
                         SIZE_TPCM, 
                         &tTPCM,
                         J1939_Address[ctrl]);

  return result;
}

/*******************************************************************************
 *    Function Name:  .
 *    Parameters:     .
 *    Return Value:   .
 *
 *    Description:    .
 *
 *    Notes:          .
 ******************************************************************************/
int32_t TPCM_ABORT_CANMSG (uint32_t ctrl,
                           uint32_t Pgn,
                           uint32_t DestinationAddress, 
                           uint32_t ConnectionAbortReason)
{
    int32_t             result;
    TPCM_U              tTPCM;

    /* Fill Data members */
    tTPCM.CONNABORT.ControlByte           = CONN_ABORT_TPCM;
    tTPCM.CONNABORT.ConnectionAbortReason = (uint8_t)ConnectionAbortReason;
    tTPCM.CONNABORT.Rvd                   = 0xFFFFU;
    tTPCM.CONNABORT.Rvd1                  = 0xFFU;
    tTPCM.CONNABORT.Pgn                   = (uint16_t)(Pgn & 0xFFFFU);
    tTPCM.CONNABORT.Pgn1                  = (uint8_t)((Pgn & 0x30000U) >> 16);

#ifdef DEBUG_J1939_TP
    printf ("<TPCM: ABORT, Pgn: 0x%x, Reason: %d\n", 
            Pgn, ConnectionAbortReason); 
#endif         

    /* Send the Message */
    result = Output_J1939 (ctrl,
                           (PGN_TPCM | DestinationAddress), 
                           J1939_INFO_PRIORITY, 
                           SIZE_TPCM, 
                           &tTPCM,
                           J1939_Address[ctrl]);
    
    return result;
}

/* End of $Workfile: TPCM_canmsg.c$ */
