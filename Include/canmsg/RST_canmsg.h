
#ifndef RST_CANMSG_H
#define RST_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_RESET_ECU                       0x0200U
#define SIZE_RESET_ECU                      8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagRESET_ECU
{
    uint8_t Data[SIZE_RESET_ECU];
} RESET_ECU_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 RST_CANMSG (uint32_t ctlr);
int32_t                 RST_CANMSG_SendReset (uint32_t ctrl, uint8_t destination);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: RST_canmsg.h$ */

