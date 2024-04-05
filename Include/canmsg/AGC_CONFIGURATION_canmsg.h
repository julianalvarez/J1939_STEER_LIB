
#ifndef AGC_CONFIGURATION_CANMSG_H
#define AGC_CONFIGURATION_CANMSG_H

/*!\page AGC AutoGuide Command
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
#ifndef AGC_VEHICLE_STEER_ACTUATOR_TYPES
#define AGC_VEHICLE_STEER_ACTUATOR_TYPES
enum tagAGC_VEHICLE_STEER_ACTUATOR_TYPES    /*!< Available actuator for steering */
{          
    AGC_STEERING_ACT_EXTERNAL_MOTOR = 0,              /*!< Std. Electric */
    AGC_STEERING_ACT_HYDRAULIC_PWM = 1,               /*!< Hydraulic PWM valve */
    AGC_STEERING_ACT_EMBEDDED_MOTOR_DELTA_POS = 2,    /*!< Direct Drive (Control by Delta Position)*/
    AGC_STEERING_ACT_HYDRAULIC_PVED_CL = 3,           /*!< Hydraulic PVED-CL valve */
    AGC_STEERING_ACT_EMBEDDED_MOTOR_SPEED = 4,        /*!< Direct Drive (Control by Speed) */
    AGC_STEERING_ACT_HYDRAULIC_CURRENT = 6,           /*!< Hydraulic Current valve */
    AGC_STEERING_ACT_ESi2_MOTOR_SPEED = 7,            /*!< eWheel ESi2 (Control by Speed) */
	AGC_STEERING_ACT_INVALID_LICENSE = 240,           /*!< Value indicating invalid license */
	AGC_STEERING_ACT_NO_ACTUATOR = 250,                /*!< No steering actuator */
#if !defined(STEER_HGNSS)  
    AGC_STEERING_ACT_HYDRAULIC_PVED_STD = 5,          /*!< Hydraulic PVED STD */
    AGC_STEERING_ACT_TERRAN_DIFF_DRIVE_REAR = 100,    /*!< Rear Differential Drive */
    AGC_STEERING_ACT_TERRAN_DIFF_DRIVE_FRONT = 101,   /*!< Front Differential Drive */
    AGC_STEERING_ACT_TERRAN_SKID = 102,               /*!< Skid Steering */
#endif
};
#endif

#ifndef AGC_VEHICLE_SPEED_ACTUATOR_TYPES
#define AGC_VEHICLE_SPEED_ACTUATOR_TYPES
enum tagAGC_VEHICLE_SPEED_ACTUATOR_TYPES    /*!< Available actuator for speed */
{
    AGC_SPEED_ACT_TERRAN_DIFF_DRIVE_REAR = 100,   /*!< Rear Differential Drive */
    AGC_SPEED_ACT_TERRAN_DIFF_DRIVE_FRONT = 101,  /*!< Front Differential Drive */
    AGC_SPEED_ACT_TERRAN_SKID = 102,              /*!< Skid Steering */
    AGC_SPEED_ACT_INVALID_LICENSE = 240,          /*!< Value indicating invalid license */
    AGC_SPEED_ACT_NO_ACTUATOR = 250               /*!< No speed actuator */
};
#endif

#ifndef AGC_VEHICLE_WHEEL_ANGLE_SENSOR_SOURCE
#define AGC_VEHICLE_WHEEL_ANGLE_SENSOR_SOURCE
enum tagAGC_VEHICLE_WHEEL_ANGLE_SENSOR_SOURCES    /*!< Available Wheel Angle Sensors */
{
    AGC_VEHICLE_WHEEL_ANGLE_SENSOR_NO_SENSOR = 0,   /*!< No steering wheel sensor */
    AGC_VEHICLE_WHEEL_ANGLE_SENSOR_ADC = 1,         /*!< Pote connected to ADC Channel */
    AGC_VEHICLE_WHEEL_ANGLE_SENSOR_PVED = 2         /*!< Pote in CAN message from PVED-CL */
};
#endif

#ifndef AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR
#define AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR
enum tagAGC_VEHICLE_HYD_USER_OVERRIDE_SENSORS    /*!< User Override Sensor */
{
    AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR_NO_SENSOR                    = 0,    /*!< No Sensor */
    AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR_ANALOG_VALUE                 = 1,    /*!< Analog Value Sensor */
    AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR_ANALOG_FREQUENCY             = 2,    /*!< Analog Frequency Sensor */
    AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR_DIGITAL_FREQUENCY            = 3,    /*!< Digital Frequency Sensor */
    AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR_DIGITAL_DUTY_CYCLE_POSITION  = 4,    /*!< Digital Duty Cycle Position Sensor */
    AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR_DIGITAL_DUTY_CYCLE_SPEED     = 5,    /*!< Digital Duty Cycle Speed Sensor */
    AGC_VEHICLE_HYD_USER_OVERRIDE_SENSOR_LAST
};
#endif

#ifndef AUTOGUIDE_PARAMETERS
#define AUTOGUIDE_PARAMETERS
enum tagAUTOGUIDE_PARAMETERS                        /*!< List of IMUs parameters */
{
    AUTOGUIDE_PARAMETER_MX = 0,
    AUTOGUIDE_PARAMETER_HX = 1,                     
    AUTOGUIDE_PARAMETER_MY = 2,                     
    AUTOGUIDE_PARAMETER_HY = 3,                     
    AUTOGUIDE_PARAMETER_MZ = 4,                    
    AUTOGUIDE_PARAMETER_HZ = 5,                     
    AUTOGUIDE_PARAMETER_GX2 = 6,                     
    AUTOGUIDE_PARAMETER_GX1 = 7,                     
    AUTOGUIDE_PARAMETER_GX0 = 8,                     
    AUTOGUIDE_PARAMETER_GY2 = 9,                     
    AUTOGUIDE_PARAMETER_GY1 = 10,                     
    AUTOGUIDE_PARAMETER_GY0 = 11,                     
    AUTOGUIDE_PARAMETER_GZ2 = 12,                     
    AUTOGUIDE_PARAMETER_GZ1 = 13,                     
    AUTOGUIDE_PARAMETER_GZ0 = 14,
    AUTOGUIDE_PARAMETER_MHB_CC = 15,                     
    AUTOGUIDE_PARAMETER_HHB_CC = 16,
    AUTOGUIDE_PARAMETER_MHB_CCW = 17,                     
    AUTOGUIDE_PARAMETER_HHB_CCW = 18,              
    AUTOGUIDE_PARAMETER_LAST_ = 19,
};
#endif


#ifndef AUTOGUIDE_MOUNTING_POSITIONS
#define AUTOGUIDE_MOUNTING_POSITIONS
enum tagAUTOGUIDE_MOUNTING_POSITIONS                   /*!< List of CANSteer mounting positions */
{
    AUTOGUIDE_MOUNTING_HORIZONTAL_FORWARD = 0,        /*!< Horizontal mounting and arrow pointing forward */
    AUTOGUIDE_MOUNTING_HORIZONTAL_BACKWARD = 1,       /*!< Horizontal mounting and arrow pointing backward */
    AUTOGUIDE_MOUNTING_VERTICAL_UP = 2,               /*!< Vertical mounting and arrow pointing up */
    AUTOGUIDE_MOUNTING_VERTICAL_DOWN = 3,             /*!< Vertical mounting and arrow pointing down */
    AUTOGUIDE_MOUNTING_CUSTOM = 4,                    /*!< Custom mounting */
    AUTOGUIDE_MOUNTING_LAST
};
#endif

#ifndef AUTOGUIDE_TERRAIN_COMPENSATIONS
#define AUTOGUIDE_TERRAIN_COMPENSATIONS
enum tagAUTOGUIDE_TERRAIN_COMPENSATIONS             /*!< List of terrain compensation options */
{
    AUTOGUIDE_TC_OFF = 0,                           /*!<  */
    AUTOGUIDE_TC_T1 = 1,                            /*!< Roll compensation  */
    AUTOGUIDE_TC_T2 = 2,                            /*!< Pitch compensation */
    AUTOGUIDE_TC_T3 = 3                             /*!< Roll+Pitch compensation */
};
#endif  

#ifndef AUTOGUIDE_HEADING_COMPENSATION_MODES
#define AUTOGUIDE_HEADING_COMPENSATION_MODES
enum tagAUTOGUIDE_HEADING_COMPENSATION_MODES        /*!< List of heading compensation modes */
{
    AUTOGUIDE_HC_OFF = 0,                           /*!< Heading compensation disabled */
    AUTOGUIDE_HC_ROLL = 1,                          /*!< Heading compensated through roll rate */
    AUTOGUIDE_HC_YAW = 2,                           /*!< Heading compensated through yaw rate */
    AUTOGUIDE_HC_ROLL_AND_YAW= 3                    /*!< Heading compensated through roll rate and yaw rate */
};
#endif

#ifndef AUTOGUIDE_MOTOR_DISENGAGE_SENSITIVITYS
#define AUTOGUIDE_MOTOR_DISENGAGE_SENSITIVITYS
enum tagAUTOGUIDE_MOTOR_DISENGAGE_SENSITIVITYS              /*!< List of steering wheel feedback disengage sensitivities */
{
    AUTOGUIDE_MOTOR_DISENGAGE_LOW_SENSITIVITY = 0,          	/*!< Low sensitivity / Requires big effort to disengage */
    AUTOGUIDE_MOTOR_DISENGAGE_MEDIUM_SENSITIVITY = 1,       	/*!< Medium sensitivity / Requires normal effort to disengage */
    AUTOGUIDE_MOTOR_DISENGAGE_HIGH_SENSITIVITY = 2,         	/*!< High sensitivity / Requires little effort to disengage */
    AUTOGUIDE_MOTOR_DISENGAGE_SENSITIVITY_DISABLED = 3      	/*!< Disabled / Ignores steering wheel feedback */
};
#endif

#ifndef AUTOGUIDE_MOTOR_LOCKS
#define AUTOGUIDE_MOTOR_LOCKS
enum tagMOTOR_LOCKS_STATES              /*!< List of steering actuator modes */
{
    MOTOR_LOCK_FREE  = 0,               /*!< Actuator controlled automatically */
    MOTOR_LOCK_CLOCKWISE = 1,           /*!< Set actuator to run clockwise */
    MOTOR_LOCK_COUNTERCLOCKWISE = 2     /*!< Set actuator to run counterclockwise */
};
#endif

#ifndef AGC_H_BRIDGE_WORKING_MODE
#define AGC_H_BRIDGE_WORKING_MODE
enum tagAGC_H_BRIDGE_WORKING_MODE      /*!< List of H_Bridge modes; each leg */
{
    AGC_H_BRIDGE_MODE_OFF = 0,         /*!< H Bridge not working (high Z state) */
    AGC_H_BRIDGE_MODE_LOW = 1,         /*!< H Bridge is working in low mode */
    AGC_H_BRIDGE_MODE_HIGH = 2,        /*!< H Bridge is working in high mode */
    AGC_H_BRIDGE_MODE_PWM = 3          /*!< H Bridge is working in PWM mode */
};
#endif

#ifndef AGC_HIGH_SIDE_WORKING_MODE
#define AGC_HIGH_SIDE_WORKING_MODE
enum tagAGC_HIGH_SIDE_WORKING_MODE     /*!< List of hydraulic valve high-side input usage */
{
    AGC_HIGH_SIDE_MODE_OFF = 0,        /*!< High Side not working (always open-circuit) */
    AGC_HIGH_SIDE_MODE_ON = 1          /*!< High Side is working (controlled by software) */
};
#endif

#ifndef AGC_SPEED_TABLE_POINT
#define AGC_SPEED_TABLE_POINT
enum tagAGC_SPEED_TABLE_POINT          /*!< List of entry points to speed table */
{
    SPEED_TABLE_LOW_SPEED = 0,          /*!< Index for high speed parameters */
    SPEED_TABLE_HIGH_SPEED = 1          /*!< Index for low speed parameters */
};
#endif

#ifndef AGC_HBRIDGE_E
#define AGC_HBRIDGE_E
enum tagAGC_HBRIDGE_E           /*!< List Output Pins of H-Bridge */
{
    AGC_HBRIDGE_PIN_A = 1,      /*!< Output Pin A */
    AGC_HBRIDGE_PIN_B = 2       /*!< Output Pin B */
};
#endif

#ifndef AGC_OPEN_LOOP_GAIN_UNIT
#define AGC_OPEN_LOOP_GAIN_UNIT
enum tagAGC_OPEN_LOOP_GAIN_UNIT_E           /*!< List Open Loop Gain Units */
{
    AGC_OPEN_LOOP_GAIN_UNIT_NONE = 0,                   /*!< None */
    AGC_OPEN_LOOP_GAIN_UNIT_DPS__A = 1,                 /*!< Deegre per second / Amp */
    AGC_OPEN_LOOP_GAIN_UNIT_ONE_M_S__A = 2,             /*!< 1/m per second / Amp */
    AGC_OPEN_LOOP_GAIN_UNIT_DPS__PCNT = 3,              /*!< Deegre per second / percent */
    AGC_OPEN_LOOP_GAIN_UNIT_ONE_M_S__PCNT = 4,          /*!< 1/m per second / percent */
    AGC_OPEN_LOOP_GAIN_UNIT_DPS__RPM = 5,               /*!< Deegre per second / Rpm */
    AGC_OPEN_LOOP_GAIN_UNIT_ONE_M_S__RPM = 6,           /*!< 1/m per second / Rpm */
};
#endif

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/****************************** Guidance Configuration ************************/
/* General Configuration */
typedef struct tagAUTOGUIDE_COMMAND_P31
{
    uint8_t  Page;
    uint8_t  UserSensitivity;                   /* Sets general aggressiveness; Unit none; Factor 1; Offset 0; Value from 0 to 250; SAEpc06 */                     
    uint8_t  SteeringActuatorType;              /* Value from AGC_VEHICLE_STEER_ACTUATOR_TYPES */
    uint8_t  TerrainCompensation;               /* Value from AUTOGUIDE_TERRAIN_COMPENSATIONS */
    uint8_t  CFG_ApproachAggressiveness;        /* Factor 0.1; Offset 0 */
    uint8_t  CFG_OnLineAggressivenessLowSpeed;  /* Factor 0.1; Offset 0 */
    uint8_t  CFG_OnLineAggressivenessHighSpeed; /* Factor 0.1; Offset 0 */
    uint8_t  WheelPotentiometerUsage;           /* Indicates wether if Wheel Potentiometer will be used for guidance or not */ /* MM */
} AUTOGUIDE_COMMAND_P31_T;

typedef struct tagAUTOGUIDE_COMMAND_P32
{
    uint8_t  Page;
    uint8_t  MotorDisengageSensitivity; /* Value from AUTOGUIDE_MOTOR_DISENGAGE_SENSITIVITYS */
    uint16_t MaxEngageDistance;         /* Distance engage threshold; Units mm; Factor 1; Offset 0;  SAEds12 */
    uint16_t MaxEngageAngle;            /* Angle engage threshold; Units degrees; Factor 1/128; Offset 0; SAEad05 */
    uint16_t MaxEngageSpeed;            /* Maximum speed allowed for automatic engage; Units mm/sec; Factor 1; Offset 0 */
} AUTOGUIDE_COMMAND_P32_T;

typedef struct tagAUTOGUIDE_COMMAND_P33
{
    uint8_t  Page;
    uint8_t  CFG_TablePoint;            /* Value from AGC_SPEED_TABLE_POINT; the remaining parameters are indexed accordingly to this one */
    uint16_t CFG_SpeedValue;            /* Vehi cle speed; Units mm/sec; Factor 1; Offset 0 */
    uint16_t CFG_CabinFilterConst;      /* Factor 1/1000; Offset 32.767*/
    uint16_t CFG_HeadingFilterConst;    /* Factor 1/1000; Offset 32.767*/
} AUTOGUIDE_COMMAND_P33_T;

typedef struct tagAUTOGUIDE_COMMAND_P34
{
    uint8_t  Page;
    uint8_t  DemoMode;                  /* Indicates whether CANSteer is working in Demo Mode (1) or not (0) */
    uint8_t  GuidanceLookahead;         /* Unused */
    unsigned int        bfLowSpeedEngage          :2;   /* 0: Disabled; 1: Enabled */
    unsigned int        bfBackwardsGuidance       :2;   /* 0: Disabled; 1: Enabled */
    unsigned int        bfCalibrationComplete     :2;   /* 0: No ready for engage, one or more calibrations not complete; 1: Ready for engage */
    unsigned int        bfHeadingMergeEnabled     :2;   /* 0: Disabled; 1: Enabled */
    uint8_t  PilotSA;                    /* Source address from Pilot module*/
    unsigned int        bfPreEngage               :2;   /* 0: Disabled; 1: Enabled */
    unsigned int        bfShuttleShift            :2;   /* 0: Disabled; 1: Enabled */
    unsigned int        bfSpeedSignSync           :2;   /* 0: Disabled; 1: Enabled */
    unsigned int        bfWheelSensorFilter     :2;   /* 0: Disabled; 1: Enabled */
    uint16_t Rvd4;
} AUTOGUIDE_COMMAND_P34_T;

/* IMUs Configuration */
typedef struct tagAUTOGUIDE_COMMAND_P35
{
    uint8_t  Page;
    uint8_t  MountingPosition;       /* Value from AUTOGUIDE_MOUNTING_POSITIONS */     
    uint16_t RollMountingBiasAngle;  /* Units degree; Factor 1/256; Offset 125; SAEad07 */
    uint8_t  HeadingCompMode;        /* Value from AUTOGUIDE_HEADING_COMPENSATION_MODES */   
    uint16_t PitchMountingBiasAngle; /* Units degree; Factor 1/256; Offset 125; SAEad07 */
    uint8_t  Rvd1;
} AUTOGUIDE_COMMAND_P35_T;

typedef struct tagAUTOGUIDE_COMMAND_P36 /* Old IMU calibration procedure */
{
    uint8_t  Page;
    uint8_t  IMU_Parameter;         /* Value from AUTOGUIDE_PARAMETERS (IMUs) */
    uint32_t IMU_Value;             /* Various scales; Indexed by Parameter */
    uint16_t Rvd1;
} AUTOGUIDE_COMMAND_P36_T;

typedef struct tagAUTOGUIDE_COMMAND_P37
{
    uint8_t  Page;
    uint8_t  MaxForwardSpeed;       /* Factor 1/10 m/s/bit; Offset 0 m/s */
    uint8_t  MaxBackwardSpeed;      /* Factor 1/10 m/s/bit; Offset 0 m/s */
    uint8_t  MaxAcceleration;       /* Factor 1/10 m/s^2/bit; Offset 0 m/s^2 */
    uint8_t  MaxDecceleration;      /* Factor 1/10 m/s^2/bit; Offset 0 m/s^2 */
    uint8_t  ManualSpeedCtrl;
    uint8_t  ManualSteeringCtrl;
    uint8_t  Rvd1;
} AUTOGUIDE_COMMAND_P37_T;

/* GUIDANCE GENERAL GAIN Configuration */
typedef struct tagAUTOGUIDE_COMMAND_P38
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t GuidanceHighSpeedGeneralGain;      /* Units %; Factor 1; Offset 0; */
    uint16_t GuidanceLowSpeedGeneralGain;       /* Units %; Factor 1; Offset 0; */
    uint16_t Rvd2;
} AUTOGUIDE_COMMAND_P38_T;

typedef struct tagAUTOGUIDE_COMMAND_P39
{
    uint8_t  Page;
    uint8_t  OverrideSensorType;
    uint16_t OverrideRestValue;
    uint16_t OverrideDeltaValue;
    uint16_t Rvd1;
} AUTOGUIDE_COMMAND_P39_T;

/* Steering Column Par�meters */
typedef struct tagAUTOGUIDE_COMMAND_P40
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t SteeringWheelDiameter;     /* Units mm; Factor 1; Offset 0; SAEds12 */
    uint32_t Rvd2;
    //uint16_t SteeringToWheelRelation;   /* Implementation pending; Steering angle to wheel angle relation; Units none; Factor 1/128; Offset 0; SAEad05 */ /* MM */
} AUTOGUIDE_COMMAND_P40_T;

typedef struct tagAUTOGUIDE_COMMAND_P41
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t CWFreePlayAngle;           /* FreePlay angle ClockWise; Units degree; Factor 1/128; Offset 0; SAEad05 */
    uint16_t CCWFreePlayAngle;          /* FreePlay angle CounterClockWise; Units degree; Factor 1/128; Offset 0; SAEad05 */
    uint16_t Rvd2;
} AUTOGUIDE_COMMAND_P41_T;

/* Wheel Sensor parameters */
typedef struct tagAUTOGUIDE_COMMAND_P42
{
    uint8_t   Page;
    unsigned int        bfValvePolarity     :2;   /* 0: Direct; 1: Inverse */
    unsigned int        bfWASExtSource      :2;   /* 0: WAS powered by internal source; 1: WAS powered by external source */
    unsigned int        Rvd1                :2;
    unsigned int        Rvd2                :2;
    uint16_t  Rvd3;
    uint16_t  Rvd4;
    uint8_t   MaxPositionLeft;
    uint8_t   MaxPositionRight;
} AUTOGUIDE_COMMAND_P42_T;

typedef struct tagAUTOGUIDE_COMMAND_P43
{
    uint8_t   Page;
    uint8_t   Point;            /* Index value in wheel sensor calibration table; Factor 1; Offset 0; Range 0 to 6 */
    uint16_t  PotValue;         /* Wheel sensor tension for Point in calibration table; Units Volts; Factor 0.01; Offset 0 */
    uint16_t  AngleValue;       /* Real Angle for Point in calibration table; Units degree; Factor 1/256; Offset 125*/
    uint16_t  CurvatureValue;   /* Real Curvature for Point in calibration table; Units m^-1; Factor 0.00025 m^-1/bit; Offset 8.032 m^-1*/
} AUTOGUIDE_COMMAND_P43_T;

typedef struct tagAUTOGUIDE_COMMAND_P44
{
    uint8_t   Page; 
    uint16_t  WAE_K_CW;    /* Initial K parameter for Wheel Angle Estimator; Factor = 0.0001 Offset = 0.1 */
    uint16_t  WAE_K_CCW;   /* Initial K parameter for Wheel Angle Estimator; Factor = 0.0001 Offset = 0.1 */
    uint8_t   WAE_Deadzone_deg;
    uint16_t  Rvd2;
} AUTOGUIDE_COMMAND_P44_T;

/**************************** Std Electric ************************************/
typedef struct tagAUTOGUIDE_COMMAND_P45
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t SteerMotorCurrent;         /* Nominal current for Std. Electric; Units Ampere; Factor 0.001; Offset 0 */
    uint16_t SteerMotorRiseTime;        /* Value for Std. Electric calibration; Units miliseconds; Factor 0.01; Offset 0; SAEtm01 */
    uint16_t SteerMotorDelayTime;       /* Value for Std. Electric calibration; Units miliseconds; Factor 0.01; Offset 0; SAEtm01 */
} AUTOGUIDE_COMMAND_P45_T;

typedef struct tagAUTOGUIDE_COMMAND_P46
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t MaxSteerMotorSpeed;    /* Absolute maximum speed for Std. Electric; Units rpm; Factor 0.125; Offset 0 */
    uint16_t CFG_MotorSpeedLow;     /* Max Std. Electric Speed when low vehicle speed; Unit rpm; Factor 0.125; Offset 0 */                      
    uint16_t CFG_MotorSpeedHigh;    /* Max Std. Electric Speed when high vehicle speed; Unit rpm; Factor 0.125; Offset 0 */                      
} AUTOGUIDE_COMMAND_P46_T;

/****************************** Hydraulic Valve *******************************/
typedef struct tagAUTOGUIDE_COMMAND_P50
{
    uint8_t  Page;
    uint8_t  HighSide;           /* Value from AGC_HIGH_SIDE_WORKING_MODE */
    uint16_t FreqPWM;            /* PWM for hydraulic valve; Units Hz; Factor 1; Offset 0 */
    uint16_t MaxDutyLowSpeed ;   /* Max PWM for Hydraulic valve when vehicle speed is "LowSpeed"; Units %; Factor 0.1; Offset 100 */
    uint16_t MaxDutyHighSpeed;   /* Max PWM for Hydraulic valve when vehicle speed is "HighSpeed"; Units %; Factor 0.1; Offset 100 */
} AUTOGUIDE_COMMAND_P50_T;

typedef struct tagAUTOGUIDE_COMMAND_P51
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint8_t  Point;                /* Index value for H-Bridge parameters, from AGC_HBRIDGE_E (H-Bridge Pins) */
    uint8_t  HBridge;              /* Value from AGC_H_BRIDGE_WORKING_MODE */
    uint16_t HBridgeDutyMin;       /* Min PWM duty in CSteer output; Units %; Factor 0.1; Offset 0 */
    uint16_t HBridgeDutyMax;       /* Max PWM duty in CSteer output; Units %; Factor 0.1; Offset 0 */
} AUTOGUIDE_COMMAND_P51_T;

typedef struct tagAUTOGUIDE_COMMAND_P52
{
    uint8_t Page;
    uint8_t Rvd1;
    uint8_t MinActPos_PCNT;   /* Minimun positive actuation value in percentage; Units %; Factor 2; Offset 0 */
    uint8_t MinActNeg_PCNT;   /* Minimun negative actuation value in percentage; Units %; Factor 2; Offset 0 */
    uint8_t MaxActPos_PCNT;   /* Maximun positive actuation value in percentage; Units %; Factor 2; Offset 0 */
    uint8_t MaxActNeg_PCNT;   /* Maximun negative actuation value in percentage; Units %; Factor 2; Offset 0 */
    uint16_t VBatt;             /* Battery voltage at the moment of calibration; Units Volts; Factor 0.01; Offset 0 */
} AUTOGUIDE_COMMAND_P52_T;

typedef struct tagAUTOGUIDE_COMMAND_P53
{
    uint8_t   Page;
    uint8_t   ParametersUnit;
    uint8_t   MaxLinearOutputPositive;   /* Max Linear Output Positive for actuator */
    uint8_t   MaxLinearOutputNegative;   /* Max Linear Output Negative for actuator */
    uint16_t  MaxGainPositive;           /* Max Gain Positive for actuator */
    uint16_t  MaxGainNegative;           /* Max Gain Negative for actuator */
} AUTOGUIDE_COMMAND_P53_T;

typedef struct tagAUTOGUIDE_COMMAND_P54
{
    uint8_t  Page;
    uint8_t  Rvd1; 
    uint16_t OLGainPos;   /* Open loop gain mapped with positive actuation value; Units PCNT/[m^-1]; Factor 30; Offset 1000 */
    uint16_t OLGainNeg;   /* Open loop gain mapped with negative actuation value; Units PCNT/[m^-1]; Factor 30; Offset 1000 */
    uint16_t Rvd2;        
} AUTOGUIDE_COMMAND_P54_T;

/******************************* Headland Turn ********************************/
typedef struct tagAUTOGUIDE_COMMAND_P55
{
    uint8_t  Page;
    uint8_t  HeadlandTurn_Aggressiveness_s;   /* Aggressiveness for HeadlandTurn Factor 0.1; Offset 0 */
    uint16_t HeadlandSpeed_mps; /* Maximum Speed for headland turn; Units mm/sec; Factor 1; Offset 0 */
    uint16_t ActuatorSpeed;     /* Actuator Speed; Factor 0.1; Offset 0 */
    uint16_t ActuatorDelay;     /* Actuator Delay; Factor 0.01 sec/bit; Offset 0 */
} AUTOGUIDE_COMMAND_P55_T;

typedef struct tagAUTOGUIDE_COMMAND_P56
{
    uint8_t  Page;
    unsigned int        bfSymmetricalHLPattern  :2;
    unsigned int        Rvd1                    :2;
    unsigned int        Rvd2                    :2;
    unsigned int        Rvd3                    :2;
    uint16_t MinimumRadiusRight;    /* Units mm; Factor 1; Offset 0; SAEds12 */
    uint16_t MinimumRadiusLeft;     /* Units mm; Factor 1; Offset 0; SAEds12 */
    uint16_t ExitAppertureOffset;   /* Units mm; Factor 1; Offset 32000*/
} AUTOGUIDE_COMMAND_P56_T;

/********************* Hydraulic valve control by current *********************/
typedef struct tagAUTOGUIDE_COMMAND_P57
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t Rvd2;
    uint16_t Rvd3;
    uint8_t  DitherAmp;                 /* Dither amplitude for proportional hydraulic valve; Units mA; Factor 1; Offset 0 */
    uint8_t  DitherFreq;                /* Dither frequency for proportional hydraulic valve; Units Hz; Factor 1; Offset 0 */
} AUTOGUIDE_COMMAND_P57_T;

typedef struct tagAUTOGUIDE_COMMAND_P58
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t HBridgeMaxCurrent;     /* Maximun value of current for hydraulic valve control by current; Units A; Factor 0.001; Offset 0 */
    uint16_t Rvd2;
    uint16_t Rvd3;
} AUTOGUIDE_COMMAND_P58_T;

/******************************** Direct Drive ********************************/
typedef struct tagAUTOGUIDE_COMMAND_P61
{
    uint8_t   Page;
    uint8_t   DD_DisengageSensitivity;  /* Units %; Factor 1; Offset 0 */
    uint16_t  DD_MaxSpeed;              /* Unit rpm; Factor 0.1; Offset 0 */
    uint16_t  DD_MaxTorque;             /* Unit %; Factor 0.1; Offset 0 */
    uint16_t  DD_StopFactor;            /* Makes motor drecrease speed more or less smoothly; Range 0 to 999 */
} AUTOGUIDE_COMMAND_P61_T;

typedef struct tagAUTOGUIDE_COMMAND_P63
{
    uint8_t   Page;
    uint8_t   DD_ApproachSpeedFactor; /* Gain for Max Speed when CANSteer is on approach; Factor 0.05; Offset 0 */
    uint16_t  DD_DeadBand;      /* Position Control Dead Band; Unit degree; Factor 0.05; Offset 0 */
    uint16_t  DD_TorqueKP;      /* Proportional Gain Torque Loop; Factor 1; Offset 0 */
    uint16_t  DD_TorqueKI;      /* Integral Gain Torque Loop; Factor 1; Offset 0 */
} AUTOGUIDE_COMMAND_P63_T;

typedef struct tagAUTOGUIDE_COMMAND_P64
{
    uint8_t   Page;
    uint8_t   Rvd1;
    uint16_t  DD_PropLoopPosGain;       /* Position gain for proportional loop; Factor 1; Offset 0 */
    uint16_t  DD_PropLoopSpeedGain;     /* Speed Gain for proportional loop; Factor 1; Offset 0 */
    uint16_t  DD_PropErrorSaturation;   /* Position error saturation; Unit degree; Factor 0.05; Offset 0 */
} AUTOGUIDE_COMMAND_P64_T;

typedef struct tagAUTOGUIDE_COMMAND_P65
{
    uint8_t   Page;
    uint8_t   Rvd1;
    uint16_t  DD_IntegralLoopPosGain;       /* Position gain for integral loop; Factor 1; Offset 0 */
    uint16_t  DD_IntegralLoopSpeedGain;     /* Speed Gain for integral loop; Factor 1; Offset 0 */
    uint16_t  DD_IntegralErrorSaturation;   /* Integrator saturation; Factor 1; Offset 0 */
} AUTOGUIDE_COMMAND_P65_T;

typedef struct tagAUTOGUIDE_COMMAND_P66
{
    uint8_t   Page;
    uint8_t   Index;            /* Value 0 o 1; Values in this page come from calibration !Do Not Modify! */
    uint16_t  DD_Hall_1_4;      /* If Index = 0 first hall flank else fourth hall flank */
    uint16_t  DD_Hall_2_5;      /* If Index = 0 second hall flank else fifth hall flank */
    uint16_t  DD_Hall_3_6;      /* If Index = 0 third hall flank else sixth hall flank */
} AUTOGUIDE_COMMAND_P66_T;

typedef struct tagAUTOGUIDE_COMMAND_P67
{
    uint8_t   Page;
    uint8_t   PilotAddress;     /* Source address that controls DirectDrive */
    uint16_t  Rvd1;
    uint16_t  Rvd2;
    uint16_t  Rvd3;
} AUTOGUIDE_COMMAND_P67_T;

typedef struct tagAUTOGUIDE_COMMAND_P68       /* ESi2 Disengage */
{
    uint8_t   Page;
    uint8_t   MaxCurrent;             /* Units .1 Amp; Factor 10; Offset 0;  */        
    uint16_t  MaxTime_ms;           /* Units mSec;   Factor 1; Offset 0;  */          
    uint8_t   OverCurrent;             /* Units .1 Amp; Factor 10; Offset 0;  */
    uint8_t   RPMerror;             /* Units .1 RPM; Factor 10; Offset 0;  */
    uint8_t   OverTime;           /* Units .1 Sec; Factor 10; Offset 0;  */
    uint8_t   Rvd1;
} AUTOGUIDE_COMMAND_P68_T;

/******************************** TERRAN ********************************/
typedef struct tagAUTOGUIDE_COMMAND_P71
{
    uint8_t   Page;
    uint8_t   Rvd1;             /*  */
    uint16_t  T_SpeedKP;        /* Proportional Gain PID Speed; Factor 0.01; Offset 0 */
    uint16_t  T_SpeedKI;        /* Integral Gain PID Speed; Factor 0.01; Offset 0 */
    uint16_t  T_SpeedKD;        /* Derivative Gain PID Speed; Factor 0.01; Offset 0 */
} AUTOGUIDE_COMMAND_P71_T;

typedef struct tagAUTOGUIDE_COMMAND_P72
{
    uint8_t   Page;
    uint8_t   Rvd1;             
    uint16_t  T_YawRateKP;      /* Proportional Gain PID YawRate; Factor 0.01; Offset 0 */
    uint16_t  T_YawRateKI;      /* Integral Gain PID YawRate; Factor 0.01; Offset 0 */
    uint16_t  T_YawRateKD;      /* Derivative Gain PID YawRate; Factor 0.01; Offset 0 */
} AUTOGUIDE_COMMAND_P72_T;

typedef struct tagAUTOGUIDE_COMMAND_P73
{
    uint8_t   		Page;
    uint16_t        T_MaxMotorTorque;           /* Motor Torque Max; Unit Nm; Factor 0.01; Offset 0 */
    uint16_t        T_MaxPercentageTorque;      /* Max Percentage of Motor torque applied; Unit %; Factor 0.01; Offset 0 */
    uint16_t  		T_SpeedDeadZone_mps;     	/* Minimun speed to disable integrators; Factor 0.01; Offset 0 */
    unsigned int    Rsvd0               : 2;    
    unsigned int    T_EnableDeadBand    : 2;    /* 0 = Disable speed dead band; 1 = Enable speed dead band */
    unsigned int    Rvd1                : 4;    
} AUTOGUIDE_COMMAND_P73_T;

/******************************** TERRAN ********************************/

/********************* Open loop gain Table *********************/
typedef struct tagAUTOGUIDE_COMMAND_P80
{
    uint8_t  Page;
    uint8_t  Rvd1;                                 /* Index value in open loop gain calibration table; Factor 1; Offset 0; Range 0 to 6 */
    uint16_t MaxMotorSpeed_RPM;    /* Open loop gain actuation value for Point in open loop gain Positive table; Units % or RPM; Factor 0.01; Offset 300 */
    uint32_t Rvd2;         /* Open loop gain actuation value for Point in open loop gain Positive table; Units deg/seg; Factor 0.000001; Offset 0 */       
} AUTOGUIDE_COMMAND_P80_T;

typedef struct tagAUTOGUIDE_COMMAND_P81
{
    uint8_t  Page;
    uint8_t  SourceAddress_actuatorBus;      /* Source address of the actuatr bus - for PVE-CL-> HPExtSA */
    uint8_t  Offset_base;                    /* offset base PVED-CL */
    uint8_t  Rvd1;     
    uint16_t  Rvd2;
    uint16_t  Rvd3;
} AUTOGUIDE_COMMAND_P81_T;


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

/* End of $Workfile: AGC_CONFIGURATION_canmsg.h$ */

