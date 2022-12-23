#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <p18f4620.h>

#define PORT_BUTTON		PORTC
#define TRIS_BUTTON		TRISC
#define	MAX_COL			4
#define MAX_ROW			2

extern unsigned int key_code[];

extern unsigned char key_flag[];


void init_key_matrix();
void init_key_matrix_with_uart();
void scan_key_matrix();
void scan_key_matrix_with_uart();
void button_process();

#endif