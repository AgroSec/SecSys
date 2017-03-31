#ifndef GSM_H
#define GSM_H  1

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
#include "custom_types.h"

void PowerOnGSM(void);
void SendSMS(SMS_Message_en message);
unsigned char ReceiveSMS(void);
void ReadSMS(void);
#endif
//EOF

