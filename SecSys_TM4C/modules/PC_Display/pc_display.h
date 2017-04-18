#ifndef PC_DISP_H
#define PC_DISP_H 1

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
#include "custom_types.h"

void PC_Display_Message(char *string1, uint32_t value, char *string2);
void PC_Display_Message_FP(char *string1, int32_t value, uint8_t digits, char *string2);
#endif
//EOF
