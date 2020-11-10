

#include <stdint.h>
#include "STK_interface.h"
#include "ADC_interface.h"
#include "TIM2.h"
#include "DAC_interface.h"
#include "oscilloscope.h"



int main(void)
{

	/* Config all periraphls */
	System_Config();

	/* Test signal */
	DAC_Soft_Write(DAC1, 2, 4000);
	TIM_PWM(TIM2, CLK, 400000, 50);

		
	/* Start ADC2 cycle Conversin */
	ADC_Start(ADC2);
	uint16_t f = 0;
	while(1)
	{
		/* Inputs Config */
		OSC_Config();
		
		/* Update SAMPLES */
		OSC_Update_Samples();
		
		/* Process the SAMPLES */
		OSC_Process_Samples();
		
		/* Update screen inforamtion */
		OSC_Update_Screen_Info();
		
		/* Draw Signal */
		OSC_Draw_Samples();
		
		STK_voidDelayMs(100);
		
		/* Clear Signal */
		OSC_Clear_Screen();
	}
	
	return 0;
}

