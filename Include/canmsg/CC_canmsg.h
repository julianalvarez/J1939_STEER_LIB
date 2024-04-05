#ifndef CC_CANMSG_H
#define CC_CANMSG_H

/*! \page CC Configure Command
*   \brief <B>PAGE 0 - NonSpec</B>
*   \section sec505 Page:
*   \section sec506 WheelPerimeter:  
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \section sec507 LaborWidth:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \section sec508 LaborWidthPercent:
*      Offset = <B>0</B>, Factor = <B>0.4</B>, Unit = <B>%/bit</B> \n
*   \section sec509 PulsesPerWheel:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>p/bit</B> \n
*   \n
*   \brief <B>PAGE 1 - NonSpec</B>
*   \section sec509 Page:
*   \section sec510 EngineSpeedCalib:  
*      Offset = <B>0</B>, Factor = <B>0.125</B>, Unit = <B>rpm/bit</B> \n
*   \n
*   \brief <B>PAGE 2 - NonSpec</B>
*   \section sec511 Page:
*   \section sec512 PositionCorrection:  
*       to complete \n
*   \section s513 EntryPoint:  
*       to complete \n
*   \section s514 DiffSource:   
*       to complete \n
*   \section sec516 AntennaToPivot:
*      Offset = <B>32000</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \section sec518 PivotToImplement:  
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \section sec517 DistanceBetweenAxes;
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \n
*   \section s500 AntennaToAxe:  
*      Offset = <B>32000</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \section s501 AntennaHeight:  
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \section s502 AntennaOffsetFromCenter;
*      Offset = <B>32000</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*   \n
*   \brief <B>PAGE 0 - Combine</B>
*   \section sec520 Page:
*   \section sec521 CalibrationCommand:
*       0x00 = <B>NONE_DEVICE</B>\n
*       0x01 = <B>HEADER_DEVICE</B>\n
*       0x02 = <B>FAN_DEVICE</B>\n
*       0x03 = <B>REEL_DEVICE</B>\n
*       0x04 = <B>CONCAVE_DEVICE</B>\n
*       0x05 = <B>CYLINDER_DEVICE</B>\n
*   \section sec522 OemHeightLevel:
*       0x01 = <B>LOW_LEVEL</B>\n
*       0x02 = <B>MEDIUM_LEVEL</B>\n
*       0x03 = <B>HIGH_LEVEL</B>\n
*   \section sec523 OemControlType:
*     Ox00 = <B>WITHOUT_TERRAIN_COPIER_CTRLHP</B>\n
*     0x01 = <B>TERRAIN_COPIER_CTRLHP</B>\n
*   \section sec524 ActualControlType:
*     Ox00 = <B>WITHOUT_TERRAIN_COPIER_CTRLHP</B>\n
*     0x01 = <B>TERRAIN_COPIER_CTRLHP</B>\n
*   \section sec525 UserHeightLevel:
*       0x01 = <B>LOW_LEVEL</B>\n
*       0x02 = <B>MEDIUM_LEVEL</B>\n
*       0x03 = <B>HIGH_LEVEL</B>\n
*   \section sec526 AbortCalibrations:
*     0x00 = <B>Continue Calibration</B>\n
*     0x01 = <B>Abort Calibration</B>\n
*   \section sec527 UserSensitivity:
*       0x01 = <B>LOW_LEVEL</B>\n
*       0x02 = <B>MEDIUM_LEVEL</B>\n
*       0x03 = <B>HIGH_LEVEL</B>\n
*   \section sec528 OemSetPoint:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>%/bit</B> \n
*   \section sec529 OemDeadBand:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>%/bit</B> \n
*   \n
*   \brief <B>PAGE 1 - Combine</B>
*   \section sec530 Page:
*   \section sec531 CylinderType:
*     0x00 = <B>PERCENT_UNIT</B>\n
*     0x01 = <B>RPM_UNIT</B>\n
*     0x02 = <B>MM_UNIT</B>\n
*     0x03 = <B>CM_UNIT</B>\n
*   \section sec532 CylinderSetPoint:
*      Offset = <B>0</B>, Factor = <B>0.125</B>, Unit = <B>rpm/bit</B> \n
*   \section sec533 FanSetPoint:
*      Offset = <B>0</B>, Factor = <B>0.125</B>, Unit = <B>rpm/bit</B> \n
*      Offset = <B>0</B>, Factor = <B>0.25</B>, Unit = <B>%/bit</B> \n
*   \section sec534 FanType:
*     0x00 = <B>PERCENT_UNIT</B>\n
*     0x01 = <B>RPM_UNIT</B>\n
*     0x02 = <B>MM_UNIT</B>\n
*     0x03 = <B>CM_UNIT</B>\n
*   \section sec535 ConcaveType:
*     0x00 = <B>PERCENT_UNIT</B>\n
*     0x01 = <B>RPM_UNIT</B>\n
*     0x02 = <B>MM_UNIT</B>\n
*     0x03 = <B>CM_UNIT</B>\n
*   \section sec536 ConcaveSetPoint:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mm/bit</B> \n
*      Offset = <B>0</B>, Factor = <B>0.25</B>, Unit = <B>%/bit</B> \n
*   \n
*   \brief <B>PAGE 2 - Combine</B>
*   \section sec537 Page:
*   \section sec538 PulseOnTimeUp:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \section sec539 PulseOffTimeUp:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \section sec540 PulseOnTimeDown:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \section sec541 PulseOffTimeDown:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \section sec542 PulseOnTimeTilt:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \section sec544 PulseOffTimeTilt:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \section sec545 PulseOnTimeCombine:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \n
*   \brief <B>PAGE 3 - Combine</B>
*   \section sec546 Page:
*   \section sec547 AdaptativeRL: 
*      0x00 = <B>No Adaptative</B> \n
*      0x01 = <B>Adaptative</B> \n
*   \section sec548 PulseOffTimeCombine:
*      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>mseg/bit</B> \n
*   \section sec549 ReelSp:
*      Offset = <B>0</B>, Factor = <B>0.128</B>, Unit = <B>hz/bit</B> \n
*   \section sec550 TolerancePID:
*      Offset = <B>0</B>, Factor = <B>0.128</B>, Unit = <B>hz/bit</B> \n
*   \section sec551 ReelAccuracy:
*      <B>Accuracy = 1/(2^ReelAccuracy)</B>\n
*   \section sec552 ReelSampling:
*      Offset = <B>0</B>, Factor = <B>10</B>, Unit = <B>msg/bit</B> \n
*   \n
*   \brief <B>PAGE 4 - Combine</B>
*   \section sec553 Page:
*   \section sec554 KP: 
*      Offset = <B>0</B>, Factor = <B>1/Accuracy</B>, Unit = <B>na</B> \n
*   \section sec555 KI:
*      Offset = <B>0</B>, Factor = <B>1/Accuracy</B>, Unit = <B>na</B> \n
*   \section sec556 KD:
*      Offset = <B>0</B>, Factor = <B>1/Accuracy</B>, Unit = <B>na</B> \n
*   \section sec557 Type:
*     0x01 = <B>A_TYPE_PID</B>\n
*     0x02 = <B>B_TYPE_PID</B>\n
*     0x03 = <B>C_TYPE_PID</B>\n
*   \section sec558 NewKpAdaptation:
*     0x00 = <B>Old Adaptation</B>\n
*     0x01 = <B>New Adaptation</B>\n
*   \section sec559 NewKiAdaptation:
*     0x00 = <B>Old Adaptation</B>\n
*     0x01 = <B>New Adaptation</B>\n
*   \section sec560 NewKdAdaptation:
*     0x00 = <B>Old Adaptation</B>\n
*     0x01 = <B>New Adaptation</B>\n
*   \section sec561 Mode:
*   \n
*   \brief <B>PAGE 5 - Combine</B>
*   \section sec562 Page:
*   \section sec563 bfAdaptation: 
*     0x00 = <B>No Adaptation</B>\n
*     0x01 = <B>Adaptation</B>\n
*   \section sec564 FiltrateHp:
*   \section sec565 WindowSize:
*   \section sec566 AdaptationTime:
*   \section sec567 AlgorithmType:
*   \section sec568 Divisor:
*   \section sec569 CombineUp:
*   \section sec570 CombineDown:
*   \section sec571 DirectHysteresis:
*   \n  
*   \brief <B>PAGE 6 - Combine</B>
*   \section sec572 Page:
*   \section sec573 DeadBandSpeedCompensation: 
*   \section sec574 DbRelations:
*   \n
*   \brief <B>PAGE 7 - Combine</B>
*   \section sec575 Page:
*   \section sec575 PulseHeightUp:
*   \section sec576 PulseHeightDw:
*   \section sec577 PulseHeightTilt:
*   \section sec578 PulseHeightComb:
*   \section sec579 MinHeight:
*   \n  
*   \brief <B>PAGE 8 - Combine</B>
*   \section sec580 Page:
*   \section sec581 PulseBandUp:
*   \section sec582 PulseBandDw:
*   \section sec583 PulseBandTilt:
*   \section sec584 PulseBandComb:
*   \n
*   \brief <B>PAGE 9 - Combine</B>
*   \section sec585 Page:
*   \section sec586 bOscilationLimit:
*   \section sec587 bCurrentActionTimeLimit:
*   \section sec588 bOppositeActionTimeLimit:
*   \section sec589 bDivisorMax:
*   \section sec590 bDivisorMin:
*   \section sec591 bMaxTimeOn:
*   \section sec592 bMinTimeOn:
*   \n
*   \brief <B>PAGE 10 - Combine</B>
*   \section sec593 Page:
*   \section sec594 SensorLeft:
*   \section sec595 SensorRight:
*   \section sec596 SensorFeeder:
*   \section sec597 SensorFeeder:
*   \section sec598 SensorFan:
*   \n
*   \brief <B>PAGE 11 - Combine</B>
*   \section sec599 Page:
*   \section sec200 Strawalker_Sens:
*   \section sec201 Sieves_Sens:
*   \n
*   \brief <B>PAGE 0 - Sprayer </B>
*   \section sec202 Page:
*   \section sec203 CalibrationCommand:
*   \section sec204 CalibrationValue:
*   \section sec205 SectionsNumber:
*   \section sec206 ControlValve:
*   \section sec207 SectionValve:
*   \section sec208 ControlValve:
*   \section sec209 MasterBoomValve:
*   \section sec210 AbortCalibrations:
*   \section sec211 HBMode:
*   \section sec212 PWMDuty:
*   \n
*   \brief <B>PAGE 1 - Sprayer </B>
*   \section sec213 Page:
*   \section sec214 Device:
*   \section sec215 bDensityCorrectionFactor:
*   \section sec216 wMinimumInput:
*   \section sec217 wMaximumInput:
*   \section sec218 wCalibrationFactor:
*   \n
*   \brief <B>PAGE 2 - Sprayer </B>
*   \section sec219 Page:
*   \section sec220 Device:
*   \section sec221 wLowPressureLimit:
*   \section sec221 wHighPressureLimit:
*   \n
*   \brief <B>PAGE 3 - Sprayer </B>
*   \section sec222 Page:
*   \section sec223 Device:
*   \section sec224 wLowSpeedLimit:
*   \section sec225 wHighSpeedLimit:
*   \n
*   \brief <B>PAGE 11 - Sprayer </B>
*   \section sec226 Page:
*   \section sec227 Parameter:
*   \section sec228 ParameterValue::
*   \n
*/

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
#ifndef CC_VEHICLE_STEER_TYPES
#define CC_VEHICLE_STEER_TYPES
enum tagCC_VEHICLE_STEER_TYPES
{
    CC_FRONT_STEER_VEHICLE,       /*!< Front steering vehicle */
    CC_REAR_STEER_VEHICLE,        /*!< Rear steering vehicle */
    CC_ARTICULATED_STEER_VEHICLE, /*!< Articulated steering vehicle */
    CC_TRACKED_STEER_VEHICLE,      /*!< Tracked steering vehicle */
    CC_DIFFERENTIAL_STEER_VEHICLE /*!< Differential steering vehicle */
};
#endif

#ifndef CAN_UNITS_MODES
#define CAN_UNITS_MODES
enum tagCAN_UNITS_MODES
{
    PERCENT_UNIT,     /*!< Units on message are set to % */
    RPM_UNIT,         /*!< Units on message are set to RPM */
    MM_UNIT,          /*!< Units on message are set to mm */
    CM_UNIT           /*!< Units on message are set to cm */
};
#endif

#ifndef DEVICES_CODES
#define DEVICES_CODES
enum tagDEVICES_CODES
{
    NONE_DEVICE,      /*!< None device selected */
    HEADER_DEVICE,    /*!< Header device selected */
    FAN_DEVICE,       /*!< Fan device selected */
    REEL_DEVICE,      /*!< Reel device selected */
    CONCAVE_DEVICE,   /*!< Concave device selected */
    CYLINDER_DEVICE   /*!< Cylinder device selected */
};
#endif

#ifndef CONTROL_MODES_CODES
#define CONTROL_MODES_CODES
enum tagCONTROL_MODES_CODES
{
    CONTROL_MANUAL_MODE,                /*!< Manual mode */
    CONTROL_AUTO_MODE,                  /*!< Auto mode */
    CONTROL_STANDBY_MODE,               /*!< Standby mode */
    CONTROL_CALIBRATION_MODE            /*!< Calibration mode */
};
#endif

#ifndef SPRAYER_DEVICES_CODES
#define SPRAYER_DEVICES_CODES
enum tagSPRAYER_DEVICES_CODES
{
    SPRAYER_NONE_DEVICE,                /*!< No sprayer device selected */
    SPRAYER_SPRAY_FLOW_SENSOR_DEVICE,   /*!< Srayer flow sensor selected */
    SPRAYER_TANK_FLOW_SENSOR_DEVICE,    /*!< Sprayer filling tank flow selected */
    SPRAYER_FLOW_CONTROL_DEVICE,        /*!< Sprayer control device selected */
    SPRAYER_PRESSURE_SENSOR_DEVICE,     /*!< Sprayer pressure device selected */
    SPRAYER_CONTROLLER_DEVICE,          /*!< Sprayer controller selected */
    SPRAYER_ACTUATOR_DEVICE             /*!< Sprayer actuator selected */
};
#endif

#ifndef SPRAYER_PROJECT_TYPES
#define SPRAYER_PROJECT_TYPES
enum tagSPRAYER_PROJECT_TYPES
{
    SPRAYER_NONE_PROJECT,               /*!< Projects */
    SPRAYER_PLANTIUM_PROJECT,           /*!< Plantium Project */
    SPRAYER_AGCO_BX155_PROJECT,         /*!< BX155 Project */
};
#endif

#ifndef SPRAYER_VALVES_TYPES
#define SPRAYER_VALVES_TYPES
enum tagSPRAYER_VALVES_TYPES
{
    SPRAYER_NONE_VALVE,                 /*!< No valve avaiable */
    SPRAYER_DIRECT_VALVE,               /*!< Direct  HB valve selected */
    SPRAYER_INVERSE_VALVE,              /*!< Inverse HB valve avaiable */
    SPRAYER_DIRECT_HIGH_SIDE_VALVE,     /*!< Direct High Side valve selected */
    SPRAYER_INVERSE_HIGH_SIDE_VALVE     /*!< Inverse High Side valve selected */
};
#endif

#ifndef SPRAYER_CONTROLLER_PARAMETERS_SET
#define SPRAYER_CONTROLLER_PARAMETERS_SET
enum tagSPRAYER_CONTROLLER_PARAMETERS_SET
{
    SPRAYER_NONE_CONTROLLER_PARAMETER = 0,      /*!< None parameter selected */
    SPRAYER_KP_CONTROLLER_PARAMETER,            /*!< Select KP parameter from PID controller */
    SPRAYER_KI_CONTROLLER_PARAMETER,            /*!< Select KI parameter from PID controller */
    SPRAYER_KD_CONTROLLER_PARAMETER,            /*!< Select KD parameter from PID controller */
    SPRAYER_CONTROLLER_K_PARAMETER,             /*!< K */
    SPRAYER_CONTROLLER_RANGE_PARAMETER,         /*!< Flow Range */
    SPRAYER_CONTROLLER_PID_TRIGGER_PARAMETER,   /*!< Value to activate the PID */
    SPRAYER_CONTROLLER_MINPWM_PARAMETER         /*!< Minimum PWM to drive the valve */
};
#endif

#ifndef SPRAYER_CONTROLLER_PARAMETERS_GET
#define SPRAYER_CONTROLLER_PARAMETERS_GET
enum tagSPRAYER_CONTROLLER_PARAMETERS_GET
{
    SPRAYER_K_PARAMETER = 0,
    SPRAYER_RANGE_PARAMETER,
    SPRAYER_PID_TRIGGER_PARAMETER,
    SPRAYER_MINPWM_PARAMETER,
    last_SPRAYER_INTERNAL_CONTROLLER_PARAM
};
#endif

enum tagCONGIG_COMMANDS_ID
{
    CC_UPDATE_ENGINE_TOTAL_HOURS = 0,
    CC_UPDATE_WORKED_TOTAL_HOURS = 1,
    CC_last
};

/* Defines ********************************************************************/
#define PGN_CONFIGURE_COMMAND               0xFFC0U		
#define SIZE_CONFIGURE_COMMAND        	    8U	

#define CONTROLLER_INTERNAL_PARAM_QTY      (last_SPRAYER_INTERNAL_CONTROLLER_PARAM)

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagCONFIG_COMMAND_NONSPEC_P0
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint16_t WheelPerimeter;
    uint16_t LaborWidth;
    uint8_t  LaborWidthPercent;
    uint16_t PulsesPerWheel;
} CONFIGURE_COMMAND_NONSPEC_P0_T;

typedef struct tagCONFIG_COMMAND_NONSPEC_P1
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint16_t EngineSpeedCalib;
    uint8_t  CommandId; /* see enum tagCONGIG_COMMANDS_ID */
    uint32_t CommandParameter;
} CONFIGURE_COMMAND_NONSPEC_P1_T;

typedef struct tagCONFIG_COMMAND_NONSPEC_P2
{
    unsigned int Page                 :4;  
    unsigned int Rvd1                 :4;
    unsigned int PositionCorrection   :2;
    unsigned int EntryPoint           :2;
    unsigned int DiffSource           :4;
    uint16_t AntennaToPivot;          /* Offset: 32000 */
    uint16_t PivotToImplement;
    uint16_t DistanceBetweenAxes;
} CONFIGURE_COMMAND_NONSPEC_P2_T;

typedef struct tagCONFIG_COMMAND_NONSPEC_P3
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint16_t AntennaToAxes;           /* Offset: 32000 */
    uint16_t AntennaHeight;
    uint16_t AntennaOffsetFromCenter; /* Offset: 32000 */
    uint8_t  Rvd;
} CONFIGURE_COMMAND_NONSPEC_P3_T;

typedef struct tagCONFIG_COMMAND_NONSPEC_P4
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint8_t  VehicleSteerType;     
    uint8_t  VehicleTractionType;
    uint8_t  VehicleSteerActuatorType; 
    uint8_t  SteeringOperationMode;
    uint8_t  Rvd2;
    uint8_t  Rvd3;
    uint8_t  Rvd4;
} CONFIGURE_COMMAND_NONSPEC_P4_T;

typedef struct tagCONFIG_COMMAND_NONSPEC_P5
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint16_t ImplementOffsetFromCenter; /* Offset: 32000 */
    uint16_t PivotToImplementAxes; //not implemented yet
    uint16_t OverlapDistance;           /* Offset: 32000 */
    uint8_t  Rvd2;
} CONFIGURE_COMMAND_NONSPEC_P5_T;

typedef struct tagCONFIG_COMMAND_NONSPEC_P10
{
    unsigned int Page       :4;  
    unsigned int Rvd1       :4;
    unsigned int DebugState :2;
    unsigned int DiffSource :6;
    uint8_t  MessageCode;     
    uint16_t MessageTime;
    uint8_t  Rvd2;
    uint8_t  Rvd3;
    uint8_t  Rvd4;
} CONFIGURE_COMMAND_NONSPEC_P10_T;

typedef struct tagCONFIG_COMMAND_NONSPEC_P11
{
    unsigned int Page         :4;  
    unsigned int Rvd1         :4;
    unsigned int SetSetPoint  :2;
    unsigned int AutoMode     :2;
    unsigned int Rvd          :4;
    uint8_t  SetDeadBand;     
    uint8_t  Rvd2;
    uint8_t  Rvd3;
    uint8_t  Rvd4;
    uint8_t  Rvd5;
    uint8_t  Rvd6;
} CONFIGURE_COMMAND_NONSPEC_P11_T;   

typedef struct tagCONFIG_COMMAND_COMBINES_P0
{
    unsigned int Page               :4;
    unsigned int CalibrationCommand :4;  
    unsigned int OemHeightLevel     :3;
    unsigned int OemControlType     :3;
    unsigned int UseTiltSensors     :2;
    unsigned int ActualControlType  :3;
    unsigned int UserHeightLevel    :3;  
    unsigned int AbortCalibrations  :2;  
    unsigned int UserSensitivity    :3;  
    unsigned int Rvd2               :5;
    uint8_t OemSetPoint;
    uint8_t OemDeadBand; 
    uint8_t Rvd3;
    uint8_t Rvd4;
} CONFIGURE_COMMAND_COMBINES_P0_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P1
{
    unsigned int Page         :4;
    unsigned int Rvd1         :1;  
    unsigned int CylinderType :3;
    uint16_t CylinderSetPoint;
    uint16_t FanSetPoint;
    unsigned int FanType      :3;
    unsigned int Rvd2         :2;  
    unsigned int ConcaveType  :3;
    uint16_t ConcaveSetPoint;
}CONFIGURE_COMMAND_COMBINES_P1_T;

/*----- The follow ones are for debug ------*/
typedef struct tagCONFIG_COMMAND_COMBINES_P2
{
    unsigned int Page :4;
    unsigned int Rvd  :4;
    uint8_t PulseOnTimeUp;
    uint8_t PulseOffTimeUp;
    uint8_t PulseOnTimeDown;
    uint8_t PulseOffTimeDown;
    uint8_t PulseOnTimeTilt;
    uint8_t PulseOffTimeTilt;
    uint8_t PulseOnTimeCombine;
} CONFIGURE_COMMAND_COMBINES_P2_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P3
{
    unsigned int Page         :4;
    unsigned int AdaptativeRL :2; 
    unsigned int Rvd 	      :2;
    uint8_t  PulseOffTimeCombine;
    uint16_t ReelSp;
    uint16_t TolerancePID;
    uint8_t  ReelAccuracy;
    uint8_t  ReelSampling;
} CONFIGURE_COMMAND_COMBINES_P3_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P4
{
    unsigned int Page            :4;
    unsigned int Rvd             :4;
    int8_t Kp;
    int8_t Ki;
    int8_t Kd;
    uint8_t Type;
    unsigned int NewKpAdaptation :2;
    unsigned int NewKiAdaptation :2;
    unsigned int NewKdAdaptation :2;
    unsigned int Rvd2            :2;
    uint8_t Mode;
    uint8_t Rvd1;
} CONFIGURE_COMMAND_COMBINES_P4_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P5
{
    unsigned int Page             :4;
    unsigned int bfAdaptation     :2;
    unsigned int FiltrateHp       :2; 
    uint8_t WindowSize;
    uint8_t AdaptationTime;
    unsigned int AlgorithmType    :2;
    unsigned int Rvd1             :6;
    uint8_t bHb_Divisor;
    unsigned int CombinedUp       :2;
    unsigned int CombinedDown     :2;
    unsigned int DirectHysteresis :2;
    unsigned int Rvd2             :2;
    uint8_t Rvd3;
    uint8_t Rvd4;
} CONFIGURE_COMMAND_COMBINES_P5_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P6
{
    unsigned int Page                      :4;
    unsigned int DeadBandSpeedCompensation :2;
    unsigned int Rvd                       :2;
    uint8_t DbRelations;
    uint8_t Rvd1;
    uint8_t Rvd2;
    uint8_t Rvd3;
    uint8_t Rvd4;
    uint8_t Rvd5;
    uint8_t Rvd6;
} CONFIGURE_COMMAND_COMBINES_P6_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P7
{
    unsigned int Page :4;
    unsigned int Rvd  :4;
    uint8_t PulseHeightUp;
    uint8_t PulseHeightDw;
    uint8_t PulseHeightTilt;
    uint8_t PulseHeightComb;
    uint8_t MinHeight;  
    uint8_t Rvd1;
    uint8_t Rvd2;
} CONFIGURE_COMMAND_COMBINES_P7_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P8
{
    unsigned int Page :4;
    unsigned int Rvd  :4;
    uint8_t PulseBandUp;
    uint8_t PulseBandDw;
    uint8_t PulseBandTilt;
    uint8_t PulseBandComb;
    uint8_t Rvd1;
    uint8_t Rvd2;
    uint8_t Rvd3;
} CONFIGURE_COMMAND_COMBINES_P8_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P9
{
    unsigned int Page :4;
    unsigned int Rvd  :4;
    uint8_t bOscilationLimit;
    uint8_t bCurrentActionTimeLimit;
    uint8_t bOppositeActionTimeLimit;
    uint8_t bDivisorMax;
    uint8_t bDivisorMin;
    uint8_t bMaxTimeOn;
    uint8_t bMinTimeOn;
} CONFIGURE_COMMAND_COMBINES_P9_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P10
{
    unsigned int Page :4;
    unsigned int Rvd  :4;
    uint8_t SensorLeft;
    uint8_t SensorRight;
    uint8_t SensorTilt;
    uint8_t SensorFeeder;
    uint8_t SensorFan;
    uint8_t Rvd1;
    uint8_t Rvd2;
} CONFIGURE_COMMAND_COMBINES_P10_T;

typedef struct tagCONFIG_COMMAND_COMBINES_P11
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint16_t Strawalker_Sens;
    uint16_t Sieves_Sens;
    uint8_t  Rvd2;
    uint8_t  Rvd3;
    uint8_t  Rvd4;
} CONFIGURE_COMMAND_COMBINES_P11_T;

typedef struct tagCONFIG_COMMAND_SPRAYERS_P0
{
    unsigned int Page               :4;
    unsigned int CalibrationCommand :4;
    uint16_t CalibrationValue;
    uint8_t  SectionsNumber;
    unsigned int ControlValve       :4;
    unsigned int SectionValve       :4;
    unsigned int MasterBoomValve    :4;
    unsigned int Rvd1               :4;
    unsigned int AbortCalibrations  :2;
    unsigned int HBMode             :6;
    uint8_t  PWMDuty;
}CONFIGURE_COMMAND_SPRAYERS_P0_T;

typedef struct tagCONFIG_COMMAND_SPRAYERS_P1
{
    unsigned int Page         :4;
    unsigned int Device       :4;
    uint8_t  bDensityCorrectionFactor;
    uint16_t wMinimumInput;
    uint16_t wMaximumInput;
    uint16_t wCalibrationFactor; //offset = 0, factor = 0.1, unit = pl/units
}CONFIGURE_COMMAND_SPRAYERS_P1_T;

typedef struct tagCONFIG_COMMAND_SPRAYERS_P2
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint16_t wLowPressureLimit;
    uint16_t wHighPressureLimit;
    uint8_t  Rvd2;
    uint16_t Rvd3;
}CONFIGURE_COMMAND_SPRAYERS_P2_T;

typedef struct tagCONFIG_COMMAND_SPRAYERS_P3
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint16_t wLowSpeedLimit;
    uint16_t wHighSpeedLimit;
    uint8_t  Rvd2;
    uint16_t Rvd3;
}CONFIGURE_COMMAND_SPRAYERS_P3_T;

typedef struct tagCONFIG_COMMAND_SPRAYERS_P10
{
    unsigned int Page :4;
    unsigned int Rvd1 :4;
    uint8_t  Parameter;
    int32_t  ParameterValue;
    uint8_t  ControllerInstance;
    uint8_t  Rvd3;
} CONFIGURE_COMMAND_SPRAYERS_P10_T;

#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

typedef union tagCONFIG_COMMAND_COMBINE
{
    CONFIGURE_COMMAND_COMBINES_P0_T P0;
    CONFIGURE_COMMAND_COMBINES_P1_T P1;
    CONFIGURE_COMMAND_COMBINES_P2_T P2;
    CONFIGURE_COMMAND_COMBINES_P3_T P3;
    CONFIGURE_COMMAND_COMBINES_P4_T P4;
    CONFIGURE_COMMAND_COMBINES_P5_T P5;
    CONFIGURE_COMMAND_COMBINES_P6_T P6;
    CONFIGURE_COMMAND_COMBINES_P7_T P7;
    CONFIGURE_COMMAND_COMBINES_P8_T P8;
    CONFIGURE_COMMAND_COMBINES_P9_T P9;
    CONFIGURE_COMMAND_COMBINES_P10_T P10;
    CONFIGURE_COMMAND_COMBINES_P11_T P11;
} CONFIGURE_COMMAND_COMBINE_U; 

typedef union tagCONFIG_COMMAND_SPRAYER
{
    CONFIGURE_COMMAND_SPRAYERS_P0_T   P0;
    CONFIGURE_COMMAND_SPRAYERS_P1_T   P1;
    CONFIGURE_COMMAND_SPRAYERS_P2_T   P2;
    CONFIGURE_COMMAND_SPRAYERS_P3_T   P3;
    CONFIGURE_COMMAND_SPRAYERS_P10_T  P10;
} CONFIGURE_COMMAND_SPRAYERS_U; 

typedef union tagCONFIG_COMMAND_NONSPEC
{
    CONFIGURE_COMMAND_NONSPEC_P0_T P0;
    CONFIGURE_COMMAND_NONSPEC_P1_T P1;
    CONFIGURE_COMMAND_NONSPEC_P2_T P2;
    CONFIGURE_COMMAND_NONSPEC_P3_T P3;
    CONFIGURE_COMMAND_NONSPEC_P4_T P4;
    CONFIGURE_COMMAND_NONSPEC_P5_T P5;
    CONFIGURE_COMMAND_NONSPEC_P10_T P10;
    CONFIGURE_COMMAND_NONSPEC_P11_T P11;   
} CONFIGURE_COMMAND_NONSPEC_U; 

typedef union tagCONFIGURE_COMMAND
{	
    CONFIGURE_COMMAND_NONSPEC_U   Nonspec;
    CONFIGURE_COMMAND_COMBINE_U   Combine;
    CONFIGURE_COMMAND_SPRAYERS_U  Sprayer;
} CONFIGURE_COMMAND_T;

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

/* End of $Workfile: CC_canmsg.h$ */
