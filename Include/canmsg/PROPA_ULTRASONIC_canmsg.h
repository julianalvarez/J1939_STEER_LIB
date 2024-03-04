/*******************************************************************************
** $Revision: 0$
** $Date: 17/05/2018 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PROPA_ULTRASONIC_CANMSG_H
#define PROPA_ULTRASONIC_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define ULTRASONIC_MSG_PAGE								 (151U)

#define ULTRASONIC_MSG_XID_GET_PARAMETER                    (0xA0U)
#define ULTRASONIC_MSG_XID_GET_PARAMETER_RESPONSE           (0xA1U)
#define ULTRASONIC_MSG_XID_SET_PARAMETER                    (0xA2U)
#define ULTRASONIC_MSG_XID_SET_PARAMETER_RESPONSE           (0xA3U)
#define ULTRASONIC_MSG_XID_RESTORE_DEFAULTS                 (0xA4U)
#define ULTRASONIC_MSG_XID_RESTORE_DEFAULTS_RESPONSE        (0xA5U)
#define ULTRASONIC_MSG_XID_CONFIG                           (0xA6U)
#define ULTRASONIC_MSG_XID_CONFIG_RESPONSE                  (0xA7U)

#define ULTRASONIC_MSG_RESTORE_DEFAULTS_CHECK_VALUE         (0x5CU)
#define ULTRASONIC_MSG_CONFIG_CHECK_VALUE                   (0x5AU)

/******************************** Enums *********************************/

typedef enum tagULTRASONIC_PARAMETERS   /*!< List of ULTRASONIC Parameters accessible with Get_Parameter/Set_Parameter */
{
  /* Module Parameters */
  ULTRASONIC_MSG_PERIOD_PARAMETER = 0x1000U,    /*!< ULTRASONIC period canmsg distance report*/

} ULTRASONIC_PARAMETERS_E;


typedef enum tagULTRASONIC_MSG_RESTORE_DEFAULTS_COMMAND_E   /*!< List of Commands for RestoreDefaults */
{
  //IMU_MSG_RESTORE_DEFAULTS_COMMAND_ACC      = 0x00U,     /*!< Restore accelerometer parameters */
  //IMU_MSG_RESTORE_DEFAULTS_COMMAND_GYR      = 0x01U,     /*!< Restore gyroscope parameters */
  ULTRASONIC_MSG_RESTORE_DEFAULTS_COMMAND_FULL     = 0xFFU      /*!< Restore all parameters */
} ULTRASONIC_MSG_RESTORE_DEFAULTS_COMMAND_E;

typedef enum tagULTRASONIC_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS   /*!< List of Status messages returned from RestoreDefaultsResponse */
{
  ULTRASONIC_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_FAIL        = 0x00U,    /*!< RestoreDefaults failed */
  ULTRASONIC_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_SUCCESS     = 0xFFU     /*!< RestoreDefaults succeeded */
} ULTRASONIC_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E;

typedef enum tagULTRASONIC_MSG_CONFIG_RESPONSE_STATUS   /*!< List of Status messages returned from CommitDataResponse */
{
  ULTRASONIC_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_FAIL                      = 0x00U,
  ULTRASONIC_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_SUCCESS                   = 0x01U,
} ULTRASONIC_MSG_CONFIG_RESPONSE_STATUS_E;

typedef enum tagULTRASONIC_MSG_CONFIG_RESPONSE_ERROR_CODE   /*!< List of ErrorCode messages returned from CommitDataResponse */
{
  ULTRASONIC_MSG_CONFIG_RESPONSE_ERROR_CODE_0     = 0x00U,
  ULTRASONIC_MSG_CONFIG_RESPONSE_ERROR_CODE_FF    = 0xFFU
} ULTRASONIC_MSG_CONFIG_RESPONSE_ERROR_CODE_E;

/******************************** Typedefs *********************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/******************************** General Msg *********************************/

/* PROPA Messages */
typedef struct tagULTRASONIC_MSG_P151
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  Byte3;
    uint8_t  Byte4;
    uint8_t  Byte5;
    uint8_t  Byte6;
    uint8_t  Byte7;
    uint8_t  Byte8;
} ULTRASONIC_MSG_P151_T;

// ----------------------------------------------------------------- // 

typedef struct tagULTRASONIC_MSG_P151_GET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from ULTRASONIC_PARAMETERS_E*/
    uint32_t Rvd1;
} ULTRASONIC_MSG_P151_GET_PARAMETER_T;

typedef struct tagULTRASONIC_MSG_P151_GET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from ULTRASONIC_PARAMETERS_E*/
    real32_T ParameterValue;
} ULTRASONIC_MSG_P151_GET_PARAMETER_RESPONSE_T;

// ----------------------------------------------------------------- // 

typedef struct tagULTRASONIC_MSG_P151_SET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from ULTRASONIC_PARAMETERS_E*/
    real32_T ParameterValue;
} ULTRASONIC_MSG_P151_SET_PARAMETER_T;

typedef struct tagULTRASONIC_MSG_P151_SET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from ULTRASONIC_PARAMETERS_E*/
    real32_T ParameterValue;
} ULTRASONIC_MSG_P151_SET_PARAMETER_RESPONSE_T;

// ----------------------------------------------------------------- // 

typedef struct tagULTRASONIC_P151_MSG_RESTORE_DEFAULTS
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5C --> ULTRASONIC_MSG_RESTORE_DEFAULTS_CHECK_VALUE*/
    uint8_t  Command;        /* Value from ULTRASONIC_MSG_RESTORE_DEFAULTS_COMMAND_E*/
    uint32_t Rvd2;
} ULTRASONIC_MSG_P151_RESTORE_DEFAULTS_T;

typedef struct tagULTRASONIC_P151_MSG_RESTORE_DEFAULTS_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  RestoreStatus;   /* Value from ULTRASONIC_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} ULTRASONIC_MSG_P151_RESTORE_DEFAULTS_RESPONSE_T;

// ----------------------------------------------------------------- // 

//Apply current configuration
typedef struct tagULTRASONIC_P151_MSG_CONFIG
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5A --> ULTRASONIC_MSG_CONFIG_CHECK_VALUE*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} ULTRASONIC_MSG_P151_CONFIG_T;

typedef struct tagULTRASONIC_MSG_P151_CONFIG_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CommitStatus;       /* Value from ULTRASONIC_MSG_CONFIG_RESPONSE_STATUS_E*/
    uint16_t CommitErrorCode;    /* Value from ULTRASONIC_MSG_CONFIG_RESPONSE_ERROR_CODE_E*/
    uint8_t  Rvd1;
    uint16_t Rvd2;
} ULTRASONIC_MSG_P151_CONFIG_RESPONSE_T;

// ----------------------------------------------------------------- // 

typedef union tagULTRASONIC_MSG_P151_U
{
    ULTRASONIC_MSG_P151_T                           	ULTRASONIC_MSG_P151;
    ULTRASONIC_MSG_P151_GET_PARAMETER_T             	ULTRASONIC_MSG_P151_GET_PARAMETER;
    ULTRASONIC_MSG_P151_GET_PARAMETER_RESPONSE_T    	ULTRASONIC_MSG_P151_GET_PARAMETER_RESPONSE;
    ULTRASONIC_MSG_P151_SET_PARAMETER_T             	ULTRASONIC_MSG_P151_SET_PARAMETER;
    ULTRASONIC_MSG_P151_SET_PARAMETER_RESPONSE_T    	ULTRASONIC_MSG_P151_SET_PARAMETER_RESPONSE;
    ULTRASONIC_MSG_P151_RESTORE_DEFAULTS_T          	ULTRASONIC_MSG_P151_RESTORE_DEFAULTS;
    ULTRASONIC_MSG_P151_RESTORE_DEFAULTS_RESPONSE_T 	ULTRASONIC_MSG_P151_RESTORE_DEFAULTS_RESPONSE;
    ULTRASONIC_MSG_P151_CONFIG_T             		    ULTRASONIC_MSG_P151_CONFIG;
    ULTRASONIC_MSG_P151_CONFIG_RESPONSE_T    		    ULTRASONIC_MSG_P151_CONFIG_RESPONSE;
} ULTRASONIC_MSG_P151_U;

#endif /* end PROPA_ULTRASONIC_CANMSG_H */

/* End of $Workfile: PROPA_ULTRASONIC_canmsg.h$ */
