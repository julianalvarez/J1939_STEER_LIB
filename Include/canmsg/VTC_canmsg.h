
#ifndef VTC_CANMSG_H
#define VTC_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define PGN_VEHICLE_TRACTION_CONTROL              0xFFDAU
#define SIZE_VEHICLE_TRACTION_CONTROL             4U	

/* Enums **********************************************************************/

typedef enum tagVEHICLE_TRACTION_MOTOR_ID 
{
    VEHICLE_TRACTION_REAR_LEFT          = 0, /* Motor ID in power train */
    VEHICLE_TRACTION_REAR_RIGHT         = 1, /* Motor ID in power train */  
    VEHICLE_TRACTION_FRONT_LEFT         = 2, /* Motor ID in power train */
    VEHICLE_TRACTION_FRONT_RIGHT        = 3, /* Motor ID in power train */ 
} VEHICLE_TRACTION_MOTOR_ID;


typedef enum tagVEHICLE_TRACTION_ACTION 
{
    VEHICLE_TRACTION_STOP               = 0, /* Power Train Stop Automatic control */
    VEHICLE_TRACTION_START              = 1, /* Power Train Start Automatic control */
    VEHICLE_TRACTION_RESUME             = 2, /* Power Train Ack error */
    VEHICLE_TRACTION_NO_ACTION          = 3, /* Power Train no action */
} VEHICLE_TRACTION_ACTION;

typedef enum tagVEHICLE_TRACTION_CONTROL_MODE 
{
    VEHICLE_TRACTION_TORQUE_CONTROL     = 0, /* Power Train in torque control */
    VEHICLE_TRACTION_SPEED_CONTROL      = 1, /* Power Train in speed control */
    VEHICLE_TRACTION_DEMO_START         = 2, /* Power Train in demo mode start */
} VEHICLE_TRACTION_CONTROL_MODE;


/******************************** General Msg *********************************/

typedef struct tagMOTOR_TRACTION_CONTROL_P0
{
    unsigned int    MotorID         : 3;    /* Use VEHICLE_TRACTION_MOTOR_ID to identificate the motor to send this msg */
    unsigned int    Command         : 2;    /* Use VEHICLE_TRACTION_ACTION to choise the action*/
    unsigned int    ControlMode     : 3;    /* Use VEHICLE_TRACTION_CONTROL_MODE to choise the control mode */
    uint8_t         Page;                   /* Page */
    uint16_t        SetPoint;               /* Set Point to VEHICLE_TRACTION_CONTROL_MODE: Torque Mode: Unit: %; Offset: 100; Scale: 0.01; Speed Mode: Unit: RPM; Offset: 100; Scale: 0.01*/
} VEHICLE_TRACTION_CONTROL_P0_T;

typedef union tagVEHICLE_TRACTION_CONTROL_U
{
    VEHICLE_TRACTION_CONTROL_P0_T  P0;   
} VEHICLE_TRACTION_CONTROL_U;

#endif /* end VTC_CANMSG_DATA_H */

/* End of $Workfile: VTC_canmsg.h$ */
