/*******************************************************************************
** $Revision: 2$
** $Date: 02/02/2011 03:05:34 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"
#include "hal.h"
#include "CS_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static CAN_STATUS_T     tCANS;

/* Prototypes *****************************************************************/
static void Update0_CANSMSG (void);
static void Update1_CANSMSG (void);

/* Functions ******************************************************************/
int32_t CS_CANMSG (uint32_t ctrl)
{
    Pgn_J1939 (ctrl,
               PGN_CAN_STATUS, 
               J1939_INFO_PRIORITY,              
               SIZE_CAN_STATUS, 
               0U,
               &tCANS, 
               0U,  
               1000U, 
               ctrl ? Update1_CANSMSG : Update0_CANSMSG);

    return 0;
}

int32_t CS_2_CANMSG (uint32_t ctrl)
{
    Pgn_J1939 (ctrl,
               PGN_CAN_STATUS_2, 
               J1939_INFO_PRIORITY,              
               SIZE_CAN_STATUS, 
               0U,
               &tCANS, 
               0U,  
               1000U, 
               ctrl ? Update1_CANSMSG : Update0_CANSMSG);

    return 0;
}

int32_t CS_CANMSG_CONFIGURABLE (uint32_t ctrl, uint32_t ctrl_info, bool usePGN_2)
{
    Pgn_J1939 (ctrl,
               usePGN_2 ? PGN_CAN_STATUS_2 : PGN_CAN_STATUS, 
               J1939_INFO_PRIORITY,              
               SIZE_CAN_STATUS, 
               0U,
               &tCANS, 
               0U,  
               1000U, 
               ctrl_info ? Update1_CANSMSG : Update0_CANSMSG);

    return 0;
}

static void Update0_CANSMSG (void)
{
    uint32_t            RxError;
    uint32_t            TxError;

    tCANS.Port = 0;

    RxError = GetRxError_CAN(0);
    TxError = GetTxError_CAN(0);

	/* Check Receive Warning and Bus-Passive */
	if (RxError > 127U) { 
        tCANS.ReceiveBusPassive = true;
	} else {
		tCANS.ReceiveBusPassive = false;
		if (RxError > 95U) { 
			tCANS.ReceiveWarning = true;
		} else {
			tCANS.ReceiveWarning = false;
		}
	}

	/* Check Transmit Warning and Bus-Passive */
	if (TxError > 127U) { 
		tCANS.TransmitBusPassive = true;
	} else {
		tCANS.TransmitBusPassive = false;
		if (TxError > 95U) { 
			tCANS.TransmitWarning = true;
		} else {
			tCANS.TransmitWarning = false;
		}
	}

	tCANS.ReceiveErrorCounter  = RxError;
    tCANS.TransmitErrorCounter = TxError;
}

static void Update1_CANSMSG (void)
{
    uint32_t            RxError;
    uint32_t            TxError;

    tCANS.Port = 1;

    RxError = GetRxError_CAN(1);
    TxError = GetTxError_CAN(1);

	/* Check Receive Warning and Bus-Passive */
	if (RxError > 127U) { 
        tCANS.ReceiveBusPassive = true;
	} else {
		tCANS.ReceiveBusPassive = false;
		if (RxError > 95U) { 
			tCANS.ReceiveWarning = true;
		} else {
			tCANS.ReceiveWarning = false;
		}
	}

	/* Check Transmit Warning and Bus-Passive */
	if (TxError > 127U) { 
		tCANS.TransmitBusPassive = true;
	} else {
		tCANS.TransmitBusPassive = false;
		if (TxError > 95U) { 
			tCANS.TransmitWarning = true;
		} else {
			tCANS.TransmitWarning = false;
		}
	}

	tCANS.ReceiveErrorCounter  = RxError;
    tCANS.TransmitErrorCounter = TxError;
}

/* End of $Workfile: CS_canmsg.c$ */
