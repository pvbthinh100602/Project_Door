#ifndef _TIMER_H_
#define _TIMER_H_

#include <p18f4620.h>

void init_timer3(unsigned int count);
void start_timer3(void);
void stop_timer3(void);

void timer0_isr(void);
void timer1_isr(void);
void timer2_isr(void);
void timer3_isr(void);
// xay dung ham cap cao cho timer, nhung ham se duoc lop user goi
void SetTimer2_ms(int time);
void SetTimer1_ms(int time);
void SetTimer3_ms(int time);


extern unsigned char flag_timer1,flag_timer2,flag_timer3;
// extern la khai bao bien toan cuc chuong trinh, khong duoc gan gia tri

#endif