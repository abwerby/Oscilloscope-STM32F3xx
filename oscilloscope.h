




#ifndef	_OSCILLOSCOPE_H_
#define _OSCILLOSCOPE_H_

#define CLK 	72000000UL
#define GIGA	1000000000UL
#define SAMPLES		1024*4
#define MAX_DIGITAL		1023


void System_Config();
void OSC_Update_Samples();
void OSC_Process_Samples();
void OSC_Update_Screen_Info();
void OSC_Draw_Samples();
void OSC_Clear_Screen();
void OSC_Config();

void ButtonISR();
void EncoderISR();
void Change_dt();
void Change_TimDiv();
void Change_VoltDiv();
void Change_Voffest();

long map(long x, long in_min, long in_max, long out_min, long out_max);
uint32_t mean(uint16_t * arr, uint32_t arr_size);
uint32_t Period_Time(uint16_t * array, uint32_t arr_size, uint16_t Avg, uint32_t S_Time);
void Net();
uint16_t find_max (uint16_t * array, uint32_t arr_size);
uint16_t find_min (uint16_t * array, uint32_t arr_size);

#endif

