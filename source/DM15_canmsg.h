/*******************************************************************************
** $Revision: 1$
** $Date: 08/02/2010 10:21:51 a.m.$
** $Author: Admin Leandro Gentili$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef DM15_CANMSG_H
#define DM15_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/
/* Defines ********************************************************************/
#define PGN_DM15                            0xD800U
#define SIZE_DM15                           8U

#define STATUS_PROCEED_DM15                 0U
#define STATUS_BUSY_DM15                    1U
#define STATUS_RVD1_DM15                    2U
#define STATUS_RVD2_DM15                    3U
#define STATUS_OPERATION_COMPLETED_DM15     4U 
#define STATUS_OPERATION_FAILED_DM15        5U
#define STATUS_RVD3_DM15                    6U
#define STATUS_RVD4_DM15                    7U

/* Error Indicator States */
#define EIS_NO_ERROR                        0x000000U
#define EIS_ERROR_NOT_DEFINED               0x000001U
#define EIS_PROCESSING_ELSE                 0x000002U

#define EIS_PROCESSING_ERASE                0x000010U
#define EIS_PROCESSING_READ                 0x000011U
#define EIS_PROCESSING_WRITE                0x000012U
#define EIS_PROCESSING_STATUS               0x000013U
#define EIS_PROCESSING_BOOTLOAD             0x000016U
#define EIS_PROCESSING_EDCP                 0x000017U
#define EIS_PROCESSING_UNSPECIFIED          0x00001FU

#define EIS_EDC_NOT_CORRECT                 0x000020U
#define EIS_RAM_NOT_VERIFIED                0x000021U
#define EIS_FLASH_NOT_VERIFIED              0x000022U
#define EIS_PROM_NOT_VERIFIED               0x000023U
#define EIS_INTERNAL_FAILURE_REQ            0x000024U

#define EIS_ADDRESS_GENERAL                 0x000100U
#define EIS_ADDRESS_NOT_BOUNDARY            0x000101U
#define EIS_ADDRESS_NOT_LENGTH              0x000102U
#define EIS_ADDRESS_EXCEED                  0x000103U
#define EIS_ADDRESS_ERASE_DATA              0x000104U
#define EIS_ADDRESS_ERASE_PROGRAM           0x000105U
#define EIS_ADDRESS_EXE_ERASE_PROGRAM       0x000106U
#define EIS_ADDRESS_BOOTLOADER_NOT_EXE      0x000107U
#define EIS_ADDRESS_BOOTLOADER_NOT_BOUNDARY 0x000108U
#define EIS_DATA_DATA_NOT_RANGE             0x000109U
#define EIS_DATA_NAME_NOT_VALUE             0x00010AU

#define EIS_SECURITY_GENERAL                0x001000U  
#define EIS_SECURITY_PASSOWRD               0x001001U
#define EIS_SECURITY_USER_LEVEL             0x001002U
#define EIS_SECURITY_KEY                    0x001003U
#define EIS_SECURITY_DIAGNOSTIC_MODE        0x001004U
#define EIS_SECURITY_NOT_DEVELOPMENT_MODE   0x001005U
#define EIS_SECURITY_ENGINE_RUNNING         0x001006U
#define EIS_SECURITY_NOT_PARK               0x001007U
 
#define EIS_ABORT                           0x010000U
#define EIS_TOO_RETRY                       0x010001U
#define EIS_NO_RESPONSE                     0x010002U
#define EIS_TIMEOUT                         0x010003U

/* EDCP Extension States */
#define EDCP_EXT_COMPLETED                  0x00U
#define EDCP_EXT_HIGHER                     0x02U
#define EDCP_EXT_LOWER                      0x03U
#define EDCP_EXT_ERROR                      0x06U
#define EDCP_EXT_ERROR_S                    0x07U
#define EDCP_EXT_NO_ERROR                   0xFFU

/* Typedefs *******************************************************************/
/*** STANDARD CAN MESSAGES: ***************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

/* DM15 - Memory Access Response */
typedef struct tagDM15
{
    uint8_t NumberAllowed;
	unsigned int Rvd1              :1;
	unsigned int Status            :3;
	unsigned int Rvd2              :1;
    unsigned int NumberAllowedExt  :3;
    unsigned int ErrorIndicator    :24;
	unsigned int EDCP_Extention    :8;
	uint16_t Seed;
} DM15_T;

#if defined  (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

int32_t                 DM15_CANMSG (uint32_t Status, 
                                     uint32_t ErrorIndicator,
                                     uint32_t NumberAllowed,
                                     uint32_t EDCP_Extention,
                                     uint32_t DestinationAddress);

#if defined(__cplusplus)
}
#endif

#endif	

/* End of $Workfile: DM15_canmsg.h$ */
