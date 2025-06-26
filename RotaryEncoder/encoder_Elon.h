#ifndef _ENCODER_ELON_H
#define _ENCODER_ELON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <string.h>
#include <stdint.h>
#include "board.h"
#include "c2000ware_libraries.h"
#include "FreeRTOS.h"
#include "queue.h"

#define constrain(amt,low,high) ((amt<low)? low:((amt>high)? high:amt))
//Code area
typedef enum 
{
    FORWARD=0,
    REVERSE
}EC_direction;
typedef enum
{
    IPS2=0,//2 increments/step
    IPS4=0,//4 increments/step
}rotaryType;
typedef struct _encoder_
{
    uint32_t pin1;
    uint32_t pin2;
    float counterMin;
    float counterMax;
    float counter;
    //float counterDefault;
    rotaryType countType;
    float stepSize;
    EC_direction ECD;
    volatile unsigned char a0;// for A channel state storage 
    volatile unsigned char b0;// for B channel state storage 
    volatile unsigned char c0;// for pushButton state storage 
    volatile unsigned char flag_ab;
    uint16_t debounceCountMax;
    uint16_t highCount;
    uint16_t lowCount;
    uint16_t lowCountLongPress;
    uint16_t flag_buttonPressed;
    uint16_t flag_lastButtonState;

}encoder_t;

#define EC_DEFAULT {\
    0.0f,\
    0.0f,\
    0.0f,\
    0.0f,\
    FORWARD,\
    0,\
    0,\
    0,\
    0,\
    0,\
    0,\
    0,\
    0,\
    0,\
    0,\
}
typedef struct _encoder_ *encoderHandle;


encoderHandle encoder_Init(void *pmemory, const size_t numBytes);
float getEncoder(encoderHandle handle);
void setEncoder(encoderHandle handle,float min,float max, float step,float defaultValue);
extern __interrupt void INT_R_ENC1_XINT_ISR(void);
QueueHandle_t getQueueRENC(void);
QueueHandle_t getQueueRENC2(void);

#ifdef __cplusplus
}
#endif


#endif 

