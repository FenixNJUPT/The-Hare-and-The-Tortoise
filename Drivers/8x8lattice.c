#include "8x8lattice.h"


/*
void hc595Write(unsigned char writeVal)
{
	unsigned char i;
	ST_CP=0;
	for(i=0; i<8; i++)
	{
		SH_CP=0;
		DS=((writeVal<<i)&0x80)?1:0;
		SH_CP=1;
	}
	ST_CP=1;
}

void hc238Write(unsigned char writeVal)
{
	switch(writeVal)
	{
		case 0: hc238EN=1;hc238A=0;hc238B=0;hc238C=0;break;
		case 1: hc238EN=1;hc238A=1;hc238B=0;hc238C=0;break;
		case 2: hc238EN=1;hc238A=0;hc238B=1;hc238C=0;break;
		case 3: hc238EN=1;hc238A=1;hc238B=1;hc238C=0;break;
		case 4: hc238EN=1;hc238A=0;hc238B=0;hc238C=1;break;
		case 5: hc238EN=1;hc238A=1;hc238B=0;hc238C=1;break;
		case 6: hc238EN=1;hc238A=0;hc238B=1;hc238C=1;break;
		case 7: hc238EN=1;hc238A=1;hc238B=1;hc238C=1;break;
		default: hc238EN=0; break;	
	}
}

void drawPoint(unsigned char x, unsigned char y)
{
	hc595Write(0xFF);
	hc595Write(~(1<<x));
	hc238Write(y);
	
}

void scanDisplay(unsigned char *pbuff)
{
	unsigned char i=0;
	hc595Write(0xFF);
	for(i=0; i<8; i++)
	{	
		hc595Write(~pbuff[i]);
		hc238Write(i);
		hc595Write(0xFF);
	}
}
*/


unsigned char code TAB[8]  = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

void Hc595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	SSRCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	SSRCLK=1;
	_nop_();
	_nop_();
	SSRCLK=0;
}


void scanDisplay(unsigned char *pbuff)
{
	unsigned char tab;
  for(tab=0;tab<8;tab++)
	{	
		Hc595SendByte(0x00);			     //ÏûÒþ																
		COMMONPORTS	= TAB[tab];				 //Êä³ö×ÖÂë	
		Hc595SendByte(pbuff[tab]);		
	}
}

