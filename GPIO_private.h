/*********************************************************************************/
/* Author    : Abdelrhman                                                       */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H





/**
  * @brief General Purpose I/O
  */

typedef struct
{
  volatile uint32_t MODER;        /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t OTYPER;       /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t OSPEEDR;      /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IDR;          /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t ODR;          /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32_t BSRR;         /*!< GPIO port bit set/reset register,      Address offset: 0x1A */
  volatile uint32_t LCKR;         /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32_t AFR[2];       /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  volatile uint32_t BRR;          /*!< GPIO bit reset register,               Address offset: 0x28 */
}GPIO_TypeDef;



#define GPIOA        ((GPIO_TypeDef *)0x48000000)            // define the boundary address of GPIO port A
#define GPIOB        ((GPIO_TypeDef *)0x48000400)            // define the boundary address of GPIO port B
#define GPIOC        ((GPIO_TypeDef *)0x48000800)            // define the boundary address of GPIO port C
#define GPIOD        ((GPIO_TypeDef *)0x48000C00)            // define the boundary address of GPIO port D
#define GPIOE        ((GPIO_TypeDef *)0x48001000)            // define the boundary address of GPIO port E
#define GPIOF        ((GPIO_TypeDef *)0x48001400)            // define the boundary address of GPIO port F



#endif