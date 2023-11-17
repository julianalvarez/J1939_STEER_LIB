/*******************************************************************************
** $Revision: 8$
** $Date: 15/10/2014 03:12:12 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"
#include "hal.h"

/* Defines ********************************************************************/
static const int32_t    _msec = PERIOD_TIMER_J1939;
static int32_t          _oldTime[MAX_PORT_J1939];

/* Globals ********************************************************************/
/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
void TimerEventInit_J1939 (uint32_t ctrl)
{
    _oldTime[ctrl] = getTime();
}

void TimerEvent_J1939 (uint32_t ctrl)
{
    static int32_t      _msec_pending[MAX_PORT_J1939]; 
    int32_t             newTime;
    uint32_t            i;

    newTime = getTime(); 
    _msec_pending[ctrl] -= (newTime - _oldTime[ctrl]);
	_oldTime[ctrl] = newTime;
    while (_msec_pending[ctrl] <= 0) {
        _msec_pending[ctrl] = _msec + _msec_pending[ctrl];

        if (!J1939_Flags[ctrl].WaitingForAddressClaimContention) {
            for (i = 0; i < MAX_REG_MSG_J1939; i++) {
                if (tREG_MSG[ctrl][i].eType != NONE_EVENT) {
                    tREG_MSG[ctrl][i].CounterOC++;
                    tREG_MSG[ctrl][i].CounterCT++;
            
                    if (tREG_MSG[ctrl][i].OnChangeTime) {
                        if (tREG_MSG[ctrl][i].CounterOC >= tREG_MSG[ctrl][i].OnChangeTime) {
                            tREG_MSG[ctrl][i].bfOnChangeTime = true;
                        }
                    }
            
                    if (tREG_MSG[ctrl][i].CycleTime) {
                        if (tREG_MSG[ctrl][i].CounterCT >= tREG_MSG[ctrl][i].CycleTime) {
                            tREG_MSG[ctrl][i].bfCycleTime = true;
                        }
                    }
        
                    if (tREG_MSG[ctrl][i].TimeOut > 0U) {
                        tREG_MSG[ctrl][i].CounterTimeOut++;
                    }
                }
            }
        } else {
            if (ContentionWaitTime[ctrl]) {
                ContentionWaitTime[ctrl]--;
            }
        }
    }
}

void TimerProcess_J1939 (uint32_t ctrl)
{
    uint32_t            i;

    /* Process TimeOut - OnPGN, Request, Command */
    for (i = 0; i < MAX_REG_MSG_J1939; i++) {
        if (tREG_MSG[ctrl][i].TimeOut != 0) {
            if (tREG_MSG[ctrl][i].CounterTimeOut >= tREG_MSG[ctrl][i].TimeOut) {
                /* DELETE ENTRY after Timeout = Request and Command */            
                if ((tREG_MSG[ctrl][i].eType == REQUEST_EVENT) ||
                    (tREG_MSG[ctrl][i].eType == COMMAND_EVENT)) {
                    tREG_MSG[ctrl][i].eType = NONE_EVENT;
	                tREG_MSG[ctrl][i].TimeOut = 0U;
                }
                tREG_MSG[ctrl][i].CounterTimeOut = 0U;
                if (tREG_MSG[ctrl][i].FunctionTM != NULL) {
                    tREG_MSG[ctrl][i].FunctionTM();
                }
                /* Reset Fast-Packet Frame */
#ifdef J1939_FAST_PACKET_PROTOCOL                
                tREG_MSG[ctrl][i].Frame = 0xFF;
#endif
            } 
        }
    }
}

void TimeOut_J1939 (uint32_t ctrl, uint32_t TimeOut, void (*FunctionTM)(void))
{
    uint32_t            i;
    
    i = 0U;
    while (tTM[ctrl][i].FunctionTM != NULL) {
        i++;
    }

    tTM[ctrl][i].TimeOut        = (uint16_t)(TimeOut / PERIOD_TIMER_J1939);
    tTM[ctrl][i].CounterTimeOut = 0U;
    tTM[ctrl][i].FunctionTM     = FunctionTM;  
}

void ResetTimeOut_J1939 (uint32_t ctrl, void (*FunctionTM)(void))
{
    uint32_t            i;

    i = 0U;
    while (tTM[ctrl][i].FunctionTM != FunctionTM) {
        if (i >= MAX_TIMEOUT_J1939) {
            break;
        }
        i++;
    }

    /* If there was a reset w/o handler this routine does nothing */
    if (i < MAX_TIMEOUT_J1939) {
        /* Clear slot */
        tTM[ctrl][i].TimeOut        = 0U;
        tTM[ctrl][i].CounterTimeOut = 0U;
        tTM[ctrl][i].FunctionTM     = 0U;  
    }
}

/* End of $Workfile: TimerEvent_J1939.c$ */

