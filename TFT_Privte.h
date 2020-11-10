/*
 * TFT_Privte.h
 *
 *  Created on: Jan 23, 2019
 *      Author: abood
 */

#ifndef TFT_PRIVTE_H_
#define TFT_PRIVTE_H_


#define PIN_HIGH(GPIOx, GPIO_Pin)  GPIOx->BSRR  =  (1 << GPIO_Pin);
#define PIN_LOW(GPIOx, GPIO_Pin)   GPIOx->BSRR  =  (1 << (GPIO_Pin + 16));


#define RD_ACTIVE  PIN_LOW(RD_PORT, RD_PIN)
#define RD_IDLE    PIN_HIGH(RD_PORT, RD_PIN)
#define RD_OUTPUT  PIN_OUTPUT(RD_PORT, RD_PIN)
#define WR_ACTIVE  PIN_LOW(WR_PORT, WR_PIN)
#define WR_IDLE    PIN_HIGH(WR_PORT, WR_PIN)
#define WR_OUTPUT  PIN_OUTPUT(WR_PORT, WR_PIN)
#define CD_COMMAND PIN_LOW(CD_PORT, CD_PIN)
#define CD_DATA    PIN_HIGH(CD_PORT, CD_PIN)
#define CD_OUTPUT  PIN_OUTPUT(CD_PORT, CD_PIN)
#define CS_ACTIVE  PIN_LOW(CS_PORT, CS_PIN)
#define CS_IDLE    PIN_HIGH(CS_PORT, CS_PIN)
#define CS_OUTPUT  PIN_OUTPUT(CS_PORT, CS_PIN)
#define RESET_ACTIVE  PIN_LOW(RESET_PORT, RESET_PIN)
#define RESET_IDLE    PIN_HIGH(RESET_PORT, RESET_PIN)
#define RESET_OUTPUT  PIN_OUTPUT(RESET_PORT, RESET_PIN)

#define pgm_read_byte(addr) (*(const unsigned char *)(addr))

#define write_8(d) { \
 GPIOA->BSRR = 0b00000011100000000 << 16; \
 GPIOB->BSRR = 0b00000010000111000 << 16; \
 GPIOC->BSRR = 0b00000000010000000 << 16; \
 GPIOA->BSRR = (((d) & (1<<7)) << 1) \
						 | (((d) & (1<<0)) << 9) \
						 | (((d) & (1<<2)) << 8); \
 GPIOB->BSRR = (((d) & (1<<3)) << 0) \
						 | (((d) & (1<<5)) >> 1) \
						 | (((d) & (1<<6)) << 4) \
						 | (((d) & (1<<4)) << 1); \
 GPIOC->BSRR = (((d) & (1<<1)) << 6); \
	}


/*********************************************************************
 *
 *  PRIVTE FUNCTION USER CANNOT USE IT
 *
 ***********************************************************************/


void drawPixel(uint16_t x, uint16_t y, uint16_t color);
void TFT_GPIO_Init();
void Write_Byte(uint8_t data);
void TFT_Write_Data_Byte(uint8_t data);
void TFT_Write_Cmd_Byte(uint8_t cmd);
void TFT_Wrte_Data_Word(uint16_t data);
void TFT_Write_Cmd_Word(uint16_t data);


void TFT_SetAddrWindow(int16_t x, int16_t y, int16_t x1, int16_t y1);
void TFT_fillCircleHelper(int16_t x0, int16_t y0, int16_t r,uint8_t cornername, int16_t delta, uint16_t color);


void TFT_Print_Char14x24(uint16_t x,uint16_t y,uint8_t data );
void TFT_Print_Char18x32(uint16_t x,uint16_t y,uint8_t data);
void TFT_Print_Char8x16(uint16_t x,uint16_t y,uint8_t num);
void TFT_Print_String18x32(int8_t *string);
void TFT_Print_String14x24(int8_t *string);
void TFT_Print_String8x16(int8_t *string);


#define Write_Byte(data){ write_8(data); WR_ACTIVE; WR_IDLE;}


/*********************************************************************
 *
 *  SCREEN SIZE
 *
 **********************************************************************/

#define TFT_WIDTH  320
#define TFT_HEIGHT 480


/*********************************************************************
 *
 *  GLOBALE VARIBLE
 *
 **********************************************************************/



uint8_t font_width, font_height;
uint8_t font_offset;
uint8_t *font_addr;

uint16_t tft_W = TFT_WIDTH;
uint16_t tft_H = TFT_HEIGHT;

int16_t   _width, _height, cursor_x, cursor_y , color ;
uint16_t   POINT_COLOR, BACK_COLOR;
uint8_t    textsize, rotation;



/*********************************************************************
 *
 *  ORINTIONS OF SCREEN COMMAND
 *
 ***********************************************************************/

#define PORTRAIT       0x48
#define LANDSCAPE      0x28
#define PORTRAIT_REV   0x98
#define LANDSCAPE_REV  0xF4

/*********************************************************************
 *
 *   SCREEN COMMAND
 *
 ***********************************************************************/

#define TFT_NOP     0x00
#define TFT_SWRST   0x01
#define TFT_CASET   0x2A
#define TFT_PASET   0x2B
#define TFT_RAMWR   0x2C
#define TFT_RAMRD   0x2E
#define TFT_MADCTL  0x36
#define TFT_MAD_MY  0x80
#define TFT_MAD_MX  0x40
#define TFT_MAD_MV  0x20
#define TFT_MAD_ML  0x10
#define TFT_MAD_BGR 0x08
#define TFT_MAD_MH  0x04
#define TFT_MAD_SS  0x02
#define TFT_MAD_GS  0x01
#define TFT_MAD_RGB 0x00
#define TFT_INVOFF  0x20
#define TFT_INVON   0x21


#endif /* TFT_PRIVTE_H_ */
