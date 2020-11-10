/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 13 SEPTEMBER 2020           */
/*****************************************/


/*Preprocessor File Guard*/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include "DMA_private.h"

typedef struct 
{
    uint8_t  Channel_Number;
    volatile uint32_t * Peripheral_Reg;
		volatile uint32_t * Memory_Address;
    uint16_t Total_Data;	// number in byte
    uint8_t  Channel_Priority;
    uint8_t  Data_Direction;
    uint8_t  Circular_Mode;
    uint8_t  Memory_Size;
    uint8_t  Peripheral_Size;
    uint8_t  MINC; // Memory increment mode.
    uint8_t  PINC; // Peripheral increment mode.
    uint8_t MEM2MEM; //Memory to memory mode.

}DMA_config;


#define DMA_Circular_Mode_OFF       0
#define DMA_Circular_Mode_ON        1


#define DMA_MEM_OR_PER_Size_8       0x00
#define DMA_MEM_OR_PER_Size_16      0x01
#define DMA_MEM_OR_PER_Size_32      0x02

#define DMA_Data_Direction_Read_From_MEM        1
#define DMA_Data_Direction_Read_From_PER        0


#define DMA_MINC_ON         1
#define DMA_MINC_OFF        0
#define DMA_PINC_ON         1
#define DMA_PINC_OFF        0

#define DMA_Channel_Priority_LOW            0x00
#define DMA_Channel_Priority_Medium         0x01
#define DMA_Channel_Priority_High           0x02
#define DMA_Channel_Priority_VeryHigh       0x03

#define DMA_MEM2MEM_ON       1
#define DMA_MEM2MEM_OFF      0


void DMA_Init(DMA_t * DMAx, DMA_config * dma_config);
void DMA_Channel_Enable(DMA_t * DMAx, uint8_t Channel_Number);
void DMA_Channel_Disable(DMA_t * DMAx, uint8_t Channel_Number);

#endif