/*
 * Project: N|Watch
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/diy-digital-wristwatch/
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "event_groups.h"               // ARM.FreeRTOS::RTOS:Event Groups
#include "semphr.h"                     // ARM.FreeRTOS::RTOS:Core

#include "draw.h"
#include "oledDriver.h"
#include "game2.h"

#define NOINVERT	false
#define INVERT		true


#define CAR_COUNT	3
#define CAR_WIDTH	12
#define CAR_LENGTH	15
#define ROAD_SPEED	6

static uint32_t g_xres, g_yres, g_bpp;
static uint8_t *g_framebuffer;

static xSemaphoreHandle g_xSemaphore;
static xSemaphoreHandle g_xSPIMutex;

EventGroupHandle_t g_xEventhandle;
TaskHandle_t task1;
TaskHandle_t task2;
TaskHandle_t task3;

struct car {
	int x;
	int y;
};

struct car g_cars[3] = {
	{0, 0},
	{0, 22},
	{0, 43}
};

static const byte carImg[] ={
	0x40,0xF8,0xEC,0x2C,0x2C,0x38,0xF0,0x10,0xD0,0x30,0xE8,0x4C,0x4C,0x9C,0xF0,
	0x02,0x1F,0x37,0x34,0x34,0x1C,0x0F,0x08,0x0B,0x0C,0x17,0x32,0x32,0x39,0x0F,
};

static const byte clearImg[30] ={0};

static const byte roadMarking[] ={
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
};

#if 0
void car_test(void)
{
	g_framebuffer = OLED_GetFrameBuffer(&g_xres, &g_yres, &g_bpp);
	draw_init();
	draw_end();
	
	draw_bitmap(0, 0, carImg, 15, 16, NOINVERT, 0);
	draw_flushArea(0, 0, 15, 16);
	
	draw_bitmap(0, 16, roadMarking, 8, 1, NOINVERT, 0);
	draw_flushArea(0, 16, 8, 1);

	while (1);
}
#endif

static void ShowCar(struct car *pcar)
{
	draw_bitmap(pcar->x, pcar->y, carImg, 15, 16, NOINVERT, 0);
	draw_flushArea(pcar->x, pcar->y, 15, 16);
}

static void HideCar(struct car *pcar)
{
	draw_bitmap(pcar->x, pcar->y, clearImg, 15, 16, NOINVERT, 0);
	draw_flushArea(pcar->x, pcar->y, 15, 16);
}

static void Car1Task(void *params)
{
	struct car *pcar = (struct car *)params;

	ShowCar(pcar);
	// get semaphore
	//xQueueSemaphoreTake(g_xSemaphore,portMAX_DELAY);
	
	for(;;)
	{
			if (pcar->x <=113)
			{
				/* éš�è—�æ±½è½¦ */
				HideCar(pcar);
				
				/* è°ƒæ•´ä½�ç½® */
				pcar->x += 2;
				if (pcar->x > 113)
				{
					pcar->x =113;

				}
				
				/* é‡�æ–°æ˜¾ç¤ºæ±½è½¦ */
				ShowCar(pcar);
				
				vTaskDelay(50);
				if(pcar->x ==113)
				{
                   // xSemaphoreGive(g_xSemaphore);
                    //vTaskDelete(NULL);
				    xEventGroupSetBits(g_xEventhandle, 1<<3);
				}

			}
	}
}
static void Car2Task(void *params)
{
    struct car *pcar = (struct car *)params;

    ShowCar(pcar);
    //vTaskDelay(1000);
    // get semaphore
    //xQueueSemaphoreTake(g_xSemaphore,portMAX_DELAY);
  // xEventGroupWaitBits(g_xEventhandle, 1<<3, pdTRUE, pdTRUE, portMAX_DELAY);
    for(;;)
    {
            if (pcar->x <=113)
            {
                /* éš�è—�æ±½è½¦ */
                HideCar(pcar);

                /* è°ƒæ•´ä½�ç½® */
                pcar->x += 1;
                if (pcar->x > 113)
                {
                    pcar->x =113;

                }

                /* é‡�æ–°æ˜¾ç¤ºæ±½è½¦ */
                ShowCar(pcar);

                vTaskDelay(50);
                //DEVICE_DELAY_US(50000);
                if(pcar->x ==113)
                {
                   //xSemaphoreGive(g_xSemaphore);
                    xEventGroupSetBits(g_xEventhandle, 1<<1);
                  // vTaskDelete(NULL);
                }

            }
    }
}
static void Car3Task(void *params)
{
    struct car *pcar = (struct car *)params;

    ShowCar(pcar);
    // get semaphore
    //vTaskDelay(1000);
    //xQueueSemaphoreTake(g_xSemaphore,portMAX_DELAY);
    xEventGroupWaitBits(g_xEventhandle, 1<<3|1<<1, pdTRUE, pdFALSE, portMAX_DELAY);
    for(;;)
    {
            if (pcar->x <=113)
            {
                /* éš�è—�æ±½è½¦ */
                HideCar(pcar);

                /* è°ƒæ•´ä½�ç½® */
                pcar->x += 1;
                if (pcar->x > 113)
                {
                    pcar->x =113;

                }

                /* é‡�æ–°æ˜¾ç¤ºæ±½è½¦ */
                ShowCar(pcar);

               //vTaskDelay(50);
               DEVICE_DELAY_US(50000);
                if(pcar->x ==113)
                {
                    //xSemaphoreGive(g_xSemaphore);
                    vTaskDelete(NULL);
                }

            }
    }
}
void car_game(void)
{
	//int x;
	int i, j;
    g_xSPIMutex=xSemaphoreCreateMutex();
	draw_init();
	draw_end();

	/* roadmark*/
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 9; j++)
		{
			draw_bitmap(16*j, 20+20*i, roadMarking, 8, 1, NOINVERT, 0);
			draw_flushArea(16*j, 20+20*i, 8, 1);
		}
	}
	    //g_xSemaphore=xSemaphoreCreateBinary();
	  //  g_xSemaphore=xSemaphoreCreateMutex();
	    g_xEventhandle=xEventGroupCreate();
	  // xSemaphoreGive(g_xSemaphore);
	/* åˆ›å»º3ä¸ªæ±½è½¦ä»»åŠ¡ */
#if 0
	for (i = 0; i < 3; i++)
	{
		draw_bitmap(g_cars[i].x, g_cars[i].y, carImg, 15, 16, NOINVERT, 0);
		draw_flushArea(g_cars[i].x, g_cars[i].y, 15, 16);
	}
#else
	xTaskCreate(Car1Task, "car1Task", 256, &g_cars[0], 1, &task1);
	xTaskCreate(Car2Task, "car2Task", 256, &g_cars[1], 2, &task2);
	xTaskCreate(Car3Task, "car3Task", 256, &g_cars[2], 3, &task3);

#endif
}

void getSPImutex(void)
{
    xSemaphoreTake(g_xSPIMutex,portMAX_DELAY);

}
void releaseSPImutex(void)
{
    xSemaphoreGive(g_xSPIMutex);
}
