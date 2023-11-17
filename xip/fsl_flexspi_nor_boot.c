/*
 * Copyright 2017-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexspi_nor_boot.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xip_device"
#endif

#if defined(XIP_BOOT_HEADER_ENABLE) && (XIP_BOOT_HEADER_ENABLE == 1)
#if defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__GNUC__)
__attribute__((section(".boot_hdr.ivt"), used))
#elif defined(__ICCARM__)
#pragma location = ".boot_hdr.ivt"
#endif
/*************************************
 *  IVT Data
 *************************************/
const ivt image_vector_table = {
    IVT_HEADER,                    /* IVT Header */
    IMAGE_ENTRY_ADDRESS,           /* Image Entry Function */
    IVT_RSVD,                      /* Reserved = 0 */
    (uint32_t)DCD_ADDRESS,         /* Address where DCD information is stored */
    (uint32_t)BOOT_DATA_ADDRESS,   /* Address where BOOT Data Structure is stored */
    (uint32_t)&image_vector_table, /* Pointer to IVT Self (absolute address */
    (uint32_t)CSF_ADDRESS,         /* Address where CSF file is stored */
    IVT_RSVD                       /* Reserved = 0 */
};


/*************************************
 *  Boot Data
 *************************************/

#endif
