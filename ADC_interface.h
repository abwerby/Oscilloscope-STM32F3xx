/*********************************************************************************/
/* Author    : Abdelrhman                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "ADC_private.h"

/** @defgroup ADCEx_channels ADC Extended Channels
  * @{
  */
#define ADC_CHANNEL_1           ((uint32_t)(1))
#define ADC_CHANNEL_2           ((uint32_t)(2))
#define ADC_CHANNEL_3           ((uint32_t)(3))
#define ADC_CHANNEL_4           ((uint32_t)(4))
#define ADC_CHANNEL_5           ((uint32_t)(5)
#define ADC_CHANNEL_6           ((uint32_t)(6))
#define ADC_CHANNEL_7           ((uint32_t)(7))
#define ADC_CHANNEL_8           ((uint32_t)(8))
#define ADC_CHANNEL_9           ((uint32_t)(9))
#define ADC_CHANNEL_10          ((uint32_t)(10))
#define ADC_CHANNEL_11          ((uint32_t)(11))
#define ADC_CHANNEL_12          ((uint32_t)(12))
#define ADC_CHANNEL_13          ((uint32_t)(13))
#define ADC_CHANNEL_14          ((uint32_t)(14))
#define ADC_CHANNEL_15          ((uint32_t)(15))
#define ADC_CHANNEL_16          ((uint32_t)(16))
#define ADC_CHANNEL_17          ((uint32_t)(17))
#define ADC_CHANNEL_18          ((uint32_t)(18))

#define ADC_CHANNEL_TEMPSENSOR  ADC_CHANNEL_16
#define ADC_CHANNEL_VREFINT     ADC_CHANNEL_17
#define ADC_CHANNEL_VBAT        ADC_CHANNEL_18


/** @defgroup the resolution of the conversion
  * @{
  */
#define ADC_DATA_RES_12     0x00
#define ADC_DATA_RES_10     0x01
#define ADC_DATA_RES_8      0x02
#define ADC_DATA_RES_6      0x03
/**
  * @}
  */


/** @defgroup ADC Scan_mode ADC Extended Scan Mode
  * @{
  */
#define ADC_SCAN_DISABLE         (0)
#define ADC_SCAN_ENABLE          (1)
/**
  * @}
  */


/** @defgroup ADC Scan_mode ADC Extended Scan Mode
  * @{
  */
#define ADC_DMA_DISABLE         (0)
#define ADC_DMA_ENABLE          (1)
/**
  * @}
  */
	
/** @defgroup ADC Scan_mode ADC Extended Scan Mode
  * @{
  */
#define ADC_DMA_SCAN_DISABLE         (0)
#define ADC_DMA_SCAN_ENABLE          (1)
/**
  * @}
  */


/** @defgroup ADC ClockPrescaler ADC Extended Clock Prescaler
  * @{
  */ 
#define ADC_CLOCK_ASYNC_DIV1          (0)            /*!< ADC asynchronous clock derived from ADC dedicated PLL */
#define ADC_CLOCK_SYNC_PCLK_DIV1      ((uint32_t)1)  /*!< ADC synchronous clock derived from AHB clock without prescaler */
#define ADC_CLOCK_SYNC_PCLK_DIV2      ((uint32_t)2)  /*!< ADC synchronous clock derived from AHB clock divided by a prescaler of 2U */
#define ADC_CLOCK_SYNC_PCLK_DIV4      ((uint32_t)3)  /*!< ADC synchronous clock derived from AHB clock divided by a prescaler of 4U */
/**
  * @}
  */

/** @defgroup ADCEx_sampling_times ADC Extended Sampling Times
  * @{
  */
#define ADC_SAMPLETIME_1CYCLE_5       ((uint32_t)0)     /*!< Sampling time 1.5 ADC clock cycle */
#define ADC_SAMPLETIME_2CYCLES_5      ((uint32_t)1)     /*!< Sampling time 2.5 ADC clock cycles */
#define ADC_SAMPLETIME_4CYCLES_5      ((uint32_t)2)     /*!< Sampling time 4.5 ADC clock cycles */
#define ADC_SAMPLETIME_7CYCLES_5      ((uint32_t)3)   	/*!< Sampling time 7.5 ADC clock cycles */
#define ADC_SAMPLETIME_19CYCLES_5     ((uint32_t)4)     /*!< Sampling time 19.5 ADC clock cycles */
#define ADC_SAMPLETIME_61CYCLES_5     ((uint32_t)5)   	/*!< Sampling time 61.5 ADC clock cycles */
#define ADC_SAMPLETIME_181CYCLES_5    ((uint32_t)6)   	/*!< Sampling time 181.5 ADC clock cycles */
#define ADC_SAMPLETIME_601CYCLES_5    ((uint32_t)7)     /*!< Sampling time 601.5 ADC clock cycles */
/**
  * @}
  */



typedef struct 
{
    uint8_t CLK_Source;
    uint8_t Scan_State;
    uint8_t Numbers_of_Channels;
    uint8_t * Channels_Sequence;
    uint8_t Data_Resolution;
    uint8_t DMA_State;
    uint8_t DMA_Mode;
}ADC_config;


void ADC_Init(ADC_TypeDef * ADCx, ADC_config * adc_config);
void ADC_Deinit(ADC_TypeDef * ADCx);
uint16_t ADC_Read(ADC_TypeDef * ADCx);
void ADC_Start(ADC_TypeDef * ADCx);
void ADC_Stop(ADC_TypeDef * ADCx);
void ADC_Set_Channel_SMT(ADC_TypeDef * ADCx, uint8_t ChannelNum, uint8_t SampleTime);


#endif