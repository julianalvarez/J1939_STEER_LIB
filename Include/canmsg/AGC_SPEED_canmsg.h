
#ifndef AGC_SPEED_CANMSG_H
#define AGC_SPEED_CANMSG_H

/*!\page AGC AutoGuide Command
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tag_AGC_COMMAND_SPEED_E                  /*!< List of Speed Commands */
{
    AGC_COMMAND_SPEED_NO_CMD = 0,                                  /*!< No command */
    AGC_COMMAND_SPEED_SWITCH_ENGAGE_DISENGAGE = 1,                 /*!< Switch Engage/Disengage state */
    AGC_COMMAND_SPEED_ENGAGE = 2,                                  /*!< Engage speed */
    AGC_COMMAND_SPEED_DISENGAGE = 3,                               /*!< Disengage speed */
    AGC_COMMAND_SPEED_STOP_EXTERNAL_REF = 50,                      /*!< Stop speed with External Reference */
    //joystick cmd
	AGC_COMMAND_SPEED_START_JOYSTICK_EXTERNAL_REF = 51,                     /*!< Start steering with External Joystick Reference */
	AGC_COMMAND_SPEED_EXTERNAL_JOYSTICK_REF_SPEED_VALUE = 52,               /*!< LongParam is External Speed Reference value. (Factor 0.0001 m/s/bit; Offset 100 m/s) */
    AGC_COMMAND_SPEED_EXTERNAL_JOYSTICK_REF_ACCELERATION_VALUE = 54,        /*!< LongParam is External Acceleration Reference value. (Factor 0.0001 m/s^2/bit; Offset 100 m/s^2) */
    AGC_COMMAND_SPEED_EXTERNAL_JOYSTICK_REF_COMMON_TORQUE_VALUE = 56,       /*!< LongParam is External Common Torque Reference value. (Factor 0.0001 perc/bit; Offset 100 perc) */
	//screen cmd
    //AGC_COMMAND_SPEED_STOP_SCREEN_EXTERNAL_REF = 60,                      /*!< Stop steering with External Screen Reference */
    AGC_COMMAND_SPEED_START_SCREEN_EXTERNAL_REF = 61,                       /*!< Start steering with External Screen Reference */
    AGC_COMMAND_SPEED_EXTERNAL_SCREEN_REF_SPEED_VALUE = 62,                 /*!< LongParam is External Speed Reference value. (Factor 0.0001 m/s/bit; Offset 100 m/s) */
    AGC_COMMAND_SPEED_EXTERNAL_SCREEN_REF_ACCELERATION_VALUE = 64,          /*!< LongParam is External Acceleration Reference value. (Factor 0.0001 m/s^2/bit; Offset 100 m/s^2) */
    AGC_COMMAND_SPEED_EXTERNAL_SCREEN_REF_COMMON_TORQUE_VALUE = 66,         /*!< LongParam is External Common Torque Reference value. (Factor 0.0001 perc/bit; Offset 100 perc) */
} AGC_COMMAND_SPEED_E;

typedef enum tag_AGC_MESSAGE_SPEED_E                     /*!< List of Speed messages */
{
    AGC_MESSAGE_SPEED_NO_MESSAGE = 0,                                       /*!< No message */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_UNSUPPORTED = 1,                         /*!< ENGAGE ERROR: Speed Control unsupported */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_SPEED_SENSE_INCONSISTENT = 2,            /*!< ENGAGE ERROR: Speed Sense inconsistent */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_STEERING_CONDITION = 3,                  /*!< ENGAGE ERROR: Steering cannot engage */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_CANT_ACHIEVE_ON_LINE_CONDITIONS = 4,     /*!< ENGAGE ERROR: The on line conditions cant be achieved */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_MONITOR_TIMEOUT = 5,                     /*!< ENGAGE ERROR: Monitor Timeout */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_ACTUATOR_NOT_DETECTED = 6,               /*!< ENGAGE ERROR: Actuator not detected */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_ACTUATOR_ERROR = 7,                      /*!< ENGAGE ERROR: Actuator error */
    AGC_MESSAGE_SPEED_ENGAGE_ERROR_LICENSE_INVALID = 8,                     /*!< ENGAGE ERROR: License invalid */
    AGC_MESSAGE_SPEED_DISENGAGED_NO_GPS = 50,                               /*!< DISENGAGED: No GPS */
    AGC_MESSAGE_SPEED_DISENGAGED_NO_GPS_FIX = 51,                           /*!< DISENGAGED: No GPS Fix */
    AGC_MESSAGE_SPEED_DISENGAGED_UNKNOWN = 52,                              /*!< DISENGAGED: Unknown */
    AGC_MESSAGE_SPEED_DISENGAGED_ACTUATOR_ERROR = 53,                       /*!< DISENGAGED: Actuator Error */
    AGC_MESSAGE_SPEED_DISENGAGED_BY_COMMAND = 54,                           /*!< DISENGAGED: By command */
    AGC_MESSAGE_SPEED_DISENGAGED_ACTUATOR_NOT_DETECTED = 55,                /*!< DISENGAGED: Actuator not detected */
    AGC_MESSAGE_SPEED_DISENGAGED_SPEED_SENSE_INCONSISTENT = 56,             /*!< DISENGAGED: Speed Sense inconsistent */
    AGC_MESSAGE_SPEED_DISENGAGED_STEERING_DISENGAGE = 57,                   /*!< DISENGAGED: Steering disengaged */
	AGC_MESSAGE_SPEED_DISENGAGED_BY_PAUSE        = 58,                      /*!< DISENGAGED: Monitor timeout */
    AGC_MESSAGE_SPEED_ENGAGED_ON_APPROACH = 150,                            /*!< ENGAGED: On approach */
    AGC_MESSAGE_SPEED_ENGAGED_ONLINE = 151,                                 /*!< ENGAGED: Online */
    AGC_MESSAGE_SPEED_ENGAGED_POWER_MODE = 152,                             /*!< ENGAGED: Power Mode */
    AGC_MESSAGE_SPEED_EXT_REF_STARTED = 179,                                /*!< EXT REF STARTED: Waiting for value */
    AGC_MESSAGE_SPEED_EXT_REF_SPEED_STARTED = 180,                          /*!< EXT REF STARTED: Speed Reference */
    AGC_MESSAGE_SPEED_EXT_REF_ACCELERATION_STARTED = 181,                   /*!< EXT REF STARTED: Acceleration Reference */
    AGC_MESSAGE_SPEED_EXT_REF_COMMON_TORQUE_STARTED = 182,                  /*!< EXT REF STARTED: Common Torque Reference */
    AGC_MESSAGE_SPEED_EXT_REF_STOPPED_ON_COMMAND = 185,                     /*!< EXT REF STOPPED: On command */
    AGC_MESSAGE_SPEED_EXT_REF_STOPPED_NO_REFERENCE = 186,                   /*!< EXT REF STOPPED: Reference timeout */
    AGC_MESSAGE_SPEED_EXT_REF_STOPPED_STATUS_ERROR = 187,                   /*!< EXT REF STOPPED: Status error */
    AGC_MESSAGE_SPEED_EXT_REF_START_ERROR_NOT_IDLE = 188,                   /*!< EXT REF START ERROR: Speed control not idle */
    AGC_MESSAGE_SPEED_EXT_REF_START_ERROR_STATUS_ERROR = 189,               /*!< EXT REF START ERROR: Status error */
} AGC_MESSAGE_SPEED_E;

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

/* End of $Workfile: AGC_SPEED_canmsg.h$ */

