
/* Include ********************************************************************/
#include "j1939.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
int32_t Pgn_ChangeTime_J1939 (uint32_t ctrl, 
                              uint32_t Pgn, 
                              uint32_t OnChangeTime, 
                              uint32_t CycleTime)
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].eType == PGN_EVENT) &&
            (tREG_MSG[ctrl][i].Pgn == Pgn)) {
            tREG_MSG[ctrl][i].CycleTime    = (uint16_t)(CycleTime / PERIOD_TIMER_J1939);
            tREG_MSG[ctrl][i].OnChangeTime = (uint16_t)(OnChangeTime / PERIOD_TIMER_J1939);
            result = RC_SUCCESS;
        }            
    }
    
    return result;       
}

int32_t Pgn_Function_ChangeTime_J1939 (uint32_t ctrl, 
									   uint32_t Pgn, 
									   uint32_t OnChangeTime, 
									   uint32_t CycleTime,
									   void (*Function)(void))
{
    uint32_t            i;
    int32_t             result;  

    result = RC_ERROR; 
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if ((tREG_MSG[ctrl][i].eType == PGN_EVENT) &&
            (tREG_MSG[ctrl][i].Pgn == Pgn)	&&
			(tREG_MSG[ctrl][i].Function == Function)) {
            tREG_MSG[ctrl][i].CycleTime    = (uint16_t)(CycleTime / PERIOD_TIMER_J1939);
            tREG_MSG[ctrl][i].OnChangeTime = (uint16_t)(OnChangeTime / PERIOD_TIMER_J1939);
            result = RC_SUCCESS;
        }            
    }
    
    return result;       
}

/* End of $Workfile: PgnChangeTime_J9193.c$ */

