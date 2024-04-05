
#ifndef HSC_CANMSG_H
#define HSC_CANMSG_H

/*!\page HSC High Speed Control
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/

/* Defines ********************************************************************/
#define PGN_HIGHSPEED_CONTROL               0xFF0DU
#define SIZE_HIGHSPEED_CONTROL              3U	
#define PGN_DIRECT_DRIVE_COMMAND            0xFFF8U
#define SIZE_DIRECT_DRIVE_COMMAND   		8U
#define PGN_DIRECT_DRIVE_STATUS             0xFFF6U
#define SIZE_DIRECT_DRIVE_STATUS		    8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/* HighSpeed Control pages */
typedef struct tagHIGHSPEED_CONTROL_P0
{
    uint8_t  Page;
    uint16_t  PGNPeriod;   /* Configures data send period */
} HIGHSPEED_CONTROL_P0_T;

typedef struct tagHIGHSPEED_CONTROL_P1
{
    uint8_t  Page;
    uint16_t  DD_RelativeRefPosition;   /* Position Reference Relative to Actual Position; Unit degree; Factor 0.05; Offset 1440 */
} HIGHSPEED_CONTROL_P1_T;

typedef struct tagHIGHSPEED_CONTROL_P2
{
    uint8_t  Page;
    uint16_t  DD_RefPosition;   /* Position Reference; Unit degree; Factor 0.05; Offset 1440; Range -1260/+1260 */
} HIGHSPEED_CONTROL_P2_T;

typedef struct tagHIGHSPEED_CONTROL_P3
{
    uint8_t  Page;
    uint16_t  DD_RefSpeed;      /* Speed Reference; Unit rpm; Factor 0.1; Offset 300 */
} HIGHSPEED_CONTROL_P3_T;

typedef struct tagHIGHSPEED_CONTROL_P4
{
    uint8_t  Page;
    uint16_t  DD_RefTorque;     /* Torque Reference; Unit %; Factor 0.1; Offset 100 */
} HIGHSPEED_CONTROL_P4_T;

typedef struct tagHIGHSPEED_CONTROL_P5
{
    uint8_t  Page;
    uint16_t  ActualPosition;   /* Actual Position; Unit degree; Factor 0.05; Offset 1440 */
} HIGHSPEED_CONTROL_P5_T;

typedef struct tagHIGHSPEED_CONTROL_P6
{
    uint8_t  Page;
    uint16_t  ActualSpeed;      /* Actual Speed; Unit rpm; Factor 0.1; Offset 300 */
} HIGHSPEED_CONTROL_P6_T;

typedef struct tagHIGHSPEED_CONTROL_P7
{
    uint8_t  Page;
    uint16_t  ActualTorque;     /* Actual Torque; Unit %; Factor 0.1; Offset 100 */
} HIGHSPEED_CONTROL_P7_T;

typedef struct tagHIGHSPEED_CONTROL_P8
{
    uint8_t  Page;
    uint16_t  MaxSpeed;         /* Max Speed Limit; Unit rpm; Factor 0.1; Offset 0 */
} HIGHSPEED_CONTROL_P8_T;

typedef struct tagDIRECT_DRIVE_STATUS_P0
{
    uint8_t   Page;
    uint8_t   SteeringEngageState;        /* Value from AGS_STEERING_ENGAGE_STATE_E */
    uint16_t  Rvd1;        
    uint16_t  Rvd2;           
    uint16_t  Rvd3;          
} DIRECT_DRIVE_STATUS_P0_T;

typedef struct tagDIRECT_DRIVE_STATUS_P60
{
    uint8_t   Page;
    uint8_t   GeneralStatus;        /* Value from DD_STATUS_E */
    uint16_t  ActualPosition;       /* Actual Position; Unit degree; Factor 0.05; Offset 1440 */
    uint16_t  ActualSpeed;          /* Actual Speed; Unit rpm; Factor 0.1; Offset 300 */
    uint16_t  ActualTorque;         /* Actual Torque; Unit %; Factor 0.1; Offset 100 */
} DIRECT_DRIVE_STATUS_P60_T;

typedef struct tagDIRECT_DRIVE_STATUS_P61
{
    uint8_t   Page;
    uint8_t   Rvd1;
    uint16_t  DD_RefPosition;       /* Position Reference; Unit degree; Factor 0.05; Offset 1440 (4 complete turns) */
    uint16_t  DD_RefSpeed;          /* Speed Reference; Unit rpm; Factor 0.1; Offset 300 */
    uint16_t  DD_RefTorque;         /* Unit %; Factor 0.1; Offset 100 */
} DIRECT_DRIVE_STATUS_P61_T;

typedef struct tagDIRECT_DRIVE_STATUS_P62
{
    uint8_t   Page;
    uint8_t   HallStatus;           /* The three less significant bits represent hall sensor status */
    uint8_t   HallCalibStatus;      /* Hall calibration status */
    uint8_t   ControllerCalibStatus;/* Controller calibration status */
    uint32_t  ErrorCode;            /* Combination of values from AGS_DD_ERROR_E */
} DIRECT_DRIVE_STATUS_P62_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P31
{
    uint8_t   Page;
    uint8_t   Rvd1;                                        
    uint8_t   SteeringActuatorType;              /* Value from AGC_VEHICLE_STEER_ACTUATOR_TYPES */
    uint8_t   Rvd2;               
    uint32_t  Rvd3;                              
} DIRECT_DRIVE_COMMAND_P31_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P32
{
    uint8_t  Page;
    uint8_t  MotorDisengageSensitivity; /* Value from AUTOGUIDE_MOTOR_DISENGAGE_SENSITIVITYS */
    uint16_t MaxEngageDistance;         /* Distance engage threshold; Units mm; Factor 1; Offset 0;  SAEds12 */
    uint16_t MaxEngageAngle;            /* Angle engage threshold; Units degrees; Factor 1/128; Offset 0; SAEad05 */
    uint16_t MaxEngageSpeed;            /* Maximum speed allowed for automatic engage; Units mm/sec; Factor 1; Offset 0 */
} DIRECT_DRIVE_COMMAND_P32_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P41
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t CWFreePlayAngle;           /* FreePlay angle ClockWise; Units degree; Factor 1/128; Offset 0; SAEad05 */
    uint16_t CCWFreePlayAngle;          /* FreePlay angle CounterClockWise; Units degree; Factor 1/128; Offset 0; SAEad05 */
    uint16_t Rvd2;
} DIRECT_DRIVE_COMMAND_P41_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P60
{
    uint8_t  Page;
    uint8_t  DD_Command;               /* Value from AGC_DD_COMMAND */
    uint8_t  DD_Message;               /* Value from AGC_DD_MESSAGE */
    uint8_t  DD_ShortParam;            /* Short param for DD_Command or DD_Message */  
    uint32_t DD_LongParam;             /* Long param for DD_Command or DD_Message */
} DIRECT_DRIVE_COMMAND_P60_T;

 typedef struct tagDIRECT_DRIVE_COMMAND_P61
{
    uint8_t   Page;
    uint8_t   DD_DisengageSensitivity;  /* Units %; Factor 1; Offset 0 */
    uint16_t  DD_MaxSpeed;              /* Unit rpm; Factor 0.1; Offset 0 */
    uint16_t  DD_MaxTorque;             /* Unit %; Factor 0.1; Offset 0 */
    uint16_t  DD_StopFactor;            /* Makes motor drecrease speed more or less smoothly; Range 0 to 999 */
} DIRECT_DRIVE_COMMAND_P61_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P63
{
    uint8_t   Page;
    uint8_t   DD_ApproachSpeedFactor; /* Gain for Max Speed when CANSteer is on approach; Factor 0.05; Offset 0 */
    uint16_t  DD_DeadBand;      /* Position Control Dead Band; Unit degree; Factor 0.05; Offset 0 */
    uint16_t  DD_TorqueKP;      /* Proportional Gain Torque Loop; Factor 1; Offset 0 */
    uint16_t  DD_TorqueKI;      /* Integral Gain Torque Loop; Factor 1; Offset 0 */
} DIRECT_DRIVE_COMMAND_P63_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P64
{
    uint8_t   Page;
    uint8_t   Rvd1;
    uint16_t  DD_PropLoopPosGain;       /* Position gain for proportional loop; Factor 1; Offset 0 */
    uint16_t  DD_PropLoopSpeedGain;     /* Speed Gain for proportional loop; Factor 1; Offset 0 */
    uint16_t  DD_PropErrorSaturation;   /* Position error saturation; Unit degree; Factor 0.05; Offset 0 */
} DIRECT_DRIVE_COMMAND_P64_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P65
{
    uint8_t   Page;
    uint8_t   Rvd1;
    uint16_t  DD_IntegralLoopPosGain;       /* Position gain for integral loop; Factor 1; Offset 0 */
    uint16_t  DD_IntegralLoopSpeedGain;     /* Speed Gain for integral loop; Factor 1; Offset 0 */
    uint16_t  DD_IntegralErrorSaturation;   /* Integrator saturation; Factor 1; Offset 0 */
} DIRECT_DRIVE_COMMAND_P65_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P66
{
    uint8_t   Page;
    uint8_t   Index;            /* Value 0 o 1; Values in this page come from calibration !Do Not Modify! */
    uint16_t  DD_Hall_1_4;      /* If Index = 0 first hall flank else fourth hall flank */
    uint16_t  DD_Hall_2_5;      /* If Index = 0 second hall flank else fifth hall flank */
    uint16_t  DD_Hall_3_6;      /* If Index = 0 third hall flank else sixth hall flank */
} DIRECT_DRIVE_COMMAND_P66_T;

typedef struct tagDIRECT_DRIVE_COMMAND_P67
{
    uint8_t   Page;
    uint8_t   PilotAddress;     /* Source address that controls DirectDrive */
    uint16_t  Rvd1;
    uint16_t  Rvd2;
    uint16_t  Rvd3;
} DIRECT_DRIVE_COMMAND_P67_T;

#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

typedef union tagHIGHSPEED_CONTROL
{
    HIGHSPEED_CONTROL_P0_T   P0;
    HIGHSPEED_CONTROL_P1_T   P1;
    HIGHSPEED_CONTROL_P2_T   P2;
    HIGHSPEED_CONTROL_P3_T   P3;
    HIGHSPEED_CONTROL_P4_T   P4;
    HIGHSPEED_CONTROL_P5_T   P5;
    HIGHSPEED_CONTROL_P6_T   P6;
    HIGHSPEED_CONTROL_P7_T   P7;
    HIGHSPEED_CONTROL_P8_T   P8;
} HIGHSPEED_CONTROL_U;

typedef union tagDIRECT_DRIVE_STATUS
{
	DIRECT_DRIVE_STATUS_P0_T P0;
	DIRECT_DRIVE_STATUS_P60_T P60;
	DIRECT_DRIVE_STATUS_P61_T P61;
	DIRECT_DRIVE_STATUS_P62_T P62;
} DIRECT_DRIVE_STATUS_U;

typedef union tagDIRECT_DRIVE_COMMAND
{
	DIRECT_DRIVE_COMMAND_P31_T P31;
	DIRECT_DRIVE_COMMAND_P32_T P32;
	DIRECT_DRIVE_COMMAND_P41_T P41;
	DIRECT_DRIVE_COMMAND_P60_T P60;
	DIRECT_DRIVE_COMMAND_P61_T P61;
	DIRECT_DRIVE_COMMAND_P63_T P63;
	DIRECT_DRIVE_COMMAND_P64_T P64;
	DIRECT_DRIVE_COMMAND_P65_T P65;
	DIRECT_DRIVE_COMMAND_P66_T P66;
	DIRECT_DRIVE_COMMAND_P67_T P67;
} DIRECT_DRIVE_COMMAND_U;

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

/* End of $Workfile: HSC_canmsg.h$ */
