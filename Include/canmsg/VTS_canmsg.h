
#ifndef VTS_CANMSG_H
#define VTS_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define PGN_VEHICLE_TRACTION_STATUS               0xFFD9U
#define SIZE_VEHICLE_TRACTION_STATUS              5U	

/* Enums **********************************************************************/
typedef enum tagVEHICLE_TRACTION_STATUS 
{
    VEHICLE_TRACTION_READY              = 0, /* Power Train running automatic control */
    VEHICLE_TRACTION_STOPPED            = 1, /* Power Train stoped and listeing a start command */
    VEHICLE_TRACTION_EMERGENCY          = 2, /* Power Train with critical alarms or waiting a ack alarm */
    VEHICLE_TRACTION_UNAVAILABLE        = 3, /* Power Train in Manual mode */ 
    VEHICLE_TRACTION_TIMEOUT            = 4, /* Extended state for Motor TimeOut */     
} VEHICLE_TRACTION_STATUS;

/******************************** General Msg *********************************/

typedef struct tagMOTOR_TRACTION_STATUS_P0
{
    unsigned int    VT_MotorID : 4;         /* Motor identification from VEHICLE_TRACTION_LOCATION*/
    unsigned int    VT_CtrlMode: 4;         /* Information form VEHICLE_TRACTION_CONTROL_MODE in VTC */
    uint8_t         Page;                   /* Page */
    uint8_t         VT_Status;              /* information from VEHICLE_TRACTION_STATUS */
    uint16_t        VT_Speed;               /* Current motor Speed; Unit rpm; Factor 0.1; Offset 300 */
} VEHICLE_TRACTION_STATUS_P0_T;   

typedef union tagVEHICLE_TRACTION_STATUS_U
{
    VEHICLE_TRACTION_STATUS_P0_T  P0;
} VEHICLE_TRACTION_STATUS_U;

#endif /* end VTS_CANMSG_DATA_H */

/* End of $Workfile: VTS_canmsg.h$ */
