/*******************************************************************************
** $Revision: 6$
** $Date: 15/10/2014 03:12:12 p.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include "j1939.h"
#include "../../hal/hal.h"
#include "canmsg/rqst_canmsg.h"
#include "canmsg/ackm_canmsg.h"
#include "canmsg/tpcm_canmsg.h"
#include "canmsg/tpdt_canmsg.h"
#include "canmsg/ac_canmsg.h"

#include <stdio.h>
extern uint32_t TIME_Get(void);
/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Public */
ADDRESS_CLAIM_T         AC_NAME[MAX_PORT_J1939];
uint32_t                J1939_Address[MAX_PORT_J1939];
J1939_FLAG_T            J1939_Flags[MAX_PORT_J1939];
#ifdef J1939_BRIDGE
J1939_FLAG_T            J1939_FlagsGW[MAX_PORT_J1939];
#endif

#ifdef J1939_TRANSPORT_PROTOCOL
J1939_CIR_BUF_T         j1939_TP_TX[MAX_PORT_J1939];
#endif
J1939_CIR_BUF_T         j1939_RX[MAX_PORT_J1939];
#ifdef J1939_BRIDGE
J1939_CIR_BUF_T         j1939_RXGW[MAX_PORT_J1939];
#endif
#ifdef J1939_TRANSPORT_PROTOCOL
bool                    J1939_TP_TxBsy[MAX_PORT_J1939];
#endif
/* Private */
J1939_FILTER_T			tFILTER[MAX_PORT_J1939][MAX_FILTER_J1939];
#ifdef J1939_BRIDGE
J1939_FILTER_T			tFILTERGW[MAX_PORT_J1939][MAX_FILTERGW_J1939];
#endif
J1939_REG_MSG_T         tREG_MSG[MAX_PORT_J1939][MAX_REG_MSG_J1939];
J1939_TM_T              tTM[MAX_PORT_J1939][MAX_TIMEOUT_J1939];
#ifdef J1939_TRANSPORT_PROTOCOL
J1939_TP_T              tTP[MAX_PORT_J1939][MAX_TRANSPORT_PROTOCOL_J1939];
#endif
uint32_t                ContentionWaitTime[MAX_PORT_J1939];

/* Statics ********************************************************************/
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
void Open_J1939 (uint32_t ctrl,
                 bool     InitNAMEandAddress, 
                 uint8_t  Address,
                 uint8_t  Arbitrary_Address,
                 uint8_t  Industry_Group,
                 uint8_t  Vehicle_Instance,
                 uint8_t  Vehicle_System,
                 uint8_t  Function,
                 uint8_t  Function_Instance,
                 uint8_t  Ecu_Instance,
                 uint16_t Manufacturer_Code,
                 uint32_t Identity_Number)
{
    /* Initialize global variables */
    /* Cannot Claim Address, all other flags cleared. */
    J1939_Flags[ctrl].PortInitialized                  = true;
    J1939_Flags[ctrl].CannotClaimAddress               = false;
    J1939_Flags[ctrl].WaitingForAddressClaimContention = true;
    J1939_Flags[ctrl].GettingCommandedAddress          = false;
    TimerEventInit_J1939(ctrl);
    ContentionWaitTime[ctrl]                           = CONTENTION_TIME_J1939;
    
    if (InitNAMEandAddress) {
        J1939_Address[ctrl]             = Address;
        AC_NAME[ctrl].Arbitrary_Address = Arbitrary_Address;
        AC_NAME[ctrl].Industry_Group    = Industry_Group;
        AC_NAME[ctrl].Ecu_Instance      = Ecu_Instance;
        AC_NAME[ctrl].Vehicle_Instance  = Vehicle_Instance;
        AC_NAME[ctrl].Vehicle_System    = Vehicle_System;
        AC_NAME[ctrl].Reserved          = 0x0;
        AC_NAME[ctrl].Function          = Function;
        AC_NAME[ctrl].Function_Instance = Function_Instance;
        AC_NAME[ctrl].Manufacturer_Code = Manufacturer_Code;
        AC_NAME[ctrl].Identity_Number   = Identity_Number;
        
    }
    InitializeFilter_J1939(ctrl);

    AddFilter_J1939 (ctrl, PGN_REQUEST); 
    AddFilter_J1939 (ctrl, PGN_ACKNOWLEDGMENT);
    AddFilter_J1939 (ctrl, PGN_ADDRESS_CLAIM);
    AddFilter_J1939 (ctrl, PGN_TPCM);
    AddFilter_J1939 (ctrl, PGN_TPDT);

    J1939_CIR_BUF_RESET (j1939_RX[ctrl]);
#ifdef J1939_BRIDGE    
    InitializeFilterBridge_J1939(ctrl);
    J1939_CIR_BUF_RESET (j1939_RXGW[ctrl]);
#endif
#ifdef J1939_TRANSPORT_PROTOCOL            
    J1939_CIR_BUF_RESET (j1939_TP_TX[ctrl]);
    J1939_TP_TxBsy[ctrl] = false;
#endif  
    /* Open can and pass 2 hooks */
    init_CAN (ctrl, 250000);

    /* Start the process of claiming our address */
    if (InitNAMEandAddress) {
        AddressClaim_J1939 (ctrl);
    }
}

/* End of $Workfile: Open_J1939.c$ */

