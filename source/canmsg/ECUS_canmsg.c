
/* Include ********************************************************************/
#include "j1939.h"
#include "hal/hal.h"
#include "canmsg/ECUS_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static ECU_STATUS_T     tECUS;

/* Prototypes *****************************************************************/
static void             Update_ECUSMSG (void);

/* Functions ******************************************************************/
int32_t ECUS_CANMSG (uint32_t ctrl)
{
    /* Open Pgn ECU */
    Pgn_J1939 (ctrl,
               PGN_ECU_STATUS, 
               J1939_INFO_PRIORITY,              
               SIZE_ECU_STATUS, 
               0U,
               &tECUS, 
               0U,  
               1000U, 
               Update_ECUSMSG);

    return 0;
}

static void Update_ECUSMSG (void)
{
    //tECUS.ModuleIntTemp = GetModuleTemp();
//    tECUS.VBatt	= GetVBatt();
//    tECUS.VCap = GetVCap();
//    tECUS.MemDiag = GetMemDiag();
//    tECUS.ProcDiag = GetProcDiag();
}

/* End of $Workfile: ECUS_canmsg.c$ */
 
