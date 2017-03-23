#define ALEX_GAAL1 0744424818
#define ALEX_GAAL2 0758438903
#define ORANGE_CLAUDIU_1 0751538300
#define ORANGE_CLAUDIU_2 0749256822

#define GSM_SERIAL_DEBUG_ACTIVE (1)

#if GSM_SERIAL_DEBUG_ACTIVE  //If Serial Debug is On, security functions are not used
  #undef SECURITY_FUNCTIONS
#else
  #define SECURITY_FUNCTIONS
#endif

#define PIR_A_INPUT    (2)  //Input pin for PIR A
#define PIR_B_INPUT    (3)  //Input pin for PIR B
#define WIRE_A_INPUT_1 (4)  //Bottom Wire Input pin 1 - triggered by wire cut
#define WIRE_A_INPUT_2 (5)  //Bottom Wire Input pin 2 - triggered by wire pull
#define WIRE_B_INPUT_1 (6)  //Middle Wire
#define WIRE_B_INPUT_2 (7)
#define WIRE_C_INPUT_1 (8)  //Top Wire
#define WIRE_C_INPUT_2 (9)
#define GSM_RX_Pin     (10)  //Pin to receive data from GSM module
#define GSM_TX_Pin     (11)  //Pin to transmit data to GSM module
#define GSM_Power_Pin  (12)  //Pin used to power on GSM module via software

#define STARTUP_DELAY  (60)  //number of seconds to wait befor startup
#define SMS_SEND_DELAY (5000)  //number of mili seconds to wait after sms sending
#define SMS_READ_DELAY (1000)  //number of mili seconds to wait between SMS reads
#define PIR_READ_DELAY (1000)  //number of mili seconds to wait between PIR reads

#define ULTRA_SHORT_DELAY (10)  //10ms
#define SHORT_DELAY       (50)  //50ms
#define LONG_DELAY        (100)  //100ms
#define ULTRA_LONG_DELAY  (500)  //500ms

#define SMS_NUMBER_START_INDEX (7)
#define SMS_NUMBER_END_INDEX  (18)
#define SMS_DATA_START_INDEX  (48)
#define SMS_PASSWORD (1234)  //mandatory content of every SMS command