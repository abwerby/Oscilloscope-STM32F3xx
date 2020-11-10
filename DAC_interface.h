/*********************************************************************************/
/* Author    : Abdelrhman                                                        */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/


#ifndef _DAC_INTERFACE_H_
#define _DAC_INTERFACE_H_

#include "DAC_private.h"

#define DAC_TIM6_TRGO_Event     (0x00)
#define DAC_TIM3_TRGO_Event     (0x01)
#define DAC_TIM8_TRGO_Event     (0x01)
#define DAC_TIM7_TRGO_Event     (0x02)
#define DAC_TIM15_TRGO_Event    (0x03)
#define DAC_TIM4_TRGO_Event     (0x04)
#define DAC_TIM2_TRGO_Event     (0x05)
#define DAC_EXTI_LINE9_Event    (0x06)
#define DAC_SWTRIG_Event        (0x07)

#define DAC_8BIT_RIGHT_Alignment      (0)
#define DAC_12BIT_LEFT_Alignment      (1)
#define DAC_12BIT_RIGHT_Alignment     (2)

#define DAC_WAVE_DISABLE     (0x00)
#define DAC_WAVE_NOISE       (0x01)
#define DAC_WAVE_TRIANGLE    (0x02)


#define DAC_BUFFER_DISABLE     (0x01)
#define DAC_BUFFER_ENABLE      (0x00)

#define DAC_DMA_DISABLE         (0)
#define DAC_DMA_ENABLE          (1)

#define DAC_TRIANGLEAMPLITUDE_1            ((uint32_t)0) /*!< Select max triangle amplitude of 1U */
#define DAC_TRIANGLEAMPLITUDE_3            ((uint32_t)1) /*!< Select max triangle amplitude of 3U */
#define DAC_TRIANGLEAMPLITUDE_7            ((uint32_t)2) /*!< Select max triangle amplitude of 7U */
#define DAC_TRIANGLEAMPLITUDE_15           ((uint32_t)3) /*!< Select max triangle amplitude of 15U */
#define DAC_TRIANGLEAMPLITUDE_31           ((uint32_t)4) /*!< Select max triangle amplitude of 31U */
#define DAC_TRIANGLEAMPLITUDE_63           ((uint32_t)5) /*!< Select max triangle amplitude of 63U */
#define DAC_TRIANGLEAMPLITUDE_127          ((uint32_t)6) /*!< Select max triangle amplitude of 127U */
#define DAC_TRIANGLEAMPLITUDE_255          ((uint32_t)7) /*!< Select max triangle amplitude of 255U */
#define DAC_TRIANGLEAMPLITUDE_511          ((uint32_t)8) /*!< Select max triangle amplitude of 511U */
#define DAC_TRIANGLEAMPLITUDE_1023         ((uint32_t)9) /*!< Select max triangle amplitude of 1023U */
#define DAC_TRIANGLEAMPLITUDE_2047         ((uint32_t)10) /*!< Select max triangle amplitude of 2047U */
#define DAC_TRIANGLEAMPLITUDE_4095         ((uint32_t)11) /*!< Select max triangle amplitude of 4095U */


typedef struct 
{
    uint8_t Channel;
    uint8_t Trigger_Source;
    uint8_t Wave;
    uint8_t Wave_Amplitude; 
    uint8_t Buffer;
    uint8_t DMA_State;
}DAC_config;

void DAC_Init(DAC_TypeDef * DACx, DAC_config * dac_config);
void DAC_Deinit(DAC_TypeDef * DACx);
void DAC_Soft_Write(DAC_TypeDef * DACx, uint8_t channel, uint16_t data);


#endif