/*
 *  HX711 C reference driver
 */



sbit ADDO = P1^5;	//maybe some init
sbit ADSK = P0^0;

uint32_t ReadCount(void){
	uint32_t Count;
	uint8_t i;
	ADDO=1;		// set DOUT to HIGH
	ADSK=0;		// set SLK to LOW
	Count=0;
	while(ADDO);// wait for DOUT to go LOW
		for (i=0;i<24;i++)
		{
				ADSK=1;				// set SLK to HIGH
				Count=Count<<1;		// shift Count by 1 bit to the left to make room for new read
				ADSK=0;				// set SLK to LOW
				if(ADDO) Count++;	// if DOUT if HIGH, increment Count (set LSB in Count to 1)
		}
	ADSK=1;					// set SLK to HIGH (25th bit)
	Count=Count^0x800000;	// data is in 2's complement
	ADSK=0;					// set SLK to LOW (25th bit)
	return(Count);
} 