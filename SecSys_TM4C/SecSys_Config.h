//This file will contain all the preprocessor commands to configure the SW before compilation

#ifndef CONFIG
	#define CONFIG

	/*	---					General purpose			---	*/
	#define PIR_AVAILABLE		(0)
	#define GSM_AVAILABLE		(0)
	#define HX711_AVAILABLE	(0)
	#define RFID_AVAILABLE	(0)
	#define TEMP_AVAILABLE	(1)

	#define DIGI_ALEX_GAAL1 0744424818
	#define ORANGE_ALEX_GAAL2 0758438903
	#define ORANGE_CLAUDIU_1 0751538300
	#define ORANGE_CLAUDIU_2 0749256822

	#define Micros2Ticks(x) ((((SysCtlClockGet()*(x))/1000)/1000))	
	#define Millis2Ticks(x) (((SysCtlClockGet()*(x))/1000) - 1)	
	//Returns the clock cycles required for the requested time in mili seconds
	/*	---	end of 	General purpose			---	*/


	/*	---					Serial debug		---	*/
	#define SERIAL_DEBUG_ACTIVE (1)  //Set Serial Debug active or inactive (for serial monitor)
	/*	---	end of 	Serial debug		---	*/


	/*	---					PIR			---	*/
	#define PIR_TRIGGERS_TO_ALARM (2) //number of PIR triggers to consider as valid alarm
	#define PIR_TRIGGERS_TIMEFRAME (10) //Timeframe for PIR triggers to consder for valid alarm
	#define PIR_STARTUP_DELAY  (5)  //number of seconds to wait befor startup
	#define PIR_READ_DELAY (1000)  //number of mili seconds to wait between PIR reads
	/*	---	end of 	PIR			---	*/


	/*	---					GSM			---	*/
	#define SMS_SEND_DELAY (10000)  //number of mili seconds to wait after sms sending
	#define SMS_READ_DELAY (1000)  //number of mili seconds to wait between SMS reads

	#define SMS_NUMBER_START_INDEX (7)
	#define SMS_NUMBER_END_INDEX  (18)
	#define SMS_DATA_START_INDEX  (48)
	#define SMS_PASSWORD (1234)  //mandatory content of every SMS command

	#define GSM_MESSAGE_SIZE (300)
	/*	---	end of 	GSM			---	*/


	/*	---					HX711			---	*/

	/*	---	end of 	HX711			---	*/


	/*	---					TEMPERATURE			---	*/
	#define OW_port1 PortE
	#define OW_portbase1 GPIO_PORTE_BASE
	#define OW_pin1 GPIO_PIN_1		//port PE1
	#define TEMPERATURE_RESOLUTION (11)	
	/*	---	end of 	TEMPERATURE			---	*/


#endif
//EOF
