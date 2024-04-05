#ifndef PCFG_CANMSG_H
#define PCFG_CANMSG_H

/*! \page PCFG PGN Configure
 *  \section sect001 PGN:
 *      U32 PGN + SA.   
 *  \section sect002 OnChangeTime:
 *      On Change time in mseconds \n
 *                                 \n
 *  \section sect003 CycleTime:
 *      Cycle time in mseconds     \n
 *                                 \n
 *      <B>Example:</B> \n
 *      i.e.: 0x01FF80DA -> PGN = 0x1FF80, SA = DA \n
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_PGN_CONFIGURE                   0xFF04U
#define SIZE_PGN_CONFIGURE                  8U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagPGN_CONFIGURE_TIME
{
    /* 
     * PGN field layout:
     *                    MSB = PGN2
     *                     B2 = PGN1
     *                     B1 = PGN0
     *                    LSB = Source Address
     *
     * i.e.: 0x01FF80DA -> PGN = 0x1FF80, SA = DA
     */      
    uint32_t	 Pgn;
    uint16_t     OnChangeTime;
    uint16_t     CycleTime;  
} PGN_CONFIGURE_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t 	            PCFG_CANMSG (uint32_t ctrl);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: PCFG_canmsg.h$ */

