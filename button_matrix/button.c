#include "button.h"

unsigned int key_code[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
//unsigned char key_flag[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
//unsigned char arrayMaskOutputOfKey [8] = {0x80,0x40,0x20,0x10,0x01,0x02,0x04,0x08};
//unsigned char arrayMaskInputOfKey [8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char arrayMaskOutputOfKey [4] = {0x10,0x20,0x40,0x80};
unsigned char arrayMaskInputOfKey [3] = {0x02,0x04,0x08};

unsigned char debounce1[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char debounce2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char debounce3[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

void init_key_matrix()
{
	TRIS_BUTTON = TRIS_BUTTON | 0x0e; 
	PORT_BUTTON = 0xff;
}

void init_key_matrix_with_uart()
{
//        TRIS_BUTTON = TRIS_BUTTON | 0x07;
        //TRIS_BUTTON = TRIS_BUTTON & 0b11001111; //RC5 & RC4 Output
        TRIS_BUTTON = TRIS_BUTTON & 0xcf; //RC5 & RC4 Output
	PORT_BUTTON = 0xff;
}

void scan_key_matrix()
{
	int i,j;
	for(i=0;i<MAX_ROW;i++)     
	{
        PORT_BUTTON = ~arrayMaskOutputOfKey[i];
        PORT_BUTTON = PORT_BUTTON | 0x0f;
		for(j=0;j<MAX_COL;j++)
		{   
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0){
                key_code[i*MAX_ROW+j]++;
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
	for(i=0;i<2;i++)
	{
		PORT_BUTTON = PORT_BUTTON & ~arrayMaskOutputOfKey[i];
                PORT_BUTTON = PORT_BUTTON | 0x0f;
		for(j=0;j<MAX_COL;j++)
		{
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0)
				key_code[i*MAX_ROW+j] = key_code[i*MAX_ROW+j] + 1;
			else
				key_code[i*MAX_ROW+j] = 0;
		}
	}
}