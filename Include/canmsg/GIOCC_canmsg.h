/*******************************************************************************
** $Revision:
** $Date: 
** $Author:
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/
#ifndef GIOCC_CANMSG_H
#define GIOCC_CANMSG_H

/*! \page GIOC CONFIG
 *  \section sec6 Digital Input: 
 */

/* Include ********************************************************************/
#include "types.h"

/*******************************************************************************
 NON-SPECIFIC
******************************************************************************/
/* PAGE 0 */

/* PAGE 1 */ 

/*******************************************************************************
COMBINE-HARVESTER
******************************************************************************/
/* PAGE 0 */

 
/*******************************************************************************
 PLANT-SEEDER
******************************************************************************/
/* PAGE 0 */

/*******************************************************************************
SPRAYER
********************************************************************************/
/* PAGE 0 */
 
/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__)
#pragma pack(1)
#endif

typedef enum tag_GIOCC_COMMAND_E                          /*!< List of commands for GIOC LIBRARY */
{ 
    GIOC_COMMAND_SEND_DEBUG_OPTION               		  = 0,        /*!< ShortParam indicates the debug option sent, it will be a value in GIOC_COMMAND_DEBUG_OPTIONS. If LongParam is valid, it contains a value to be set */
    GIOC_COMMAND_SEND_PIN_CONFIGURATION          		  = 1,        /*!< Send current Pin configuration */
	GIOC_COMMAND_SEND_SEQUENCE_CONFIGURATION    	 	  = 2,		  /*!< Send current Sequence configuration */
    GIOC_COMMAND_RECEIVE_TOTAL_PIN_CONFIGURATION          = 3,        /*!< Receive total number of pin configuration */
	GIOC_COMMAND_RECEIVE_TOTAL_SEQUENCE_CONFIGURATION     = 4,     	  /*!< Receive total number of sequences configuration */
    GIOC_COMMAND_SEND_STATE_PIN_CONFIGURATION          	  = 5,		  /*!< Send pin configuration state sucessfull or not*/
	GIOC_COMMAND_SEND_STATE_SEQUENCE_CONFIGURATION    	  = 6,     	  /*!< Send sequence configuration state sucessfull or not*/
	GIOC_COMMAND_RESET_PIN_CONFIGURATION         		  = 7,        /*!< Reset Pin Confgiuration*/
	GIOC_COMMAND_RESET_SEQUENCE_CONFIGURATION     		  = 8,		  /*!< Reset Sequence Confgiuration*/
	GIOC_COMMAND_RECEIVE_CRC16_CONFIGURATION     		  = 9,		  /*!< Receive CRC16 Configuration*/
	
} GIOC_COMMAND_E;

typedef enum tag_GIOCC_MESSAGES_E                         /*!< List of messages returned from GIOC Library */
{                 
    GIOCC_MESSAGE_CONFIGURATION_NOTSUCCESS 				 = 0,
	GIOCC_MESSAGE_CONFIGURATION_SUCCESS 				 = 1
	
} GIOCC_MESSAGES_E;

typedef struct tag_GIOC_COMMAND_CONF_P187
{
	uint8_t  	Page;
	uint8_t  	Command;               /* Value from GIOC_COMMAND_E*/
	uint8_t  	Message;               /* Value from GIOC_MESSAGES_E*/
	uint8_t  	ShortParam;            /* Short param for Command or Message */
	uint32_t 	LongParam;             /* Long param for Command or Message */
	
} GIOC_COMMAND_CONF_P187_T;

/* GIOC Config PAGE 187 */
//Config pin
typedef struct tagGIOC_CONFIG_P188
{
    uint8_t		Page;
    uint8_t		Rdv1;
    uint8_t		ReservedPage;                 
    uint8_t		ReservedSlot;	    	
    uint8_t		Pin;     				
	uint8_t		Mode;
	uint16_t	Value;

} GIOC_CONFIG_P188_T;

/* GIOC Config PAGE 189 */
typedef struct tagGIOC_CONFIG_P189
{
    uint8_t		Page;
	//uint8_t		Rvd1;
	uint8_t		SequenceNumber;
	uint8_t		BlockNumber;
	uint8_t		IONumber;
//	uint8_t		NodeNumber;
	uint8_t		Mode;    		 // Input, Output, Alarm, Timer, Sequence
	uint8_t		ParamIdx ;  	 // 0 ModeIO, 1 Page, 2 Slot, 3 Compare Input value, 4 Value
    uint16_t	LongParam;                 
    				
} GIOC_SEQUENCE_CONFIG_P189_T;

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

/* End of $Workfile: SETD_canmsg.h$ */
