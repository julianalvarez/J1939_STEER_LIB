#ifndef SD_CANMSG_H
#define SD_CANMSG_H


/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_STEP_DATA_COMMAND               0xFF06U
#define SIZE_STEP_DATA_COMMAND              202U

#define MAX_STEP                            100U

/* Typedefs *******************************************************************/
typedef enum tagSTEP_DATA_E
{
    STPDATA_NO_ID = 0U,                        /*!< Comment */
    STPDATA_DMC_RESPONSE,
} STEP_DATA_E;

#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagSTEP_DATA
{
    uint16_t            DataId;
    uint16_t            DataStep_A[MAX_STEP];
} STEP_DATA_T;

#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

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

/* End of $Workfile: SD_canmsg.h$ */

