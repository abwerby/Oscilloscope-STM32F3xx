/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 13 SEPTEMBER 2020           */
/*****************************************/

#include <stdint.h>
#include "BIT_MATH.h"
#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"

void DMA_Init(DMA_t * DMAx, DMA_config * dma_config)
{
	DMAx->Channel[dma_config->Channel_Number].CPAR = dma_config->Peripheral_Reg;
	DMAx->Channel[dma_config->Channel_Number].CMAR = dma_config->Memory_Address;
	DMAx->Channel[dma_config->Channel_Number].CNDTR = dma_config->Total_Data;
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->Channel_Priority << 12);
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->Data_Direction << 4);
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->Circular_Mode << 5);
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->PINC << 6);
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->MINC << 7);
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->Peripheral_Size << 8);
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->Memory_Size << 10);
	DMAx->Channel[dma_config->Channel_Number].CCR |= (dma_config->MEM2MEM << 14);
	/* Enable DMA Channel */
	// SET_BIT(DMAx->Channel[dma_config->Channel_Number].CCR, 0);

}

void DMA_Channel_Enable(DMA_t * DMAx, uint8_t Channel_Number)
{
	SET_BIT(DMAx->Channel[Channel_Number].CCR, 0);
}

void DMA_Channel_Disable(DMA_t * DMAx, uint8_t Channel_Number)
{
	CLR_BIT(DMAx->Channel[Channel_Number].CCR, 0);
}

