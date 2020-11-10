#include "stdint.h"
#include "TIM2.h"
#include "BIT_MATH.h"
#include "math.h"


void TIM_Init_IT(TIM_TypeDef * TIMx, uint32_t ms, uint32_t clk, uint16_t pre)
{
	TIMx->PSC = pre - 1 ;     // devide CLK by pre. 
	TIMx->ARR = ((uint64_t)ms * clk)/(pre * 1000)  - 1 ;    // count up to this value.
	TIMx->CNT = 0;
	TIMx->CR1 = 1;
	SET_BIT(TIMx->DIER, 0); // update enterrupt enable

}

void TIM_Init_OC(TIM_TypeDef * TIMx, uint32_t ms, uint32_t clk, uint16_t pre)
{
	TIMx->PSC = pre - 1 ;     															// devide CLK by pre. 
	TIMx->ARR = ((uint64_t)ms * clk)/(pre * 1000)  - 1 ;    // count up to this value.
	SET_BIT(TIMx->CCMR1, 4);  															// config channel 1
	SET_BIT(TIMx->CCMR1, 5); 																// config channel 1
	TIMx->CCR1 = 0;																					// set match value
	SET_BIT(TIMx->CCER, 0); 																//enable channel 1
	TIMx->CNT = 0; 									 												// clear timer counter
	TIMx->CR1 = 1;									 												// enable TIM
}

void TIM_Init_IC(TIM_TypeDef * TIMx, uint16_t pre)
{
	TIMx->PSC = pre - 1;     															  // devide CLK by pre. 
	SET_BIT(TIMx->CCMR1, 0);  															// config channel 1 to ICU T1
	CLR_BIT(TIMx->CCMR1, 1); 																// config channel 1	to ICU T1
	SET_BIT(TIMx->CCER, 0); 																//enable channel 1
	CLR_BIT(TIMx->CCER, 1); 																// config ICU ro rising edge
	CLR_BIT(TIMx->CCER, 3); 																// config ICU ro rising edge
	TIMx->CR1 = 1;									 												// enable TIM
}

float TIM_Freq_IC(TIM_TypeDef * TIMx, uint32_t clk, uint16_t pre)
{
	uint32_t current_value = 0;
	uint32_t last_value = 0;
	int32_t period = 0;
	float freq = 0;
	
	for(int i = 0; i < 2; i++)
	{
		while(GET_BIT(TIMx->SR, 1) == 0);
		
		current_value = TIMx->CCR1;
		period = current_value - last_value;
		if(period < 0)
		{
			period = pow(2, 32) + period; 						// NOTE: pow(2, TIM_MAX)
		}
		freq = ((float)clk/pre)/period;
		last_value = current_value;
		
	}

	return freq;
}

void TIM_PWM(TIM_TypeDef * TIMx, uint32_t sys_clk, uint32_t pwm_freq, uint32_t pres)
{
	TIMx->PSC = 1 - 1;     															// devide CLK by pre. 
	TIMx->ARR = sys_clk / pwm_freq - 1;
	SET_BIT(TIMx->CCMR1, 5);  															// config channel 1 to PWM
	SET_BIT(TIMx->CCMR1, 6); 																// config channel 1 to PWM
	SET_BIT(TIMx->CCER, 0); 																//enable channel 1 
	TIMx->CCR1 = (((sys_clk / pwm_freq - 1) + 1) * pres) / 100 - 1;																	// set match value
	TIMx->CNT = 0; 									 												// clear timer counter
	TIMx->CR1 = 1;
	
}