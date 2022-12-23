#include "timer.h"
#include "..\button_matrix\button.h"
unsigned char flag_timer1 = 0,flag_timer2 = 0,flag_timer3 = 0;
unsigned int timer1_cnt = 0,timer2_cnt = 0,timer3_cnt = 0;
unsigned int timer3_value = 0;

//--------------------TIMER0-------------------------
//--------------------TIMER3-------------------------

void init_timer3(unsigned int count)
{	
	T3CONbits.TMR3ON = 0;			// turn off timer 3
	timer3_value = count;
	TMR3H = ((65535-timer3_value)/256);	// count timer3_value times
	TMR3L = ((65535-timer3_value)%256);	//
	PIE2bits.TMR3IE = 1;			// enable timer3 interrupt
	PIR2bits.TMR3IF = 0;			// clear timer3 interrupt flag

	IPR2bits.TMR3IP = 0;			// timer3 interrupt low priority 	

	//T1CON
	T3CONbits.RD16 = 1;				// select timer3 16 bits mode
	T3CONbits.T3CKPS0 = 0;			//
	T3CONbits.T3CKPS1 = 0;			// prescaler 1:1
//	T3CONbits.T3SYNC = 0;			// this bit ignore when TMR3CS = 0
	T3CONbits.TMR3CS = 0;			// select internal clock source
	T3CONbits.TMR3ON = 1;			// start timer3
}

void start_timer3(void)
{
	TMR3L = (65535 - timer3_value)%256;
	TMR3H = (65535 - timer3_value)/256;
	T3CONbits.TMR3ON = 1;
}

void stop_timer3(void)
{
	T3CONbits.TMR3ON = 0;
}


void timer3_isr(void)
{
    if(timer1_cnt > 0){
        timer1_cnt--;
        if(timer1_cnt <= 0){
            flag_timer1 = 1;
        }
    }
    if(timer2_cnt > 0){
        timer2_cnt--;
        if(timer2_cnt <= 0){
            flag_timer2 = 1;
        }
    }
    if(timer3_cnt > 0){
        timer3_cnt--;
        if(timer3_cnt <= 0){
            flag_timer3 = 1;
        }
    }
}

void SetTimer2_ms(int time)
{
//	time0_MUL = time/10;
	timer2_cnt = time/10;
	flag_timer2 = 0;
}

void SetTimer1_ms(int time)
{
//	time1_MUL = time/10;
	timer1_cnt = time/10;
	flag_timer1 = 0;
}

void SetTimer3_ms(int time)
{
//	time3_MUL = time/10;
	timer3_cnt = time/10;
	flag_timer3 = 0;
}

//------------------VIRTUAL TIMER----------------------
