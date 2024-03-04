/*******************************************************************************
** $Revision: 0$
** $Date: 17/05/2018 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PROPA_HOOK_COMMAND_CANMSG_H
#define PROPA_HOOK_COMMAND_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/

/******************************** Enums *********************************/
typedef enum tag_HOOK_COMMAND_E                          /*!< List of commands for CANSteer */
{
	//Read/Write --> use ReadWrite bit
    HOOK_COMMAND_SENSIBILITY = 0x30,        /*!< Write sensibility parameter. Unit: uV/V Factor: 1  Offset: 0*/
	HOOK_COMMAND_CELL_QTY = 0x31,           /*!< Write total cells quantity parameter. Unit: kg Factor: 1  Offset: 0*/
	HOOK_COMMAND_TIME_EST = 0x32,           /*!< Write stabilization time parameter. Unit: ms Factor: 1  Offset: 0*/
	HOOK_COMMAND_RECORTE = 0x33,            /*!< Write trim N samples from the begin and end of the sample array. Unit: - Factor: 1  Offset: 0*/
	HOOK_COMMAND_CONVERSION = 0x34,         /*!< Write conversions. Conver > 2*Recorte Unit: - Factor: 1  Offset: 0*/
	HOOK_COMMAND_WINDOW = 0x35,             /*!< Write window parameter. Unit: - Factor: 1  Offset: 0*/
	HOOK_COMMAND_KG_FILTER = 0x36,          /*!< Write filter gain parameter. Unit: kg Factor: 0.01  Offset: 0*/
	HOOK_COMMAND_DIVISIONS = 0x37,          /*!< Write divisions parameter. Unit: kg Factor: 0.01  Offset: 0*/
	HOOK_COMMAND_CORRECTION_FACTOR = 0x38,  /*!< Write correction factor parameter. Unit: - Factor: 0.01  Offset: 0*/
	//Cmd --> Use Read/Write bit set in 0
	HOOK_COMMAND_SAVE_PARAM = 0x39,         /*!< Command save parameters No data is needed*/
	HOOK_COMMAND_SET_ZERO = 0x3A,           /*!< Command set zero No data is needed*/
	HOOK_COMMAND_GET_ZERO = 0x3C,           /*!< Command get zero No data is needed*/
	HOOK_COMMAND_SET_KNOWN_WEIGHT = 0x3D,   /*!< Command set known weight Unit: kg Factor: 1  Offset: 0*/
    // Information
    HOOK_COMMAND_CPU_SERIAL = 0x3E,         /*!< Read Serial Number. Unit: - Factor: 1  Offset: 0 */
    HOOK_COMMAND_VERSION = 0x3F,            /*!< Read Version Number. Interpretation: 0x00 0x00 0xAA 0xBB where 0xAA is the MAYOR and 0xBB is MINOR (vMAYOR.MINOR) */
} HOOK_COMMAND_E;

/******************************** General Msg *********************************/

/* PROPA Messages */
typedef struct tagHOOK_MSG_COMMAND
{
	uint8_t  CmdID : 7;			/* Value from HOOK_COMMAND_E*/
    uint8_t  ReadWrite : 1;      /* MSB from first byte. Change HOOK_COMMAND from set(0) to get(1)*/
    uint32_t messageData;		/* Data bytes: byte 1 - 4 interpret data with HOOK_COMMAND_E*/
	uint16_t Rvd1;			    /*Reserved*/
	uint8_t  Rvd2;			    /*Reserved*/
} HOOK_MSG_COMMAND_T;

#endif /* end PROPA_HOOK_COMMAND_CANMSG_H */

/* End of $Workfile: PROPA_HOOK_command_canmsg.h$ */
