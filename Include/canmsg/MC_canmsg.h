/*******************************************************************************
** $Revision: 0$
** $Date: $
** $Author: jlondero$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef MC_CANMSG_H
#define MC_CANMSG_H

/* Include ********************************************************************/
#include "types.h"
//#include "propa_canmsg.h"

/* Defines ********************************************************************/
#define PGN_MOTOR_CONTROL_A                 PGN_PROPRIETARY_A
#define SIZE_MOTOR_CONTROL_A                SIZE_PROPRIETARY_A

/* Enums **********************************************************************/
typedef enum tagMOTOR_COMMANDS
{
	/* Commands 0..40 deprecated. Old enum version */
    MOTOR_COMMAND_SEND_CONFIGURATION            =  40, /* Request configuration from module */
	MOTOR_COMMAND_MANUAL_MODE					=  41, /* Set application in manual mode */
	MOTOR_COMMAND_AUTO_MODE 					=  42, /* Set application in auto mode */
    MOTOR_COMMAND_STOP                          =  43, /* Stop motor */
    MOTOR_COMMAND_POSITION_MODE					=  44, /* Set motor in position control mode. LongParam may contain position reference */
	MOTOR_COMMAND_SET_POSITION					=  45, /* Set position reference. Long Param, new position. Scale: ??; Offset: ?? */
    MOTOR_COMMAND_SPEED_MODE                    =  46, /* Set motor in speed control mode. LongParam may contain position reference */
    MOTOR_COMMAND_SET_SPEED                     =  47, /* Set speed reference. Long Param, new speed. Scale: 1 rpm/bit; Offset: 1000 rpm */
    MOTOR_COMMAND_TORQUE_MODE                   =  48, /* Set motor in torque control mode. LongParam may contain position reference */
    MOTOR_COMMAND_SET_TORQUE                    =  49, /* Set torque reference. Long Param, new torque. Scale: 0.1 %/bit; Offset: 100% */
    MOTOR_COMMAND_ACK_FAULT                     =  50, /* Acknowledge past faults */
    MOTOR_COMMAND_ENABLE_DRIVERS                =  51, /* Enable power stage drivers */
    MOTOR_COMMAND_DISABLE_DRIVERS               =  52, /* Disable power stage drivers */
    MOTOR_COMMAND_SET_PWM_MANUALLY              =  53, /* Enable PWM controlled manually. Short param from MANUAL_PWM_MODE_E. LongParam PWM duty; Factor 0.001; Offset 100 */
    MOTOR_COMMAND_ENC_ALIGN                     =  54, /* Trigger drivers encoder align method */
    MOTOR_COMMAND_HALL_ALIGN                    =  55, /* Trigger hall alignment startup */
    MOTOR_COMMAND_SEND_ENCODER_HALL_INFO        =  56, /* Long param: 0 => Do not send; 1 => send once; 2 => continuous send */
    MOTOR_COMMAND_SET_ZERO_POS                  =  57, /* Modify position offset to take current position as zero */
	MOTOR_COMMAND_SET_ENCODER                   =  58, /* Set encoder alignment manually. LongParam, new encoder counter value. Scale 1 bit/bit; Offset: 0 bit */
    MOTOR_COMMAND_START_HALL_CALIB              =  59, /* Trigger hall calibration start */
	MOTOR_COMMAND_CANCEL_HALL_CALIBRATION 		=  60, /* Cancel hall calibration in progress */
    MOTOR_COMMAND_SET_VALID_HALL_CALIB          =  61, /* Set valid hall calibration state */
	MOTOR_COMMAND_SET_INVALID_HALL_CALIB		=  62, /* Set invalid hall calibration state */
	MOTOR_COMMAND_SET_CURRENT_HALL_CALIB		=  63, /* Calibration will be perfomed with current alignment */
    MOTOR_COMMAND_ENABLE_CURRENT_READING		=  64, /* Enable manual phase current reading and MS_P9 */
	MOTOR_COMMAND_DISABLE_CURRENT_READING		=  65, /* Disable manual phase current reading and MS_P9 */	
    MOTOR_COMMAND_RESTORE_EEPROM_VALUES         =  66, /* Restore control parameter values to default */
    MOTOR_COMMAND_ENABLE_IQD_VQD_READING        =  67, /* Enable manual IQD and VQD reading in MS_P65 and MS_P66 */
    MOTOR_COMMAND_DISABLE_IQD_VQD_READING       =  68, /* Disable manual IQD and VQD reading in MS_P65 and MS_P66 */
    MOTOR_COMMAND_SET_ERROR                     =  69, /* Set a motor error from MOTOR_ERROR_STATUS_E in MS_canmsg to be checked */
    MOTOR_COMMAND_RESET_ERROR                   =  70, /* Delete a motor error from MOTOR_ERROR_STATUS_E in MS_canmsg, this error won't be checked */    
    
	MOTOR_COMMAND_APPLICATION_DRIVE_TRAIN		= 238, /* Needs ShortParam from MC_DRIVE_TRAIN_COMMAND_E */
	MOTOR_COMMAND_APPLICATION_ECUROW			= 239, /* Needs ShortParam from MC_ECUROW_COMMAND_E */
	MOTOR_COMMAND_USERCOMMAND 					= 240, /* Disabled in final version. Needs ShortParam from MC_USER_COMMAND_E and LongParam is value (when needed,  Factor 0.001; Offset 100) */
} MOTOR_COMMANDS_E;

typedef enum tagMANUAL_PWM_MODE
{
	OFF_OFF_OFF		= 0,
	OFF_PWM_LOW		= 1,
	LOW_PWM_OFF		= 2,
	LOW_OFF_PWM		= 3,
	OFF_LOW_PWM		= 4,
	PWM_LOW_OFF		= 5,
	PWN_OFF_LOW		= 6,
	PWM_PWM_PWM		= 10,
	PWM_LOW_LOW		= 11,
	LOW_PWM_LOW		= 12,
	LOW_LOW_PWM		= 13,
	LOW_LOW_LOW		= 14,
} MANUAL_PWM_MODE_E;

typedef enum tagMC_DRIVE_TRAIN_COMMAND_E
{
	MC_DRIVE_TRAIN_NO_COMMAND			=   0, /* Place Holder */
} MC_DRIVE_TRAIN_COMMAND_E;

typedef enum tagMC_ECUROW_COMMAND_E
{
	MC_ECUROW_NO_COMMAND				=   0, /* Place Holder */
	MC_ECUROW_SET_PRESSURE_SENSOR_ZERO	=   1, /* Auto calibrates 0 offset for pressure sensor */
	MC_ECUROW_START_DISC_REFILL			=   2, /* Triggers refill mechanism manually */
    MC_ECUROW_DISABLE_PRESSURE_SENSOR   =   3, /* Disable pressure sensor, reenabled setting new offset or with SET_PRESSURE_ZERO command */
} MC_ECUROW_COMMADN_E;

typedef enum tagMC_USER_COMMAND_E
{ 
	MC_UC_NO_COMMAND		            =   0, /* Place Holder */
    MOTOR_COMMAND_SEND_STACK_USAGE      =   1, /* Send stack size and usage */
    MOTOR_COMMAND_CLEAR_EEPROM          =   2, /* Clear EEPROM and reset module */
    MOTOR_COMMAND_DEBUG_EEPROM          =   3, /* Send EEPROM debug */
	MOTOR_COMMAND_CLEAR_EEPROM_BACKUP   =   4, /* Delete eeprom backup so that values can be modified */
} MC_USER_COMMAND_E;

typedef enum tagMC_POSITION_E
{
	MC_REAR_LEFT					    =   0, /* Motor position in vehicle */
    MC_REAR_RIGHT                       =   1, /* Motor position in vehicle */
	MC_FRONT_LEFT					    =   2, /* Motor position in vehicle */
    MC_FRONT_RIGHT                      =   3, /* Motor position in vehicle */
} MC_POSITION_E;
/******************************** General Msg *********************************/

typedef struct tagMOTOR_CONFIG_P128
{
    uint8_t  Page;
    uint8_t  Motor_Command;                     /* Value from MOTOR_COMMANDS_E */
    uint8_t  Motor_Message;                     /* Unused */
    uint8_t  Motor_ShortParam;                  /* Short param for Motor_Command */  
    uint32_t Motor_LongParam;                   /* Long param for Motor_Command */
} MOTOR_CONFIG_P128_T;

typedef struct tagMOTOR_CONFIG_P129
{
    uint8_t     Page;                           /*  */
    uint8_t     Rvd1;                           /*  */
    uint16_t    Motor_SpeedKP;                  /* KP gain in Speed PI controller; Factor 1; Offset 0 */
    uint16_t    Motor_SpeedKI;                  /* KI gain in Speed PI controller; Factor 1; Offset 0 */
    uint16_t    Rvd2;                           /*  */
} MOTOR_CONFIG_P129_T;

typedef struct tagMOTOR_CONFIG_P130
{
    uint8_t     Page;                           /*  */
    uint8_t     Rvd1;                           /*  */
    uint16_t    Motor_PosKP;                    /* KP gain in Angle PI controller; Factor 1; Offset 0 */
    uint16_t    Motor_PosKI;                    /* KI gain in Angle PI controller; Factor 1; Offset 0 */
    uint16_t    Rvd2;                           /*  */
} MOTOR_CONFIG_P130_T;

typedef struct tagMOTOR_CONFIG_P131
{
    uint8_t     Page;                           /*  */
    uint8_t     Rvd1;                           /*  */
    uint16_t    Motor_TorqueKP;                 /* KP gain in Torque PI controller; Factor 1; Offset 0 */
    uint16_t    Motor_TorqueKI;                 /* KI gain in Torque PI controller; Factor 1; Offset 0 */
    uint16_t    Rvd2;                           /*  */
} MOTOR_CONFIG_P131_T;

typedef struct tagMOTOR_CONFIG_P132
{
    uint8_t     Page;                           /*  */
    uint8_t     Motor_SpeedSign : 2;            /* Motor speed sign, according constructive design. 0  = speed; 1 = -speed */
    uint8_t     Rvd1 : 6;                       /*  */
    uint16_t    Motor_MaxTorque;                /* Unit %; Factor 0.01; Offset 0 */
    uint16_t    Motor_MaxSpeed;                 /* Unit RPM; Factor 0.01; Offset 0 */
    uint16_t    Motor_MaxPosDiff;               /* Unit Degree; Factor 0.01; Offset 0 */
} MOTOR_CONFIG_P132_T;

typedef struct tagMOTOR_CONFIG_P133
{
    uint8_t     Page;                           /*  */
    uint8_t     motorEnabled : 2;               /* Shows if motor is enabled or not. Can be read and set. Intended for section cutoff */
    uint8_t     Rvd1 : 6;                       /*  */
    uint8_t     discRefillPressureHighTh;       /* Refill pressure threshold in mBars; Offset 0; Scale 1 mBar per bit */
    uint16_t    pressureSensorOffset;           /* Pressure sensor offset; Offset 32768; Scale 0.01 mBar per bit */
    uint8_t     Rvd2;							/*  */
    uint16_t    Rvd3;                           /*  */
} MOTOR_CONFIG_P133_T;

typedef struct tagMOTOR_CONFIG_P135
{
    uint8_t     Page;
    uint8_t     Index;          				/* Value 0 o 1; Values in this page come from calibration !Do Not Modify! */
    uint16_t    Hall_1_4;       				/* If Index = 0 first hall flank else fourth hall flank */
    uint16_t    Hall_2_5;       				/* If Index = 0 second hall flank else fifth hall flank */
    uint16_t    Hall_3_6;       				/* If Index = 0 third hall flank else sixth hall flank */
} MOTOR_CONFIG_P135_T;

typedef struct tagMOTOR_CONFIG_P136
{
    uint8_t     Page;                           /*  */
    uint8_t     Index;                          /* Value 0, 1 or 2 */
    uint16_t    Hall1_P_N;                      /* If Index = 0: hall phase shift - Offset 0; Scale 0.01 degree per bit; Index = 1 or 2 first hall correction in positive turn direction else correction in negative turn. Offset 18000; Scale 0.01 degree per bit */
    uint16_t    Hall2_P_N;                      /* If Index = 1 or 2 second hall correction in positive turn direction else correction in negative turn. Offset 18000; Scale 0.01 degree per bit */
    uint16_t    Hall3_P_N;                      /* If Index = 1 or 2 third hall correction in positive turn direction else correction in negative turn. Offset 18000; Scale 0.01 degree per bit */
} MOTOR_CONFIG_P136_T;

typedef struct tagMOTOR_CONFIG_P137
{
    uint8_t     Page;                           /*  */
    uint8_t     Rvd1;                           /*  */
    uint16_t    Motor_MaxCurrent;               /* Offset 0; Scale 0.01 Ampere per bit */
    uint16_t    Motor_MinBatVoltage;            /* Offset 0; Scale 0.01 Volt per bit */
    uint16_t    Motor_MaxBatVoltage;            /* Offset 0; Scale 0.01 Volt per bit */
} MOTOR_CONFIG_P137_T;

typedef struct tagMOTOR_CONFIG_P138
{
    uint8_t     Page;                           /*  */
    uint8_t     Debug_TimeLoop;             /*  */
    uint16_t    Motor_MaxStatorTemp;            /* Offset 0; Scale 0.01 degree centigrade per bit */
    uint16_t    Motor_MaxDriverTemp;            /* Offset 0; Scale 0.01 degree centigrade per bit */
    uint16_t    Motor_MaxTorqueReg;         /* Unit %; Factor 0.01; Offset 0 */
} MOTOR_CONFIG_P138_T;

typedef struct tagMOTOR_CONFIG_P139
{
    uint8_t     Page;                           /*  */
    uint8_t     Motor_Position;                 /* Value from MC_POSITION_E */
    uint8_t     FF_Status;                      /* Feed Forward estate: 0 DISABLE, 1 ENABLE */
    uint8_t     FF_PM;                          /* Feed Forward Permanent magnet flux linkage (mWb) Offset 0; Scale 1 */
    uint16_t    FF_Lq;                          /* Feed Forward Lq (uH) Offset 0; Scale 1  */
    uint16_t    FF_Ld;                          /* Feed Forward Ld (uH) Offset 0; Scale 1  */
} MOTOR_CONFIG_P139_T;

typedef union tagMOTOR_CONFIG_U
{
    MOTOR_CONFIG_P128_T     P128;
	MOTOR_CONFIG_P129_T	    P129;
	MOTOR_CONFIG_P130_T	    P130;
	MOTOR_CONFIG_P131_T	    P131;
	MOTOR_CONFIG_P132_T	    P132;
	MOTOR_CONFIG_P133_T	    P133;
	MOTOR_CONFIG_P135_T		P135;
	MOTOR_CONFIG_P136_T		P136;
	MOTOR_CONFIG_P137_T		P137;
	MOTOR_CONFIG_P138_T		P138;
    MOTOR_CONFIG_P139_T		P139;
} MOTOR_CONFIG_U;

#endif /* end MC_CANMSG_H */

/* End of $Workfile: MC_canmsg.h$ */
