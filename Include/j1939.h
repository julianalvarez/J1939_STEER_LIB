/*******************************************************************************
** $Revision: 45$
** $Date: 18/07/2014 08:13:04 a.m.$
** $Author: Bernab� Scarso$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/
#ifndef J1939_H
#define J1939_H

/* Include ********************************************************************/
#include "canmsg/rqst_canmsg.h"
#include "canmsg/ackm_canmsg.h"
#include "canmsg/ac_canmsg.h"

/* Enums **********************************************************************/
typedef enum { /* Originator */
               IDLE_O_SM_J1939,
               BAM_O_SM_J1939,
               RTS_O_SM_J1939, 
               CTS_O_SM_J1939,
               DT_O_SM_J1939,
               EOMACK_O_SM_J1939,
               /* Responder */
               IDLE_R_SM_J1939,
               BAM_R_SM_J1939,
               RTS_R_SM_J1939, 
               CTS_R_SM_J1939,
               DT_R_SM_J1939,
               EOMACK_R_SM_J1939
             } J1939_TP_E;

typedef enum {
               NONE_EVENT, 
               PGN_EVENT, 
               REQUEST_EVENT,
               COMMAND_EVENT,
               ONPGN_EVENT,
               ONREQUEST_EVENT,
               ONCOMMAND_EVENT
             } J1939_EVENT_E;

/* Defines ********************************************************************/
//#define DEBUG_J1939
//#define DEBUG_J1939_TP

#if defined (SYSTEM_DD)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   10U
/* Max of Object Created */
#define MAX_FILTER_J1939                    20U
#define MAX_REG_MSG_J1939                   20U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  64U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        4U
                          
#elif defined (SYSTEM_CANJOYSTICK)             
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    15U
#define MAX_REG_MSG_J1939                   15U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  8U
//#define J1939_TRANSPORT_PROTOCOL             
//#define MAX_TRANSPORT_PROTOCOL_J1939        6U
             
#elif defined (SYSTEM_HUB)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_SBOXPLUS)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_SBOX7)
#define MAX_PORT_J1939                      3U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Gateway */
#define J1939_BRIDGE
#define MAX_FILTERGW_J1939                  30U
/* Fast packet Protocol */
#define J1939_FAST_PACKET_PROTOCOL
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_EOS)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_LB100)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    40U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        5U

#elif defined (SYSTEM_STEER)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    40U
#define MAX_FILTERGW_J1939                  20U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  256U
/* Gateway */
#define J1939_BRIDGE
/* Protocol */
#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_DD)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   10U
/* Max of Object Created */
#define MAX_FILTER_J1939                    20U
#define MAX_REG_MSG_J1939                   20U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  64U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        4U
                          
#elif defined (SYSTEM_CANJOYSTICK)             
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    15U
#define MAX_REG_MSG_J1939                   15U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  8U
//#define J1939_TRANSPORT_PROTOCOL             
//#define MAX_TRANSPORT_PROTOCOL_J1939        6U
             
#elif defined (SYSTEM_HUB)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_SBOXPLUS)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_SBOX7)
#define MAX_PORT_J1939                      3U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Gateway */
#define J1939_BRIDGE
#define MAX_FILTERGW_J1939                  30U
/* Fast packet Protocol */
#define J1939_FAST_PACKET_PROTOCOL
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_EOS)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    55U
#define MAX_REG_MSG_J1939                   55U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_LB100)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    40U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        5U

#elif defined (SYSTEM_STEER)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    40U
#define MAX_FILTERGW_J1939                  20U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  256U
/* Gateway */
#define J1939_BRIDGE
/* Protocol */
#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_GACA)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    40U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_TRANSPORT_PROTOCOL             
#define MAX_TRANSPORT_PROTOCOL_J1939        6U

#elif defined (SYSTEM_CANSEED) || defined (SYSTEM_CANSEEDRADAR)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    15U
#define MAX_REG_MSG_J1939                   15U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  32U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_CANIO)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    10U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_SMARTANTENNA)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    13U
#define MAX_REG_MSG_J1939                   13U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        4U

#elif defined (SYSTEM_ECUROW)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    25U
#define MAX_REG_MSG_J1939                   25U
/* Gateway */
#define J1939_BRIDGE
#define MAX_FILTERGW_J1939                  30U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        2U

#elif defined (SYSTEM_CANIMU)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    10U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_CANLIGHT)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    10U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_CANULTRASONIC)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    10U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_RADAR)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    10U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  128U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_CANWEATHERSTATION)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    15U
#define MAX_REG_MSG_J1939                   40U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_ACTIVESINGULATION)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    15U
#define MAX_REG_MSG_J1939                   15U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  32U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (SYSTEM_ACTIVEFORCECONTROLLER)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    25U
#define MAX_REG_MSG_J1939                   25U
/* Gateway */
#define J1939_BRIDGE
#define MAX_FILTERGW_J1939                  30U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        2U

#elif defined (SYSTEM_ACTIVEFORCE)
#define MAX_PORT_J1939                      1U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    15U
#define MAX_REG_MSG_J1939                   15U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  32U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        1U

#elif defined (TERRAN_SYSTEM)
#define MAX_PORT_J1939                      2U
/* Max of Object Created */
#define MAX_TIMEOUT_J1939                   5U
/* Max of Object Created */
#define MAX_FILTER_J1939                    25U
#define MAX_REG_MSG_J1939                   25U
/* Gateway */
#define J1939_BRIDGE
#define MAX_FILTERGW_J1939                  30U
/* J1939 Circular Buffer Messages */
#define J1939_CIR_BUF_SIZE                  16U
/* Transport Protocol */
//#define J1939_FAST_PACKET_PROTOCOL
#define J1939_TRANSPORT_PROTOCOL
#define MAX_TRANSPORT_PROTOCOL_J1939        2U

#else
    #error "is not defined any SYSTEM!!"
#endif

/* Period Timer */
#define PERIOD_TIMER_J1939                  10U     /* 10 ms */
#define CONTENTION_TIME_J1939               (260U / PERIOD_TIMER_J1939) /* 260 ms / 20ms */
#define NULL_ADDRESS_CLAIM_TIME             (90000 / PERIOD_TIMER_J1939)

/* Function */
#define J1939_FUNCTION_VEHICLE_NAVIGATION   23U

/* ECU Address */
#define J1939_ADDRESS_PVED_CL                   19U
#define J1939_ADDRESS_ESI2                      19U
#define J1939_ADDRESS_VEHICLE_NAVIGATION        28U
#define J1939_ADDRESS_SMARTANTENNA              J1939_ADDRESS_VEHICLE_NAVIGATION
#define J1939_ADDRESS_SYSTEM_MONITOR            128U
#define J1939_ADDRESS_WEATHERSTATION            200U
#define J1939_ADDRESS_ACTIVESINGULATION         201U
#define J1939_ADDRESS_ACTIVEFORCECONTROLLER     202U
#define J1939_ADDRESS_ACTIVEFORCE               203U
#define J1939_ADDRESS_JOYSTICK                  208U
#define J1939_ADDRESS_GAC                       210U
#define J1939_ADDRESS_OCU                       215U
#define J1939_ADDRESS_UCU                       216U
#define J1939_ADDRESS_HCU                       217U
#define J1939_ADDRESS_UMU                       218U
#define J1939_ADDRESS_HCU2                      219U
#define J1939_ADDRESS_SHU                       220U
#define J1939_ADDRESS_ROCU                      221U
#define J1939_ADDRESS_CANSIP                    223U
#define J1939_ADDRESS_CANSEED                   224U
#define J1939_ADDRESS_ECUROW                    225U
#define J1939_ADDRESS_CANIO                     226U
#define J1939_ADDRESS_HOOK_WHEIGHT_METER        227U
#define J1939_ADDRESS_DRIVE_TRAIN               228U
#define J1939_ADDRESS_CHARGER                   229U
#define J1939_ADDRESS_CANSTEER                  230U
#define J1939_ADDRESS_CANULTRASONIC             231U
#define J1939_ADDRESS_DD                        232U
#define J1939_ADDRESS_LIGHTBAR                  233U
#define J1939_ADDRESS_CANGPRS                   234U
#define J1939_ADDRESS_CANGPS                    235U
#define J1939_ADDRESS_CANYIELD                  236U
#define J1939_ADDRESS_CANIMU                    237U
#define J1939_ADDRESS_CANKEY                    238U
#define J1939_ADDRESS_CAN_LIGHT                 239U
#define J1939_ADDRESS_HUB                       240U
#define J1939_ADDRESS_IOHUB                     241U
#define J1939_ADDRESS_RADAR                     242U
#define J1939_ADDRESS_BMS                       243U
#define J1939_ADDRESS_SBOX                      244U
#define J1939_ADDRESS_VDU                       245U
#define J1939_ADDRESS_AIOU                      246U
#define J1939_ADDRESS_VC                        247U
#define J1939_ADDRESS_EOS                       J1939_ADDRESS_AIOU
#define J1939_ADDRESS_FBOOT                     251U
#define J1939_ADDRESS_PVED_MMI                  252U
#define J1939_ADDRESS_PVED_CONFIGURATION_TOOL   253U
#define J1939_ADDRESS_NULL                      254U
#define J1939_ADDRESS_GLOBAL                    255U

/* PUT IT IN 1 ERROR GENERAL MODULE */
/* Function Return Codes */
#define RC_ERROR                            -1
#define RC_SUCCESS                          0
#define RC_QUEUEEMPTY                       1
#define RC_QUEUEFULL                        1
#define RC_CANNOTRECEIVE                    2
#define RC_CANNOTTRANSMIT                   2
#define RC_PARAMERROR                       3
#define RC_NOMORE                           3
#define RC_FINISH                           4
#define RC_SIZEERROR                        5	
#define RC_TXBUFFERFULL                     6
        
/* J1939 Default Priorities */
#define J1939_NAVIGATION_PRIORITY           1U
#define J1939_CONTROL_PRIORITY              3U
#define J1939_INFO_PRIORITY                 6U
#define J1939_PROPRIETARY_PRIORITY          6U
#define J1939_REQUEST_PRIORITY              6U
#define J1939_ACK_PRIORITY                  6U
#define J1939_TP_CM_PRIORITY                7U
#define J1939_TP_DT_PRIORITY                7U

/* J1939 PDU Formats, Control Bytes, and PGN's */
#define J1939_PF_ADDRESS_CLAIM              0xEEU	/* With global address */
#define J1939_PF_PROPRIETARY_A              0xEFU
#define J1939_PF_PROPRIETARY_B              0xFFU
#define J1939_PF_REQUEST                    0xEAU
#define J1939_PF_ACKNOWLEDGMENT             0xE8U
#define J1939_PF_DM14                       0xD9U
#define J1939_PF_DM15                       0xD8U
#define J1939_PF_DM16                       0xD7U
#define J1939_PF_TPCM                       0xECU
#define J1939_PF_TPDT                       0xEBU
#define J1939_PF_REQUEST2                   0xC9U
#define J1939_PF_TRANSFER                   0xCAU
#define J1939_PF_VTTOECU                    0xE6U
#define J1939_PF_ECUTOVT                    0xE7U

#define PGN_ADDRESS_CLAIM                   0xEE00U 
#define PGN_COMMANDED_ADDRESS               0xFED8U 
#define PGN_REQUEST                         0xEA00U
#define PGN_BOOTLOADER                      0x0100U
#define PGN_RESET                           0x0200U
#define PGN_INVALID                         J1939SIG_NA_U32 // To signal uninitialized internal variables

#define J1939_MSG_LENGTH                    5U
#define J1939_DATA_LENGTH                   8U

#define GroupExtension                      PDUSpecific
#define DestinationAddress                  PDUSpecific

/* Put all the Transport Protocol in another Module */
#define J1939_TP_MAX_PACKETS                255U
#define J1939_TP_MAX_BYTES                  (J1939_TP_MAX_PACKETS * 7U)

/* Max Limit */
#define MAX_VALUE_U8_J1939                  0xFAU
#define MAX_VALUE_U16_J1939                 0xFAFFU
#define MAX_VALUE_U32_J1939                 0xFAFFFFFFUL

/* General J1939SIG */
#define J1939SIG_SI_DEFAULT_VALUES_U8       0xFBU
#define J1939SIG_SI_DEFAULT_VALUES_U16      0xFB00U
#define J1939SIG_SI_DEFAULT_VALUES_U32      0xFB000000U
#define J1939SIG_NA_U2                      0x03U
#define J1939SIG_NA_U3                      0x07U
#define J1939SIG_NA_U4                      0x0FU
#define J1939SIG_NA_U5                      0x1FU
#define J1939SIG_NA_U6                      0x3FU
#define J1939SIG_NA_U8                      0xFFU
#define J1939SIG_NA_U12						0x0FFFU
#define J1939SIG_NA_U16                     0xFFFFU
#define J1939SIG_NA_U32                     0xFFFFFFFFUL
#define J1939SIG_NA_U40                     0xFFFFFFFFFFUL
#define J1939SIG_NA_U48                     0xFFFFFFFFFFFFUL
#define J1939SIG_NA_U56                     0xFFFFFFFFFFFFFFUL

#define J1939SIG_OFF                        0x00U	
#define J1939SIG_ON                         0x01U
    
#define J1939SIG_ERROR_U2                   0x02U
#define J1939SIG_ERROR_U3                   0x06U
#define J1939SIG_ERROR_U4                   0x0EU
#define J1939SIG_ERROR_U8                   0xFEU
#define J1939SIG_ERROR_U16                  0xFE00U
#define J1939SIG_ERROR_U32                  0xFE000000U

#define J1939SIG_REVERSED                   J1939SIG_OFF
#define J1939SIG_FORWARD                    J1939SIG_ON

#define J1939SIG_NOT_PRESSED                J1939SIG_OFF
#define J1939SIG_PRESSED                    J1939SIG_ON

#define J1939SIG_NOT_VALID_U8               0xFBU
#define J1939SIG_NOT_VALID_U16              0xFB01U
#define J1939SIG_NOT_VALID_U32              0xFB000001U

/* Vehicles Systems */
#define VS_NON_SPECIFIC_SYSTEM_MSG          0U
#define VS_TRACTOR_MSG                      1U
#define VS_TILLAGE_MSG                      2U
#define VS_SECONDARY_TILLAGE_MSG            3U
#define VS_PLANTERS_SEEDERS_MSG             4U
#define VS_FERTILIERS_MSG                   5U
#define VS_SPRAYERS_MSG                     6U
#define VS_COMBINES_HARVESTERS_MSG          7U
#define VS_ROOT_HARVESTERS_MSG              8U
#define VS_FORAGE_MSG                       9U
#define VS_IRRIGATION_MSG                   10U
#define VS_MODULE_SPECIFIC_MSG              15U

/* TimeOuts */
#define TIMEOUT_R_J1939                     250U
#define TIMEOUT_H_J1939                     550U
#define TIMEOUT_1_J1939                     800U
#define TIMEOUT_2_J1939                     1300U
#define TIMEOUT_3_J1939                     1300U
#define TIMEOUT_4_J1939                     1100U

/*#define TIMEOUT_R_J1939                     0xFFFFU
  #define TIMEOUT_H_J1939                     0xFFFFU
  #define TIMEOUT_1_J1939                     0xFFFFU
  #define TIMEOUT_2_J1939                     0xFFFFU
  #define TIMEOUT_3_J1939                     0xFFFFU
  #define TIMEOUT_4_J1939                     0xFFFFU */

#define J1939_CIR_BUF_MASK                  (J1939_CIR_BUF_SIZE - 1U)

#define J1939_CIR_BUF_RESET(Buf)            (Buf.rdIdx = Buf.wrIdx = 0)
#define J1939_CIR_BUF_PUSH(Buf, dataIn)     (Buf.buffer[J1939_CIR_BUF_MASK & Buf.wrIdx++] = (dataIn))
#define J1939_CIR_BUF_POP(Buf)              (Buf.buffer[J1939_CIR_BUF_MASK & Buf.rdIdx++])   
#define J1939_CIR_BUF_EMPTY(Buf)            (Buf.rdIdx == Buf.wrIdx)
#define J1939_CIR_BUF_FULL(Buf)             ((J1939_CIR_BUF_MASK & Buf.rdIdx) == (J1939_CIR_BUF_MASK & (Buf.wrIdx+1)))
#define J1939_CIR_BUF_COUNT(Buf)            (J1939_CIR_BUF_MASK & (Buf.wrIdx - Buf.rdIdx))

#define GET_PGN(pgn)                        (pgn & 0x3FFFFU)
#define GET_PDUFORMAT(pgn)                  ((pgn & 0x3FF00U) >> 8)
#define GET_PDUSPECIFIC(pgn)                (pgn & 0x00FFU)
#define IF_PDU1(pgn)                        (((pgn & 0x0FF00U) >> 8) < 240U)

#define MAX_TP_PACKETS_J1939                255U
#define MAX_TP_BYTES_J1939                  (MAX_TP_PACKETS_J1939 * 7U)

/* Typedefs *******************************************************************/
#if defined (__ghs__) || (__GNUC__) || (__TI_ARM__)
#pragma pack(1)
#endif

typedef struct tagJ1939_FLAG_T
{
    bool PortInitialized;
    bool CannotClaimAddress;
    bool WaitingForAddressClaimContention;
    bool GettingCommandedAddress;
    bool GotFirstDataPacket;
    bool ReceivedMessagesDropped;
} J1939_FLAG_T;

typedef struct tagJ1939_MESSAGE_T
{
    uint8_t      bfEFF;
    uint8_t      Priority;
    uint32_t     Pgn;
    uint8_t      SourceAddress;
    uint32_t     Length;
    uint8_t      Data[J1939_DATA_LENGTH];
    uint8_t*     pData;
} J1939_MESSAGE_T;

typedef struct J1939_CIR_BUF {
  uint32_t        wrIdx;
  uint32_t        rdIdx;
  J1939_MESSAGE_T buffer[J1939_CIR_BUF_SIZE];
} J1939_CIR_BUF_T;

typedef struct tagJ1939_REG_MSG_T
{
    uint32_t      Pgn;
    uint8_t       Priority;
    uint32_t      Length;
    void*         pMsg;
    void*         pMsg_Old;
    J1939_EVENT_E eType;
    unsigned int  bfChanged      :1;
    unsigned int  bfOnChangeTime :1;
    unsigned int  bfCycleTime    :1;
#ifdef J1939_FAST_PACKET_PROTOCOL
    unsigned int  bfFastPacket   :1;        // Used in Fast-Packet Protocol.
    uint8_t       Frame;                    // Used in Fast-Packet Protocol.
    uint8_t       CounterByte;              // Used in Fast-Packet Protocol.
#endif
    uint16_t      CounterCT;
    uint16_t      CounterOC;
    uint16_t      CycleTime;
    uint16_t      OnChangeTime;
    uint16_t      CounterTimeOut;
    uint16_t      TimeOut;
    void          (*Function)(void);
    uint32_t      (*FunctionA)(uint32_t Addr);
    void          (*FunctionAC)(uint32_t Addr, uint32_t ControlByte);
    void          (*FunctionTM)(void);
    struct J1939_TP_T* pTP;
} J1939_REG_MSG_T;

typedef struct tagJ1939_TP_T
{
    struct
    {
        unsigned int bfResponder       :1;
        unsigned int bfOriginator      :1;
        unsigned int bfBAM             :1;
        unsigned int bfDT              :1;
        unsigned int bfMessageReceived :1;
    } Flag;
    J1939_TP_E CurrState;
    uint32_t   Ctrl;
    uint32_t   Pgn;
    uint32_t   TotalMessageSize;
    uint16_t   MessageSize;
    uint16_t   TotalNumberOfPackets;
    uint16_t   NumberOfPackets;
    uint16_t   MaximumNumberOfPackets;
    uint8_t    NumberOfPacketsCanSent;
    uint8_t    NextPacketNumberToBeSent;
    uint8_t    SequenceNumber;
    uint8_t    DestinationAddress;
    void       (*pfEOMACK)(void);
    uint32_t   (*pfEOMACKA)(uint32_t Addr);
    void       (*pfABORT)(void);
    void       *pMsg;
} J1939_TP_T;

typedef struct tagJ1939_TM_T
{
    uint16_t CounterTimeOut;
    uint16_t TimeOut;
    void (*FunctionTM) (void);
} J1939_TM_T;

typedef struct tagJ1939_FILTER_T
{
    uint32_t Pgn;
} J1939_FILTER_T;

typedef struct tagBlockOutputJ1939_T
{
    uint8_t   Ctrl;
    uint16_t  Pgn;
} BlockOutputJ1939_T;

#if defined (__TI_ARM__)
#pragma pack()
#endif

/* Externs ********************************************************************/
/* Public: */
extern ADDRESS_CLAIM_T  AC_NAME[MAX_PORT_J1939];
extern uint32_t         J1939_Address[MAX_PORT_J1939];
extern J1939_FLAG_T    	J1939_Flags[MAX_PORT_J1939];
extern J1939_FLAG_T    	J1939_FlagsGW[MAX_PORT_J1939];

extern J1939_CIR_BUF_T  j1939_TP_TX[MAX_PORT_J1939];
extern J1939_CIR_BUF_T  j1939_RX[MAX_PORT_J1939];
extern J1939_CIR_BUF_T  j1939_RXGW[MAX_PORT_J1939];
extern bool             J1939_TP_TxBsy[MAX_PORT_J1939];

/* Private */
extern J1939_FILTER_T	tFILTER[MAX_PORT_J1939][MAX_FILTER_J1939];
#ifdef J1939_BRIDGE
extern J1939_FILTER_T	tFILTERGW[MAX_PORT_J1939][MAX_FILTERGW_J1939];
#endif
extern J1939_REG_MSG_T  tREG_MSG[MAX_PORT_J1939][MAX_REG_MSG_J1939];
extern J1939_TM_T       tTM[MAX_PORT_J1939][MAX_TIMEOUT_J1939];
#ifdef J1939_TRANSPORT_PROTOCOL
extern J1939_TP_T       tTP[MAX_PORT_J1939][MAX_TRANSPORT_PROTOCOL_J1939];
#endif
extern uint32_t         ContentionWaitTime[MAX_PORT_J1939];

/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

/* Private: */
void                    AddressClaim_J1939 (uint32_t ctrl);
void                    OnAddressClaim_J1939 (uint32_t ctrl, J1939_MESSAGE_T ReceivedMsg);
void                    OnRequestForAddressClaim_J1939 (uint32_t ctrl);
void                    InitializeFilter_J1939(uint32_t ctrl);
int32_t                 AddFilter_J1939 (uint32_t ctrl, uint32_t Pgn);
void                    InitializeFilterBridge_J1939(uint32_t ctrl);
int32_t                 AddFilterBridge_J1939 (uint32_t ctrl, uint32_t Pgn);
int32_t                 enableAllFilter_J1939 (uint32_t ctrl, bool enable);
bool                    ifAllFilter_J1939 (uint32_t ctrl);
void                    TimerEvent_J1939 (uint32_t ctrl);
void                    TimerEventInit_J1939 (uint32_t ctrl);
void                    TimerProcess_J1939 (uint32_t ctrl);

/* Semi Private: */
int32_t                 Output_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t Priority,
                                      uint32_t DataLength, void* pMsg, uint8_t SourceAddress);
int32_t                 DequeueMessage_J1939 (uint32_t ctrl, J1939_MESSAGE_T*);
int32_t                 EnqueueMessage_J1939 (uint32_t ctrl, J1939_MESSAGE_T*);
void                    ReceiveMessages_J1939 (uint32_t ctrl, J1939_MESSAGE_T*);
int32_t                 TransmitMessages_J1939 (uint32_t ctrl, J1939_MESSAGE_T*);
void                    WaitingACC_J1939 (uint32_t ctrl);

/* Public: */
                        /* TimeOut API */
void                    TimeOut_J1939 (uint32_t ctrl, uint32_t TimeOut, void (*FunctionTM)(void));
void                    ResetTimeOut_J1939 (uint32_t ctrl, void (*FunctionTM)(void));

                        /* API to enable sinchronization of address and claim address between all controllers;
                           ctrl 0 must be initied with name and address and all others not. 
                           After all ctrl are started, set synchronize to true. */
void                    SetSynchronizeAddressClaim(bool enable);
bool                    GetSynchronizeAddressClaim(void);
                        /* API to configure self address if Arbitrary_Address in ISONAME is true */
void                    SelfConfigurableAddressRange(uint32_t ctrl, uint8_t addrStart, uint8_t addrEnd);
                        /* Open J1939 Driver */
void                    Open_J1939 (uint32_t ctrl,
                                    bool     InitNAMEandAddress,
                                    uint8_t  Address,
                                    uint8_t  Arbitrary_Address,
                                    uint8_t  Industry_Group,
                                    uint8_t  Vehicle_Instance,
                                    uint8_t  Vehicle_System,
                                    uint8_t  Function,
                                    uint8_t  Function_Instance,
                                    uint8_t  Ecu_Instance,
                                    uint16_t Manufacturer_Code,
                                    uint32_t Identity_Number);

                        /* Messages API */
int32_t                 Pgn_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t Priority, uint32_t DataLength,
                                   void* pMsg, void* pMsg_Old, uint32_t OnChangeTime,
                                   uint32_t CycleTime, void (*Function)(void));
                                   
int32_t                 Deregister_Pgn_J1939(uint32_t ctrl, uint32_t Pgn);
int32_t                 Deregister_onPgn_J1939(uint32_t ctrl, uint32_t Pgn);
int32_t 				Deregister_Pgn_Function_J1939(uint32_t ctrl, uint32_t Pgn, void (*Function)(void));
int32_t                 Deregister_Request_J1939(uint32_t ctrl, uint32_t Pgn);
int32_t                 Deregister_onRequest_J1939(uint32_t ctrl, uint32_t Pgn);
int32_t                 Deregister_Command_J1939(uint32_t ctrl, uint32_t Pgn);
int32_t                 Deregister_onCommand_J1939(uint32_t ctrl, uint32_t Pgn);

int32_t                 Block_Output_J1939(uint32_t ctrl, uint32_t Pgn);
int32_t                 Clear_Output_J1939(uint32_t ctrl, uint32_t Pgn);
int32_t                 Init_Output_J1939(void);
                                   
int32_t                 Pgn_ChangeTime_J1939 (uint32_t ctrl,
                                              uint32_t Pgn,
                                              uint32_t OnChangeTime,
                                              uint32_t CycleTime);
int32_t 				Pgn_Function_ChangeTime_J1939 (uint32_t ctrl, 
													   uint32_t Pgn, 
													   uint32_t OnChangeTime, 
													   uint32_t CycleTime,
													   void (*Function)(void));
							  
int32_t                 OneShootPgn_J1939 (uint32_t ctrl, uint32_t Pgn);
int32_t                 OnPgn_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t DataLength, void* pMsg,
                                     uint32_t (*FunctionA)(uint32_t Addr),
                                     uint32_t TimeOut, void (*FunctionTM)(void));
int32_t                 ClearRegisteredOnPgn_J1939 (uint32_t ctrl);
int32_t                 OnPgnAllFilter_J1939 (uint32_t ctrl, uint32_t (*FunctionA)(uint32_t ctrl, J1939_MESSAGE_T* pMsg));
int32_t                 FunctionAllFilter_J1939 (uint32_t ctrl, J1939_MESSAGE_T* pMsg);

int32_t                 Request_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t DestinationAddress,
                                       void (*FunctionAC)(uint32_t Addr, uint32_t ControlByte),
                                       uint32_t TimeOut, void (*FunctionTM)(void));
int32_t                 OnRequest_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t Priority, uint32_t DataLength,
                                         void* pMsg, uint32_t (*FunctionA)(uint32_t Addr));

int32_t                 Command_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t Priority, uint32_t DataLength,
                                       void* pMsg, void (*FunctionAC)(uint32_t Addr, uint32_t ControlByte),
                                       uint32_t TimeOut, void (*FunctionTM)(void));
int32_t                 OnCommand_J1939 (uint32_t ctrl, uint32_t Pgn, uint32_t DataLength, void* pMsg,
                                         uint32_t (*FunctionA)(uint32_t Addr));
                        /* Gateway Function */
                        /*
                         * TODO: Transport Protocol Support.
                         */
int32_t                 BridgeMessages_J1939 (uint32_t ctrl, uint32_t Pgn);

                        /* Transport Protocol API */
int32_t                 RegisterTP_O_J1939 (uint32_t ctrl,
                                            uint32_t Pgn,
                                            uint32_t DataLength,
                                            uint32_t MaximumNumberOfPackets,
                                            uint32_t DestinationAddress,
                                            void     (*pfEOMACK)(void),
                                            void     (*pfABORT)(void));

int32_t                 TP_O_J1939 (uint32_t ctrl,
                                    uint32_t Pgn,
                                    void     *pMsg);

int32_t                 RegisterTP_R_J1939 (uint32_t ctrl,
                                            uint32_t Pgn,
                                            void*    pMsg,
                                            uint32_t NumberOfPacketsCanSent,
                                            uint32_t (*pfEOMACK)(uint32_t Addr),
                                            void     (*pfABORT)(void));

                        /* Prcessor for the J1939 Engine */
void                    Processor_J1939 (void);

                        /* Getters of with info available in the last message received */
uint32_t                getCTRLRcv_J1939 (void);
J1939_MESSAGE_T*        getMSGRcv_J1939 (void);
                   
                        /* State Machine API */
void                    TP_SM_J1939 (J1939_TP_T* pTP);
void                    TP_Set_SM_J1939 (J1939_TP_T* pTP, J1939_TP_E NewState);
void                    TP_SetData_SM_J1939 (J1939_TP_T* pTP, uint8_t* pData);
J1939_TP_E              TP_Get_SM_J1939 (J1939_TP_T* pTP);

#if defined(__cplusplus)
}
#endif

#endif /* end J1939_H */

/* End of $Workfile: j1939.h$ */



