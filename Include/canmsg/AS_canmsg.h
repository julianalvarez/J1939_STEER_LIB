/*******************************************************************************
** $Revision: 6$
** $Date: 04/11/2013 02:49:03 p.m.$
** $Author: Bernab� Scarso$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef AS_CANMSG_H
#define AS_CANMSG_H

/*! \page AS Analog Status
 *  \section sec8 Analog Input:
 *      Offset = <B>0</B>, Factor = <B>.05</B>, Unit = <B>V/bit</B> \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_ANALOG_STATUS                   0xFF70U
#define SIZE_ANALOG_STATUS                  8U

/*******************************************************************************
 NON-SPECIFIC
********************************************************************************/
/* PAGE 0 */
#define FIELD_ENGINE_COOLANT_TEMP_AS        Analog1Status /*!< NON-SPEC Page 0 */
#define FIELD_ENGINE_OIL_TEMP_AS  	        Analog2Status /*!< NON-SPEC Page 0 */
#define FIELD_ENGINE_OIL_PRESSURE_AS 	      Analog3Status /*!< NON-SPEC Page 0 */
/* PAGE 1 */
#define FIELD_FUEL_LEVEL_AS   	            Analog1Status /*!< NON-SPEC Page 1 */
#define FIELD_ENGINE_COOLANT_LEVEL_AS       Analog2Status /*!< NON-SPEC Page 1 */
#define FIELD_HYDRAULIC_OIL_TEMP_AS	        Analog3Status /*!< NON-SPEC Page 1 */
/* PAGE 2 */
#define FIELD_ENGINE_RPM_ACCELERATOR_AS     Analog1Status /*!< NON-SPEC Page 2 */
#define FIELD_JOYSTICK_A_AS		              Analog3Status /*!< NON-SPEC Page 2 */
/* PAGE 3 */
#define FIELD_FRONTAL_AXLE_LEFT_HEIGHT_AS   Analog1Status /*!< NON-SPEC Page 3 */
#define FIELD_FRONTAL_AXLE_RIGHT_HEIGHT_AS  Analog2Status /*!< NON-SPEC Page 3 */

/*******************************************************************************
COMBINE-HARVESTER
********************************************************************************/
/* PAGE 0 */
#define FIELD_HP_RIGHT_AS                   Analog1Status /*!< COMBINE Page 0 */
#define FIELD_HP_LEFT_AS                    Analog2Status /*!< COMBINE Page 0 */
#define FIELD_HP_TILT_AS                    Analog3Status /*!< COMBINE Page 0 */
/* PAGE 1 */
#define FIELD_HP_FEEDER_AS                  Analog1Status /*!< COMBINE Page 1 */
/* PAGE 2 */
#define FIELD_FAN_AIR_FLOW_AS               Analog1Status /*!< COMBINE Page 2 */
#define FIELD_CONCAVE_CLREARANCE_AS         Analog2Status /*!< COMBINE Page 2 */
#define FIELD_BASECUTTER_PRESSURE_AS        Analog3Status /*!< COMBINE Page 2 */
/* PAGE 3 */
#define FIELD_GRAIN_FLOW_AS                 Analog1Status /*!< COMBINE Page 3 */
#define FIELD_GRAIN_TEMP_AS                 Analog2Status /*!< COMBINE Page 3 */
#define FIELD_GRAIN_MOISTURE_AS             Analog3Status /*!< COMBINE Page 3 */
/* PAGE 4 */
#define FIELD_CHOPPER_SPEED_AS              Analog1Status /*!< COMBINE Page 4 */
#define FIELD_PRIMARY_EXTRACTOR_SPEED_AS    Analog2Status /*!< COMBINE Page 4 */
/* PAGE 5 */
#define FIELD_GRAIN_POSITIVE_MOISTURE_AS    Analog1Status /*!< COMBINE Page 5 */
#define FIELD_GRAIN_NEGATIVE_MOISTURE_AS    Analog2Status /*!< COMBINE Page 5 */
/* PAGE 6 */
#define FIELD_HEADER_DRIVE_ENGAGE_AS        Analog1Status /*!< COMBINE Page 6 */
#define FIELD_CYLINDER_DRIVE_ENGAGE_AS      Analog2Status /*!< COMBINE Page 6 */
#define FIELD_AUGER_DRIVE_ENGAGE_AS         Analog3Status /*!< COMBINE Page 6 */

/*******************************************************************************
 PLANT-SEEDER
********************************************************************************/
/* PAGE 0 */
#define FIELD_POWER_LINE_SENSOR_1_AS	      Analog1Status /*!< PLANTER Page 0 */
#define FIELD_POWER_LINE_SENSOR_2_AS	      Analog2Status /*!< PLANTER Page 0 */
#define FIELD_POWER_LINE_SENSOR_3_AS	      Analog3Status /*!< PLANTER Page 0 */

/*******************************************************************************
 SPRAYER
********************************************************************************/
/* PAGE 0 */
#define FIELD_SPRAYER_BOOM_PRESSURE_AS	        Analog1Status /*!< SPRAYER Page 0 */
#define FIELD_SPRAYER_PUMP_ACTIVATION_LEVEL_AS  Analog2Status /*!< SPRAYER Page 0 */

/* PAGE 1 */
#define FIELD_SPRAYER_BOOM_LEFT_ANGLE_AS    Analog1Status /*!< SPRAYER Page 1 */
#define FIELD_SPRAYER_BOOM_RIGHT_ANGLE_AS   Analog2Status /*!< SPRAYER Page 1 */
#define FIELD_SPRAYER_BOOM_HEIGHT_AS	      Analog3Status /*!< SPRAYER Page 1 */

/*******************************************************************************
 MODULE-SPECIFIC
********************************************************************************/
/* PAGE 100 */
#define FIELD_IMU_GYR_PITCH_RATE_TEMPERATURE_AS   Analog1Status   /*!< MODULE-SPEC Page 100 */
#define FIELD_IMU_GYR_ROLL_RATE_TEMPERATURE_AS    Analog2Status   /*!< MODULE-SPEC Page 100 */
#define FIELD_IMU_GYR_YAW_RATE_TEMPERATURE_AS     Analog3Status   /*!< MODULE-SPEC Page 100 */
/* PAGE 101 */
#define FIELD_IMU_ACC_LATERAL_TEMPERATURE_AS      Analog1Status   /*!< MODULE-SPEC Page 101 */
#define FIELD_IMU_ACC_LONGITUDINAL_TEMPERATURE_AS Analog2Status   /*!< MODULE-SPEC Page 101 */
#define FIELD_IMU_ACC_VERTICAL_TEMPERATURE_AS     Analog3Status   /*!< MODULE-SPEC Page 101 */

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagANALOG_STATUS
{
  uint8_t  Page;
  uint8_t  Rvd;
  uint16_t Analog1Status;
  uint16_t Analog2Status;
  uint16_t Analog3Status;
} ANALOG_STATUS_T;

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

/* End of $Workfile: AS_canmsg.h$ */
