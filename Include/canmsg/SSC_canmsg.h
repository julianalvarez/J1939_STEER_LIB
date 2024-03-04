/*******************************************************************************
** $Revision: 0$
** $Date: 17/03/2015 08:06:12 a.m.$
** $Author: Cintia Corti$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef SSC_CANMSG_H
#define SSC_CANMSG_H


/*!\page Seed Sensor Configure 
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/

/* Enums **********************************************************************/
typedef enum tag_SSC_FAST_SPEED_LOGGING_MODE_E
{
    SSC_FAST_SPEED_LOGGING_OFF          = 0,
    SSC_FAST_SPEED_LOGGING_CONTINUOUS   = 1,
    SSC_FAST_SPEED_LOGGING_TRIGGERED    = 2,
    SSC_REAL_TIME_LOGGING               = 3,
} SSC_FAST_SPEED_LOGGING_MODE_E;

typedef enum tag_SSC_COMMAND_E                          /*!< List of commands for Seed Sensor */
{ 
    SSC_COMMAND_SEND_DIRT_DETAIL                = 0,        /*!< ShortParam in 1 indicates send; in 0, do not send */ 
    SSC_COMMAND_SEND_RXLEDs_OUTPUT              = 1,        /*!< ShortParam in 1 indicates send; in 0, do not send */
    SSC_COMMAND_SEND_DEBUG_OPTION               = 2,        /*!< ShortParam indicates the debug option sent, it will be a value in SSC_COMMAND_DEBUG_OPTIONS. If LongParam is valid, it contains a value to be set */
    SSC_COMMAND_SEND_DISTANCES_PAGES            = 3,        /*!< ShortParam in 1 indicates send; in 0, do not send */
    SSC_COMMAND_SEND_TEST_PAGES                 = 4,        /*!< ShortParam in 1 indicates send; in 0, do not send */
    SSC_COMMAND_SEND_CONFIGURATION              = 5,        /*!< Send current configuration */
    SSC_COMMAND_RESET_MODULE                    = 6,        /*!< Reset module - Deprecated, use RST PGN*/
    SSC_COMMAND_SIMULATE_DATA                   = 7,        /*!< Simulate sensor data with demo sequence. Long Param selects sequence. */
    SSC_COMMAND_STOP_DATA_SIMULATION            = 8,        /*!< Stop sensor simulation data */
    SSC_COMMAND_FAST_SPEED_LOGGING_MODE         = 9,        /*!< Enable Raw data logging. Short Param from SSC_FAST_SPEED_LOGGING_MODE_E */
    SSC_COMMAND_RADAR_FREQ_CONFIGURATION        = 10,       /*!< Configuration of Radar frequency control. ShortParam 0: Manual Mode, LongParam: DAC value MAX 0xFFF. ShortParam 1: AutoMode, LongParam: FreqSetpoint, KHz */
} SSC_COMMAND_E;

typedef enum tag_SSC_MESSAGES_E                         /*!< List of messages returned from Seed Sensor */
{
	SSC_MESSAGE_SEED_TYPE_ERROR = 0,                    /*!< Seed Type selected is invalid. */
    SSC_MESSAGE_SET_VALUE_ERROR = 1,                    /*!< Specified value cannot be set. */
    SSC_MESSAGE_OVERRUN = 2,                            /*!< LED barrier overrun */
    SSC_MESSAGE_UNKNOWN_ERROR   = 3
} SSC_MESSAGES_E;

typedef enum tagSEED_SENSOR_MODE_TYPE
{
  NORMAL_MODE   = 0U,
  CONFIG_MODE   = 1U,
  TEST_MODE     = 2U,
  DEBUG_MODE    = 3U
} SEED_SENSOR_MODE_TYPE_E;

typedef enum tagSEED_SENSOR_SEED_TYPE
{
    NoneSeed_           = 0U,
    Alfalfa_            = 1U,
    Canola_             = 2U,
    Colza_              = 3U,
    Trefoil_            = 4U,
    Barley_             = 5U,
    Corn_               = 6U,
    Beans_              = 7U,
    Flax_               = 8U,
    Grass_              = 9U,
    Millet_             = 10U,
    Mustard_            = 11U,
    Oats_               = 12U,
    Peas_               = 13U,
    Popcorn_            = 14U,
    Rice_               = 15U,
    Safflower_          = 16U,
    Rye_                = 17U,
    Sorghum_            = 18U,
    Soy_                = 19U,
    Sunflower_          = 20U,
    Wheat_              = 21U,
    Cotton_             = 22U,
    SoyLowDens_         = 23U,
    BigPeanut_          = 24U,
    SmallPeanut_        = 25U,
    SmallChickpea_      = 26U,
    BigChickpea_        = 27U,
    LAST_SEED_TYPE_     = 28U		
} SEED_SENSOR_SEED_TYPE_E;

typedef enum tag_SSC_PRODUCTS_E /*!< Product Type Identification */
{ 
    SSC_PRODUCT_SEEDS                           = 0,
    SSC_PRODUCT_FERTILIZER1                     = 1,
    SSC_PRODUCT_FERTILIZER2                     = 2,
} SSC_PRODUCTS_E;

typedef enum tag_SSC_COMMAND_DEBUG_OPTIONS  /*!< List of commands for debug*/
{ 
    TURN_ON_LED_PAIR    = 0U,               /* LongParam will contain the value of Rx in its eight LSB and the value of Tx in the following byte*/
    SET_CURRENT         = 1U,               /* LongParam will contain the current to be set */
    SET_GAIN            = 2U,               /* LongParam will contain the gain to be set */
    TURN_OFF_LEDS       = 3U                /* LongParam will be invalid, no value is needed*/
} SSC_COMMAND_DEBUG_OPTIONS;

/******************************** General Msg *********************************/

typedef struct tagSEED_SENSOR_CONF_P0
{
	uint8_t  Page;
	uint8_t  Command;               /* Value from SSC_COMMAND_E*/
	uint8_t  Message;               /* Value from SSC_MESSAGES_E*/
	uint8_t  ShortParam;            /* Short param for Command or Message */
	uint32_t LongParam;             /* Long param for Command or Message */
} SEED_SENSOR_CONF_P0_T;

typedef struct tagSEED_SENSOR_CONF_P1
{
    uint8_t  Page;
    uint8_t  Mode;                      /* Seed sensor mode.0x00U:Normal, 0x01U:Config, 0x02U:Test, 0x03U:Debug */
    uint8_t  VoltageThreshold;          /* A parameter used to compute the minimum voltage threshold to determine if a seed is being detected, or if the signal is just noise */
    uint8_t  TimeThreshold;             /* The minimum time the LED signal must stay occluded to consider that a seed has been detected */  
    uint8_t  Amplitude;                 /* If the seed type is unknown, this value helps determine if the seeds are big or small. It cannot be set by the user*/
    uint8_t  ThreshPercentSmallSeeds;   /* The voltage threshold when the seed type is unknown and the seeds are determined to be small*/
    uint8_t  ThreshPercentBigSeeds;     /* The voltage threshold when the seed type is unknown and the seeds are determined to be big*/
    uint8_t  SeedType;                  /* A value from 0 to 21 indicating the type of seed (soy, corn, etc) that should be detected. 0 means that the seed type is unknown */
} SEED_SENSOR_CONF_P1_T;

typedef struct tagSEED_SENSOR_CONF_P2
{
    uint8_t  Page;
    uint16_t GoodSpacingFactor;             /* Distance threshold up to which two seeds are considered well spaced. (unit: % of ideal distance)  */
    uint16_t IdealSeedDistance;             /* The target distance between seeds for optimum yield (unit: mm). For CANSeed, ecuRow uses IdealSeedsPerMeter*/
    uint8_t  NbrPagesForDistancesData;      /* Max number of pages that can be used to send the distances between consecutive seeds. */
    uint8_t  NumberOfLeds;                  /* The number of LEDs in the sensor */
    uint8_t  Rvd1; 
} SEED_SENSOR_CONF_P2_T;   

typedef struct tagSEED_SENSOR_CONF_P3
{
    uint8_t  Page;
    uint16_t DoublesFactor;                 /* Distance threshold up to which two seeds are considered a double. (unit: mm)  */
    uint16_t SkipsFactor;                   /* Minimum distance from which a skip is considered to have occurred (unit: mm).  */
    uint8_t  LedBarrierMode;                /* Mode for LEDBARRIER */
    uint16_t wDiffMinThresh;							/*Derivative threshold*/        
} SEED_SENSOR_CONF_P3_T;


typedef struct tagSEED_SENSOR_CONF_P4 // ECURow configuration
{
    uint8_t  Page;
    uint8_t  Mode;                      /* */
    uint16_t SeedHoles;                 /* Number of seeds per revolution; Scale: 1; Offset: 0; unit: N/A*/
    uint16_t IdealSeedsPerMeter;        /* Seeds per meter setpoint; unit: seeds/meter; Scale: 0.1 seeds/meter/bit; Offset: 0; For ecuRow only, CANseed uses IdealSeedDistance */
    uint16_t UnitWeight;                /* Product unit weight; Unit: g; Scale: 0.001 g/bit; Offset: 0 */
} SEED_SENSOR_CONF_P4_T;

typedef struct tagSEED_SENSOR_CONF_P5
{
    uint8_t  Page;                      
    uint8_t  ProductIndex;              /* Value from SSC_PRODUCTS_E */
    uint8_t  RowIndex;                  /* Indicates row number. Index 0 in the leftmost position looking in the advance direction */
    uint8_t  TotalRows;                 /* Total number of rows for this product */
    uint16_t ImplementWidth;            /* Total implement working width; Unit: mm; Scale: 1 mm/bit; Offset: 0 */
    uint16_t ImplementOffsetFromCenter; /* TODO */
} SEED_SENSOR_CONF_P5_T;

typedef struct tagSEED_SENSOR_CONF_P6
{
    uint8_t     Page;
    uint8_t     LedIndex;                   /* Index of the LED that you want to apply DAC and Gain */
    uint8_t     DBG_Gain;                   /* Gain mode to apply to LED with LedIndex */
    uint16_t    DBG_DAC;                    /* DAC counts to apply to LED with LedIndex */
    uint8_t     CurrentControlEnable;       /* Enable for Current Control*/
    uint8_t     DebugMsgsBuffSize;          /* Debug Messages Buffer Size*/
    uint8_t     DebugMsgsMode;              /* Debug Messages Processor Mode */
} SEED_SENSOR_CONF_P6_T;

typedef struct tagSEED_SENSOR_CONF_P7
{
    uint8_t     Page;
    uint16_t    DACMinValue;                /* Minimum Value of DAC in Current Control */
    uint8_t     Rvd1;
    uint8_t     Rvd2;
    uint8_t     Rvd3;
    uint8_t     Rvd4;
    uint8_t     Rvd5;
} SEED_SENSOR_CONF_P7_T;

#endif /* end SSC_CANMSG_H */

/* End of $Workfile: SSC_canmsg.h$ */

