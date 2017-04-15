#ifndef GSM_H
#define GSM_H  1

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
#include "custom_types.h"

void PowerOnGSM(void);
void SendSMS(SMS_Message_en message);
//uint8_t ReceiveSMS(void);
//uint8_t CheckForSMS(void);
//void ReadSMS(uint8_t *message_data);

int16_t GSMgetResponse(void);
bool GSMparseMessage(int16_t lineCount);

#endif
//EOF

