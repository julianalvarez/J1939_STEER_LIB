
/* Include ********************************************************************/
#include <string.h>
#include "j1939.h"
#include "hal/hal.h"
#include "canmsg/RST_canmsg.h"

/* Defines ********************************************************************/
#define MAGIC_RESET_ECU                     "DEADDEAD"

/* Globals ********************************************************************/
/* Statics ********************************************************************/
static RESET_ECU_T      tRST;

/* Prototypes *****************************************************************/
static uint32_t         Reset_CANMSG (uint32_t Address);

/* Functions ******************************************************************/
int32_t RST_CANMSG (uint32_t ctrl)
{
    /* Null Timeout */
    OnPgn_J1939 (ctrl,
                 PGN_RESET_ECU | J1939_Address[ctrl], 
                 SIZE_RESET_ECU,
                 &tRST, 
                 Reset_CANMSG,
                 0U,
                 NULL);

    return (0);
}

int32_t RST_CANMSG_SendReset (uint32_t ctrl, uint8_t destination)
{
    char                Magic[sizeof (MAGIC_RESET_ECU)] = MAGIC_RESET_ECU;

    return Output_J1939 (   ctrl,
                            PGN_RESET_ECU | (uint32_t) destination,
                            J1939_INFO_PRIORITY, 
                            SIZE_RESET_ECU,
                            Magic,
                            J1939_Address[ctrl]);
}

static uint32_t Reset_CANMSG (uint32_t Address)
{
    char                Magic[sizeof (MAGIC_RESET_ECU)] = MAGIC_RESET_ECU;

    if (memcmp (Magic, tRST.Data, SIZE_RESET_ECU) == 0) {
        /* Call Hardware-Dependant Reset Code */
    	//Reset();
    }

    return 0;
}

/* End of $Workfile: RST_canmsg.c$ */
