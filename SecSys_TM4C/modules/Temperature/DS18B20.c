/*---------------------OS Includes--------------------*/

/*-------------------Driver Includes------------------*/

/*-------------------Configuration Includes-----------*/

/*-------------------Service Includes-----------------*/
#include "onewire_handler.h"
/*------Export interface---Self header Includes-------*/
//#if TEMP_AVAILABLE
#include "DS18B20.h"
/*-----------------Application Includes---------------*/
#include "pc_display.h"
/*-------------Global Variable Definitions------------*/
extern uint8_t ROM_NO[8];
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/

//--------------------------------------------------------------------------
// TEST BUILD MAIN
//
void doStuffOnOneWire()
{	
	int16_t rslt,i,cnt;
	
	PC_Display_Message_FP("FIND ALL", -32767, 0, "");
	cnt = 0;
	rslt = OWFirst();
	while (rslt)
	{
		// print16_t device found
		for (i = 7; i >= 0; i--)
			PC_Display_Message_FP("asd", ROM_NO[i], 0, "");
		PC_Display_Message_FP("", ++cnt, 0, "");
		rslt = OWNext();
	}
	// find only 0x1A
	PC_Display_Message_FP("FIND ONLY 0x1A", -32767, 0, "");
	cnt = 0;
	OWTargetSetup(0x1A);
	while (OWNext())
	{
		// check for incorrect type
		if (ROM_NO[0] != 0x1A)
		break;

		// print device found
		for (i = 7; i >= 0; i--)
			PC_Display_Message_FP("qwe", ROM_NO[i], 0, "");
		PC_Display_Message_FP("", ++cnt, 0, "");
	}
	// find all but 0x04, 0x1A, 0x23, and 0x01
	PC_Display_Message_FP("FIND ALL EXCEPT 0x10, 0x04, 0x0A, 0x1A, 0x23, 0x01", -32767, 0, "");
	cnt = 0;
	rslt = OWFirst();
	while (rslt)
	{
		// check for incorrect type
		if ((ROM_NO[0] == 0x04) || (ROM_NO[0] == 0x1A) ||
		(ROM_NO[0] == 0x01) || (ROM_NO[0] == 0x23) ||
		(ROM_NO[0] == 0x0A) || (ROM_NO[0] == 0x10))
			OWFamilySkipSetup();
		else
		{
			// print device found
			for (i = 7; i >= 0; i--)
				PC_Display_Message_FP("dsa", ROM_NO[i], 0, "");
		PC_Display_Message_FP("", ++cnt, 0, "");
		}
		rslt = OWNext();
	}

}

//#endif	// TEMP_AVAILABLE
// EOF
