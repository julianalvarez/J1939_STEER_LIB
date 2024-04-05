#ifndef N2K_VH_CANMSG_H
#define N2K_VH_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tagHEADING_SOURCE
{
 	UNAVAILABLE     = 0,
 	GYRO            = 1,
 	GNSS       	    = 2
} HEADING_SOURCE_E;

/* Defines ********************************************************************/
#define PGN_N2K_GPS_VESSEL_HEADING      0x1F112U
#define SIZE_N2K_GPS_VESSEL_HEADING          8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagN2K_GPS_VESSEL_HEADING
{
    uint8_t       SID;
    uint16_t       Heading;
    uint16_t       Deviation;
    uint16_t       Variation;
    unsigned int  Rvd               :4;
    unsigned int  HeadingSource     :2;
    unsigned int  HeadingReference  :2;
} N2K_GPS_VESSEL_HEADING_T;

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

/* End of $Workfile: N2K_VH_canmsg.h$ */
