//custom_types.h
#ifndef CST_TYPE
#define CST_TYPE
/*-------------------Type Defines--------------------*/
typedef struct mtr_prm_st
{
	char right_motor_DC;
	char left_motor_DC;
	char motor_direction;		//0 - stop, 1 - forward left, 2 - forward right, 3 - forward straight, 4 - backward
} motor_parameters_st;

typedef enum LCD_typeOfWrite
{
  COMMAND,                              //0, the transmission is an LCD command
  DATA                                  //1, the transmission is data
} LCD_typeOfWrite_en;

// The Data/Command pin must be valid when the eighth bit is
// sent.  The SSI module has hardware input and output FIFOs
// that are 8 locations deep.  Based on the observation that
// the LCD interface tends to send a few commands and then a
// lot of data, the FIFOs are not used when writing
// commands, and they are used when writing data.  This
// ensures that the Data/Command pin status matches the byte
// that is actually being transmitted.
// The write command operation waits until all data has been
// sent, configures the Data/Command pin for commands, sends
// the command, and then waits for the transmission to
// finish.
// The write data operation waits until there is room in the
// transmit FIFO, configures the Data/Command pin for data,
// and then adds the data to the transmit FIFO.

typedef enum Motor_Mode
{
  IN_IN,
  PHASE_ENABLE
} Motor_Mode_en;

typedef enum Motor_Direction
{
  FWD,
  RWD
} Motor_Direction_en;


typedef enum Led_State
{
  Right_Feedback_Off,
	Right_Feedback_On,
	Left_Feedback_Off,
	Left_Feedback_On,
	Center_Feedback_Off,
	Center_Feedback_On
} Led_State_en;

#endif
//EOF
