/*******************************************************************************
** $Revision:
** $Date: 
** $Author: 
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef WSC_CANMSG_H
#define WSC_CANMSG_H

/*!\page WSC Weatherstation CONFIG
 *  \brief <B>PAGE 184</B>
  * \brief <B>PAGE 185</B>
 */


/* Enums **********************************************************************/
/* Defines ********************************************************************/

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef enum tagWEATHERSTATION_CONFIG_COMMAND_E
{
    WEATHERSTATION_CONFIG_COMMAND_SEND_CONFIGURATION       = 0,
    WEATHERSTATION_CONFIG_COMMAND_RESET                    = 1,
} WEATHERSTATION_CONFIG_COMMAND_E;

/******************************** General Msg *********************************/

/* WEATHERSTATION Config PAGE 184 */
typedef struct tagWEATHERSTATION_CONFIG_P184_T
{
    uint8_t             Page;
    uint8_t             Command;
    uint8_t             Message;
    uint8_t             ShortParam;
    uint32_t            LongParam;
} 	WEATHERSTATION_CONFIG_P184_T;

/* WEATHERSTATION Config PAGE 185 */

typedef struct tagWEATHERSTATION_CONFIG_P185
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint8_t  Rvd2;
	uint8_t  Rvd3;
    uint16_t NrwsMovAvg;        /* Factor = 1     Offset = 0  */        
    uint16_t NrwdMovAvg;	    /* Factor = 1     Offset = 0  */

} WEATHERSTATION_CONFIG_P185_T;

/* WEATHERSTATION Config PAGE 186 */

typedef struct tagWEATHERSTATION_CONFIG_P186
{
    uint8_t  Page;
    uint8_t  Rvd1;
    uint16_t HumiditySlope;         /* Factor = 1     Offset = 0  */        
    uint16_t TemperatureSlope;	    /* Factor = 1     Offset = 0  */
    uint16_t PressureSlope;     	/* Factor = 1     Offset = 0� */

} WEATHERSTATION_CONFIG_P186_T;


/******************************************************************************/
#if defined  (__ghs__) || (__GNUC__)
#pragma pack()
#endif



//#endif

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

/* End of $Workfile: WSC_canmsg.h$ */
