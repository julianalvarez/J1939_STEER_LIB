/*******************************************************************************
** $Revision: 3$
** $Date: 14/10/2010 04:40:51 p.m.$
** $Author: Admin Ariel Moreno$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef PROPA_CANMSG_H
#define PROPA_CANMSG_H

/* Include ********************************************************************/
#include "types.h"
#include "SSC_canmsg.h"
#include "PVED_canmsg.h"
#include "IOC_canmsg.h"
#include "MC_canmsg.h"
#include "PROPA_IMU_canmsg.h"
#include "PROPA_HOOK_command_canmsg.h"
#include "PROPA_HOOK_weight_canmsg.h"
#include "PROPA_RF_canmsg.h"
#include "PROPA_LIGHT_canmsg.h"
#include "PROPA_ULTRASONIC_canmsg.h"
#include "PROPA_IOHUB_APP_canmsg.h"
#include "PROPA_CRD_canmsg.h"
#include "PROPA_OC_canmsg.h"
#include "ASC_canmsg.h"
#include "WSC_canmsg.h"
#include "GIOCC_canmsg.h"
#include "AFC_canmsg.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_PROPRIETARY_A                   0xEF00U
#define SIZE_PROPRIETARY_A                  8U

/* Propietary Commamds: */
#define LIGHTS_COMMANDS_PAGE                (127U)

/* Lights Function IDs Ranges: */
#define LIGTHS_NONSPEC_ID_START                (0U)
#define LIGTHS_TRACTOR_ID_START                (1000U)
#define LIGTHS_TILLAGE_ID_START                (2000U)
#define LIGTHS_SECONDARY_TILLAGE_ID_START      (3000U)
#define LIGTHS_PLANTERS_SEEDERS_ID_START       (4000U)
#define LIGTHS_FERTILIZERS_ID_START            (5000U)
#define LIGTHS_SPRAYERS_ID_START               (6000U)
#define LIGTHS_COMBINE_HARVESTERS_ID_START     (7000U)
#define LIGTHS_ROOT_HARVESTERS_ID_START        (8000U)
#define LIGTHS_FORAGE_ID_START                 (9000U)
#define LIGTHS_IRRIGATION_ID_START             (10000U)

/* Lights Function ID definitions: */
/* Non Spec */
#define AUTOGUIDE_LED                           (100U)
#define POWER_5V_SENSORS                        (200U)
/* Sprayers */
#define SPRAYER_MASTER_SWITCH_LED               (6000U)


/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif



/* Proprietary Commands */


/* Pages 0-10 are defined in SSC_canmsg.h*/



typedef struct tagPROPRIETARY_A_P127
{
    uint8_t            	Page;
	uint8_t 			Rvd;
    uint16_t            FunctionId;
    uint8_t             Bright;           /*! < [units %]...[offset 0]...[factor 0,4] >*/
    uint16_t            BlinkFrequency;   /*! < [units hz]...[offset 0]...[factor 1/128] >*/
    uint8_t             Rvd1;
} PROPIETARY_A_P127_T;


typedef union tagPROPRIETARY_A   /* Deprecated */
{
    PROPIETARY_A_P127_T   P127;
} PROPIETARY_A_T; 

typedef union tagPROPRIETARY_A_U
{
    SEED_SENSOR_CONF_P0_T               P0;
    SEED_SENSOR_CONF_P1_T               P1;
    SEED_SENSOR_CONF_P2_T               P2;
    SEED_SENSOR_CONF_P3_T               P3;
    SEED_SENSOR_CONF_P4_T               P4;
    SEED_SENSOR_CONF_P5_T               P5;
    SEED_SENSOR_CONF_P6_T               P6;
    SEED_SENSOR_CONF_P7_T               P7;
    
    PIN_CONFIG_P16_T                    P16;
    PIN_CONFIG_P17_T                    P17;
    PROPIETARY_A_P127_T                 P127;
    MOTOR_CONFIG_P128_T                 P128;
    MOTOR_CONFIG_P129_T                 P129;
    MOTOR_CONFIG_P130_T                 P130;
    MOTOR_CONFIG_P131_T                 P131;
    MOTOR_CONFIG_P132_T                 P132;
    MOTOR_CONFIG_P133_T                 P133;
	MOTOR_CONFIG_P135_T					P135;
	MOTOR_CONFIG_P136_T					P136;
	MOTOR_CONFIG_P137_T					P137;
	MOTOR_CONFIG_P138_T					P138;
    MOTOR_CONFIG_P139_T					P139;
	IMU_MSG_P140_U                     	P140;
    LIGHT_MSG_P145_U                    P145;
	/* Proprietary Danfoss PVED-CL Pages */
    PVED_MSG_T                          PVED_MSG;
    PVED_MSG_GET_PARAMETER_T            PVED_MSG_GET_PARAMETER;
    PVED_MSG_GET_PARAMETER_RESPONSE_T   PVED_MSG_GET_PARAMETER_RESPONSE;
    PVED_MSG_SET_PARAMETER_T            PVED_MSG_SET_PARAMETER;
    PVED_MSG_SET_PARAMETER_RESPONSE_T   PVED_MSG_SET_PARAMETER_RESPONSE;
    PVED_MSG_START_STOP_STATUS_T        PVED_MSG_START_STOP_STATUS;
    HOOK_MSG_COMMAND_T                  HOOK_COMMAND;
    HOOK_MSG_WEIGHT_T                   HOOK_WEIGHT;
    RF_MSG_P150_U                     	P150;
    ULTRASONIC_MSG_P151_U               P151;
    IOHUB_APP_P152_U                    P152;
    OCUWEED_CONFIGURATION_P153_U        P153;
    CRD_MSG_P180_U                      P180;
    
    ACTIVE_SINGULATION_CONFIG_P181_T      P181;
    ACTIVE_SINGULATION_CONFIG_P182_T      P182;
    ACTIVE_SINGULATION_CONFIG_P183_T      P183;
	
	WEATHERSTATION_CONFIG_P184_T        P184;
	WEATHERSTATION_CONFIG_P185_T        P185;
//	WEATHERSTATION_CONFIG_P186_T        P186;
	
	GIOC_COMMAND_CONF_P187_T	        P187;
	GIOC_CONFIG_P188_T			        P188;
    GIOC_SEQUENCE_CONFIG_P189_T			P189;
    
    ACTIVE_FORCE_CONFIG_P190_T          P190;
    ACTIVE_FORCE_CONFIG_P191_T          P191;
	
} PROPRIETARY_A_U;


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

/* End of $Workfile: PROPA_canmsg.h$ */
