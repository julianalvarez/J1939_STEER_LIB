/*******************************************************************************
** $Revision: 0$
** $Date: $
** $Author: jlondero$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef IOC_CANMSG_H
#define IOC_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/

/* Enums **********************************************************************/
typedef enum tagPIN_CONFIG_COMMAND_E
{
    PIN_CONFIG_COMMAND_SEND_CONFIGURATION       = 0,
    PIN_CONFIG_COMMAND_RESET                    = 1,
} PIN_CONFIG_COMMAND_E;

/******************************** General Msg *********************************/
typedef struct tagPIN_CONFIG_P16_T
{
    uint8_t             Page;
    uint8_t             Command;
    uint8_t             Message;
    uint8_t             ShortParam;
    uint32_t            LongParam;
} PIN_CONFIG_P16_T;

typedef struct tagPIN_CONFIG_P17_T
{
    uint8_t             Page;
    uint8_t             PinIndex;
    uint8_t             ConfigParameterIndex;
    uint16_t            ConfigValue;
    uint8_t             MasterSwitchMode; // To be extended to other functions
    uint8_t             Rvd1;
    uint8_t             Rvd2;
} PIN_CONFIG_P17_T;

typedef union tagPIN_CONFIG_U
{
    PIN_CONFIG_P16_T     P16;
    PIN_CONFIG_P17_T     P17;
} PIN_CONFIG_U;

#endif /* end IOC_CANMSG_H */

/* End of $Workfile: IOC_canmsg.h$ */
