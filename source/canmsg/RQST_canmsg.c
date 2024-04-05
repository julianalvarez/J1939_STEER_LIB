
/* Include ********************************************************************/
#include <stdio.h>
#include "j1939.h"
#include "canmsg/RQST_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
/*
 * Request message
 * Note: Per user requirements, generally recommended that requests occur
 *       no more than 2 or 3 times per second.
 */
int32_t RQST_CANMSG (uint32_t ctrl, uint32_t Pgn, uint32_t DestinationAddress)
{
    int32_t             result;
    RQST_T              tRQST;

    result = RC_SUCCESS;

    /* Fill Data members */
    tRQST.Pgn  = (uint16_t)(Pgn & 0xFFFFU);
    tRQST.Pgn1 = (uint8_t)((Pgn & 0x30000U) >> 16);

#ifdef DEBUG_J1939
    printf ("<RQST: Pgn: 0x%x\n", Pgn); 
#endif         
                              
    /* Send the Message */
    result = Output_J1939 (ctrl,
                          (PGN_REQUEST | DestinationAddress), 
                          J1939_REQUEST_PRIORITY, 
                          SIZE_REQUEST, 
                          &tRQST,
                          J1939_Address[ctrl]);

    return (result);
}

/* End of $Workfile: RQST_canmsg.c$ */
