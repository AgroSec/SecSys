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

uint8_t GSMgetResponse(void);
bool GSMparseMessage(uint8_t lineCount);
void GSMprocessMessage(uint8_t msgNum);
#endif
//EOF

