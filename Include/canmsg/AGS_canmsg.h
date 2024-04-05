#ifndef AGS_CANMSG_H
#define AGS_CANMSG_H

/*!\page AGS AutoGuide Status
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tag_AGS_STEERING_ENGAGE_STATE_E         /*!< List of Steering Engage status */
{
    AGS_STEERING_ENGAGE_STATE_ENGAGED                                =  0, /*!< Steering is following path */
    AGS_STEERING_ENGAGE_STATE_ON_APPROACH                            =  1, /*!< Steering is approaching path */
    AGS_STEERING_ENGAGE_STATE_ENGAGE_ALLOWED                         =  2, /*!< Steering is ready to engage */
    AGS_STEERING_ENGAGE_STATE_DISENGAGED                             =  3, /*!< Steering is disengaged, conditions are not ok to engage */
    AGS_STEERING_ENGAGE_STATE_PRE_ENGAGE_ACTIVE                      =  4, /*!< Steering is disengaged, with Pre Engage Active */
    AGS_STEERING_ENGAGE_STATE_PRE_ENGAGE_ALLOWED                     =  5, /*!< Steering is disengaged, with Pre Engage Allowed*/
    AGS_STEERING_ENGAGE_STATE_CALIBRATING                            =  6, /*!< Steering is performing generic calibration - WILL BE DISCARDED IN FUTURE RELEASE */
    AGS_STEERING_ENGAGE_STATE_TURNING_HEADLAND                       =  7, /*!< Steering is turning in headland */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_ROLL                       =  8, /*!< Steering is performing roll calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_DMC                        =  9, /*!< Steering is performing DMC calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_HYDRAULIC_ACTUATOR         = 10, /*!< Steering is performing hydraulic actuator calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_HYDRAULIC_ACTUATOR_MANUAL  = 11, /*!< Steering is performing manual hydraulic actuator calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_WHEEL_SENSOR               = 12, /*!< Steering is performing wheel sensor calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_DIRECT_DRIVE               = 13, /*!< Steering is performing Direct Drive calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_TURN_RADIUS                = 14, /*!< Steering is performing turn radius calibration */
    AGS_STEERING_ENGAGE_STATE_HEADLAND_PENDING                       = 15, /*!< Steering received valid headland command. Is waiting for headland start */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_WHEEL_ESTIMATOR            = 16, /*!< Steering is performing wheel estimator calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_OVERRIDE_SENSOR            = 17, /*!< Steering is performing override sensor calibration */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_OPEN_LOOP_GAIN_ESTIMATOR   = 18, /*!< Steering is performing open loop gain calibracion */
    AGS_STEERING_ENGAGE_STATE_CALIBRATING_WHEEL_LOCK                 = 19, /*!< Steering is performing open loop gain calibracion */
    AGS_STEERING_ENGAGE_STATE_ERROR                                  = 200 /*!< Error condition */
} AGS_STEERING_ENGAGE_STATE_E;

typedef enum tag_AGS_SPEED_ENGAGE_STATE_E         /*!< List of Speed Engage status */
{
    AGS_SPEED_ENGAGE_STATE_ENGAGED                                  =  0, /*!< Speed is following path */
    AGS_SPEED_ENGAGE_STATE_ON_APPROACH                              =  1, /*!< Speed is approaching path */
    AGS_SPEED_ENGAGE_STATE_ENGAGE_ALLOWED                           =  2, /*!< Speed is ready to engage */
    AGS_SPEED_ENGAGE_STATE_DISENGAGED                               =  3, /*!< Speed is disengaged, conditions are not ok to engage */
    AGS_SPEED_ENGAGE_STATE_HEADLAND_TURN							=  4, /*!< Speed is doing a headland turn */
    AGS_SPEED_ENGAGE_STATE_ERROR                                    = 200 /*!< Error condition */
} AGS_SPEED_ENGAGE_STATE_E;

typedef enum tag_AGS_HEADING_STATUS_E         /*!< List of Heading status */
{
    AGS_HEADING_STATUS_NOT_READY                            = 0,
    AGS_HEADING_STATUS_ONLY_GPS_COURSE                      = 1,
    AGS_HEADING_STATUS_ONLY_GPS_COURSE_AND_HEADING          = 2,
    AGS_HEADING_STATUS_COMPENSATED_COURSE                   = 3,
    AGS_HEADING_STATUS_COMPENSATED_COURSE_AND_HEADING       = 4
} AGS_HEADING_STATUS_E;

typedef enum tag_AGS_SPEED_STATUS_E         /*!< List of Speed status */
{
    AGS_SPEED_STATUS_VALID                             = 0,
    AGS_SPEED_STATUS_UNDETERMINED                      = 1,
    AGS_SPEED_STATUS_INCONSISTENT                      = 2
} AGS_SPEED_STATUS_E;

typedef enum tag_AGS_GUIDANCE_LOCALIZER_MODE_E         /*!< List of Guidance localizer mode */
{
    AGS_GUIDANCE_LOCALIZER_MODE_NONE                   	= 0, /*!< No localizer */
    AGS_GUIDANCE_LOCALIZER_MODE_GLOBAL                 	= 1, /*!< Looking at global localizer */
    AGS_GUIDANCE_LOCALIZER_MODE_LOCAL                  	= 2  /*!< Looking at local localizer */
} AGS_GUIDANCE_LOCALIZER_MODE_E;

typedef enum tag_AGS_GUIDANCE_STATUS_E         /*!< List of Guidance Status */
{
    AGS_GUIDANCE_STATUS_LOCALIZER_OK                   	= 10, /*!< No error */
    AGS_GUIDANCE_STATUS_EMPTY_LIST                 		= 11, /*!< Bezier list is empty */
    AGS_GUIDANCE_STATUS_LOCALIZER_ERROR               	= 12, /*!< Error status */
	AGS_GUIDANCE_STATUS_PATH_FINISHED                  	= 13, /*!< Bezier list end */
	AGS_GUIDANCE_STATUS_PATH_FINISHING                  = 14  /*!< Lookahead detect a end path */
} AGS_GUIDANCE_STATUS_E;

typedef enum tag_AGS_STEER_MOTOR_STATUS                 /*!< List of possible Std Electric Error */
{ 
    AGS_MOTOR_STATUS_OK = 0,                          /*!< No error */
    AGS_MOTOR_STATUS_OVERCURRENT = 1,                 /*!< Too high current detected */
    AGS_MOTOR_STATUS_PULSES_ERROR = 2,                /*!< Encoder error detected */
    AGS_MOTOR_STATUS_OPEN_LOAD = 3,                 /*!< No load detected on motor */
    AGS_MOTOR_STATUS_ORIENTATION_ERROR = 4          /*!< Motor turn orientation is inverted */
} AGS_STEER_MOTOR_STATUS_E;



/******************************************************************************/
/********************************** New Enum **********************************/
/******************************************************************************/



typedef enum tag_AGS_WHEEL_ANGLE_ESTIMATOR_STATUS       /*!< List of possible Wheel Angle Estimator Status */
{ 
    AGS_WHEEL_ANGLE_ESTIMATOR_STATUS_INACTIVE = 0,          /*!< Wheel Angle Estimator is not being used */
    AGS_WHEEL_ANGLE_ESTIMATOR_STATUS_ACTIVE = 1,            /*!< Wheel Angle Estimator is being used */
    AGS_WHEEL_ANGLE_ESTIMATOR_STATUS_CALIBRATING = 2,       /*!< Wheel Angle Estimator is calibrating */
    AGS_WHEEL_ANGLE_ESTIMATOR_STATUS_INITIALISING = 3,      /*!< Wheel Angle Estimator is using WAE_K_Initial to initialise */
    AGS_WHEEL_ANGLE_ESTIMATOR_STATUS_ERROR = 4              /*!< Wheel Angle Estimator failed. Recalibration is needed */
} AGS_WHEEL_ANGLE_ESTIMATOR_STATUS_E;

typedef enum tagAGS_MOVEMENT_COMMAND_DURATION_TYPES
{
    AGS_MOVEMENT_COMMAND_DURATION_TYPE_NONE_E           = 0,    /*!<  */
    AGS_MOVEMENT_COMMAND_DURATION_TYPE_TIME_E           = 1,    /*!<  */
    AGS_MOVEMENT_COMMAND_DURATION_TYPE_DISTANCE_E       = 2,    /*!<  */
    AGS_MOVEMENT_COMMAND_DURATION_TYPE_DELTA_HEADING_E  = 3,    /*!<  */
} AGS_MOVEMENT_COMMAND_DURATION_TYPES_E;

typedef enum tagAGS_CRD_MODE_E
{
    AGS_CRD_MODE_DISABLED                           = 0,
    AGS_CRD_MODE_AUTO                               = 1,
    AGS_CRD_MODE_FORCED                             = 2,
} AGS_CRD_MODE_E;

/* Defines ********************************************************************/
#define PGN_AUTOGUIDE_STATUS                0xFFF6U
#define SIZE_AUTOGUIDE_STATUS               8U  

#define NON_SUITABLE_VALUE_U16              0xFB01U
/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/* AutoGuide Status PAGE 0 */
typedef struct tagAUTOGUIDE_STATUS_P0
{
    uint8_t  Page;
    uint8_t  SteeringEngageState;               /* Value from AGS_STEERING_ENGAGE_STATE_E */
    uint8_t  SpeedEngageState;                  /* Value from AGS_SPEED_ENGAGE_STATE_E */
    uint8_t  TerrainCompensationStatus;         /* Value from AGC_TERRAIN_COMPENSATIONS */
    uint8_t  IMU_Status;                        /* Error code for imu diagnostic; Returns always 0 */
    uint8_t  SteerMotorStatus;                  /* Value from AGS_STEER_MOTOR_STATUS_E */
    uint8_t  DistancetoHeadland;                /* Distance to AutoTurn entry point; Factor 0.1 m/bit; Offset 0 m*/
    uint8_t  DirectDriveStatus;                 /* Value from AGS_DIRECT_DRIVE_STATUS_E */
} AUTOGUIDE_STATUS_P0_T;

/* AutoGuide Status PAGE 1 */
typedef struct tagAUTOGUIDE_STATUS_P1
{
    uint8_t  Page;
    uint8_t  Pattern;                           /* Model output */
    uint16_t HeadingError;                      /* Error to path with Terrain compensation; Units mm; Factor 1; Offset 32767mm */
    uint16_t PassCounter;                       /* Pass number; Factor 1; Offset 32767 */
    uint16_t Guidance_Error;                    /* Error to current trajectory, used for guidance; Units mm; Factor 1; Offset 32767mm */
} AUTOGUIDE_STATUS_P1_T;

/* AutoGuide Status PAGE 2 */
typedef struct tagAUTOGUIDE_STATUS_P2
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t MeanError;                 /* Only avaiable when steer engaged; Units mm; Factor 1; Offset 32767 */
    uint16_t StandardDeviation;         /* Only avaiable when steer engaged; Units cm; Factor 0.001; Offset 30 */
    uint16_t Confidence;                /* Only avaiable when steer engaged; Units cm; Factor 0.001; Offset 30 */
} AUTOGUIDE_STATUS_P2_T;

/* AutoGuide Status PAGE 3 */
typedef struct tagAUTOGUIDE_STATUS_P3
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t RollAngle;                 /* SAEad08; Units degree; Factor 0.002; Offset 64; Range [-64, 64.51] */
    uint16_t PitchAngle;                /* SAEad08; Units degree; Factor 0.002; Offset 64; Range [-64, 64.51] */
    uint16_t YawAngle;                  /* SAEad05; Units Degree; Factor 1/128; Offset 0  */
} AUTOGUIDE_STATUS_P3_T;

/* AutoGuide Status PAGE 4 */
typedef struct tagAUTOGUIDE_STATUS_P4
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t RollRate;                  /* Factor = 0.002 �/seg Offset = 64�/sec SAEva02 */
    uint16_t PitchRate;                 /* Factor = 0.002 �/seg Offset = 64�/sec SAEva02 */
    uint16_t YawRate;                   /* Factor = 0.002 �/seg Offset = 64�/sec SAEva02 */ 
} AUTOGUIDE_STATUS_P4_T;

/* AutoGuide Status PAGE 5 */
typedef struct tagAUTOGUIDE_STATUS_P5
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t UAcceleration;             /* Factor = 1/2048 m/s2  offset = 15.687 m/s2 SAEac01 */
    uint16_t VAcceleration;             /* Factor = 1/2048 m/s2  offset = 15.687 m/s2 SAEac01 */
    uint16_t WAcceleration;             /* Factor = 1/2048 m/s2  offset = 15.687 m/s2 SAEac01 */
} AUTOGUIDE_STATUS_P5_T;

/* AutoGuide Status PAGE 6 */
typedef struct tagAUTOGUIDE_STATUS_P6
{
    uint8_t  Page;
    uint8_t  eMotorDirection;    /* 0: Stopped; 1: Turning Right; 2: Turning Left */
    uint16_t eMotor_SpeedRPM;          /* Factor = 0.125 */
    uint16_t eMotor_RefSpeedRPM;             /* Factor = 0.125 */
    uint16_t Rvd0;
} AUTOGUIDE_STATUS_P6_T;

/* AutoGuide Status PAGE 7 */
typedef struct tagAUTOGUIDE_STATUS_P7
{
    uint8_t  Page;
    uint8_t  ActuatorEnable;
    uint16_t MotorCurrent;              /* Factor 0.001 A/bit Offset = 0 SAEec06 */
    uint16_t MotorVoltage;              /* Factor 0.01 V/bit  Offset = 0 SAEev03 */
    uint16_t MotorPWM;                  /* Factor 0.01 %/bit  Offset = 100 */
} AUTOGUIDE_STATUS_P7_T;

/* AutoGuide Status PAGE 8 */
typedef struct tagAUTOGUIDE_STATUS_P8
{
    uint8_t  Page;
    uint8_t  Rvd0;
    uint16_t WASVoltage;
    uint16_t IMUWheelAngle_deg;
    uint16_t IMUCurvature;
} AUTOGUIDE_STATUS_P8_T;

/* AutoGuide Status PAGE 9 */
typedef struct tagAUTOGUIDE_STATUS_P9
{
    uint8_t             Page;
    unsigned int        bfSpeedSign             :2;     /* 0: Driving backwards; 1: Undefined speed sign; 2: Driving forwards */
    unsigned int        bfAlarmMaxWheelAngleRef :2;     /* 0: No alarm; 1: Wheel angle reference saturation */
    unsigned int        bfAlarmBigThetaDiffLH   :2;     /* 0: No alarm; 1: Big heading error in lookahead point */
    unsigned int        bfABSenseDirect         :2;     /* 0: Sense BA; 1: Sense AB */
    uint16_t            Demo_Curvature;
    uint16_t            HbridgeOutput;
    unsigned int        bfPaused                :2;     /* 0: Active; 1: Paused */
    unsigned int        TP_Active_BOOL          :2;		/* 0: Disable; 1: Enable */
    unsigned int        bfRvd2                  :2;
    unsigned int        bfRvd3                  :2;
    uint8_t             PRYrateBiasComp_Status;
} AUTOGUIDE_STATUS_P9_T;

/* AutoGuide Status PAGE 10 */
typedef struct tagAUTOGUIDE_STATUS_P10
{
    uint8_t  Page;
    uint8_t  WAE_Status;
    uint8_t  WAS_Status;
    uint8_t  Mode;
    uint16_t WASVoltageRaw;
    uint16_t Rvd2;
} AUTOGUIDE_STATUS_P10_T;

/* AutoGuide Status PAGE 11 */
typedef struct tagAUTOGUIDE_STATUS_P11
{
    uint8_t  Page;
    uint8_t  DisengAnalogVoltage;       /* Factor 0.02 V/bit; Offset 0 */
    uint16_t DisengAnalogFreq;          /* Factor 1 Hz/bit  Offset = 0 */
    uint16_t DisengDigitalFreq;         /* Factor 1 Hz/bit  Offset = 0 */
    uint8_t  DisengDigitalDutyCycle;    /* Factor 0.4 %/bit  Offset = 0 */
    uint8_t  DisengEnable;
} AUTOGUIDE_STATUS_P11_T;

/* AutoGuide Status PAGE 12 */
typedef struct tagAUTOGUIDE_STATUS_P12
{
    uint8_t  Page;
    unsigned int SteeringRefSource  :4;     /* Value from AGS_STEERING_REFERENCE_SOURCE_E */
    unsigned int SteeringRefType    :4;     /* Value from AGS_STEERING_REFERENCE_TYPE_E */
    uint8_t Rvd1;
    unsigned int Rvd2               :2;
    unsigned int RFStatusMBE        :1;
    unsigned int RFStatusNM         :1;
    unsigned int RFStatusP          :1;
    unsigned int RFPauseState       :1;
    unsigned int RFRegisteredState  :1;
    unsigned int RFHeartbeatTO      :1;
    uint16_t RFSerialBTN;
    uint16_t RFSerialTO;
} AUTOGUIDE_STATUS_P12_T;

/* AutoGuide Status PAGE 14 */
typedef struct tagAUTOGUIDE_STATUS_P14
{
    uint8_t  Page;
    uint16_t VehicleSpeed;                  /* Factor 0.002 km/h/bit Offset = 64 km/h */
    uint8_t  VehicleSpeedStatus;            /* Value from AGS_SPEED_STATUS_E */
    uint16_t VehicleCourse;                 /* Factor = 0.0001 rad/bit offset = 6.28318 rad */
    uint8_t  VehicleHeadingStatus;          /* Value from AGS_HEADING_STATUS_E */
    uint8_t  GPSFix;                        /* GPS Status */
} AUTOGUIDE_STATUS_P14_T;

/* AutoGuide Status PAGE 17 (0x11) */ /* Debug purposes */
typedef struct tagAUTOGUIDE_STATUS_P17
{
    uint8_t  Page;
    unsigned int Index :4;
    unsigned int Flag0 :1;
    unsigned int Flag1 :1;
    unsigned int Rsvd0 :2;
    unsigned int SteeringSrc :4;
    unsigned int ReferenceTypeSteering :4;
    uint16_t ReferenceValueSteering;
    unsigned int MotionSrc :4;
    unsigned int ReferenceTypeMotion :4;
    uint16_t ReferenceValueMotion;
} AUTOGUIDE_STATUS_P17_T;

/* AutoGuide Status PAGE 20 */
typedef struct tagAUTOGUIDE_STATUS_P20 /* Demo page. Sent by CANSteer when demo mode is on. */
{
    uint8_t  Page;
    uint8_t  Demo_SensorVoltage;
    uint16_t Demo_Speed_kph;            /* Factor 0.002 kph/bit; Offset = 64 kph */
    uint16_t Demo_WheelAngle_deg;       /* Factor 0.001 deg/bit; Offset = 32 deg */
    uint16_t Demo_YawRate_dps;          /* Factor 0.008 �/seg/bit Offset = 256 �/sec */
} AUTOGUIDE_STATUS_P20_T;

/* AutoGuide Status PAGE  21 */
typedef struct tagAUTOGUIDE_STATUS_P21
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t MeasuredCurvature;         /* Factor 0.00025 m^-1/bit Offset = 8.032 m^-1 */
    uint16_t DesiredCurvature;          /* Factor 0.00025 m^-1/bit Offset = 8.032 m^-1 */
    uint16_t EstimatedCurvature;         /* Factor 0.00025 m^-1/bit Offset = 8.032 m^-1 */
} AUTOGUIDE_STATUS_P21_T;

/* AutoGuide Status PAGE  21 */
typedef struct tagAUTOGUIDE_STATUS_P22
{
    uint8_t  Page;
    uint8_t  Index;
    uint32_t Position_NED_m;
    uint16_t Course_rad;
} AUTOGUIDE_STATUS_P22_T;

/******************************************************************************/
/********************************* New Pages **********************************/
/******************************************************************************/

/******************************** Direct Drive ********************************/
typedef struct tagAUTOGUIDE_STATUS_P60
{
    uint8_t   Page;
    uint8_t   GeneralStatus;        /* Value from DD_STATUS_E */
    uint16_t  eMotor_ActualPosition;       /* Actual Position; Unit degree; Factor 0.05; Offset 1440 */
    uint16_t  ActualSpeed;          /* Actual Speed; Unit rpm; Factor 0.1; Offset 300 */
    uint16_t  ActualTorque;         /* Actual Torque; Unit %; Factor 0.1; Offset 100 */
} AUTOGUIDE_STATUS_P60_T;

typedef struct tagAUTOGUIDE_STATUS_P61
{
    uint8_t   Page;
    uint8_t   Rvd1;
    uint16_t  DD_RefPosition;       /* Position Reference; Unit degree; Factor 0.05; Offset 1440 (4 complete turns) */
    uint16_t  DD_RefSpeed;          /* Speed Reference; Unit rpm; Factor 0.1; Offset 300 */
    uint16_t  DD_RefTorque;         /* Unit %; Factor 0.1; Offset 100 */
} AUTOGUIDE_STATUS_P61_T;

typedef struct tagAUTOGUIDE_STATUS_P62
{
    uint8_t   Page;
    uint8_t   HallStatus;           /* The three less significant bits represent hall sensor status */
    uint8_t   HallCalibStatus;      /* Hall calibration status */
    uint8_t   ControllerCalibStatus;/* Controller calibration status */
    uint32_t  ErrorCode;            /* Combination of values from AGS_DD_ERROR_E */
} AUTOGUIDE_STATUS_P62_T;

/******************************** ESi2 ********************************/
typedef struct tagAUTOGUIDE_STATUS_P70
{
    uint8_t   Page;
    uint8_t   GeneralStatus;        /* Value from canmsg_esi2.h status */
    uint16_t  ActualPosition;       /* Actual Position; Unit degree; Factor 0.01; Offset 0 */
    uint16_t  ActualSpeed;          /* Actual Speed; Unit rpm; Factor 0.01; Offset 300 */
    uint16_t  ActualCurrent;        /* Actual Torque; Unit %; Factor 0.01; Offset 0 */
} AUTOGUIDE_STATUS_P70_T;

typedef struct tagAUTOGUIDE_STATUS_P71
{
    uint8_t   Page;
    uint8_t   Temperature;          /* Unit �C; Factor 1; Offset 0 */
    uint8_t   BattVoltage;          /* Unit: V; Factor 1; Offset 0 */
    uint8_t   ErrorCode;            /* Value from canmsg_esi2.h error code */
    uint16_t  ESi2_RefSpeed;        /* Speed Reference; Unit rpm; Factor 0.01; Offset 300 */
    uint16_t  ControlMode;          /* Control Mode; Factor 1; Offset 0 */
} AUTOGUIDE_STATUS_P71_T;

/******************************** CropRowDetection ********************************/
typedef struct tagAUTOGUIDE_STATUS_P90
{
    uint8_t     Page;
    uint16_t    Offset;         /* Unit cm; Factor 1; Offset 32.767 */
    uint16_t    Headding;       /* Unit dg; Factor 1; Offset 32.767 */
    uint8_t     Reliability;    /* Unit -; Factor 100; Offset 0 */
    uint8_t     Rvd1_t;         /* Rvd */
    uint8_t     Rvd2_t;         /* Rvd */
} AUTOGUIDE_STATUS_P90_T;

typedef struct tagAUTOGUIDE_STATUS_P91{
    uint8_t  Page;
    uint8_t  Index;
    uint16_t Rvd1;         
    uint32_t ControlPoint_NED_m;      /* Units; Factor 0.00001; Offset = 20000 */
} AUTOGUIDE_STATUS_P91_T;

typedef struct tagAUTOGUIDE_STATUS_P92{
    uint8_t  Page;
    uint8_t  CRDMode;               /* Value from AGS_CRD_MODE_E */
    uint8_t  Rvd1;
    uint8_t  Rvd2;
    uint8_t  Rvd3;
    uint8_t  Rvd4;
    uint8_t  Rvd5;
    uint8_t  Rvd6;
} AUTOGUIDE_STATUS_P92_T;

typedef struct tagAUTOGUIDE_STATUS_P93
{
    uint8_t     Page;
    uint16_t    detectedRelativeHeading;    /* Units rad; Factor 0.001; Offset 32.767 rad */
    uint16_t    rawAbsCropRowHeading;       /* Units rad; Factor 0.001; Offset 32.767 rad */
    uint16_t    filteredAbsCropRowHeading;  /* Units rad; Factor 0.001; Offset 32.767 rad */
    uint8_t     Rvd1_t;                     /* Rvd */
} AUTOGUIDE_STATUS_P93_T;

/******************************************************************************/
/********************************* Debug Pages ********************************/
/******************************************************************************/

/* AutoGuide Status PAGE 208 (0xD0) */
typedef struct tagAUTOGUIDE_STATUS_P208
{
    uint8_t  Page;
    uint8_t  Deadzone_deg;
    uint16_t Rvd1;
    uint16_t PoteBiasCurvature;
    uint16_t Rvd2;                         /* Units: degs; Factor 0.002 Offset = 50 */
} AUTOGUIDE_STATUS_P208_T;

/* AutoGuide Status PAGE 209 (0xD1) */
typedef struct tagAUTOGUIDE_STATUS_P209
{
    uint8_t  Page;
    uint8_t  Index;
    uint32_t Position_NED_m;
    uint16_t Course_rad;
} AUTOGUIDE_STATUS_P209_T;

/* AutoGuide Status PAGE 210 (0xD2) MODEL_STEP_TIME_DEBUG */
typedef struct tagAUTOGUIDE_STATUS_P210
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t Aux_SniffVar7;                             /* Factor 1; Offset 0 */
    uint16_t Aux_SniffVar8;                             /* Factor 1; Offset 0 */
    uint16_t Aux_SniffVar9;                             /* Factor 1; Offset 0 */
} AUTOGUIDE_STATUS_P210_T;

/* AutoGuide Status PAGE 211 (0xD3) */
typedef struct tagAUTOGUIDE_STATUS_P211
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t Rvd2;
    uint16_t Rvd3;
    uint16_t Rvd4;
} AUTOGUIDE_STATUS_P211_T;

typedef struct tagAUTOGUIDE_STATUS_P212
{
    uint8_t  Page;
    uint8_t  Rvd0;
    uint16_t Rvd1;
    uint16_t Rvd2;
    uint16_t Rvd3;
} AUTOGUIDE_STATUS_P212_T;

typedef struct tagAUTOGUIDE_STATUS_P213
{
    uint8_t  Page;
    uint8_t  Rvd0;
    uint16_t OLCalibCurvatureRate;    
    uint16_t FilterSignalDirect;                             
    uint16_t FilterSignalInverse;                       
} AUTOGUIDE_STATUS_P213_T;

typedef struct tagAUTOGUIDE_STATUS_P214
{
    uint8_t  Page;
    uint8_t  HB_Enable;
    uint16_t HB_Current;                     
    uint16_t HB_PWM;                      
    uint16_t HB_FilteredCurrent;                         
} AUTOGUIDE_STATUS_P214_T;

typedef struct tagAUTOGUIDE_STATUS_P215
{
    uint8_t  Page;
    uint8_t  Rvd0;
    uint16_t Rvd1;         
    uint32_t Rvd2;                                
} AUTOGUIDE_STATUS_P215_T;

typedef struct tagAUTOGUIDE_STATUS_P216
{
    uint8_t  Page;
    unsigned int        bfRvd1                  :2;
    unsigned int        FP_Active_BOOL          :2;     /* 0:Disabled; 1: Enabled */
    unsigned int        AutoSyncSpeedSign_BOOL  :2;     /* 0:Nothing;  1: AutoSync */
    unsigned int        DZ_Active_BOOL          :2;		/* 0:Disabled; 1: Enabled */
    uint16_t Speed_Estimated_kph;                            
    uint16_t Kp;                                        /* Factor 0.1; Offset  500 */
    uint16_t LookAhead_m;                             
} AUTOGUIDE_STATUS_P216_T;

typedef struct tagAUTOGUIDE_STATUS_P217
{
    uint8_t  Page;
    uint8_t  Sample;           		    /* Factor 1; Offset 0 */
    uint16_t bias_PitchRate_dps;     	/* Factor = 0.002 �/seg Offset = 64�/sec */    
    uint16_t bias_RollRate_dps;        	/* Factor = 0.002 �/seg Offset = 64�/sec */        
    uint16_t bias_YawRate_dps;         	/* Factor = 0.002 �/seg Offset = 64�/sec */       	
} AUTOGUIDE_STATUS_P217_T;

typedef struct tagAUTOGUIDE_STATUS_P218
{
    uint8_t  Page;
    uint8_t  MeanResult;
    uint16_t YawRate_Estimated_dps;  
    uint16_t YawRate_Raw_dps;       
    uint16_t YawRate_Vehicle_dps;   	
} AUTOGUIDE_STATUS_P218_T;

typedef struct tagAUTOGUIDE_STATUS_P219
{
    uint8_t  Page;
    uint8_t  Mean;
    uint16_t DeltaHydUR_Value;
    uint16_t RestHydUR_Value;
    uint16_t OLGainPos;          
} AUTOGUIDE_STATUS_P219_T;

typedef struct tagAUTOGUIDE_STATUS_P220
{
    uint8_t  Page;
    uint8_t  Delta;
    uint16_t FP_Pulse_RPM;                   /* Units deg; Factor 0.01; Offset 100  */ 
    uint16_t CurvatureRate_SP;
    uint16_t OLGainNeg;
} AUTOGUIDE_STATUS_P220_T;

typedef struct tagAUTOGUIDE_STATUS_P221
{
    uint8_t  Page;
    uint8_t  bCALIBRATION;
    uint16_t pathError_Comp_m;                	/* Error to current trajectory, from antenna position compesated; Units mm; Factor 1; Offset 32767mm */
    uint16_t pathError_GPS_m;                 	/* Error to current trajectory, from GPS position; Units mm; Factor 1; Offset 32767mm */
    uint16_t pathError_Shifted_m;
} AUTOGUIDE_STATUS_P221_T;

typedef struct tagAUTOGUIDE_STATUS_P222
{
    uint8_t  Page;
    uint8_t  ActualLA_m;
    uint8_t  FP_CW;
    uint8_t  FP_CCW;
    uint16_t debug_K_CW;                   
    uint16_t debug_K_CCW;             
} AUTOGUIDE_STATUS_P222_T;

typedef struct tagAUTOGUIDE_STATUS_P223
{
    uint8_t  Page;
    uint8_t  Rvd0;
    uint16_t Rvd1;                     
    uint16_t Rvd2;
    uint16_t Rvd3;
} AUTOGUIDE_STATUS_P223_T;

typedef struct tagAUTOGUIDE_STATUS_P224
{
    uint8_t  Page;
    uint8_t  Rvd0;                                
    uint8_t  TerranState;                               /* Terran state according TERRAN_STATE */
    uint8_t  TerranError;                               /* Terran errors according TERRAN_ERRORS */
    uint8_t  TerranControlMode;                         /* CTRL_MODE_INACTIVE  0 - CTRL_MODE_TORQUE  1 - CTRL_MODE_SPEED  2 */
    uint8_t  TerranControlType;                         /* ACTION_MANUAL  0 - ACTION_AUTOMATIC  1*/
    uint16_t Rvd1;                                      /* */
} AUTOGUIDE_STATUS_P224_T;


/* AutoGuide Status PAGE 225 (0xE1) */
typedef struct tagAUTOGUIDE_STATUS_P225
{
    uint8_t  Page;
    uint16_t VehSpeed;                                  /* Terran input Speed: Unit: kph; Factor 0.01 A/bit; Offset 300 */
    uint16_t commonTorque;                              /* Terran control common torque Unit: Nm; Factor 0.1 A/bit; Offset 3000 */
    uint16_t diffTorque;                                /* Terran control differental torque Unit: Nm; Factor 0.1 A/bit; Offset 3000 */
    uint8_t  Rvd1;                                      /* */
} AUTOGUIDE_STATUS_P225_T;

/* AutoGuide Status PAGE 4 */
typedef struct tagAUTOGUIDE_STATUS_P226
{
    uint8_t  Page;
    uint8_t  TerranFilters_Mode;
    uint16_t Rvd1;                  
    uint16_t SpeedWsComp_mps;        /* Factor = 0.002 �/seg Offset = 64�/sec SAEva02 */
    uint16_t YawRateWsComp_rps;      /* Factor = 0.002 �/seg Offset = 64�/sec SAEva02 */ 
} AUTOGUIDE_STATUS_P226_T;

/* AutoGuide Status PAGE 227 (0xE3) */
typedef struct tagAUTOGUIDE_STATUS_P227
{
    uint8_t  Page;
    uint8_t  Rvd0;
    uint16_t Rvd1;         
    uint32_t Rvd2;                                                 
} AUTOGUIDE_STATUS_P227_T;

/* AutoGuide Status PAGE 228 (0xE4) - Ref Debug purposes */
typedef struct tagAUTOGUIDE_STATUS_P228
{
    uint8_t  Page;
    uint8_t  ReferenceSrc;    
    uint8_t  ReferenceTypeSteering;
    uint16_t ReferenceValueSteering;
    uint8_t  ReferenceTypeMotion;    
    uint16_t ReferenceValueMotion;
} AUTOGUIDE_STATUS_P228_T;



/******************************************************************************/
#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

typedef union tagAUTOGUIDE_STATUS_U
{
    AUTOGUIDE_STATUS_P0_T  P0;
    AUTOGUIDE_STATUS_P1_T  P1;
    AUTOGUIDE_STATUS_P2_T  P2;
    AUTOGUIDE_STATUS_P3_T  P3;
    AUTOGUIDE_STATUS_P4_T  P4;
    AUTOGUIDE_STATUS_P5_T  P5;
    AUTOGUIDE_STATUS_P6_T  P6;
    AUTOGUIDE_STATUS_P7_T  P7;
    AUTOGUIDE_STATUS_P8_T  P8;
    AUTOGUIDE_STATUS_P9_T  P9;
    AUTOGUIDE_STATUS_P10_T  P10;
    AUTOGUIDE_STATUS_P11_T  P11;
    AUTOGUIDE_STATUS_P12_T  P12;
    AUTOGUIDE_STATUS_P14_T  P14;
    AUTOGUIDE_STATUS_P17_T  P17;
    AUTOGUIDE_STATUS_P20_T  P20;
    AUTOGUIDE_STATUS_P21_T  P21;
    AUTOGUIDE_STATUS_P22_T  P22;
    /* New pages for DirectDrive */
    AUTOGUIDE_STATUS_P60_T P60;
    AUTOGUIDE_STATUS_P61_T P61;
    AUTOGUIDE_STATUS_P62_T P62;
    /* New pages for ESi2 actuator */
    AUTOGUIDE_STATUS_P70_T P70;
    AUTOGUIDE_STATUS_P71_T P71;
    /* CropRowDetection */
    AUTOGUIDE_STATUS_P90_T P90;
    AUTOGUIDE_STATUS_P91_T P91;
    AUTOGUIDE_STATUS_P92_T P92;
    AUTOGUIDE_STATUS_P93_T P93;
    /* Debug pages */
    AUTOGUIDE_STATUS_P208_T P208;
    AUTOGUIDE_STATUS_P209_T P209;
    AUTOGUIDE_STATUS_P210_T P210;
    AUTOGUIDE_STATUS_P211_T P211;
    AUTOGUIDE_STATUS_P212_T P212;
    AUTOGUIDE_STATUS_P213_T P213;
    AUTOGUIDE_STATUS_P214_T P214;
    AUTOGUIDE_STATUS_P215_T P215;
    AUTOGUIDE_STATUS_P216_T P216;
    AUTOGUIDE_STATUS_P217_T P217;
    AUTOGUIDE_STATUS_P218_T P218;
    AUTOGUIDE_STATUS_P219_T P219;
    AUTOGUIDE_STATUS_P220_T P220;
    AUTOGUIDE_STATUS_P221_T P221;
    AUTOGUIDE_STATUS_P222_T P222;
    AUTOGUIDE_STATUS_P223_T P223;
    AUTOGUIDE_STATUS_P224_T P224;
    AUTOGUIDE_STATUS_P225_T P225;    
    AUTOGUIDE_STATUS_P226_T P226;
	AUTOGUIDE_STATUS_P227_T P227;
    AUTOGUIDE_STATUS_P228_T P228;
    
} AUTOGUIDE_STATUS_U;

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

/* End of $Workfile: AGS_canmsg.h$ */
