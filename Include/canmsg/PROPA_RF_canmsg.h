/*******************************************************************************
** $Revision: 0$
** $Date: 17/05/2018 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PROPA_RF_CANMSG_H
#define PROPA_RF_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define RF_MSG_PAGE								 (150U)

#define RF_MSG_XID_GET_PARAMETER                    (0xA0U)
#define RF_MSG_XID_GET_PARAMETER_RESPONSE           (0xA1U)
#define RF_MSG_XID_SET_PARAMETER                    (0xA2U)
#define RF_MSG_XID_SET_PARAMETER_RESPONSE           (0xA3U)
#define RF_MSG_XID_RESTORE_DEFAULTS                 (0xA4U)
#define RF_MSG_XID_RESTORE_DEFAULTS_RESPONSE        (0xA5U)
#define RF_MSG_XID_CONFIG                           (0xA6U)
#define RF_MSG_XID_CONFIG_RESPONSE                  (0xA7U)

#define RF_MSG_RESTORE_DEFAULTS_CHECK_VALUE         (0x5CU)
#define RF_MSG_CONFIG_CHECK_VALUE                   (0x5AU)

/******************************** Enums *********************************/

typedef enum tagRF_PARAMETERS   /*!< List of RF Parameters accessible with Get_Parameter/Set_Parameter */
{
  /* Module Parameters */
  RF_AUTOBAUD_PARAMETER   		= 0x0200U,    /*!< RF autobaud status*/
  RF_CHANNEL_PARAMETER   	    = 0x0201U,    /*!< RF channel*/
  RF_TIMEOUT_PARAMETER   		= 0x0202U,    /*!< RF timeout for heartbeat*/
  RF_INIT_CHANNEL               = 0x0203U,    /*!< RF set savedFrequency*/
    
  /* RF linked addresses */  
  RF_ADDRESS_PARAMETER_POS0		= 0x0100U,    /*!< RF Address position 0 (master)*/
  RF_ADDRESS_PARAMETER_POS1		= 0x0101U,    /*!< RF Address position 1 (slave)*/
  RF_ADDRESS_PARAMETER_POS2		= 0x0102U,    /*!< RF Address position 2 (slave)*/
  RF_ADDRESS_PARAMETER_POS3		= 0x0103U,    /*!< RF Address position 3 (slave)*/
  RF_ADDRESS_PARAMETER_POS4		= 0x0104U,    /*!< RF Address position 4 (slave)*/
  RF_ADDRESS_PARAMETER_POS5		= 0x0105U,    /*!< RF Address position 5 (slave)*/
  RF_ADDRESS_PARAMETER_POS6		= 0x0106U,    /*!< RF Address position 6 (slave)*/
  RF_ADDRESS_PARAMETER_POS7		= 0x0107U,    /*!< RF Address position 7 (slave)*/
  RF_ADDRESS_PARAMETER_POS8		= 0x0108U,    /*!< RF Address position 8 (slave)*/
  RF_ADDRESS_PARAMETER_POS9		= 0x0109U,    /*!< RF Address position 9 (slave)*/
    
  /* RF linked addresses */  
  RF_TIMEOUT_PARAMETER_POS0		= 0x0150U,    /*!< RF Address position 0 (master)*/
//  RF_BTN_ENABLE_PARAMETER_POS1		= 0x0151U,    /*!< RF Address position 1 (slave)*/
//  RF_BTN_ENABLE_PARAMETER_POS2		= 0x0152U,    /*!< RF Address position 2 (slave)*/
//  RF_BTN_ENABLE_PARAMETER_POS3		= 0x0153U,    /*!< RF Address position 3 (slave)*/
//  RF_BTN_ENABLE_PARAMETER_POS4		= 0x0154U,    /*!< RF Address position 4 (slave)*/

  /* RF linked addresses */  
  RF_BUTTON_PARAMETER_POS0		= 0x0160U,    /*!< RF Address position 0 (master)*/



} RF_PARAMETERS_E;


typedef enum tagRF_MSG_RESTORE_DEFAULTS_COMMAND_E   /*!< List of Commands for RestoreDefaults */
{
  //IMU_MSG_RESTORE_DEFAULTS_COMMAND_ACC      = 0x00U,     /*!< Restore accelerometer parameters */
  //IMU_MSG_RESTORE_DEFAULTS_COMMAND_GYR      = 0x01U,     /*!< Restore gyroscope parameters */
  RF_MSG_RESTORE_DEFAULTS_COMMAND_FULL     = 0xFFU      /*!< Restore all parameters */
} RF_MSG_RESTORE_DEFAULTS_COMMAND_E;

typedef enum tagRF_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS   /*!< List of Status messages returned from RestoreDefaultsResponse */
{
  RF_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_FAIL        = 0x00U,    /*!< RestoreDefaults failed */
  RF_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_SUCCESS     = 0xFFU     /*!< RestoreDefaults succeeded */
} RF_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E;

typedef enum tagRF_MSG_CONFIG_RESPONSE_STATUS   /*!< List of Status messages returned from CommitDataResponse */
{
  RF_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_FAIL                      = 0x00U,
  RF_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_SUCCESS                   = 0x01U,
} RF_MSG_CONFIG_RESPONSE_STATUS_E;

typedef enum tagRF_MSG_CONFIG_RESPONSE_ERROR_CODE   /*!< List of ErrorCode messages returned from CommitDataResponse */
{
  RF_MSG_CONFIG_RESPONSE_ERROR_CODE_0     = 0x00U,
  RF_MSG_CONFIG_RESPONSE_ERROR_CODE_FF    = 0xFFU
} RF_MSG_CONFIG_RESPONSE_ERROR_CODE_E;

/******************************** Typedefs *********************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/******************************** General Msg *********************************/

/* PROPA Messages */
typedef struct tagRF_MSG_P150
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  Byte3;
    uint8_t  Byte4;
    uint8_t  Byte5;
    uint8_t  Byte6;
    uint8_t  Byte7;
    uint8_t  Byte8;
} RF_MSG_P150_T;

// ----------------------------------------------------------------- // 

typedef struct tagRF_MSG_P150_GET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from RF_PARAMETERS_E*/
    uint32_t Rvd1;
} RF_MSG_P150_GET_PARAMETER_T;

typedef struct tagRF_MSG_P150_GET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from RF_PARAMETERS_E*/
    real32_T ParameterValue;
} RF_MSG_P150_GET_PARAMETER_RESPONSE_T;

// ----------------------------------------------------------------- // 

typedef struct tagRF_MSG_P150_SET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from RF_PARAMETERS_E*/
    real32_T ParameterValue;
} RF_MSG_P150_SET_PARAMETER_T;

typedef struct tagRF_MSG_P150_SET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from RF_PARAMETERS_E*/
    real32_T ParameterValue;
} RF_MSG_P150_SET_PARAMETER_RESPONSE_T;

// ----------------------------------------------------------------- // 

typedef struct tagRF_P150_MSG_RESTORE_DEFAULTS
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5C --> RF_MSG_RESTORE_DEFAULTS_CHECK_VALUE*/
    uint8_t  Command;        /* Value from RF_MSG_RESTORE_DEFAULTS_COMMAND_E*/
    uint32_t Rvd2;
} RF_MSG_P150_RESTORE_DEFAULTS_T;

typedef struct tagRF_P150_MSG_RESTORE_DEFAULTS_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  RestoreStatus;   /* Value from RF_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} RF_MSG_P150_RESTORE_DEFAULTS_RESPONSE_T;

// ----------------------------------------------------------------- // 

//Apply current configuration
typedef struct tagRF_P150_MSG_CONFIG
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5A --> RF_MSG_CONFIG_CHECK_VALUE*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} RF_MSG_P150_CONFIG_T;

typedef struct tagRF_MSG_P150_CONFIG_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CommitStatus;       /* Value from RF_MSG_CONFIG_RESPONSE_STATUS_E*/
    uint16_t CommitErrorCode;    /* Value from RF_MSG_CONFIG_RESPONSE_ERROR_CODE_E*/
    uint8_t  Rvd1;
    uint16_t Rvd2;
} RF_MSG_P150_CONFIG_RESPONSE_T;

// ----------------------------------------------------------------- // 

typedef union tagRF_MSG_P150_U
{
    RF_MSG_P150_T                           	RF_MSG_P150;
    RF_MSG_P150_GET_PARAMETER_T             	RF_MSG_P150_GET_PARAMETER;
    RF_MSG_P150_GET_PARAMETER_RESPONSE_T    	RF_MSG_P150_GET_PARAMETER_RESPONSE;
    RF_MSG_P150_SET_PARAMETER_T             	RF_MSG_P150_SET_PARAMETER;
    RF_MSG_P150_SET_PARAMETER_RESPONSE_T    	RF_MSG_P150_SET_PARAMETER_RESPONSE;
    RF_MSG_P150_RESTORE_DEFAULTS_T          	RF_MSG_P150_RESTORE_DEFAULTS;
    RF_MSG_P150_RESTORE_DEFAULTS_RESPONSE_T 	RF_MSG_P150_RESTORE_DEFAULTS_RESPONSE;
    RF_MSG_P150_CONFIG_T             		      RF_MSG_P150_CONFIG;
    RF_MSG_P150_CONFIG_RESPONSE_T    		      RF_MSG_P150_CONFIG_RESPONSE;
} RF_MSG_P150_U;

#endif /* end PROPA_RF_CANMSG_H */

/* End of $Workfile: PROPA_RF_canmsg.h$ */
