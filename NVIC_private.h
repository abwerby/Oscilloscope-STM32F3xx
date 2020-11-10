/**********************************************************/
/* Author    : Ahmed Assaf                                */
/* Date      : 19 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_ISER0       *((uint32_t*)0xE000E100) /* Enable External interrupts from 0  to 31 */    
#define NVIC_ISER1       *((uint32_t*)0xE000E104) /* Enable External interrupts from 32 to 63 */
#define NVIC_ISER2       *((uint32_t*)0xE000E108) /* Enable External interrupts from 64 to 127 */

#define NVIC_ICER0       *((uint32_t*)0xE000E180)
#define NVIC_ICER1       *((uint32_t*)0xE000E184)
#define NVIC_ICER2       *((uint32_t*)0xE000E188)

#define NVIC_ISPR0       *((uint32_t*)0xE000E200)
#define NVIC_ISPR1       *((uint32_t*)0xE000E204)
#define NVIC_ISPR2       *((uint32_t*)0xE000E208)

#define NVIC_ICPR0       *((uint32_t*)0xE000E280)
#define NVIC_ICPR1       *((uint32_t*)0xE000E284)
#define NVIC_ICPR2       *((uint32_t*)0xE000E288)

#define NVIC_IABR0       *((volatile uint32_t*)0xE000E300)
#define NVIC_IABR1       *((volatile uint32_t*)0xE000E304)
#define NVIC_IABR2       *((volatile uint32_t*)0xE000E308)


#define NVIC_IPR          ((uint8_t*)0xE000E400)

#define MNVIC_GROUP_4_SUB_0      0x05FA0300
#define MNVIC_GROUP_3_SUB_1      0x05FA0400
#define MNVIC_GROUP_2_SUB_2      0x05FA0500
#define MNVIC_GROUP_1_SUB_3      0x05FA0600
#define MNVIC_GROUP_0_SUB_4      0x05FA0700

#endif

