/*******************************************************************************
** $Revision: 0$
** $Date: 17/05/2018 08:06:12 a.m.$
** $Author: Dario Gabriel Lipicar$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved. 
*******************************************************************************/

#ifndef PROPA_CRD_CANMSG_H
#define PROPA_CRD_CANMSG_H

/* Include ********************************************************************/
#include "types.h"

/* Defines ********************************************************************/
#define CRD_MSG_PAGE								 (180U)


#define CRD_MSG_XID_COMMAND                     (0x10U)  
#define CRD_MSG_XID_STATUS                      (0x11U)  
#define CRD_MSG_XID_GET_PARAMETER               (0xA0U)              
#define CRD_MSG_XID_GET_PARAMETER_RESPONSE      (0xA1U)        
#define CRD_MSG_XID_SET_PARAMETER               (0xA2U)
#define CRD_MSG_XID_SET_PARAMETER_RESPONSE      (0xA3U)
#define CRD_MSG_XID_GET_POINT                   (0xA4U)
#define CRD_MSG_XID_GET_POINT_RESPONSE          (0xA5U)
#define CRD_MSG_XID_SET_POINT                   (0xA6U)
#define CRD_MSG_XID_SET_POINT_RESPONSE          (0xA7U)
#define CRD_MSG_XID_GET_MATRIX                  (0xA8U)
#define CRD_MSG_XID_GET_MATRIX_RESPONSE         (0xA9U)
#define CRD_MSG_XID_SET_MATRIX                  (0xAAU)
#define CRD_MSG_XID_SET_MATRIX_RESPONSE         (0xABU)

/******************************** Enums *********************************/

/* Enums **********************************************************************/
typedef enum tagCRD_COMMANDS
{
    CRD_COMMAND_SEND_CONFIGURATION                  =  0x0000U, /* Request configuration from module */
    CRD_COMMAND_START_APP                  			=  0x0001U, /* Start */
	CRD_COMMAND_START_RUNNING                  		=  0x0002U, /* Start running*/
	CRD_COMMAND_STOP_RUNNING                  		=  0x0003U, /* Stop running */
    CRD_COMMAND_ENABLE                  		    =  0x0004U, /* Enable tracking */
    CRD_COMMAND_DISABLE                  		    =  0x0005U, /* Disable tracking */
    CRD_COMMAND_START_CALIB_DIST                  	=  0x0006U, /* Start distortion calibration */
    CRD_COMMAND_START_CALIB_PERSPECTIVE             =  0x0007U, /* Start perspective calibration */
    CRD_COMMAND_START_CALIB_DETECTOR                =  0x0008U, /* Start detector calibration */
    
} CRD_COMMANDS_E;


typedef enum tagCRD_PARAMETERS   /*!< List of CRD Parameters accessible with Get_Parameter/Set_Parameter */
{
  /* Calibration */
  CRD_PARAMETER_PX_RATIO_X                = 0x0000U,    /*!< Ratio meter/px */
  CRD_PARAMETER_PX_RATIO_Y                = 0x0001U,    /*!< Ratio meter/py */

  CRD_PARAMETER_CALIB_DETECTOR_ROW_QTY    = 0X0010U,    /*!< Detector calibration: Crop row quantity */
  CRD_PARAMETER_CALIB_DETECTOR_ROW_WIDTH  = 0X0011U,    /*!< Detector calibration: Average rows width */
  CRD_PARAMETER_CALIB_DETECTOR_ROW_SPACE  = 0X0012U,    /*!< Detector calibration: Average rows space */

} CRD_PARAMETERS_E;

typedef enum tagCRD_POINTS   /*!< List of CRD Points accessible with Get_Points/Set_Points */
{
  /* Calibration */
  CRD_POINT_CALIB_PERSPECTIVE_UP_LEFT     = 0x0000U,    /*!< Perspective calibration: Up-Left Point */
  CRD_POINT_CALIB_PERSPECTIVE_UP_RIGHT    = 0x0001U,    /*!< Perspective calibration: Up-Right Point */
  CRD_POINT_CALIB_PERSPECTIVE_DOWN_LEFT   = 0x0002U,    /*!< Perspective calibration: Down-Left Point */
  CRD_POINT_CALIB_PERSPECTIVE_DOWN_RIGHT  = 0x0003U,    /*!< Perspective calibration: Down-Right Point */
  
  CRD_POINT_CALIB_DETECTOR_POINT_0        = 0x0010U,    /*!< Detector calibration: Row=0 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_1        = 0x0011U,    /*!< Detector calibration: Row=0 Point=1 */
  CRD_POINT_CALIB_DETECTOR_POINT_2        = 0x0012U,    /*!< Detector calibration: Row=1 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_3        = 0x0013U,    /*!< Detector calibration: Row=1 Point=1 */
  CRD_POINT_CALIB_DETECTOR_POINT_4        = 0x0014U,    /*!< Detector calibration: Row=2 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_5        = 0x0015U,    /*!< Detector calibration: Row=2 Point=1 */
  CRD_POINT_CALIB_DETECTOR_POINT_6        = 0x0016U,    /*!< Detector calibration: Row=3 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_7        = 0x0017U,    /*!< Detector calibration: Row=3 Point=1 */
  CRD_POINT_CALIB_DETECTOR_POINT_8        = 0x0018U,    /*!< Detector calibration: Row=4 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_9        = 0x0019U,    /*!< Detector calibration: Row=4 Point=1 */
  CRD_POINT_CALIB_DETECTOR_POINT_10       = 0x001AU,    /*!< Detector calibration: Row=5 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_11       = 0x001BU,    /*!< Detector calibration: Row=5 Point=1 */
  CRD_POINT_CALIB_DETECTOR_POINT_12       = 0x001CU,    /*!< Detector calibration: Row=6 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_13       = 0x001DU,    /*!< Detector calibration: Row=6 Point=1 */
  CRD_POINT_CALIB_DETECTOR_POINT_14       = 0x001EU,    /*!< Detector calibration: Row=7 Point=0 */
  CRD_POINT_CALIB_DETECTOR_POINT_15       = 0x001FU,    /*!< Detector calibration: Row=7 Point=1 */

} CRD_POINTS_E;

typedef enum tagCRD_MATRIX   /*!< List of CRD Points accessible with Get_Matrix/Set_Matrix */
{
  /* Calibration */
  CRD_MATRIX_CALIB_DIST_CAMERA            = 0x0000U,    /*!< Distortion calibration: Camera matrix [3,3] */
  CRD_MATRIX_CALIB_DIST_NEW_CAMERA        = 0x0001U,    /*!< Distortion calibration: New camera matrix [3,3] */
  CRD_MATRIX_CALIB_DIST_ROI               = 0x0002U,    /*!< Distortion calibration: ROI [4,2] */
  CRD_MATRIX_CALIB_DIST_PARAMS            = 0x0003U,    /*!< Distortion calibration: Parameters [1,4]*/

} CRD_MATRIX_E;

typedef enum tagCRD_CALIB_TYPES
{
  /* Calibration */
  CRD_CALIB_PERSPECTIVE     = 0x0000U,    /*!< Perspective calibration */
  CRD_CALIB_MULTIROI        = 0x0001U,    /*!< MultiROI calibration */
  CRD_CALIB_PX_DENSITY      = 0x0002U,    /*!< Pixels density calibration (meters/px) */
} CRD_CALIB_TYPES_E;

typedef enum tagCRD_CALIB_RESULTS
{
  /* Calibration */
  CRD_CALIB_SUCCESS                     = 0x0000U,
  
  CRD_CALIB_GENERIC_FAIL                = 0x0010U,
  CRD_CALIB_FAIL_WRONG_COORDIANATES     = 0x0011U,
} CRD_CALIB_RESULTS_E;

typedef enum tagCRD_STATUS
{
	CRD_STATUS_SC_STARTUP					= 0x0000U,
	CRD_STATUS_SC_WAITING					= 0x0001U, 
	CRD_STATUS_SC_RUNNING					= 0x0002U,
	CRD_STATUS_SC_ENABLED					= 0x0003U,
	CRD_STATUS_SC_GUIDING					= 0x0004U,
	CRD_STATUS_SC_ERROR					    = 0x0005U,
	CRD_STATUS_SC_CALIBRATING				= 0x0006U,
} CRD_STATUS_E;

/******************************** Typedefs *********************************/
// #if defined (__ghs__) || (__GNUC__)
// #pragma pack(1)
// #endif

/******************************** General Msg *********************************/

/* PROPA Messages */

typedef struct tagCRD_MSG_P180
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  Byte3;
    uint8_t  Byte4;
    uint8_t  Byte5;
    uint8_t  Byte6;
    uint8_t  Byte7;
    uint8_t  Byte8;
} CRD_MSG_P180_T;

typedef struct tagCRD_MSG_P180_COMMAND
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t cmd;               /* Value from CRD_COMMANDS_E*/
    uint32_t Parameters;
} CRD_MSG_P180_COMMAND_T;

typedef struct tagCRD_MSG_P180_COMMAND_START_PARAMETERS
{
    unsigned int camera_route: 4; 
    unsigned int log: 1;
	unsigned int rvd0: 3;
	
	unsigned int calibrate_perspective: 1;
	unsigned int calibrate_detector: 1;
	unsigned int rvd1: 6;
	
	unsigned int show_result: 1;
	unsigned int show_binary: 1;
	unsigned int show_warped: 1;
	unsigned int show_warped_bin: 1;
	unsigned int show_unwarped: 1;
	unsigned int rvd3: 3;
	
	uint8_t rvd4;
	
} CRD_MSG_P180_COMMAND_START_PARAMETERS_T;


typedef struct tagCRD_MSG_P180_STATUS
{
    uint8_t  Page;
    uint8_t  XID;
    uint32_t Status;               /* Value from CRD_COMMANDS_E*/
    uint16_t Rvd;
} CRD_MSG_P180_STATUS_T;

typedef struct tagCRD_MSG_P180_GET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;      /* Value from CRD_PARAMETERS_E*/
    uint32_t Rvd1;
} CRD_MSG_P180_GET_PARAMETER_T;

typedef struct tagCRD_MSG_P180_GET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;      /* Value from CRD_PARAMETERS_E*/
    int32_t ParameterValue;      /* Offset: 0, Scale: 1000.0  */
} CRD_MSG_P180_GET_PARAMETER_RESPONSE_T;

typedef struct tagCRD_MSG_P180_SET_PARAMETER
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;      /* Value from CRD_PARAMETERS_E*/
    int32_t ParameterValue;      /* Offset: 0, Scale: 1000.0  */
} CRD_MSG_P180_SET_PARAMETER_T;

typedef struct tagCRD_MSG_P180_SET_PARAMETER_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t ParameterIndex;      /* Value from CRD_PARAMETERS_E*/
    int32_t ParameterValue;      /* Offset: 0, Scale: 1000.0  */
} CRD_MSG_P180_SET_PARAMETER_RESPONSE_T;



typedef struct tagCRD_MSG_P180_GET_POINT
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t pointID;           /* Value from CRD_POINTS_E*/
    uint32_t Rvd1;
} CRD_MSG_P180_GET_POINT_T;

typedef struct tagCRD_MSG_P180_GET_POINT_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t pointID;           /* Value from CRD_POINTS_E*/
    uint16_t pointX;            /* Offset: 0, Scale: 1.0  */
    uint16_t pointY;            /* Offset: 0, Scale: 1.0  */
} CRD_MSG_P180_GET_POINT_RESPONSE_T;

typedef struct tagCRD_MSG_P180_SET_POINT
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t  pointID;           /* Value from CRD_POINTS_E*/
    uint16_t pointX;            /* Offset: 0, Scale: 1.0  */
    uint16_t pointY;            /* Offset: 0, Scale: 1.0  */
} CRD_MSG_P180_SET_POINT_T;

typedef struct tagCRD_MSG_P180_SET_POINT_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint16_t  pointID;           /* Value from CRD_POINTS_E*/
    uint16_t pointX;            /* Offset: 0, Scale: 1.0  */
    uint16_t pointY;            /* Offset: 0, Scale: 1.0  */
} CRD_MSG_P180_SET_POINT_RESPONSE_T;



typedef struct tagCRD_MSG_P180_GET_MATRIX
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  MatrixIndex;       /* Value from CRD_MATRIX_E*/
    unsigned int row_idx: 4;    /* Offset: 0, Scale: 1.0  */
    unsigned int col_idx: 4;    /* Offset: 0, Scale: 1.0  */
    uint32_t Rvd1;
} CRD_MSG_P180_GET_MATRIX_T;

typedef struct tagCRD_MSG_P180_GET_MATRIX_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  MatrixIndex;        /* Value from CRD_MATRIX_E*/
    unsigned int row_idx: 4;     /* Offset: 0, Scale: 1.0  */
    unsigned int col_idx: 4;     /* Offset: 0, Scale: 1.0  */
    int32_t ParameterValue;     /* Offset: 0, Scale: 1000.0  */
} CRD_MSG_P180_GET_MATRIX_RESPONSE_T;

typedef struct tagCRD_MSG_P180_SET_MATRIX
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  MatrixIndex;        /* Value from CRD_MATRIX_E*/
    unsigned int row_idx: 4;     /* Offset: 0, Scale: 1.0  */
    unsigned int col_idx: 4;     /* Offset: 0, Scale: 1.0  */
    int32_t ParameterValue;     /* Offset: 0, Scale: 1000.0  */
} CRD_MSG_P180_SET_MATRIX_T;

typedef struct tagCRD_MSG_P180_SET_MATRIX_RESPONSE
{
    uint8_t  Page;
    uint8_t  XID;
    uint8_t  MatrixIndex;        /* Value from CRD_MATRIX_E*/
    unsigned int row_idx: 4;     /* Offset: 0, Scale: 1.0  */
    unsigned int col_idx: 4;     /* Offset: 0, Scale: 1.0  */
    int32_t ParameterValue;     /* Offset: 0, Scale: 1000.0  */
} CRD_MSG_P180_SET_MATRIX_RESPONSE_T;



typedef union tagCRD_MSG_P180_U
{
    CRD_MSG_P180_T                           	CRD_MSG_P180;
    CRD_MSG_P180_COMMAND_T                      CRD_MSG_P180_COMMAND;
    CRD_MSG_P180_GET_PARAMETER_T             	CRD_MSG_P180_GET_PARAMETER;
    CRD_MSG_P180_GET_PARAMETER_RESPONSE_T    	CRD_MSG_P180_GET_PARAMETER_RESPONSE;
    CRD_MSG_P180_SET_PARAMETER_T             	CRD_MSG_P180_SET_PARAMETER;
    CRD_MSG_P180_SET_PARAMETER_RESPONSE_T    	CRD_MSG_P180_SET_PARAMETER_RESPONSE;
    CRD_MSG_P180_GET_POINT_T             	    CRD_MSG_P180_GET_POINT;
    CRD_MSG_P180_GET_POINT_RESPONSE_T    	    CRD_MSG_P180_GET_POINT_RESPONSE;
    CRD_MSG_P180_SET_POINT_T             	    CRD_MSG_P180_SET_POINT;
    CRD_MSG_P180_SET_POINT_RESPONSE_T    	    CRD_MSG_P180_SET_POINT_RESPONSE;
    CRD_MSG_P180_GET_MATRIX_T             	    CRD_MSG_P180_GET_MATRIX;
    CRD_MSG_P180_GET_MATRIX_RESPONSE_T    	    CRD_MSG_P180_GET_MATRIX_RESPONSE;
    CRD_MSG_P180_SET_MATRIX_T             	    CRD_MSG_P180_SET_MATRIX;
    CRD_MSG_P180_SET_MATRIX_RESPONSE_T    	    CRD_MSG_P180_SET_MATRIX_RESPONSE;
    
} CRD_MSG_P180_U;

#endif /* end PROPA_CRD_CANMSG_H */

/* End of $Workfile: PROPA_CRD_canmsg.h$ */
