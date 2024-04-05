/*******************************************************************************
** $Revision: 2$
** $Date: 02/08/2018 02:10:50 p.m.$
** $Author:  Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef N2K_ADF_CANMSG_H
#define N2K_ADF_CANMSG_H

/*! \page N2KADF NMEA2000 Altitude Delta Fast
 * AltitudeDeltaFast       \n
 *                         \n
 * The "Altitude Delta Fast" Parameter Group is intended for applications where very high precision 
 * and very fast update rates are needed for altitude and course over ground data.\n
 * This PG can provide delta altitude changes down to 1 millimeter, a change in direction as small as 0.0057 degrees,
 * and with a delta time period accurate to 5 milliseconds.\n
 *  Latitude Position:
 *      Offset = <B>-90</B>, Factor = <B>1e-007</B>, Unit = <B>deg/bit</B> \n  
 *  \section sec3001 Longitude Position:
 *      Offset = <B>-180</B>, Factor = <B>1e-007</B>, Unit = <B>deg/bit</B> \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_N2K_ALTITUDE_DELTA_FAST           0x1F804U
#define SIZE_N2K_ALTITUDE_DELTA_FAST          8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef PACKED struct tagN2K_ALTITUDE_DELTA_FAST
{
    /* Factor = 1e-007, Range = [-90, 90], Unit = deg. */
    int32_t Latitude;
    /* Factor = 1e-007, Range = [-180, 180], Unit = deg. */
    int32_t Longitude;
} N2K_GPS_POSITION_FAST_T;

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

/* End of $Workfile: N2K_ADF_canmsg.h$ */
