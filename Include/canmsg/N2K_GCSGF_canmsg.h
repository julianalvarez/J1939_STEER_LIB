#ifndef N2K_GCSGF_CANMSG_H
#define N2K_GCSGF_CANMSG_H

/*! \page N2KGCSGF NMEA2000 GPS Cource Speed Ground Fast
 *  COGSOGRapidUpdate \n
 *                    \n
 *  This PGN is a single frame PGN that provides Course Over Ground(COG)and Speed Over Ground(SOG). \n
 *
 *  \section sec81 Secuence ID:
 *      0 to 252 \n
 *  \section sec82 Course Over Ground Reference:
 *      0b00 = <B>TRUE</B>      \n 
 *      0b01 = <B>MAGNETIC</B>  \n
 *      0b10 = <B>ERROR</B>     \n
 *      0b11 = <B>NULL</B>      \n
 *  \section sec83 Curse Over Ground:
 *      Offset = <B>0</B>, Factor = <B>.0001</B>, Unit = <B>rad/bit</B> \n  
 *  \section sec84 Speed Over Ground:
 *      Offset = <B>0</B>, Factor = <B>.01</B>, Unit = <B>m/bit</B> \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_N2K_GPS_COURSE_SPEED_GROUND_FAST    0x1F802U
#define SIZE_N2K_GPS_COURSE_SPEED_GROUND_FAST   8U

/* COGRefernce */
#define TRUE_COG                            0x00U
#define MAGNETIC_COG                        0x01U
#define ERROR_COG                           0x02U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef struct tagN2K_GPS_COURSE_SPEED_GROUND_FAST
{
    uint8_t      SID;
    /* 0b00 = TRUE     */
    /* 0b01 = MAGNETIC */
    /* 0b10 = ERROR    */
    /* 0b11 = NULL     */
    unsigned int COGReference :2;
    unsigned int Rvd          :6;
    /* Factor = 0.0001 Range = [0, 6.28318], Unit = rad. */
    uint16_t     CourseOverGround;
    /* Factor = 0.01 Range = [0, 655.32], Unit = m/s. */
    uint16_t     SpeedOverGround;
    uint16_t     Rvd2;
} N2K_GPS_COURSE_SPEED_GROUND_FAST_T;

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

/* End of $Workfile: N2K_GCSGF_canmsg.h$ */
