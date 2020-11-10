/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/

#include <stdint.h>
#include "BIT_MATH.h"

#include "SYSCFG_private.h"
#include "SYSCFG_interface.h"



void SYSCFG_Config_EXTI(uint8_t Exti_line, uint8_t Gpiox)
{
    if (Exti_line < 4)
    {
        SYSCFG->EXTICR[0] |= (Gpiox << (Exti_line * 4));
    }
    else if (Exti_line < 8)
    {
        SYSCFG->EXTICR[1] |= (Gpiox << ((Exti_line * 4)-16));
    }
    else if (Exti_line < 12)
    {
        SYSCFG->EXTICR[2] |= (Gpiox << ((Exti_line * 4)-32));
    }
    else if (Exti_line < 16)
    {
        SYSCFG->EXTICR[3] |= (Gpiox << ((Exti_line * 4)-48));
    }
    else
    {
        /* Error */
    }
}
