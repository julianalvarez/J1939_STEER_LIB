/*******************************************************************************
** $Revision: 1$
** $Date: 01/11/2018 01:06:50 p.m.$
** $Author: dlipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef SSI2_CANMSG_H 
#define SSI2_CANMSG_H

/*! \page SSI2 Slope Sensor Information 2
 *  \n
 *  \section SPN Pitch Angle (Ext. Range):
 *      Offset = <B>-250</B>, Factor = <B>1/32768</B>, Unit = <B>deg</B> \n  
 *  \section SPN RollAngle (Ext. Range):
 *      Offset = <B>-250</B>, Factor = <B>1/32768</B>, Unit = <B>deg</B> \n  
 *  \section SPN PitchAngleCompensation (Ext. Range):
 *      0b00 = <B>Compensation Off</B>         \n 
 *      0b01 = <B>Compensation On</B>         \n
 *      0b10 = <B>Error</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section SPN PitchAngleFigureOfMerit (Ext. Range):
 *      0b00 = <B>Fully Functional</B>         \n 
 *      0b01 = <B>Degraded</B>         \n
 *      0b10 = <B>Error</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section SPN RollAngleCompensation (Ext. Range):
 *      0b00 = <B>Compensation Off</B>         \n 
 *      0b01 = <B>Compensation On</B>         \n
 *      0b10 = <B>Error</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section SPN RollAngleFigureOfMerit (Ext. Range):
 *      0b00 = <B>Fully Functional</B>         \n 
 *      0b01 = <B>Degraded</B>         \n
 *      0b10 = <B>Error</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section se56 RollAndPitchMeasurementLatency:
 *      Offset = <B>0</B>, Factor = <B>0.5</B>, Unit = <B>msec</B> \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_SLOPE_SENSOR_INFORMATION_2        0xF029U
#define SIZE_SLOPE_SENSOR_INFORMATION_2       8U

/* Enums **********************************************************************/
typedef enum tagSLOPE_SENSOR_INFORMATION_2_COMPENSATION
{
  SLOPE_SENSOR_INFORMATION_2_COMPENSATION_OFF   = 0x0U,
  SLOPE_SENSOR_INFORMATION_2_COMPENSATION_ON 		= 0x1U,
  SLOPE_SENSOR_INFORMATION_2_COMPENSATION_ERROR = 0x2U
} SLOPE_SENSOR_INFORMATION_2_COMPENSATION_E;

typedef enum tagSLOPE_SENSOR_INFORMATION_2_FIGURE_OF_MERIT
{
  SLOPE_SENSOR_INFORMATION_2_FIGURE_OF_MERIT_FULLY_FUNCTIONAL = 0x0U,
  SLOPE_SENSOR_INFORMATION_2_FIGURE_OF_MERIT_DEGRADED 		    = 0x1U,
  SLOPE_SENSOR_INFORMATION_2_FIGURE_OF_MERIT_ERROR 			      = 0x2U
} SLOPE_SENSOR_INFORMATION_2_FIGURE_OF_MERIT_E;

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagSLOPE_SENSOR_INFORMATION_2
{
    /* Factor = 1/32768 Range = [-250, 252], Unit = deg. */
    unsigned long PitchAngle :24;
    /* Factor = 1/32768 Range = [-250, 252], Unit = deg. */
    unsigned long RollAngle :24;
    /* 0b00 = COMPENSATION OFF */
    /* 0b01 = COMPENSATION ON  */
    /* 0b10 = ERROR            */
    /* 0b11 = N/A              */
    unsigned long PitchAngleCompensation :2;
    /* 0b00 = FULLY FUNCTIONAL */
    /* 0b01 = DEGRADED         */
    /* 0b10 = ERROR            */
    /* 0b11 = N/A              */
    unsigned long PitchAngleFigureOfMerit :2;
    /* 0b00 = COMPENSATION OFF */
    /* 0b01 = COMPENSATION ON  */
    /* 0b10 = ERROR            */
    /* 0b11 = N/A              */
    unsigned long RollAngleCompensation  :2;
    /* 0b00 = FULLY FUNCTIONAL */
    /* 0b01 = DEGRADED         */
    /* 0b10 = ERROR            */
    /* 0b11 = N/A              */
    unsigned long RollAngleFigureOfMerit   :2;
    /* Factor = 0.5 Range = [0, 125], Unit = ms. */
    unsigned long RollAndPitchMeasurementLatency :8;
} SLOPE_SENSOR_INFORMATION_2_T;

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

/* End of $Workfile: SSI2_canmsg.h$ */
