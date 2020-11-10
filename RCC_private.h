/*********************************************************************************/
/* Author    :                                                        */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define BASE_ADDRESS    0x40021000

/* Register Definitions */
#define RCC_CR         *((uint32_t*)BASE_ADDRESS)
#define RCC_CFGR       *((uint32_t*)(BASE_ADDRESS + 0x04))
#define RCC_CIR        *((uint32_t*)(BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR   *((uint32_t*)(BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR   *((uint32_t*)(BASE_ADDRESS + 0x10))
#define RCC_AHBENR     *((uint32_t*)(BASE_ADDRESS + 0x14))
#define RCC_APB2ENR    *((uint32_t*)(BASE_ADDRESS + 0x18))
#define RCC_APB1ENR    *((uint32_t*)(BASE_ADDRESS + 0x1C))
#define RCC_BDCR       *((uint32_t*)(BASE_ADDRESS + 0x20))
#define RCC_CSR        *((uint32_t*)(BASE_ADDRESS + 0x24))
#define RCC_AHBRSTR    *((uint32_t*)(BASE_ADDRESS + 0x28))
#define RCC_CFGR2      *((uint32_t*)(BASE_ADDRESS + 0x2C))
#define RCC_CFGR3      *((uint32_t*)(BASE_ADDRESS + 0x30))

#define	FLASH_ACR			*((uint32_t*)(0x40022000))

/* Clock Types */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSI_DIV_1  1
#define RCC_PLL_IN_HSE        2

/* PLL MUL */
#define RCC_PLL_CLK_MUL_2     0
#define RCC_PLL_CLK_MUL_3     1 
#define RCC_PLL_CLK_MUL_4     2  
#define RCC_PLL_CLK_MUL_5     3  
#define RCC_PLL_CLK_MUL_6     4  
#define RCC_PLL_CLK_MUL_7     5  
#define RCC_PLL_CLK_MUL_8     6  
#define RCC_PLL_CLK_MUL_9     7  
#define RCC_PLL_CLK_MUL_10    8   
#define RCC_PLL_CLK_MUL_11    9   
#define RCC_PLL_CLK_MUL_12    10  
#define RCC_PLL_CLK_MUL_13    11  
#define RCC_PLL_CLK_MUL_14    12   
#define RCC_PLL_CLK_MUL_15    13   
#define RCC_PLL_CLK_MUL_16    14  
       

/* FLASH Latency*/
#define 	RCC_FLASH_ZERO_WAIT_STATE		0
#define 	RCC_FLASH_ONE_WAIT_STATE		1
#define 	RCC_FLASH_TWO_WAIT_STATE		2










#endif