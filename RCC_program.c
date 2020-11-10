/*********************************************************************************/
/* Author    : Ahmed Atia                                                        */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#include "stdint.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	FLASH_ACR |= (RCC_FLASH_LATENCY << 0);
	#if	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;
		
	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000;
	
	#elif   RCC_CLOCK_TYPE == RCC_PLL
		RCC_CFGR |= (RCC_PLL_INPUT << 15);
		RCC_CFGR |= (RCC_PLL_MUL_VAL << 18);
		SET_BIT(RCC_CFGR, 1);
		SET_BIT(RCC_CR, 24);
	#else
		#error("You chosed Wrong Clock type")
	#endif
	/* APB1 RREDIV */
	RCC_CFGR |= (4 << 8);
}



void RCC_voidEnableClock(uint8_t Copy_uint8_tBusId, uint8_t Copy_uint8_tPerId)
{
	if (Copy_uint8_tPerId <= 31)
	{
		switch (Copy_uint8_tBusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_uint8_tPerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_uint8_tPerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_uint8_tPerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}


void RCC_voidDisableClock(uint8_t Copy_uint8_tBusId, uint8_t Copy_uint8_tPerId)
{
	if (Copy_uint8_tPerId <= 31)
	{
		switch (Copy_uint8_tBusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_uint8_tPerId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_uint8_tPerId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_uint8_tPerId);   break;
		}
	}
	else
	{
		/* Return Error */
	}

}


uint8_t RCC_uint8_tGetClock(void)
{

	if (GET_BIT(RCC_CFGR, 2) == 0 && GET_BIT(RCC_CFGR, 3) == 0)
	{
		return RCC_HSI_CLK;
	}
	else if (GET_BIT(RCC_CFGR, 2) == 1 && GET_BIT(RCC_CFGR, 3) == 0)
	{
		return RCC_HSE_CLK;
	}
	else if (GET_BIT(RCC_CFGR, 2) == 0 && GET_BIT(RCC_CFGR, 3) == 1)
	{
		return RCC_PLL_CLK;
	}
	else
	{
		/* Error */
	}

}

void RCC_Set_ADC12_CLK_PRES(uint8_t pres)
{
	RCC_CFGR2 |= (pres << 4);
}

void RCC_Set_ADC34_CLK_PRES(uint8_t pres)
{
	RCC_CFGR2 |= (pres << 9);
}

// void RCC_voidResetClock(uint8_t Copy_uint8_tBusId, uint8_t Copy_uint8_tPerId)


