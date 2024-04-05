
#ifndef AGC_CANMSG_H
#define AGC_CANMSG_H

/*!\page AGC AutoGuide Command
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"
#include "AGC_SPEED_canmsg.h"
#include "AGC_STEERING_canmsg.h"
#include "AGC_SYSTEM_canmsg.h"
#include "AGC_CONFIGURATION_canmsg.h"
#include "AGC_GUIDANCE_canmsg.h"

/* Enums **********************************************************************/
#ifndef AGC_PATTERN_TYPES
#define AGC_PATTERN_TYPES
enum tagAGC_PATTERN_TYPES            /*!< Different patterns for pilot */
{
    AGC_PTRN_TYPE_AB_LINE               = (uint8_t)(0x00),      /*!< Straight line with position average */
    AGC_PTRN_TYPE_2POINT_LINE           = (uint8_t)(0x20),      /*!< Straight line defined by 2 points */
    AGC_PTRN_TYPE_APLUS_LINE            = (uint8_t)(0x30),      /*!< Straight line defined by 1 point and heading */
    AGC_PTRN_TYPE_USER_DEFINED_CURVE    = (uint8_t)(0x01),      /*!< Arbitrary pattern */
    AGC_PTRN_TYPE_CIRCLE                = (uint8_t)(0x02),      /*!< Pivot */
    AGC_PTRN_TYPE_CONTOUR               = (uint8_t)(0x12)       /*!< Closed curve used for contour */
};
#endif

#ifndef AGC_PATTERN_CLASSES
#define AGC_PATTERN_CLASSES
enum tagAGC_PATTERN_CLASSES            /*!< Different patterns for pilot */
{
    AGC_PTRN_CLASS_LINE                 = (uint8_t)(0x00),      /*!< Straight line */
    AGC_PTRN_CLASS_CURVE                = (uint8_t)(0x01),      /*!< Open curve */
    AGC_PTRN_CLASS_CLOSED_CURVE         = (uint8_t)(0x02),      /*!< Closed curve */
    AGC_PTRN_CLASS_NO_PATTERN           = (uint8_t)(0x0F)       /*!< Invalid pattern */
};
#endif

typedef enum tag_AGC_REFERENCE_SOURCE_E         /*!< List of Steering Reference Sources */
{
    AGC_REFERENCE_SOURCE_NONE                          = 0,
    AGC_REFERENCE_SOURCE_PILOT                         = 1,
    AGC_REFERENCE_SOURCE_WCT                           = 2,
    AGC_REFERENCE_SOURCE_JOYSTICK                      = 3,
    AGC_REFERENCE_SOURCE_SCREEN                        = 4,
    AGC_REFERENCE_SOURCE_CROP_ROW                      = 5,
    AGC_REFERENCE_SOURCE_PERCEPTION                    = 6,
    AGC_REFERENCE_SOURCE_CALIBRATION                   = 200
} AGC_REFERENCE_SOURCE_E;

typedef enum tag_AGC_REFERENCE_TYPE_E   /*!< List of Steering Reference Types */
{
	AGC_REFERENCE_TYPE_INVALID          = (uint8_t)(0),
	AGC_REFERENCE_TYPE_CURVATURE        = (uint8_t)(1),
	AGC_REFERENCE_TYPE_WHEEL_ANGLE      = (uint8_t)(2),
	AGC_REFERENCE_TYPE_YAW_RATE         = (uint8_t)(3),
    AGC_REFERENCE_TYPE_SPEED            = (uint8_t)(4),
    AGC_REFERENCE_TYPE_ACCELERATION     = (uint8_t)(5),
	AGC_REFERENCE_TYPE_TORQUE           = (uint8_t)(6)
} AGC_REFERENCE_TYPE_E;

typedef enum tag_AGC_COMMAND_E                          /*!< List of commands for CANSteer */
{
    AGC_COMMAND_POINTA = 0,                             /*!< Set first point for pattern calibration; Needs ShortParam from AGC_STEERING_PATTERN */
    AGC_COMMAND_POINTB = 1,                             /*!< Set end point for pattern calibration; Needs ShortParam from AGC_STEERING_PATTERN */
    AGC_COMMAND_DRIFTAJUST = 2,                         /*!< Set actual error to zero */
    AGC_COMMAND_DMC_START_CALIB = 3,                    /*!< Start DMC calibration */
    AGC_COMMAND_ROLL_POINT1_CALIB = 4,                  /*!< Start ROLL compensation point 1 */
    AGC_COMMAND_ROLL_POINT2_CALIB = 5,                  /*!< Start ROLL compensation point 2 */
    AGC_COMMAND_CANCEL_CALIBRATIONS = 6,                /*!< Abort current calibration */
    AGC_COMMAND_FREE_PLAY_START_CALIB = 7,              /*!< Start free play calibration */
    AGC_COMMAND_FREE_PLAY_INCREASE_ANGLE = 8,           /*!< Indicate to free play calibration to increase the angle */
    AGC_COMMAND_FREE_PLAY_DECREASE_ANGLE = 9,           /*!< Indicate to free play calibration to decrease the angle */
    AGC_COMMAND_FREE_PLAY_END_CALIBRATION = 10,         /*!< End the free play calibration */
    AGC_COMMAND_FACTORY_IMU_START_CALIBRATION = 11,     /*!< Start IMU factory calibration process */
    AGC_COMMAND_FACTORY_IMU_END_CALIBRATION = 12,       /*!< Ends  IMU factory calibration process */
    AGC_COMMAND_IMU_SELF_TEST = 13,                     /*!< Change the self test outputs of the IMUS; Needs ShortParam from AGC_IMU_SELF_TEST_MODE */
    AGC_COMMAND_LOCK_MOTOR_CONTROL = 14,                /*!< Set Control of the motor from the outside; Needs ShortParam from AUTOGUIDE_MOTOR_LOCKS */ 
    AGC_COMMAND_START_HYDRAULIC_ACTUATOR_CALIB = 15,    /*!< Starts the calibration process for the Hydraulic actuator..equivalent to DMC */
    AGC_COMMAND_START_WHEEL_ANGLE_SENSOR_CALIB = 16,    /*!< Starts the calibration process for the wheel sensor  */
    AGC_COMMAND_DEMO_MODE_STEER = 17,                   /*!< DemoMode >*/
    AGC_COMMAND_NORMAL_MODE_STEER = 18,                 /*!< DemoMode >*/
    AGC_COMMAND_ENGAGE_EVENT_STEER = 19,                /*!< Engage main Steer replacing red button */
    AGC_COMMAND_DISENGAGE_EVENT_STEER = 20,             /*!< Disengage main Steer */
    AGC_COMMAND_START_DIRECT_DRIVE_CALIB = 21,          /*!< Starts the calibration process for the Direct Drive (embedded motor) */
    AGC_COMMAND_CANCEL_POINTAB = 22,                    /*!< Aborts Point A-B calibration */
    AGC_COMMAND_MANUAL_HYD_ACT_CALIB_START = 23,        /*!< Sets CANSteer to Manual Hydraulic Calibration Mode */
    AGC_COMMAND_MANUAL_HYD_ACT_CALIB_DUTY = 24,         /*!< Sets Manual Hydraulic Calibration PWM Output. LongParam is PWM value ( Factor 0.001; Offset 100) */
    AGC_COMMAND_MANUAL_HYD_ACT_CALIB_END = 25,          /*!< Returns CANSteer to normal mode */
    AGC_COMMAND_DRIFT_MODIFY = 26,                      /*!< Moves guidance pattern a perpendicular distance set in LongParam (Units m; Factor 0.005; Offset 100) */
    AGC_COMMAND_CALIB_TURNRADIUS_START_RIGHT = 27,      /*!< Start Minimum Radius Calibration Right */
    AGC_COMMAND_CALIB_TURNRADIUS_START_LEFT = 28,       /*!< Start Minimum Radius Calibration Left */
    AGC_COMMAND_HEADLANDTURN_ENABLE = 29,               /*!< Start Headland turn now!. Short param is the relative number of swath to return (> 0 is right; Factor 1; Offset 120) */
    AGC_COMMAND_HEADLANDTURN_CANCEL = 30,               /*!< Cancel future headland turn */
    AGC_COMMAND_START_WHEEL_ESTIMATOR_CALIB = 31,       /*!< Starts the calibration process for the wheel estimator  */
    AGC_COMMAND_AB_PATTERN_PAUSE = 32,                  /*!< Pause point buffering for AB pattern generation  */
    AGC_COMMAND_AB_PATTERN_START = 33,                  /*!< Start point buffering for AB pattern generation  */
    AGC_COMMAND_OVERRIDE_CALIB = 34,                    /*!< Override Calibration commands  */
    AGC_COMMAND_STEERING = 35,                          /*!< Steering commands; Needs ShortParam from AGC_COMMAND_STEERING_E  */
    AGC_COMMAND_SPEED = 36,                             /*!< Speed commands; Needs ShortParam from AGC_SPEED_COMMAND_E  */
    AGC_COMMAND_MOUNTING_CALIB_CMD = 37,                /*!< Mounting Calibration Commands; Needs ShortParam from AGC_MOUNTING_CALIB_COMMAND_E */
    AGC_COMMAND_SYSTEM = 38,                            /*!< System Commands; Needs ShortParam from AGC_SYSTEM_COMMAND_E */
    AGC_COMMAND_START_OPEN_LOOP_GAIN_ESTI_CALIB = 39,   /*!< Starts the calibration process for the actuator open loop gain estimator */
    AGC_COMMAND_RESUME_OPEN_LOOP_GAIN_ESTI_CALIB = 41,  /*!< Resume the calibration from pause state for actuator the open loop gain estimator */
    AGC_COMMAND_STEERING_TEST = 40,                     /*!< Steering Test messages */
    AGC_COMMAND_WHEEL_CONTROL_TEST = 42,                /*!< Wheel Controln test */
    AGC_COMMAND_START_WHEEL_LIMIT_CALIB = 43,           /*!< Wheel Limit calib start */
    AGC_COMMAND_START_FREEPLAY_CALIB = 44,              /*!< FreePlay calib start */
    AGC_COMMAND_CLEAR_ERROR_HISTORY_DD = 45,              /*!< FreePlay calib start */
    AGC_COMMAND_SET_HIGH_SIDE = 238,                       /*!< For debug purposes. ShortParam: 0=OFF, 1=ON */
    AGC_COMMAND_CRD_MODE_DISABLED = 90,                 /*!< Change CRD mode to disabled */
    AGC_COMMAND_CRD_MODE_AUTO = 91,                     /*!< Change CRD mode to auto */
    AGC_COMMAND_CRD_MODE_FORCED = 92,                   /*!< Change CRD mode to forced */
    AGC_COMMAND_SET_5VSENS = 239,                       /*!< For debug purposes. ShortParam: 0=OFF, 1=ON */
    AGC_COMMAND_USERCOMMAND = 240                       /*!< Disabled in final version. Needs ShortParam from AGC_USER_COMMAND_E and LongParam is value (when needed,  Factor 0.001; Offset 100) */
} AGC_COMMAND_E;

typedef enum tag_AGC_MESSAGES_E                                     /*!< List of messages returned from CANSteer */
{
    AGC_MESSAGE_DMC_STARTED_CALIB = 0,                               /*!< Calibration process has been started */
    AGC_MESSAGE_DMC_SUCCESSFUL_CALIB = 1,                            /*!< Calibration process has finished ok */
    AGC_MESSAGE_DMC_INTERRUPTED_BY_USER_CALIB = 2,                   /*!< Calibration process has been interrupted by user */
    AGC_MESSAGE_DMC_CANT_START_CALIB_MACHINE_MOVING = 3,             /*!< Can't start calibration process because machine is moving */
    AGC_MESSAGE_DMC_CANT_START_CALIB_BATTERY_VOLTAGE = 4,            /*!< Can't start calibration process because battery voltage is out of range */
    AGC_MESSAGE_DMC_ERROR_CALIB_NO_MOTOR_FEEDBACK = 5,               /*!< No motor feedback was detected, cable and encoder must be check */
    AGC_MESSAGE_DMC_ERROR_CALIB_MOTOR_RPM_TOO_HIGH = 6,              /*!< The RPMs read are too high, probably the steering wheel is not engaged */
    AGC_MESSAGE_DMC_ERROR_CALIB_MOTOR_RPM_TOO_LOW = 7,               /*!< The RPMs read are too low, probably steering is too hard for control */
    AGC_MESSAGE_DMC_ERROR_CALIB_MOTOR_CURRENT_TOO_HIGH = 8,          /*!< The current read is too high, check for jammed steering */
    AGC_MESSAGE_DMC_ERROR_CALIB_BAD_IDENTIFICATION = 9,              /*!< The id process didn't achieve a good performance, repeat the calibration */
    AGC_MESSAGE_DMC_ERROR_CALIB_UNKNOWN = 10,                        /*!< Other errors */
    AGC_MESSAGE_POINTA_OK = 20,                                      /*!< PointA accepted */
    AGC_MESSAGE_POINTB_OK = 21,                                      /*!< PointB accepted */
    AGC_MESSAGE_POINTB_ERROR_DISTANCE_TOO_SHORT = 22,                /*!< Cant set point B because is too close of point A */
    AGC_MESSAGE_DRIFT_ADJUSTED = 23,                                 /*!< Drift was adjusted; Long Param should be interpreted as an array of 2 uint16_t: [Drift_East,Drift_North](Units m; Factor 0.005; Offset 160) */
    AGC_MESSAGE_DRIFT_ERROR_NO_POINTS_DEFINED = 24,                  /*!< Can't set drift because there is no rect points data */
    AGC_MESSAGE_FREE_PLAY_STARTED_CALIB = 25,                        /*!< Started free play calibration */
    AGC_MESSAGE_FREE_PLAY_SUCESSFUL_CALIB = 26,                      /*!< Successful End of free play calibration */
    AGC_MESSAGE_FREE_PLAY_ERROR_ANGLE_REACH_HIGHER_LIMIT = 27,       /*!< The free play angle can't be increased */
    AGC_MESSAGE_FREE_PLAY_ERROR_ANGLE_REACH_LOWER_LIMIT = 28,        /*!< The free play angle can't be decreased  */
    AGC_MESSAGE_FREE_PLAY_INTERRUPTED_BY_USER_CALIB = 29,            /*!< The free play calibration was interrupted by user */
    AGC_MESSAGE_DMC_ERROR_CALIB_ENCODER = 30,                        /*!< There was an error with the encoder during the motor calibration */
    AGC_MESSAGE_DMC_ERROR_CALIB_MOTOR_ORIENTATION = 31,              /*!< The orientation detection of the motor during the calibration is not ok */
    AGC_MESSAGE_DMC_ERROR_CALIB_NO_MOTOR_CURRENT = 32,               /*!< No motor current was measured */
    AGC_MESSAGE_PWM_WARNING_SYSTEM_SLOW = 39,                        /*!< Hydraulic calibration error: the system seems to be too slow */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_STARTED = 47,                     /*!< Direct Drive calibration has been started */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_SUCCESSFUL = 48,                  /*!< Direct Drive calibration has finish ok */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_INTERRUPTED_BY_USER = 49,         /*!< Direct Drive calibration interrupted by user */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_CANT_START_MACHINE_MOVING = 50,   /*!< Direct Drive calibration can't start because machine is moving */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_TIMEOUT = 51,                     /*!< Direct Drive calibration timed out */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_CANNOT_START_MOTOR = 52,          /*!< Direct Drive calibration can't start (hall sensors are not aligned, turn motor half revolution) */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_ERROR = 53,                       /*!< Direct Drive calibration error */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_FAIL = 54,                        /*!< Direct Drive calibration can't reach suitable value */
    AGC_MESSAGE_DIRECT_DRIVE_CALIB_NO_MOTOR_DETECTED = 55,           /*!< Direct Drive calibration can't start (no motor feedback received) */
    AGC_MESSAGE_POINTAB_CANCELLED = 56,                              /*!< Point AB calibration has been cancelled */
    AGC_MESSAGE_MANUAL_HYD_ACT_CALIB_SUCCESSFUL = 57,                /*!< Manual Hydraulic Actuator Caibration Ended OK */
    AGC_MESSAGE_MANUAL_HYD_ACT_CALIB_STARTED = 58,                   /*!< CANSteer started Manual Hydraulic Actuator Caibration */
    AGC_MESSAGE_MANUAL_HYD_ACT_CALIB_CANNOT_START = 59,              /*!< Can't start Manual Hydraulic Actuator Caibration, Machine moving or CANSteer not in normal mode */
    AGC_MESSAGE_MANUAL_HYD_ACT_CALIB_INTERRUPTED_BY_USER = 60,       /*!< CANSteer returned to normal mode after cancel calibration command */
    AGC_MESSAGE_MANUAL_HYD_ACT_CALIB_FAIL = 61,                      /*!< CANSteer returned to normal mode after user override detection */
    AGC_MESSAGE_MANUAL_HYD_ACT_CALIB_TIMEOUT = 62,                   /*!< CANSteer returned to normal mode after calibration timed out */
    AGC_MESSAGE_POINTAB_ERROR_NO_GPS = 63,                           /*!< No GPS during AB pattern definition */
    AGC_MESSAGE_POINT_A_ERROR_IMUS = 64,                             /*!< IMU and compensation error. Cant define new AB */
    AGC_MESSAGE_PATTERNAB_RECEIVED_OK = 65,                          /*!< AB pattern received ok through CAN */
    AGC_MESSAGE_DRIFT_ERROR_NO_GPS = 66,                             /*!< Error when trying DriftAdjust, no GPS */
    AGC_MESSAGE_DRIFT_ERROR = 77,                                    /*!< Drift adjust cannot be executed */
    AGC_MESSAGE_STEERING = 78,                                       /*!< Guidance Steering messages */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB = 79,                          /*!< Wheel Angle Estimator calibration messages */
    AGC_MESSAGE_WHEEL_ESTIMATOR = 80,                                /*!< Wheel Angle Estimator messages; Needs ShortParam from AGC_MESSAGE_WHEEL_ESTIMATOR_E */
    AGC_MESSAGE_AB_PATTERN_READY = 81,                               /*!< AB pattern generated ok, ready to be sent */
    AGC_MESSAGE_AB_PATTERN_PAUSED = 82,                              /*!< Paused point buffering for AB pattern generation */
    AGC_MESSAGE_AB_PATTERN_STARTED = 83,                             /*!< Started point buffering for AB pattern generation */
    AGC_MESSAGE_AB_PATTERN_CLOSED = 84,                              /*!< AB pattern closed by user request */
    AGC_MESSAGE_AB_PATTERN_AUTOCLOSED = 85,                          /*!< AB pattern closed automatically */
    AGC_MESSAGE_AB_ERROR_TOO_MANY_BEZIERS = 86,                      /*!< Insufficient memory to store AB pattern */
    AGC_MESSAGE_CALIB_ERROR_LICENSE_INVALID = 91,                    /*!< Calibration can't start because autopilot license is invalid */
    AGC_MESSAGE_AB_ERROR_AREA_TOO_SMALL = 92,                        /*!< Closed Curve Pattern too small */
    AGC_MESSAGE_OVERRIDE_CALIB = 93,                                 /*!< User Override calibration messages */
    AGC_MESSAGE_SPEED = 94,                                          /*!< Guidance Steering messages */
    AGC_MESSAGE_MOUNTING_CALIB = 95,                                 /*!< Mounting Calibration Messages; Needs ShortParam from AGC_MOUNTING_CALIB_MESSAGE_E */
    AGC_MESSAGE_SYSTEM = 96,                                         /*!< System Messages; Needs ShortParam from AGC_SYSTEM_MESSAGE_E */
    AGC_MESSAGE_OPENLOOP_CALIB = 97,                                 /*!< OpenLoop calibration messages */
	AGC_MESSAGE_GUIDANCE = 105,                                      /*!< System Messages; Needs ShortParam from AGC_GUIDANCE_MESSAGE_E */
    AGC_MESSAGE_GPS_INFO = 106,
	AGC_MESSAGE_STACK_INFO = 107,
    AGC_MESSAGE_GPS_ERROR = 108,                                     /*!< Distance to the previous GPSpoint, greater than 1 degree */
    AGC_MESSAGE_WHEEL_LOCK_CALIB = 109,                              /*!< Wheel Lock calibration messages */
    AGC_MESSAGE_FREEPLAY_CALIB = 112,                                /*!< Free play calibration messages */
    AGC_MESSAGE_GPS_COMPENSATION_ERROR = 114,                        /*!< Distance from Position Compensated to the GPSpoint, greater than 5.55 m */
    AGC_MESSAGE_GPS_ID_ERROR = 115,                                  /*!< GPS_POSITION_DELTA.ID does not match GPS_DATA.ID */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB = 116,                      /*!< Wheel Angle Sensor calibration messages */
    AGC_MESSAGE_HYDRAULIC_CALIB = 117,                               /*!< Hydraulic calibration messages */
    AGC_MESSAGE_TURNRADIUS_CALIB = 118,                              /*!< Turn radius calibration messages */
    AGC_MESSAGE_USERMESSAGE = 240
} AGC_MESSAGES_E;

typedef enum tag_AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_E                     /*!< List of Wheel Angle Estimator calibration messages */
{
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_NO_DESCRIPTION = 0,                                   /*!< No message */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_STARTED = 1,                                          /*!< Wheel estimator calibration has started */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_SUCCESSFUL = 2,                                       /*!< Wheel estimator calibration has finished OK */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_INTERRUPTED_BY_USER = 3,                              /*!< Wheel estimator calibration has been interrupted by user */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_FAIL_K_DIDNT_CONVERGE = 4,                            /*!< Wheel estimator calibration error: WAE_K did not converge */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_FAIL_UNKNOWN = 5,                                     /*!< Wheel estimator calibration failed due to an unknown error */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_TIMEOUT_WARNING = 6,                                  /*!< Wheel estimator calibration timed out */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_INTERRUPTED_LOW_SPEED = 7,                            /*!< Wheel estimator calibration has been interrupted due to low vehicle speed */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_ERROR_LOW_SPEED = 8,                                  /*!< Wheel estimator calibration cannot start due to low vehicle speed */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_ERROR_SPEED_SENSE_UNDETERMINED = 9,                   /*!< Wheel estimator calibration cannot start due indetermination in the vehicle's speed sense */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_ERROR_SPEED_SENSE_BACKWARDS = 10,                      /*!< Wheel estimator calibration cannot start because the vehicle is driving backwards */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_ERROR_HIGH_SPEED = 11,                                 /*!< Wheel estimator calibration cannot start due to high vehicle speed */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_ERROR_ACTUATOR_NOT_DETECTED = 12,                     /*!< Wheel estimator calibration cannot start due to actuator not detected */
    AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_ERROR_NO_GPS = 13                            /*!< Wheel estimator calibration cannot start due to no gps */
} AGC_MESSAGE_WHEEL_ESTIMATOR_CALIB_E;

typedef enum tag_AGC_MESSAGE_WHEEL_LOCK_CALIB_E                         /*!< List of Wheel Lock calibration messages */
{
    AGC_MESSAGE_WHEEL_LOCK_CALIB_NO_DESCRIPTION = 0,                                   /*!< No message */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_STARTED = 1,                                          /*!< Wheel lock calibration has started */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_SUCCESSFUL = 2,                                       /*!< Wheel lock calibration has finished OK */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_INTERRUPTED_BY_USER = 3,                              /*!< Wheel lock calibration has been interrupted by user */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_MAX_ACTUATOR_SPEED = 4,                         /*!< Wheel lock calibration error: Max RPM could not be measured */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_TIMEOUT_WARNING = 5,                                  /*!< Wheel lock calibration timed out */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_LOW_SPEED = 6,                                  /*!< Wheel lock calibration cannot start due to low vehicle speed */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_SPEED_SENSE_UNDETERMINED = 7,                   /*!< Wheel lock calibration cannot start due indetermination in the vehicle's speed sense */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_SPEED_SENSE_BACKWARDS = 8,                      /*!< Wheel lock calibration cannot start because the vehicle is driving backwards */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_HIGH_SPEED = 9,                                 /*!< Wheel lock calibration cannot start due to high vehicle speed */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_ACTUATOR_NOT_DETECTED = 10,                     /*!< Wheel lock calibration cannot start due to high vehicle speed */
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_NO_GPS = 11,
    AGC_MESSAGE_WHEEL_LOCK_CALIB_ERROR_ROADING_SWITCH_TRAVE_MODE = 12
} AGC_MESSAGE_WHEEL_LOCK_CALIB_E;

typedef enum tag_AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_E                         /*!< List of Wheel Lock calibration messages */
{
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_NO_DESCRIPTION = 0,                                   /*!< No message */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_STARTED = 1,                                          /*!< Wheel angle sensor calibration has started */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_SUCCESSFUL = 2,                                       /*!< Wheel angle sensor calibration has finished OK */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_POINT_SUCCESSFUL = 3,                                 /*!< Wheel angle sensor calibration point OK */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_INTERRUPTED_BY_USER = 4,                              /*!< Wheel angle sensor calibration has been interrupted by user */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_FAIL_VOLTAGE_RANGE = 5,                               /*!< Wheel angle sensor calibration range < 1.5v */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_TIMEOUT_WARNING = 6,                                  /*!< Wheel angle sensor calibration timed out */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_ERROR_SPEED_SENSE_UNDETERMINED = 7,                   /*!< Wheel angle sensor calibration cannot start due indetermination in the vehicle's speed sense */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_ERROR_SPEED_SENSE_BACKWARDS = 8,                      /*!< Wheel angle sensor calibration cannot start because the vehicle is driving backwards */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_ERROR_LOW_SPEED = 9,                                  /*!< Wheel angle sensor calibration cannot start due to low vehicle speed */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_ERROR_HIGH_SPEED = 10,                                /*!< Wheel angle sensor calibration cannot start due to high vehicle speed */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_INTERRUPTED_LOW_SPEED  = 11,                          /*!< Wheel angle sensor calibration aborted due to low vehicle speed */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_INTERRUPTED_HIGH_SPEED  = 12,                         /*!< Wheel angle sensor calibration aborted due to high vehicle speed */
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_ERROR_BAD_CONFIG = 13,                                /*!< Wheel sensor calibration cannot start due to bad configuration */                     
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_ERROR_ACTUATOR_NOT_DETECTED = 14,
    AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_ERROR_ROADING_SWITCH_TRAVEL_MODE = 15
} AGC_MESSAGE_WHEEL_ANGLE_SENSOR_CALIB_E;

typedef enum tag_AGC_COMMAND_OVERRIDE_CALIB_E                     /*!< List of User Override calibration commands */
{
    AGC_COMMAND_OVERRIDE_CALIB_NO_CMD = 0,                                        /*!< No message */
    AGC_COMMAND_OVERRIDE_CALIB_START_CALIBRATION = 1,                             /*!< Start Override calibration */
    AGC_COMMAND_OVERRIDE_CALIB_CANCEL_CALIBRATION = 2,                            /*!< Cancel Override calibration */
    AGC_COMMAND_OVERRIDE_CALIB_WAIT_FOR_MOVEMENT = 3,                             /*!< Wait for steering wheel movement */
    AGC_COMMAND_OVERRIDE_CALIB_WAIT_FOR_REST = 4                                  /*!< Wait for steering wheel rest */
} AGC_COMMAND_OVERRIDE_CALIB_E;

typedef enum tag_AGC_MESSAGE_OVERRIDE_CALIB_E                     /*!< List of User Override calibration messages */
{
    AGC_MESSAGE_OVERRIDE_CALIB_NO_MSG = 0,                                 /*!< No message */
    AGC_MESSAGE_OVERRIDE_CALIB_STARTED = 1,                                /*!< Override calibration has started */
    AGC_MESSAGE_OVERRIDE_CALIB_CANCELLED = 2,                              /*!< Override calibration has been cancelled */
    AGC_MESSAGE_OVERRIDE_CALIB_REST_VALUE_OK = 3,                          /*!< Override calibration Rest Value calculation succeeded */
    AGC_MESSAGE_OVERRIDE_CALIB_WAITING_FOR_MOVEMENT = 4,                   /*!< Override calibration is waiting for steering wheel movement */
    AGC_MESSAGE_OVERRIDE_CALIB_MOVEMENT_DETECTED = 5,                      /*!< Override calibration has detected steering wheel movement */
    AGC_MESSAGE_OVERRIDE_CALIB_DELTA_VALUE_OK = 6,                         /*!< Override calibration Delta Value calculation succeeded */
    AGC_MESSAGE_OVERRIDE_CALIB_WAITING_FOR_REST = 7,                       /*!< Override calibration is waiting for steering wheel to stop movement */
    AGC_MESSAGE_OVERRIDE_CALIB_REST_DETECTED = 8,                          /*!< Override calibration has detected steering wheel lack of movement */
    AGC_MESSAGE_OVERRIDE_CALIB_FINISHED = 9,                               /*!< Override calibration has finished OK */
    AGC_MESSAGE_OVERRIDE_CALIB_ERROR_REST_VALUE_UNSTABLE = 10,             /*!< Override calibration error: Input varies too much during rest */
    AGC_MESSAGE_OVERRIDE_CALIB_ERROR_NO_MOVEMENT = 11,                     /*!< Override calibration error: Timed out waiting for movement */
    AGC_MESSAGE_OVERRIDE_CALIB_ERROR_DELTA_VALUE_BELOW_THRESHOLD = 12,     /*!< Override calibration error: Delta value below noise threshold */
    AGC_MESSAGE_OVERRIDE_CALIB_ERROR_REST_VALUE_INCONSISTENT = 13,         /*!< Override calibration error: New rest value different to the previously calculated */
    AGC_MESSAGE_OVERRIDE_CALIB_ERROR_UNKNOWN = 14,                         /*!< Override calibration error: Unknown cause */
    AGC_MESSAGE_OVERRIDE_CALIB_ERROR_WRONG_ACTUATOR = 15,                  /*!< Override calibration error: Current actuator is not supported  */
    AGC_MESSAGE_OVERRIDE_CALIB_ERROR_WRONG_SENSOR_TYPE = 16                /*!< Override calibration error: Selected sensor type is not supported  */
} AGC_MESSAGE_OVERRIDE_CALIB_E;

typedef enum tag_AGC_MESSAGE_WHEEL_ESTIMATOR_E                          /*!< List of Wheel Angle Estimator messages */
{
    AGC_MESSAGE_WHEEL_ESTIMATOR_NO_DESCRIPTION = 0,                                   /*!< No message */
    AGC_MESSAGE_WHEEL_ESTIMATOR_INIT_STARTED = 1,                                     /*!< Wheel estimator initialisation has started */
    AGC_MESSAGE_WHEEL_ESTIMATOR_INIT_SUCCESSFUL = 2,                                  /*!< Wheel estimator initialisation has finished OK */
    AGC_MESSAGE_WHEEL_ESTIMATOR_INIT_FAILED = 3,                                      /*!< Wheel estimator initialisation has failed. Recalibration needed */
    AGC_MESSAGE_WHEEL_ESTIMATOR_ACTIVE_FAILED = 4,                                    /*!< Wheel estimator active mode failed. Reinitialising */
    AGC_MESSAGE_WHEEL_ESTIMATOR_DEACTIVATED = 5                                       /*!< Wheel estimator deactivated */
} AGC_MESSAGE_WHEEL_ESTIMATOR_E;

typedef enum tag_AGC_MESSAGE_STEERING_TEST_E                          /*!< List of Steering test messages */
{
    AGC_MESSAGE_STEERING_TEST_NO_DESCRIPTION = 0,                                   /*!< No message */
    AGC_MESSAGE_STEERING_TEST_PRE_MAP = 1,                                          /*!< Steering test pre map pwm actuator */
    AGC_MESSAGE_STEERING_TEST_POST_MAP = 2,                                         /*!< Steering test post map pwm actuator */
    AGC_MESSAGE_STEERING_TEST_USER_OVERRIDE = 3,                                    /*!< Steering test user override actuation */
    AGC_MESSAGE_STEERING_TEST_MAX_OUTPUT = 4                                        /*!< Steering test max actuation */
} AGC_MESSAGE_STEERING_TEST_E;

typedef enum tag_AGC_MESSAGE_IMU_ERROR_CODE_E                                /*!< List of IMU Errors. Error Code may be one or a combination of more of this values */
{
    AGC_MESSAGE_IMU_ERROR_ACCX_VOLTAGE_ERROR            =(uint32_t)(0x1<<0),  /*!< Accelerometer X voltage out of range */
    AGC_MESSAGE_IMU_ERROR_ACCY_VOLTAGE_ERROR            =(uint32_t)(0x1<<1),  /*!< Accelerometer Y voltage out of range */
    AGC_MESSAGE_IMU_ERROR_ACCZ_VOLTAGE_ERROR            =(uint32_t)(0x1<<2),  /*!< Accelerometer Z voltage out of range */
    AGC_MESSAGE_IMU_ERROR_GYROP_VOLTAGE_ERROR           =(uint32_t)(0x1<<3),  /*!< Gyroscope P voltage out of range */
    AGC_MESSAGE_IMU_ERROR_GYROQ_VOLTAGE_ERROR           =(uint32_t)(0x1<<4),  /*!< Gyroscope Q voltage out of range */
    AGC_MESSAGE_IMU_ERROR_GYROR_VOLTAGE_ERROR           =(uint32_t)(0x1<<5),  /*!< Gyroscope R voltage out of range */
    AGC_MESSAGE_IMU_ERROR_GYROP_TEMP_VOLTAGE_ERROR      =(uint32_t)(0x1<<6),  /*!< Gyroscope P Temp Sensor voltage out of range */
    AGC_MESSAGE_IMU_ERROR_GYROQ_TEMP_VOLTAGE_ERROR      =(uint32_t)(0x1<<7),  /*!< Gyroscope Q Temp Sensor voltage out of range */
    AGC_MESSAGE_IMU_ERROR_GYROR_TEMP_VOLTAGE_ERROR      =(uint32_t)(0x1<<8),  /*!< Gyroscope R Temp Sensor voltage out of range */
    AGC_MESSAGE_IMU_ERROR_G_ERROR                       =(uint32_t)(0x1<<9),  /*!< Gravity magnitude out of range */
    AGC_MESSAGE_IMU_ERROR_REFERENCE_VOLTAGE_ERROR       =(uint32_t)(0x1<<10), /*!< Reference voltage out of range */
    AGC_MESSAGE_IMU_ERROR_CALIB_ERROR                   =(uint32_t)(0x1<<11), /*!< Invalid IMU Calibration values*/
    AGC_MESSAGE_IMU_ERROR_COMM_ERROR                    =(uint32_t)(0x1<<12), /*!< Communication error with IMU*/
} AGC_MESSAGE_IMU_ERROR_E;

#ifndef AGC_USER_COMMAND_E
#define AGC_USER_COMMAND_E
enum tagAGC_USER_COMMAND_E           /*!< List of Possible User Commands in P30 ShortParam */
{
    AGC_UC_IGNORE_COMMAND           =  0,
    AGC_UC_HYD_SET_POINT            =  1,
    AGC_UC_HB_PWM                   =  2,
    AGC_UC_NULL                     =  3,
    AGC_UC_HYD_DEAD_BAND            =  4,
    AGC_UC_HYD_KV                   =  5,
    AGC_UC_HYD_POWER_BAND           =  6,
    AGC_UC_HYD_APPROACH_FACTOR      =  7,
    AGC_UC_HYD_KI                   =  8,
    AGC_UC_HYD_KD                   =  9,
    AGC_UC_FILT_POLO                = 10,
    AGC_UC_FILT_TEORIC_GAIN         = 11,
    AGC_UC_FILT_DESIRED_GAIN        = 12,
    AGC_UC_INTEGRATOR               = 13,
    AGC_UC_DEAD_BAND                = 14,
    AGC_UC_FILTER_WHEEL             = 15,
    AGC_UC_FILT_RETARDO_DESIRED     = 16,
    AGC_UC_OFFSET_THRESHOLD_MTS     = 17, //pilotlogic
    AGC_UC_MAX_SPEED_DD_CONST       = 20,
    AGC_UC_USE_HEADING_COMPENSATION = 21,
    AGC_UC_HEADLAND_CURVATURE_GAIN  = 22, //pilotguidance_pattern
    AGC_UC_HEADLAND_FEEDFW_FILTER   = 23, //pilotguidance_pattern
    AGC_UC_HEADLAND_HEADING_WEIGHT  = 24, //pilotguidance_pattern
    AGC_UC_HEADLAND_SET_SPEED       = 25,
    AGC_UC_HEADLAND_CONTROL_SPEED   = 26,
    AGC_UC_HEADLAND_CURV_LOOKAHEAD  = 27, //pilotguidance_pattern
    AGC_UC_HEADLAND_LOOKAHEAD_MIN   = 28, //pilotguidance_pattern [also 57, 58, 59 and 71]
    AGC_UC_SHOW_HL_ERROR            = 29,
	AGC_UC_LINEAR_APPROACH_ENABLE   = 30,
    AGC_UC_CURRENT_CTRL_KI          = 32,
    AGC_UC_WAS_FILTER_GAIN          = 33,
    AGC_UC_INTEGRAL_SPEED_GAIN_DD   = 50,
    AGC_UC_BOTTLE_K_CONTROLLER      = 60, //Also used in pilotguidance_pattern!
    AGC_UC_BOTTLE_K_LOWPASSFILTER   = 61, //Also used in pilotguidance_pattern!
    AGC_UC_BRIDGE_ACTUATOR_CAN      = 100,
    AGC_UC_MAX_ACT_POSITIVE         = 110,
    AGC_UC_MAX_ACT_NEGATIVE         = 111,
    AGC_UC_MIN_RPM                  = 184,
    AGC_UC_OLGAIN_FACTOR            = 185,
    AGC_UC_WAS_BIAS_GAIN            = 186,
    AGC_UC_SPEED_PROFILE_ONLINE_KPH     = 187,
    AGC_UC_SPEED_PROFILE_HEADLAND_KPH   = 188,
    AGC_UC_LPF_POLE                 = 189,
    AGC_UC_GAIN_CURVATURE           = 190,
    AGC_UC_ENABLE_WAE               = 192,
    AGC_UC_GAIN_FREEPLAY            = 193,
    AGC_UC_SW_CURVATURE             = 196,
    AGC_UC_GAIN_DZ                  = 199,
	AGC_UC_ENABLE_SEND_BENZIER_LIST  = 205,
	AGC_UC_DISABLE_SEND_BENZIER_LIST = 206,
    AGC_UC_SEND_STACK_INFO           = 207,
    AGC_UC_DEBUG_REF                 = 208,
    AGC_UC_TERRANFILTERS_MODE        = 209
};
#endif

#ifndef AGC_USER_MESSAGE_E
#define AGC_USER_MESSAGE_E
enum tagAGC_USER_MESSAGE_E           /*!< List of Possible User Messages P30 */
{
    AGC_UM_AB_LINE_DEBUG                = 1,
    AGC_UM_ABGC_TYPE                    = 2,
    AGC_NED_TC                          = 3,
    AGC_UM_STACK_SIZE                   = 4,
    AGC_UM_STACK_USED                   = 5
};
#endif

#ifndef AGC_DD_COMMAND
#define AGC_DD_COMMAND
enum tagAGC_DD_COMMAND          /*!< List of commands for DirectDrive */
{
    DD_COMMAND_DISENGAGE = 100,                       /*!< Stop motor, free running */
    DD_COMMAND_POSITION_CONTROL = 101,                /*!< Set motor in position control mode */
    DD_COMMAND_SPEED_CONTROL = 102,                   /*!< Set motor in speed control mode */
    DD_COMMAND_TORQUE_CONTROL = 103,                  /*!< Set motor in torque control mode */
    DD_COMMAND_SET_ZERO_REFERENCE = 104,              /*!< Sets actual Position as zero */
    DD_COMMAND_HALL_START_CALIB = 105,                /*!< Start Hall Calibration. Is necessary to run once for each device, factory calibration */
    DD_COMMAND_HALL_ALIGN = 106,                      /*!< Start Hall alignment proccess */
    DD_COMMAND_CONTROLLER_START_CALIB = 107,          /*!< Start controller calibration */
    DD_COMMAND_CANCEL_CALIBRATIONS = 108,             /*!< Abort current calibration */
    DD_COMMAND_CLEAR_ERROR_HISTORY = 109,             /*!< Clear error history */
    DD_COMMAND_ACTIVATE_DRIVERS = 110,                /*!< Activate drivers enable signal without turning on the controller */
    DD_COMMAND_DEACTIVATE_DRIVERS = 111,              /*!< Deactivate divers enable signal. If controller is active, it will stop */
    DD_COMMAND_SEND_DEBUG_DATA = 112,                 /*!< Start sending debug data */
    DD_COMMAND_STOP_DEBUG_DATA = 113,                 /*!< Stop sending debug data, return to normal mode */
    //AGC_COMMAND_USE_POTE_FOR_ANGLE = 114,
    //AGC_COMMAND_DO_NOT_USE_POTE_FOR_ANGLE = 115,
    DD_COMMAND_IGNORE_STEER = 116,                    /*!< DirectDrive ignores commands from CANSteer and resets COMM_TIMEOUT error */
    DD_COMMAND_ACT_ON_STEER = 117,                    /*!< DirectDrive resumes interpreting commands from CANSteer. COMM_TIMEOUT error is functional after this command */
    DD_COMMAND_SEND_ANALOG_INPUTS = 118,              /*!< DirectDrive sends burst of analogic inputs value. Debug purposes only */
    DD_COMMAND_PWM_TEST = 119,                        /*!< DirectDrive activates during a short period of time PWM outputs */
    DD_COMMAND_SET_DRIVER_OUTPUT = 120,               /*!< DirectDrive activates drivers in fixed mode */
    DD_COMMAND_START_DEMO = 121,                      /*!< DirectDrive auto generates random references */
    DD_COMMAND_STOP_DEMO = 122,                       /*!< DirectDrive returns to normal mode */
    DD_COMMAND_SEND_ENCODER_HALL_INFO = 123           /*!< DirectDrive sends hall position or hall error on hall interruption */
};
#endif

#ifndef AGC_DD_MESSAGE
#define AGC_DD_MESSAGE
enum tagAGC_DD_MESSAGE                              /*!< List of messages for DirectDrive */
{
    DD_MESSAGE_CONTROL_DISENGAGED                       = 100,  /*!< Motor stopped */
    DD_MESSAGE_CONTROL_DISENGAGED_USER_OVERRIDE         = 101,  /*!< Motor stopped because of user steering wheel override (depends on sensitivity) */
    DD_MESSAGE_CONTROL_DISENGAGED_ERROR                 = 102,  /*!< Motor stopped because of error */
    DD_MESSAGE_CONTROL_DISENGAGED_TIMEOUT               = 103,  /*!< Motor stopped because of HSC canmsg timeout */
    DD_MESSAGE_CANNOT_START_CONTROL                     = 104,  /*!< Controller Init Timed Out; Check for errors */
    DD_MESSAGE_POSITION_CONTROL_ACTIVATED               = 105,  /*!< Motor is in position control mode */
    DD_MESSAGE_SPEED_CONTROL_ACTIVATED                  = 106,  /*!< Motor is in speed control mode */
    DD_MESSAGE_TORQUE_CONTROL_ACTIVATED                 = 107,  /*!< Motor is in torque control mode */
    DD_MESSAGE_ENCODER_ALIGNED_DEFAULT                  = 108,  /*!< Hall sensors aligned with default values */
    DD_MESSAGE_ENCODER_ALIGNED_CALIBRATED               = 109,  /*!< Hall sensors aligned with calibrated values */
    DD_MESSAGE_HALL_STARTED_CALIB                       = 110,  /*!< Started Hall Calibration. It is necessary to run once for each device, factory calibration */
    DD_MESSAGE_CANNOT_START_HALL_CALIB                  = 111,  /*!< Hall calibration cannot start; conditions are not ok */
    DD_MESSAGE_HALL_INTERRUPTED_BY_USER_CALIB           = 112,  /*!< Hall calibration aborted */ 
    DD_MESSAGE_HALL_ERROR_CALIB                         = 113,  /*!< Hall calibration error */
    DD_MESSAGE_HALL_CALIB_SUCCESSFUL                    = 114,  /*!< Hall calibration ended correctly */
    DD_MESSAGE_CONTROLLER_CALIB_STARTED                 = 115,  /*!< Controller calibration started */
    DD_MESSAGE_CONTROLLER_CALIB_SUCCESSFUL              = 116,  /*!< Controller calibration ended correctly */
    DD_MESSAGE_CONTROLLER_CALIB_INTERRUPTED_BY_USER     = 117,  /*!< Controller calibration interrupted by user */
    DD_MESSAGE_CONTROLLER_CALIB_TIMEOUT                 = 118,  /*!< Controller calibration timed out */
    DD_MESSAGE_CONTROLLER_CALIB_CANNOT_START            = 119,  /*!< Controller calibration cannot start; conditions are not ok */
    DD_MESSAGE_CONTROLLER_CALIB_ERROR                   = 120,  /*!< Controller calibration error */
    DD_MESSAGE_CONTROLLER_CALIB_FAIL                    = 121,  /*!< Controller calibration cannot reach suitable value */
    DD_MESSAGE_DRIVERS_ACTIVATED                        = 122,  /*!< Drivers enable signal activated without turning on the controller */
    DD_MESSAGE_DRIVERS_DEACTIVATED                      = 123,  /*!< Divers enable signal deactivated. If controller is active, it will stop */
    DD_MESSAGE_ANALOG_INPUTS                            = 124,  /*!< ShortParam is the input identification number, long param is the read value */
    DD_MESSAGE_ENCODER_ALIGNMENT                        = 125,  /*!< LongParam is hall alignment error in encoder pulses, Offset = 30000 */
    DD_MESSAGE_USERMESSAGE                              = 240
};
#endif

#ifndef AGC_DD_OUTPUT_MODE
#define AGC_DD_OUTPUT_MODE
enum tagAGC_DD_OUTPUT_MODE          /*!< List of Short_Param for DD_COMMAND_SET_DRIVER_OUTPUT*/
{
    DD_OUTPUT_OFF_OFF_OFF               = (uint8_t) 0, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    
    DD_OUTPUT_OFF_PWM_LOW               = (uint8_t) 1, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_LOW_PWM_OFF               = (uint8_t) 2, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_LOW_OFF_PWM               = (uint8_t) 3, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_OFF_LOW_PWM               = (uint8_t) 4, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_PWM_LOW_OFF               = (uint8_t) 5, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_PWM_OFF_LOW               = (uint8_t) 6, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/

    DD_OUTPUT_PWM_PWM_PWM               = (uint8_t)10, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/

    DD_OUTPUT_PWM_LOW_LOW               = (uint8_t)11, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_LOW_PWM_LOW               = (uint8_t)12, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_LOW_LOW_PWM               = (uint8_t)13, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    DD_OUTPUT_LOW_LOW_LOW               = (uint8_t)14, /* Long Param represents PWM output; Offset 0; Scale 0,1%*/
    
    DD_OUTPUT_OFF_PWM_LOW_I             = (uint8_t)21, /* Long Param represent current set point; Offset 0; Scale 0,01 A */
    DD_OUTPUT_LOW_PWM_OFF_I             = (uint8_t)22, /* Long Param represent current set point; Offset 0; Scale 0,01 A */
    DD_OUTPUT_LOW_OFF_PWM_I             = (uint8_t)23, /* Long Param represent current set point; Offset 0; Scale 0,01 A */
    DD_OUTPUT_OFF_LOW_PWM_I             = (uint8_t)24, /* Long Param represent current set point; Offset 0; Scale 0,01 A */
    DD_OUTPUT_PWM_LOW_OFF_I             = (uint8_t)25, /* Long Param represent current set point; Offset 0; Scale 0,01 A */
    DD_OUTPUT_PWM_OFF_LOW_I             = (uint8_t)26  /* Long Param represent current set point; Offset 0; Scale 0,01 A */
};
#endif

#ifndef TERRAN_COMMAND_E
#define TERRAN_COMMAND_E
enum tagTERRAN_COMMAND_E                 /*!< List of TERRAN mode configuration */
{
    TERRAN_COMMAND_AUTOMATIC            		=  0,  	/* TERRAN is in working mode */
    TERRAN_COMMAND_DEMO                 		=  1,  	/* TERRAN is in demo mode */
    TERRAN_COMMAND_ACK_ERROR            		=  2,  	/* TERRAN ack error */
    TERRAN_CONTROL_PID_PILOT            		=  3,  	/* TERRAN drive train control with a PID with GPS and IMU estimation of speed and yaw rate */
    TERRAN_CONTROL_PID_WSPEED           		=  4,  	/* TERRAN drive train control with a PID with wheel speed estimation of speed and yaw rate */
    TERRAN_CONTROL_OPEN_LOOP            		=  5,  	/* TERRAN drive train control in open loop, use a motor torque */
	TERRAN_COMMAND_CHANGE_SPEED_SIGN			=  6,  	/* TERRAN change sign of terran wheel speed estimation */	
	TERRAN_COMMAND_CHECK_SPEED_SIGN_PROT		=  7,	/* TERRAN enable inconsistent speed protection in terran.c */
	TERRAN_COMMAND_DONT_CHECK_SPEED_SIGN_PROT	=  8,	/* TERRAN disable inconsistent speed protection in terran.c */
	TERRAN_COMMAND_ENABLE_SPEED_SIGN_INFO		=  9,	/* TERRAN enable speed sign information getting from motots speed */
	TERRAN_COMMAND_DISABLE_SPEED_SIGN_INFO		= 10,	/* TERRAN disable speed sign information getting from motots speed */
};
#endif

#ifndef AGC_DD_USER_MESSAGE_E
#define AGC_DD_USER_MESSAGE_E
enum tagAGC_DD_USER_MESSAGE_E           /*!< List of Possible DD User Messages P60 */
{
    //AGC_DD_UM_ALIGNMENT_ERROR               = 1,
    AGC_DD_UM_LIBRARY_MEASURED_SPEED        = 2,
    //AGC_DD_UM_HALL_POSITION                 = 3,
    AGC_DD_UM_NO_MESSAGE                    = 255
};
#endif

#ifndef AGC_IMU_SELF_TEST_MODE
#define AGC_IMU_SELF_TEST_MODE
enum tagAGC_IMU_SELF_TEST_MODE          /*!< List of IMU self test configuration */
{
    AGC_IMU_SELF_TEST_OFF = 0,          /*!< GPIO_Set (ptGYRO_ST2, false); GPIO_Set (ptGYRO_ST1, false); */
    AGC_IMU_SELF_TEST_ONE = 1,          /*!< GPIO_Set (ptGYRO_ST2, false); GPIO_Set (ptGYRO_ST1, true); */
    AGC_IMU_SELF_TEST_TWO = 2           /*!< GPIO_Set (ptGYRO_ST2, true); GPIO_Set (ptGYRO_ST1, false); */
};
#endif

/* Defines ********************************************************************/
#define PGN_AUTOGUIDE_COMMAND               0xFFF8U
#define SIZE_AUTOGUIDE_COMMAND              8U  

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/******************************** General Msg *********************************/
typedef struct tagAUTOGUIDE_COMMAND_P30
{
    uint8_t  Page;
    uint8_t  Command;               /* Value from AGC_COMMAND_E; from TPS to CSTEER only */
    uint8_t  Message;               /* Value from AGC_MESSAGES_E; from CSTEER to TPS only*/
    uint8_t  ShortParam;            /* Short param for Command or Message */  
    uint32_t LongParam;             /* Long param for Command or Message */
} AUTOGUIDE_COMMAND_P30_T;

/******************************** Direct Drive ********************************/
typedef struct tagAUTOGUIDE_COMMAND_P60
{
    uint8_t  Page;
    uint8_t  DD_Command;               /* Value from AGC_DD_COMMAND */
    uint8_t  DD_Message;               /* Value from AGC_DD_MESSAGE */
    uint8_t  DD_ShortParam;            /* Short param for DD_Command or DD_Message */  
    uint32_t DD_LongParam;             /* Long param for DD_Command or DD_Message */
} AUTOGUIDE_COMMAND_P60_T;

/******************************** TERRAN ********************************/
typedef struct tagAUTOGUIDE_COMMAND_P70
{
    uint8_t  Page;
    uint8_t  T_Command;               /* Value from TERRAN_COMMANDS_E */
    uint8_t  T_Message;               /* Unused */
    uint8_t  T_ShortParam;            /* Short param for TERRAN command */  
    uint32_t T_LongParam;             /* Long param for TERRAN command */
} AUTOGUIDE_COMMAND_P70_T;
/******************************** TERRAN ********************************/


#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

/* New Union declaration */
typedef union tagAUTOGUIDE_COMMAND_U
{
/***** General Msg/Cmd *****/
    AUTOGUIDE_COMMAND_P30_T  P30;

/***** Guidance Configuration *****/
    AUTOGUIDE_COMMAND_P31_T  P31;
    AUTOGUIDE_COMMAND_P32_T  P32;
    AUTOGUIDE_COMMAND_P33_T  P33;
    AUTOGUIDE_COMMAND_P34_T  P34;
    AUTOGUIDE_COMMAND_P35_T  P35;
    AUTOGUIDE_COMMAND_P36_T  P36;
    AUTOGUIDE_COMMAND_P37_T  P37;
    AUTOGUIDE_COMMAND_P38_T  P38;
    AUTOGUIDE_COMMAND_P39_T  P39;
    AUTOGUIDE_COMMAND_P40_T  P40;
    AUTOGUIDE_COMMAND_P41_T  P41;
    AUTOGUIDE_COMMAND_P42_T  P42;
    AUTOGUIDE_COMMAND_P43_T  P43;
    AUTOGUIDE_COMMAND_P44_T  P44;

/***** Std Electric *****/
    AUTOGUIDE_COMMAND_P45_T  P45;
    AUTOGUIDE_COMMAND_P46_T  P46;
    //AUTOGUIDE_COMMAND_P47_T  P47;
    //AUTOGUIDE_COMMAND_P48_T  P48;
    //AUTOGUIDE_COMMAND_P49_T  P49;

/***** Hydraulic Valve *****/
    AUTOGUIDE_COMMAND_P50_T  P50;
    AUTOGUIDE_COMMAND_P51_T  P51;
    AUTOGUIDE_COMMAND_P52_T  P52;
    
/***** Open Loop Gain Calibration *****/    
    AUTOGUIDE_COMMAND_P54_T  P54;

/***** Headland Turn *****/
    AUTOGUIDE_COMMAND_P55_T  P55;
    AUTOGUIDE_COMMAND_P56_T  P56;
    
/***** Hydraulic Valve control by current *****/    
    AUTOGUIDE_COMMAND_P57_T  P57;
    AUTOGUIDE_COMMAND_P58_T  P58;
    //AUTOGUIDE_COMMAND_P59_T  P59;

/***** Direct Drive Msg/Cmd *****/
    AUTOGUIDE_COMMAND_P60_T  P60;
    
/***** Direct Drive *****/
    AUTOGUIDE_COMMAND_P61_T  P61;
    //AUTOGUIDE_COMMAND_P62_T  P62; /* Unused */
    AUTOGUIDE_COMMAND_P63_T  P63;
    AUTOGUIDE_COMMAND_P64_T  P64;
    AUTOGUIDE_COMMAND_P65_T  P65;
    AUTOGUIDE_COMMAND_P66_T  P66;
    AUTOGUIDE_COMMAND_P67_T  P67;
    
/***** ESi2 *****/    
    AUTOGUIDE_COMMAND_P68_T  P68;

/***** TERRAN Msg/Cmd *****/
    AUTOGUIDE_COMMAND_P70_T  P70;
    
/***** TERRAN *****/
    AUTOGUIDE_COMMAND_P71_T  P71;
    AUTOGUIDE_COMMAND_P72_T  P72;
    AUTOGUIDE_COMMAND_P73_T  P73;
	AUTOGUIDE_COMMAND_P80_T  P80;

    AUTOGUIDE_COMMAND_P81_T  P81;

} AUTOGUIDE_COMMAND_U;


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

/* End of $Workfile: AGC_canmsg.h$ */

