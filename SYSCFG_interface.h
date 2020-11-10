/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H



#define		 SYSCFG_EXTI_LINE0 			0
#define		 SYSCFG_EXTI_LINE1 			1
#define		 SYSCFG_EXTI_LINE2 			2
#define		 SYSCFG_EXTI_LINE3		    3
#define		 SYSCFG_EXTI_LINE4	    	4
#define		 SYSCFG_EXTI_LINE5 		    5
#define		 SYSCFG_EXTI_LINE6		    6
#define		 SYSCFG_EXTI_LINE7		    7
#define		 SYSCFG_EXTI_LINE8		    8
#define		 SYSCFG_EXTI_LINE9		    9
#define		 SYSCFG_EXTI_LINE10			10
#define		 SYSCFG_EXTI_LINE11		    11
#define		 SYSCFG_EXTI_LINE12			12
#define		 SYSCFG_EXTI_LINE13			13
#define		 SYSCFG_EXTI_LINE14			14
#define		 SYSCFG_EXTI_LINE15			15



#define SYSCFG_EXTI_GPIOA	0
#define SYSCFG_EXTI_GPIOB	1
#define SYSCFG_EXTI_GPIOC	2
#define SYSCFG_EXTI_GPIOD	3
#define SYSCFG_EXTI_GPIOE	4
#define SYSCFG_EXTI_GPIOF	5
#define SYSCFG_EXTI_GPIOG	6





void SYSCFG_Config_EXTI(uint8_t SYSCFG_EXTI_LINE, uint8_t Gpiox);


#endif