/*******************************************************************************
** $Revision: 3$
** $Date: 02/09/2010 04:18:54 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static bool             __enable_all_filter[MAX_PORT_J1939];

/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
void InitializeFilter_J1939(uint32_t ctrl)
{
    uint32_t            i;
    
    for (i = 0; i < MAX_FILTER_J1939; i++) {
        tFILTER[ctrl][i].Pgn = PGN_INVALID;
    }
}

int32_t AddFilter_J1939 (uint32_t ctrl, uint32_t Pgn) 
{
    uint32_t            i;
    int32_t             result;

    result = RC_ERROR;

    for (i = 0; i < MAX_FILTER_J1939; i++) {
        if (tFILTER[ctrl][i].Pgn == Pgn) {
            result = RC_SUCCESS;
            break;
        }
        if (tFILTER[ctrl][i].Pgn == PGN_INVALID) {
            tFILTER[ctrl][i].Pgn = Pgn;
            result = RC_SUCCESS;
            break;
        }
    }

    return result;
}

/*
 *  Allow to receive all J1939 messages
 */
int32_t enableAllFilter_J1939 (uint32_t ctrl, bool enable) 
{
    __enable_all_filter[ctrl] = enable;    
    return RC_SUCCESS;
}

/*
 * Return State of enable all filter
 */
bool ifAllFilter_J1939 (uint32_t ctrl) 
{
    return __enable_all_filter[ctrl];
}

/* End of $Workfile: AddFilter_J1939.c$ */

