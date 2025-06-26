#include "queuetest.h"


extern encoder_t roataryEncoder1;
extern encoder_t *currentEncoder;
extern encoderHandle  roataryEncoderHandler;
static QueueHandle_t g_QueueRENC;
static QueueHandle_t g_QueueRENC2;
static TaskHandle_t rotaryTaskHandle1=NULL;
static TaskHandle_t rotaryTaskHandle2=NULL;
static SemaphoreHandle_t xSemaphoreBinDisplay=NULL;

static void counterUpdate(int16_t input)
{
    currentEncoder->counter=constrain((currentEncoder->counter+currentEncoder->stepSize*input),currentEncoder->counterMin,currentEncoder->counterMax);

}
static void encoderTask1(void* parameters)
{
    int16_t rdata;
    setEncoder(roataryEncoderHandler,10,100,3,50);
    OLED_PrintString(0,0,"RotaryEncoder:");
    OLED_PrintSignedVal(0, 3, currentEncoder->counter);
    for(;;)
    {
        xQueueReceive(g_QueueRENC,&rdata,portMAX_DELAY);
       // xSemaphoreTake(xSemaphoreBinDisplay,portMAX_DELAY);
        OLED_Clear();
        OLED_PrintString(0,0,"RotaryEncoder:");
        counterUpdate(rdata);
        OLED_PrintSignedVal(0, 3, currentEncoder->counter);
        OLED_PrintSignedVal(0, 5, uxTaskGetStackHighWaterMark(rotaryTaskHandle1));
        //xSemaphoreGive(xSemaphoreBinDisplay);
//        xTaskNotifyGiveIndexed(rotaryTaskHandle2,xArrayIndex);
        xTaskNotifyGive(rotaryTaskHandle2);
    }

}
static void encoderTask2(void* parameters)
{
    int16_t rdata;
    //setEncoder(roataryEncoderHandler,1,10,1,5);
    static int16_t counter=5;
    //OLED_PrintSignedVal(3, 3, counter);
    for(;;)
    {

        xQueueReceive(g_QueueRENC2,&rdata,portMAX_DELAY);
//        ulTaskNotifyTakeIndexed(xArrayIndex,pdTRUE,portMAX_DELAY);
        ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
        //xSemaphoreTake(xSemaphoreBinDisplay,portMAX_DELAY);
        counter=constrain((counter+rdata),0,10);
        OLED_PrintSignedVal(3, 3,counter);
        OLED_PrintSignedVal(3, 5, uxTaskGetStackHighWaterMark(rotaryTaskHandle2));
        //xSemaphoreGive(xSemaphoreBinDisplay);
    }

}
void rotaryTest(void)
{
    roataryEncoderHandler=encoder_Init(&roataryEncoder1,sizeof(roataryEncoder1));
    g_QueueRENC=getQueueRENC();
    g_QueueRENC2=getQueueRENC2();
    xSemaphoreBinDisplay=xSemaphoreCreateBinary();
    xSemaphoreGive(xSemaphoreBinDisplay);
    xTaskCreate(encoderTask1, "rotaryTest1", 300, NULL, 1, &rotaryTaskHandle1);
    xTaskCreate(encoderTask2, "rotaryTest2", 300, NULL, 2, &rotaryTaskHandle2);
}
