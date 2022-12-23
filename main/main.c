#include "main.h"
#include <stdlib.h>
#include <limits.h>
//#include "../uart/uart.h"
// Noi khai bao hang so

#define     ON      1
#define     OFF     0
// Noi khai bao bien toan cuc
// Khai bao cac ham co ban IO
void init_system(void);
void delay_ms(int value);

////////////////////////////////////////////////////////////////////
//Hien thuc cac chuong trinh con, ham, module, function duoi cho nay
////////////////////////////////////////////////////////////////////
void main(void)
{
   
//	unsigned int k = 0;
	init_system();
    lcd_clear();
    LcdClearS();
    srand(0);
	while (1)
	{     
        if(seed != INT_MAX) seed = 0;
        else seed++;

        if(flag_timer1 == 1){
            SetTimer1_ms(50);
            scan_key_matrix_with_uart();
            openDoorInside();
            openDoorOutside();
            openDoor();
            fsm_switch_mode_run();
            fsm_door_mode1_run();
            fsm_door_mode2_run();
            DisplayLcdScreen(); 
        }
        
	}
}
// Hien thuc cac module co ban cua chuong trinh
void delay_ms(int value)
{
	int i,j;
	for(i=0;i<value;i++)
		for(j=0;j<238;j++);
}

void init_system(void)
{
    TRISB = 0x00;		//setup PORTB is output
//    init_peripheral();
    TRISD = 0x01;
    PORTDbits.RD1 = 0;
    PORTDbits.RD2 = 0;
    init_lcd();
    LcdClearS();
    init_adc();
    init_interrupt();
    init_uart();
    init_key_matrix_with_uart();
    
    delay_ms(1000);
//    init_timer0(4695);//dinh thoi 1ms sai so 1%
//    init_timer1(9390);//dinh thoi 2ms
    init_timer3(46950);//dinh thoi 10ms
    SetTimer1_ms(50);
//    SetTimer2_ms();
//    SetTimer3_ms(50); //Chu ky thuc hien viec xu ly input,proccess,output
}
