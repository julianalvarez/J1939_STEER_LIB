/*******************************************************************************
** $Revision: 1$
** $Date: 03/06/2021 20:51:14 p.m.$
** $Author: Juan Imsand$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef PROPA_OC_CANMSG_H
#define PROPA_OC_CANMSG_H

/* Include ********************************************************************/
#include "types.h"
#include "OC_canmsg.h"     // Enums


/* Defines ********************************************************************/
#define	OCUWEED_CONFIGURATION_PAGE					(153U)

/* Enums **********************************************************************/


/* Typedefs *******************************************************************/
/*
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif
*/

/* ocuWeed specific parameters configuration */
typedef struct tagOCUWEED_CONFIGURATION_P153
{
    uint8_t             Page;                       /* Page number */
    uint8_t             ParameterGroup;             /* Parameter group from OCUWEED_PARAM_GROUP_E */      
    uint8_t             Parameter;                  /* Parameter */
    uint8_t             ParameterIndex;             /* Parameter index value */
    uint16_t            ParameterValue;             /* Parameter value 1 */
    uint8_t             Rvd1;                       /* Reserved */
    uint8_t             Rvd2;                       /* Reserved */
} OCUWEED_CONFIGURATION_P153_T;


/******************************************************************************/
#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

typedef union tagOCUWEED_CONFIGURATION_P153_U
{
    OCUWEED_CONFIGURATION_P153_T                    OCUWEED_PAGE_P153;
} OCUWEED_CONFIGURATION_P153_U;

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

/* End of $Workfile: PROPA_OC_canmsg.h$ */
