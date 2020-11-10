/*********************************************************************************/
/* Author    : Abdelrhman                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/


#ifndef _DAC_PRIVATE_H_
#define _DAC_PRIVATE_H_

typedef struct
{
  volatile uint32_t CR;       /*!< DAC control register,                                    Address offset: 0x00 */
  volatile uint32_t SWTRIGR;  /*!< DAC software trigger register,                           Address offset: 0x04 */
  volatile uint32_t DHR12R1;  /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
  volatile uint32_t DHR12L1;  /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
  volatile uint32_t DHR8R1;   /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
  volatile uint32_t DHR12R2;  /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
  volatile uint32_t DHR12L2;  /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
  volatile uint32_t DHR8R2;   /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
  volatile uint32_t DHR12RD;  /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
  volatile uint32_t DHR12LD;  /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
  volatile uint32_t DHR8RD;   /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
  volatile uint32_t DOR1;     /*!< DAC channel1 data output register,                       Address offset: 0x2C */
  volatile uint32_t DOR2;     /*!< DAC channel2 data output register,                       Address offset: 0x30 */
  volatile uint32_t SR;       /*!< DAC status register,                                     Address offset: 0x34 */
} DAC_TypeDef;

#define DAC1    ((DAC_TypeDef *)0x40007400)


#endif