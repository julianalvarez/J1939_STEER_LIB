/*******************************************************************************
** $Revision: 0$
** $Date: 18/07/2016 12:56:00 p.m.$
** $Author: Federico Baulies$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef SAGPS_CANMSG_H
#define SAGPS_CANMSG_H

/*! Smart Antenna GPS Status
 *
 */

/* Include ********************************************************************/
#include "../types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_SMARTANTENNA_GPS           	0xFFD6U
#define SIZE_SMARTANTENNA_GPS			72U

#define MAX_GPS_LENGTH          		(120U)

#define MAX_GPS_VERSION_LENGTH     		12U // Longest DEV version ever used: 5.6Aa09_6221
/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagGPS_STATUS_DATA
{
    uint16_t     originID;
    int32_t      latitude;
    int32_t      longitude;
    int32_t      height;
    uint16_t     speed;
    uint16_t     heading;
    uint8_t      typ_fixMode;           // TYP from RTKSTAT
    uint8_t      satellitesInUse;
    uint16_t     gpsSubscription;
    uint16_t     gpsLicense;
    uint16_t     age;
    int16_t      HDOP;
	uint8_t      snr_L1_L2;		        // RTKSTAT
	uint8_t      snr_G1_G2;		        // RTKSTAT
    uint8_t      roverSlipFlag;         // RTKSTAT
    uint8_t      baseSlipFlag;          // RTKSTAT
	uint8_t      ionoScint;             // RTKSTAT
    uint16_t     distanceToBase;        // RTKSTAT
    uint16_t     HAG;                   // RTKSTAT
    uint16_t     AccStat;               // RTKSTAT
    uint32_t     BER2;                  // RD1
    uint8_t      AGC_SignalStrength;    // RD1
    uint8_t      ArmStat;               // RD1
    uint32_t     NavCon;                // RD1
    uint32_t     gpsBoardSN;
    char         gpsSwVer[MAX_GPS_VERSION_LENGTH];
    uint8_t      gpsActiveBank      :2; // JAPP
    uint8_t      Rvd                :6;
    uint32_t     freqLband;             // JLBEAM
    uint16_t     baudLband;             // JLBEAM
} GPS_STATMSG_DATA;

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

/* End of $Workfile: SAGPS_canmsg.h$ */
