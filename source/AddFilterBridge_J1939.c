/*******************************************************************************
** $Revision: 1$
** $Date: 04/02/2014 11:46:17 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
#ifdef J1939_BRIDGE
void InitializeFilterBridge_J1939(uint32_t ctrl)
{
    uint32_t            i;
    
    for (i = 0; i < MAX_FILTERGW_J1939; i++) {
        tFILTERGW[ctrl][i].Pgn = PGN_INVALID;
    }
}

int32_t AddFilterBridge_J1939 (uint32_t ctrl, uint32_t Pgn) 
{
    uint32_t            i;
    int32_t             result;

    result = RC_ERROR;

    for (i = 0; i < MAX_FILTERGW_J1939; i++) {
        if (tFILTERGW[ctrl][i].Pgn == Pgn) {
            result = RC_SUCCESS;
            break;
        }
        if (tFILTERGW[ctrl][i].Pgn == PGN_INVALID) {
            tFILTERGW[ctrl][i].Pgn = Pgn;
            result = RC_SUCCESS;
            break;
        }
    }

    return result;
}
#endif

/* End of $Workfile: AddFilterBridge_J1939.c$ */

