/*******************************************************************************
** $Revision: 0$
** $Date: 18/07/2016 12:56:00 p.m.$
** $Author: Federico Baulies$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef SAGSM_CANMSG_H
#define SAGSM_CANMSG_H

/*! Smart Antenna General Status Message
 *
 */

/* Include ********************************************************************/
#include "../types.h"

/* Enums **********************************************************************/
typedef enum tagGPS_LICENSE_STATE
{
 	LICENSE_STATE_OK 				= 0,
 	LICENSE_STATE_       			= 1
} GPS_LICENSE_STATE_E;


/* Defines ********************************************************************/
#define PGN_SMARTANTENNA_GSM           	0xFFD5U
#define SIZE_SMARTANTENNA_GSM          	15U

#define MAX_GSM_LENGTH          		(120U)
/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagGSM_STATUS_DATA
{
    uint16_t     originID;
    uint8_t      battery;
    int8_t       temperature;
    int8_t       rssi;
    uint16_t     crcErrors;
    uint16_t     msgsLostGlobal;
    uint16_t     msgsNotRegistered;
    uint32_t     majorSwVersion             :4;
    uint32_t     minorSwVersion             :4;
    uint32_t     fixSwVersion               :4;
    uint32_t     buildSwVersion             :8;
    uint32_t     gpsAntennaSC               :1;
    uint32_t     gpsAntennaConnected        :1;
    uint32_t     gpsLicenseState            :2;
    uint32_t     broadcaster                :1;
    uint32_t     autoconfigState            :3;
    uint32_t     autoconfigEnabled          :1;
    uint32_t     h10Enabled                 :1;
    uint32_t     gpsBoardPresent            :1;
	uint32_t     gpsThroughCAN              :1;
} GSM_STATUS_DATA;

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

/* End of $Workfile: SAGSM_canmsg.h$ */
