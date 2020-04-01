#include "config.h"

sbit keyUp1		= P3^0;
sbit keyDown1 	= P3^1;
sbit keyLeft1 	= P3^2;
sbit keyRight1 	= P3^3;
sbit keyUp2		= P2^0;
sbit keyDown2 	= P2^1;
sbit keyLeft2 	= P2^6;
sbit keyRight2 	= P2^7;

//extern unsigned char keyValue;
//extern enum Dir{ speedup1, speeddown1, left1, right1, speedup2, speeddown2, left2, right2, nothing};
//*********Ö÷º¯Êý*************//
void main()
{
	while(1)
	{
		if(!keyUp1)
		{
	     initTimer0();
       initTimer1();
	     while(1)startRabbit();
		}
		else if(!keyDown1)
		{
			 initTimer0();
       initTimer1();
	     while(1)startTor();
		}
		else if(!keyLeft1)
		{
			 initTimer0();
       initTimer1();
	     while(1)startDuel();
		}
	}
}