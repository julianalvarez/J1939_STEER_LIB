/*******************************************************************************
** $Revision: 0$
** $Date: 9/03/2017 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PVED_CANMSG_H
#define PVED_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define PVECL_SOURCE_ADDRESS_CONTROLER              (28U)

#define PGN_GUIDANCE_SYSTEM_COMMAND                 44288U //(0xAD00)
#define SIZE_GUIDANCE_SYSTEM_COMMAND                8U
#define PGN_GUIDANCE_MACHINE_STATUS                 44032U //(0xAC00)
#define SIZE_GUIDANCE_MACHINE_STATUS                8U
#define PGN_VEHICLE_SPEED_SENSOR                    65265U //(0xFEF1)
#define SIZE_VEHICLE_SPEED_SENSOR                   8U

#define SOURCE_ADDRES_VEHICLE_SPEED_SENSOR          251U   //(0xFB)

#define PGN_PVED_PROPIETARY_B                       65280U //0xFF00
#define PGN_PVED_OFFSET_BASE                        230U   //0xE6
#define PGN_PVED_STATUS                             (PGN_PVED_PROPIETARY_B + 0U) 
#define PGN_PVED_STATUS_SEND                        (PGN_PVED_STATUS + PGN_PVED_OFFSET_BASE) 
#define SIZE_PVED_STATUS                            8U
#define PGN_PVED_OPERATION_STATUS                   (PGN_PVED_PROPIETARY_B + 1U)
#define PGN_PVED_OPERATION_STATUS_SEND              (PGN_PVED_OPERATION_STATUS + PGN_PVED_OFFSET_BASE)
#define SIZE_PVED_OPERATION_STATUS                  8U
#define PGN_PVED_TIME_REPORT                        (PGN_PVED_PROPIETARY_B + 2U)
#define PGN_PVED_TIME_REPORT_SEND                   (PGN_PVED_TIME_REPORT + PGN_PVED_OFFSET_BASE)
#define SIZE_PVED_TIME_REPORT                       8U

// <PVED Configuration Tool>
#define PVED_MSG_XID_GET_PARAMETER                    0xA00FU
#define PVED_MSG_XID_GET_PARAMETER_RESPONSE           0xA10FU
#define PVED_MSG_XID_SET_PARAMETER                    0xA20FU
#define PVED_MSG_XID_SET_PARAMETER_RESPONSE           0xA30FU
#define PVED_MSG_XID_RESTORE_DEFAULTS                 0xA40FU
#define PVED_MSG_XID_RESTORE_DEFAULTS_RESPONSE        0xA50FU
#define PVED_MSG_XID_COMMIT_DATA                      0xA60FU
#define PVED_MSG_XID_COMMIT_DATA_RESPONSE             0xA70FU
#define PVED_MSG_XID_ENTER_CALIBRATION_MODE           0xA80FU
#define PVED_MSG_XID_GET_CURRENT_MODE                 0xA90FU
#define PVED_MSG_XID_GET_CURRENT_MODE_RESPONSE        0xAA0FU
#define PVED_MSG_XID_START_STOP_STATUS                0xAB0FU
//STATUS
#define PVED_MSG_XID_START_STOP_OPERATION_STATUS      0xAC0FU
//OPERATIONSTATUS
//TIMEREPORT
#define PVED_MSG_XID_SET_SPOOL_POSITION               0xAD0FU
#define PVED_MSG_XID_SET_FLOW                         0xB80FU

// <MMI>
#define PVED_MSG_XID_START_VALVE_AUTO_CALIBRATION     0xB60FU
#define PVED_MSG_XID_VALVE_AUTO_CALIBRATION_STATUS    0xB70FU
#define PVED_MSG_XID_SELECT_PROGRAM                   0xAE0FU
#define PVED_MSG_XID_SELECT_PROGRAM_RESPONSE          0xAF0FU
#define PVED_MSG_XID_DISABLE_STEERING_DEVICE          0xB00FU
#define PVED_MSG_XID_DISABLE_STEERING_DEVICE_RESPONSE 0xB10FU

/******************************** Enums *********************************/
typedef enum tagPVED_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS   /*!< List of Status messages returned from RestoreDefaultsResponse */
{
  PVED_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_FAIL        = 0x00U,    /*!< RestoreDefaults failed */
  PVED_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_SUCCESS     = 0xFFU     /*!< RestoreDefaults succeeded */
} PVED_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E;

typedef enum tagPVED_MSG_COMMIT_DATA_RESPONSE_STATUS   /*!< List of Status messages returned from CommitDataResponse */
{
  PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_READY_TO_COMMIT                  = 0x00U,
  PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_BEGUN                     = 0x01U,
  PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_SUCCESS                   = 0x02U,
  PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_FAIL                      = 0x03U,
  PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_PARAMETER_CHECK_FAIL             = 0x04U,
  PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_COMMIT_ALREADY_IN_PROGRESS       = 0x05U
} PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_E;

typedef enum tagPVED_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE   /*!< List of ErrorCode messages returned from CommitDataResponse */
{
  PVED_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_0    = 0x00U,
  PVED_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_FF    = 0xFFU,
} PVED_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_E;

typedef enum tagPVED_MSG_START_STOP_STATUS_STATUS_RQST   /*!< List of StatusRqst messages sent in StartStopStatus */
{
  PVED_MSG_START_STOP_STATUS_STATUS_RQST_STOP    = 0x00U,
  PVED_MSG_START_STOP_STATUS_STATUS_RQST_SET1    = 0x01U,
  PVED_MSG_START_STOP_STATUS_STATUS_RQST_SET2    = 0x02U,
  PVED_MSG_START_STOP_STATUS_STATUS_RQST_SET3    = 0x03U,
  PVED_MSG_START_STOP_STATUS_STATUS_RQST_SET4    = 0x04U
} PVED_MSG_START_STOP_STATUS_STATUS_RQST_E;

typedef enum tagPVED_MSG_START_STOP_OPERATION_STATUS_STATUS_RQST   /*!< List of StatusRqst messages sent in StartStopOperationStatus */
{
  PVED_MSG_START_STOP_OPERATION_STATUS_STATUS_RQST_STOP    = 0x00U,
  PVED_MSG_START_STOP_OPERATION_STATUS_STATUS_RQST_START   = 0xFFU
} PVED_MSG_START_STOP_OPERATION_STATUS_STATUS_RQST_E;

typedef enum tagPVED_MSG_OPERATION_STATUS_CURRENT_MODE   /*!< List of Current Mode messages returned from Operation Status */
{
  PVED_MSG_OPERATION_STATUS_CURRENT_MODE_OPERATIONAL                = 0xAAU,
  PVED_MSG_OPERATION_STATUS_CURRENT_MODE_REDUCED                    = 0xAFU,
  PVED_MSG_OPERATION_STATUS_CURRENT_MODE_FAULT                      = 0xFFU
} PVED_MSG_OPERATION_STATUS_CURRENT_MODE_E;

typedef enum tagPVED_MSG_OPERATION_STATUS_SELECTED_DEVICE   /*!< List of Selected Device messages returned from Operation Status */
{
  PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_NO_DEVICE                   = 0x00U,
  PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_STEERING_WHEEL              = 0x01U,
  PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_RESERVED                    = 0x02U,
  PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_HPSD                        = 0x03U,
  PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_LPSD                        = 0x04U,
  PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_HPESPC                      = 0x05U
} PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_E;

typedef enum tagPVED_GUIDANCE_SYSTEM_COMMAND_STEERING_COMMAND_STATUS   /*!< List of Steering Command Status in Guidance System Command */
{
  PVED_GUIDANCE_SYSTEM_COMMAND_STEERING_COMMAND_STATUS_NOT_INTENDED_FOR_STEERING    = 0x0U,
  PVED_GUIDANCE_SYSTEM_COMMAND_STEERING_COMMAND_STATUS_INTENDED_FOR_STEERING        = 0x1U,
  PVED_GUIDANCE_SYSTEM_COMMAND_STEERING_COMMAND_STATUS_ERROR_INDICATION             = 0x2U,
  PVED_GUIDANCE_SYSTEM_COMMAND_STEERING_COMMAND_STATUS_NOT_AVAILABLE                = 0x3U,
} PVED_GUIDANCE_SYSTEM_COMMAND_STEERING_COMMAND_STATUS_E;

typedef enum tagPVED_GUIDANCE_MACHINE_STATUS_REQUEST_RESET_COMMAND_STATUS   /*!< List of Reset Command Status in Machine Status */
{
  PVED_GUIDANCE_MACHINE_STATUS_REQUEST_RESET_COMMAND_STATUS_RESET_NOT_REQUIRED          = 0x0U,
  PVED_GUIDANCE_MACHINE_STATUS_REQUEST_RESET_COMMAND_STATUS_RESET_REQUIRED              = 0x1U,
  PVED_GUIDANCE_MACHINE_STATUS_REQUEST_RESET_COMMAND_STATUS_ERROR_INDICATION            = 0x2U,
  PVED_GUIDANCE_MACHINE_STATUS_REQUEST_RESET_COMMAND_STATUS_NOT_AVAILABLE               = 0x3U,
} PVED_GUIDANCE_MACHINE_STATUS_REQUEST_RESET_COMMAND_STATUS_E;

typedef enum tagPVED_GUIDANCE_MACHINE_STATUS_INPUT_POSITION_STATUS   /*!< List of Input Position Status in Machine Status */
{
  PVED_GUIDANCE_MACHINE_STATUS_INPUT_POSITION_STATUS_INCORRECT_POSITION          = 0x0U,
  PVED_GUIDANCE_MACHINE_STATUS_INPUT_POSITION_STATUS_CORRECT_POSITION            = 0x1U,
  PVED_GUIDANCE_MACHINE_STATUS_INPUT_POSITION_STATUS_ERROR_INDICATION            = 0x2U,
  PVED_GUIDANCE_MACHINE_STATUS_INPUT_POSITION_STATUS_NOT_AVAILABLE               = 0x3U,
} PVED_GUIDANCE_MACHINE_STATUS_INPUT_POSITION_STATUS_E;

typedef enum tagPVED_GUIDANCE_MACHINE_STATUS_MACHINE_COMMANDS_EXECUTION_STATUS   /*!< List of Machine Commands Execution Status in Machine Status */
{
  PVED_GUIDANCE_MACHINE_STATUS_MACHINE_COMMANDS_EXECUTION_STATUS_SYSTEM_IS_NOT_READY         = 0x0U,
  PVED_GUIDANCE_MACHINE_STATUS_MACHINE_COMMANDS_EXECUTION_STATUS_SYSTEM_IS_READY             = 0x1U,
  PVED_GUIDANCE_MACHINE_STATUS_MACHINE_COMMANDS_EXECUTION_STATUS_ERROR_INDICATION            = 0x2U,
  PVED_GUIDANCE_MACHINE_STATUS_MACHINE_COMMANDS_EXECUTION_STATUS_NOT_AVAILABLE               = 0x3U,
} PVED_GUIDANCE_MACHINE_STATUS_MACHINE_COMMANDS_EXECUTION_STATUS_E;

typedef enum tagPVED_GUIDANCE_MACHINE_STATUS_SYSTEM_LOCKOUT_STATUS   /*!< List of System Lockout Status in Machine Status */
{
  PVED_GUIDANCE_MACHINE_STATUS_SYSTEM_LOCKOUT_STATUS_NOT_ACTIVE             = 0x0U,
  PVED_GUIDANCE_MACHINE_STATUS_SYSTEM_LOCKOUT_STATUS_ACTIVE                 = 0x1U,
  PVED_GUIDANCE_MACHINE_STATUS_SYSTEM_LOCKOUT_STATUS_ERROR_INDICATION       = 0x2U,
  PVED_GUIDANCE_MACHINE_STATUS_SYSTEM_LOCKOUT_STATUS_NOT_AVAILABLE          = 0x3U,
} PVED_GUIDANCE_MACHINE_STATUS_SYSTEM_LOCKOUT_STATUS_E;

/******************************** Typedefs *********************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/******************************** General Msg *********************************/

/* PROPA Messages */
typedef struct tagPVED_MSG
{
    uint16_t XID;
    uint8_t  Byte3;
    uint8_t  Byte4;
    uint8_t  Byte5;
    uint8_t  Byte6;
    uint8_t  Byte7;
    uint8_t  Byte8;
} PVED_MSG_T;

typedef struct tagPVED_MSG_GET_PARAMETER
{
    uint16_t XID;
    uint16_t ParameterIndex;     /* Value from PVED_PARAMETERS_E*/
    uint32_t Rvd1;
} PVED_MSG_GET_PARAMETER_T;

typedef struct tagPVED_MSG_GET_PARAMETER_RESPONSE
{
    uint16_t XID;
    uint16_t ParameterIndex;     /* Value from PVED_PARAMETERS_E*/
    uint32_t ParameterValue;
} PVED_MSG_GET_PARAMETER_RESPONSE_T;

typedef struct tagPVED_MSG_SET_PARAMETER
{
    uint16_t XID;
    uint16_t ParameterIndex;     /* Value from PVED_PARAMETERS_E*/
    uint32_t ParameterValue;
} PVED_MSG_SET_PARAMETER_T;

typedef struct tagPVED_MSG_SET_PARAMETER_RESPONSE
{
    uint16_t XID;
    uint16_t ParameterIndex;     /* Value from PVED_PARAMETERS_E*/
    uint32_t ParameterValue;
} PVED_MSG_SET_PARAMETER_RESPONSE_T;

typedef struct tagPVED_MSG_RESTORE_DEFAULTS
{
    uint16_t XID;
    uint8_t  CheckValue;     /* 0x5C */
    uint8_t  Rvd1;
    uint32_t Rvd2;
} PVED_MSG_RESTORE_DEFAULTS_T;

typedef struct tagPVED_MSG_RESTORE_DEFAULTS_RESPONSE
{
    uint16_t XID;
    uint8_t  RestoreStatus;   /* Value from PVED_MSG_RESTORE_DEFAULTS_RESPONSE_STATUS_E*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} PVED_MSG_RESTORE_DEFAULTS_RESPONSE_T;

typedef struct tagPVED_MSG_COMMIT_DATA
{
    uint16_t XID;
    uint8_t  CheckValue;     /* 0x5A */
    uint8_t  Rvd1;
    uint32_t Rvd2;
} PVED_MSG_COMMIT_DATA_T;

typedef struct tagPVED_MSG_COMMIT_DATA_RESPONSE
{
    uint16_t XID;
    uint8_t  CommitStatus;       /* Value from PVED_MSG_COMMIT_DATA_RESPONSE_STATUS_E*/
    uint16_t CommitErrorCode;    /* Value from PVED_MSG_COMMIT_DATA_RESPONSE_ERROR_CODE_E*/
    uint8_t  Rvd1;
    uint16_t Rvd2;
} PVED_MSG_COMMIT_DATA_RESPONSE_T;

typedef struct tagPVED_MSG_ENTER_CALIBRATION_MODE
{
    uint16_t XID;
    uint8_t  CheckValue;     /* 0x58 */
    uint8_t  Rvd1;
    uint32_t Rvd2;
} PVED_MSG_ENTER_CALIBRATION_MODE_T;

typedef struct tagPVED_MSG_START_STOP_STATUS
{
    uint16_t XID;
    uint8_t  StatusRqst;       /* Value from PVED_MSG_START_STOP_STATUS_STATUS_RQST_E*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} PVED_MSG_START_STOP_STATUS_T;

typedef struct tagPVED_MSG_START_STOP_OPERATION_STATUS
{
    uint16_t XID;
    uint8_t  StatusRqst;       /* Value from PVED_MSG_START_STOP_OPERATION_STATUS_STATUS_RQST_E*/
    uint8_t  Rvd1;
    uint32_t Rvd2;
} PVED_MSG_START_STOP_OPERATION_STATUS_T;

/* PROPB Messages */
typedef struct tagPVED_MSG_STATUS_SET1
{
    int16_t     AD1Voltage;     /* Raw value of AD1. 0 -> 1023 reflects 0V -> 5V */
    int16_t     AD2Voltage;     /* Raw value of AD2. 0 -> 1023 reflects 0V -> 5V */
    int16_t     AD3Voltage;     /* Raw value of AD3 (Spool Position). 0 -> 1023 reflects 0V -> 5V */
    int16_t     Xsp;            /* Calculated Spool Position set-point. -1000 -> 1000 reflects -7mm -> 7mm */
} PVED_MSG_STATUS_SET1_T;

typedef struct tagPVED_MSG_STATUS_SET2
{
    int16_t     Yact;               /* Scaled Steering Actuator position. -1000 -> 1000 reflects -100% -> 100% */
    int16_t     Yset;               /* Commanded Actuator Position Set-Point (Closed loop) or Actuator Speed Set-Point (Open-Loop) */
    int16_t     Q;                  /* Port Flow command. -1000 -> 1000 reflects -100% -> 100% */
    uint16_t    SelectedDevice;     /* Selected Device */
} PVED_MSG_STATUS_SET2_T;

typedef struct tagPVED_MSG_STATUS_SET3
{
    int16_t     Xsp;                            /* Calculated Spool Position set-point. -1000 -> 1000 reflects -7mm -> 7mm */
    int16_t     Xpos;                           /* Scaled Spool Position. -1000 -> 1000 reflects -7mm -> 7mm */
    uint16_t    WheelAngle;                     /* Wheel Angle (scaled Yact). 0 -> 2047 -> 4095 reflects Left Endlock -> Pointing Straight Ahead -> Right Endlock */
    uint16_t    Timestamp;                      /* Milliseconds since power-on. Rollover after one minute */
} PVED_MSG_STATUS_SET3_T;

typedef struct tagPVED_MSG_STATUS_SET4
{
    uint16_t   SensorVoltage;                   /* Sensor supply voltage in mV. */
    int16_t    Xpos;                            /* Scaled Spool Position. -1000 -> 1000 reflects -7mm -> 7mm */
    int16_t    ModuleTemp;                      /* PVED-CL Temperature in degC. */
    uint16_t   BatteryVoltage;                  /* Battery supply voltage in mV*/
} PVED_MSG_STATUS_SET4_T;

typedef struct tagPVED_MSG_OPERATION_STATUS
{
    uint8_t     CurrentMode;                    /* Current operation mode. Value from PVED_MSG_OPERATION_STATUS_CURRENT_MODE_E */
    uint8_t     SelectedDevice;                 /* Current selected device. Value from PVED_MSG_OPERATION_STATUS_SELECTED_DEVICE_E */
    uint8_t     ActiveProgram;                  /* Current active program */
    uint8_t     HPSDStatus;                     /* High Priority Steering Device status */
    uint8_t     LPSDStatus;                     /* Low Priority Steering Device status */
    uint8_t     HPESPCStatus;                   /* High Priority External Set-Point Controller status */
    unsigned int RMWheelAngleSensor  :1;        /* Reduced Mode cause by problems with Wheel Angle Sensor signal */
    unsigned int RMVehicleSpeed      :1;        /* Reduced Mode cause by problems with Vehicle Speed signal */
    unsigned int RMHPSD              :1;        /* Reduced Mode cause by problems with High Priority Steering Device */
    unsigned int RMLPSD              :1;        /* Reduced Mode cause by problems with Low Priority Steering Device */
    unsigned int Rvd1                :4;
    uint8_t     Rvd2;
} PVED_MSG_OPERATION_STATUS_T;

/*PVED_MSG_OPERATION_STATUS_T
Current mode:
0x0AA� operational
0x0AF� reduced
0x0FF� fault

Selected device:
0x00� no device selected
0x01� steering wheel
0x02� reserved
0x03� high priority steering device
0x04� low priority steering device
0x05� high priority external set-point controller

Active program.(depends on the selected device) 
0x0FF if no device is selected

High priority steering device status:
0x00� device not mapped
0x03� device enabled
0x53� device enabled. Change armed
0x0A3� device disabled
0x0F3� device disabled. Change armed

Low priority steering device status:
0x00� device not mapped
0x04� device enabled
0x54� device enabled. Change armed
0x0A4� device disabled
0x0F4� device disabled. Change armed

High priority external set-point controller:
0x00� device not mapped
0x05� device enabled
0x55� device enabled. Change armed
0x0A5� device disabled
0x0F5� device disabled. Change armed
 
*/

typedef struct tagPVED_MSG_TIME_REPORT
{
    uint16_t TimeStamp;                                 /* Milliseconds since power-on. Rollover after one minute */
    uint32_t RolloverCounter;                           /* Number of rollovers of millisecond counter */
    uint16_t Rvd1;
} PVED_MSG_TIME_REPORT_T;

typedef struct tagPVED_VEHICLE_SPEED_SENSOR
{
    uint8_t Rvd1;
    uint16_t VehicleSpeed;                              /* Vehicle Speed. Range 0 � 64255. in 1/256 km/h reflects 0 � 250.996 km/h  */    
    uint8_t  Rvd2;
    uint32_t Rvd3;
} PVED_VEHICLE_SPEED_SENSOR_T;


/* ISOBUS Messages */
typedef struct tagPVED_GUIDANCE_SYSTEM_COMMAND
{
    uint16_t CurvatureCommand;                          /* curvature command. Range (-8032 to 8031.75) unit km-1. resolution 0.25 km-1. offset -8032 km-1*/
    unsigned int bfSteeringCommandStatus     :2;        /* 00: not intended for steering | 01: intended for steering | 10: error indication | 11: not available */
    unsigned int Rvd1                        :2;
    unsigned int Rvd2                        :2;
    unsigned int Rvd3                        :2;
    uint8_t  Rvd4;
    uint32_t Rvd5;
} PVED_GUIDANCE_SYSTEM_COMMAND_T;

typedef struct tagPVED_GUIDANCE_MACHINE_STATUS
{
    uint16_t EstimatedCurvature;                         /*Estimated curvature. Range(-8032 to 8031.75). unit km-1.resolution 0.25 km-1. offset -8032 km-1  */
    unsigned int bfMechanicalSystemLockoutStatus    :2;  /* 00: not active          | 10: active           | 10: error indication | 11: not available */
    unsigned int bfMachineCanExecuteStatus          :2;  /* 00: incorrect position  | 01: correct position | 10: error indication | 11: not available */
    unsigned int bfSteeringInputPositionStatus      :2;  /* 00: system is not ready | 01: system is ready  | 10: error indication | 11: not available */
    unsigned int bfRequestResetCommandStatus        :2;  /* 00: reset not required  | 01: reset required   | 10: error indication | 11: not available */
    uint8_t  Rvd1;
    uint32_t Rvd2;
} PVED_GUIDANCE_MACHINE_STATUS_T;

#endif /* end PVED_CANMSG_H */

/* End of $Workfile: PVED_canmsg.h$ */
