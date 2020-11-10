/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/*
   Apply Clock choice from configuration file 
   Disable SysTick interrupt 
   Disable Systick                         
*/
void STK_voidInit(uint32_t Copy_uint32_tTicks);
void STK_voidDelayMs(uint32_t t);
void STK_voidStop(void);
void STK_Set_CallBack(void (* Fptr) (void));
uint32_t STK_uint32_t_millis(void);

#endif