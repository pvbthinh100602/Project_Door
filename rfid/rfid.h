/* 
 * File:   rfid.h
 * Author: phamv
 *
 * Created on December 20, 2022, 12:34 PM
 */

#ifndef _RFID_H_
#define	_RFID_H_

#include "../global/global.h"

extern long tag_id;

unsigned char check_rfid();
long hexstr2l(unsigned char* str, int size);
extern unsigned char rfid_index;
extern unsigned char admin_index;

#endif	/* RFID_H */

