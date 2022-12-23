#include "peripheral.h"

unsigned char arrayMapOfNumber [12] = {'1','2','3','4','5','6','7','8','9','*','0','#'};
unsigned int ReadValueAdc = 0;
unsigned char isLock = 1;
unsigned char numberValue = 0;
unsigned char isDoorOpenInside = 0;
unsigned char isDoorOpenOutside = 0;

void init_peripheral(){
    // RD0 is input: ir sensor
    // RD1 is output: buzzer
    // RD2 is output: relay
//    TRISD = 0x01;
//    PORTDbits.RD1 = 0;
//    PORTDbits.RD2 = 0;
    TRISC |= 0x01;
    TRISC &= 0xf9;
    PORTCbits.RC1 = 0;
    PORTCbits.RC2 = 0;
}

unsigned char isDoorOpen(){
    if(PORTCbits.RC0 == 0){
        return 0;
    }
    return 1;
}

unsigned char isButtonNumber()
{
    int i;
    for (i = 0; i < 12; i++)
        if (key_code[i] == 1)
        {
            numberValue = arrayMapOfNumber[i];
            return 1;
        }
    return 0;
}

unsigned char isButtonEnter()
{
    if (key_code[9] == 1){
        return 1;
    }
    return 0;
}
void openDoor()
{   if(isDoorOpenInside == 1 || isDoorOpenOutside == 1) PORTCbits.RC1 = 1;
    else PORTCbits.RC1 = 0;
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
    PORTCbits.RC2 = 1;
}

void buzzerOff(){
    PORTCbits.RC2 = 0;
}