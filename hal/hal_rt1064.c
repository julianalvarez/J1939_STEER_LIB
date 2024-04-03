#include "j1939.h"
#include "hal/hal.h"
#include "can_ext.h"
#include "can.h"
#include "time.h"


void init_CAN (uint32_t ctrl, uint32_t baudrate)
{
    init_can (ctrl, 0, 0, 0, baudrate/1000);
}

void PutMSG_CAN (uint32_t ctrl, J1939_MESSAGE_T* pJ1939Msg)
{
    tSend            Msg;

    Msg.dwId = (((uint32_t)pJ1939Msg->Priority) << 26) |
               (((uint32_t)pJ1939Msg->Pgn) << 8)       |
               (uint32_t)pJ1939Msg->SourceAddress;
    Msg.bDlc = pJ1939Msg->Length;
    Msg.bXtd = pJ1939Msg->bfEFF;
    memcpy (Msg.abData, pJ1939Msg->Data, Msg.bDlc);

    send_can_msg (ctrl, 0, &Msg);
}

void Obj_ISR (uint8_t ctrl, CAN_msg* Msg)
{
    J1939_MESSAGE_T     J1939Msg;

	J1939Msg.Priority      = (Msg->id >> 26) & 0x07U;
	J1939Msg.Pgn           = (Msg->id >> 8) & 0x3FFFFU;
	J1939Msg.SourceAddress = Msg->id & 0xFFU;
	J1939Msg.Length        = Msg->len;
	J1939Msg.bfEFF         = Msg->format;
	memcpy (J1939Msg.Data, Msg->data, J1939Msg.Length );

	ReceiveMessages_J1939 (ctrl, &J1939Msg);

}

uint32_t getTime (void)
{
    return TIME_Get();
}

void SetAddressFilter_CAN (uint32_t ctrl, uint32_t Address)
{
    ctrl = ctrl;
    Address = Address;
}

void Write_EEPROM(uint32_t Address, void* pOrigin, uint32_t Size)
{
	Write_VIRTUAL_EEPROM (Address, (uint8_t*)pOrigin, Size);
}
