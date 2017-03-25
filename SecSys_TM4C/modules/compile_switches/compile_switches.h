//This file will contain all the preprocessor commands to configure the SW before compilation

#ifndef COMP_SW
#define COMP_SW

#define SysTick_Enabled (0x07)		//0x00 - disable; 0x05 - SysTick enabled W/O Interrupts;	0x07 - SysTick enable with Interrupts (For periodic interrupts)
#define Off (0)
#define On 	(1)
#define False (0)
#define True 	(1)
#define Full_SW			(On)		//Use "On" to have the full functionality of the SW, Use "Off" only for specific module development
#define UART_Debug	(Off)		//Use On to have UART Printing for debugging available
#define Accelerometer_CS_GPIO (Off)	//Use On if GPIO pin PE0 controls CS, Off if CS is hardwired

/*----------------On board LED definitions-------------*/
#define Red_LED (0x02)
#define Blue_LED (0x04) //PF2
#define Green_LED (0x08) //PF3
#define Yellow_LED (0x0A)
#define Cyan_LED (0x0C)
#define White_LED (0x0E)

/*-------------Motion calculation config--------------*/
#define Min_Delta_LS (120)			//configure half of minimum difference between LS, to take into account as different LS
#define Max_Speed_Delay (100)		//configure nr of 100ms to cruise before go ahead with max speed
#define Mx_LS_Go_BckW (Off)

/*-------------Motor PWM duty cycle config------------*/
#define Outer_Wheel_DS (70)			//PWM duty cycle for outer wheel at cornering
#define Inner_Wheel_DS (0)			//PWM duty cycle for inner wheel at cornering
#define Stop_Wheel_DS (0)				//PWM duty cycle for stoped wheel
#define Cruise_Wheel_DS (60)		//PWM duty cycle for cruising speed
#define Max_Speed_Wheel_DS (95)	//PWM duty cycle for cruising speed
#define Revers_Wheel_DS (50)		//PWM duty cycle for reverse

/*------------Temperature sensor config--------------*/
#define ADC_VREFP (3.3)  //3.3 Volt
#define ADC_VREFN (0)  //0 Volt
#define ADC_Ref_Voltage (ADC_VREFP - ADC_VREFN)	//33 represents 3v3, 50 represents 5v

/*---------------------LCD config--------------------*/
// Maximum dimensions of the LCD, although the pixels are numbered from zero to (MAX-1).  
//Address may automatically be incremented after each transmission.
#define LCD_Max_X 		(84)
#define LCD_Max_Y 		(48)
#define	LCD_Mode 			(0x0C)		// 0x0C -for normal mode, 0x0D - for inverse mode
#define LCD_Contrast	(0xBA) 		//LCD display contrast
/* try 
0xB1 (for 3.3V red SparkFun), 
0xB8 (for 3.3V blue SparkFun), 
0xBF if your display is too dark,
0x80 to 0xFF if experimenting,
0xBA optimal value so far - Gaal Alexandru */

/*-------------------Interrupt priorities-------------*/
#define Int_Prio_Timer0A_50ms		(0x00) 	//Priority 0 = "001"0.0000
#define Int_Prio_WTimer0A_1s		(0x01) 	//Priority 1 = "001"0.0000
#define Int_Prio_GPIO_PF_LightS	(0x02)	//Priority 2 = "010"0.0000
#define Int_Prio_Comp_Mic				(0x03)	//Priority 3 = "011"0.0000
#define Int_Prio_Temp_Sens			(0x07)	//Priority 7 = "111"0.0000
#define Int_Prio_Light_Sens			(0x01)	//Priority 1 = "001"0.0000
#define Int_Prio_Acc_Sens				(0x02)	//Priority 2 = "010"0.0000

/*-------------------Accelerometer config-------------*/
#define Acc_Slave_Adress			(0x1D)//MMA 7455 accelerometer adress is 0x1D, see datasheet page 23: $0D: I2C Device Address
#define Master_Rx_Slave_Tx		(1)		//Configures master to receive data from the slave
#define Master_Tx_Slave_Rx		(0)		//Configures master to send data to the slave
#define I2C_Rate_100kbps			(0)		//Configure I2C transfer rate to normal mode 100 kbps
#define Acc_X8bit_Reg_Adress	(0x06)//MMA 74755 accelerometer X acc 8 bit output
#define Acc_Y8bit_Reg_Adress	(0x07)//MMA 74755 accelerometer Y acc 8 bit output
#define Acc_Z8bit_Reg_Adress	(0x08)//MMA 74755 accelerometer Z acc 8 bit output
#endif
//EOF
