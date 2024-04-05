
#ifndef AGC_SYSTEM_CANMSG_H
#define AGC_SYSTEM_CANMSG_H

/*!\page AGC AutoGuide Command
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/

typedef enum tag_AGC_COMMAND_SYSTEM_E                     /*!< List of System commands */
{
    AGC_COMMAND_SYSTEM_NO_COMMAND 							= 0,    /*!< No message */
    AGC_COMMAND_SYSTEM_RESET_FILTERS 						= 1,    /*!< Reset filters */
    AGC_COMMAND_SYSTEM_RESET_GUIDANCE_INT 					= 2,    /*!< Reset guidance integrator */
    AGC_COMMAND_SYSTEM_RESET_CANSTEER 						= 3,    /*!< Reset CANSteer */
    AGC_COMMAND_SYSTEM_SET_ENABLE_ESI2_TRUE 				= 4,    /*!< Enable ESi2 */
    AGC_COMMAND_SYSTEM_SET_ENABLE_ESI2_FALSE 				= 5,    /*!< Disable ESi2 */
    AGC_COMMAND_SYSTEM_SET_SPEED_SIGN_FORWARD 				= 18,   /*!< Force positive speed sign */
    AGC_COMMAND_SYSTEM_SET_SPEED_SIGN_BACKWARD 				= 19,   /*!< Force negative speed sign */
    AGC_COMMAND_SYSTEM_PAUSE                                = 20,   /*!< Pause operation */
    AGC_COMMAND_SYSTEM_RESUME                               = 21,   /*!< Resume operation */
    AGC_COMMAND_SYSTEM_TIMEOUT_STEERING_WIFI                = 30,   /*!< Pause Timeout wifi steering connection */
    AGC_COMMAND_SYSTEM_TIMEOUT_SPEED_WIFI                   = 31,   /*!< Pause Timeout wifi speed connection */
    AGC_COMMAND_SYSTEM_ERROR_JOYSTICK_BLUETOOTH             = 32,   /*!< Pause Timeout joystick connection */
    AGC_COMMAND_SYSTEM_EXIT_JobApp                          = 33,   /*!< Pause Exit from JobApp */
    AGC_COMMAND_SYSTEM_INVISIBLE_WIDGET                     = 34,   /*!< Pause  scrren source and hided widget */
    AGC_COMMAND_SYSTEM_MOVEMENT_CANCEL                      = 50,   /*!< Movement cancel */
} AGC_COMMAND_SYSTEM_E;

typedef enum tag_AGC_MESSAGE_SYSTEM_E                     /*!< List of System messages */
{
    AGC_MESSAGE_SYSTEM_NO_MESSAGE                                   = 0,        /*!< No message */
    AGC_MESSAGE_SYSTEM_RESET_FILTERS_OK                             = 1,        /*!< Reset filters succeeded */
    AGC_MESSAGE_SYSTEM_RESET_GUIDANCE_INT_OK                        = 2,        /*!< Reset guidance integrator succeeded */
    AGC_MESSAGE_SYSTEM_RESET_FILTERS_ERROR                          = 3,        /*!< Reset filters due to error */
    AGC_MESSAGE_SYSTEM_SET_SPEED_SIGN_MANUALLY_OK                   = 75,       /*!< Set Speed sign manually*/
    AGC_MESSAGE_SYSTEM_SPEED_SIGN_RESET_AUTOMATICALLY               = 76,       /*!< Aytomatically reset Speed sign*/
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_START_OK                        = 80,       /*!< Movement start command OK */
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_START_ERROR_STATUS              = 81,       /*!< Movement start command ERROR: Status error */
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_START_ERROR_NOT_IDLE            = 82,       /*!< Movement start command ERROR: Not idle */
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_START_ERROR_NOT_ENABLED         = 83,       /*!< Movement start command ERROR: Not enabled */
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_START_ERROR_TIMEOUT             = 84,       /*!< Movement start command ERROR: Timeout */
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_CANCEL_OK                       = 90,       /*!< Movement cancel command OK */
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_CANCEL_ERROR_NOT_ACTIVE         = 91,       /*!< Movement cancel command ERROR: Not active */
    AGC_MESSAGE_SYSTEM_MOVEMENT_CMD_CANCEL_ERROR_TIMEOUT            = 92,       /*!< Movement cancel command ERROR: Timeout */
    AGC_MESSAGE_SYSTEM_MOVEMENT_FINISHED                            = 95,       /*!< Movement finished */
    AGC_MESSAGE_SYSTEM_MOVEMENT_ERROR_STATUS                        = 96,       /*!< Movement ERROR: Status error */
    AGC_MESSAGE_SYSTEM_PAUSE_CMD_OK                                 = 100,      /*!< Pause command OK */
    AGC_MESSAGE_SYSTEM_PAUSE_CMD_ERROR_NOT_IDLE                     = 101,      /*!< Pause command ERROR: System not idle */
    AGC_MESSAGE_SYSTEM_PAUSE_CMD_ERROR_NOT_ENABLED                  = 102,      /*!< Pause command ERROR: Pause not enabled */
    AGC_MESSAGE_SYSTEM_PAUSE_UNKNOWN                                = 110,      /*!< Paused: Unknown reason */
    AGC_MESSAGE_SYSTEM_PAUSE_EXT_STEERING_REF_TIMEOUT               = 111,      /*!< Paused: External steering reference timeout */
    AGC_MESSAGE_SYSTEM_PAUSE_EXT_SPEED_REF_TIMEOUT                  = 112,      /*!< Paused: External speed reference timeout */
    AGC_MESSAGE_SYSTEM_PAUSE_RF_HEARTBEAT_TIMEOUT                   = 113,      /*!< Paused: RF heartbeat timeout */
    AGC_MESSAGE_SYSTEM_PAUSE_RF_BUTTON                              = 114,      /*!< Paused: RF button pressed */
    AGC_MESSAGE_SYSTEM_PAUSE_MONITOR_HEARTBEAT_TIMEOUT              = 116,      /*!< Paused: Monitor heartbeat timeout */
    AGC_MESSAGE_SYSTEM_PAUSE_SPEED_STATUS_ERROR                     = 117,      /*!< Paused: Speed status error */
    AGC_MESSAGE_SYSTEM_PAUSE_STEERING_STATUS_ERROR                  = 118,      /*!< Paused: Steering status error */
    AGC_MESSAGE_SYSTEM_PAUSE_SPEED_DISENGAGE                        = 119,      /*!< Paused: Speed disengage */
    AGC_MESSAGE_SYSTEM_PAUSE_STEERING_DISENGAGE                     = 150,      /*!< Paused: Steering disengage */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_OK                                = 120,      /*!< Resume command OK */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_NOT_PAUSED                  = 121,      /*!< Resume command ERROR: System not paused */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_UNKNOWN                     = 122,      /*!< Resume command ERROR: Unknown reason */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_EXT_STEERING_REF_TIMEOUT    = 123,      /*!< Resume command ERROR: External steering reference timeout */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_EXT_SPEED_REF_TIMEOUT       = 124,      /*!< Resume command ERROR: External speed reference timeout */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_RF_HEARTBEAT_TIMEOUT        = 125,      /*!< Resume command ERROR: RF heartbeat timeout */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_RF_BUTTON                   = 126,      /*!< Resume command ERROR: RF button pressed */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_MONITOR_HEARTBEAT_TIMEOUT   = 127,      /*!< Resume command ERROR: Monitor heartbeat timeout */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_SPEED_STATUS_ERROR          = 128,      /*!< Resume command ERROR: Speed status error */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_STEERING_STATUS_ERROR       = 129,      /*!< Resume command ERROR: Steering status error */
    AGC_MESSAGE_SYSTEM_RESUME_CMD_ERROR_NOT_ENABLED                 = 130,      /*!< Resume command ERROR: Pause not enabled */
    AGC_MESSAGE_SYSTEM_NO_STEERING_SOURCE                           = 131,      /*!< Resume command ERROR: Attemp to start speed before steering reference */
    AGC_MESSAGE_SYSTEM_PAUSE_EXT_TIMEOUT_WIFI                       = 132,		/*!< Timeout wifi connection when driving with Joystick */
    AGC_MESSAGE_SYSTEM_PAUSE_EXT_TIMEOUT_JOYSTICK_BLUETOOTH         = 133,		/*!< Problems with Joystick dongle */
    AGC_MESSAGE_SYSTEM_PAUSE_COMMAND_SYSTEM_EXIT_JobApp             = 134,		/*!< Exit from job app with the vehicle mooving and not engaged to steering loop */
    AGC_MESSAGE_SYSTEM_PAUSE_INVISIBLE_WIDGET                       = 135,		/*!< Close driving widget when driving with screen command */
} AGC_MESSAGE_SYSTEM_E;

/* Defines ********************************************************************/
/* Typedefs *******************************************************************/
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

/* End of $Workfile: AGC_SYSTEM_canmsg.h$ */

