#include "encoder_Elon.h"


encoder_t roataryEncoder1;
encoder_t *currentEncoder=&roataryEncoder1;
encoderHandle  roataryEncoderHandler=NULL;

static QueueHandle_t g_QueueRENC;
static uint16_t RENCQueueStorageBuffer[10*sizeof(int16_t)];
static StaticQueue_t g_StructQueue;

static QueueHandle_t g_QueueRENC2;

void setEncoder(encoderHandle handle,float min,float max, float step,float defaultValue)
{
    encoder_t *obj= (encoder_t *) handle;
    obj->counterMax=max;
    obj->counterMin=min;
    obj->counter=defaultValue;
    obj->stepSize=(obj->ECD==FORWARD)? step : -step;

    return;
}

float getEncoder(encoderHandle handle)
{
    encoder_t *obj= (encoder_t *) handle;
    float result;
    result=obj->counter;
    return result;
}

encoderHandle encoder_Init(void *pmemory, const size_t numBytes)
{
    encoderHandle handle;
    encoder_t *obj;

    if(numBytes < sizeof(encoder_t))
    {
        return((encoderHandle)NULL);
    }

    // assign the handle
    handle = (encoderHandle)pmemory;

    // assign the object
    obj = (encoder_t *)handle;
    obj->pin1=R_ENC1;
    obj->pin2=R_ENC2;
    obj->a0=GPIO_readPin(obj->pin1);
    obj->b0=GPIO_readPin(obj->pin2);
    obj->flag_ab=(obj->a0==obj->b0);
    obj->countType=IPS2;
    g_QueueRENC=xQueueCreateStatic(10, sizeof(int16_t), RENCQueueStorageBuffer,&g_StructQueue);
    g_QueueRENC2=xQueueCreate(10,sizeof(int16_t));
    return handle;
}
__interrupt void INT_R_ENC1_XINT_ISR(void)
{
    static uint32_t a0=0;
    static uint32_t b0=0;
    int16_t incremental=1;
    uint32_t a=GPIO_readPin(currentEncoder->pin1);
    uint32_t b=GPIO_readPin(currentEncoder->pin2);
    if(a!=a0)
    {
        a0=a;
        if(b!=b0)
        {
            b0=b;
            incremental=((a==b)? 1:-1);
            if(currentEncoder->countType && ((a==b)!=currentEncoder->flag_ab))
            {
                incremental=((a==b)? 1:-1);
            }
            currentEncoder->flag_ab=(a==b);
            xQueueSendToBackFromISR(g_QueueRENC,&incremental,NULL);
            xQueueSendToBackFromISR(g_QueueRENC2,&incremental,NULL);
        }
    }
    Interrupt_clearACKGroup(INT_R_ENC1_XINT_INTERRUPT_ACK_GROUP);
}

QueueHandle_t getQueueRENC(void)
{
     return g_QueueRENC;
}
QueueHandle_t getQueueRENC2(void)
{
     return g_QueueRENC2;
}

