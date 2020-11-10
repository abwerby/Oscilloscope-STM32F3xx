



#include <stdint.h>
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"
#include "DMA_interface.h"
#include "TFT_Interface.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"
#include "NVIC_interface.h"
#include "DAC_interface.h"
#include "oscilloscope.h"



uint16_t AdcArr[SAMPLES];
uint32_t SampleScaller;
float DigitalScaller;
uint16_t avg;
uint32_t P_Time;
uint32_t Freq;
uint16_t minVal;
uint16_t maxVal;


/* Inputs */
uint32_t TimeDiv; 		// in nano seconds
uint16_t VoltDiv;			// in milli volt
uint16_t V_Offest;			// in pixel unit
uint32_t dt = (18*1000)/72;

uint8_t B_Click;
int8_t E_Rotate_1;
int8_t E_Rotate_2;
int8_t E_Rotate_3;
int8_t E_Rotate_4;
uint8_t flag;

long loc_y, loc_x, prev_loc_x, prev_loc_y;

void OSC_Config()
{
	switch(B_Click)
	{
		case 0:										break;
		case 1:	flag = 1; TFT_fillRect(10,  2, 75, 21, ILI9486_DARKGREY); Change_dt(); 		 break;
		case 2:	flag = 2; TFT_fillRect(140, 2, 75, 21, ILI9486_DARKGREY); Change_VoltDiv(); break;
		case 3:	flag = 3; TFT_fillRect(260, 2, 75, 21, ILI9486_DARKGREY); Change_TimDiv();  break;
		case 4:	flag = 4; TFT_fillRect(360, 2, 95, 21, ILI9486_DARKGREY); Change_Voffest(); break;	
		default: 									break;
	}
}

void OSC_Update_Samples()
{
	ADC_Stop(ADC2);
	DMA_Channel_Disable(DMA2, 0);
	DMA2->Channel[0].CNDTR = SAMPLES;
	ADC_Start(ADC2);		
	DMA_Channel_Enable(DMA2, 0);
}

void OSC_Process_Samples()
{
	//DMA_Channel_Disable(DMA2, 0);
	minVal = find_min(AdcArr, SAMPLES);
	maxVal = find_max(AdcArr, SAMPLES);
	avg = mean(AdcArr, SAMPLES);
	P_Time = Period_Time(AdcArr, SAMPLES, avg, dt);
	Freq = GIGA/P_Time;
}

void OSC_Update_Screen_Info()
{
	TFT_SetCursor(10, 2);
	TFT_Print_String("dt: ");
	TFT_Print_Number(dt);
	TFT_Print_String("nS");
	
	TFT_SetCursor(140, 2);
	TFT_Print_Number(VoltDiv);
	TFT_Print_String("mV/div");	
	
	TFT_SetCursor(260, 2);
	TFT_Print_Number(TimeDiv/1000);
	TFT_Print_String("uS/div");

	TFT_SetCursor(360, 2);
	TFT_Print_String("v_offest: ");	
	TFT_Print_Number(V_Offest);
	
	TFT_SetCursor(10, 300);
	TFT_Print_String("f: ");
	TFT_Print_Number(Freq);
	TFT_Print_String("Hz");
	
	TFT_SetCursor(120, 300);	
	TFT_Print_String("max: ");	
	TFT_Print_Number((maxVal*3300)/MAX_DIGITAL);
	TFT_Print_String(" mV");

	TFT_SetCursor(240, 300);	
	TFT_Print_String("min: ");	
	TFT_Print_Number((minVal*3300)/MAX_DIGITAL);
	TFT_Print_String(" mV");

	TFT_SetCursor(360, 300);	
	TFT_Print_String("avg: ");	
	TFT_Print_Number((avg*3300)/MAX_DIGITAL);
	TFT_Print_String(" mV");	
}

void OSC_Draw_Samples()
{
	prev_loc_x = 12;
	prev_loc_y = map(AdcArr[0]*DigitalScaller, 0, MAX_DIGITAL, 290-V_Offest, 25);
	for (uint16_t j = 0; j < SAMPLES/SampleScaller; j++)
	{
		loc_x = map(j, 0, SAMPLES/SampleScaller, 10, 460);
		loc_y = map(AdcArr[j]*DigitalScaller, 0, MAX_DIGITAL, 290-V_Offest, 25);
		TFT_Draw_Line(prev_loc_x, prev_loc_y, loc_x, loc_y, ILI9486_RED);
		prev_loc_x = loc_x;
		prev_loc_y = loc_y;
	}
}

void OSC_Clear_Screen()
{
	for (uint16_t j = 0; j < SAMPLES/SampleScaller; j++)
	{
		loc_x = map(j, 0, SAMPLES/SampleScaller, 10, 460);
		loc_y = map(AdcArr[j]*DigitalScaller, 0, MAX_DIGITAL, 290-V_Offest, 25);
		TFT_Draw_Line(prev_loc_x, prev_loc_y, loc_x, loc_y, ILI9486_BLACK);
		prev_loc_x = loc_x;
		prev_loc_y = loc_y;
	}
	/* Redraw Net and Box */
	Net();
	TFT_fillRect(0, 2, 460, 23, ILI9486_BLACK);
	TFT_fillRect(0, 295, 480, 23, ILI9486_BLACK);
	TFT_DrawRect(10, 25, 480, 270, ILI9486_WHITE);
}

void Change_dt()
{
	uint8_t smt = map(E_Rotate_1, -100, 100, 0, 7);
	switch(smt)
	{
		case 0:	break;
		case 1: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_2CYCLES_5);    dt = (13*1000)/72; break;
		case 2: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_4CYCLES_5);    dt = (15*1000)/72; break;
		case 3: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_7CYCLES_5);    dt = (18*1000)/72; break;
		case 4: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_19CYCLES_5);   dt = (30*1000)/72; break;
		case 5: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_61CYCLES_5);   dt = (72*1000)/72; break;
		case 6: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_181CYCLES_5);  dt = (192*1000)/72; break;
		case 7: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_601CYCLES_5);  dt = (612*1000)/72; break;
		default: ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_4CYCLES_5);   dt = (15*1000)/72; break;
	}
}

void Change_TimDiv()
{
	/*
	*		SampleDiv = (Sampling_Time_of_ADC * Number_of samples) / (Number_of_HBox_In_single_screen * Each_Box_Time).
	*		SampleDiv = (333 * 4096) / (10 * TimeDiv).
	*		NOTE: ALL Time unit in nano second.
	*/
	TimeDiv = map(E_Rotate_3, -100, 100, 1, 100000);
	SampleScaller = (SAMPLES * dt) / (10 * TimeDiv);
}

void Change_VoltDiv()
{
	/*
	*		SampleDiv = (MAX_DIGITAL_Value * LSB) / (Number_of_VBox_In_single_screen * VoltDiv).
	*		SampleDiv = (1023 * 3.2) / (6 * VoltDiv).
	*		NOTE: ALL Time unit in nano second.
	*/

	VoltDiv = map(E_Rotate_2, -100, 100, 4, 1500);
	DigitalScaller = (MAX_DIGITAL*3.2) / (6 * VoltDiv);
}

void Change_Voffest()
{
	V_Offest = map(E_Rotate_4, -100, 100, 0, 100);
}


void System_Config()
{
	/* Config system CLK to PLL 72MHZ */
	RCC_voidInitSysClock();
	/* Config SYSTICK Timer to Rise Interrupt every 1ms */
	STK_voidInit(72000);
	/* Enable peripherals CLK */
	RCC_voidEnableClock(RCC_APB1, 29);
	RCC_voidEnableClock(RCC_AHB,  RCC_AHB_ADC12);
	RCC_voidEnableClock(RCC_AHB,  RCC_AHB_DMA2);
	RCC_voidEnableClock(RCC_AHB,  RCC_AHB_GPIOA);
	RCC_voidEnableClock(RCC_AHB,  RCC_AHB_GPIOB);
	RCC_voidEnableClock(RCC_AHB,  RCC_AHB_GPIOC);
	RCC_voidEnableClock(RCC_APB1, RCC_AHB_ADC34);
	RCC_voidEnableClock(RCC_APB1, RCC_APB1_TIM2);
	RCC_voidEnableClock(RCC_APB1, RCC_APB1_TIM3);
	RCC_voidEnableClock(RCC_APB2, 0);

	RCC_Set_ADC12_CLK_PRES(RCC_ADC_CLK_PRES_DIV_1);
	/********************************************************/
	
	/* init ADC ARRAY data */
	for (uint32_t i = 0; i < SAMPLES; i++)
	{
		AdcArr[i] = 0;
	}
	
	B_Click = 0;
	E_Rotate_1 = 0;
	E_Rotate_2 = 0;
	E_Rotate_3 = 0;
	E_Rotate_4 = -100;
	
  TimeDiv = 25000; 		// in nano seconds
  VoltDiv = 600;			// in milli volt
  V_Offest	= 0;			// in pixel unit
  DigitalScaller = (MAX_DIGITAL*3.2) / (6 * VoltDiv);
	SampleScaller = (SAMPLES * dt) / (10 * TimeDiv);
	
	/********************************************************/

	
	/* Config GPIO Pins */
	GPIO_Pin_Conf_t pin_confg;
	
	pin_confg.pin = PIN6;
	pin_confg.mode = GPIO_PIN_ALT_FUN_MODE;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	pin_confg.alternate = 2;
	GPIO_Init(GPIOC, &pin_confg);
	
	pin_confg.pin = PIN15;
	pin_confg.alternate = 1;
	GPIO_Init(GPIOA, &pin_confg);
	
	pin_confg.pin = PIN4;
	pin_confg.mode = GPIO_PIN_ANALOG_MODE;
	pin_confg.pull = GPIO_PIN_NO_PULL;
	GPIO_Init(GPIOC, &pin_confg);
	
	pin_confg.pin = PIN10;
	pin_confg.mode = GPIO_PIN_INPUT_MODE;
	pin_confg.pull = GPIO_PIN_PULL_UP;
	GPIO_Init(GPIOC, &pin_confg);
	
	pin_confg.pin = PIN11;
	pin_confg.mode = GPIO_PIN_INPUT_MODE;
	pin_confg.pull = GPIO_PIN_PULL_UP;
	GPIO_Init(GPIOC, &pin_confg);
	
	pin_confg.pin = PIN7;
	pin_confg.mode = GPIO_PIN_INPUT_MODE;
	pin_confg.pull = GPIO_PIN_PULL_UP;
	GPIO_Init(GPIOB, &pin_confg);
	

	/********************************************************/
	/*
	*	Config EXTI line 13, 14 to port C
	* Enable NVIC line 40.
	*/
	SYSCFG_Config_EXTI(EXTI_LINE10, SYSCFG_EXTI_GPIOC);
	SYSCFG_Config_EXTI(EXTI_LINE7, SYSCFG_EXTI_GPIOB);
	EXTI_voidEnableEXTI(EXTI_LINE10, EXTI_RISING_EDGE, ButtonISR);
	EXTI_voidEnableEXTI(EXTI_LINE7, EXTI_RISING_EDGE, EncoderISR);
	NVIC_voidInit();
	NVIC_voidEnableInterrupt(40);
	NVIC_voidEnableInterrupt(23);

	/********************************************************/
	DAC_config dac_config;
	dac_config.Buffer = DAC_BUFFER_ENABLE;
	dac_config.Channel = 2;
	dac_config.DMA_State = DAC_DMA_DISABLE;
	dac_config.Trigger_Source = DAC_SWTRIG_Event;
	dac_config.Wave = DAC_WAVE_TRIANGLE;
	dac_config.Wave_Amplitude = 0b1010;
	DAC_Init(DAC1, &dac_config);

	/* 
	*	Config Channel 5 in ADC2 to continuous mode with DMA,
	*	Data Res = 10BIT,
	*	ADC2 CLK = AHB/2 = 72MHz/2 = 36MHz
	*/
	uint8_t seq_arr[1] = {5};
	ADC_config adc_config;
	adc_config.Numbers_of_Channels = 1;
	adc_config.Channels_Sequence = seq_arr;
	adc_config.CLK_Source = ADC_CLOCK_ASYNC_DIV1;
	adc_config.Data_Resolution = ADC_DATA_RES_10;
	adc_config.DMA_State = ADC_DMA_ENABLE;
	adc_config.DMA_Mode = ADC_DMA_SCAN_DISABLE;
	adc_config.Scan_State = ADC_SCAN_ENABLE;
	ADC_Init(ADC2, &adc_config);
	ADC_Set_Channel_SMT(ADC2, 5, ADC_SAMPLETIME_4CYCLES_5);
	dt = (15*1000)/72;
	/********************************************************/
	
	/* Config DMA2 in circular mode to transfer data from ADC->DR register to 'AdcArr' address */
	DMA_config dma_config;
	dma_config.Channel_Number = 0;
	dma_config.Channel_Priority = DMA_Channel_Priority_VeryHigh;
	dma_config.Circular_Mode = DMA_Circular_Mode_OFF;
	dma_config.Data_Direction = DMA_Data_Direction_Read_From_PER;
	dma_config.Memory_Address = AdcArr;
	dma_config.Peripheral_Reg = &ADC2->DR;
	dma_config.Memory_Size = DMA_MEM_OR_PER_Size_16;
	dma_config.Peripheral_Size = DMA_MEM_OR_PER_Size_16;
	dma_config.Total_Data = SAMPLES;
	dma_config.MINC = DMA_MINC_ON;
	dma_config.PINC = DMA_PINC_OFF; 
	dma_config.MEM2MEM = DMA_MEM2MEM_OFF;
	DMA_Init(DMA2, &dma_config);
	/*******************************************************************/
	
	
	/* TFT Screen Config */
	TFT_Init();	
	TFT_Set_Rotation(TFT_LANDSCAPE);
	TFT_fillScreen(ILI9486_BLACK);

	TFT_DrawRect(10, 25, 460, 270, ILI9486_WHITE);
	Net();

	TFT_SetTextSize(1);
	TFT_SetTextColor(ILI9486_GREEN);
	/*******************************************************************/
	

}



long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint32_t mean(uint16_t * arr, uint32_t arr_size)
{
	uint32_t mean = 0;
	for (uint32_t i = 0; i < arr_size; i++)	mean += arr[i];
	return mean/arr_size;
}

uint32_t Period_Time(uint16_t * array, uint32_t arr_size, uint16_t Avg, uint32_t S_Time)
{
	uint32_t cut_Loc_1 , cut_Loc_2, counter = 0;
	uint8_t k = 0;
	uint32_t p_time = 0;
	for(uint16_t i = 1 ; i < SAMPLES ; i++)
	{
		if(array[i-1] < Avg && array[i] > Avg)
		{
			if(k == 0)
			{
				cut_Loc_1 = i ;
				k = 1 ;
			}
			else
			{
				cut_Loc_2 = i ;
				k = 0 ;
				p_time += (cut_Loc_2 - cut_Loc_1) * S_Time ;
				counter++;
			}
		}
	}
	return p_time/counter;
	 
}

void Net()
{

	for(uint16_t i = 56 ; i < 460 ; i = i+46)
	{
		TFT_DrawFastVLine(i, 26, 270, ILI9486_BLUE);
	}
	
	for(uint16_t j = 70 ; j < 270 ; j = j+45)
	{
		TFT_DrawFastHLine(11, j, 459, ILI9486_BLUE);
	}
	
	TFT_DrawFastVLine(240, 26, 270, ILI9486_WHITE);
	TFT_DrawFastHLine(11, 162, 459, ILI9486_WHITE);
}

uint16_t find_max (uint16_t * array, uint32_t arr_size)
{
	uint16_t _max = array[0];
	for (int c = 1; c < arr_size; c++)
	{
		if (array[c] > _max)	_max  = array[c];
	}
	return _max;
}



uint16_t find_min (uint16_t * array, uint32_t arr_size)
{
	uint16_t _min = array[0];
	for (int c = 1; c < arr_size; c++)
	{
		if (array[c] < _min)	_min  = array[c];
	}
	return _min;
}

void ButtonISR()
{
	// while (GPIO_Read_Pin(GPIOC, PIN10) == LOW);
	for (uint16_t i = 0; i < 1000; i++);
	B_Click++;
	if (B_Click > 4) B_Click = 0;
}

void EncoderISR()
{
	switch(flag)
	{
		case 1:
				if (GPIO_Read_Pin(GPIOC, PIN11) == GPIO_Read_Pin(GPIOB, PIN7))
				{
					E_Rotate_1++;
				}
				else
				{
					E_Rotate_1--;
				}
				if (E_Rotate_1 > 100 || E_Rotate_1 < -100) E_Rotate_1 = -100;
				break;
		case 2:
				if (GPIO_Read_Pin(GPIOC, PIN11) == GPIO_Read_Pin(GPIOB, PIN7))
				{
					E_Rotate_2++;
				}
				else
				{
					E_Rotate_2--;
				}
				if (E_Rotate_2 > 100 || E_Rotate_2 < -100) E_Rotate_2 = -100;
				break;
		case 3:
				if (GPIO_Read_Pin(GPIOC, PIN11) == GPIO_Read_Pin(GPIOB, PIN7))
				{
					E_Rotate_3++;
				}
				else
				{
					E_Rotate_3--;
				}
				if (E_Rotate_3 > 100 || E_Rotate_3 < -100) E_Rotate_3 = -100;
				break;
		case 4:
				if (GPIO_Read_Pin(GPIOC, PIN11) == GPIO_Read_Pin(GPIOB, PIN7))
				{
					E_Rotate_4++;
				}
				else
				{
					E_Rotate_4--;
				}
				if (E_Rotate_4 > 100 || E_Rotate_4 < -100) E_Rotate_4 = -100;
				break;
		default: break;		
	}

}
