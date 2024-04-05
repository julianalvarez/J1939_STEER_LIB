
#ifndef HSI_CANMSG_H
#define HSI_CANMSG_H

/*! \page HSI Hardware Software Information
 *  \section sec41 Serial Number:
 *      0x0000 - 0xFA00   
 *  \section sec42 Manufacture Month:
 *      0x1F - 0xCF     \n
 *                      \n
 *      <B>Example:</B> \n
 *      0x4F = <B>April</B>, 0xCF = <B>December</B>
 *  \section sec43 Manufacture Year:
 *      0x00 - 0x63
 *  \section sec44 Hardware Version:
 *      0x00 - 0x99     \n
 *                      \n
 *      <B>Example:</B> \n
 *      0x12 = <B>x.1.2</B>, 0x00 = <B>x.0.0</B>
 *  \section sec45 Software Version:
 *      0x00 - 0x99     \n
 *                      \n
 *      <B>Example:</B> \n
 *      0x99 = <B>x.9.9</B>, 0x43 = <B>x.4.3</B>
 *  \section sec46 Hardware Version Extend:
 *      0xX0 - 0xX9     \n
 *                      \n
 *      <B>Example:</B> \n
 *      0x0X = <B>0.x.x</B>, 0x90 = <B>9.x.x</B>
 *  \section sec47 Software Version Extend:
 *      0x0X - 0x9X     \n
 *                      \n
 *      <B>Example:</B> \n
 *      0x1X = <B>1.x.x</B>, 0x90 = <B>9.x.x</B>
 *                      \n
 *  \section sec48 Software build:
 *      0x00 - 0x63
 *  \note In memory this structure layout is <B>packed</B> and <B>little endian</B>: \n
 *      ss SS mF yy hh ss SH bb \n
 *      <B>ss</B> is less significative byte of <B>s</B>erial number \n 
 *      <B>SS</B> is most significative byte of <B>s</B>erial number \n 
 *      <B>mf</B> is nibble byte of <B>m</B>onth of manufacture \n 
 *      <B>yy</B> is byte of <B>y</B>ear of manufacture\n 
 *      <B>hh</B> is less significative byte of <B>h</B>ardware version \n 
 *      <B>ss</B> is less significative byte of <B>s</B>oftware version \n 
 *      <B>XH</B> is extention nibble of <B>h</B>ardware version \n 
 *      <B>SX</B> is extention nibble of <B>s</B>oftware version \n 
 *      <B>bb</B> is byte of software <B>b</B>uild\n 
 *
 *      <B>Example:</B>                                  \n
 *       02 01 4F 0A 01 30 34 50                         \n
 *       serial: 0x0102 = <B>258</B>                     \n
 *       month: 0x4F = <B>April</B>                 \n 
 *       year: 0x0A = <B>2010</B>                  \n 
 *       hw v.: 0x401 = <B>4.0.1</B> (BCD notation) \n
 *       sw v.: 0x330 = <B>3.3.0</B> (BCD notation) \n
 *       build: 0x50 = <B>80</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_HARDWARE_SOFTWARE_INFO          0xFF05U
#define SIZE_HARDWARE_SOFTWARE_INFO         8U

#define HSI_ADDRESS_EEPROM                  0U

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagHARDWARE_SOFTWARE_INFO
{
    uint16_t     SerialNumber;
    unsigned int Rvd              :4;
    unsigned int ManufactureMonth :4;
    uint8_t	     ManufactureYear;
    uint8_t      HardwareVer;
    uint8_t	     SoftwareVer;
    unsigned int HardwareVerExt   :4;
    unsigned int SoftwareVerExt   :4;
    uint8_t	     SoftwareBuild;
} HARDWARE_SOFTWARE_INFO_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t 	            HSI_CANMSG (uint32_t ctrl);
int32_t 	            HSI_CANMSG_Output (uint32_t ctrl);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: HSI_canmsg.h$ */

