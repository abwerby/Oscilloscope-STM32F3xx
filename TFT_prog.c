/*
 * TFT_prog.c
 *
 *  Created on: Jan 23, 2019
 *      Author: ab_werby
 */

#include "stdint.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "TFT_Interface.h"
#include "TFT_cfg.h"
#include "TFT_Privte.h"
#include "TFT_Fonts.h"
#include "STK_interface.h"

// #define DelayMs()  for(uint32_t i = 0; i < 1000000; i++);
#define DelayMs()		STK_voidDelayMs(500);

void PIN_OUTPUT (GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
	GPIO_Pin_Conf_t GPIO_InitStruct;

	GPIO_InitStruct.pin = GPIO_Pin;
	GPIO_InitStruct.mode = GPIO_PIN_OUTPUT_MODE;
	GPIO_InitStruct.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	GPIO_InitStruct.pull = GPIO_PIN_NO_PULL;
	GPIO_InitStruct.speed = GPIO_PIN_SPEED_VERY_HIGH;
	GPIO_Init(GPIOx, &GPIO_InitStruct);
}



void TFT_Init()
{
	TFT_GPIO_Init();
	TFT_Reset();

	TFT_Write_Cmd_Byte(0x11); // Sleep out, also SW reset
	DelayMs();

	TFT_Write_Cmd_Byte(0x3A);
	TFT_Write_Data_Byte(0x55);

	TFT_Write_Cmd_Byte(0xC2);
	TFT_Write_Data_Byte(0x44);

	TFT_Write_Cmd_Byte(0xC5);
	TFT_Write_Data_Byte(0x00);
	TFT_Write_Data_Byte(0x00);
	TFT_Write_Data_Byte(0x00);
	TFT_Write_Data_Byte(0x00);

	TFT_Write_Cmd_Byte(0xE0);
	TFT_Write_Data_Byte(0x0F);
	TFT_Write_Data_Byte(0x1F);
	TFT_Write_Data_Byte(0x1C);
	TFT_Write_Data_Byte(0x0C);
	TFT_Write_Data_Byte(0x0F);
	TFT_Write_Data_Byte(0x08);
	TFT_Write_Data_Byte(0x48);
	TFT_Write_Data_Byte(0x98);
	TFT_Write_Data_Byte(0x37);
	TFT_Write_Data_Byte(0x0A);
	TFT_Write_Data_Byte(0x13);
	TFT_Write_Data_Byte(0x04);
	TFT_Write_Data_Byte(0x11);
	TFT_Write_Data_Byte(0x0D);
	TFT_Write_Data_Byte(0x00);

	TFT_Write_Cmd_Byte(0xE1);
	TFT_Write_Data_Byte(0x0F);
	TFT_Write_Data_Byte(0x32);
	TFT_Write_Data_Byte(0x2E);
	TFT_Write_Data_Byte(0x0B);
	TFT_Write_Data_Byte(0x0D);
	TFT_Write_Data_Byte(0x05);
	TFT_Write_Data_Byte(0x47);
	TFT_Write_Data_Byte(0x75);
	TFT_Write_Data_Byte(0x37);
	TFT_Write_Data_Byte(0x06);
	TFT_Write_Data_Byte(0x10);
	TFT_Write_Data_Byte(0x03);
	TFT_Write_Data_Byte(0x24);
	TFT_Write_Data_Byte(0x20);
	TFT_Write_Data_Byte(0x00);

	TFT_Write_Cmd_Byte(0x20);                     // display inversion OFF

	TFT_Write_Cmd_Byte(0x36);
	TFT_Write_Data_Byte(0x48);

	TFT_Write_Cmd_Byte(0x29);                     // display on
	DelayMs();

	TFT_Set_Rotation(TFT_PORTRAIT);


}

void TFT_Write_Data_Byte(uint8_t data)
{
	/* CS_ACTIVE */
	CS_ACTIVE;
	
	/* CD/RS DATA */
	CD_DATA;

	Write_Byte(data);

	/* CS_IDLE */
	CS_IDLE;
}

void TFT_Write_Cmd_Byte(uint8_t cmd)
{
	/* CS_ACTIVE */
	CS_ACTIVE;

	/* CD/RS COMMAND */
	CD_COMMAND;

	Write_Byte(cmd);

	/* CS_IDLE */
	CS_IDLE;


}

void TFT_Write_Data_Word(uint16_t data)
{
	/* CS_ACTIVE */
	CS_ACTIVE;

	/* CD/RS DATA */
	CD_DATA;


	Write_Byte(data >> 8 );
	Write_Byte(data & 0xff );

	/* CS_IDLE */
	CS_IDLE;

}

void TFT_Write_Cmd_Word(uint16_t cmd)
{

	/* CS_ACTIVE */
	CS_ACTIVE;

	/* CD/RS COMMAND */
	CD_COMMAND;

	Write_Byte(cmd >> 8 );
	Write_Byte(cmd & 0xff );

	/* CS_IDLE */
	CS_IDLE;
}

void TFT_Write_Cmd_Data(uint16_t cmd, uint16_t data) {
	TFT_Write_Cmd_Byte(cmd);
	TFT_Write_Data_Word(data);
}

void TFT_GPIO_Init()
{
	/* SET CONTROL PINS OUTPUT */
	WR_OUTPUT;
	CD_OUTPUT;
	CS_OUTPUT;
	RD_OUTPUT;
	RESET_OUTPUT;


	/* SET DATA PINS OUTPUT */
	PIN_OUTPUT(D0_PORT, D0_PIN);
	PIN_OUTPUT(D1_PORT, D1_PIN);
	PIN_OUTPUT(D2_PORT, D2_PIN);
	PIN_OUTPUT(D3_PORT, D3_PIN);
	PIN_OUTPUT(D4_PORT, D4_PIN);
	PIN_OUTPUT(D5_PORT, D5_PIN);
	PIN_OUTPUT(D6_PORT, D6_PIN);
	PIN_OUTPUT(D7_PORT, D7_PIN);
}

void TFT_Reset()
{

	/* CS_IDLE */
	CS_IDLE;

	/* RD_IDLE */
	RD_IDLE;

	/* WR_IDLE */
	WR_IDLE;

	/* RESET_IDLE */
	RESET_IDLE;

	//DelayMs(50);

	/* RESET_IDLE */
	RESET_ACTIVE;

	DelayMs();

	/* RESET_IDLE */
	RESET_IDLE;

	DelayMs();

}

void TFT_Write_Data_Cmd(uint16_t cmd, uint16_t data)
{
	TFT_Write_Cmd_Byte(cmd);
	TFT_Write_Data_Word(data);
}


void TFT_Write_Cmd_ParamN(uint8_t cmd, int8_t N, uint8_t * block)
{
	TFT_Write_Cmd_Byte(cmd);
	while (N-- > 0)
	{
		uint8_t Z = *block++;
		TFT_Write_Data_Byte(Z);;
	}
}

void TFT_Write_Cmd_Param4(uint8_t cmd, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4)
{
	uint8_t d[4];
	d[0] = d1, d[1] = d2, d[2] = d3, d[3] = d4;
	TFT_Write_Cmd_ParamN(cmd, 4, d);
}


void TFT_Clear(uint16_t color)
{
	uint16_t i,j;

	TFT_SetAddrWindow(0,0,tft_W-1,tft_H-1);
	TFT_Write_Cmd_Byte(TFT_RAMWR);
	for(i=0;i<tft_W;i++)
	{
		for (j=0;j<tft_H;j++)
		{
			TFT_Write_Data_Word(color);
		}
	}
}

void TFT_Scroll_Vertical(int16_t top, int16_t scrollines, int16_t offset)
{
	int16_t bfa = tft_H - top - scrollines;  // bottom fixed area
	int16_t vsp;
	int16_t sea = top;
	vsp = top + offset; // vertical start position

	if (offset < 0)
	{
		vsp += scrollines;     //keep in unsigned range
	}
	sea = top + scrollines - 1;

	uint8_t d[6];           // for multi-byte parameters

	d[0] = top >> 8;        //TFA
	d[1] = top;
	d[2] = scrollines >> 8; //VSA
	d[3] = scrollines;
	d[4] = bfa >> 8;        //BFA
	d[5] = bfa;
	TFT_Write_Cmd_ParamN(0x33, 6, d);

	d[0] = vsp >> 8;        //VSP
	d[1] = vsp;
	TFT_Write_Cmd_ParamN(0x37, 2, d);

}

void drawPixel(uint16_t x, uint16_t y, uint16_t color)
{


	if (x < 0 || y < 0 || x >= tft_W || y >= tft_H)
	{
		return;
	}


	TFT_Write_Cmd_Param4(TFT_CASET, x >> 8, x, x >> 8, x);
	TFT_Write_Cmd_Param4(TFT_PASET, y >> 8, y, y >> 8, y);

	TFT_Write_Cmd_Data(TFT_RAMWR,color);
}






void TFT_Draw_Line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {

	int16_t i;
	int16_t dx,dy;
	int16_t sx,sy;
	int16_t E;

	/* distance between two points */
	if(x2 > x1)
	{
		dx = x2 - x1 ;
	}
	else
	{
		dx = x1 - x2 ;
	}

	if(y2 > y1)
	{
		dy = y2 - y1 ;
	}
	else
	{
		dy = y1 - y2 ;
	}



	/* direction of two point */

	if(x2 > x1)
	{
		sx = 1 ;
	}
	else
	{
		sx = -1 ;
	}

	if(y2 > y1)
	{
		sy = 1 ;
	}
	else
	{
		sy = -1;
	}


	if (y1 == y2) {
		if (x2 > x1) {
			TFT_DrawFastHLine(x1, y1, x2 - x1 + 1, color);
		} else {
			TFT_DrawFastHLine(x2, y1, x1 - x2 + 1, color);
		}
		return;
	} else if (x1 == x2) {
		if (y2 > y1) {
			TFT_DrawFastVLine(x1, y1, y2 - y1 + 1, color);
		} else {
			TFT_DrawFastVLine(x1, y2, y1 - y2 + 1, color);
		}
		return;
	}

	/* inclination < 1 */
	if ( dx > dy ) {
		E = -dx;
		for ( i = 0 ; i <= dx ; i++ ) {
			drawPixel( x1, y1, color );
			x1 += sx;
			E += 2 * dy;
			if ( E >= 0 ) {
				y1 += sy;
				E -= 2 * dx;
			}
		}
		/* inclination >= 1 */
	} else {
		E = -dy;
		for ( i = 0 ; i <= dy ; i++ ) {
			drawPixel( x1, y1, color );
			y1 += sy;
			E += 2 * dx;
			if ( E >= 0 ) {
				x1 += sx;
				E -= 2 * dy;
			}
		}
	}
}



void TFT_Draw_Circle(int16_t x0, int16_t y0, int16_t r,uint16_t color)
{
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	drawPixel(x0  , y0+r, color);
	drawPixel(x0  , y0-r, color);
	drawPixel(x0+r, y0  , color);
	drawPixel(x0-r, y0  , color);

	while (x<y)
	{
		if (f >= 0)
		{
			y--;
			ddF_y += 2;
			f += ddF_y;
		}

		x++;
		ddF_x += 2;
		f += ddF_x;

		drawPixel(x0 + x, y0 + y, color);
		drawPixel(x0 - x, y0 + y, color);
		drawPixel(x0 + x, y0 - y, color);
		drawPixel(x0 - x, y0 - y, color);
		drawPixel(x0 + y, y0 + x, color);
		drawPixel(x0 - y, y0 + x, color);
		drawPixel(x0 + y, y0 - x, color);
		drawPixel(x0 - y, y0 - x, color);
	}
}


void TFT_fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
	TFT_DrawFastVLine(x0, y0-r, 2*r+1, color);
	TFT_fillCircleHelper(x0, y0, r, 3, 0, color);
}

void TFT_Draw_Point(int16_t x0, int16_t y0 ,uint16_t color)
{
	int16_t r = 1 ;
	TFT_DrawFastVLine(x0, y0-r, 2*r+1, color);
	TFT_fillCircleHelper(x0, y0, r, 3, 0, color);
}

void TFT_fillCircleHelper(int16_t x0, int16_t y0, int16_t r,uint8_t cornername, int16_t delta, uint16_t color)
{

	int16_t f     = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x     = 0;
	int16_t y     = r;

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f     += ddF_y;
		}
		x++;
		ddF_x += 2;
		f     += ddF_x;

		if (cornername & 0x1) {
			TFT_DrawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
			TFT_DrawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
		}
		if (cornername & 0x2) {
			TFT_DrawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
			TFT_DrawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
		}
	}
}

void TFT_DrawRect(int16_t x, int16_t y,  int16_t w, int16_t h,  uint16_t color)
{
	TFT_DrawFastHLine(x, y, w, color);
	TFT_DrawFastHLine(x, y+h-1, w, color);
	TFT_DrawFastVLine(x, y, h, color);
	TFT_DrawFastVLine(x+w-1, y, h, color);
}

void TFT_DrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
	if ((x >= tft_W) || (y >= tft_H || h < 1))
	{
		return;
	}
	if ((y + h - 1) >= tft_H)
	{
		h = tft_H - y;
	}

	TFT_fillRect(x, y, 1, h, color);
}

void TFT_DrawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
	if ((x >= tft_W) || (y >= tft_H || w < 1))
	{
		return;
	}
	if ((x + w - 1) >=tft_W)
	{
		w =tft_W - x;
	}
	TFT_fillRect(x, y, w, 1, color);
}

void TFT_fillScreen(uint16_t color)
{
	TFT_fillRect(0, 0, tft_W, tft_H, color);
}

void TFT_SetAddrWindow(int16_t x, int16_t y, int16_t x1, int16_t y1)
{
	TFT_Write_Cmd_Param4(TFT_CASET, x >> 8, x, x1 >> 8, x1);
	TFT_Write_Cmd_Param4(TFT_PASET, y >> 8, y, y1 >> 8, y1);
}


void TFT_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	int16_t end;
	if (w < 0) {
		w = -w;
		x -= w;
	}                           //+ve w
	end = x + w;
	if (x < 0)
		x = 0;
	if (end > tft_W)
		end = tft_W;
	w = end - x;
	if (h < 0) {
		h = -h;
		y -= h;
	}                           //+ve h
	end = y + h;
	if (y < 0)
		y = 0;
	if (end > tft_H)
		end = tft_H;
	h = end - y;

	TFT_SetAddrWindow(x, y, x + w - 1, y + h - 1);
	TFT_Write_Cmd_Byte(TFT_RAMWR);
	if (h > w) {
		end = h;
		h = w;
		w = end;
	}
	while (h-- > 0) {
		end = w;
		do {
			TFT_Write_Data_Word(color);
		} while (--end != 0);
	}

}


void TFT_Print_Char14x24(uint16_t x,uint16_t y, uint8_t data)
{
	if((x>tft_W-14)||(y>tft_H-24)) return;
	uint8_t i,j,k,temp;
	TFT_SetAddrWindow(x,y,x+16-1,y+24-1);
	for(i=0;i<24/8;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<14;k++)
			{
				temp = pgm_read_byte(&(Consolas14x24[(data-' ')*(24/8)*14+k*(24/8)+i]));      
				if(temp&(0x01<<j))
				{
					drawPixel(x+k,y+(8*i+j),POINT_COLOR);
				}
			}
		}
	}
}


void TFT_Print_Char18x32(uint16_t x, uint16_t y, uint8_t data)
{
	if((x>tft_W-18)||(y>tft_H-32)) return;
	uint8_t i,j,k,temp;
	TFT_SetAddrWindow(x,y,x+18-1,y+32-1);
	for(i=0;i<32/8;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<18;k++)
			{
				temp = pgm_read_byte(&(Consolas18x32[(data-' ')*(32/8)*18+k*(32/8)+i]));          //temp=Consolas18x32[(data-' ')*(32/8)*18+k*(32/8)+i];
				if(temp&(0x01<<j))
				{
					drawPixel(x+k,y+(8*i+j),POINT_COLOR);
				}
			}
		}
	}
}


void TFT_Print_Char8x16(uint16_t x, uint16_t y, uint8_t num)
{
	uint8_t temp;
	uint8_t pos,t;
	//uint16_t x0=x;
	uint16_t colortemp=POINT_COLOR;
	if(x>tft_W-8||y>tft_H-16)return;
	num=num-' ';
	TFT_SetAddrWindow(x,y,y+16-1, x+8-1);

	for(pos=0;pos<16;pos++)
	{
		temp = pgm_read_byte(&(asc2_1608[(uint16_t)num*16+pos]));       //temp=asc2_1608[(uint16_t)num*16+pos];
		for(t=0;t<8;t++)
		{
			if(temp&0x01)drawPixel(x+t,y+pos,POINT_COLOR);
			temp>>=1;
		}
	}
	POINT_COLOR=colortemp;
}




void TFT_SetCursor(int16_t x, int16_t y)
{
	cursor_x = y;
	cursor_y = x;
}

void TFT_SetTextSize(int8_t s)
{
	textsize = s ;
}


void TFT_SetTextColor(uint16_t c)
{
	POINT_COLOR   = c;
}


void TFT_Set_Rotation(uint8_t rotation)
{
#define RGB 1
#define BGR 0

	TFT_Write_Cmd_Byte(0x36);

	if(rotation == 0)
	{
		TFT_Write_Data_Byte(0x48);
		tft_W = TFT_WIDTH;
		tft_H = TFT_HEIGHT;
	}

	if(rotation == 1)
	{
		TFT_Write_Data_Byte(0x28);
		tft_W = TFT_HEIGHT;
		tft_H = TFT_WIDTH;
	}

	if(rotation == 2)
	{
		TFT_Write_Data_Byte(0x98);
		tft_W =TFT_WIDTH;
		tft_H = TFT_HEIGHT;
	}

	if(rotation == 3)
	{
		TFT_Write_Data_Byte(0xF8);
		tft_W = TFT_HEIGHT;
		tft_H =TFT_WIDTH;
	}

}

void TFT_Print_String18x32(int8_t *string)
{
	uint8_t i=0;
	uint8_t font_w=18;
	uint8_t font_h=32;

	while(*(string+i)!='\0')
	{

		if(*(string+i)==0)
		{
			return;
		}

		if(*(string+i)=='\n')
		{
			cursor_x+=font_h;
			cursor_y=0;
			string++;
		}

		if(cursor_y>tft_W-font_w)
		{
			cursor_y=0;cursor_x+=font_h;
		}

		if(cursor_x>tft_H-font_h)
		{
			cursor_x=cursor_y=0;
		}

		TFT_Print_Char18x32(cursor_y,cursor_x,*(string+i));
		cursor_y+=font_w;
		i++;
	}
}


void TFT_Print_String14x24(int8_t *string)
{
	uint8_t i=0;
	uint8_t font_w=14;
	uint8_t font_h=24;

	while(*(string+i)!='\0')
	{

		if(*(string+i)==0)
		{
			return;
		}

		if(*(string+i)=='\n')
		{
			cursor_x+=font_h;
			cursor_y=0;
			string++;
		}

		if(cursor_y>tft_W-font_w)
		{
			cursor_y=0;cursor_x+=font_h;
		}

		if(cursor_x>tft_H-font_h)
		{
			cursor_x=cursor_y=0;
		}

		TFT_Print_Char14x24(cursor_y,cursor_x,*(string+i));
		cursor_y+=font_w;
		i++;
	}
}

void TFT_Print_String8x16(int8_t *string)
{
	uint8_t i=0;
	uint8_t font_w=8;
	uint8_t font_h=16;

	while(*(string+i)!='\0')
	{

		if(*(string+i)==0)
		{
			return;
		}

		if(*(string+i)=='\n')
		{
			cursor_x+=font_h;
			cursor_y=0;
			string++;
		}

		if(cursor_y>tft_W-font_w)
		{
			cursor_y=0;cursor_x+=font_h;
		}

		if(cursor_x>tft_H-font_h)
		{
			cursor_x=cursor_y=0;
		}

		TFT_Print_Char8x16(cursor_y,cursor_x,*(string+i));
		cursor_y+=font_w;
		i++;
	}
}

void TFT_Print_String(int8_t *string)
{
	switch(textsize)
	{
	case 1 : TFT_Print_String8x16(string);
	break;
	case 2 : TFT_Print_String14x24(string);
	break;
	case 3 : TFT_Print_String18x32(string);
	break;

	}
}


void TFT_Print_Number(long  Number)
{

	long Temp =1;

	if (Number <= 0)
	{
		switch(textsize)
		{
		case 1 : TFT_Print_Char8x16(cursor_y,cursor_x,'0');  cursor_y+=8;
		break;
		case 2 : TFT_Print_Char14x24(cursor_y,cursor_x,'0'); cursor_y+=14;
		break;
		case 3 : TFT_Print_Char18x32(cursor_y,cursor_x,'0'); cursor_y+=18;
		break;

		}
	}
	else
	{
		while (Number!=0)
		{
			uint8_t Reminder = Number % 10;
			Number = Number / 10 ;
			Temp = Temp * 10 + Reminder ;
		}
		while (Temp != 1)
		{
			uint8_t Reminder2 = Temp % 10 ;

			switch(textsize)
			{
			case 1 : TFT_Print_Char8x16(cursor_y,cursor_x,Reminder2+48);   cursor_y+=8;
			break;
			case 2 : TFT_Print_Char14x24(cursor_y,cursor_x,Reminder2+48);  cursor_y+=14;
			break;
			case 3 : TFT_Print_Char18x32(cursor_y,cursor_x,Reminder2+48);  cursor_y+=18;
			break;

			}
			Temp = Temp / 10 ;
		}
	}


}



