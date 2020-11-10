/*
 * TFT_Interface.h
 *
 *  Created on: Jan 23, 2019
 *      Author: abdelrhamn werby
 */

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

/************************************************************
 *
 *  CONTROL FUNCTIONS
 *
 ************************************************************/



void TFT_Init();
void TFT_Reset();
void TFT_Clear(uint16_t color);
void TFT_Set_Rotation(uint8_t rotation);

/************************************************************
 *
 *  DRAW FUNCTIONS
 *
 ************************************************************/


void TFT_Draw_Line(int16_t x0, int16_t y0,int16_t x1, int16_t y1,uint16_t color);
void TFT_Draw_Circle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void TFT_DrawRect(int16_t x, int16_t y,  int16_t w, int16_t h,  uint16_t color);
void TFT_DrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void TFT_DrawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void TFT_fillRect(int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color);
void TFT_fillScreen(uint16_t color);
void TFT_fillCircle(int16_t x0, int16_t y0, int16_t r,uint16_t color);
void TFT_Draw_Point(int16_t x0, int16_t y0 ,uint16_t color);
void TFT_Scroll_Vertical(int16_t top, int16_t scrollines, int16_t offset);




/************************************************************
 *
 * TEXT PRINT FUNCTIONS
 *
 ************************************************************/


void TFT_SetCursor(int16_t x, int16_t y);
void TFT_SetTextSize(int8_t s);
void TFT_SetTextColor(uint16_t c);
void TFT_Print_String(int8_t *string);
void TFT_Print_Number(long  Number);



/************************************************************
 *
 *  COLORS
 *
 ************************************************************/


#define ILI9486_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9486_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9486_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9486_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9486_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9486_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9486_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9486_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9486_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9486_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9486_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9486_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9486_RED         0xF800      /* 255,   0,   0 */
#define ILI9486_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9486_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9486_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9486_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9486_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9486_PINK        0xF81F

/************************************************************
 *
 *  ORINTIONS
 *
 ************************************************************/


#define TFT_PORTRAIT       0
#define TFT_LANDSCAPE      1
#define TFT_PORTRAIT_REV   2
#define TFT_LANDSCAPE_REV  3



#endif /* TFT_INTERFACE_H_ */
