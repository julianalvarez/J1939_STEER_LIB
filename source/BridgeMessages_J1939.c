/* Include ********************************************************************/
#include <assert.h>
#include "j1939.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
/*
 * TODO: Transport Protocol Support.
 */
int32_t BridgeMessages_J1939 (uint32_t ctrl, uint32_t Pgn)
{
    int32_t             result;  

    result = RC_SUCCESS; 

    if (AddFilterBridge_J1939 (ctrl, Pgn)) {
        return RC_ERROR;
    }
    
    return result;
}



/* End of $Workfile: BridgeMessages_J1939.c$ */

