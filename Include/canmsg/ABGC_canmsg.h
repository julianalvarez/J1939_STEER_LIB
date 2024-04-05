
#ifndef ABGC_CANMSG_H
#define ABGC_CANMSG_H

/*!\page AB AB-Generic Curve
*  \brief <B>PAGE 0</B>
*/

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
typedef enum tagABGC_DATA_TYPES
{
    ABGC_HEADER_DT          = 0,    /*!<  */
    ABGC_LINE_DT            = 1,    /*!<  */
    ABGC_BEZIER_2ND_DT      = 2,    /*!<  */
    ABGC_BEZIER_3RD_DT      = 3,    /*!<  */
    ABGC_CIRCLE_DT          = 4,    /*!<  */
    ABGC_HEADLAND_CONFIG    = 5,    /*!<  */
    ABGC_LAST_DT            = 6     /*!<  */
} ABGC_DATA_TYPES_E;
 
/* Defines ********************************************************************/
#define PGN_ABGC_DATA                         0xFFF4U
#define SIZE_ABGC_DATA                        69U	

typedef enum tag_FI_SIGN_E
{
    FI_SIGN_NEGATIVE,
    FI_SIGN_POSITIVE
} FI_SIGN_E;

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

/* AB Line message */
typedef  struct tagFI
{
    /* 0: Negative 1:Positive */
    unsigned int        sign:2;            
    /* Factor = 1 */
    unsigned int        integer:30;
    /* Factor = 1/4211081216 range = [0, 4211081215/4211081216] */
    uint32_t            fractional;
} FI_T;

typedef  struct tagPATTERN_CONFIG
{
    unsigned int        bfUseExtendedBelongs    :2;
    unsigned int        Rvd1                    :2;
    unsigned int        Rvd2                    :2;
    unsigned int        Rvd3                    :2;
} PATTERN_CONFIG_T;

typedef  struct tagABGC_HEADER
{
    /* */
    uint16_t            wLastSequence;
    /* Reference Point */
    uint32_t            dwLatitude;
    uint32_t            dwLongitude;
    uint32_t            dwHeight;
    uint8_t             bPatternClass;
    PATTERN_CONFIG_T    tPatternConfig;
    uint16_t            wReserved[24];
} ABGC_HEADER_T;

typedef  struct tagABGC_LINE
{
    FI_T                tA;
    FI_T                tB;
    FI_T                tC;
    FI_T                tReserved[5];
} ABGC_LINE_T;

typedef  struct tagABGC_BEZIER_2ND
{
    FI_T                tAe;
    FI_T                tBe;
    FI_T                tCe;
    FI_T                tAn;
    FI_T                tBn;
    FI_T                tCn;
    FI_T                tReserved[2];
} ABGC_BEZIER_2ND_T;

typedef  struct tagABGC_BEZIER_3RD
{
    FI_T                tAe;
    FI_T                tBe;
    FI_T                tCe;
    FI_T                tDe;
    FI_T                tAn;
    FI_T                tBn;
    FI_T                tCn;
    FI_T                tDn;
} ABGC_BEZIER_3RD_T;
    
typedef  struct tagABGC_CIRCLE
{
    FI_T                tCenterEast;
    FI_T                tCenterNorth;
    FI_T                tCircleRadius;
    FI_T                tReserved[5];
} ABGC_CIRCLE_T;

typedef  struct tagHEADLAND_CONFIG
{
    uint16_t             bSkipSwath;        /* Number of swath to turn. Positive is right. Zero returns over same swath; Factor 1; Offset 32767 */
    /* Point Headland Start */
    uint32_t            dwLatitudeIn;       /* Unit Degree; Factor 1e-7; Offset 90 */
    uint32_t            dwLongitudeIn;      /* Unit Degree; Factor 1e-7; Offset 180 */
    uint32_t            dwHeightIn;         /* Unit m; Factor 0.001; Offset 2000000 */
    uint16_t            dwHeadingIn;        /* Unit rad; Factor 0.0001; Offset 0 */
    /* Point Headland End */
    uint32_t            dwLatitudeOut;      /* Unit Degree; Factor 1e-7; Offset 90 */
    uint32_t            dwLongitudeOut;     /* Unit Degree; Factor 1e-7; Offset 180 */
    uint32_t            dwHeightOut;        /* Unit m; Factor 0.001; Offset 2000000 */
    uint16_t            dwHeadingOut;       /* Unit rad; Factor 0.0001; Offset 0 */
    /* Fill - complete 64 bytes */
    uint16_t            wReserved[17];
} ABGC_HEADLAND_CONFIG_T;

typedef  union tagABGC_DATA
{
    ABGC_HEADER_T           tHeader;
    ABGC_LINE_T             tLine;
    ABGC_BEZIER_2ND_T       tBezier2;
    ABGC_BEZIER_3RD_T       tBezier3;
    ABGC_CIRCLE_T           tCircle;
    ABGC_HEADLAND_CONFIG_T  tHeadlandConfig;
} ABGC_DATA_T;
    
/* AB Data message (69 bytes) */
typedef  struct tagABGC_MSG_T
{
    ABGC_DATA_TYPES_E   eDataType;
    uint16_t            wSequence;	/* Messages sequence */
    uint16_t            wOrder;
    ABGC_DATA_T         tData;
} ABGC_MSG_T;

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

/* End of $Workfile: ABGC_canmsg.h$ */

