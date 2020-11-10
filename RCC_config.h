/*********************************************************************************/
/* Author    : Ahmed Assaf                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H



/* Options for CLK type:  
*    RCC_HSE_CRYSTAL
*    RCC_HSE_RC
*    RCC_HSI
*    RCC_PLL			   
*/
#define RCC_CLOCK_TYPE    RCC_PLL


/* Options:
    RCC_PLL_IN_HSI_DIV_2
    RCC_PLL_IN_HSI_DIV_1
    RCC_PLL_IN_HSE      
*/
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT     RCC_PLL_IN_HSI_DIV_1
#endif


/* Note: Select value only if you have PLL as input clock source */
/* Options: 2 to 16
	RCC_PLL_CLK_MUL_2     
	RCC_PLL_CLK_MUL_3     
	RCC_PLL_CLK_MUL_4      
	RCC_PLL_CLK_MUL_5      
	RCC_PLL_CLK_MUL_6     
	RCC_PLL_CLK_MUL_7       
	RCC_PLL_CLK_MUL_8       
	RCC_PLL_CLK_MUL_9       
	RCC_PLL_CLK_MUL_10    
	RCC_PLL_CLK_MUL_11       
	RCC_PLL_CLK_MUL_12      
	RCC_PLL_CLK_MUL_13      
	RCC_PLL_CLK_MUL_14       
	RCC_PLL_CLK_MUL_15       
	RCC_PLL_CLK_MUL_16    
*/

#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_MUL_VAL   RCC_PLL_CLK_MUL_9
#endif

/* 
FLASH Latency config:
	RCC_FLASH_ZERO_WAIT_STATE		
 	RCC_FLASH_ONE_WAIT_STATE		
 	RCC_FLASH_TWO_WAIT_STATE		

*/

#define RCC_FLASH_LATENCY		RCC_FLASH_TWO_WAIT_STATE

#endif

