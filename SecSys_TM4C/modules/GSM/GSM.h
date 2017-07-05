#ifndef GSM_H
#define GSM_H  1

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
#include "custom_types.h"

typedef enum SMS_Message
{
	PIR_A = 0,
	PIR_B,
	Wire_1_Pull,
	Wire_1_Cut,
	Wire_2_Pull,
	Wire_2_Cut,
	Wire_3_Pull,
	Wire_3_Cut,
	Status,
	System_Ready,
	Wrong_Command,
	Switch1_Feedback,
	Switch2_Feedback,
} SMS_Message_en;

void GSMgetCommand(uint8_t *command,uint8_t msgId);
void PowerOnGSM(void);
void SendSMS(SMS_Message_en message);
uint8_t GSMgetResponse(void);
bool GSMparseMessage(uint8_t lineCount);
void GSMprocessMessage(uint8_t msgNum);
#endif
//EOF

