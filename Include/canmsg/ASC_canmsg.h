
#ifndef ASC_CANMSG_H
#define ASC_CANMSG_H


/*!\page Active Singulation Configure 
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/

/* Enums **********************************************************************/
typedef enum tag_ASC_COMMAND_E                          /*!< List of commands for Active Singulation */
{ 
    ASC_COMMAND_RESET_POSITION                  = 0,
    ASC_COMMAND_RESET_ALARMS                    = 1,
    ASC_COMMAND_LIMITS_CALIB                    = 2,
    ASC_COMMAND_STEP_MODE                       = 3,
    ASC_COMMAND_DEBUG_MSGS                      = 4,
    ASC_COMMAND_SEND_CONFIG                     = 5,
    ASC_COMMAND_LED_BLINK                       = 6,
    ASC_COMMAND_SET_DUMMY_RANGE                 = 7,
} ASC_COMMAND_E;

/******************************** General Msg *********************************/

typedef struct tagACTIVE_SINGULATION_CONFIG_P181
{
	uint8_t  Page;
	uint8_t  Command;               /* Value from ASC_COMMAND_E*/
	uint8_t  Message;               /* Value from ASC_MESSAGES_E*/
	uint8_t  ShortParam;            /* Short param for Command or Message */
	uint32_t LongParam;             /* Long param for Command or Message */
} ACTIVE_SINGULATION_CONFIG_P181_T;

typedef struct tagACTIVE_SINGULATION_CONFIG_P182
{
	uint8_t  Page;
	uint8_t  MotorEnable;
    uint8_t  MotorDirection;
    uint8_t  PWMSetpoint;
    uint8_t  CurrentLimit;
    uint16_t ControlRef;
    uint8_t  MotorMode;
} ACTIVE_SINGULATION_CONFIG_P182_T;

typedef struct tagACTIVE_SINGULATION_CONFIG_P183
{
	uint8_t  Page;
    uint8_t  MinPWM;
    uint8_t  MaxPWM;
    uint8_t  PosDeadBand;
    uint8_t  StepPos;
    uint8_t  PropConstant;
    uint8_t  IntConstant;
    uint8_t  DerConstant;
} ACTIVE_SINGULATION_CONFIG_P183_T;

#endif /* end ASC_CANMSG_H */

/* End of $Workfile: ASC_canmsg.h$ */

