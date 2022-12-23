/* 
 * File:   peripheral.h
 * Author: phamv
 *
 * Created on December 20, 2022, 6:44 PM
 */

#ifndef _PERIPHERAL_H_
#define	_PERIPHERAL_H_

#include "../global/global.h"

unsigned char isButtonEnter();
void openDoor();
void openDoorInside();
void openDoorOutside();
unsigned char isButtonNumber();
void buzzerOn();
void buzzerOff();
unsigned char isDoorOpen();

extern unsigned char isLock;
extern unsigned char numberValue;
#endif	/* PERIPHERAL_H */

