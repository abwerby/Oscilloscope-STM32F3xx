/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H


typedef struct
{
  volatile uint32_t CFGR1;       /*!< SYSCFG configuration register 1,                      Address offset: 0x00 */
  volatile uint32_t RCR;        /*!< SYSCFG CCM SRAM protection register,               Address offset: 0x04 */
  volatile uint32_t EXTICR[4];   /*!< SYSCFG external interrupt configuration registers, Address offset: 0x14-0x08 */
  volatile uint32_t CFGR2;       /*!< SYSCFG configuration register 2,                      Address offset: 0x18 */
  volatile uint32_t RESERVED0;  /*!< Reserved,                                                          0x1C */
  volatile uint32_t RESERVED1;  /*!< Reserved,                                                          0x20 */
  volatile uint32_t RESERVED2;  /*!< Reserved,                                                          0x24 */
  volatile uint32_t RESERVED4;  /*!< Reserved,                                                          0x28 */
  volatile uint32_t RESERVED5;  /*!< Reserved,                                                          0x2C */
  volatile uint32_t RESERVED6;  /*!< Reserved,                                                          0x30 */
  volatile uint32_t RESERVED7;  /*!< Reserved,                                                          0x34 */
  volatile uint32_t RESERVED8;  /*!< Reserved,                                                          0x38 */
  volatile uint32_t RESERVED9;  /*!< Reserved,                                                          0x3C */
  volatile uint32_t RESERVED10; /*!< Reserved,                                                          0x40 */
  volatile uint32_t RESERVED11; /*!< Reserved,                                                          0x44 */
  volatile uint32_t CFGR4;      /*!< SYSCFG configuration register 4,                   Address offset: 0x48 */
  volatile uint32_t RESERVED12; /*!< Reserved,                                                          0x4C */
  volatile uint32_t RESERVED13; /*!< Reserved,                                                          0x50 */
} SYSCFG_TypeDef;



#define SYSCFG ((SYSCFG_TypeDef *) 0x40010000)


#endif