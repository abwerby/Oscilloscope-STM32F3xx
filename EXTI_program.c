/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include <stdint.h>
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#define NULL		(void * )0

static void (* EXTI0_CallBack) (void) = NULL ;
static void (* EXTI1_CallBack) (void) = NULL ;
static void (* EXTI2_CallBack) (void) = NULL ;
static void (* EXTI3_CallBack) (void) = NULL ;
static void (* EXTI4_CallBack) (void) = NULL ;
static void (* EXTI5_CallBack) (void) = NULL ;
static void (* EXTI6_CallBack) (void) = NULL ;
static void (* EXTI7_CallBack) (void) = NULL ;
static void (* EXTI8_CallBack) (void) = NULL ;
static void (* EXTI9_CallBack) (void) = NULL ;
static void (* EXTI10_CallBack) (void) = NULL ;
static void (* EXTI11_CallBack) (void) = NULL ;
static void (* EXTI12_CallBack) (void) = NULL ;
static void (* EXTI13_CallBack) (void) = NULL ;
static void (* EXTI14_CallBack) (void) = NULL ;
static void (* EXTI15_CallBack) (void) = NULL ;


void EXTI_voidEnableEXTI(uint8_t Copy_uint8_tEXTILine , uint8_t Copy_uint8_tEXTISenseMode, void (*Fptr) (void))
{	
	switch(Copy_uint8_tEXTISenseMode)
	{
		case	EXTI_RISING_EDGE		:	SET_BIT(EXTI -> RTSR , Copy_uint8_tEXTILine);	break;
		case	EXTI_FALLING_EDGE		:	SET_BIT(EXTI -> FTSR , Copy_uint8_tEXTILine);	break;
		case	EXTI_ON_CHANGE			:	SET_BIT(EXTI -> RTSR , Copy_uint8_tEXTILine);	break;
	}

	switch(Copy_uint8_tEXTILine)
	{
		case	0	:	EXTI0_CallBack = Fptr ; 	break;
		case	1	:	EXTI1_CallBack = Fptr ; 	break;
		case	2	:	EXTI2_CallBack = Fptr ; 	break;
		case	3	:	EXTI3_CallBack = Fptr ; 	break;
		case	4	:	EXTI4_CallBack = Fptr ; 	break;
		case	5	:	EXTI5_CallBack = Fptr ; 	break;
		case	6	:	EXTI6_CallBack = Fptr ; 	break;
		case	7	:	EXTI7_CallBack = Fptr ; 	break;
		case	8	:	EXTI8_CallBack = Fptr ; 	break;
		case	9	:	EXTI9_CallBack = Fptr ; 	break;
		case	10	:	EXTI10_CallBack = Fptr ; 	break;
		case	11	:	EXTI11_CallBack = Fptr ; 	break;
		case	12	:	EXTI12_CallBack = Fptr ; 	break;
		case	13	:	EXTI13_CallBack = Fptr ; 	break;
		case	14	:	EXTI14_CallBack = Fptr ; 	break;
		case	15	:	EXTI15_CallBack = Fptr ; 	break;
		
	}
	/* Enable EXTI Line */
	SET_BIT(EXTI -> IMR , Copy_uint8_tEXTILine);
}

void EXTI_voidDisableEXTI(uint8_t Copy_uint8_tEXTILine)
{
	CLR_BIT(EXTI -> IMR , Copy_uint8_tEXTILine);
}

void EXTI_voidSoftwareTrigger(uint8_t Copy_uint8_tEXTILine)
{
	SET_BIT(EXTI -> SWIER , Copy_uint8_tEXTILine);
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit  */
	SET_BIT(EXTI -> PR , 0);
}

void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	/*	Clear pending Bit  */
	SET_BIT(EXTI -> PR , 1);
}

void EXTI2_IRQHandler(void)
{
	EXTI2_CallBack();
	/*	Clear pending Bit  */
	SET_BIT(EXTI -> PR , 2);
}

void EXTI3_IRQHandler(void)
{
	EXTI3_CallBack();
	/*	Clear pending Bit  */
	SET_BIT(EXTI -> PR , 3);
}

void EXTI4_IRQHandler(void)
{
	EXTI4_CallBack();
	/*	Clear pending Bit  */
	SET_BIT(EXTI -> PR , 4);
}

void EXTI9_5_IRQHandler(void)
{
	if (GET_BIT(EXTI -> PR , 5) == 1)
	{
		EXTI5_CallBack();
		SET_BIT(EXTI -> PR , 5);
	}
	else if (GET_BIT(EXTI -> PR , 6) == 1)
	{
		EXTI6_CallBack();
		SET_BIT(EXTI -> PR , 6);
	}
	else if (GET_BIT(EXTI -> PR , 7) == 1)
	{
		EXTI7_CallBack();
		SET_BIT(EXTI -> PR , 7);
	}
	else if (GET_BIT(EXTI -> PR , 8) == 1)
	{
		EXTI8_CallBack();
		SET_BIT(EXTI -> PR , 8);
	}
	else if (GET_BIT(EXTI -> PR , 9) == 1)
	{
		EXTI9_CallBack();
		SET_BIT(EXTI -> PR , 9);
	}
	else
	{
		
	}
}

void EXTI15_10_IRQHandler(void)
{
	if (GET_BIT(EXTI -> PR , 10) == 1)
	{
		EXTI10_CallBack();
		SET_BIT(EXTI -> PR , 10);
	}
	else if (GET_BIT(EXTI -> PR , 11) == 1)
	{
		EXTI11_CallBack();
		SET_BIT(EXTI -> PR , 11);
	}
	else if (GET_BIT(EXTI -> PR , 12) == 1)
	{
		EXTI12_CallBack();
		SET_BIT(EXTI -> PR , 12);
	}
	else if (GET_BIT(EXTI -> PR , 13) == 1)
	{
		EXTI13_CallBack();
		SET_BIT(EXTI -> PR , 13);
	}
	else if (GET_BIT(EXTI -> PR , 14) == 1)
	{
		EXTI14_CallBack();
		SET_BIT(EXTI -> PR , 14);
	}
	else if (GET_BIT(EXTI -> PR , 15) == 1)
	{
		EXTI15_CallBack();
		SET_BIT(EXTI -> PR , 15);
	}
	else
	{
		
	}
}
