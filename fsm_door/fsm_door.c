#include "fsm_door.h"
unsigned char timeDelay = 0;

void fsm_switch_mode_run(){
    if(statusDoor != LOCK_DOOR) return;
    switch(mode){
        case MODE1:
            if(isButtonEnter()){
                mode = MODE2;
            }
            break;
        case MODE2:
            if(isButtonEnter()){
                mode = MODE1;
            }
            break;
        default: 
            break;
    }
}

void fsm_door_mode1_run()
{
    if(mode == MODE2) return;
    switch (statusDoor)
    {
        case INIT_SYSTEM:
            LcdClearS();
            index_buffer = 0;
            statusDoor = LOCK_DOOR;
            break;
        case LOCK_DOOR:
            LcdPrintStringS(0,0,"LOCKING         ");
            LcdPrintStringS(1,0,"MODE1           ");
            if(timeDelay < 20){
                index_buffer = 0;
                timeDelay ++;
                break;
            }
            if(check_rfid()){
                indexOfNumber = 0;
                buzzerOn();
                UartSendConstString("\nTAG ID: ");
                UartSendNum(tag_id);
                UartSendConstString("\nPASSWORD: ");
                UartSendString(generate_pass());
                timeDelay = 0;
                LcdClearS();
                statusDoor = ENTER_PASSWORD; 
            } else {
                index_buffer = 0;
            }
            break;
        case ENTER_PASSWORD:
            LcdPrintStringS(0,0,"ENTER PASSWORD  ");
            timeDelay ++;
            if(timeDelay > 10) buzzerOff();
            if (timeDelay > 200){
                statusDoor = LOCK_DOOR;
                isLock = 1;
                index_buffer = 0;
                LcdClearS();
                break;
            }
            if (isButtonNumber())
            {
                LcdPrintStringS(1,indexOfNumber,"*");
                arrayPassword[indexOfNumber] = numberValue;
                indexOfNumber ++;
                timeDelay = 0;
            }
            if (indexOfNumber >= 4){
                if (CheckPassword()){
                    statusDoor = UNLOCK_DOOR;
                    isLock = 0;
                }
                else {
                    statusDoor = WRONG_PASSWORD;
                    buzzerOn();
                }
                timeDelay = 0;
                LcdClearS();
            }
            break;
        case UNLOCK_DOOR:
            timeDelay++;
            LcdPrintStringS(0,0,"UNLOCK DOOR     ");
            if(timeDelay > 200){
                statusDoor = LOCK_DOOR;
                isLock = 1;
                index_buffer = 0;
                LcdClearS();
                break;
            }
            if(isDoorOpen() == 1){
                statusDoor = DOOR_IS_OPEN;
                LcdClearS();
            }
            break;
        case DOOR_IS_OPEN:
            LcdClearS();
            LcdPrintStringS(0,0,"OPENING DOOR    ");
            if(isDoorOpen()== 0){
                statusDoor = LOCK_DOOR;
                isLock = 1;
                index_buffer = 0;
                LcdClearS();
            }
            break;
        case WRONG_PASSWORD:
            timeDelay++;
            LcdClearS();
            LcdPrintStringS(0,0,"PASSWORD WRONG  ");
            if(timeDelay > 40){
                statusDoor = LOCK_DOOR;
                isLock = 1;
                buzzerOff();
                index_buffer = 0;
                LcdClearS();
            }
            break;
        default:
            break;
    }
}

void fsm_door_mode2_run(){
    if(mode == MODE1) return;
    switch (statusDoor)
    {
        case INIT_SYSTEM:
            LcdClearS();
            index_buffer = 0;
            statusDoor = LOCK_DOOR;
            break;
        case LOCK_DOOR:
            LcdPrintStringS(0,0,"LOCKING         ");
            LcdPrintStringS(1,0,"MODE2           ");
            if(check_rfid()){               
                indexOfNumber = 0;
                admin_index = rfid_index;
                buzzerOn();
                UartSendConstString("\nTAG ID: ");
                UartSendNum(tag_id);
                UartSendConstString("\nPASSWORD: ");
                UartSendString(generate_pass());
                timeDelay = 0;
                LcdClearS();
                statusDoor = ENTER_PASSWORD; 
            }
            break;
            case ENTER_PASSWORD:
            LcdPrintStringS(0,0,"ENTER PASSWORD  ");
            timeDelay ++;
            if(timeDelay > 10) buzzerOff();
            if (timeDelay > 200){
                statusDoor = LOCK_DOOR;
                mode = MODE1;
                isLock = 1;
                index_buffer = 0;
                LcdClearS();
                break;
            }
            if (isButtonNumber())
            {
                LcdPrintStringS(1,indexOfNumber,"*");
                arrayPassword[indexOfNumber] = numberValue;
                indexOfNumber ++;
                timeDelay = 0;
            }
            if (indexOfNumber >= 4){
                if (CheckPassword()){
                    statusDoor = UNLOCK_DOOR;
                    index_buffer = 0;
                    isLock = 0;
                }
                else {
                    statusDoor = WRONG_PASSWORD;
                    buzzerOn();
                }
                timeDelay = 0;
                LcdClearS();
            }
            break;
        case UNLOCK_DOOR:
            LcdPrintStringS(0,0,"UNLOCK DOOR     ");
            if(timeDelay < 10) timeDelay++;
            else buzzerOff();
            if(check_rfid() == 1 && rfid_index == admin_index){
                statusDoor = LOCK_DOOR;
                isLock = 1;
                buzzerOff();
                timeDelay = 0;
                mode = MODE1;
                LcdClearS();
            }
            if(isDoorOpen() == 1){
                statusDoor = DOOR_IS_OPEN;
                LcdClearS();
            }
            break;
        case DOOR_IS_OPEN:
            LcdPrintStringS(0,0,"OPENING DOOR    ");
            if(isDoorOpen()== 0){
                statusDoor = UNLOCK_DOOR;
                LcdClearS();
            }
            break;
        case WRONG_PASSWORD:
            timeDelay++;
            LcdClearS();
            LcdPrintStringS(0,0,"PASSWORD WRONG  ");
            if(timeDelay > 40){
                statusDoor = LOCK_DOOR;
                mode = MODE1;
                isLock = 1;
                buzzerOff();
                index_buffer = 0;
                LcdClearS();
                timeDelay = 0;
            }
            break;
        default:
            break;
    }
}
