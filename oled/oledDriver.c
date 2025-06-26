/*
    * @file    oledDriver.c
    * @author  
    * @version V1.0
    * @date    2025-05-23
    * @brief   OLED driver implementation
    *
    * This file contains the implementation of functions to control an OLED display.
    * It includes functions for initialization, writing commands and data, and displaying characters.
    *
    * @note    This code is based on TI F280039C  platform and may require modifications for other platforms on the following functions.
    * @functions:
    *          - OLED_WriteCmd
    *          - OLED_WriteData
    *          - OLED_WriteNBytes
*/


#include "oledDriver.h"

static uint16_t oledBuffer[FRAME_BUFFER_SIZE];

typedef enum
{
    H_RIGHT     = 0x26,
    H_LEFT      = 0x27,
}H_SCROLL_DIR;  


typedef enum
{
    HV_RIGHT    = 0x29,
    HV_LEFT     = 0x2A,
}HV_SCROLL_DIR;     
typedef enum
{
    COM_PIN_SEQ     = 0,
    COM_PIN_ALT     = 1,
}COM_PINS_MODE; 
typedef enum
{
    COM_NOREMAP     = 0,
    COM_REMAP       = 1,
}COM_REMAP_STATE;   

    
typedef enum
{
    LEVEL_0     = 0x00,
    LEVEL_1     = 0x20,
    LEVEL_2     = 0x30,
}VCOMH_LEVEL;   


typedef enum
{
    PUMP_DISABLE    = 0,
    PUMP_ENABLE     = 1,
}CHARGE_PUMP_STATE; 

typedef enum
{
    H_ADDR_MODE     = 0,    
    V_ADDR_MODE     = 1,    
    PAGE_ADDR_MODE  = 2,    
}MEM_MODE;  

// OLED display control commands
#define ENTIRE_DISP_ON()       OLED_WriteCmd(0xA5) 
#define ENTIRE_DISP_OFF()      OLED_WriteCmd(0xA4) 
#define DISP_NORMAL()          OLED_WriteCmd(0xA6)  
#define DISP_INVERSE()         OLED_WriteCmd(0xA7)
#define DISP_ON()              OLED_WriteCmd(0xAF) 
#define DISP_OFF()             OLED_WriteCmd(0xAE) 


// Scroll control commands
#define SCROLL_ON()             OLED_WriteCmd(0x2F)
#define SCROLL_OFF()            OLED_WriteCmd(0x2E)


// Memory address mode commands
#define OLED_SEG_REMAP()        OLED_WriteCmd(0xA1)
#define OLED_SEG_NOREMAP()      OLED_WriteCmd(0xA0)

// Scan direction commands
#define OLED_SCAN_NORMAL()      OLED_WriteCmd(0xC0)
#define OLED_SCAN_REMAP()       OLED_WriteCmd(0xC8)


// OLED write commands
static int OLED_WriteCmd(uint16_t cmd)
{
    if(GPIO_readPin(DC_control)) WRITECMD;
    SPI_pollingNonFIFOTransaction(OLED_BASE,8U,cmd);
    return 0;
}

// OLED write data
static int OLED_WriteData(uint16_t data)
{
    if(!GPIO_readPin(DC_control)) WRITEDATA;
    SPI_pollingNonFIFOTransaction(OLED_BASE,8U,data);
    return 0;
}

// OLED write multiple bytes
static int OLED_WriteNBytes(uint16_t *buf, uint16_t length)
{
    if(!GPIO_readPin(DC_control)) WRITEDATA;
    uint16_t index;
    for(index=0;index<length;index++)
    {
        SPI_pollingNonFIFOTransaction(OLED_BASE,8U,buf[index]);
    }
    return 0;

}

// OLED set multiplex ratio
static void OLED_SetContrastValue(uint16_t value)
{
    OLED_WriteCmd(0x81);
    OLED_WriteCmd(value);
}


// OLED set display start line
static void OLED_H_Scroll(H_SCROLL_DIR dir, uint16_t start, uint16_t fr_time, uint16_t end)
{
    if((dir != H_RIGHT) && (dir != H_LEFT))     return;
    if((start>0x07) || (fr_time>0x07) || (end>0x07))    return;
    OLED_WriteCmd(dir);
    OLED_WriteCmd(0x00);
    OLED_WriteCmd(start);
    OLED_WriteCmd(fr_time);
    OLED_WriteCmd(end);
    OLED_WriteCmd(0x00);
    OLED_WriteCmd(0xFF);
}

static void OLED_HV_Scroll(HV_SCROLL_DIR dir, uint16_t start, uint16_t fr_time, uint16_t end, uint16_t offset)
{
    if((dir != HV_RIGHT) && (dir != HV_LEFT))     return;
    if((start>0x07) || (fr_time>0x07) || (end>0x07) || (offset>0x3F))    return;
    OLED_WriteCmd(dir);
    OLED_WriteCmd(0x00);
    OLED_WriteCmd(start);
    OLED_WriteCmd(fr_time);
    OLED_WriteCmd(end);
    OLED_WriteCmd(offset);
}

// OLED set vertical scroll area
static void OLED_SetVScrollArea(uint16_t area, uint16_t row_num)
{
    if((area>0x3F) || (row_num>0x7F))       return;
    OLED_WriteCmd(0xA3);
    OLED_WriteCmd(area);
    OLED_WriteCmd(row_num);
}


static MEM_MODE mem_mode = PAGE_ADDR_MODE;  


static void OLED_SetColAddr_PAGE(uint16_t addr)
{
    if(mem_mode != PAGE_ADDR_MODE)  return;
    if(addr > 0x7F)   return;
    OLED_WriteCmd(0x00 + (addr & 0x0F));
    OLED_WriteCmd(0x10 + (addr>>4));
}


static void OLED_SetMemAddrMode(MEM_MODE mode)
{
    if((mode != H_ADDR_MODE) && (mode != V_ADDR_MODE) && (mode != PAGE_ADDR_MODE))      return;

    OLED_WriteCmd(0x20);
    OLED_WriteCmd(mode);
    mem_mode = mode;
}


static void OLED_SetColAddr_HV(uint16_t start, uint16_t end)
{
    if(mem_mode == PAGE_ADDR_MODE)      return;
    if((start > 127) || (end > 127))    return;
    OLED_WriteCmd(0x21);
    OLED_WriteCmd(start);
    OLED_WriteCmd(end);
}


static void OLED_SetPageAddr_HV(uint16_t start, uint16_t end)
{
    if(mem_mode == PAGE_ADDR_MODE)      return;
    if((start > 7) || (end > 7))        return; 
    OLED_WriteCmd(0x22);
    OLED_WriteCmd(start);
    OLED_WriteCmd(end);
}


static void OLED_SetPageAddr_PAGE(uint16_t addr)
{
    if(mem_mode != PAGE_ADDR_MODE)  return;
    if(addr > 7)   return;
    OLED_WriteCmd(0xB0 + addr);
}



static void OLED_SetDispStartLine(uint16_t line)
{
    if(line > 63)       return;
    OLED_WriteCmd(0x40 + line);
}


static void OLED_SetMuxRatio(uint16_t ratio)
{
    if((ratio < 15) || (ratio > 63))      return;
    OLED_WriteCmd(0xA8);
    OLED_WriteCmd(ratio);
}


static void OLED_SetDispOffset(uint16_t offset)
{
    if(offset > 63)     return;
    OLED_WriteCmd(0xD3);
    OLED_WriteCmd(offset);
}


static void OLED_SetComConfig(COM_PINS_MODE mode, COM_REMAP_STATE state)
{
    if((mode != COM_PIN_SEQ) && (mode != COM_PIN_ALT))      return;
    if((state != COM_NOREMAP) && (state != COM_REMAP))      return;
    
    OLED_WriteCmd(0xDA);
    OLED_WriteCmd(0x02 + (mode << 4) + (state << 5));
}



static void OLED_SetDCLK_Freq(uint16_t div, uint16_t freq)
{
    if((div>0x0F) || (freq>0x0F))       return;
    OLED_WriteCmd(0xD5);
    OLED_WriteCmd(div + (freq<<4));
}


static void OLED_SetPreChargePeriod(uint16_t phase1, uint16_t phase2)
{
    if((phase1>0x0F) || (phase2>0x0F))       return;
    OLED_WriteCmd(0xD9);
    OLED_WriteCmd(phase1 + (phase2<<4));    
}


static void OLED_SetVcomhLevel(VCOMH_LEVEL level)
{
    if((level != LEVEL_0) && (level != LEVEL_1) && (level != LEVEL_2))      return;
    OLED_WriteCmd(0xDB);
    OLED_WriteCmd(level);
}



static void OLED_SetChargePump(CHARGE_PUMP_STATE state)
{
    if((state != PUMP_DISABLE) && (state != PUMP_ENABLE))   return;
    OLED_WriteCmd(0x8D);
    OLED_WriteCmd((state<<2) + 0x10);
}


void OLED_Init(void)
{   
    
    OLED_SetMemAddrMode(PAGE_ADDR_MODE);    
    OLED_SetMuxRatio(0x3F);                 
    OLED_SetDispOffset(0x00);               
    OLED_SetDispStartLine(0x00);            
    OLED_SEG_REMAP();                       
    OLED_SCAN_REMAP();                      
    OLED_SetComConfig(COM_PIN_SEQ, COM_NOREMAP);          
    OLED_SetContrastValue(0x7F);            
    ENTIRE_DISP_OFF();                      
    DISP_NORMAL();                          
    OLED_SetDCLK_Freq(0x00, 0x08);          
    OLED_SetChargePump(PUMP_ENABLE);        
    
    OLED_SetComConfig(COM_PIN_ALT, COM_NOREMAP);
    
    DISP_ON();
}



void OLED_SetPosition(uint16_t page, uint16_t col)
{
    OLED_SetPageAddr_PAGE(page);
    OLED_SetColAddr_PAGE(col);
}


void OLED_Clear(void)
{
    uint16_t i = 0;
    uint16_t buf[128] = {0};
    
    for(i=0; i<8; i++)
    {
        OLED_SetPosition(i, 0);
        OLED_WriteNBytes(&buf[0], 128);
    }
}


void OLED_PutChar(uint16_t x, uint16_t y, char c)
{
    uint16_t page = y;
    uint16_t col  = x*8;
    
    if (y > 7 || x > 15)
        return;
    
    OLED_SetPosition(page, col);
    OLED_WriteNBytes((uint16_t*)&ascii_font[c][0], 8);
    
    OLED_SetPosition(page + 1, col);
    OLED_WriteNBytes((uint16_t*)&ascii_font[c][8], 8);
}


int OLED_PrintString(uint16_t x, uint16_t y, const char *str)
{   
    int i = 0;
    while (str[i])
    {
        OLED_PutChar(x, y, str[i]);
        x++;
        if(x > 15)
        {
            x  = 0;
            y += 2;
        }
                
        i++;
    }
    return i;
}


void OLED_PrintChinese(uint16_t x, uint16_t y)
{   
	extern uint16_t g_chinese_fonts[3][32];

	uint16_t page = y;
	uint16_t col  = x*8;
	
	if (y > 7 || x > 15)
			return;
	
	int i;
	for (i = 0; i < sizeof(g_chinese_fonts)/sizeof(g_chinese_fonts[0]); i++)
	{
		
    OLED_SetPosition(page, col);

		
    OLED_WriteNBytes((uint16_t*)&g_chinese_fonts[i][0], 16);

		
    OLED_SetPosition(page+1, col);
		
		
    OLED_WriteNBytes((uint16_t*)&g_chinese_fonts[i][16], 16);

		
		col += 16;
	}
}



void OLED_ClearLine(uint16_t x, uint16_t y)
{
    for (;x < 16; x++)
    {
        OLED_PutChar(x, y, ' ');
    }
}


int OLED_PrintHex(uint16_t x, uint16_t y, uint32_t val, uint16_t pre)
{
    uint16_t hex_tab[]={'0','1','2','3','4','5','6','7',\
                             '8','9','a','b','c','d','e','f'};
	int i, j;
	char arr[11];

	
    arr[0] = '0';
    arr[1] = 'x';
    arr[10] = '\0';

    j = 2;
	for (i = 7; i >= 0; i--)
	{
        arr[j] = hex_tab[(val >> (i*4)) & 0xf];
        if ((j != 2) || (arr[j] != '0'))
        {
            j++;
        }        
	}
    if (j == 2)
        j++;
    arr[j] = '\0';

    if (pre)
    {
        OLED_PrintString(x, y, arr);
        return j;
    }
    else
    {
        OLED_PrintString(x, y, arr+2);
        return j - 2;
    }
}

int OLED_PrintSignedVal(uint16_t x, uint16_t y, int32_t val)
{
    char str[16];
    char revert_str[16];
    int i = 0, j = 0;
    int mod;

    if (val < 0)
    {
        str[i++] = '-';
        val = 0 - val;
    }
    else if (val == 0)
    {
        str[i++] = '0';
    }

    while (val)
    {
        mod = val % 10;
        revert_str[j++] = mod + '0';
        val = val / 10;
    }

    while (j)
    {
        str[i++] = revert_str[j-1];
        j--;
    } 
    
    str[i] = '\0';
    OLED_PrintString(x, y, str);
    return i;
}


void * OLED_GetFrameBuffer(uint32_t *pXres, uint32_t *pYres, uint32_t *pBpp)
{
    *pXres = FRAME_WIDTH;
    *pYres = FRAME_HEIGHT;
    *pBpp  = 1;
    return oledBuffer;
}


void OLED_Flush(void)
{
      uint16_t i;
      for(i=0;i<8;i++)
      {
         OLED_WriteCmd(0xb0+i); 
         OLED_WriteCmd(0x00);   
         OLED_WriteCmd(0x10);   
         
         
         OLED_WriteNBytes(&oledBuffer[128*i], 128);
    }
}


void OLED_FlushRegion(int col, int row, int width, int heigh)
{
#if 0    
      uint16_t i;
      uint16_t page = row / 8;
      
      for (i = 0; i < heigh/8; i++)
      {
         OLED_SetPosition(page+i, col);
         OLED_WriteNBytes(&oledBuffer[col + (page + i) * FRAME_WIDTH], width);
        }
#else
    uint16_t i;
    uint16_t page = row / 8;
    uint16_t page_cnt = ((row % 8) + heigh +7)/8;
    
    for (i = 0; i < page_cnt; i++)
    {
        if (page+i < 8)
        {
           OLED_SetPosition(page+i, col);
           OLED_WriteNBytes(&oledBuffer[col + (page + i) * FRAME_WIDTH], width);
        }
      }

#endif
}


void OLED_ClearFrameBuffer(void)
{
    memset(oledBuffer, 0, sizeof(oledBuffer));
}

void OLED_Test(void)
{
	int cnt = 0;
    OLED_Init();
	
	OLED_Clear();

    
	while (1)
	{
		
	    OLED_PrintString(0, 0, "Elon");
		
		OLED_PrintString(0, 2, "I love Nene!");
		
		OLED_PrintSignedVal(0, 4, cnt);
		cnt++;

		DEVICE_DELAY_US(1000000);
	}
}


