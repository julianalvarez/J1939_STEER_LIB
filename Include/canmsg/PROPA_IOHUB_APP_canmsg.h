/*******************************************************************************
** $Revision: 1$
** $Date: 03/06/2021 20:51:14 p.m.$
** $Author: Juan Imsand$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef PROPA_IOHUB_APP_CANMSG_H
#define PROPA_IOHUB_APP_CANMSG_H

/* Include ********************************************************************/
#include "types.h"


/* Defines ********************************************************************/
#define	IOHUB_APP_PAGE					(152U)

/* Enums **********************************************************************/

typedef enum tagIOHUB_APP_E /*!< List of Applications with its IDs */
{

    APP_ID_GPS_DEMO           = 1U, //App id for sbox GPS simulation
    APP_ID_OCW_CAM            = 2U, //App id for command ocuweed cameras

} IOHUB_APP_E;

typedef enum tagOCW_CAM_E /*!< List of ocuweed cameras actions. Linked with APP_ID_OCW_CAM*/
{
    ACTION_ID_RESET_CAMERAS   = 1U, //Action id for reset ocuweed cameras
} OCW_CAM_E;

/* Typedefs *******************************************************************/
/*
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif
*/

/* APP IDs PAGE 152 */
typedef struct tagIOHUB_APP_P152
{
    uint8_t             Page;                       /* Page number */
    uint8_t             App_ID;                     /* ID of application APP_ID_E */
    uint8_t             Action_ID;                  /* Action ID of own application */
    uint8_t             ShortValue;                 /* Value for specific application and action */
    uint32_t            Rvd;                        /* Reserved */
} IOHUB_APP_P152_T;


/******************************************************************************/
#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif

typedef union tagIOHUB_APP_P152_U
{
    IOHUB_APP_P152_T  IOHUB_APP_PAGE_P152;
} IOHUB_APP_P152_U;

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

/* End of $Workfile: PROPA_IOHUB_APP_canmsg.h$ */
