/*
 * Project: N|Watch
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/diy-digital-wristwatch/
 */

#ifndef DRAW_H_
#define DRAW_H_
#include "c2000ware_libraries.h"

typedef  uint16_t byte;

void draw_string_P(const char* string, bool invert, byte x, byte y);
void draw_string(char* string, bool invert, byte x, byte y);
//void draw_string_time(char*, bool, byte, byte);
void draw_bitmap(byte x, byte yy, const byte* bitmap, byte w, byte h, bool invert, byte offsetY);
void draw_flushArea(byte x, byte y, byte w, byte h);
void draw_clearArea(byte x, byte y, byte w);
void draw_end(void);
void draw_init(void);

#endif /* DRAW_H_ */
