/*******************************************************************************
** $Revision: 5$
** $Date: 16/12/2013 07:30:39 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include <stdio.h>
#include "j1939.h"
#include "ACKM_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t ACKM_CANMSG (uint32_t ctrl, uint32_t ControlByte, uint32_t Pgn, 
                     uint32_t GroupFunction, uint32_t DestinationAddress)
{
    uint32_t            tmp;
    int32_t             result;
    ACKM_T              tACKM;

    result = RC_SUCCESS;

    /* Fill Data members */
    tACKM.ControlByte        = (uint8_t)ControlByte;
    tACKM.GroupFunctionValue = (uint8_t)GroupFunction;
    tACKM.Rvd                = J1939SIG_NA_U16;
    tACKM.Rvd1               = J1939SIG_NA_U8;
    tACKM.Pgn                = (uint16_t)(Pgn & 0xFFFFU);
    tACKM.Pgn1               = (uint8_t)((Pgn & 0x30000U) >> 16);

    /* if PDU1 send Lower part of Pgn, if PDU2 send Global Address */
    tmp = IF_PDU1(Pgn) ? DestinationAddress : 0xFFU;

#ifdef DEBUG_J1939
    switch (ControlByte) {
        case POSITIVE_ACKM:
            printf ("<ACKM: POSITIVE, Pgn: 0x%x, GroupF: %d\n", 
                    Pgn, GroupFunction); 
            break;        
        case NEGATIVE_ACKM:
            printf ("<ACKM: NEGATIVE, Pgn: 0x%x, GroupF: %d\n", 
                    Pgn, GroupFunction); 
            break;                
        case ACCESS_DENIED_ACKM:
            printf ("<ACKM: ACCESS DENIED, Pgn: 0x%x, GroupF: %d\n", 
                    Pgn, GroupFunction); 
            break;        
        case CANNOT_RESPOND_ACKM:
            printf ("<ACKM: CANNOT RESPOND, Pgn: 0x%x, GroupF: %d\n", 
                    Pgn, GroupFunction); 
            break;        
        
        default:
            printf ("<ACKM: UNKNOWN, Pgn: 0x%x, GroupF: %d\n", 
                    Pgn, GroupFunction); 
            break;
    }
#endif

    /* Send the Message */
    result = Output_J1939 (ctrl, 
                           (PGN_ACKNOWLEDGMENT | tmp), 
                           J1939_ACK_PRIORITY, 
                           SIZE_ACKNOWLEDGMENT, 
                           &tACKM,
                           J1939_Address[ctrl]);

    return (result);
}

/* End of $Workfile: ACKM_canmsg.c$ */
