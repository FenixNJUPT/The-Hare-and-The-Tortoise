#include "config.h"

extern enum Dir{ speedup1, speeddown1, left1, right1, speedup2, speeddown2, left2, right2, nothing};

//*********Key PIN**********//
sbit keyUp1		  = P3^0;
sbit keyDown1 	= P3^1;
sbit keyLeft1 	= P3^2;
sbit keyRight1 	= P3^3;
sbit keyUp2		  = P2^0;
sbit keyDown2 	= P2^1;
sbit keyLeft2 	= P2^6;
sbit keyRight2 	= P2^7;
//**************************//

uchar keyVal=left2;


uchar scanKey(void)
{
	
	if(!keyUp1)		keyVal=speedup1;
	else if(!keyDown1)	keyVal=speeddown1;
	else if(!keyLeft1)	keyVal=left1;
	else if(!keyRight1)	keyVal=right1;
	else if(!keyUp2)		keyVal=speedup2;
	else if(!keyDown2)	keyVal=speeddown2;
	else if(!keyLeft2)	keyVal=left2;
	else if(!keyRight2)	keyVal=right2;
	else keyVal=nothing;
	return keyVal;
}
