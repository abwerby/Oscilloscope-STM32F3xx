/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include <stdint.h>
#include "BIT_MATH.h"
#include "STK_private.h"
#include "STK_config.h"
#include "STK_interface.h"

/* Variable to store millisecond ticks */
volatile uint32_t msTicks = 0;                             

#define NULL ((void *)0)
void (* STK_CallBack) (void) = NULL;



void STK_voidInit(uint32_t Copy_uint32_tTicks)
{
    #if SYSTICK_STATE  == STK_ENABLE
        /* Load ticks value */
        STK_LOAD = Copy_uint32_tTicks - 1;
        /* Clear current value */
        STK_VAL = 0;

        SET_BIT(STK_CTRL, 0);
        #if SYSTICK_INTERRUPT == STK_INT_ENABLE
            SET_BIT(STK_CTRL, 1);
        #endif
        #if SYSTICK_CLK_SOURCE == STK_AHB
            SET_BIT(STK_CTRL, 2);
        #elif SYSTICK_CLK_SOURCE == STK_AHB_8
            CLR_BIT(STK_CTRL, 2);
        #endif
    #endif
}


void STK_voidDelayMs(uint32_t t)
{
    uint32_t start, end;
    start = STK_uint32_t_millis();
    end = start + t;
    if (start < end)
     { 
        while ((STK_uint32_t_millis() >= start) && (STK_uint32_t_millis() < end));
    } 
    else 
    { 
        while ((STK_uint32_t_millis() >= start) || (STK_uint32_t_millis() < end));
    }
}


uint32_t STK_uint32_t_millis(void)
{
    return msTicks;
}

void STK_voidStop(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK_CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}


void STK_Set_CallBack(void (* Fptr) (void))
{
	STK_CallBack = Fptr;
}

/* SysTick interrupt Handler. */
void SysTick_Handler(void)  
{
	msTicks++;
	if (STK_CallBack != NULL)
	{
			STK_CallBack();
	}
}

