#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <p18f4620.h>

#define PORT_BUTTON		PORTA
#define TRIS_BUTTON		TRISA
#define	MAX_COL			3
#define MAX_ROW			4

extern unsigned int key_code[];

extern unsigned char key_flag[];


void init_key_matrix();
void init_key_matrix_with_uart();
void scan_key_matrix();
void scan_key_matrix_with_uart();
void button_process();

#endif