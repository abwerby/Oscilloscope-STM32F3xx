/*********************************************************************************/
/* Author    : Abdelrhman werby                                                      */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/

#include <stdint.h>
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_Init(ADC_TypeDef * ADCx, ADC_config * adc_config)
{

	/* Select CLK for ADC */
	if(ADCx == ADC1 || ADCx == ADC2)
	{
		ADC12_COMMON->CCR |= (adc_config->CLK_Source << 16);
	}
	else if (ADCx == ADC3 || ADCx == ADC4)
	{
		ADC34_COMMON->CCR |= (adc_config->CLK_Source << 16);
	}

	/* Config DMA */
	ADCx->CFGR |= (adc_config->DMA_State << 0);
	ADCx->CFGR |= (adc_config->DMA_Mode << 1);

	/* Config Scan state */
	ADCx->CFGR |= (adc_config->Scan_State << 13);

	/* Select the data resolution of the conversion */
  ADCx->CFGR |= (adc_config->Data_Resolution << 3);
	
	/* OVRRUN MODE */
	SET_BIT(ADCx->CFGR, 12);
	
	/* Config channels sequence */
	if (adc_config->Numbers_of_Channels > 1)
	{
		ADCx->SQR1 |= ((adc_config->Numbers_of_Channels - 1) << 0);
		for (uint8_t i = 1; i <= adc_config->Numbers_of_Channels; i++)
		{
			/* For Rank 1 to 4U */
			if (i < 5)
			{
				ADCx->SQR1 |= ADC_SQR1_RK(adc_config->Channels_Sequence[i-1], i);
			}
			/* For Rank 5 to 9U */
			else if (i < 10)
			{
				ADCx->SQR2 |= ADC_SQR2_RK(adc_config->Channels_Sequence[i-1], i);
			}
			/* For Rank 10 to 14U */
			else if (i< 15)
			{
				ADCx->SQR3 |= ADC_SQR3_RK(adc_config->Channels_Sequence[i-1], i);
			}
			/* For Rank 15 to 16U */
			else
			{   
				ADCx->SQR4 |= ADC_SQR4_RK(adc_config->Channels_Sequence[i-1], i);
			}
		}
    
	}
	else
	{
		ADCx->SQR1 |= (adc_config->Channels_Sequence[0] << 6);
	}
	
	/* Enable ADC */
	SET_BIT(ADCx->CR, 0);
	while(GET_BIT(ADCx->ISR, 0) == 0);

}

void ADC_Deinit(ADC_TypeDef * ADCx)
{
	/* REset CLK for ADC */
	if(ADCx == ADC1 || ADCx == ADC2)
	{
		ADC12_COMMON->CCR = 0x000000000;
	}
	else if (ADCx == ADC3 || ADCx == ADC4)
	{
		ADC34_COMMON->CCR = 0x000000000;
	}

	/* Reset Registers */
	ADCx->CFGR = 0x000000000;
	ADCx->SQR1 = 0x000000000;
	ADCx->SQR2 = 0x000000000;
	ADCx->SQR3 = 0x000000000;
	ADCx->SQR4 = 0x000000000;

	/* STOP ADC */
    SET_BIT(ADCx->CR, 4);
    SET_BIT(ADCx->CR, 1);
}


uint16_t ADC_Read(ADC_TypeDef * ADCx)
{
	SET_BIT(ADCx->CR, 2);
	while(GET_BIT(ADCx->ISR, 3) == 0);
	return ADCx->DR;
}


void ADC_Start(ADC_TypeDef * ADCx)
{
	SET_BIT(ADCx->CR, 2);
}


void ADC_Stop(ADC_TypeDef * ADCx)
{
	CLR_BIT(ADCx->CR, 4);
}

void ADC_Set_Channel_SMT(ADC_TypeDef * ADCx, uint8_t ChannelNum, uint8_t SampleTime)
{
	if (ChannelNum < 10)
	{
		ADCx->SMPR1 |= ADC_SMPR1(SampleTime, ChannelNum);
	}
	else if (ChannelNum < 19)
	{
		ADCx->SMPR2 |= ADC_SMPR2(SampleTime, ChannelNum);
	}
	else
	{
		// Error handler
	}
}

