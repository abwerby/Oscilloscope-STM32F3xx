/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef EXTI0_INTERFACE_H
#define EXTI0_INTERFACE_H

void EXTI_voidEnableEXTI(uint8_t Copy_uint8_tEXTILine , uint8_t Copy_uint8_tEXTISenseMode, void (*Fptr) (void));
void EXTI_voidDisableEXTI(uint8_t Copy_uint8_tEXTILine);
void EXTI_voidSoftwareTrigger(uint8_t Copy_uint8_tEXTILine);

#define		 EXTI_FALLING_EDGE		0
#define		 EXTI_RISING_EDGE			1
#define		 EXTI_ON_CHANGE				2

#define		 EXTI_LINE0 			0
#define		 EXTI_LINE1 			1
#define		 EXTI_LINE2 			2
#define		 EXTI_LINE3		    	3
#define		 EXTI_LINE4	    		4
#define		 EXTI_LINE5 		    5
#define		 EXTI_LINE6		    	6
#define		 EXTI_LINE7		    	7
#define		 EXTI_LINE8		    	8
#define		 EXTI_LINE9		    	9
#define		 EXTI_LINE10			10
#define		 EXTI_LINE11		    11
#define		 EXTI_LINE12			12
#define		 EXTI_LINE13			13
#define		 EXTI_LINE14			14
#define		 EXTI_LINE15			15




#endif