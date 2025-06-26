// Compiler: TI C2000
#ifndef __DRIVER_OLED_H
#define __DRIVER_OLED_H

#include <stdint.h>
#include <strings.h>
#include "c2000ware_libraries.h"
#include "ascii_font.h"

#define FRAME_WIDTH			128
#define FRAME_HEIGHT		64
#define FRAME_BUFFER_SIZE	((FRAME_WIDTH * FRAME_HEIGHT) / 8)
#define WRITECMD GPIO_writePin(DC_control, 0)
#define WRITEDATA GPIO_writePin(DC_control, 1)

void OLED_Init(void);
void OLED_SetPosition(uint8_t page, uint8_t col);
void OLED_Clear(void);
void OLED_PutChar(uint8_t x, uint8_t y, char c);
int OLED_PrintString(uint8_t x, uint8_t y, const char *str);
void OLED_PrintChinese(uint8_t x, uint8_t y);
void OLED_ClearLine(uint8_t x, uint8_t y);
int OLED_PrintHex(uint8_t x, uint8_t y, uint32_t val, uint8_t pre);
int OLED_PrintSignedVal(uint8_t x, uint8_t y, int32_t val);
void * OLED_GetFrameBuffer(uint32_t *pXres, uint32_t *pYres, uint32_t *pBpp);
void OLED_Flush(void);
void OLED_ClearFrameBuffer(void);
void OLED_Test(void);

#endif /* __DRIVER_OLED_H */

