/*******************************************************************************
** $Revision: 1$
** $Date: 16/05/2018 01:06:50 p.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef ARI_CANMSG_H 
#define ARI_CANMSG_H

/*! \page ARI Angular Rate Information
 *  \n
 *  \section se50 Pitch Rate Extended Range:
 *      Offset = <B>-250</B>, Factor = <B>1/128</B>, Unit = <B>deg/s</B> \n  
 *  \section se51 Roll Rate Extended Range:
 *      Offset = <B>-250</B>, Factor = <B>1/128</B>, Unit = <B>deg/s</B> \n  
 *  \section se52 Yaw Rate Extended Range:
 *      Offset = <B>-250</B>, Factor = <B>1/128</B>, Unit = <B>deg/s</B> \n  
 *  \section se53 Pitch Rate Extended Range Figure of Merit:
 *      0b00 = <B>Pitch Rate is fully functional. Data is within sensor specification</B>         \n 
 *      0b01 = <B>Pitch Rate is degraded. Data is suspect due to environmental conditions</B>         \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section se54 Roll Rate Extended Range Figure of Merit:
 *      0b00 = <B>Roll Rate is fully functional. Data is within sensor specification</B>         \n 
 *      0b01 = <B>Roll Rate is degraded. Data is suspect due to environmental conditions</B>         \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section se55 Yaw Rate Extended Range Figure of Merit:
 *      0b00 = <B>Yaw Rate is fully functional. Data is within sensor specification</B>         \n 
 *      0b01 = <B>Yaw Rate is degraded. Data is suspect due to environmental conditions</B>         \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section se56 Angular Rate Measurement Latency:
 *      Offset = <B>0</B>, Factor = <B>0.5</B>, Unit = <B>ms</B> \n  
 */

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define PGN_ANGULAR_RATE_INFORMATION        0xF02AU
#define SIZE_ANGULAR_RATE_INFORMATION       8U

/* Enums **********************************************************************/
typedef enum tagANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT
{
  ANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT_FULLY_FUNCTIONAL = 0x0U,
  ANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT_DEGRADED 		= 0x1U,
  ANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT_ERROR 			= 0x2U
} ANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT_E;

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagANGULAR_RATE_INFORMATION
{
    /* Factor = 1/128 Range = [-250, 250.992], Unit = deg/s. */
    uint16_t     PitchRateExtendedRange;
    /* Factor = 1/128 Range = [-250, 250.992], Unit = deg/s. */
    uint16_t     RollRateExtendedRange;
    /* Factor = 1/128 Range = [-250, 250.992], Unit = deg/s. */
    uint16_t     YawRateExtendedRange;
	/* Value from ANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT_E */
    unsigned int PitchRateExtendedRangeFigureOfMerit :2;
	/* Value from ANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT_E */
    unsigned int RollRateExtendedRangeFigureOfMerit  :2;
	/* Value from ANGULAR_RATE_INFORMATION_FIGURE_OF_MERIT_E */
    unsigned int YawRateExtendedRangeFigureOfMerit   :2;
    /* Not defined. Set to 0b11 */
    unsigned int Rvd1 :2;
    /* Not defined. Set to 0xFF. */
    uint8_t      Rvd2;
} ANGULAR_RATE_INFORMATION_T;

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

/* End of $Workfile: ACCS_canmsg.h$ */
