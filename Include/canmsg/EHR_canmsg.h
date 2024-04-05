
#ifndef EHR_CANMSG_H
#define EHR_CANMSG_H

/*! \page EHR Engine Hours Revolution
 *  \section sec55 Engine Total Hours of Operation (SPN 247): 
 *      Offset = <B>0</B>, Factor = <B>.05</B>, Unit = <B>Hr/bit</B> \n
 *  \section sec56 Engine Total Revolutions (SPN 249): 
 *      Offset = <B>0</B>, Factor = <B>1000</B>, Unit = <B>r/bit</B> \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_ENGINE_HOURS_REVOLUTION	    0xFEE5U
#define SIZE_ENGINE_HOURS_REVOLUTION	    8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagENGINE_HOURS_REVOLUTION
{
    uint32_t TotalEngineHours; 
    uint32_t TotalEngineRevolutions;
} ENGINE_HOURS_REVOLUTION_T;

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

/* End of $Workfile: EHR_canmsg.h$ */
