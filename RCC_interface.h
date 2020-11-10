/*********************************************************************************/
/* Author    : Ahmed Assaf                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

#define RCC_HSI_CLK      0 
#define RCC_HSE_CLK      1
#define RCC_PLL_CLK      2

#define RCC_AHB_DMA1       0 
#define RCC_AHB_DMA2       1 
#define RCC_AHB_GPIOA      17 
#define RCC_AHB_GPIOB      18 
#define RCC_AHB_GPIOC      19 
#define RCC_AHB_GPIOD      20 
#define RCC_AHB_GPIOH      16 
#define RCC_AHB_GPIOE      21
#define RCC_AHB_ADC12      28 
#define RCC_AHB_ADC34      29

#define RCC_APB1_TIM2      0 
#define RCC_APB1_TIM3      1 
#define RCC_APB1_TIM4      2

#define RCC_ADC_CLK_PRES_DIV_1			16	
#define RCC_ADC_CLK_PRES_DIV_2			17		
#define RCC_ADC_CLK_PRES_DIV_4			18		
#define RCC_ADC_CLK_PRES_DIV_6			19		
#define RCC_ADC_CLK_PRES_DIV_8			20		
#define RCC_ADC_CLK_PRES_DIV_10			21		
#define RCC_ADC_CLK_PRES_DIV_12			22		
#define RCC_ADC_CLK_PRES_DIV_16			23		
#define RCC_ADC_CLK_PRES_DIV_32			24		
#define RCC_ADC_CLK_PRES_DIV_64			25		
#define RCC_ADC_CLK_PRES_DIV_128		26		
#define RCC_ADC_CLK_PRES_DIV_256		27		


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(uint8_t Copy_uint8_tBusId, uint8_t Copy_uint8_tPerId);
void RCC_voidDisableClock(uint8_t Copy_uint8_tBusId, uint8_t Copy_uint8_tPerId);
uint8_t RCC_uint8_tGetClock(void);
void RCC_Set_ADC12_CLK_PRES(uint8_t pres);
void RCC_Set_ADC34_CLK_PRES(uint8_t pres);


#endif

