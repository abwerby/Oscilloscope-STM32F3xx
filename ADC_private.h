/*********************************************************************************/
/* Author    : Abdelrhman                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/



#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


typedef struct
{
  volatile uint32_t ISR;              /*!< ADC Interrupt and Status Register,                 Address offset: 0x00 */
  volatile uint32_t IER;              /*!< ADC Interrupt Enable Register,                     Address offset: 0x04 */
  volatile uint32_t CR;               /*!< ADC control register,                              Address offset: 0x08 */
  volatile uint32_t CFGR;             /*!< ADC Configuration register,                        Address offset: 0x0C */
  uint32_t      RESERVED0;        		/*!< Reserved, 0x010                                                         */
  volatile uint32_t SMPR1;            /*!< ADC sample time register 1,                        Address offset: 0x14 */
  volatile uint32_t SMPR2;            /*!< ADC sample time register 2,                        Address offset: 0x18 */
  uint32_t      RESERVED1;        		/*!< Reserved, 0x01C                                                         */
  volatile uint32_t TR1;              /*!< ADC watchdog threshold register 1,                 Address offset: 0x20 */
  volatile uint32_t TR2;              /*!< ADC watchdog threshold register 2,                 Address offset: 0x24 */
  volatile uint32_t TR3;              /*!< ADC watchdog threshold register 3,                 Address offset: 0x28 */
  uint32_t      RESERVED2;        		/*!< Reserved, 0x02C                                                         */
  volatile uint32_t SQR1;             /*!< ADC regular sequence register 1,                   Address offset: 0x30 */
  volatile uint32_t SQR2;             /*!< ADC regular sequence register 2,                   Address offset: 0x34 */
  volatile uint32_t SQR3;             /*!< ADC regular sequence register 3,                   Address offset: 0x38 */
  volatile uint32_t SQR4;             /*!< ADC regular sequence register 4,                   Address offset: 0x3C */
  volatile uint32_t DR;               /*!< ADC regular data register,                         Address offset: 0x40 */
  uint32_t      RESERVED3;        		/*!< Reserved, 0x044                                                         */
  uint32_t      RESERVED4;        		/*!< Reserved, 0x048                                                         */
  volatile uint32_t JSQR;             /*!< ADC injected sequence register,                    Address offset: 0x4C */
  uint32_t      RESERVED5[4];     		/*!< Reserved, 0x050 - 0x05C                                                 */
  volatile uint32_t OFR1;             /*!< ADC offset register 1,                             Address offset: 0x60 */
  volatile uint32_t OFR2;             /*!< ADC offset register 2,                             Address offset: 0x64 */
  volatile uint32_t OFR3;             /*!< ADC offset register 3,                             Address offset: 0x68 */
  volatile uint32_t OFR4;             /*!< ADC offset register 4,                             Address offset: 0x6C */
  uint32_t      RESERVED6[4];     		/*!< Reserved, 0x070 - 0x07C                                                 */
  volatile uint32_t JDR1;             /*!< ADC injected data register 1,                      Address offset: 0x80 */
  volatile uint32_t JDR2;             /*!< ADC injected data register 2,                      Address offset: 0x84 */
  volatile uint32_t JDR3;             /*!< ADC injected data register 3,                      Address offset: 0x88 */
  volatile uint32_t JDR4;             /*!< ADC injected data register 4,                      Address offset: 0x8C */
  uint32_t      RESERVED7[4];     		/*!< Reserved, 0x090 - 0x09C                                                 */
  volatile uint32_t AWD2CR;           /*!< ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 */
  volatile uint32_t AWD3CR;           /*!< ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 */
  uint32_t      RESERVED8;         	  /*!< Reserved, 0x0A8                                                         */
  uint32_t      RESERVED9;        		/*!< Reserved, 0x0AC                                                         */
  volatile uint32_t DIFSEL;           /*!< ADC  Differential Mode Selection Register,         Address offset: 0xB0 */
  volatile uint32_t CALFACT;          /*!< ADC  Calibration Factors,                          Address offset: 0xB4 */

} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;            /*!< ADC Common status register,                  Address offset: ADC1/3 base address + 0x300 */
  uint32_t      RESERVED;       		/*!< Reserved, ADC1/3 base address + 0x304                                                    */
  volatile uint32_t CCR;            /*!< ADC common control register,                 Address offset: ADC1/3 base address + 0x308 */
  volatile uint32_t CDR;            /*!< ADC common regular data register for dual
                                     AND triple modes,                            Address offset: ADC1/3 base address + 0x30C */
} ADC_Common_TypeDef;



#define ADC1_BASE             (0x50000000 + 0x00000000U)
#define ADC2_BASE             (0x50000000 + 0x00000100U)
#define ADC1_2_COMMON_BASE    (0x50000000 + 0x00000300U)
#define ADC3_BASE             (0x50000000 + 0x00000400U)
#define ADC4_BASE             (0x50000000 + 0x00000500U)
#define ADC3_4_COMMON_BASE    (0x50000000 + 0x00000700U)

#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#define ADC3                ((ADC_TypeDef *) ADC3_BASE)
#define ADC4                ((ADC_TypeDef *) ADC4_BASE)
#define ADC12_COMMON        ((ADC_Common_TypeDef *) ADC1_2_COMMON_BASE)
#define ADC34_COMMON        ((ADC_Common_TypeDef *) ADC3_4_COMMON_BASE)


/**
  * @brief Set the selected regular Channel Sequence for Sequence between 1 and 4.
  * @param _CHANNELNB_ Channel number.
  * @param _SequenceNB_ Sequence number.    
  * @retval None
  */
#define ADC_SQR1_RK(_CHANNELNB_, _SequenceNB_) ((_CHANNELNB_) << (6U * (_SequenceNB_)))

/**
  * @brief Set the selected regular Channel Sequence for Sequence between 5 and 9.
  * @param _CHANNELNB_ Channel number.
  * @param _SequenceNB_ Sequence number.    
  * @retval None
  */
#define ADC_SQR2_RK(_CHANNELNB_, _SequenceNB_) ((_CHANNELNB_) << (6U * ((_SequenceNB_) - 5U)))

/**
  * @brief Set the selected regular Channel Sequence for Sequence between 10 and 14.
  * @param _CHANNELNB_ Channel number.
  * @param _SequenceNB_ Sequence number.    
  * @retval None
  */
#define ADC_SQR3_RK(_CHANNELNB_, _SequenceNB_) ((_CHANNELNB_) << (6U * ((_SequenceNB_) - 10U)))

/**
  * @brief Set the selected regular Channel Sequence for Sequence between 15 and 16.
  * @param _CHANNELNB_ Channel number.
  * @param _SequenceNB_ Sequence number.    
  * @retval None
  */
#define ADC_SQR4_RK(_CHANNELNB_, _SequenceNB_) ((_CHANNELNB_) << (6U * ((_SequenceNB_) - 15U)))

/**
  * @brief Set the ADC's sample time for Channels numbers between 0 and 9.
  * @param _SAMPLETIME_ Sample time parameter.
  * @param _CHANNELNB_ Channel number.  
  * @retval None
  */
#define ADC_SMPR1(_SAMPLETIME_, _CHANNELNB_) ((_SAMPLETIME_) << (3U * (_CHANNELNB_)))
    
/**
  * @brief Set the ADC's sample time for Channels numbers between 10 and 18.
  * @param _SAMPLETIME_ Sample time parameter.
  * @param _CHANNELNB_ Channel number.  
  * @retval None
  */
#define ADC_SMPR2(_SAMPLETIME_, _CHANNELNB_) ((_SAMPLETIME_) << (3U * ((_CHANNELNB_) - 10U)))



#endif