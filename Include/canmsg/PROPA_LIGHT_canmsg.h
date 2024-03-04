/*******************************************************************************
** $Revision: 0$
** $Date: 17/05/2018 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PROPA_LIGHT_CANMSG_H
#define PROPA_LIGHT_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define LIGHT_MSG_PAGE								 (145U)

#define LIGHT_MSG_RESTORE_DEFAULTS_CHECK_VALUE       (0x5CU)
#define LIGHT_MSG_COMMIT_DATA_CHECK_VALUE            (0x5AU)

/******************************** Enums *********************************/
typedef enum tagLIGHT_XID_E
{
    MSG_XID_GET_PARAMETER               = 0xA0U,
    MSG_XID_GET_PARAMETER_RESPONSE      = 0xA1U,
    MSG_XID_SET_PARAMETER               = 0xA2U,
    MSG_XID_SET_PARAMETER_RESPONSE      = 0xA3U,
    MSG_XID_RESTORE_DEFAULTS            = 0xA4U,
    MSG_XID_RESTORE_DEFAULTS_RESPONSE   = 0xA5U,
    MSG_XID_COMMIT_DATA                 = 0xA6U,
    MSG_XID_COMMIT_DATA_RESPONSE        = 0xA7U,
    MSG_XID_COMMAND                     = 0xB0U,
    MSG_XID_COMMAND_RESPONSE            = 0xB1U,
} LIGHT_XID_E;

typedef enum tagLIGHT_PARAMETERS   /*!< List of LIGHT Parameters accessible with Get_Parameter/Set_Parameter */
{
    /* Module Parameters */
    LIGHT_PARAMETER_PWM_PERIOD              = 0x0001U,    /*!< LIGHT Mounting Position */
    LIGHT_PARAMETER_ON_DELAY                = 0x0002U,
    LIGHT_PARAMETER_OFF_DELAY               = 0x0003U,
    LIGHT_PARAMETER_CYCLIC_TRIGGER          = 0x0004U,
    LIGHT_PARAMETER_CYCLIC_TRIGGER_ENABLE   = 0x0005U,
    LIGHT_PARAMETER_EXTERNAL_TRIGGER_ENABLE = 0x0006U,
    LIGHT_PARAMETER_OUT1_OFF_DUTY           = 0x0010U,
    LIGHT_PARAMETER_OUT1_ON_DUTY            = 0x0011U,
    LIGHT_PARAMETER_OUT2_OFF_DUTY           = 0x0020U,
    LIGHT_PARAMETER_OUT2_ON_DUTY            = 0x0021U,
} LIGHT_PARAMETERS_E;


typedef enum tagLIGHT_MSG_RESTORE_DEFAULTS_COMMAND_E   /*!< List of Commands for RestoreDefaults */
{
    LIGHT_MSG_RESTORE_DEFAULTS_COMMAND_FULL     = 0xFFU,     /*!< Restore all parameters */
} LIGHT_MSG_RESTORE_DEFAULTS_COMMAND_E;

typedef enum tagLIGHT_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS   /*!< List of Status messages returned from RestoreDefaultsResponse */
{
    LIGHT_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_FAIL        = 0x00U,    /*!< RestoreDefaults failed */
    LIGHT_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_SUCCESS     = 0xFFU,    /*!< RestoreDefaults succeeded */
} LIGHT_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E;

typedef enum tagLIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS   /*!< List of Status messages returned from CommitDataResponse */
{
    LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_READY_TO_COMMIT               = 0x00U,
    LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_BEGUN                  = 0x01U,
    LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_SUCCESS                = 0x02U,
    LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_FAIL                   = 0x03U,
    LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_PARAMETER_CHECK_FAIL          = 0x04U,
    LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_ALREADY_IN_PROGRESS    = 0x05U,
} LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_E;

typedef enum tagLIGHT_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE   /*!< List of ErrorCode messages returned from CommitDataResponse */
{
    LIGHT_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_0     = 0x00U,
    LIGHT_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_FF    = 0xFFU
} LIGHT_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_E;

typedef enum tagLIGHT_MSG_COMMAND_E /*!< List of Commands available for module */
{
    LIGHT_COMMAND_BOOST_POWER_ENABLE    = 0x00U,
    LIGHT_COMMAND_ON                    = 0x01U,
    LIGHT_COMMAND_OFF                   = 0x02U,
    LIGHT_COMMAND_AUTO                  = 0x03U,
    LIGHT_COMMAND_TRIGGER               = 0x04U,
} LIGHT_MSG_COMMAND_E;

typedef enum tagLIGHT_MSG_COMMAND_RESPONSE_E /*!< List of possible Commands response */
{
    LIGHT_MSG_COMMAND_RESPONSE_OK       = 0x00U,
} LIGHT_MSG_COMMAND_RESPONSE_E;

/******************************** Typedefs *********************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/******************************** General Msg *********************************/

/* PROPA Messages */
typedef struct tagLIGHT_MSG_P145
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  Byte3;
    uint8_t  Byte4;
    uint8_t  Byte5;
    uint8_t  Byte6;
    uint8_t  Byte7;
    uint8_t  Byte8;
} LIGHT_MSG_P145_T;

typedef struct tagLIGHT_MSG_P145_GET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from LIGHT_PARAMETERS_E*/
    uint32_t Rvd1;
} LIGHT_MSG_P145_GET_PARAMETER_T;

typedef struct tagLIGHT_MSG_P145_GET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from LIGHT_PARAMETERS_E*/
    real32_T ParameterValue;
} LIGHT_MSG_P145_GET_PARAMETER_RESPONSE_T;

typedef struct tagLIGHT_MSG_P145_SET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from LIGHT_PARAMETERS_E*/
    real32_T ParameterValue;
} LIGHT_MSG_P145_SET_PARAMETER_T;

typedef struct tagLIGHT_MSG_P145_SET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from LIGHT_PARAMETERS_E*/
    real32_T ParameterValue;
} LIGHT_MSG_P145_SET_PARAMETER_RESPONSE_T;

typedef struct tagLIGHT_P145_MSG_RESTORE_DEFAULTS
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5C */
    uint8_t  Command;        /* Value from LIGHT_MSG_RESTORE_DEFAULTS_COMMAND_E*/
    uint32_t Rvd2;
} LIGHT_MSG_P145_RESTORE_DEFAULTS_T;

typedef struct tagLIGHT_P145_MSG_RESTORE_DEFAULTS_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  RestoreStatus;   /* Value from LIGHT_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} LIGHT_MSG_P145_RESTORE_DEFAULTS_RESPONSE_T;

typedef struct tagLIGHT_P145_MSG_COMMIT_DATA
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5A */
    uint8_t  Rvd1;
    uint32_t Rvd2;
} LIGHT_MSG_P145_COMMIT_DATA_T;

typedef struct tagLIGHT_MSG_P145_COMMIT_DATA_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CommitStatus;       /* Value from LIGHT_MSG_COMMIT_DATA_RESPONSE_STATUS_E*/
    uint16_t CommitErrorCode;    /* Value from LIGHT_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_E*/
    uint8_t  Rvd1;
    uint16_t Rvd2;
} LIGHT_MSG_P145_COMMIT_DATA_RESPONSE_T;

typedef struct tagLIGHT_MSG_P145_COMMAND
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t CommandIndex;     /* Value from LIGHT_COMMANDS_E*/
    real32_T CommandValue;
} LIGHT_MSG_P145_COMMAND_T;

typedef struct tagLIGHT_MSG_P145_COMMAND_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t CommandResponseIndex;     /* Value from LIGHT_COMMANDS_RESPONSE_E*/
    real32_T CommandResponseValue;
} LIGHT_MSG_P145_COMMAND_RESPONSE_T;

typedef union tagLIGHT_MSG_P145_U
{
    LIGHT_MSG_P145_T                           	LIGHT_MSG_P145;
    LIGHT_MSG_P145_GET_PARAMETER_T             	LIGHT_MSG_P145_GET_PARAMETER;
    LIGHT_MSG_P145_GET_PARAMETER_RESPONSE_T    	LIGHT_MSG_P145_GET_PARAMETER_RESPONSE;
    LIGHT_MSG_P145_SET_PARAMETER_T             	LIGHT_MSG_P145_SET_PARAMETER;
    LIGHT_MSG_P145_SET_PARAMETER_RESPONSE_T    	LIGHT_MSG_P145_SET_PARAMETER_RESPONSE;
    LIGHT_MSG_P145_RESTORE_DEFAULTS_T          	LIGHT_MSG_P145_RESTORE_DEFAULTS;
    LIGHT_MSG_P145_RESTORE_DEFAULTS_RESPONSE_T 	LIGHT_MSG_P145_RESTORE_DEFAULTS_RESPONSE;
    LIGHT_MSG_P145_COMMIT_DATA_T             	LIGHT_MSG_P145_COMMIT_DATA;
    LIGHT_MSG_P145_COMMIT_DATA_RESPONSE_T    	LIGHT_MSG_P145_COMMIT_DATA_RESPONSE;
    LIGHT_MSG_P145_COMMAND_T                    LIGHT_MSG_P145_COMMAND;
    LIGHT_MSG_P145_COMMAND_RESPONSE_T           LIGHT_MSG_P145_COMMAND_RESPONSE;
} LIGHT_MSG_P145_U;

#endif /* end PROPA_LIGHT_CANMSG_H */

/* End of $Workfile: PROPA_LIGHT_canmsg.h$ */
