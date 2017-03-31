//This file will contain all the preprocessor commands to configure the SW before compilation

#ifndef CONFIG
#define CONFIG

#define DIGI_ALEX_GAAL1 0744424818
#define ORANGE_ALEX_GAAL2 0758438903
#define ORANGE_CLAUDIU_1 0751538300
#define ORANGE_CLAUDIU_2 0749256822

#define GSM_SERIAL_DEBUG_ACTIVE (0)  //Serial Debug is not implemented to TM4c frame
#if GSM_SERIAL_DEBUG_ACTIVE  //If Serial Debug is On, security functions are not used
  #undef SECURITY_FUNCTIONS
#else
  #define SECURITY_FUNCTIONS
#endif

#define Millis2Ticks(x) (((SysCtlClockGet() / 1000) * (x)) - 1)	
//Returns the clock cycles required for the requested time in mili seconds

#define PIR_STARTUP_DELAY  (5)  //number of seconds to wait befor startup
#define SMS_SEND_DELAY (10000)  //number of mili seconds to wait after sms sending
#define SMS_READ_DELAY (1000)  //number of mili seconds to wait between SMS reads
#define PIR_READ_DELAY (1000)  //number of mili seconds to wait between PIR reads

#define SMS_NUMBER_START_INDEX (7)
#define SMS_NUMBER_END_INDEX  (18)
#define SMS_DATA_START_INDEX  (48)
#define SMS_PASSWORD (1234)  //mandatory content of every SMS command

#endif
//EOF
