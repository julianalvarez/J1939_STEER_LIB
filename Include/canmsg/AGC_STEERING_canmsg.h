
#ifndef AGC_STEERING_CANMSG_H
#define AGC_STEERING_CANMSG_H

/*!\page AGC AutoGuide Command
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tag_AGC_COMMAND_STEERING_E                  /*!< List of Steering Commands */
{
    AGC_COMMAND_STEERING_NO_CMD = 0,                                  /*!< No command */
    AGC_COMMAND_STEERING_SWITCH_ENGAGE_DISENGAGE = 1,                 /*!< Switch Engage/Disengage state */
    AGC_COMMAND_STEERING_ENGAGE = 2,                                  /*!< Engage steering */
    AGC_COMMAND_STEERING_DISENGAGE = 3,                               /*!< Disengage steering */
    AGC_COMMAND_STEERING_STOP_EXTERNAL_REF = 50,                      /*!< Stop steering with External Reference */
    //joystick cmd
//    AGC_COMMAND_STEERING_STOP_JOYSTICK_EXTERNAL_REF = 50,                      /*!< Stop steering with External Joystick Reference */
    AGC_COMMAND_STEERING_START_JOYSTICK_EXTERNAL_REF = 51,                     /*!< Start steering with External Joystick Reference */
    AGC_COMMAND_STEERING_EXTERNAL_JOYSTICK_REF_CURVATURE_VALUE = 52,           /*!< LongParam is External Curvature Reference value. (Factor 0.0001 m^-1/bit; Offset 100 m^-1) */
    AGC_COMMAND_STEERING_EXTERNAL_JOYSTICK_REF_WHEEL_ANGLE_VALUE = 54,         /*!< LongParam is External Wheel Angle Reference value. (Factor 0.0001 deg/bit; Offset 100 deg) */
    AGC_COMMAND_STEERING_EXTERNAL_JOYSTICK_REF_YAW_RATE_VALUE = 56,            /*!< LongParam is External Yaw Rate Reference value. (Factor 0.0001 rps/bit; Offset 100 rps) */
    AGC_COMMAND_STEERING_EXTERNAL_JOYSTICK_REF_DIFF_TORQUE_VALUE = 58,         /*!< LongParam is External Diff Torque Reference value. (Factor 0.0001 perc/bit; Offset 100 perc) */
    //screen cmd
//    AGC_COMMAND_STEERING_STOP_SCREEN_EXTERNAL_REF = 60,                      /*!< Stop steering with External Screen Reference */
    AGC_COMMAND_STEERING_START_SCREEN_EXTERNAL_REF = 61,                     /*!< Start steering with External Screen Reference */
    AGC_COMMAND_STEERING_EXTERNAL_SCREEN_REF_CURVATURE_VALUE = 62,           /*!< LongParam is External Curvature Reference value. (Factor 0.0001 m^-1/bit; Offset 100 m^-1) */
    AGC_COMMAND_STEERING_EXTERNAL_SCREEN_REF_WHEEL_ANGLE_VALUE = 64,         /*!< LongParam is External Wheel Angle Reference value. (Factor 0.0001 deg/bit; Offset 100 deg) */
    AGC_COMMAND_STEERING_EXTERNAL_SCREEN_REF_YAW_RATE_VALUE = 66,            /*!< LongParam is External Yaw Rate Reference value. (Factor 0.0001 rps/bit; Offset 100 rps) */
    AGC_COMMAND_STEERING_EXTERNAL_SCREEN_REF_DIFF_TORQUE_VALUE = 68,         /*!< LongParam is External Diff Torque Reference value. (Factor 0.0001 perc/bit; Offset 100 perc) */	
      
} AGC_COMMAND_STEERING_E;

typedef enum tag_AGC_MESSAGE_STEERING_E                     /*!< List of Steering messages */
{
    AGC_MESSAGE_STEERING_NO_MESSAGE = 0,                                   	    /*!< No message */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_TOO_FAR = 1,                  /*!< ERROR the vehicle is too far from line */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_ANGLE_TOO_HIGH = 2,           /*!< ERROR the vehicle angle is too high */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_SPEED_TOO_FAST = 3,           /*!< ERROR the vehicle speed is too high */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_SPEED_TOO_SLOW = 4,           /*!< ERROR the vehicle speed is too slow */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_MOTOR_CURRENT_TOO_HIGH = 5,   /*!< ERROR the motor current is too high */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_NO_PATH_DEFINED = 6,          /*!< ERROR there is no path defined for autopilot PointA and B */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_CANT_ACHIEVE_ON_LINE_CONDITIONS = 7,      /*!< ERROR the on line conditions cant be achieved the engage is off */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_BAD_ACTUATOR_CALIB = 8,     	/*!< ERROR there is no valid DMC calibration */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DESCRIPTION_BAD_TERRAIN_COMP_CALIB = 9,   /*!< ERROR there is no valid Terrain compensation Value */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_ACTUATOR_NOT_DETECTED = 10,               /*!< ERROR Actuator configured for usage but it is not detected */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_ACTUATOR_ERROR = 11,                      /*!< ERROR Actuator configured for usage but it is not operational */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_HEADING_NOT_AVAILABLE = 12,               /*!< ERROR filtered heading has not converged yet */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_SPEED_SENSE_UNDETERMINED = 70,            /*!< ERROR cannot determine if the vehicle is driving forwards or backwards */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_SPEED_SENSE_BACKWARDS = 71,               /*!< ERROR vehicle is driving backwards */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_CALIBRATING = 72,                         /*!< ERROR a calibration is being performed */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_WHEEL_ANGLE_NOT_READY = 73,               /*!< ERROR Wheel Angle estimation is not ready */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_WAE_ERROR = 84,                           /*!< ERROR Wheel Angle Estimator error */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_BAD_POTE_CALIBRATION = 74,                /*!< ERROR Bad Pote calibration values */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_DEFINING_AB_PATTERN = 75,                 /*!< ERROR Currently defining an AB pattern */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_RECEIVING_AB_PATTERN = 76,                /*!< ERROR Currently receiving an AB patterns */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_NO_GPS_FIX = 77,                          /*!< ERROR GPS signal has no fix */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_WHEEL_SENSOR_NOT_DETECTED = 78,           /*!< ERROR Wheel sensor configured for usage but it is not detected */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_WHEEL_SENSOR_ERROR = 79,                  /*!< ERROR Wheel sensor configured for usage but it is not operational */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_WHEEL_SENSOR_BAD_CONFIGURATION = 80,      /*!< ERROR Wheel sensor configuration is bad */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_LICENSE_INVALID = 81,                     /*!< ERROR Autopilot license is invalid */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_STEERING_WHEEL_MOVEMENT_NEEDED = 82,      /*!< ERROR It is necessary to move the steering wheel */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_IMU_ERROR = 83,                           /*!< ERROR IMU Diagnostic indicates error*/
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_NO_GPS = 85,                              /*!< ERROR GPS signal unavailable */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_SPEED_CONDITION = 86,                     /*!< ERROR Speed cannot engage */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_MONITOR_TIMEOUT = 87,                     /*!< ERROR Monitor Timeout */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_CALIBRATION_MISSING = 88,                 /*!< ERROR One or more calibrations were not made */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_ROADING_SWITCH_TRAVEL_MODE = 89,          /*!< ERROR Roading Switch in travel mode */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_PRE_ENGAGE_TIMEOUT = 90,                  /*!< ERROR Timeout for engage. Not reach all criteria for engage */
    AGC_MESSAGE_STEERING_ENGAGE_ERROR_INVALID_ENGAGE = 91,                      /*!< ERROR Invalid engage */
    AGC_MESSAGE_STEERING_ENGAGE_WARNING_IMU_ERROR = 200,                        /*!< WARNING IMU Diagnostic indicates error */
    AGC_MESSAGE_STEERING_ENGAGE_WARNING_SPEED_SENSE_UNDETERMINED = 201,         /*!< WARNING cannot determine if the vehicle is driving forwards or backwards */
    AGC_MESSAGE_STEERING_ENGAGE_WARNING_SPEED_SENSE_BACKWARDS = 202,            /*!< WARNING vehicle is driving backwards */
    AGC_MESSAGE_STEERING_ENGAGE_WARNING_GPS_LOW_FREQ = 203,                     /*!< WARNING gps frequency is lower than 20Hz */
    AGC_MESSAGE_STEERING_ENGAGE_WARNING_GPS_HIGH_FREQ = 204,                    /*!< WARNING gps frequency is higher than 20Hz */
    AGC_MESSAGE_STEERING_ENGAGE_WARNING_GPS_MULTIPLE_SOURCES = 205,             /*!< WARNING gps was received from multiple sources */
    AGC_MESSAGE_STEERING_ENGAGE_ENGAGED_ON_APPROACH = 150,                      /*!< ENGAGED mode ON APPROACH started */
    AGC_MESSAGE_STEERING_ENGAGE_ENGAGED_ONLINE = 151,                           /*!< ENGAGED mode ONLINE started */
    AGC_MESSAGE_STEERING_ENGAGE_ENGAGED_POWER_STEERING = 152,                   /*!< ENGAGED mode POWER STEERING started */
    AGC_MESSAGE_STEERING_ENGAGE_ENGAGED_WARNING_ERROR_BIG = 153,                /*!< ENGAGED WARNING Error big */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_USER_OVERRIDE = 13,                  /*!< DISENGAGED because user override */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_SPEED_TOO_LOW = 14,                  /*!< DISENGAGED because speed to low */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_SPEED_TOO_FAST = 20,                  /*!< DISENGAGED because speed to low */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_MOTOR_CURRENT_TOO_HIGH = 112,        /*!< DISENGAGED motor current is too high */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_NO_GPS = 15,                         /*!< DISENGAGED gps signal timed out */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_NO_GPS_FIX = 16,                     /*!< DISENGAGED gps signal lost fix */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_UNKNOWN = 17,                        /*!< DISENGAGED due to an unknown cause */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_CALIBRATION = 18,                    /*!< DISENGAGED due to the beginning of a calibration */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_WAE_REINIT = 19,                     /*!< DISENGAGED due to reinitialisation of the Wheel Angle Estimator */
    AGC_MESSAGE_STEERING_DISENGAGE_REQUEST_CALIB_FREEPLAY_SUCCESSFUL = 23,      /*!< DISENGAGED due to successful finish of freeplay calibration */
    AGC_MESSAGE_STEERING_CALIB_FREEPLAY_NEW_POINT = 24,                         /*!< Calibration FreePlay NewPoint  */
    AGC_MESSAGE_STEERING_CALIB_FREEPLAY_SHORT_PASS = 25,                        /*!< Calibration FreePlay Warning short pass  */
    AGC_MESSAGE_STEERING_CALIB_FREEPLAY_SUCCESSFUL = 26,                        /*!< Calibration FreePlay finished successfully  */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_CONFIGURATION_CHANGED = 100,         /*!< DISENGAGED due to a pilot configuration change */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_DEFINING_AB_PATTERN = 101,           /*!< DISENGAGED due to definition of a new AB pattern */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_RECEIVING_AB_PATTERN = 102,          /*!< DISENGAGED due to reception of a new AB pattern */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_ON_COMMAND = 103,                    /*!< DISENGAGED due to command */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_POTE_V_SPIKES = 110,                 /*!< DISENGAGED due to pote voltage spikes */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_POTE_V_OUTSIDE_RANGE = 111,          /*!< DISENGAGED due to pote voltage outside of the calibrated range */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_ACTUATOR_NOT_DETECTED = 113,         /*!< DISENGAGED Actuator configured for usage but it is not detected */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_ACTUATOR_ERROR = 114,                /*!< DISENGAGED Actuator configured for usage but it is not operational */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_WHEEL_SENSOR_NOT_DETECTED = 115,     /*!< DISENGAGED Wheel sensor configured for usage but it is not detected */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_WHEEL_SENSOR_ERROR = 116,            /*!< DISENGAGED Wheel sensor configured for usage but it is not operational */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_GPS_SOURCE_CHANGED = 117,            /*!< DISENGAGED Addres from which GPS is received changed */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_SPEED_DISENGAGED = 118,              /*!< DISENGAGED Speed disengaged */
    AGC_MESSAGE_STEERING_DISENGAGED_BY_PAUSE               = 119,               /*!< DISENGAGED system in pause state */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_GPS_QUALITY_CHANGE = 120,            /*!< DISENGAGED GPS Quality Changed */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_ROADING_SWITCH_TRAVEL_MODE = 133,    /*!< DISENGAGED Roading Switch in travel mode */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_ERROR_TOO_BIG = 134,                 /*!< DISENGAGED Error too big */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_SHUTTLE_SHIFT_TIMEOUT = 135,         /*!< DISENGAGED Shuttle Shift timeout */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_PRE_ENGAGE_ACTIVE  = 136,            /*!< DISENGAGED Pre Engage active for 20 seconds */
    AGC_MESSAGE_STEERING_ENGAGE_DISENGAGED_SHUTTLE_SHIFT_ACTIVE  = 137,         /*!< DISENGAGED Pre Engage active for 10 seconds */
    AGC_MESSAGE_STEERING_HEADLAND_DISENGAGED_SPEED_TOO_HIGH = 21,               /*!< HEADLAND DISENGAGED because of high speed */
    AGC_MESSAGE_STEERING_HEADLAND_DISENGAGED_ERROR_TOO_BIG = 22,                /*!< HEADLAND DISENGAGED pilot cannot follow headland */
    AGC_MESSAGE_STEERING_HEADLAND_ERROR_STEER_NOT_ONLINE = 30,                  /*!< HEADLAND ERROR steer is not online */
    AGC_MESSAGE_STEERING_HEADLAND_ERROR_NEAR_SWATH_DIFFERENT_FROM_CURRENT = 31, /*!< HEADLAND ERROR generated trajectory belongs a different swath */
    AGC_MESSAGE_STEERING_HEADLAND_ERROR_NEAR_POSITION_BEHIND = 32,              /*!< HEADLAND ERROR generated trajectory is behind the vehicle */
    AGC_MESSAGE_STEERING_HEADLAND_ERROR_NEAR_SENSE_OPPOSITE = 33,               /*!< HEADLAND ERROR generated trajectory's orientation opposite to vehicle's */
    AGC_MESSAGE_STEERING_HEADLAND_ERROR_UNKNOWN = 34,                           /*!< HEADLAND ERROR generated trajectory is invalid due to an unknown cause */
    AGC_MESSAGE_STEERING_HEADLAND_ERROR_UNSUPPORTED = 35,                       /*!< HEADLAND ERROR headland turning is unsupported for the actual configuration */
    AGC_MESSAGE_STEERING_HEADLAND_CANCELLED_WAITING_TIMED_OUT = 40,             /*!< HEADLAND CANCELLED waiting for headland for too long */
    AGC_MESSAGE_STEERING_HEADLAND_CANCELLED_BY_USER = 41,                       /*!< HEADLAND CANCELLED by the user */
    AGC_MESSAGE_STEERING_HEADLAND_CANCELLED_SPEED_TOO_HIGH = 42,                /*!< HEADLAND CANCELLED because of high speed */
    AGC_MESSAGE_STEERING_HEADLAND_ALARM_ERROR_BIG = 50,                         /*!< HEADLAND ALARM while turning, guidance error reached the alarm threshold */
    AGC_MESSAGE_STEERING_HEADLAND_ALARM_SPEED_TOO_HIGH = 51,                    /*!< HEADLAND ALARM vehicle speed surpassed the setspeed for turning */
    AGC_MESSAGE_STEERING_HEADLAND_STATUS_HEADLAND_PENDING = 60,                 /*!< HEADLAND STATUS generated trajectory OK, waiting for headland */
    AGC_MESSAGE_STEERING_HEADLAND_STATUS_HEADLAND_TURN_STARTED = 61,            /*!< HEADLAND STATUS headland reached, turning started */
    AGC_MESSAGE_STEERING_HEADLAND_STATUS_HEADLAND_TURN_ENDED = 62,              /*!< HEADLAND STATUS turning finished */
    AGC_MESSAGE_STEERING_EXT_REF_STARTED = 179,                                 /*!< EXT REF STARTED: Waiting for value */
    AGC_MESSAGE_STEERING_EXT_REF_CURVATURE_STARTED = 180,                       /*!< EXT REF STARTED: Curvature Reference */
    AGC_MESSAGE_STEERING_EXT_REF_WHEEL_ANGLE_STARTED = 181,                     /*!< EXT REF STARTED: Wheel Angle Reference */
    AGC_MESSAGE_STEERING_EXT_REF_YAW_RATE_STARTED = 182,                        /*!< EXT REF STARTED: Yaw Rate Reference */
    AGC_MESSAGE_STEERING_EXT_REF_DIFF_TORQUE_STARTED = 183,                     /*!< EXT REF STARTED: Differential Torque Reference */
    AGC_MESSAGE_STEERING_EXT_REF_STOPPED_ON_COMMAND = 185,                      /*!< EXT REF STOPPED: On command */
    AGC_MESSAGE_STEERING_EXT_REF_STOPPED_NO_REFERENCE = 186,                    /*!< EXT REF STOPPED: Reference timeout */
    AGC_MESSAGE_STEERING_EXT_REF_STOPPED_STATUS_ERROR = 187,                    /*!< EXT REF STOPPED: Status error */
    AGC_MESSAGE_STEERING_EXT_REF_START_ERROR_NOT_IDLE = 188,                    /*!< EXT REF START ERROR: Steering control not idle */
    AGC_MESSAGE_STEERING_EXT_REF_START_ERROR_STATUS_ERROR = 189,                /*!< EXT REF START ERROR: Status error */
	AGC_MESSAGE_STEERING_GUIDANCE_EMPTY_LIST = 130,								/*!< GUIDANCE STATUS: Bezier list is empty */
	AGC_MESSAGE_STEERING_GUIDANCE_LOCALIZER_ERROR = 131,						/*!< GUIDANCE STATUS: Localizer error */
	AGC_MESSAGE_STEERING_GUIDANCE_PATH_FINISHED = 132,							/*!< GUIDANCE STATUS: Path finished */
	AGC_MESSAGE_STEERING_GUIDANCE_PATH_UPDATE_REFERENCE_ERROR = 138,		       	/*!< GUIDANCE STATUS: Update reference*/
    AGC_MESSAGE_STEERING_TEST_START = 139,
    AGC_MESSAGE_STEERING_TEST_STOP = 140,
    AGC_MESSAGE_STEERING_TEST_ERROR_SPEED_TOO_LOW = 141,
    AGC_MESSAGE_STEERING_TEST_ERROR_SPEED_TOO_HIGH = 142
	
} AGC_MESSAGE_STEERING_E;

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

/* End of $Workfile: AGC_STEERING_canmsg.h$ */

