
#ifndef _HAL_
#define _HAL_

#include "types.h"
#include "j1939.h"


/* Prototypes *****************************************************************/
#if defined(__cplusplus)
extern "C" 
{
#endif

/* General */
void                    Reset (void);
uint32_t                GetModuleTemp (void);
uint32_t                GetVBatt (void); 
uint32_t                GetVCap (void);
uint32_t                GetMemDiag (void); 
uint32_t                GetProcDiag (void); 

/* Time */
uint32_t                getTime (void);

/* Control Area Network */
void                    init_CAN (uint32_t ctrl, uint32_t baudrate);
void                    PutMSG_CAN (uint32_t ctrl, J1939_MESSAGE_T* pJ1939Msg);
void                    SetAddressFilter_CAN (uint32_t ctrl, uint32_t Address);
uint32_t                GetRxError_CAN (uint32_t ctrl);
uint32_t                GetTxError_CAN (uint32_t ctrl);

/* Eeprom */
void                    Read_EEPROM (uint32_t Address, void* pDest, uint32_t Size);
void                    Write_EEPROM (uint32_t Address, void* pOrigin, uint32_t Size);

#if defined(__cplusplus)
}
#endif

#endif // _HAL_

