/*******************************************************************************
** $Revision: 4$
** $Date: 16/12/2013 07:30:39 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

/* Include ********************************************************************/
#include <string.h>
#include <stdio.h>
#include "j1939.h"
#include "canmsg/TPDT_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t TPDT_CANMSG (uint32_t ctrl,
                     uint32_t DestinationAddress, 
                     uint32_t SequenceNumber, 
                     uint8_t* pByte)
{
    int32_t             result;
    TPDT_T              tTPDT;
#ifdef DEBUG_J1939_TP
    int32_t             i;
#endif
    result = RC_SUCCESS;

    /* Fill Data members */
    tTPDT.SequenceNumber = (uint8_t)SequenceNumber;
    memcpy (tTPDT.Byte, pByte, 7U);

#ifdef DEBUG_J1939_TP
    printf ("<TPDT: %d, ", SequenceNumber); 
    for (i = 0; i < 7; i++) {
        printf ("%02x ", tTPDT.Byte[i]);
    }
    printf ("\n");
#endif         
    /* Send the Message */
    result = Output_J1939 (ctrl,
                           (PGN_TPDT | DestinationAddress), 
                           J1939_INFO_PRIORITY, 
                           SIZE_TPDT, 
                           &tTPDT,
                           J1939_Address[ctrl]);

    return result;
}

/* End of $Workfile: TPDT_canmsg.c$ */
