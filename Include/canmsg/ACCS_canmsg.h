/*******************************************************************************
** $Revision: 1$
** $Date: 16/05/2018 01:06:50 p.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef ACCS_CANMSG_H 
#define ACCS_CANMSG_H

/*! \page ACCS Acceleration Sensor
 *  \n
 *  \section se50 Lateral Acceleration Extended Range:
 *      Offset = <B>-320</B>, Factor = <B>0.01</B>, Unit = <B>m/s^2</B> \n  
 *  \section se51 Longitudinal Acceleration Extended Range:
 *      Offset = <B>-320</B>, Factor = <B>0.01</B>, Unit = <B>m/s^2</B> \n  
 *  \section se52 Vertical Acceleration Extended Range:
 *      Offset = <B>-320</B>, Factor = <B>0.01</B>, Unit = <B>m/s^2</B> \n  
 *  \section se53 Lateral Acceleration Extended Range Figure of Merit:
 *      0b00 = <B>Lateral Acceleration is fully functional. Data is within sensor specification</B>         \n 
 *      0b01 = <B>Lateral Acceleration is degraded. Data is suspect due to environmental conditions</B>         \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section se54 Longitudinal Acceleration Extended Range Figure of Merit:
 *      0b00 = <B>Longitudinal Acceleration is fully functional. Data is within sensor specification</B>         \n 
 *      0b01 = <B>Longitudinal Acceleration is degraded. Data is suspect due to environmental conditions</B>         \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section se55 Vertical Acceleration Extended Range Figure of Merit:
 *      0b00 = <B>Vertical Acceleration is fully functional. Data is within sensor specification</B>         \n 
 *      0b01 = <B>Vertical Acceleration is degraded. Data is suspect due to environmental conditions</B>         \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>N/A</B>      \n
 *  \section se56 Support Variable Transmission Repetition Rate for Acceleration Sensor:
 *      0b00 = <B>?</B>       \n 
 *      0b01 = <B>?</B>        \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>N/A</B>      \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tagACCELERATION_SENSOR_FIGURE_OF_MERIT
{
  ACCELERATION_SENSOR_FIGURE_OF_MERIT_FULLY_FUNCTIONAL 		= 0x0U,
  ACCELERATION_SENSOR_FIGURE_OF_MERIT_DEGRADED 				= 0x1U,
  ACCELERATION_SENSOR_FIGURE_OF_MERIT_ERROR 				= 0x2U
} ACCELERATION_SENSOR_FIGURE_OF_MERIT_E;

/* Defines ********************************************************************/
#define PGN_ACCELERATION_SENSOR        0xF02DU
#define SIZE_ACCELERATION_SENSOR       8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagACCELERATION_SENSOR
{
    /* Factor = 0.01 Range = [-320, 322.5], Unit = m/s^2. */
    uint16_t     LateralAccelerationExtendedRange;
    /* Factor = 0.01 Range = [-320, 322.5], Unit = m/s^2. */
    uint16_t     LongitudinalAccelerationExtendedRange;
    /* Factor = 0.01 Range = [-320, 322.5], Unit = m/s^2. */
    uint16_t     VerticalAccelerationExtendedRange;
	/* Value from ACCELERATION_SENSOR_FIGURE_OF_MERIT_E */
    unsigned int LateralAccelerationExtendedRangeFigureOfMerit :2;
	/* Value from ACCELERATION_SENSOR_FIGURE_OF_MERIT_E */
    unsigned int LongitudinalAccelerationExtendedRangeFigureOfMerit  :2;
	/* Value from ACCELERATION_SENSOR_FIGURE_OF_MERIT_E */
    unsigned int VerticalAccelerationExtendedRangeFigureOfMerit   :2;
	/* Value from ACCELERATION_SENSOR_FIGURE_OF_MERIT_E */
    unsigned int SupportVariableTransmissionRepetitionRate :2;
    /* Not defined. Set to 0xFF. */
    uint8_t      Rvd1;
} ACCELERATION_SENSOR_T;

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
