#ifndef GSM_H
#define GSM_H  1

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
#include "custom_types.h"

void PowerOnGSM(void);
void SendSMS(SMS_Message_en message);
uint8_t ReceiveSMS(void);
void ReadSMS(uint8_t *message_data);
#endif
//EOF

