#ifndef __INTERRUPT_H
#define __INTERRUPT_H

#define TIMER (65536-FOSC/12/100)	//10ms
#define TIMER2 (65536-FOSC/12/20)	//50ms

void initTimer0();
void initTimer1();
void DigDisplay(unsigned char i);
	
#endif
