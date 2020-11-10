/*********************************************************************************/
/* Author    : Abdelrhman                                                        */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/

#include <stdint.h>
#include "BIT_MATH.h"
#include "DAC_private.h"
#include "DAC_config.h"
#include "DAC_interface.h"


void DAC_Init(DAC_TypeDef * DACx, DAC_config * dac_config)
{
    if (dac_config->Channel == 1)
    {
        DACx->CR |= (dac_config->DMA_State << 12);
        DACx->CR |= (dac_config->Wave_Amplitude << 8);
        DACx->CR |= (dac_config->Wave << 6);
        DACx->CR |= (dac_config->Trigger_Source << 3);
        SET_BIT(DACx->CR, 2);
        DACx->CR |= (dac_config->Buffer << 1);
        SET_BIT(DACx->CR, 0);
    }
    else if (dac_config->Channel == 2)
    {
        DACx->CR |= (dac_config->DMA_State << 28);
        DACx->CR |= (dac_config->Wave_Amplitude << 24);
        DACx->CR |= (dac_config->Wave << 22);
        DACx->CR |= (dac_config->Trigger_Source << 19);
        SET_BIT(DACx->CR, 18);
        DACx->CR |= (dac_config->Buffer << 17);
        SET_BIT(DACx->CR, 16);
    }
    else
    {
        // Error
    }
 
}

void DAC_Deinit(DAC_TypeDef * DACx)
{
    DACx->CR = 0x00000000;
    DACx->DHR12R1 = 0x00000000;
}

void DAC_Soft_Write(DAC_TypeDef * DACx, uint8_t channel, uint16_t data)
{
    if (channel == 1)
    {
        DACx->DHR12R1 = data;
        SET_BIT(DACx->SWTRIGR, 0);
    }
    else
    {
        DACx->DHR12R2 = data;
        SET_BIT(DACx->SWTRIGR, 1);
    }
}
