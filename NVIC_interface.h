/**********************************************************/
/* Author    : Ahmed Assaf                                */
/* Date      : 19 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void NVIC_voidInit(void);
void NVIC_voidSetPriority(uint8_t Copy_PeripheralIdx, uint8_t Copy_uint8_tPriority);
void NVIC_voidEnableInterrupt  (uint8_t Copy_uint8_tIntNumber);
void NVIC_voidDisableInterrupt (uint8_t Copy_uint8_tIntNumber);
void NVIC_voidSetPendingFlag   (uint8_t Copy_uint8_tIntNumber);
void NVIC_voidClearPendingFlag (uint8_t Copy_uint8_tIntNumber);
uint8_t NVIC_uint8_tGetActiveFlag        (uint8_t Copy_uint8_tIntNumber);

#endif