/* Include ********************************************************************/
#include "j1939.h"
#include "hal/hal.h"
#include "canmsg/HSI_canmsg.h"

/* Defines ********************************************************************/
/* Globals ********************************************************************/
/* Statics ********************************************************************/
static HARDWARE_SOFTWARE_INFO_T             tHSI[MAX_PORT_J1939];

/* Prototypes *****************************************************************/
uint32_t         __OnRequest_HSI (uint32_t Addr);

/* Functions ******************************************************************/

/*******************************************************************************
 *    Function Name:  .
 *    Parameters:     .
 *    Return Value:   .
 *
 *    Description:    .
 *
 *    Notes:          This Structure is in the EEPROM or FLASH
 ******************************************************************************/
int32_t HSI_CANMSG (uint32_t ctrl)
{
    /* Recall Values from EEPROM */
    //Read_EEPROM (HSI_ADDRESS_EEPROM, &tHSI[ctrl], 8U);
    
    /* ON REQUEST */
    /* Hardware Software Info */
    OnRequest_J1939 (ctrl,
                     PGN_HARDWARE_SOFTWARE_INFO,
                     J1939_INFO_PRIORITY,
                     SIZE_HARDWARE_SOFTWARE_INFO,
                     &tHSI[ctrl],
                     __OnRequest_HSI);
    
    /* Force Output */
    __OnRequest_HSI (0U);
    Output_J1939 (ctrl,
                  PGN_HARDWARE_SOFTWARE_INFO,
                  J1939_INFO_PRIORITY,
                  SIZE_HARDWARE_SOFTWARE_INFO,
                  &tHSI[ctrl],
                  J1939_Address[ctrl]);

    return 0;
}

int32_t HSI_CANMSG_Output (uint32_t ctrl){
    
    Read_EEPROM (HSI_ADDRESS_EEPROM, &tHSI[ctrl], 8U);
        /* Force Output */ 
    Output_J1939 (ctrl,
                  PGN_HARDWARE_SOFTWARE_INFO,
                  J1939_INFO_PRIORITY,
                  SIZE_HARDWARE_SOFTWARE_INFO,
                  &tHSI[ctrl],
                  J1939_Address[ctrl]);

    return 0;    
}

/*******************************************************************************
 *    Function Name:  .
 *    Parameters:     .
 *    Return Value:   .
 *
 *    Description:    .
 *
 *    Notes:          .
 ******************************************************************************/
#if defined (TI_CCS)
#pragma WEAK (__OnRequest_HSI)
#endif
uint32_t __OnRequest_HSI (uint32_t Addr)
{
    return (POSITIVE_ACKM);
}


/* End of $Workfile: HSI_canmsg.c$ */
