
#ifndef AGC_GUIDANCE_CANMSG_H
#define AGC_GUIDANCE_CANMSG_H

/*!\page AGC AutoGuide Command
 *  \brief <B>PAGE 0</B>
 */

/* Include ********************************************************************/
#include "types.h"

/* Enums **********************************************************************/

typedef enum tag_AGC_MESSAGE_GUIDANCE_E                    	 		/*!< List of Gudance messages */
{
    AGC_MESSAGE_GUIDANCE_NO_MESSAGE = 0,             				/*!< No message */
    AGC_MESSAGE_GUIDANCE_LOCALIZER_MSG = 1,               			/*!< Send a message information from AGC_MESSAGE_GUIDANCE_LOCALIZER_E */
	AGC_MESSAGE_GUIDANCE_LOCALIZER_INFO = 2,              			/*!< Send numeric information in localizer */
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_MSG = 10,              			/*!< Send a message information from AGC_MESSAGE_GUIDANCE_LOOKAHEAD_E */
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_INFO = 11,              			/*!< Send numeric information about lookahead */		
	AGC_MESSAGE_GUIDANCE_BEZIER_COEFF_INFO = 20,                  	/*!< Send numeric information about bezier coefficient */
	AGC_MESSAGE_GUIDANCE_BEZIER_ID_INFO = 21,                  		/*!< Send numeric information about ID of bezier */
	AGC_MESSAGE_GUIDANCE_BEZIER_QTY_INFO = 22,                  	/*!< Send numeric information about bezier qyt */
	AGC_MESSAGE_GUIDANCE_ERROR = 30,                  				/*!< Send a message information from AGC_MESSAGE_GUIDANCE_ERROR_E */

} AGC_MESSAGE_GUIDANCE_E;


typedef enum tag_AGC_MESSAGE_GUIDANCE_LOCALIZER_E             		/*!< List of Gudance Localizer messages */
{
    AGC_MESSAGE_GUIDANCE_LOCALIZER_MODE_NO_LOCALIZER = 0,          	/*!< No Localizer */
    AGC_MESSAGE_GUIDANCE_LOCALIZER_MODE_GLOBAL = 1,                	/*!< Localizer searching in global mode */
	AGC_MESSAGE_GUIDANCE_LOCALIZER_MODE_LOCAL = 2,                 	/*!< Localizer searching in local mode */
	AGC_MESSAGE_GUIDANCE_LOCALIZER_STATUS_NO_ERROR = 10,           	/*!< No errors in localization */
	AGC_MESSAGE_GUIDANCE_LOCALIZER_STATUS_EMPTY_LIST = 11,         	/*!< No bezier list in localizer */	
	AGC_MESSAGE_GUIDANCE_LOCALIZER_STATUS_LOCLIZER_ERROR = 12,    	/*!< Error in localization */
	AGC_MESSAGE_GUIDANCE_LOCALIZER_STATUS_END_PATH = 13,           	/*!< End path */
} AGC_MESSAGE_GUIDANCE_LOCALIZER_E;

typedef enum tag_AGC_MESSAGE_GUIDANCE_LOOKAHEAD_E             		/*!< List of Gudance Lookahead messages */
{
    AGC_MESSAGE_GUIDANCE_LOOKAHEAD_MODE_NO_LOCALIZER = 0,          	/*!< No Localizer in lookahead */
    AGC_MESSAGE_GUIDANCE_LOOKAHEAD_MODE_GLOBAL = 1,                	/*!< Localizer in lookahead searching in global mode */
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_MODE_LOCAL = 2,                 	/*!< Localizer in lookahead searching in local mode */
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_STATUS_NO_ERROR = 10,           	/*!< No errors in lookahead */
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_STATUS_EMPTY_LIST = 11,         	/*!< No bezier list in lookahead */	
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_STATUS_LOCLIZER_ERROR = 12,    	/*!< Error in lookahead */
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_STATUS_END_PATH = 13,           	/*!< End path */
	AGC_MESSAGE_GUIDANCE_LOOKAHEAD_STATUS_ENDDING_PATH = 14,        /*!< Endding path */
} AGC_MESSAGE_GUIDANCE_LOOKAHEAD_E;

typedef enum tag_AGC_MESSAGE_GUIDANCE_ERROR_E             			/*!< List of Gudance Error messages */
{
    AGC_MESSAGE_GUIDANCE_ERROR_WRONG_INPUTS = 1,          			/*!< Wrong inputs; NaN values */
} AGC_MESSAGE_GUIDANCE_ERROR_E;

//typedef enum tag_AGC_MESSAGE_GUIDANCE_BEZIER_E             			/*!< List of Gudance Bezier messages */
//{

//} AGC_MESSAGE_GUIDANCE_BEZIER_E;


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

/* End of $Workfile: AGC_GUIDANCE_CANMSG_H.h$ */

