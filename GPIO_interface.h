/*********************************************************************************/
/* Author    : Abdelrhamn Werby                                                       */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_private.h"

#define HIGH    1
#define LOW     0

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15


/* GPIO Mode Settings values*/
#define GPIO_PIN_INPUT_MODE                            ( (uint32_t)0x00)
#define GPIO_PIN_OUTPUT_MODE                           ( (uint32_t)0x01)
#define GPIO_PIN_ALT_FUN_MODE                          ( (uint32_t)0x02)
#define GPIO_PIN_ANALOG_MODE                           ( (uint32_t)0x03)

/* GPIO OP type selection values */
#define GPIO_PIN_OP_TYPE_PUSHPULL                      ( (uint32_t)0x00 )
#define GPIO_PIN_OP_TYPE_OPEN_DRAIN                    ( (uint32_t)0x01 )

/* GPIO Speed type selection values */
#define GPIO_PIN_SPEED_LOW                             ( (uint32_t)0x00 )
#define GPIO_PIN_SPEED_MEDIUM                          ( (uint32_t)0x01 )
#define GPIO_PIN_SPEED_HIGH                            ( (uint32_t)0x02 )
#define GPIO_PIN_SPEED_VERY_HIGH                       ( (uint32_t)0x03 )

/* GPIO pull up/pull dwn  selection values */
#define GPIO_PIN_NO_PULL                               ( (uint32_t)0x00 )
#define GPIO_PIN_PULL_UP                               ( (uint32_t)0x01 )
#define GPIO_PIN_PULL_DOWN                             ( (uint32_t)0x02 )

typedef struct
{
	uint32_t pin;            /*Specifies the GPIO pins to be configured */

	uint32_t mode;           /*Specifies the operating mode for the selected pins */
													
	uint32_t op_type;        /*Specifies the output type for the selected pins*/

	uint32_t pull;           /*Specifies the Pull-up or Pull-Down activation for the selected pins */
							
	uint32_t speed;          /* Specifies the speed for the selected pins */
							 
	uint32_t alternate;      /*Specifies the alternate function value, 
											 if the mode is set for alt function mode */                      
}GPIO_Pin_Conf_t;

/******************************************************************************/
/*                                                                            */
/*                      Driver exposed APIs                                   */
/*                                                                            */
/******************************************************************************/
/**
	* @brief  Initializes the gpio pin 
	* @param  *GPIOx : GPIO Port Base address
	* @param  *gpio_pin_conf :Pointer to the pin conf structure sent by application 
	* @retval None
	*/
void GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_Pin_Conf_t * gpio_pin_conf);

/**
	* @brief  Read a value from a  given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @retval uint8_t: Value read 
	*/
uint8_t GPIO_Read_Pin(GPIO_TypeDef * GPIOx,uint16_t pin_no);

/**
	* @brief  Write a value to given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  value   : value to be written 
	* @retval None
	*/
void GPIO_Write_Pin(GPIO_TypeDef * GPIOx,uint16_t pin_no, uint8_t val);

/**
	* @brief  Write a value to port 
	* @param  *GPIOx : GPIO Port Base address
	* @param  value   : value to be written 
	* @retval None
	*/
void GPIO_Write_port(GPIO_TypeDef * GPIOx, uint16_t val);

/**
	* @brief  Set the alternate functionality for the given pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  alt_fun_value   :  alternate function to be configured with 
	* @retval None
	*/
void GPIO_set_alt_function(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint16_t alt_fun_value);


#endif

