#ifndef N2K_GPF_CANMSG_H
#define N2K_GPF_CANMSG_H

/*! \page N2KGPF NMEA2000 GPS Position Fast
 * GNSSPositionRapidUpdate \n
 *                         \n
 * This PGN provides latitude and longitude referenced to WGS84.\n
 * Being defined as single frame Msg,as opposed to other PGNs that include latitude and longitude and are defined as fast multi-packet, \n
 * this PGN lends itself to being transmitted more frequently.\n
 *  \section sec3000 Latitude Position:
 *      Offset = <B>-90</B>, Factor = <B>1e-007</B>, Unit = <B>deg/bit</B> \n  
 *  \section sec3001 Longitude Position:
 *      Offset = <B>-180</B>, Factor = <B>1e-007</B>, Unit = <B>deg/bit</B> \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_N2K_GPS_POSITION_FAST           0x1F801U
#define SIZE_N2K_GPS_POSITION_FAST          8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagN2K_GPS_POSITION_FAST
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

/* End of $Workfile: N2K_GPF_canmsg.h$ */
