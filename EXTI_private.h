/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef EXTI0_PRIVATE_H
#define EXTI0_PRIVATE_H


typedef	struct
{
	volatile	uint32_t		IMR;
	volatile	uint32_t		EMR;
	volatile	uint32_t		RTSR;
	volatile	uint32_t		FTSR;
	volatile	uint32_t		SWIER;
	volatile	uint32_t		PR;
	
}EXTI_Type;

#define	EXTI		(( EXTI_Type * )0x40010400)



#endif
