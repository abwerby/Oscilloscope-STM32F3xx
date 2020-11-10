/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 13 SEPTEMBER 2020           */
/*****************************************/


/*Preprocessor File Guard*/
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct
{
	volatile uint32_t CCR;
	volatile uint32_t CNDTR;
	volatile uint32_t CPAR;
	volatile uint32_t CMAR;
	volatile uint32_t Reserved;
}DMA_Channel;

typedef struct
{
	volatile uint32_t ISR;
	volatile uint32_t IFCR;
	DMA_Channel Channel[7];
}DMA_t;

#define DMA1	(( DMA_t*)0x40020000)
#define DMA2	(( DMA_t*)0x40020400)


#endif