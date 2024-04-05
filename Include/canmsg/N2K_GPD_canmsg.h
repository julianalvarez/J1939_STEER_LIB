#ifndef N2K_GPD_CANMSG_H
#define N2K_GPD_CANMSG_H

/*! \page N2KGPD NMEA2000 GPS Position Data
 * GNSSPositionData \n
 *                  \n
 *  \section s5 SID:
 * An upward counting number used to tie related information together between different PGNs.For example,SID would be used to tie together COG,SOG \n
 * and RAIM values to a given Pos \n
 *      Offset = <B>0</B>, Factor = <B>1</B>, Unit = \n
 *  \section s6 PosDate:
 *   Days since January 1, 1970,   Date is relative to UTC Time. \n
 *      Offset = <B>0</B>, Factor = <B>1</B>, Unit = <B>day/bit</B> \n 
 *  \section s7 PosTime:
 *   24 hour clock, 0 =  midnight,  time is in UTC. \n
 *      Offset = <B>0</B>, Factor = <B>0.0001</B>, Unit = <B>sec/bit</B> \n 
 *  \section s8 LatitudeLow:
 *   Latitude referenced to WGS-84. \n
 *      Offset = <B>0</B>, Factor = <B>1e-016</B>, Unit = <B>deg/bit</B> \n 
 *  \section s9 LatitudeHigh:
 *   Latitude referenced to WGS-84. \n
 *      Offset = <B>-90</B>, Factor = <B>4.29497e-007</B>, Unit = <B>deg/bit</B> \n 
 *  \section s10 LongitudeLow:
 *   Longitude referenced to WGS-84. \n
 *      Offset = <B>0</B>, Factor = <B>1e-016</B>, Unit = <B>deg/bit</B> \n 
 *  \section s11 LongitudeHigh:
 *   Longitude referenced to WGS-84. \n
 *      Offset = <B>-180</B>, Factor = <B>4.29497e-007</B>, Unit = <B>deg/bit</B> \n 
 *  \section s12 AltitudeLow:
 *   Altitude referenced to WGS-84. \n
 *      Offset = <B>0</B>, Factor = <B>1e-006</B>, Unit = <B>m/bit</B> \n 
 *  \section s13 AltitudeHigh:
 *   Altitude referenced to WGS-84. \n
 *      Offset = <B>-9223000000000</B>, Factor = <B>4294.967295</B>, Unit = <B>m/bit</B> \n 
 *  \section s14 TypeOfSystem:
 *      0x00 = <B>GPS</B> \n
 *      0x01 = <B>GLONASS</B>\n
 *      0x02 = <B>GPS+GLONASS</B> \n 
 *      0x03 = <B>GPS+SBAS(WAAS)</B> \n 
 *      0x04 = <B>GPS+SBAS+GLONASS</B> \n
 *      0x05 - 0x0D = <B>Reserved for future combinations</B> \n
 *  \section s15 GNSSMethod:
 *      0x00 = <B>no GPS</B> \n
 *      0x01 = <B>GNSS fix</B> \n
 *      0x02 = <B>DGNSS fix</B> \n
 *      0x03 = <B>Precise GNSS*</B> \n
 *      0x04 = <B>RTK Fixed Integer</B> \n
 *      0x05 = <B>RTK Float</B> \n
 *      0x06 = <B>Est(DR)mode</B> \n
 *      0x07 = <B>Manual Input</B> \n
 *      0x08 = <B>Simulate mode</B> \n
 *      0x09 - 0x0D = <B>Reserved for future combinations</B> \n
 *      <B>*Precise GNSS means no deliberate degradation</B>\n
 *  \section s16 GNSSIntegrity:
 *      0x00 = <B>No Integrity checking*</B> \n
 *      0x01 = <B>Safe</B> \n
 *      0x02 = <B>Caution</B> \n
 *      0x03 = <B>Unsafe</B> \n
 *      <B>*means the receiver does not have this capability</B>\n
 *   \section s17 NumberOfSVs:
 *      Offset = <B>0</B>, Factor = <B>1</B>, Unit = \n
 *   \section s18 HDOP:
 *      Dilution of Precision(DOP)indicates contribution of satellite Config geometry to Posing error.\n
 *      A lower DOP value is preferred because less error is being introduced. \n
 *      Reported as components:HDOP(Horizontal),VDOP(Vertical),TDOP(Time). Min DOP value is 1.0 \n
 *      Offset = <B>-327.64</B>, Factor = <B>0.01</B>, Unit = \n
 *   \section s19 PDOP:
 *      Dilution of Precision(DOP)indicates contribution of satellite Config geometry to Posing error.\n
 *      A lower DOP value is preferred because less error is being introduced. \n
 *      Reported as components:HDOP(Horizontal),VDOP(Vertical),TDOP(Time). Min DOP value is 1.0 \n
 *      Offset = <B>-327.64</B>, Factor = <B>0.01</B>, Unit = \n
 *   \section s20 GeoidalSeparation: 
 *      The difference between the earth ellipsoid and mean-sea-level (geoid) defined by the reference datum used in the position solution, \n
 *      '-' = mean-sea-level below ellipsoid.Reference datum is defined in this packet. \n
 *      Offset = <B>-21470000</B>, Factor = <B>0.01</B>, Unit = m/bit\n
 *   \section s21 NumberOfReferenceStations:
 *      Offset = <B>0</B>, Factor = <B>1</B>, Unit = \n
 *   \section s22 ReferenceStationType1:
 *      0x00 = <B>GPS</B>\n 
 *      0x01 = <B>GLONASS</B>\n 
 *      0x03 - 0x0D = <B>Reserved</B>\n 
 *   \section s23 ReferenceStationID1: 
 *      Reference Station number as provided by the Service Provider.[Reference document required] \n
 *      Offset = <B>0</B>, Factor = <B>1</B>, Unit = \n
 *   \section s24 AgeOfDGNSSCorrections1:
 *      Offset = <B>0</B>, Factor = <B>0.01</B>, Unit = <B>sec/bit</B>\n
 *   \section s25 ReferenceStationTypeN:
 *      0x00 = <B>GPS</B>\n 
 *      0x01 = <B>GLONASS</B>\n 
 *      0x03 - 0x0D = <B>Reserved</B>\n 
 *   \section s26 ReferenceStationIDN: 
 *      Reference Station number as provided by the Service Provider.[Reference document required] \n
 *      Offset = <B>0</B>, Factor = <B>1</B>, Unit = \n
 *   \section s27 AgeOfDGNSSCorrectionsN:
 *      Offset = <B>0</B>, Factor = <B>0.01</B>, Unit = <B>sec/bit</B>\n
 *
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tagTYPE_OF_SYSTEM
{
 	GPS 				= 0,
 	GLONASS 			= 1,
 	GPS_GLONASS 		= 2, 
 	GPS_SBAS 			= 3, 
 	GPS_SBAS_GLONASS 	= 4 
} TYPE_OF_SYSTEM_E;

typedef enum tagGNSS_METHOD
{
	NO_GPS 				= 0,
	GNSS_FIX 			= 1,
 	DGNSS_FIX 			= 2,				  
 	PRECISE_GNSS 		= 3,
 	RTK_FIXED_INTEGER 	= 4,		   
	RTK_FLOAT 			= 5,
 	DR_MODE 			= 6,
 	MANUAL_INPUT 		= 7,
 	SIMULATE_MODE 		= 8
} GNSS_METHOD_E;

typedef enum tagGNSS_INTEGRITY
{
 	NO_INTEGRITY_CHECKING 	= 0,
 	SAFE 					= 1,
 	CAUTION 				= 2, 
 	UNSAFE 					= 3
} GNSS_INTEGRITY_E;
	   


/* Defines ********************************************************************/
#define PGN_N2K_GPS_POSITION_DATA           0x1F805U
#define SIZE_N2K_GPS_POSITION_DATA          51U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagN2K_GPS_POSITION_DATA
{
    uint8_t      SID;
    uint16_t     PosDate;
    uint32_t     PosTime;
    uint32_t     LatitudeLow;
    int32_t      LatitudeHigh;
    uint32_t     LongitudeLow;
    int32_t      LongitudeHigh;
    uint32_t     AltitudeLow;
    int32_t      AltitudeHigh;
    unsigned int TypeOfSystem               :4;
    unsigned int GNSSMethod                 :4;
    unsigned int GNSSIntegrity              :2;
    unsigned int Rvd                        :6;
    uint8_t      NumberOfSVs;
    int16_t      HDOP;
    int16_t      PDOP;
    int32_t      GeoidalSeparation;
    uint8_t      NumberOfReferenceStations;
    unsigned int ReferenceStationType1      :4;
    unsigned int ReferenceStationID1        :12;
    uint16_t     AgeOfDGNSSCorrections1;
    unsigned int ReferenceStationTypeN      :4;
    unsigned int ReferenceStationIDN        :12;
    uint16_t     AgeOfDGNSSCorrectionsN;
} N2K_GPS_POSITION_DATA_T;

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

/* End of $Workfile: N2K_GPD_canmsg.h$ */
