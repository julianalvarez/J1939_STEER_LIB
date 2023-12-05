/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:51 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef AC_CANMSG_H
#define AC_CANMSG_H

/* Include ********************************************************************/
#include "../types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_ADDRESS_CLAIM               0xEE00U
#define SIZE_ADDRESS_CLAIM              8U

/******************** ISO NAME DEFINITIONS ************************/
/* Arbitrary address */
#define ARBITRARY_ADDRESS_NOT_SUPPORTED     0
#define ARBITRARY_ADDRESS_SUPPORTED         1

/* Industry gorup */
#define INDUSTRY_GROUP_ALL                  0
#define INDUSTRY_GROUP_HIGHWAY              1
#define INDUSTRY_GROUP_AGRICULTURAL         2 // Use this
#define INDUSTRY_GROUP_CONSTRUCTION         3
#define INDUSTRY_GROUP_MARINE               4
#define INDUSTRY_GROUP_INDUSTRIAL           5
#define INDUSTRY_GROUP_RESERVED             6
#define INDUSTRY_GROUP_NA                   7

/* Vehicle instance */
#define VEHICLE_INSTANCE_NA                 0

/* Vehicle system: INDUSTRY_GROUP_AGRICULTURAL */
#define VEHICLE_SYSTEM_AGRICULTURAL_NON_SPECIFIC        0
#define VEHICLE_SYSTEM_AGRICULTURAL_TRACTOR             1
#define VEHICLE_SYSTEM_AGRICULTURAL_TILLAGE             2
#define VEHICLE_SYSTEM_AGRICULTURAL_SECONDARY_TILLAGE   3
#define VEHICLE_SYSTEM_AGRICULTURAL_PLANTERS_SEEDERS    4
#define VEHICLE_SYSTEM_AGRICULTURAL_FERTILIZERS         5
#define VEHICLE_SYSTEM_AGRICULTURAL_SPRAYERS            6
#define VEHICLE_SYSTEM_AGRICULTURAL_COMBINE_HARVESTERS  7
#define VEHICLE_SYSTEM_AGRICULTURAL_ROOT_HARVESTERS     8
#define VEHICLE_SYSTEM_AGRICULTURAL_FORAGE              9
#define VEHICLE_SYSTEM_AGRICULTURAL_IRRIGATION          10
#define VEHICLE_SYSTEM_AGRICULTURAL_TRANSPORT_TRAILER   11
#define VEHICLE_SYSTEM_AGRICULTURAL_FARM_YARD_OPERATION 12
#define VEHICLE_SYSTEM_AGRICULTURAL_AUXILIARY_DEVICES   13
#define VEHICLE_SYSTEM_AGRICULTURAL_SPECIAL_CROPS       14
#define VEHICLE_SYSTEM_AGRICULTURAL_EARTH_WORK          15

/* Function: standard from 0 to 130 */
#define FUNCTION_ENGINE                         0
#define FUNCTION_ELECTRIC_PROPULSION_CONTROL    2
#define FUNCTION_TRANSMISSION					3
#define FUNCTION_SHIFT_CONTROL                  5
#define FUNCTION_CRUISE_CONTROL                 14
#define FUNCTION_STEERING_CONTROLLER            16
#define FUNCTION_VEHICLE_NAVIGATION             23
#define FUNCTION_SYSTEM_MONITOR                 33
#define FUNCTION_PRECISION_FARMING_DISPLAY      128 // For VEHICLE_SYSTEM_AGRICULTURAL_TRACTOR only
#define FUNCTION_MAPPING_COMPUTER               130 // For VEHICLE_SYSTEM_AGRICULTURAL_TRACTOR only

/* Function: FW specific from 131 to 247 */
#define FUNCTION_SEED_DETECTOR                  200
#define FUNCTION_STEERING_ACTUATOR              201
#define FUNCTION_SIP_NETWORK_GATEWAY            202
#define FUNCTION_GENERIC_AUTOMATIC_CONTROLLER   203
#define FUNCTION_SEED_DOSING_UNIT               204
#define FUNCTION_AUXILIARY_IO                   205
#define FUNCTION_SCALE					        206
#define FUNCTION_DRIVE_TRAIN                    207
#define FUNCTION_ILLUMINATION_MODULE            208
#define FUNCTION_NAV_RECEIVER                   209
#define FUNCTION_SPOT_SPRAYING                  210
#define FUNCTION_ULTRSONIC_MODULE               211
#define FUNCTION_BATTERY_MANAGEMENT             212
#define FUNCTION_BATTERY_CHARGER                213
#define FUNCTION_IMU_MODULE                     214
#define FUNCTION_RADAR                          215
#define FUNCTION_WEATHERSTATION                 216
#define FUNCTION_SOIL_COMPACTION                217
/* Function instance */
#define FUNCTION_INSTANCE_NA            0

/* ECU instance */
#define ECU_INSTANCE_NA                 0

/* Manufacturer Code */
#define J1939_MANCODE_GENTEC                395U
#define MANUFACTURER_CODE_BOSH				50U
#define MANUFACTURER_CODE_GENTEC            J1939_MANCODE_GENTEC

/* Identity Number = SERIAL NUMBER*/

/********************* ISO NAME DEFINITIONS ***********************/

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagADDRESS_CLAIM
{
    uint32_t Identity_Number    :21;
    uint32_t Manufacturer_Code  :11;

    uint8_t  Ecu_Instance       :3;
    uint8_t  Function_Instance  :5;

    uint8_t  Function;

    uint8_t  Reserved           :1;
    uint8_t  Vehicle_System     :7;

    uint8_t  Vehicle_Instance   :4;
    uint8_t  Industry_Group     :3;
    uint8_t  Arbitrary_Address  :1;
} ADDRESS_CLAIM_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
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

/* End of $Workfile: AC_canmsg.h$ */
