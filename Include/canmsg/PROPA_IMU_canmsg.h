/*******************************************************************************
** $Revision: 0$
** $Date: 17/05/2018 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PROPA_IMU_CANMSG_H
#define PROPA_IMU_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define IMU_MSG_PAGE								 (140U)

#define IMU_MSG_XID_GET_PARAMETER                    (0xA0U)
#define IMU_MSG_XID_GET_PARAMETER_RESPONSE           (0xA1U)
#define IMU_MSG_XID_SET_PARAMETER                    (0xA2U)
#define IMU_MSG_XID_SET_PARAMETER_RESPONSE           (0xA3U)
#define IMU_MSG_XID_RESTORE_DEFAULTS                 (0xA4U)
#define IMU_MSG_XID_RESTORE_DEFAULTS_RESPONSE        (0xA5U)
#define IMU_MSG_XID_COMMIT_DATA                      (0xA6U)
#define IMU_MSG_XID_COMMIT_DATA_RESPONSE             (0xA7U)

#define IMU_MSG_RESTORE_DEFAULTS_CHECK_VALUE         (0x5CU)
#define IMU_MSG_COMMIT_DATA_CHECK_VALUE              (0x5AU)

/******************************** Enums *********************************/

typedef enum tagIMU_PARAMETERS   /*!< List of IMU Parameters accessible with Get_Parameter/Set_Parameter */
{
  /* Module Parameters */
//  IMU_PARAMETER_HW_ID    			= 0x0000U,    /*!< IMU Hardware ID */
//  IMU_PARAMETER_SERIAL_NUMBER   	= 0x0001U,    /*!< IMU Serial Number */
  IMU_PARAMETER_MOUNTING_POSITION   = 0x0010U,    /*!< IMU Mounting Position */
  IMU_PARAMETER_MOUNTING_QUATERNION_QW  = 0x0020U,    /*!< IMU Mounting Position Quaternion - Re. part */
  IMU_PARAMETER_MOUNTING_QUATERNION_QX  = 0x0021U,    /*!< IMU Mounting Position Quaternion - Im. part along Axis X */
  IMU_PARAMETER_MOUNTING_QUATERNION_QY  = 0x0022U,    /*!< IMU Mounting Position Quaternion - Im. part along Axis Y */
  IMU_PARAMETER_MOUNTING_QUATERNION_QZ  = 0x0023U,    /*!< IMU Mounting Position Quaternion - Im. part along Axis Z */
  IMU_PARAMETER_MOUNTING_QUATERNION_END = 0x0024U,    /*!< Signal IMU Mounting Position Quaternion transfer end */
  /* Temperature */
  IMU_PARAMETER_TEMPERATURE			= 0x0100U,    /*!< IMU Temperature */
  IMU_PARAMETER_TEMPERATURE_AX		= 0x0101U,    /*!< X Accelerometer Temperature */
  IMU_PARAMETER_TEMPERATURE_AY		= 0x0102U,    /*!< Y Accelerometer Temperature */
  IMU_PARAMETER_TEMPERATURE_AZ		= 0x0103U,    /*!< Z Accelerometer Temperature */
  IMU_PARAMETER_TEMPERATURE_GP		= 0x0104U,    /*!< PitchRate Gyroscope Temperature */
  IMU_PARAMETER_TEMPERATURE_GR		= 0x0105U,    /*!< RollRate Gyroscope Temperature */
  IMU_PARAMETER_TEMPERATURE_GY		= 0x0106U,    /*!< YawRate Gyroscope Temperature */
  /* Time */
//  IMU_PARAMETER_TIMESTAMP			= 0x0110U,    /*!< IMU Timestamp */
  /* Accelerometer Gain */
  IMU_PARAMETER_ACC_GXX				= 0x0210U,    /*!< X Accelerometer Gain */
//  IMU_PARAMETER_ACC_GXY				= 0x0211U,    /*!< X-Y Accelerometer Cross-Gain */
//  IMU_PARAMETER_ACC_GXZ				= 0x0212U,    /*!< X-Z Accelerometer Cross-Gain */
//  IMU_PARAMETER_ACC_GYX				= 0x0213U,    /*!< Y-X Accelerometer Cross-Gain */
  IMU_PARAMETER_ACC_GYY				= 0x0214U,    /*!< Y Accelerometer Gain */
//  IMU_PARAMETER_ACC_GYZ				= 0x0215U,    /*!< Y-Z Accelerometer Cross-Gain */
//  IMU_PARAMETER_ACC_GZX				= 0x0216U,    /*!< Z-X Accelerometer Cross-Gain */
//  IMU_PARAMETER_ACC_GZY				= 0x0217U,    /*!< Z-Y Accelerometer Cross-Gain */
  IMU_PARAMETER_ACC_GZZ				= 0x0218U,    /*!< Z Accelerometer Gain */
  /* Accelerometer Offset */  
//  IMU_PARAMETER_ACC_OXT1			= 0x0220U,    /*!< X Accelerometer Offset - Quadratic temperature coefficient */
//  IMU_PARAMETER_ACC_OXT2			= 0x0221U,    /*!< X Accelerometer Offset - Linear temperature coefficient */
  IMU_PARAMETER_ACC_OXT3			= 0x0222U,    /*!< X Accelerometer Offset - Constant coefficient */
//  IMU_PARAMETER_ACC_OYT1			= 0x0223U,    /*!< Y Accelerometer Offset - Quadratic temperature coefficient */
//  IMU_PARAMETER_ACC_OYT2			= 0x0224U,    /*!< Y Accelerometer Offset - Linear temperature coefficient */
  IMU_PARAMETER_ACC_OYT3			= 0x0225U,    /*!< Y Accelerometer Offset - Constant coefficient */
//  IMU_PARAMETER_ACC_OZT1			= 0x0226U,    /*!< Z Accelerometer Offset - Quadratic temperature coefficient */
//  IMU_PARAMETER_ACC_OZT2			= 0x0227U,    /*!< Z Accelerometer Offset - Linear temperature coefficient */
  IMU_PARAMETER_ACC_OZT3			= 0x0228U,    /*!< Z Accelerometer Offset - Constant coefficient */
  /* Gyroscope Gain */
//  IMU_PARAMETER_GYR_GPP				= 0x0310U,    /*!< PitchRate Gyroscope Gain */
//  IMU_PARAMETER_GYR_GPR				= 0x0311U,    /*!< PitchRate-RollRate Gyroscope Cross-Gain */
//  IMU_PARAMETER_GYR_GPY				= 0x0312U,    /*!< PitchRate-YawRate Gyroscope Cross-Gain */
//  IMU_PARAMETER_GYR_GRP				= 0x0313U,    /*!< RollRate-PitchRate Gyroscope Cross-Gain */
//  IMU_PARAMETER_GYR_GRR				= 0x0314U,    /*!< RollRate Gyroscope Gain */
//  IMU_PARAMETER_GYR_GRY				= 0x0315U,    /*!< RollRate-YawRate Gyroscope Cross-Gain */
//  IMU_PARAMETER_GYR_GYP				= 0x0316U,    /*!< YawRate-PitchRate Gyroscope Cross-Gain */
//  IMU_PARAMETER_GYR_GYR				= 0x0317U,    /*!< YawRate-RollRate Gyroscope Cross-Gain */
//  IMU_PARAMETER_GYR_GYY				= 0x0318U,    /*!< YawRate Gyroscope Gain */
  /* Gyroscope Offset*/  
  IMU_PARAMETER_GYR_OPT1			= 0x0320U,    /*!< PitchRate Gyroscope Offset - Quadratic temperature coefficient */
  IMU_PARAMETER_GYR_OPT2			= 0x0321U,    /*!< PitchRate Gyroscope Offset - Linear temperature coefficient */
  IMU_PARAMETER_GYR_OPT3			= 0x0322U,    /*!< PitchRate Gyroscope Offset - Constant coefficient */
  IMU_PARAMETER_GYR_ORT1			= 0x0323U,    /*!< RollRate Gyroscope Offset - Quadratic temperature coefficient */
  IMU_PARAMETER_GYR_ORT2			= 0x0324U,    /*!< RollRate Gyroscope Offset - Linear temperature coefficient */
  IMU_PARAMETER_GYR_ORT3			= 0x0325U,    /*!< RollRate Gyroscope Offset - Constant coefficient */
  IMU_PARAMETER_GYR_OYT1			= 0x0326U,    /*!< YawRate Gyroscope Offset - Quadratic temperature coefficient */
  IMU_PARAMETER_GYR_OYT2			= 0x0327U,    /*!< YawRate Gyroscope Offset - Linear temperature coefficient */
  IMU_PARAMETER_GYR_OYT3			= 0x0328U,    /*!< YawRate Gyroscope Offset - Constant coefficient */
} IMU_PARAMETERS_E;


typedef enum tagIMU_MSG_RESTORE_DEFAULTS_COMMAND_E   /*!< List of Commands for RestoreDefaults */
{
  IMU_MSG_RESTORE_DEFAULTS_COMMAND_ACC      = 0x00U,     /*!< Restore accelerometer parameters */
  IMU_MSG_RESTORE_DEFAULTS_COMMAND_GYR      = 0x01U,     /*!< Restore gyroscope parameters */
  IMU_MSG_RESTORE_DEFAULTS_COMMAND_FULL     = 0xFFU      /*!< Restore all parameters */
} IMU_MSG_RESTORE_DEFAULTS_COMMAND_E;

typedef enum tagIMU_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS   /*!< List of Status messages returned from RestoreDefaultsResponse */
{
  IMU_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_FAIL        = 0x00U,    /*!< RestoreDefaults failed */
  IMU_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_SUCCESS     = 0xFFU     /*!< RestoreDefaults succeeded */
} IMU_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E;

typedef enum tagIMU_MSG_COMMIT_DATA_RESPONSE_STATUS   /*!< List of Status messages returned from CommitDataResponse */
{
  IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_READY_TO_COMMIT                  = 0x00U,
  IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_BEGUN                     = 0x01U,
  IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_SUCCESS                   = 0x02U,
  IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_FAIL                      = 0x03U,
  IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_PARAMETER_CHECK_FAIL             = 0x04U,
  IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_ALREADY_IN_PROGRESS       = 0x05U
} IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_E;

typedef enum tagIMU_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE   /*!< List of ErrorCode messages returned from CommitDataResponse */
{
  IMU_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_0     = 0x00U,
  IMU_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_FF    = 0xFFU
} IMU_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_E;

/******************************** Typedefs *********************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/******************************** General Msg *********************************/

/* PROPA Messages */
typedef struct tagIMU_MSG_P140
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  Byte3;
    uint8_t  Byte4;
    uint8_t  Byte5;
    uint8_t  Byte6;
    uint8_t  Byte7;
    uint8_t  Byte8;
} IMU_MSG_P140_T;

typedef struct tagIMU_MSG_P140_GET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from IMU_PARAMETERS_E*/
    uint32_t Rvd1;
} IMU_MSG_P140_GET_PARAMETER_T;

typedef struct tagIMU_MSG_P140_GET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from IMU_PARAMETERS_E*/
    real32_T ParameterValue;
} IMU_MSG_P140_GET_PARAMETER_RESPONSE_T;

typedef struct tagIMU_MSG_P140_SET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from IMU_PARAMETERS_E*/
    real32_T ParameterValue;
} IMU_MSG_P140_SET_PARAMETER_T;

typedef struct tagIMU_MSG_P140_SET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;     /* Value from IMU_PARAMETERS_E*/
    real32_T ParameterValue;
} IMU_MSG_P140_SET_PARAMETER_RESPONSE_T;

typedef struct tagIMU_P140_MSG_RESTORE_DEFAULTS
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5C */
    uint8_t  Command;        /* Value from IMU_MSG_RESTORE_DEFAULTS_COMMAND_E*/
    uint32_t Rvd2;
} IMU_MSG_P140_RESTORE_DEFAULTS_T;

typedef struct tagIMU_P140_MSG_RESTORE_DEFAULTS_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  RestoreStatus;   /* Value from IMU_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} IMU_MSG_P140_RESTORE_DEFAULTS_RESPONSE_T;

typedef struct tagIMU_P140_MSG_COMMIT_DATA
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CheckValue;     /* 0x5A */
    uint8_t  Rvd1;
    uint32_t Rvd2;
} IMU_MSG_P140_COMMIT_DATA_T;

typedef struct tagIMU_MSG_P140_COMMIT_DATA_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  CommitStatus;       /* Value from IMU_MSG_COMMIT_DATA_RESPONSE_STATUS_E*/
    uint16_t CommitErrorCode;    /* Value from IMU_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_E*/
    uint8_t  Rvd1;
    uint16_t Rvd2;
} IMU_MSG_P140_COMMIT_DATA_RESPONSE_T;

typedef union tagIMU_MSG_P140_U
{
    IMU_MSG_P140_T                           	IMU_MSG_P140;
    IMU_MSG_P140_GET_PARAMETER_T             	IMU_MSG_P140_GET_PARAMETER;
    IMU_MSG_P140_GET_PARAMETER_RESPONSE_T    	IMU_MSG_P140_GET_PARAMETER_RESPONSE;
    IMU_MSG_P140_SET_PARAMETER_T             	IMU_MSG_P140_SET_PARAMETER;
    IMU_MSG_P140_SET_PARAMETER_RESPONSE_T    	IMU_MSG_P140_SET_PARAMETER_RESPONSE;
    IMU_MSG_P140_RESTORE_DEFAULTS_T          	IMU_MSG_P140_RESTORE_DEFAULTS;
    IMU_MSG_P140_RESTORE_DEFAULTS_RESPONSE_T 	IMU_MSG_P140_RESTORE_DEFAULTS_RESPONSE;
    IMU_MSG_P140_COMMIT_DATA_T             		IMU_MSG_P140_COMMIT_DATA;
    IMU_MSG_P140_COMMIT_DATA_RESPONSE_T    		IMU_MSG_P140_COMMIT_DATA_RESPONSE;
} IMU_MSG_P140_U;

#endif /* end PROPA_IMU_CANMSG_H */

/* End of $Workfile: PROPA_IMU_canmsg.h$ */
