/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:16 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/

/* Include ********************************************************************/
#include <string.h>
#include "j1939.h"
#include "hal/hal.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static uint8_t selfConfigurableAddressStart[MAX_PORT_J1939];
static uint8_t selfConfigurableAddressEnd[MAX_PORT_J1939];
static uint8_t selfConfigurableAddressRemaining[MAX_PORT_J1939];
static bool synchronizeAddressClaim = false;
/* Prototypes *****************************************************************/
/* Functions ******************************************************************/
void SetSynchronizeAddressClaim(bool enable)
{
    uint32_t i;
    
    synchronizeAddressClaim = enable;
    
    if (synchronizeAddressClaim) {
        for (i = 1; i < MAX_PORT_J1939; i++) {
            J1939_Address[i] = J1939_Address[0];
            AddressClaim_J1939 (i);
        }
    }
}

bool GetSynchronizeAddressClaim(void)
{
    return synchronizeAddressClaim;
}

void SelfConfigurableAddressRange(uint32_t ctrl, uint8_t addrStart, uint8_t addrEnd)
{
    selfConfigurableAddressStart[ctrl] = addrStart;
    selfConfigurableAddressEnd[ctrl] = addrEnd;
    selfConfigurableAddressRemaining[ctrl] = addrEnd - addrStart + 1;
}

void AddressClaim_J1939 (uint32_t ctrl)
{
    J1939_MESSAGE_T     tJ1939Msg;
    uint32_t            ctrlForAddressClaim;
        
    if (J1939_Address[ctrl] == J1939_ADDRESS_NULL)
    {
        /* we are claiming no address */
        J1939_Flags[ctrl].CannotClaimAddress = true;
        J1939_Flags[ctrl].WaitingForAddressClaimContention = true;
        ContentionWaitTime[ctrl]= NULL_ADDRESS_CLAIM_TIME;
    }
    
    if (synchronizeAddressClaim) {
        ctrlForAddressClaim = 0;
    } else {
        ctrlForAddressClaim = ctrl;
    }

    tJ1939Msg.Priority           = J1939_INFO_PRIORITY;
    tJ1939Msg.Pgn                = PGN_ADDRESS_CLAIM | J1939_ADDRESS_GLOBAL;
    tJ1939Msg.Length             = J1939_DATA_LENGTH;
    memcpy (&tJ1939Msg.Data, (uint8_t*)(&AC_NAME[ctrlForAddressClaim]), 8U);
    tJ1939Msg.SourceAddress = J1939_Address[ctrl];
    TransmitMessages_J1939 (ctrl, &tJ1939Msg);
}

void OnAddressClaim_J1939(uint32_t ctrl, J1939_MESSAGE_T ReceivedMsg) 
{
    uint32_t i;
    uint64_t ourISONAME;
    uint64_t theirISONAME;
    
    if (ReceivedMsg.SourceAddress == J1939_ADDRESS_NULL) {
        /* Someone else is claiming null address */
        return;
    }
    
    if (synchronizeAddressClaim) {
        ctrl = 0;
    }
    
    if (ReceivedMsg.SourceAddress == J1939_Address[ctrl]) {
        /* Someone claimed our address */
        ourISONAME = *(uint64_t*)&AC_NAME[ctrl];
        theirISONAME = *(uint64_t*)&ReceivedMsg.Data;
        if (ourISONAME >= theirISONAME) /* Arbitration */
        {
            /* We lost! :( */
            if (AC_NAME[ctrl].Arbitrary_Address == 1) {
                /* Arbitrary address, search next address to claim */
                if (selfConfigurableAddressRemaining[ctrl] > 0) {
                    selfConfigurableAddressRemaining[ctrl]--;
                    J1939_Address[ctrl]++;
                    /* Check new address is in range */
                    if (J1939_Address[ctrl] > selfConfigurableAddressEnd[ctrl]) {
                        J1939_Address[ctrl] = selfConfigurableAddressStart[ctrl];
                    } else if (J1939_Address[ctrl] < selfConfigurableAddressStart[ctrl]) {
                        J1939_Address[ctrl] = selfConfigurableAddressStart[ctrl];
                    }
                    /* Set up filter to receive messages sent to new address */                    
                    if (synchronizeAddressClaim) {
                        for (i = 0; i < MAX_PORT_J1939; i++) {
                            SetAddressFilter_CAN (i, J1939_Address[ctrl]);
                            J1939_Address[i] = J1939_Address[ctrl];
                        }
                    } else {
                        SetAddressFilter_CAN (ctrl, J1939_Address[ctrl]);
                    }
                    if (ctrl == 0) {
                        /* Write new address to EEPROM, only for can bus 0 */
                        Write_EEPROM(0x8 , (void*)(&J1939_Address[ctrl]),1);
                    }
                } else {
                    /* Already checked all configuable address, go to address null */
                    if (synchronizeAddressClaim) {
                        for (i = 0; i < MAX_PORT_J1939; i++) {
                            /* Set up filter to receive messages sent to the global address */
                            SetAddressFilter_CAN (i, J1939_ADDRESS_GLOBAL);
                            /* Set own address to null */
                            J1939_Address[i] = J1939_ADDRESS_NULL;
                        }
                    } else {
                        /* Set up filter to receive messages sent to the global address */
                        SetAddressFilter_CAN (ctrl, J1939_ADDRESS_GLOBAL);
                        /* Set own address to null */
                        J1939_Address[ctrl] = J1939_ADDRESS_NULL;
                    }
                }
            } else {
                /* Unique address, go to NULL address */
                if (synchronizeAddressClaim) {
                    for (i = 0; i < MAX_PORT_J1939; i++) {
                        /* Set up filter to receive messages sent to the global address */
                        SetAddressFilter_CAN (i, J1939_ADDRESS_GLOBAL);
                        /* Set own address to null */
                        J1939_Address[i] = J1939_ADDRESS_NULL;
                    }
                } else {
                    /* Set up filter to receive messages sent to the global address */
                    SetAddressFilter_CAN (ctrl, J1939_ADDRESS_GLOBAL);
                    /* Set own address to null */
                    J1939_Address[ctrl] = J1939_ADDRESS_NULL;
                }
            }
//        } else {
//            /* We won! ;) */
        }
        
        /* Send our address claim */
        if (synchronizeAddressClaim) {
            for (i = 0; i < MAX_PORT_J1939; i++) {
                AddressClaim_J1939(i);
            }
        } else {
            AddressClaim_J1939(ctrl);
        }
    }
}

void OnRequestForAddressClaim_J1939 (uint32_t ctrl)
{
    uint32_t i;
    
    /* Send our address claim */
    if (synchronizeAddressClaim) {
        for (i = 0; i < MAX_PORT_J1939; i++) {
            AddressClaim_J1939(i);
        }
    } else {
        AddressClaim_J1939(ctrl);
    }
}

/* End of $Workfile: AddressClaim_J1939.c$ */

