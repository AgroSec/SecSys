//adc_handler.c
//Service layer

/*---------------------OS Includes--------------------*/
#include "os_core.h"

/*-------------------Configuration Includes-----------*/
#include "compile_switches.h"

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"

/*------Export interface---Self header Includes------*/
#include "adc_handler.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"

/*-------------------HW define Includes--------------*/
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

/*-------------Global Variable Definitions------------*/
extern fifo_t FifoADC_Temp;
extern fifo_t FifoADC_MxLight;
extern fifo_t FifoADC_LxLight;
extern fifo_t FifoADC_RxLight;

void ADC_Temperature_Sensor_Init(void) //Initialize microphone input
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);			//The ADC0 peripheral must be enabled for use.

	IntDisable(INT_ADC0SS3);
	
	ADCIntClear(ADC0_BASE, 3); 										//Clear interrupt flag	
	ADCIntDisable(ADC0_BASE, 3);
	ADCSequenceDisable(ADC0_BASE,3);							//Disable sequencer 3
	
	ADCSequenceConfigure(ADC0_BASE,3, /*ADC_TRIGGER_ALWAYS*/ADC_TRIGGER_PROCESSOR, 0); //Sequence 3 will do a single sample when the processor (SW) sends a signal to start the conversion
	ADCSequenceStepConfigure(ADC0_BASE,3,0, ADC_CTL_CH3 |ADC_CTL_TS| ADC_CTL_IE | ADC_CTL_END);  //Configure step 0 on sequencer 3 to channel 1, interrupt enable and end conversion when after 1 conversion
	
	ADCSequenceEnable(ADC0_BASE,3); 							//Enable sequencer 3
	ADCIntEnable(ADC0_BASE, 3); 
		
	IntPrioritySet(INT_ADC0SS3,(Int_Prio_Temp_Sens)<<5);
	IntEnable(INT_ADC0SS3);	
}

void ADC_Light_Sensor_Init(void) //Initialize microphone input
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);		//The ADC1 peripheral must be enabled for use.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);	//Enable GPIO port E
	
	GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);	// Configure PE1, PE2, PE3 as analog input
	GPIODirModeSet(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_DIR_MODE_IN);	//Set direction input for PE1, PE2, PE3
	GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_ANALOG); //Configure PUR for PE3

	IntDisable(INT_ADC1SS0);
	IntDisable(INT_ADC1SS1);
	IntDisable(INT_ADC1SS2);

	ADCIntClear(ADC1_BASE, 0); 										//Clear interrupt flag for ADC1 sequencer 0
	ADCIntDisable(ADC1_BASE, 0);									//Disable interrupts from ADC1 sequencer 0
	ADCSequenceDisable(ADC1_BASE,0);							//Disable ADC1 sequencer 0
	
	ADCIntClear(ADC1_BASE, 1); 										//Clear interrupt flag for ADC1 sequencer 1
	ADCIntDisable(ADC1_BASE, 1);									//Disable interrupts from ADC1 sequencer 1
	ADCSequenceDisable(ADC1_BASE,1);							//Disable ADC1 sequencer 1
	
	ADCIntClear(ADC1_BASE, 2); 										//Clear interrupt flag for ADC1 sequencer 2
	ADCIntDisable(ADC1_BASE, 2);									//Disable interrupts from ADC1 sequencer 2
	ADCSequenceDisable(ADC1_BASE,2);							//Disable ADC1 sequencer 2
	
	//Central light sensor ADC configuration
	ADCSequenceConfigure(ADC1_BASE,0, ADC_TRIGGER_PROCESSOR, 1); //Sequence 0 will do a single sample when the processor (SW) sends a signal to start the conversion
	ADCSequenceStepConfigure(ADC1_BASE,0,0, ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);  //Configure step 0 on sequencer 0 to channel 0, interrupt enable and end conversion when after 1 conversion
	
	//Left light sensor ADC configuration
	ADCSequenceConfigure(ADC1_BASE,2, ADC_TRIGGER_PROCESSOR, 2); //Sequence 2 will do a single sample when the processor (SW) sends a signal to start the conversion
	ADCSequenceStepConfigure(ADC1_BASE,2,0, ADC_CTL_CH2 | ADC_CTL_IE | ADC_CTL_END);  //Configure step 0 on sequencer 3 to channel 0, interrupt enable and end conversion when after 1 conversion
	
	//Right light sensor ADC configuration	
	ADCSequenceConfigure(ADC1_BASE,1, ADC_TRIGGER_PROCESSOR, 2); //Sequence 1 will do a single sample when the processor (SW) sends a signal to start the conversion
	ADCSequenceStepConfigure(ADC1_BASE,1,0, ADC_CTL_CH1 | ADC_CTL_IE | ADC_CTL_END);  //Configure step 0 on sequencer 3 to channel 0, interrupt enable and end conversion when after 1 conversion

	ADCSequenceEnable(ADC1_BASE,0); 							//Enable ADC1 sequencer 0
	ADCSequenceEnable(ADC1_BASE,1); 							//Enable ADC1 sequencer 2
	ADCSequenceEnable(ADC1_BASE,2); 							//Enable ADC1 sequencer 3
	
	ADCIntEnable(ADC1_BASE, 0); 								//Enable interrupts from ADC1 sequencer 0
	ADCIntEnable(ADC1_BASE, 1); 								//Enable interrupts from ADC1 sequencer 2
	ADCIntEnable(ADC1_BASE, 2); 								//Enable interrupts from ADC1 sequencer 3	
	
	IntPrioritySet(INT_ADC1SS0,(Int_Prio_Light_Sens)<<5);	
	IntPrioritySet(INT_ADC1SS1,(Int_Prio_Light_Sens)<<5);
	IntPrioritySet(INT_ADC1SS2,(Int_Prio_Light_Sens)<<5);
	
	IntEnable(INT_ADC1SS0);												//Enable interrupts from ADC1 sequencer 0
	IntEnable(INT_ADC1SS1);												//Enable interrupts from ADC1 sequencer 2
	IntEnable(INT_ADC1SS2);												//Enable interrupts from ADC1 sequencer 3
}
/*
The sample sequencers are configured with  ADCSequenceConfigure() and ADCSequenceStep-
Configure(). They are enabled and disabled with ADCSequenceEnable() and ADCSequenceDisable().
The captured data is obtained with ADCSequenceDataGet(). Sample sequencer FIFO
overflow and underflow is managed with ADCSequenceOverflow(), ADCSequenceOverflowClear(),
ADCSequenceUnderflow(), and ADCSequenceUnderflowClear().

Hardware oversampling of the ADC is controlled with ADCHardwareOversampleConfigure(). Software
oversampling of the ADC is controlled with ADCSoftwareOversampleConfigure(), ADCSoftwareOversampleStepConfigure(),
and ADCSoftwareOversampleDataGet().

The processor trigger is generated with ADCProcessorTrigger().

The interrupt handler for the ADC sample sequencer interrupts are managed with ADCIntRegister()
and ADCIntUnregister(). The sample sequencer interrupt sources are managed with ADCIntDisable(),
ADCIntEnable(), ADCIntStatus(), and ADCIntClear().
*/

void ADC0Seq3_Handler(void)		//ADC0 Seq3 ISR
{
	uint32_t digital_value;
	uint32_t temperature;
	uint32_t analog_voltage;
	
	if(ADCIntStatus(ADC0_BASE, 3, false))
	{
		ADCIntClear(ADC0_BASE, 3); 										//Clear interrupt flag
		ADCSequenceDataGet(ADC0_BASE, 3, &digital_value);	
		temperature = (147.5 - ((75 * (ADC_Ref_Voltage) * digital_value) / 4096));
		analog_voltage = ((digital_value * ADC_Ref_Voltage)/4096)*1000;
		OS_FIFO_Put(&FifoADC_Temp,temperature);		

		/*
		The internal temperature sensor converts a temperature measurement into a voltage. This voltage
		value, VTSENS, is given by the following equation (where TEMP is the temperature in °C):
		VTSENS = 2.7 - ((TEMP + 55) / 75)
		The temperature sensor reading can be sampled in a sample sequence by setting the TSn bit in
		the ADCSSCTLn register. The temperature reading from the temperature sensor can also be given
		as a function of the ADC value. The following formula calculates temperature (TEMP in ?) based
		on the ADC reading (ADCCODE, given as an unsigned decimal number from 0 to 4095) and the
		maximum ADC voltage range (VREFP - VREFN):
		TEMP = 147.5 - ((75 * (VREFP - VREFN) × ADCCODE) / 4096)
		*/
	}
}

void ADC1Seq0_Handler(void)		//ADC1 Seq0 ISR for MX light sensor
{
	uint32_t Light;
	if(ADCIntStatus(ADC1_BASE, 0, false))
	{
		ADCIntClear(ADC1_BASE, 0);  //Clear interrupt flag
		ADCSequenceDataGet(ADC1_BASE, 0, &Light);
		OS_FIFO_Put(&FifoADC_MxLight,Light);
	}
}

void ADC1Seq1_Handler(void)		//ADC1 Seq1 ISR for RX light sensor
{
	uint32_t Light;
	if(ADCIntStatus(ADC1_BASE, 1, false))
	{
		ADCIntClear(ADC1_BASE, 1);  //Clear interrupt flag
		ADCSequenceDataGet(ADC1_BASE, 1, &Light);		
		OS_FIFO_Put(&FifoADC_RxLight,Light);
	}
}

void ADC1Seq2_Handler(void)		//ADC1 Seq2 ISR for LX light sensor
{
	uint32_t Light;
	if(ADCIntStatus(ADC1_BASE, 2, false))
	{
		ADCIntClear(ADC1_BASE, 2);  //Clear interrupt flag
		ADCSequenceDataGet(ADC1_BASE, 2, &Light);		
		OS_FIFO_Put(&FifoADC_LxLight,Light);
	}
}
