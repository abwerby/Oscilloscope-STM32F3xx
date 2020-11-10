/*
 * TFT_cfg.h
 *
 *  Created on: Jan 23, 2019
 *      Author: abood
 */

#ifndef TFT_CFG_H_
#define TFT_CFG_H_

#define RD_PORT GPIOA
#define RD_PIN  PIN0
#define WR_PORT GPIOA
#define WR_PIN  PIN1
#define CD_PORT GPIOA          // RS PORT
#define CD_PIN  PIN4     // RS PIN
#define CS_PORT GPIOB
#define CS_PIN  PIN0
#define RESET_PORT GPIOC
#define RESET_PIN  PIN1

#define D0_PORT GPIOA
#define D0_PIN PIN9
#define D1_PORT GPIOC
#define D1_PIN PIN7
#define D2_PORT GPIOA
#define D2_PIN PIN10
#define D3_PORT GPIOB
#define D3_PIN PIN3
#define D4_PORT GPIOB
#define D4_PIN PIN5
#define D5_PORT GPIOB
#define D5_PIN PIN4
#define D6_PORT GPIOB
#define D6_PIN PIN10
#define D7_PORT GPIOA
#define D7_PIN PIN8



#define  WIDTH    ((uint16_t)320)
#define  HEIGHT   ((uint16_t)480)




	


#endif /* TFT_CFG_H_ */
