
#ifndef ECUS_CANMSG_H
#define ECUS_CANMSG_H

/*! \page ECUS ECU Status
 *  \section sec5 Module Temperature:
 *      Offset = <B>-40</B>, Factor = <B>1</B>, Unit = <B>C/bit</B> \n
 *  \section sec1 Battery Voltage:
 *      Offset = <B>0</B>, Factor = <B>.05</B>, Unit = <B>V/bit</B> \n
 *  \section sec2 Capacitor Voltage:
 *      Offset = <B>0</B>, Factor = <B>.05</B>, Unit = <B>V/bit</B> \n
 *  \section sec3 Memory Diagnostic:
 *      <B>TYPE MEMORY MASK (0xF0)</B>     \n
 *      0x00 = <B>OK</B>                   \n
 *      0x1X = <B>FLASH MEMORY</B>         \n
 *      0x2X = <B>EEPROM MEMORY</B>        \n
 *      0x3X = <B>NVRAM MEMORY</B>         \n 
 *                                         \n 
 *      <B>CODE ERROR MASK (0x0F)</B>      \n
 *      0xX1 = <B>BACKUP BANK 1 ERROR</B>       \n
 *      0xX2 = <B>BACKUP BANK 2 ERROR</B>       \n
 *      0xX3 = <B>BACKUP BANK 1 AMD 2 ERROR</B> \n
 *                                              \n  
 *      <B>Example: </B>                        \n  
 *      1) 0x21 = <B>EEPROM BACKUP BANK 1 ERROR</B> \n  
 *      2) 0x30 = <B>NVRAM MEMORY OK</B>            \n  
 *  \section sec4 Processor Diagnostic:
 *      0x00 = <B>OK</B>                        \n
 *      0x01 = <B>WATCH DOG ERROR</B>           \n       
 */


/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_ECU_STATUS              0xFF03U
#define SIZE_ECU_STATUS             7U

/* Memory Errors */
#define VTSIG_OK_MEM                0x00U
#define VTSIG_FLASH_MEM	            0x10U
#define VTSIG_EEPROM_MEM		    0x20U
#define VTSIG_NVRAM_MEM			    0x30U
#define VTSIG_BACKUP1_ERROR_MEM     0x01U
#define VTSIG_BACKUP2_ERROR_MEM     0x02U
#define VTSIG_BACKUP1AND2_ERROR_MEM	0x03U

#define ECUS_TYPE_MEM               0xF0U
#define ECUS_CODE_ERROR_MEM         0x0FU

/* Processor Errors */
#define VTSIG_OK_PROC               0x00U
#define VTSIG_RESET_WATCHDOG_PROC   0x01U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagECU_STATUS
{
  uint8_t  ModuleIntTemp;
  uint16_t VBatt;
  uint16_t VCap;
  uint8_t  MemDiag;
  uint8_t  ProcDiag;
} ECU_STATUS_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 ECUS_CANMSG (uint32_t ctrl);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: ECUS_canmsg.h$ */
