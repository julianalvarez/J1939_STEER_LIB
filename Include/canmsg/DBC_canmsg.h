/*******************************************************************************
** $Revision: 6$
** $Date: 26/09/2019 08:06:13 a.m.$
** $Author: abenso$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef DBC_CANMSG_H
#define DBC_CANMSG_H

/* Include ********************************************************************/
#include "../types.h"

/* Enums **********************************************************************/
typedef enum tagDBC_DATA_TYPES
{
    DBC_HEADER_DT           = 0,    /*!<  */
    DBC_CONTROL_POINT_DT    = 6,    /*!<  */
    DBC_INVALID_PATTERN_DT  = 7,    /*!<  */
    DBC_MOVEMENT_COMMAND_DT = 3,    /*!<  */
    DBC_LAST_DT                     /*!<  */
} DBC_DATA_TYPES_E;
 
/* Defines ********************************************************************/
#define PGN_DYNAMIC_BEZIER_CONTROL_HEADLAND                0xFFFAU
#define PGN_DYNAMIC_BEZIER_CONTROL                         0xFFFCU
#define SIZE_DYNAMIC_BEZIER_CONTROL                        56U	

typedef enum tag_FI_DBC_SIGN_E
{
    FI_DBC_SIGN_NEGATIVE,
    FI_DBC_SIGN_POSITIVE
} FI_DBC_SIGN_E;

typedef enum tagDBC_MOVEMENT_COMMAND_DURATION_TYPES
{
    DBC_MOVEMENT_COMMAND_DURATION_TYPE_NONE_E           = 0,    /*!<  */
    DBC_MOVEMENT_COMMAND_DURATION_TYPE_TIME_E           = 1,    /*!<  */
    DBC_MOVEMENT_COMMAND_DURATION_TYPE_DISTANCE_E       = 2,    /*!<  */
    DBC_MOVEMENT_COMMAND_DURATION_TYPE_DELTA_HEADING_E  = 3,    /*!<  */
    DBC_MOVEMENT_COMMAND_DURATION_TYPE_LAST                    /*!<  */
} DBC_MOVEMENT_COMMAND_DURATION_TYPES_E;

typedef enum tagDBC_MOVEMENT_COMMAND_SPEED_CMD_TYPES
{
    DBC_MOVEMENT_COMMAND_SPEED_CMD_TYPE_NONE_E              = 0,    /*!<  */
    DBC_MOVEMENT_COMMAND_SPEED_CMD_TYPE_SPEED_E             = 1,    /*!<  */
    DBC_MOVEMENT_COMMAND_SPEED_CMD_TYPE_ACCELERATION_E      = 2,    /*!<  */
    DBC_MOVEMENT_COMMAND_SPEED_CMD_TYPE_COMMON_TORQUE_E     = 3,    /*!<  */
    DBC_MOVEMENT_COMMAND_SPEED_CMD_TYPE_LAST                        /*!<  */
} DBC_MOVEMENT_COMMAND_SPEED_CMD_TYPES_E;

typedef enum tagDBC_MOVEMENT_COMMAND_STEERING_CMD_TYPES
{
    DBC_MOVEMENT_COMMAND_STEERING_CMD_TYPE_NONE_E               = 0,    /*!<  */
    DBC_MOVEMENT_COMMAND_STEERING_CMD_TYPE_CURVATURE_E          = 1,    /*!<  */
    DBC_MOVEMENT_COMMAND_STEERING_CMD_TYPE_YAW_RATE_E           = 2,    /*!<  */
    DBC_MOVEMENT_COMMAND_STEERING_CMD_TYPE_WHEEL_ANGLE_E        = 3,    /*!<  */
    DBC_MOVEMENT_COMMAND_STEERING_CMD_TYPE_DIFF_TORQUE_E        = 4,    /*!<  */
    DBC_MOVEMENT_COMMAND_STEERING_CMD_TYPE_LAST                         /*!<  */
} DBC_MOVEMENT_COMMAND_STEERING_CMD_TYPES_E;

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

/* AB Line message */
typedef struct tagFI_DBC
{
    /* 0: Negative 1:Positive */
    unsigned int        sign:2;            
    /* Factor = 1 */
    unsigned int        integer:30;
    /* Factor = 1/4211081216 range = [0, 4211081215/4211081216] */
    uint32_t            fractional;
} FI_DBC_T;

typedef struct tagPATTERN_DBC_CONFIG
{
    unsigned int        bfUseExtendedBelongs    :2;
    unsigned int        Rvd1                    :2;
    unsigned int        Rvd2                    :2;
    unsigned int        Rvd3                    :2;
} PATTERN_DBC_CONFIG_T;

typedef struct tagDBC_HEADER
{
    /* */
    uint16_t            	wLastSequence;
    /* Reference Point */
    uint32_t            	dwLatitude;
    uint32_t            	dwLongitude;
    uint32_t            	dwHeight;
    uint8_t            	 	bPatternClass;
    PATTERN_DBC_CONFIG_T    tPatternConfig;
    uint16_t            	wReserved[11];
} DBC_HEADER_T;

typedef struct tagDBC_CONTROL_POINT
{
    FI_DBC_T                tPosN;
    FI_DBC_T                tPosE;
    FI_DBC_T                tHeading;
    FI_DBC_T                tVelPreModule;
    FI_DBC_T                tVelPostModule;
    FI_DBC_T                tSpeed;
    uint8_t             	bPointType;
    uint8_t             	bReserved[2];
} DBC_CONTROL_POINT_T;

typedef struct tagDBC_INVALID_PATTERN
{
    uint8_t             bReserved[56];
} DBC_INVALID_PATTERN_T;

typedef struct tagMOVEMENT_COMMAND
{
    uint8_t             bDurationType;          /* Value (Time, Distance, DeltaHeading) */
    uint32_t            dwDuration;             /* Command duration (Factor 0.1 s/bit | m/bit | deg/bit; Offset 0 s | m | deg) */
    uint8_t             bSpeedCmdType;          /* Value (Speed, Acceleration) */
    uint32_t            dwSpeedCmd;             /* Commanded speed value (Factor 0.0001 m/s/bit | m/s^2/bit | perc/bit; Offset 100 m/s | m/s^2 | perc) */
    uint8_t             bSteeringCmdType;       /* Value (Curvature, YawRate, WheelAngle) */
    uint32_t            dwSteeringCmd;          /* Commanded steering value (Factor 0.0001 m^-1/bit | deg/bit | rps/bit | perc/bit; Offset 100 m^-1 | deg | rps | perc) */
    /* Fill - complete 64 bytes */
    uint8_t             bReserved[43];
} DBC_MOVEMENT_COMMAND_T;

typedef union tagDBC_DATA
{
    DBC_HEADER_T            tHeader;
    DBC_CONTROL_POINT_T     tControlPoint;
    DBC_INVALID_PATTERN_T   tInvalidPattern;
    DBC_MOVEMENT_COMMAND_T  tMovementCommand;
} DBC_DATA_T;
    
/* AB Data message (52 bytes) */
typedef struct tagDBC_MSG_T
{
    DBC_DATA_TYPES_E   eDataType;
    uint16_t           wSequence;	/* Messages sequence */
    uint16_t           wOrder;
    DBC_DATA_T         tData;
} DBC_MSG_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

#if defined(__cplusplus)
}
#endif

#endif

/* End of $Workfile: DBC_canmsg.h$ */
