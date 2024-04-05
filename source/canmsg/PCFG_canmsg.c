/* Include ********************************************************************/
#include <string.h>
#include "j1939.h"
#include "hal/hal.h"
#include "canmsg/PCFG_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static PGN_CONFIGURE_T  tPCFG;

/* Prototypes *****************************************************************/
static uint32_t         UpdatePgnChangeTime_CANMSG (uint32_t Address);

/* Functions ******************************************************************/
int32_t PCFG_CANMSG (uint32_t ctrl)
{
    /* Null Timeout */
    OnPgn_J1939 (ctrl,
                 PGN_PGN_CONFIGURE, 
                 SIZE_PGN_CONFIGURE,
                 &tPCFG, 
                 UpdatePgnChangeTime_CANMSG,
                 0U,
                 NULL);

    return (0);
}

static uint32_t UpdatePgnChangeTime_CANMSG (uint32_t Address)
{
    if ((tPCFG.Pgn & 0xFF) == J1939_ADDRESS_GLOBAL) {
        Pgn_ChangeTime_J1939 (getCTRLRcv_J1939(), tPCFG.Pgn >> 8, tPCFG.OnChangeTime, tPCFG.CycleTime);
    } else if ((tPCFG.Pgn & 0xFF) == J1939_Address[getCTRLRcv_J1939()]) {
        Pgn_ChangeTime_J1939 (getCTRLRcv_J1939(), tPCFG.Pgn >> 8, tPCFG.OnChangeTime, tPCFG.CycleTime);
    }

    return 0;
}

/* End of $Workfile: PCFG_canmsg.c$ */
