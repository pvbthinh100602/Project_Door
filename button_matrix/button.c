#include "button.h"

unsigned int key_code[8] = {0,0,0,0,0,0,0,0};
unsigned int debounce1[8] = {0,0,0,0,0,0,0,0};
unsigned int debounce2[8] = {0,0,0,0,0,0,0,0};
//unsigned char key_flag[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
//unsigned char arrayMaskOutputOfKey [8] = {0x80,0x40,0x20,0x10,0x01,0x02,0x04,0x08};
//unsigned char arrayMaskInputOfKey [8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char arrayMaskOutputOfKey [2] = {0x10,0x20};
unsigned char arrayMaskInputOfKey [4] = {0x01,0x02,0x04,0x08};
void init_key_matrix()
{
	TRIS_BUTTON = TRIS_BUTTON | 0x0e;
    TRIS_BUTTON = TRIS_BUTTON & 0x0f;
	PORT_BUTTON = 0xff ;
}

void init_key_matrix_with_uart()
{
        TRIS_BUTTON = TRIS_BUTTON | 0x0f; 
        TRIS_BUTTON = TRIS_BUTTON & 0xcf; 
        PORT_BUTTON = 0x3f;
}

void scan_key_matrix()
{
	int i,j;
	for(i=0;i<MAX_ROW;i++)     
	{
        PORT_BUTTON = (PORT_BUTTON | 0xf0) & (~arrayMaskOutputOfKey[i]);
//        PORT_BUTTON |= 0xf0;
//        PORT_BUTTON &= ~arrayMaskOutputOfKey[i];
		for(j=0;j<MAX_COL;j++)
		{   
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0){
                key_code[i*MAX_ROW+j] = 1;
//                key_flag[i*MAX_ROW+j] = 1;
            }
            else                 
                key_code[i*MAX_ROW+j] = 0;
            
        }
	}
}

void scan_key_matrix_with_uart()
{
	int i,j;
	for(i=0;i<MAX_ROW;i++)
	{
		PORT_BUTTON = (PORT_BUTTON | 0x3f) & ~arrayMaskOutputOfKey[i];
		for(j=0;j<MAX_COL;j++)
		{
//            debounce1[i*MAX_COL+j] = debounce2[i*MAX_COL+j];
//            debounce2[i*MAX_COL+j] = (PORT_BUTTON & arrayMaskInputOfKey[j]) >> j;
//            if(debounce1[i*MAX_COL+j] == debounce2[i*MAX_COL+j]){
//                if(debounce1[i*MAX_COL+j] == 0) key_code[i*MAX_COL+j] = 1;
//            }           
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0)
				key_code[i*MAX_COL+j]++;
			else
				key_code[i*MAX_COL+j] = 0;
		}
	}
}
