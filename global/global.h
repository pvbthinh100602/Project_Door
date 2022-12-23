/* 
 * File:   global.h
 * Author: phamv
 *
 * Created on December 20, 2022, 12:14 PM
 */

#ifndef _GLOBAL_H_
#define	_GLOBAL_H_

#include <p18f4620.h>
#include "..\adc\adc.h"
#include "..\timer\timer.h"
#include "..\button_matrix\button.h"
#include "..\interrupt\interrupt.h"
#include "..\uart\uart.h"
#include "..\fsm_door\fsm_door.h"
#include "..\peripheral\peripheral.h"
#include "..\rfid\rfid.h"
#include "..\password\password.h"
#include "..\lcd\lcd.h"


#define     INIT_SYSTEM        0
#define     LOCK_DOOR          1
#define     ENTER_PASSWORD     3
#define     CHECK_PASSWORD     4
#define     UNLOCK_DOOR        5
#define     WRONG_PASSWORD     6
#define     DOOR_IS_OPEN       7
#define     WAIT_FOR_PASS      8

#define     MODE1              1
#define     MODE2              2
extern unsigned char statusDoor;
extern unsigned char mode;

#endif	/* GLOBAL_H */

