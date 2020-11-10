/**********************************************************/
/* Author    : Ahmed Assaf                                */
/* Date      : 19 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#include <stdint.h>
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidInit(void)
{
    #define SCB_AIRCR  *((uint32_t*)0xE000ED0C)
		SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}


void NVIC_voidSetPriority(uint8_t Copy_PeripheralIdx, uint8_t Copy_uint8_tPriority)
{
	if (Copy_PeripheralIdx < 74)
	{
		NVIC_IPR[Copy_PeripheralIdx] = Copy_uint8_tPriority;
	}

	else
	{
		/* Report Error */
	}
}

void NVIC_voidEnableInterrupt (uint8_t Copy_uint8_tIntNumber)
{
	if ( Copy_uint8_tIntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 63)
	{
		Copy_uint8_tIntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 127)
	{
		Copy_uint8_tIntNumber -= 64;
		NVIC_ISER2 = (1 << Copy_uint8_tIntNumber);
	}
	else
	{
		/* Return Error */
	}
	
}



void NVIC_voidDisableInterrupt (uint8_t Copy_uint8_tIntNumber)
{
	if ( Copy_uint8_tIntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 63)
	{
		Copy_uint8_tIntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 127)
	{
		Copy_uint8_tIntNumber -= 64;
		NVIC_ICER2 = (1 << Copy_uint8_tIntNumber);
	}
	else
	{
		/* Return Error */
	}
	
}


void NVIC_voidSetPendingFlag(uint8_t Copy_uint8_tIntNumber)
{
	if ( Copy_uint8_tIntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 63)
	{
		Copy_uint8_tIntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 127)
	{
		Copy_uint8_tIntNumber -= 64;
		NVIC_ISPR2 = (1 << Copy_uint8_tIntNumber);
	}
	else
	{
		/* Return Error */
	}
	
}

void NVIC_voidClearPendingFlag(uint8_t Copy_uint8_tIntNumber)
{
	if ( Copy_uint8_tIntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 63)
	{
		Copy_uint8_tIntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 127)
	{
		Copy_uint8_tIntNumber -= 64;
		NVIC_ICPR2 = (1 << Copy_uint8_tIntNumber);
	}
	else
	{
		/* Return Error */
	}
	
}



uint8_t MNVIC_uint8_tGetActiveFlag(uint8_t Copy_uint8_tIntNumber)
{
	uint8_t Local_uint8_tResult;
	
	if ( Copy_uint8_tIntNumber <= 31)
	{
		Local_uint8_tResult = GET_BIT(NVIC_IABR0, Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 63)
	{
		Copy_uint8_tIntNumber -= 32;
		Local_uint8_tResult = GET_BIT(NVIC_IABR1, Copy_uint8_tIntNumber);
	}
	else if (  Copy_uint8_tIntNumber <= 127)
	{
		Copy_uint8_tIntNumber -= 64;
		Local_uint8_tResult = GET_BIT(NVIC_IABR2, Copy_uint8_tIntNumber);
	}
	else
	{
		/* Return Error */
	}
	
	return Local_uint8_tResult;
	
}


