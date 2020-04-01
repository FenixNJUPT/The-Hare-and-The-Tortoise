#include "config.h"

extern unsigned char tCount;	//来源于snake.c文件
extern unsigned char keyValue;	//来源于snake.c文件
unsigned char wei=0;
unsigned int counter=0,sec=0;
extern unsigned char DisplayData[8];


sbit LS1=P2^2;
sbit LS2=P2^3;
sbit LS3=P2^4;
sbit LS4=P2^5;

//******定时器0初始化*************//
void initTimer0()
{
	TMOD |= 0x01;
	TL0 = TIMER;
	TH0 = TIMER>>8;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
}

//******定时器0中断服务处理*************//
void timer0Handle() interrupt 1
{	// 10ms中断
	TL0 = TIMER;
	TH0 = TIMER>>8;
	keyValue=scanKey();
	tCount++;
}

//******定时器1初始化*************//
void initTimer1()
{
	TMOD |= 0x01;
	TL1 = TIMER2;
	TH1 = TIMER2>>8;
	TR1 = 1;
	ET1 = 1;
	EA = 1;
}

//******定时器1中断服务处理*************//
void timer1Handle() interrupt 3
{	// 50ms中断
	TL1 = TIMER2;
	TH1 = TIMER2>>8;
	P1=0x00;//消隐
	DigDisplay(wei);
	wei++;
	if(wei>3)
		wei=0;
	counter++;
	if(counter>=200)
	{
		sec++;
		counter=0;
	}
}

void DigDisplay(unsigned char i)
{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LS1=0;LS2=0;LS3=0;LS4=1; break;//显示第0位
			case(1):
				LS1=0;LS2=0;LS3=1;LS4=0; break;//显示第1位
			case(2):
				LS1=0;LS2=1;LS3=0;LS4=0; break;//显示第2位
			case(3):
			  LS1=1;LS2=0;LS3=0;LS4=0; break;
		}
		P1=DisplayData[i];//发送段码
}
