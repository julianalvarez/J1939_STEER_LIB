/*******************************************************************************
** $Revision: $
** $Date: 15/11/2021 $
** $Author: Juan Imsand$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef OC_CANMSG_H
#define OC_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tagOCUWEED_PARAM_GROUP_E /*!< List of ocuweed specific parameters to config */
{

    COMMAND_GROUP                       = 0U,       /* Parameter from COMMAND_PARAM_E */
    MEASUREMENT_GROUP,                              /* Parameter from MEASUREMENT_PARAM_E */
    SPRAYING_GROUP,                                 /* Parameter from SPRAYING_PARAM_E */
    OCUWEED_GROUP,                                  /* Parameter from OCUWEED_PARAM_E */

} OCUWEED_PARAM_GROUP_E;

typedef enum tagCOMMAND_PARAM_E /*!< List of ocuweed specific parameters to config */
{

    START_CONFIG_PROCESS                = 0U,       /* Parameter: offset=0, scale=1; ParameterLongValue: ecuVision serial no */
    FINISH_CONFIG_PROCESS,                          /* Parameter: offset=0, scale=1; ParameterLongValue: ecuVision serial no */
    CALIBRATE_CAMERA,                               /* Parameter: offset=0, scale=1; ParameterLongValue: camera index */
    STATUS_CONFIG_PROCESS,                          /* Parameter: offset=0, scale=1; ParameterLongValue: ecuVision serial no; ParameterShortValue: from STATUS_CONFIG_E */

} COMMAND_PARAM_E;

typedef enum tagMEASUREMENT_PARAM_E /*!< List of ocuweed specific parameters to config */
{

    BOOM_TO_IMPLEMENT                   = 0U,       /* ParameterIndex: from 0 to #BOOM_MODULES_QUANTITY-1; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    BOOM_FLOOR,                                     /* non ParameterIndex; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    BOOM_MODULES_REAR_AXLE,                         /* ParameterIndex: from 0 to #BOOM_MODULES_QUANTITY-1; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    BOOM_MODULES_WIDTH,                             /* ParameterIndex: from 0 to #BOOM_MODULES_QUANTITY-1; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    CAMERA_MODULES_REAR_AXLE,                       /* ParameterIndex: from 0 to #CAMERAS_MODULES_QUANTITY-1; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    CAMERA_MODULES_OFFSET,                          /* ParameterIndex: from 0 to #CAMERAS_MODULES_QUANTITY-1; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    CAMERA_MODULES_FLOOR,                           /* ParameterIndex: from 0 to #CAMERAS_MODULES_QUANTITY-1; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    GPS_ANTENNA_TO_IMPLEMENT,                       /* non ParameterIndex; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    GPS_ANTENNA_FLOOR,                              /* non ParameterIndex; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    GPS_ANTENNA_OFFSET,                             /* non ParameterIndex; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    AXES_DISTANCE,                                  /* non ParameterIndex; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    GPS_ANTENNA_REAR_AXLE,                          /* non ParameterIndex; ParameterLongValue: offset=65500, scale=1000 1bit/mm */
    BOOM_WIDTH_GLOBAL,                              /* non ParameterIndex; ParameterLongValue: offset=65500, scale=1000 1bit/mm */

} MEASUREMENT_PARAM_E;

typedef enum tagSPRAYING_PARAM_E /*!< List of ocuweed specific parameters to config */
{

    BOOM_MODULES_QUANTITY               = 0U,       /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/boom */
    OPEN_VALVES_DELAY_HW,                           /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/ms */
    CLOSE_VALVES_DELAY_HW,                          /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/ms */
    OPEN_VALVES_DELAY_SW,                           /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/ms */
    CLOSE_VALVES_DELAY_SW,                          /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/ms */
    NOZZLES_QUANTITY,                               /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/nozzle */
    NOZZLES_PER_BOOM,                               /* ParameterIndex: from 0 to #BOOM_MODULES_QUANTITY-1; ParameterLongValue: offset=0, scale=1 1bit/nozzle */
    NOZZLES_TYPE,                                   /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 */
    VALVE_GAC_LINE,                                 /* ParameterIndex: from 0 to #NOZZLES_QUANTITY-1; ParameterLongValue: offset=0, scale=1 1bit/line */
    VALVE_GAC_SECTION,                              /* ParameterIndex: from 0 to #NOZZLES_QUANTITY-1; ParameterLongValue: offset=0, scale=1 1bit/section */
    VALVE_GAC_ADDRESS,                              /* ParameterIndex: from 0 to #NOZZLES_QUANTITY-1; ParameterLongValue: offset=0, scale=1 1bit/address */

} SPRAYING_PARAM_E;

typedef enum tagOCUWEED_PARAM_E /*!< List of ocuweed specific parameters to config */
{

    CAMERAS_MODULES_QUANTITY_GLOBAL   = 0U,         /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/camera */
    CAMERAS_MODULES_QUANTITY_SPECIFIC,              /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 (PROPA) 1bit/camera */ /* This message is send under FFC1, ParameterIndex = value; ParameterLongValue = serialNo */
    CAMERA_ECUVISION_OWNER,                         /* ParameterIndex: from 0 to #CAMERAS_MODULES_QUANTITY_GLOBAL-1; ParameterLongValue: offset=0, scale=1 1bit/camera */
    CAMERA_CONNECTOR_NUMBER,                        /* ParameterIndex: from 0 to #CAMERAS_MODULES_QUANTITY_GLOBAL-1; ParameterLongValue: offset=0, scale=1 1bit/conn */
    NOZZLES_QUANTITY_SPECIFIC,                      /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 (PROPA) 1bit/nozzle */ /* This message is send under FFC1, ParameterIndex = value; ParameterLongValue = serialNo */
    NOZZLE_ECUVISION_OWNER,                         /* ParameterIndex: from 0 to #NOZZLES_QUANTITY-1; ParameterLongValue: offset=0, scale=1 1bit/global position */
    VERTICAL_OVERLAP_STRIP_TO_CELL,                 /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/mm */
    HORIZONTAL_OVERLAP_STRIP_TO_CELL,               /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/mm */
    TOP_CELL_MARGIN,                                /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/mm */
    BOTTOM_CELL_MARGIN,                             /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 1bit/mm */
    TACTIC,                                         /* non ParameterIndex; ParameterLongValue: offset=0, scale=1 */

} OCUWEED_PARAM_E;

typedef enum tagSTATUS_CONFIG_E /*!< List of ocuweed commands */
{

    SUCCESS_STATUS                  = 0,
    FAIL_STATUS,

} STATUS_CONFIG_E;


/* Defines ********************************************************************/
#define PGN_OCUWEED_CONFIGURATION           0xFFC1U
#define SIZE_OCUWEED                        8U

/* Typedefs *******************************************************************/
/*
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif
*/


/* ocuWeed command parameters configuration */
typedef struct tagOCUWEED_COMMAND_CONFIGURATION_T
{
    uint8_t             ParameterGroup;             /* Parameter group from OCUWEED_PARAM_GROUP_E */      
    uint8_t             Parameter;                  /* Parameter */
    uint32_t            ParameterLongValue;         /* ecuVision serial number */
    uint8_t             ParameterShortValue;        /* Parameter short value */      
    uint8_t             Reserved;                   /* Reserved */
} OCUWEED_COMMAND_CONFIGURATION_T;

/* ocuWeed measurement parameters configuration */
typedef struct tagOCUWEED_MEASUREMENT_CONFIGURATION_T
{
    uint8_t             ParameterGroup;             /* Parameter group from OCUWEED_PARAM_GROUP_E */
    uint8_t             Parameter;                  /* Parameter */
    uint8_t             ParameterIndex;             /* Parameter index value */
    uint32_t            ParameterLongValue;         /* Parameter long value */
    uint8_t             Reserved;                   /* Reserved */
} OCUWEED_MEASUREMENT_CONFIGURATION_T;

/* ocuWeed spraying parameters configuration */
typedef struct tagOCUWEED_SPRAYING_CONFIGURATION_T
{
    uint8_t             ParameterGroup;             /* Parameter group from OCUWEED_PARAM_GROUP_E */      
    uint8_t             Parameter;                  /* Parameter */
    uint8_t             ParameterIndex;             /* Parameter index value */
    uint32_t            ParameterLongValue;         /* Parameter long value */
    uint8_t             Reserved;                   /* Reserved */
} OCUWEED_SPRAYING_CONFIGURATION_T;

/* ocuWeed specific parameters configuration */
typedef struct tagOCUWEED_SPECIFIC_CONFIGURATION_T
{
    uint8_t             ParameterGroup;             /* Parameter group from OCUWEED_PARAM_GROUP_E */      
    uint8_t             Parameter;                  /* Parameter */
    uint8_t             ParameterIndex;             /* Parameter index value */
    uint32_t            ParameterLongValue;         /* Parameter long value */
    uint8_t             Reserved;                   /* Reserved */
} OCUWEED_SPECIFIC_CONFIGURATION_T;


/******************************************************************************/
#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

typedef union tagOCUWEED_CONFIGURATION
{

    OCUWEED_COMMAND_CONFIGURATION_T                 COMMAND;
    OCUWEED_MEASUREMENT_CONFIGURATION_T             MEASUREMENT;
    OCUWEED_SPRAYING_CONFIGURATION_T                SPRAYING;
    OCUWEED_SPECIFIC_CONFIGURATION_T                SPECIFIC;

} OCUWEED_CONFIGURATION_U;

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

/* End of $Workfile: OC_canmsg.h$ */
