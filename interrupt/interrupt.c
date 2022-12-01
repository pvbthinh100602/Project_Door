#include "interrupt.h"
#include "..\timer\timer.h"


unsigned int cnt0 = 0,cnt1 = 0;

void init_interrupt(void)
{
	INTCONbits.GIE = 1;  //enable global interrupt
	RCONbits.IPEN = 1;   //enable interrupt priority
	INTCONbits.PEIE = 1; //Peripheral External Interupt Enable
}

void init_ext_int0(void)
{
	INTCON2bits.INTEDG0 = 0; //Interrupt0 on falling edge
	INTCONbits.INT0IF = 0; //Clear Interrupt Flag bit
	INTCONbits.INT0IE = 1;	// Enable INT0
}



#pragma code InterruptVectorLow		= 0x18
void InterruptVectorLow(void)
{
	_asm
		GOTO	low_isr
	_endasm
}

#pragma code InterruptVectorHigh 	= 0x08
void InterruptVectorHigh(void)
{
	_asm
		GOTO	high_isr
	_endasm
}

#pragma code
#pragma interruptlow	low_isr
void low_isr(void)
{
	if (PIR2bits.TMR3IF) // timer3
	{
		stop_timer3();
		PIR2bits.TMR3IF = 0;
		start_timer3();
		timer3_isr();
	}

        if(PIR1bits.RCIF == 1) // UART interupt Receive
	{
		PIR1bits.RCIF = 0;
	}
}

#pragma code
#pragma interrupt		high_isr
void high_isr(void)
{
	if (PIR2bits.TMR3IF) // timer3
	{
		stop_timer3();
		PIR2bits.TMR3IF = 0;
		start_timer3();
		timer3_isr();
	}

        if(PIR1bits.RCIF == 1) // UART interupt Receive
	{
		PIR1bits.RCIF = 0;
	}

        //if(PIR1bits.TXIF == 1) // UART interupt Receive
}
