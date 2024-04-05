#ifndef N2K_GPDHPRU_CANMSG_H
#define N2K_GPDHPRU_CANMSG_H

/*! \page N2KGPDHPRU NMEA2000 GPS Position Delta, High 
 *   Precision Rapid Update \n
 *                          \n
 *  The "Position Delta, High Precision Rapid Update" Parameter Group is intended for applications where very high precision and
 *  very fast update rates are needed for position data. This PGN can provide delta position changes down to 1 millimeter with a delta
 *  time period accurate to 5 milliseconds. \n
 * 
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_N2K_GPS_POSITION_DELTA    0x1F803U
#define SIZE_N2K_GPS_POSITION_DELTA   8U


/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagN2K_GPS_POSITION_DELTA
{
    uint8_t      SID;
    uint8_t      TimeDelta; 
    int32_t      LatitudeDelta  :24;     /* Factor = 1e-005, Range = [], Unit = sec. */
    int32_t      LongitudeDelta :24;     /* Factor = 1e-005, Range = [], Unit = sec. */
} N2K_GPS_POSITION_DELTA_T;

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

/* End of $Workfile: N2K_GPDPG_canmsg.h$ */
