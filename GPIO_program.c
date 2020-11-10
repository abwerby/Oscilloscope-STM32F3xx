#include <stdint.h>
#include "GPIO_private.h"
#include "GPIO_interface.h"


/**
	* @brief  Configures the mode of a pin : input, output, alt or analog mode 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  mode   : mode to be configured
	* @retval None
	*/
void GPIO_configure_pin_mode(GPIO_TypeDef *GPIOx, uint16_t pin_no, uint32_t mode)
{
	 
	GPIOx->MODER   &= ~(0x03 << ( 2 * pin_no));
	GPIOx->MODER   |= (mode << ( 2 * pin_no));
}

/**
	* @brief  Configures the speed of a pin 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  speed   : value of the speed 
	* @retval None
	*/
void GPIO_configure_pin_speed(GPIO_TypeDef *GPIOx, uint16_t pin_no, uint32_t speed)
{
	
	 GPIOx->OSPEEDR |= (speed << (2 * pin_no));
}

/**
	* @brief  Configures the output type of a pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  op_type   : output type to be configured with 
	* @retval None
	*/
void GPIO_configure_pin_otype(GPIO_TypeDef *GPIOx, uint16_t pin_no, uint32_t op_type)
{
	
	 GPIOx->OTYPER |= (op_type << pin_no);
	
}

/**
	* @brief  Activates the internall pull up or pull down resistors
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  pupd   : specifies which resistor to activate
	* @retval None
	*/
void GPIO_configure_pin_pupd(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t pupd)
{
	 GPIOx->PUPDR |= (pupd << (2 * pin_no));

}


/**
	* @brief  Initializes the gpio pin 
	* @param  *GPIOx : GPIO Port Base address
	* @param  *gpio_pin_conf :Pointer to the pin conf structure sent by application 
	* @retval None
	*/
void GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_Pin_Conf_t * gpio_pin_conf)
{
	GPIO_configure_pin_mode(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->mode);
	GPIO_configure_pin_speed(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->speed);
	GPIO_configure_pin_otype(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->op_type);
	GPIO_configure_pin_pupd(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->pull);
	GPIO_set_alt_function(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->alternate);
}

/**
	* @brief  Write a value to given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  value  : value to be written 
	* @retval None
	*/
void GPIO_Write_Pin(GPIO_TypeDef * GPIOx,uint16_t pin_no, uint8_t val)
{
	if(val)
		GPIOx->ODR |=  (1 << pin_no);
	else
		GPIOx->ODR &=  ~(1 << pin_no);
	
}

/**
	* @brief  Write a value to port 
	* @param  *GPIOx : GPIO Port Base address
	* @param  value  : value to be written 
	* @retval None
	*/
void GPIO_Write_Port(GPIO_TypeDef * GPIOx, uint16_t val)
{
		GPIOx->ODR = val;
}

/**
	* @brief  Read a value from a  given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @retval uint8_t: Value read 
	*/
uint8_t GPIO_Read_Pin(GPIO_TypeDef * GPIOx,uint16_t pin_no)
{
	
	uint8_t value ; 
	
	value = ((GPIOx->IDR >> pin_no ) & 0x00000001 );
	
	return value ;
}


/**
	* @brief  Set the alternate functionality for the given pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  alt_fun_value   :  alternate function to be configured with 
	* @retval None
	*/
void GPIO_set_alt_function(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint16_t alt_fun_value)
{
  if ( pin_no  <= 7 )
	{
		GPIOx->AFR[0] |= (alt_fun_value << ((pin_no) * 4 ));
	}
	else
	{
		GPIOx->AFR[1] |= (alt_fun_value << ( ( pin_no % 8) * 4 ));
	}
}	

