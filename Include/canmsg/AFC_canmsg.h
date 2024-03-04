
#ifndef AFC_CANMSG_H
#define AFC_CANMSG_H


/*!\page Active Force Configure 
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/

/* Enums **********************************************************************/
typedef enum tag_AFC_COMMAND_E                          /*!< List of commands for Active Force Controller */
{ 
    AFC_COMMAND_RESET_ALARMS			= 0,
	AFC_COMMAND_DEBUG_MSGS              = 1,
	AFC_COMMAND_SEND_CONFIG             = 2,
} AFC_COMMAND_E;

/******************************** General Msg *********************************/

typedef struct tagACTIVE_FORCE_CONFIG_P190
{
	uint8_t  Page;
	uint8_t  Command;               /* Value from ASC_COMMAND_E*/
	uint8_t  Message;               /* Value from ASC_MESSAGES_E*/
	uint8_t  ShortParam;            /* Short param for Command or Message */
	uint32_t LongParam;             /* Long param for Command or Message */
} ACTIVE_FORCE_CONFIG_P190_T;

typedef struct tagACTIVE_FORCE_CONFIG_P191
{
	uint8_t  Page;
	uint8_t  ModuleIndex;
    uint8_t  Rvd1;
    uint8_t  Rvd2;
    uint8_t  Rvd3;
    uint8_t  Rvd4;
    uint8_t  Rvd5;
	uint8_t  Rvd6;
} ACTIVE_FORCE_CONFIG_P191_T;

#endif /* end AFC_CANMSG_H */

/* End of $Workfile: AFC_canmsg.h$ */

