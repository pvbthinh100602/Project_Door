#include "peripheral.h"

unsigned char arrayMapOfNumber [8] = {'1','2','3','A','4','5','6','B'};
unsigned int ReadValueAdc = 0;
unsigned char isLock = 1;
unsigned char numberValue = 0;
unsigned char isDoorOpenInside = 0;
unsigned char isDoorOpenOutside = 0;

void init_peripheral(){
    // RD0 is input: ir sensor
    // RD1 is output: buzzer
    // RD2 is output: relay
    TRISD = 0x01;
    PORTDbits.RD1 = 0;
    PORTDbits.RD2 = 0;
}

unsigned char isDoorOpen(){
    if(PORTDbits.RD0 == 0){
        return 0;
    }
    return 1;
}

unsigned char isButtonNumber()
{
    int i;
    for (i = 0; i < 8; i++)
        if (key_code[i] == 1)
        {
            numberValue = arrayMapOfNumber[i];
            return 1;
        }
    return 0;
}

unsigned char isButtonEnter()
{
    if (key_code[3] == 1){
        return 1;
    }
    return 0;
}
void openDoor()
{   if(isDoorOpenInside == 1 || isDoorOpenOutside == 1) PORTDbits.RD2 = 1;
    else PORTDbits.RD2 = 0;
}

void openDoorInside(){
    ReadValueAdc = get_adc_value(0);
    if(ReadValueAdc > 500) isDoorOpenInside = 1;
    else isDoorOpenInside = 0;
}

void openDoorOutside(){
    if(isLock == 1) {
        isDoorOpenOutside = 0;
        return;
    }
    ReadValueAdc = get_adc_value(1);
    if(ReadValueAdc > 500) isDoorOpenOutside = 1;
    else isDoorOpenOutside = 0;
}

void buzzerOn(){
    PORTDbits.RD1 = 1;
}

void buzzerOff(){
    PORTDbits.RD1 = 0;
}